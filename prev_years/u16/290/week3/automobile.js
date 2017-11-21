/*
 * Name: Benjamin Tate
 * Date: 7/10/2016
 * Filename: automobile.js
 * Class: CS290 - Section 400
 * Assignment: Higher-Order Functions and Objects
 */

function Automobile( year, make, model, type ){
	this.year = year; //integer (ex. 2001, 1995)
	this.make = make; //string (ex. Honda, Ford)
	this.model = model; //string (ex. Accord, Focus)
	this.type = type; //string (ex. Pickup, SUV)
}

var automobiles = [ 
	new Automobile(1995, "Honda", "Accord", "Sedan"),
	new Automobile(1990, "Ford", "F-150", "Pickup"),
	new Automobile(2000, "GMC", "Tahoe", "SUV"),
	new Automobile(2010, "Toyota", "Tacoma", "Pickup"),
	new Automobile(2005, "Lotus", "Elise", "Roadster"),
	new Automobile(2008, "Subaru", "Outback", "Wagon")
];

/*This function sorts arrays using an arbitrary comparator. You pass it a comparator and an array of objects appropriate for that comparator and it will return a new array which is sorted with the largest object in index 0 and the smallest in the last index*/
function sortArr( comparator, array ){
	//Create var to hold length of array
	var arrLen = array.length;
	
	//Iterate from first to second-to-last element of array
	for(var i = 0; i < arrLen-1; i++) {
		//Create var to hold index of minimum value
		var min = i;

		//Iterate from next element to last element
		for(var j = i + 1; j < arrLen; j++) {
			//Call comparator to compare cars at min and j
			if(comparator(array[min], array[j])) {
				//Adjust min index if smaller value is found
				min = j;
			}
		}

		//At the end of each pass, swap values at min and i if min != i
		if(min != i) {
			var temp = array[i];
			array[i] = array[min];
			array[min] = temp;
		}
	}
}

/*A comparator takes two arguments and uses some algorithm to compare them. If the first argument is larger or greater than the 2nd it returns true, otherwise it returns false. Here is an example that works on integers*/
function exComparator( int1, int2){
	if (int1 > int2){
		return true;
	} else {
		return false;
	}
}

/*For all comparators if cars are 'tied' according to the comparison rules then the order of those 'tied' cars is not specified and either can come first*/

/*This compares two automobiles based on their year. Newer cars are "greater" than older cars.*/
function yearComparator( auto1, auto2){
	//Create variables to hold the year of each automobile being compared
	var year1 = auto1.year;
	var year2 = auto2.year;

	//Return true if year1 < year2 and false otherwise
	if(year1 < year2) {
		return true;
	} else {
		return false;
	}
}

/*This compares two automobiles based on their make. It should be case insensitive and makes which are alphabetically earlier in the alphabet are "greater" than ones that come later.*/
function makeComparator( auto1, auto2){
	//Create variables to hold the make of each automobile being compared
	var make1 = auto1.make;
	var make2 = auto2.make;
	//Make each string lowercase to make the sort case-insensitive
	make1 = make1.toLowerCase();
	make2 = make2.toLowerCase();

	//Return true if make1 > make2 (later, alphabetically) and false otherwise
	if(make1 > make2) {
		return true;
	} else {
		return false;
	}
}

/*This compares two automobiles based on their type. The ordering from "greatest" to "least" is as follows: roadster, pickup, suv, wagon, (types not otherwise listed). It should be case insensitive. If two cars are of equal type then the newest one by model year should be considered "greater".*/
function typeComparator( auto1, auto2){
	//Create variables to hold the type of each automobile being compared
	var type1 = auto1.type;
	var type2 = auto2.type;
	//Make each string lowercase to make the sort case-insensitive
	type1 = type1.toLowerCase();
	type2 = type2.toLowerCase();

	//Create variables to hold the value of each type
	//(this will be used to create the arbitrary order)
	var typeVal1 = 0;
	var typeVal2 = 0;

	//Assign typeVal1
	if(type1 == "wagon") {
		typeVal1 = 1;
	} else if(type1 == "suv") {
		typeVal1 = 2;
	} else if(type1 == "pickup") {
		typeVal1 = 3;
	} else if(type1 == "roadster") {
		typeVal1 = 4;
	}

	//Assign typeVal2
	if(type2 == "wagon") {
		typeVal2 = 1;
	} else if(type2 == "suv") {
		typeVal2 = 2;
	} else if(type2 == "pickup") {
		typeVal2 = 3;
	} else if(type2 == "roadster") {
		typeVal2 = 4;
	}
	
	//Return true if typeVal1 < typeVal2 and false otherwise
	if(typeVal1 < typeVal2) {
		return true;
	} else {
		return false;
	}
}

/*Your program should output the following to the console.log, including the opening and closing 5 stars. All values in parenthesis should be replaced with appropriate values. Each line is a seperate call to console.log.
 *
 * Each line representing a car should be produced via a logMe function. This function should be added to the Automobile class and accept a single boolean argument. If the argument is 'true' then it prints "year make model type" with the year, make, model and type being the values appropriate for the automobile. If the argument is 'false' then the type is ommited and just the "year make model" is logged.
 *
 * *****
 * The cars sorted by year are:
 * (year make model of the 'greatest' car)
 * (...)
 * (year make model of the 'least' car)
 *
 * The cars sorted by make are:
 * (year make model of the 'greatest' car)
 * (...)
 * (year make model of the 'least' car)
 *
 * The cars sorted by type are:
 * (year make model type of the 'greatest' car)
 * (...)
 * (year make model type of the 'least' car)
 * *****
 *
 * As an example of the content in the parenthesis:
 * 1990 Ford F-150 */

/*Add logMe() to Automobile prototype*/
Automobile.prototype.logMe = function(printType) {
	//Print with type if passed true, and without if passed false
	if(printType) {
		console.log(this.year + " " + this.make + " " + this.model + " -- " + this.type);
	} else {
		console.log(this.year + " " + this.make + " " + this.model);
	}
}

//Log list to console, sorted by year
console.log();
sortArr(yearComparator, automobiles);
console.log("The cars sorted by year are: ");
for(var i = 0; i < automobiles.length; i++) {
  	automobiles[i].logMe(false);
}

//Log list to console, sorted by make
console.log();
sortArr(makeComparator, automobiles);
console.log("The cars sorted by make are: ");
for(var i = 0; i < automobiles.length; i++) {
  	automobiles[i].logMe(false);
}

//Log list to console, sorted by type
console.log();
sortArr(typeComparator, automobiles);
console.log("The cars sorted by type are: ");
for(var i = 0; i < automobiles.length; i++) {
  	automobiles[i].logMe(true);
}
console.log();

