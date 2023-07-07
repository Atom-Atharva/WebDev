// let fs = require("fs");

// *Using Promises--
let fs = require("fs/promises");

//Takes time thus output later--
// fs.readFile("file.txt", "utf-8", function (err, data) {
//     console.log(err, data);
// });

//Returns a promise (Still takes time to read file)--
let a = fs.readFile("file.txt", "utf-8");
console.log(a);

//If promise resolved then--
a.then(function (data) {
    console.log(data);
});

// *Async-Await makes Non-blocking JS to Blocking--
const readThree = async (file1, file2, file3) => {
    // If this are printed without await then output can be non-systematic
    let a = fs.readFile(file1, "utf-8");
    let b = fs.readFile(file2, "utf-8");
    let c = fs.readFile(file3, "utf-8");

    //To Arrange in an order--
    let d = await a;
    console.log(d);
    let e = await b;
    console.log(e);
    let f = await c;
    console.log(f);
};

console.log("End of the Code.");

readThree("file1.txt", "file2.txt", "file3.txt");
