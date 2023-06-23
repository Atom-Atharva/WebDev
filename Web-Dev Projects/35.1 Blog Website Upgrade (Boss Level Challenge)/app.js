//EJS Module already covered in express module--
import express from "express";
//Import mongoose--
import mongoose from "mongoose";

const homeStartingContent =
    "Lacus vel facilisis volutpat est velit egestas dui id ornare. Semper auctor neque vitae tempus quam. Sit amet cursus sit amet dictum sit amet justo. Viverra tellus in hac habitasse. Imperdiet proin fermentum leo vel orci porta. Donec ultrices tincidunt arcu non sodales neque sodales ut. Mattis molestie a iaculis at erat pellentesque adipiscing. Magnis dis parturient montes nascetur ridiculus mus mauris vitae ultricies. Adipiscing elit ut aliquam purus sit amet luctus venenatis lectus. Ultrices vitae auctor eu augue ut lectus arcu bibendum at. Odio euismod lacinia at quis risus sed vulputate odio ut. Cursus mattis molestie a iaculis at erat pellentesque adipiscing.";
const aboutContent =
    "Hac habitasse platea dictumst vestibulum rhoncus est pellentesque. Dictumst vestibulum rhoncus est pellentesque elit ullamcorper. Non diam phasellus vestibulum lorem sed. Platea dictumst quisque sagittis purus sit. Egestas sed sed risus pretium quam vulputate dignissim suspendisse. Mauris in aliquam sem fringilla. Semper risus in hendrerit gravida rutrum quisque non tellus orci. Amet massa vitae tortor condimentum lacinia quis vel eros. Enim ut tellus elementum sagittis vitae. Mauris ultrices eros in cursus turpis massa tincidunt dui.";
const contactContent =
    "Scelerisque eleifend donec pretium vulputate sapien. Rhoncus urna neque viverra justo nec ultrices. Arcu dui vivamus arcu felis bibendum. Consectetur adipiscing elit duis tristique. Risus viverra adipiscing at in tellus integer feugiat. Sapien nec sagittis aliquam malesuada bibendum arcu vitae. Consequat interdum varius sit amet mattis. Iaculis nunc sed augue lacus. Interdum posuere lorem ipsum dolor sit amet consectetur adipiscing elit. Pulvinar elementum integer enim neque. Ultrices gravida dictum fusce ut placerat orci nulla. Mauris in aliquam sem fringilla ut morbi tincidunt. Tortor posuere ac ut consequat semper viverra nam libero.";

const app = express();

//Connect to Database--
mongoose.connect("mongodb://127.0.0.1:27017/blogDB");

//Use EJS as VIEW ENGINE--
app.set("view engine", "ejs");

//Use Body--
app.use(express.urlencoded({ extended: true }));

//Use Static Files--
app.use("/public", express.static("public"));

//Global Variable to store composed posts--
// const posts = [];

//Schema For MongoDB--
const blogSchema = new mongoose.Schema({
    title: String,
    content: String,
});

//Attach to Database--
const Blog = mongoose.model("Blog", blogSchema);

app.get("/", async (req, res) => {
    //Find Array DB--
    const posts = await Blog.find();

    res.render("home", { startingContent: homeStartingContent, posts: posts });
});

app.get("/about", (req, res) => {
    res.render("about", { aboutContent: aboutContent });
});

app.get("/contact", (req, res) => {
    res.render("contact", { contactContent: contactContent });
});

app.get("/compose", (req, res) => {
    res.render("compose");
});

app.get("/posts/:postid", async (req, res) => {
    // console.log(req.params.content);
    const id = req.params.postid;

    const post = await Blog.findOne({ _id: id });
    console.log("Found: " + post.title);

    res.render("post", { post: post });
});

app.post("/compose", (req, res) => {
    // console.log(req.body.postTitle);

    //Create new post structure--
    const post = new Blog({
        title: req.body.postTitle,
        content: req.body.postContent,
    });

    //Save to DataBase & Redirect to root--
    post.save().then(() => res.redirect("/"));
});

//Listen to port--
app.listen(3000 || process.env.PORT, function (err) {
    if (err) throw err;
    console.log("Server started on port 3000");
});
