console.log("1^3 =", cube(1));
console.log("2^3 =", cube(2));
console.log("3^3 =", cube(3));
console.log("4^3 =", cube(4));
console.log("5^3 =", cube(5));

function cube(x) {
    return x * x * x;
}

console.log("I bet this doesn't work!");
console.log("1^2 =", square(1));

var square = function(x) {
    return x * x;
}
