import express from "express";
import path from "path";

const app = express();

app.use(express.urlencoded({ extended: true }));

app.get("/", function (request, respond) {
    respond.sendFile(path.resolve(".") + "/bmiCalculator.html");
});

app.post("/bmiCalculator.html", (req, res) => {
    var weight = parseFloat(req.body.weight);
    var height = parseFloat(req.body.height);

    var bmi = weight / (height * height);

    res.send("YOUR BMI IS: " + bmi);
});

app.listen(3000, () => {
    console.log(`Server app listning to localhost:3000`);
});
