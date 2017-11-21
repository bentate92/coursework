/*
 * Name: Benjamin Tate
 * Date: 8/3/16
 * Filename: final.js
 * Class: CS290 - Section 400
 * Assignment: Final Project
 * URL: http://52.41.46.3:3040/
 */

var express = require('express');

var app = express();
var handlebars = require('express-handlebars').create({defaultLayout:'main'});

var bodyParser = require('body-parser');
app.use(bodyParser.urlencoded({ extended: false }));
app.use(bodyParser.json());

app.engine('handlebars', handlebars.engine);
app.set('view engine', 'handlebars');
app.set('port', 3040);

var mysql = require('mysql');
var pool = mysql.createPool({
	host	: 'localhost',
	user	: 'student',
	password: 'default',
	database: 'student'
});

app.get('/', function(req, res, next) {
	//Create empty object to data to send back
	var context = {};

	//Select all rows from database
	pool.query('SELECT id, name, reps, weight, DATE_FORMAT(date,"%Y-%m-%d") AS date, lbs FROM workouts', function(err,rows,fields) {
		if(err) {
			console.log(err.message);
			console.log(err.stack);
			return;
		}

		context.results = rows;

		//Format units
		for(var i = 0; i < context.results.length; i++) {
			if(context.results[i].lbs == '0') {
				context.results[i].unit = 'kilograms';
			} else if (context.results[i].lbs == '1') {
				context.results[i].unit = 'pounds';
			}
		}

		res.render('finalhome', context);
	});
});

app.post('/insert', function(req,res,next) {
	//Create empty object to data to send back
	var context = {};

	//Insert new row into database
	pool.query('INSERT INTO workouts (name, reps, weight, date, lbs) '+
		'VALUES (?,?,?,?,?)', 
		[req.body.name, 
		 req.body.reps, 
		 req.body.weight, 
		 req.body.date, 
		 req.body.lbs], function(err, result) {
		if(err) {
			console.log(err.message);
			console.log(err.stack);
			return;
		}
		
			//Select all rows from database
			pool.query('SELECT id, name, reps, weight, DATE_FORMAT(date,"%Y-%m-%d") AS date, lbs FROM workouts', function(err,rows,fields) {
			if(err) {
				console.log(err.message);
				console.log(err.stack);
				return;
			}
		
			context.results = rows;

			for(var i = 0; i < context.results.length; i++) {
				if(context.results[i].lbs == '0') {
					context.results[i].unit = 'kilograms';
				} else if (context.results[i].lbs == '1') {
					context.results[i].unit = 'pounds';
				}
			}

			res.send(context.results);
		});
	});
});

app.post('/delete', function(req,res,next) {
	//Create empty object to data to send back
	var context = {};

	//Delete given row from database
	pool.query('DELETE FROM workouts WHERE id=(?)', [req.body.id], function(err, result){
		if(err) {
			console.log(err.message);
			console.log(err.stack);
			return;
		}

		//Select all rows from database
		pool.query('SELECT id, name, reps, weight, DATE_FORMAT(date,"%Y-%m-%d") AS date, lbs FROM workouts', function(err,rows,fields) {
			if(err) {
				console.log(err.message);
				console.log(err.stack);
				return;
			}
		
			context.results = rows;

			//Format units
			for(var i = 0; i < context.results.length; i++) {
				if(context.results[i].lbs == '0') {
					context.results[i].unit = 'kilograms';
				} else if (context.results[i].lbs == '1') {
					context.results[i].unit = 'pounds';
				}
			}

			res.send(context.results);
		});
	});
});

app.post('/edit', function(req,res,next) {
	//Create empty object to data to send back
	var context = {};

	//Select given row from database to populate client side table	
	pool.query('SELECT id, name, reps, weight, DATE_FORMAT(date,"%Y-%m-%d") AS date, lbs FROM workouts WHERE id=(?)', [req.body.id], function(err,rows,fields) {
		if(err) {
			console.log(err.message);
			console.log(err.stack);
			return;
		}

		context.results = rows;
		res.send(context.results);
	});
});

app.post('/update', function(req,res,next) {
	//Create empty object to data to send back
	var context = {};

	//Update given row with given values
	pool.query('UPDATE workouts SET name=?, reps=?, weight=?, date=?, lbs=? WHERE id=?',
	[req.body.name, req.body.reps, req.body.weight, req.body.date, req.body.lbs, req.body.id],
	function(err, result) {
		if(err) {
			console.log(err.message);
			console.log(err.stack);
			return;
		}
	});

	//Select all rows from database
	pool.query('SELECT id, name, reps, weight, DATE_FORMAT(date,"%Y-%m-%d") AS date, lbs FROM workouts', function(err,rows,fields) {
		if(err) {
			console.log(err.message);
			console.log(err.stack);
			return;
		}

		context.results = rows;

		//Format units
		for(var i = 0; i < context.results.length; i++) {
			if(context.results[i].lbs == '0') {
				context.results[i].unit = 'kilograms';
			} else if (context.results[i].lbs == '1') {
				context.results[i].unit = 'pounds';
			}
		}

		res.send(context.results);
	});
});

app.get('/reset-table',function(req,res,next){
	var context = {};
	pool.query("DROP TABLE IF EXISTS workouts", function(err){ 
		var createString = "CREATE TABLE workouts("+
		"id INT PRIMARY KEY AUTO_INCREMENT,"+
		"name VARCHAR(255) NOT NULL,"+
		"reps INT,"+
		"weight INT,"+
		"date DATE,"+
		"lbs BOOLEAN)";
		pool.query(createString, function(err){
			context.results = "Table reset";
			res.render('finalhome',context);
		})
	});
});

//Send invalid page requests to 404.handlebars
app.use(function(req,res){
	res.status(404);
	res.render('404');
});

//Send server errors to 500.handlebars
app.use(function(err, req, res, next){
	console.error(err.stack);
	res.type('plain/text');
	res.status(500);
	res.render('500');
});

app.listen(app.get('port'), function(){
	console.log('Express started on http://localhost:' + app.get('port') + '; press Ctrl-C to terminate.');
});
