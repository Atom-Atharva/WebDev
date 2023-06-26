// Angela Solution Reference--
// https://github.com/londonappbrewery/Authentication-Secrets

import "dotenv/config";
import express from "express";
import mongoose from "mongoose";
// Level-3 Hashing Function--
// import encrypt from "mongoose-encryption";
// import md5 from "md5";

//Level-4 Salting and Hashing--
// import bcrypt from "bcrypt";
// const saltRounds = 10;

//Level-5 Using Passport.js, Cookies and Sessions--
import passport from "passport";
//Responsible for cookies and session--
import session from "express-session";
import passportLocalMongoose from "passport-local-mongoose";

//Level-6 Using Google Verfication--
import { Strategy as GoogleStrategy } from "passport-google-oauth20";
import findOrCreate from "mongoose-findorcreate";
import FacebookStrategy from "passport-facebook";

//Create app--
const app = express();

//Set EJS as View Engine--
app.set("view engine", "ejs");

//Use Body--
app.use(express.urlencoded({ extended: true }));

//Use Static Files--
app.use("/public", express.static("public"));

//Setting Sessions--
app.use(
    session({
        secret: "Our little secret.",
        resave: false,
        saveUninitialized: false,
    })
);

//Using passport package to initialize and uses session package--
app.use(passport.initialize());
app.use(passport.session());

//Connect to userDB--
mongoose.connect("mongodb://127.0.0.1:27017/userDB");

//Create Schema--
const userSchema = new mongoose.Schema({
    email: String,
    password: String,
    googleId: String,
    facebookId: String,
    secret: String,
});

//Activate passport local mongoose--
userSchema.plugin(passportLocalMongoose);
userSchema.plugin(findOrCreate);

// Level-2 Encryption Security (Cipher Method)--
// const secret = "Thisisourlittlesecret.";
// As Secret is needed to be saved from hacker we use dotencrypt--
// const secret = process.env.SECRET;

//Add Pulugin to Schema--
// userSchema.plugin(encrypt, { secret: secret, encryptedFields: ["password"] });

//Model Schema--
const User = new mongoose.model("User", userSchema);

// CHANGE: USE "createStrategy" INSTEAD OF "authenticate"
passport.use(User.createStrategy());

//Only works for local-
// passport.serializeUser(User.serializeUser());
// passport.deserializeUser(User.deserializeUser());

passport.serializeUser(function (user, cb) {
    process.nextTick(function () {
        return cb(null, {
            id: user.id,
            username: user.username,
            picture: user.picture,
        });
    });
});

passport.deserializeUser(function (user, cb) {
    process.nextTick(function () {
        return cb(null, user);
    });
});

//Set Up google strategy--
passport.use(
    new GoogleStrategy(
        {
            clientID: process.env.CLIENT_ID,
            clientSecret: process.env.CLIENT_SECRET,
            callbackURL: "http://localhost:3000/auth/google/secrets",
        },
        function (accessToken, refreshToken, profile, cb) {
            // console.log(profile);
            User.findOrCreate({ googleId: profile.id }, function (err, user) {
                return cb(err, user);
            });
        }
    )
);

passport.use(
    new FacebookStrategy(
        {
            clientID: process.env.FACEBOOK_APP_ID,
            clientSecret: process.env.FACEBOOK_APP_SECRET,
            callbackURL: "http://localhost:3000/auth/facebook/secrets",
        },
        function (accessToken, refreshToken, profile, cb) {
            // console.log(profile);
            User.findOrCreate({ facebookId: profile.id }, function (err, user) {
                return cb(err, user);
            });
        }
    )
);

//Get all routes--
app.get("/", (req, res) => {
    res.render("home");
});

app.get(
    "/auth/google",
    passport.authenticate("google", { scope: ["profile"] })
);

app.get(
    "/auth/google/secrets",
    passport.authenticate("google", { failureRedirect: "/login" }),
    function (req, res) {
        // Successful authentication, redirect secrets page.
        res.redirect("/secrets");
    }
);

app.get("/auth/facebook", passport.authenticate("facebook"));

app.get(
    "/auth/facebook/secrets",
    passport.authenticate("facebook", { failureRedirect: "/login" }),
    function (req, res) {
        // Successful authentication, redirect home.
        res.redirect("/secrets");
    }
);

app.get("/login", (req, res) => {
    res.render("login");
});

app.get("/register", (req, res) => {
    res.render("register");
});

app.get("/secrets", async (req, res) => {
    const foundUsers = await User.find({ secret: { $ne: null } });
    if (foundUsers) {
        res.render("secrets", { userWithSecrets: foundUsers });
    }
});

app.get("/submit", (req, res) => {
    if (req.isAuthenticated()) {
        return res.render("submit");
    } else {
        return res.redirect("/login");
    }
});

app.get("/logout", (req, res) => {
    req.logout(function (err) {
        if (err) {
            return next(err);
        }
        res.redirect("/");
    });
});

app.post("/submit", async (req, res) => {
    const submittedSecret = req.body.secret;

    const user = await User.findById(req.user.id);
    if (user) {
        user.secret = submittedSecret;
        await user.save();
        return res.redirect("/secrets");
    }
});

//Level - 5 Using Passport--
app.post("/register", async (req, res) => {
    User.register(
        { username: req.body.username },
        req.body.password,
        function (err, user) {
            if (err) {
                console.log(err);
                return res.redirect("/register");
            } else {
                passport.authenticate("local")(req, res, function () {
                    return res.redirect("/secrets");
                });
            }
        }
    );
});

// app.post("/register", async (req, res) => {
//     bcrypt.hash(req.body.password, saltRounds, async function (err, hash) {
//         const username = req.body.username;
//         const password = hash;

//         const newUser = new User({
//             email: username,
//             password: password,
//         });

//         if (username.length > 1 && password.length > 1) {
//             await newUser.save();
//             return res.render("secrets");
//         }
//         return res.redirect("/register");
//     });

//     // const username = req.body.username;
//     // // const password = req.body.password;
//     // const password = md5(req.body.password);

//     // const newUser = new User({
//     //     email: username,
//     //     password: password,
//     // });

//     // if (username.length > 1 && password.length > 1) {
//     //     await newUser.save();
//     //     return res.render("secrets");
//     // }
//     // return res.redirect("/register");
// });

app.post("/login", async (req, res) => {
    const user = new User({
        username: req.body.username,
        password: req.body.password,
    });

    req.login(user, function (err) {
        if (err) {
            console.log(err);
        }
        passport.authenticate("local")(req, res, function () {
            return res.redirect("/secrets");
        });
    });
});

// app.post("/login", async (req, res) => {
//     const username = req.body.username;
//     const password = req.body.password;
//     // const password = md5(req.body.password);

//     const entry = await User.findOne({ email: username });
//     if (entry) {
//         bcrypt.compare(password, entry.password, function (err, result) {
//             if (result === true) {
//                 return res.render("secrets");
//             } else {
//                 return res.redirect("/login");
//             }
//         });

//         // if (entry.password === password) {
//         //     return res.render("secrets");
//         // } else {
//         //     return res.redirect("/login");
//         // }
//     } else {
//         return res.redirect("/register");
//     }
// });

//Connect to host--
app.listen(process.env.PORT || 3000, (err) => {
    if (err) throw err;
    console.log("Listning to server...");
});
