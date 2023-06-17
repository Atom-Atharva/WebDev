//EJS is already included in express module--
import express from "express";
//Due to ES Module in JavaScript we need to import default export--
import date from "./date.js";

const app = express();
const port = 3000;

//Use EJS as VIEW ENGINE--
app.set("view engine", "ejs");

//Accessing Body--
app.use(express.urlencoded({ extended: true }));

//Accessing Static Sites--
app.use("/public", express.static("public"));

let items = [];
let workItems = [];

//Responding to the Home route--
app.get("/", (req, res) => {
    //Method 3: By Modules--
    // let day = date.getDay();
    let day = date.getDate();

    //Method 2: Using toLocateDateString--
    // let options = {
    //     weekday: "long",
    //     month: "long",
    //     day: "numeric",
    // };

    // let today = new Date();
    // let date = today.toLocaleDateString("en-US", options);

    res.render("list", { listType: day, listItems: items });

    //Method 1: using getDate and converting day toh string--
    // let today = new Date();
    // let currentDay = today.getDay();

    // let day = "";
    // switch (currentDay) {
    //     case 0:
    //         day = "Sunday";
    //          break;
    //     case 1:
    //         day = "Monday";
    //         break;
    //     case 2:
    //         day = "Tuesday";
    //         break;
    //     case 3:
    //         day = "Wednesday";
    //         break;
    //     case 4:
    //         day = "Thrusday";
    //         break;
    //     case 5:
    //         day = "Friday";
    //         break;
    //     case 6:
    //         day = "Saturday";
    //         break;

    //     default:
    //         console.log(
    //             "Error you are living on some other planet, CurrentDay: " +
    //                 currentDay
    //         );
    //         break;
    // // }

    // //See the ./views.list.ejs file--
    // res.render("list", { typeOfDay: day });
});

app.get("/work", (req, res) => {
    res.render("list", { listType: "Work List", listItems: workItems });
});

app.post("/", (req, res) => {
    let item = req.body.newItem;
    console.log(item);

    // console.log(req.body);
    if (req.body.list === "Work List") {
        workItems.push(item);
        res.redirect("/work");
    } else {
        items.push(item);
        res.redirect("/");
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
