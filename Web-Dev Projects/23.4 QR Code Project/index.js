/* 
1. Use the inquirer npm package to get user input.
2. Use the qr-image npm package to turn the user entered URL into a QR code image.
3. Create a txt file to save the user input using the native fs node module.
*/

import inquirer from "inquirer";
import fs from "fs";
import qr from "qr-image";

inquirer
    .prompt([{ 
        type: "input", 
        name: "URL", 
        message: "Enter URL!" }])
    .then((answer) => {
        const url = answer.URL;
        var qr_svg = qr.image(url);
        qr_svg.pipe(fs.createWriteStream("./qr.png"));

        fs.writeFile("Code.txt", url, (err) => {
            if (err) throw err;
            console.log("FILE SAVED!");
        });
    })
    .catch((error) => {
        if (error.isTtyError) {
            // Prompt couldn't be rendered in the current environment
        } else {
            // Something else went wrong
        }
    });
