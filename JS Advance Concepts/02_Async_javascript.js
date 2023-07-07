console.log("First Output");

setTimeout(() => {
    console.log("Inside Timeout");
}, 1000);

console.log("End Output");

// As Expected javaScript doesn't wait for timer to go off...
// It immediately runs the next line of code.
// Well Explained in Namaste JavaScript.
