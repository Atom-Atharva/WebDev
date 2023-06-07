// jshint esversion:6

import express from "express";
import path from "path";

// const express = require("express");
const app = express();
const port = 3000;

app.use(express.urlencoded({ extended: true }));

app.get("/", (req, res) => {
    res.sendFile(path.resolve(".") + "/index.html");
});

app.post("/index.html", function (req, res) {
    var num1 = Number(req.body.num1);
    var num2 = Number(req.body.num2);

    var result = num1 + num2;
    // res.send("Thankyou!");
    res.send("The result: " + result);
});

app.listen(port, () => {
    console.log(`Example app listening on port ${port}`);
});
