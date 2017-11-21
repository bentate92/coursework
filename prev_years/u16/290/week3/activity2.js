function buildList(list) {
    var result = [];
    for (var i = 0; i < list.length; i++) {
        //var item = 'item' + list[i];
        //result.push(function() {alert(item + ' ' + list[i])});
        result[i] = function(x) {
            return function() {
                alert('item ' + x);
            }
        }(list[i]);
    }
    return result;
}

var buildIt = buildList;

function testList() {
    var fnlist = buildList([1, 2, 3]);
    // using j only to help prevent confusion - could use i
    for (var j = 0; j < fnlist.length; j++) {
        fnlist[j]();
    }
}

testList(buildIt);
