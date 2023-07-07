// *Spread Operator and Destructuring*
let arr = [1, 2, 5, 65, 88];

function avg(a1, a2, a3) {
    return (a1 + a2 + a3) / 3;
}

// Passing Parameter--
let a = avg(...arr);
console.log(a);

// Concatenate in Array--
let b = [100, ...arr, 93, 11];
console.log(b);

// Merge Arrays--
let a2 = [...arr, ...arr];
console.log(a2);

// Object--
let obj = {
    student: "Atharva",
    branch: "IT A",
    favSub: "C++",
};

// Only Specific Field Change--
let obj2 = { ...obj, favSub: "Programming" };
console.log(obj2);

// *Destructuring*

// Divide in variables--
let { student, branch, favSub } = obj;
console.log(student, branch, favSub);
