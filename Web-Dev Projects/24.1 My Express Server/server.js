import express from "express";

const app = express();

app.get("/", function (request, respond) {
    respond.send("<H1>Hello World!!</H1>");
    // console.log(request);
});

app.get("/contact", (req, res) => {
    res.send("Contact me at atharva@gmail.com");
});

app.get("/about", (req, res) => {
    res.send("I am Atharva, a coding enthusiast!!");
});

app.listen(3000, () => {
    console.log(`Server app listning to localhost:3000`);
});
