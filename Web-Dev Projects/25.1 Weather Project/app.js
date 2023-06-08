import express from "express";
import https from "https";
import path from "path";

const app = express();

app.use(express.urlencoded({ extended: true }));

app.get("/", (req, res) => {
    res.sendFile(path.resolve(".") + "/index.html");
});

app.post("/", (req, res) => {
    const city = req.body.cityName;
    const appid = "34cc5cb438a35d3444ecd7f9539de177";
    const unit = "metric";
    const url =
        "https://api.openweathermap.org/data/2.5/weather?q=" +
        city +
        "&appid=" +
        appid +
        "&units=" +
        unit;
    https.get(url, function (response) {
        console.log(response.statusCode);

        response.on("data", function (data) {
            //Create in JSON format--
            const weatherData = JSON.parse(data);
            const temp = weatherData.main.temp;
            const desc = weatherData.weather[0].description;
            const img = weatherData.weather[0].icon;
            const imgURL =
                "https://openweathermap.org/img/wn/" + img + "@2x.png";
            console.log(temp);
            console.log(desc);

            //Write can be done--
            res.write("<p>The Weather currently is " + desc + "</p>");
            res.write(
                "<h1>The temp in " +
                    city +
                    " is " +
                    temp +
                    " degree Celcius.</h1>"
            );
            res.write("<img src=" + imgURL + " />");

            res.send();
        });
    });

    // No 2 send in one request
    // res.send("Server is Running!");
});

app.listen(3000, function (err) {
    if (err) throw err;
    console.log("Running on Port: 3000.");
});
