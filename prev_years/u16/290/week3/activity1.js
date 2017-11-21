function sumArr(a) {
    var sum = 0;

    a.forEach(function(x) {
        sum += x;
    });

    return sum;
}

var arr = [1,2,3];

console.log(sumArr(arr));

function dialog(character) {
    return function(words) {
        return character + " says, \"" + words + "\"";
    }
}

var Mickey = {name: "Mickey Mouse"};

Mickey.speak = dialog(Mickey.name);

console.log(Mickey.speak("What up, daaaawwwwggg?"));
