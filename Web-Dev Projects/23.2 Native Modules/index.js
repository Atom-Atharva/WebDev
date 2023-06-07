const fs = require("fs");

// Writing a File--
// fs.writeFile("info.txt", "Hello Form Node JS!", "utf-8", (err) => {
//     if (err) throw err;
//     console.log("File has been saved!");
// });

//Reading a File--
fs.readFile("info.txt", "utf-8", (err, data) => {
    if (err) throw err;
    console.log(data);
});
