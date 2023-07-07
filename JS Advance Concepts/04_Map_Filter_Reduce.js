let a = [1, 2, 3, 4, 5, 64, 643, 7542];

// *JavaScript Map*
// Iteration to All elements of the array--
let b = a.map((value) => {
    return value + 6;
});

// console.log(a);
// console.log(b);

// *JavaScript Filter*
// Filter out all the elements from the array--
let b2 = a.filter((value) => {
    return value > 6;
});
// console.log(b2);

// *JavaScript Reduce*
// Reduce the function till one element is present--
let b3 = a.reduce((val1, val2) => {
    return val1 + val2;
});
// console.log(b3);
