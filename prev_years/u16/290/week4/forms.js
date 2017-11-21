/*
 * Name: Benjamin Tate
 * Date: 7/17/2016
 * Filename: forms.js
 * Class: CS290 - Section 400
 * Assignment: Ajax Interactions Activity
 * Note: Unfortunately, I spent all of the time that I had to work on this
 * 		 trying to get the first form to log anything to the console (with
 * 		 no success), and then had not time left to try anything with the
 * 		 second form. The url I get from the submitted form does lead to 
 * 		 an object that looks right, but I can't for the life of me figure
 * 		 out how to actually make the call and do anything with that object
 * 		 like log it to the console.
 */

var apiKey = '4fce75e25bd50f3ec5c01bfee74a74d1';
var req = new XMLHttpRequest();
var url = "http://api.openweathermap.org/data/2.5/weather?";

/*function citySubmit() {
	var city = document.getElementsByName('city')[0].value;
	var state = document.getElementsByName('state')[0].value;
	var append = "q=" + city + "," + state.toLowerCase() + "&appid=" + apiKey;
	
	url += append;

	req.open("GET", url, true);
	req.send(null);
	console.log(JSON.parse(req.responseText));
}*/

function zipSubmit() {
	var zip = document.getElementsByName('zip')[0].value;
	var append = "zip=" + zip + ",us" + "&appid=" + apiKey;

	url += append;

	alert(url);

	req.open("GET", url, true);
	req.addEventListener('load', function() {
		if(req.status >=200 && req.status < 400) {
			console.log(JSON.parse(req.responseText));
		} else {
			console.log("Error in network request: " + req.statusText);
		}
	});
	req.send(null);
}

//document.getElementById('citySub').addEventListener('click', citySubmit);
document.getElementById('zipSub').addEventListener('click', zipSubmit);
