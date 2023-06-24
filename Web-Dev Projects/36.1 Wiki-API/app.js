import express from "express";
import mongoose from "mongoose";

const app = express();

//Connect Mongoose Server--
mongoose.connect("mongodb://127.0.0.1:27017/wikiDB");

const articleSchema = new mongoose.Schema({
    title: String,
    content: String,
});

const Article = mongoose.model("Article", articleSchema);

//Use EJS as View Engine--
app.set("view engine", "ejs");

//Use Body Parser--
app.use(express.urlencoded({ extended: true }));

//Use Public Sites--
app.use("public", express.static("public"));

// // Get Request on articles--
// app.get("/articles", async (req, res) => {
//     const result = await Article.find({});
//     console.log(result);
//     res.send(result);
// });

// //Post Request on articles--
// app.post("/articles", (req, res) => {
//     const newArticle = new Article({
//         title: req.body.title,
//         content: req.body.content,
//     });

//     newArticle
//         .save()
//         .then(() => {
//             res.send("Sucessfull Entry");
//         })
//         .catch((err) => {
//             res.send(err);
//         });
// });

// //Delete Request on articles--
// app.delete("/articles", async (req, res) => {
//     await Article.deleteMany({}).then(() => {
//         res.send("Successfully Deleted ALL Data!");
//     });
// });

//Simple way to do it so that no error in route--
app.route("/articles")
    .get(async (req, res) => {
        const result = await Article.find({});
        console.log(result);
        res.send(result);
    })
    .post((req, res) => {
        const newArticle = new Article({
            title: req.body.title,
            content: req.body.content,
        });

        newArticle
            .save()
            .then(() => {
                res.send("Sucessfull Entry");
            })
            .catch((err) => {
                res.send(err);
            });
    })
    .delete(async (req, res) => {
        await Article.deleteMany({}).then(() => {
            res.send("Successfully Deleted ALL Data!");
        });
    });

//For Specific Route--
app.route("/articles/:title")
    .get(async (req, res) => {
        const title = req.params.title;

        const article = await Article.findOne({ title: title });
        if (article) {
            res.send(article);
        } else {
            res.send("Nothing Found :(");
        }
    })
    .put(async (req, res) => {
        //ReplaceOne method is used to overwrite entire entity--
        const update = await Article.replaceOne(
            { title: req.params.title },
            {
                title: req.body.title,
                content: req.body.content,
            }
        );
        if (update.modifiedCount > 0) {
            res.send("Success!");
        } else {
            res.send("ERROR!");
        }
    })
    .patch(async (req, res) => {
        //UpdateOne Method is used to set a particular entry (DO NOT OVERWRITE)--
        const update = await Article.updateOne(
            { title: req.params.title },
            {
                title: req.body.title,
                content: req.body.content,
            }
        );

        if (update.modifiedCount > 0) {
            res.send("Success!");
        } else {
            res.send(update);
        }
    })
    .delete(async (req, res) => {
        const del = await Article.deleteOne({ title: req.params.title });
        if (del.deletedCount > 0) {
            res.send("SUCCESS!");
        } else {
            res.send("ERROR!");
        }
    });

//Listen to Local Host--
app.listen(process.env.PORT || 3000, function (err) {
    if (err) throw err;
    console.log("Listning to 3000...");
});
