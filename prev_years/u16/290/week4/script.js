/*
 * Name: Benjamin Tate
 * Date: 7/17/2016
 * Filename: script.js
 * Class: CS290 - Section 400
 * Assignment: DOM and Events
 */

//Update title element text
var title = document.getElementsByTagName("title")[0]
title.textContent = "DOM and Events Assignment";

//Create variable to hold document.body
var body = document.body;

//Create table and append to body node
var table = document.createElement("table");
table.border = '1';
body.appendChild(table);

//Create header row and append to table
var row0 = document.createElement("tr");
row0.id = 'row0';
table.appendChild(row0);

//Create columns for row0
var col1 = document.createElement("td");
col1.id = '01';
col1.textContent = "Header 1";
var col2 = document.createElement("td");
col2.id = '02';
col2.textContent = "Header 2";
var col3 = document.createElement("td");
col3.id = '03';
col3.textContent = "Header 3";
var col4 = document.createElement("td");
col4.id = '04';
col4.textContent = "Header 4";

//Append columns to row
row0.appendChild(col1);
row0.appendChild(col2);
row0.appendChild(col3);
row0.appendChild(col4);

//Create columns for row1
var row1 = document.createElement("tr");
row1.id = 'row1';
table.appendChild(row1);
col1 = document.createElement("td");
col1.id = '11';
col1.textContent = "1, 1";
col2 = document.createElement("td");
col2.id = '12';
col2.textContent = "2, 1";
col3 = document.createElement("td");
col3.id = '13';
col3.textContent = "3, 1";
col4 = document.createElement("td");
col4.id = '14';
col4.textContent = "4, 1";

//Append columns to row
row1.appendChild(col1);
row1.appendChild(col2);
row1.appendChild(col3);
row1.appendChild(col4);

//Create columns for row2
var row2 = document.createElement("tr");
row2.id = 'row2';
table.appendChild(row2);
col1 = document.createElement("td");
col1.id = '21';
col1.textContent = "1, 2";
col2 = document.createElement("td");
col2.id = '22';
col2.textContent = "2, 2";
col3 = document.createElement("td");
col3.id = '23';
col3.textContent = "3, 2";
col4 = document.createElement("td");
col4.id = '24';
col4.textContent = "4, 2";

//Append columns to row
row2.appendChild(col1);
row2.appendChild(col2);
row2.appendChild(col3);
row2.appendChild(col4);

//Create columns for row3
var row3 = document.createElement("tr");
row3.id = 'row3';
table.appendChild(row3);
col1 = document.createElement("td");
col1.id = '31';
col1.textContent = "1, 3";
col2 = document.createElement("td");
col2.id = '32';
col2.textContent = "2, 3";
col3 = document.createElement("td");
col3.id = '33';
col3.textContent = "3, 3";
col4 = document.createElement("td");
col4.id = '34';
col4.textContent = "4, 3";

//Append columns to row
row3.appendChild(col1);
row3.appendChild(col2);
row3.appendChild(col3);
row3.appendChild(col4);

//Create and append line break to body
var br = document.createElement("br");
body.appendChild(br);

//Create div to hold button layout and append to body
var buttons = document.createElement("div");
buttons.id = 'buttons';
buttons.style.width = '180px';
buttons.style.height = '60px';
buttons.style.textAlign = 'center';
body.appendChild(buttons);

//Create 'Up' button and append to buttons div
var up = document.createElement("button");
up.id = 'up';
up.textContent = "Up";
up.style.height = '21px'
up.style.width = '50px';
buttons.appendChild(up);

//Append line break to buttons div
br = document.createElement("br");
buttons.appendChild(br);

//Create 'Left' button and append to buttons div
var left = document.createElement("button");
left.id = 'left';
left.textContent = "Left";
left.style.height = '21px';
left.style.width = '50px';
buttons.appendChild(left);

//Create 'Mark Cell' button and append to buttons div
var mark = document.createElement("button");
mark.id = 'mark';
mark.textContent = "Mark Cell";
mark.style.height = '21px';
mark.style.width = '80px';
mark.style.backgroundColor = 'yellow';
buttons.appendChild(mark);

//Create 'Right' button and append to buttons div
var right = document.createElement("button");
right.id = 'right';
right.textContent = "Right";
right.style.height = '21px';
right.style.width = '50px';
buttons.appendChild(right);

//Append line break to buttons div
br = document.createElement("br");
buttons.appendChild(br);

//Create 'Down' button and append to buttons div
var down = document.createElement("button");
down.id = 'down';
down.textContent = "Down";
down.style.height = '21px';
down.style.width = '50px';
buttons.appendChild(down);

//Create variable current to hold currently selected cell, initialize to top-left
var current = document.getElementById('11');
selectCell(current);

/*
 * Function: selectCell()
 * Description: Selects a cell by making its border thicker
 * Parameter: selection -- A cell of the table
 * Conditions: selection must be a valid cell
 */
function selectCell(selection) {
	selection.style.border = 'solid 3px';
	current = selection;
}

/*
 * Function: subChar()
 * Description: Subtracts 1 from a given index of a cell id
 * Parameters: str -- The string holding the current id
 * 			   idx -- The index at which to subtract 1
 * Conditions: str must be a valid string, idx must be a valid integer, and idx
 * 			   must be less than the length of str
 */
function subChar(str, idx) {
	var newStr = str.substr(0,idx) + str.charAt(idx) - 1 + str.substr(idx+1);
	return newStr;
}

/*
 * Function: addChar()
 * Description: Adds 1 to a given index of a cell id
 * Parameters: str -- The string holding the current id
 * 			   idx -- The index at which to add 1
 * Conditions: str must be a valid string, idx must be a valid integer, and idx
 * 			   must be less than the length of str
 */
function addChar(str, idx) {
	var newStr = str.substr(0,idx) + str.charAt(idx) - (-1) + str.substr(idx+1);
	return newStr;
}

/*
 * Function: moveUp()
 * Description: Moves current cell up 1 if it is not already in the top row
 * Parameters: None
 * Conditions: current must contain a valid cell
 */
function moveUp() {
	//Create var to hold current cell's id
	var update = current.id;

	//If current is not already in the top row...
	if(update.charAt(0) != '1') {
		//Change current's border to original thickness
		current.style.border = 'solid 1px';
		//Call subChar() to change update to the id of the new cell
		update = subChar(update, 0);
		//Update current cell
		current = document.getElementById(update);
		//Call selectCell() to select new current
		selectCell(current);
	}
}

/*
 * Function: moveLeft()
 * Description: Moves current cell left 1 if it is not already in the first column
 * Parameters: None
 * Conditions: current must contain a valid cell
 */
function moveLeft() {
	//Create var to hold current cell's id
	var update = current.id;

	//If current is not already in the first column...
	if(update.charAt(1) != '1') {
		//Change current's border to original thickness
		current.style.border = 'solid 1px';
		//Call subChar() to change update to the id of the new cell
		update = subChar(update, 1);
		//Update current cell
		current = document.getElementById(update);
		//Call selectCell() to select new current
		selectCell(current);
	}
}

/*
 * Function: moveRight()
 * Description: Moves current cell right 1 if it is not already in the last column
 * Parameters: None
 * Conditions: current must contain a valid cell
 */
function moveRight() {
	//Create var to hold current cell's id
	var update = current.id;

	//If current is not already in the last column...
	if(update.charAt(1) != '4') {
		//Change current's border to original thickness
		current.style.border = 'solid 1px';
		//Call addChar() to change update to the id of the new cell
		update = addChar(update, 1);
		//Update current cell
		current = document.getElementById(update);
		//Call selectCell() to select new current
		selectCell(current);
	}
}

/*
 * Function: moveDown()
 * Description: Moves current cell down 1 if it is not already in the bottom row
 * Parameters: None
 * Conditions: current must contain a valid cell
 */
function moveDown() {
	//Create var to hold current cell's id
	var update = current.id;

	//If current is not already in the bottom row...
	if(update.charAt(0) != '3') {
		//Change current's border to original thickness
		current.style.border = 'solid 1px';
		//Call addChar() to change update to the id of the new cell
		update = addChar(update, 0);
		//Update current cell
		current = document.getElementById(update);
		//Call selectCell() to select new current
		selectCell(current);
	}
}

/* Function: markCell()
 * Description: Permanently changes current cell's background color to yellow
 * Parameters: None
 * Conditions: current must contain a valid cell
 */
function markCell() {
	current.style.backgroundColor = 'yellow';
}

//Add click events to each button with appropriate functions
document.getElementById('up').addEventListener('click', moveUp);
document.getElementById('left').addEventListener('click', moveLeft);
document.getElementById('right').addEventListener('click', moveRight);
document.getElementById('down').addEventListener('click', moveDown);
document.getElementById('mark').addEventListener('click', markCell);
