function deepEqual(x, y) {
    if(typeof(x) == 'object' && x != null && typeof(y) == 'object' && y != null) {
        for(var prop in x) {
            return deepEqual(x[prop], y[prop]);
        }
    } else if(typeof(x) == typeof(y)) {
        return x == y;
    } else { 
        return false; 
    }
}

var obj = {here: {is: "an"}, object: 2};
console.log(deepEqual(obj, obj));
// → true
console.log(deepEqual(obj, {here: 1, object: 2}));
// → false
console.log(deepEqual(obj, {here: {is: "an"}, object: 2}));
// → true
