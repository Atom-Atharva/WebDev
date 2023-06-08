import express from "express";
import path from "path";
import client from "@mailchimp/mailchimp_marketing";

const app = express();
const port = 8080;

//For accessing body--
app.use(express.urlencoded({ extended: true }));

//For accessing static files--
app.use("/assets", express.static("assets"));
// app.use("*/css", express.static("assets/css"));
// app.use("*/image", express.static("assets/image"));

app.get("/", (req, res) => {
    res.sendFile(path.resolve(".") + "/signup.html");
});

client.setConfig({
    apiKey: "cdf8d255378e42146d6ba551b92a7474-us13",
    server: "us13",
});

app.post("/", (req, res) => {
    const firstName = req.body.fName;
    const lastName = req.body.lName;
    const email = req.body.email;

    const run = async () => {
        const response = await client.lists.batchListMembers("a231db7880", {
            members: [
                {
                    email_address: email,
                    status: "subscribed",
                    merge_fields: {
                        FNAME: firstName,
                        LNAME: lastName,
                    },
                },
            ],
        });
        console.log(response);

        if (response.error_count >= 1) {
            res.sendFile(path.resolve(".") + "/failure.html");
        } else {
            res.sendFile(path.resolve(".") + "/success.html");
        }
    };

    run();

    // OLD METHOD -- ANGELA
    // // console.log(firstName, lastName, email);
    // const data = {
    //     new_members: [
    //         {
    //             email_address: email,
    //             status: "subscribed",
    //             merge_fields: {
    //                 FNAME: firstName,
    //                 LNAME: lastName,
    //             },
    //         },
    //     ],
    // };

    // //Convert Json to string--
    // const jsonData = JSON.stringify(data);

    // const url = `https://us13.api.mailchimp.com/lists/a231db7880`;
    // const option = {
    //     method: "POST",
    //     auth: "Atharva1:cdf8d255378e42146d6ba551b92a7474-us13",
    // };

    // //Create Request--
    // const request = https.request(url, option, (response) => {
    //     response.on("data", (data) => {
    //         console.log(JSON.parse(data));
    //     });
    // });

    // request.write(jsonData);
    // request.end();
});

app.post("/failure", (req, res) => {
    res.redirect("/");
});

app.listen(process.env.PORT || port, (err) => {
    if (err) throw err;
    console.log(`Listning to Port: ${port}`);
});

//API Key (Mailchimp)--
// cdf8d255378e42146d6ba551b92a7474-us13

//List id--
// a231db7880
