//EJS is already included in express module--
import express from "express";
import mongoose from "mongoose";
import _ from "lodash";

//Connect to mongodb database via mongoose--
mongoose.connect("mongodb+srv://user-admin:atharva1908@cluster0.6skzckf.mongodb.net/todolistDB");

const app = express();
const port = 3000;

//Use EJS as VIEW ENGINE--
app.set("view engine", "ejs");

//Accessing Body--
app.use(express.urlencoded({ extended: true }));

//Accessing Static Sites--
app.use("/public", express.static("public"));

//As Server Restarts, items will be reset--
// let items = [];
// let workItems = [];

//Creating New Schema--
const itemsSchema = new mongoose.Schema({
    name: String,
});

const listSchema = new mongoose.Schema({
    name: String,
    items: [itemsSchema],
});

const List = mongoose.model("List", listSchema);

//Creating Model for Schema--(singlular name of collection, schema)
const Item = mongoose.model("Item", itemsSchema);

const item1 = new Item({
    name: "Welcome to you TODO List!",
});
const item2 = new Item({
    name: "Hit + button to add a new item.",
});
const item3 = new Item({
    name: "<-- Hit this to delete an item.",
});

//Defaluts Items List--
const defaultsItems = [item1, item2, item3];

//Responding to the Home route--
app.get("/", async (req, res) => {
    const items = await Item.find();

    if (items.length === 0) {
        //Insert Default items--
        await Item.insertMany(defaultsItems, { ordered: true });
        res.redirect("/");
    } else {
        res.render("list", { listType: "Today", listItems: items });
    }
});

app.get("/:customListName", async (req, res) => {
    const customListName = _.capitalize(req.params.customListName);

    const check = await List.findOne({ name: customListName });
    console.log(check);

    if (check === null) {
        const list = new List({
            name: customListName,
            items: defaultsItems,
        });
        await list.save();
        res.redirect("/" + customListName);
    } else {
        res.render("list", { listType: check.name, listItems: check.items });
    }
});

app.post("/", async (req, res) => {
    const itemName = req.body.newItem;
    const listType = req.body.list;
    // console.log(itemName);
    // console.log(listType);

    const item = new Item({
        name: itemName,
    });

    if (listType === "Today") {
        item.save();
        res.redirect("/");
    } else {
        const check = await List.findOne({ name: listType });
        // console.log(check);
        check.items.push({
            name: itemName,
        });
        check.save();

        res.redirect("/" + listType);
    }
});

app.post("/delete", async (req, res) => {
    const checkedItemId = req.body.checkbox;
    const listName = req.body.listName;

    if (listName === "Today") {
        await Item.deleteOne({ _id: checkedItemId });
        res.redirect("/");
    } else {
        // Delete an element from an array--
        // As list name is an object--

        await List.findOneAndUpdate(
            { name: listName },
            { $pull: { items: { _id: checkedItemId } } }
        );

        res.redirect("/" + listName);
    }
});

app.get("/about", (req, res) => {
    res.render("about");
});

//Listning to the port--
app.listen(port || process.env.PORT, (err) => {
    if (err) throw err;
    console.log(`Listning to ${port}`);
});
