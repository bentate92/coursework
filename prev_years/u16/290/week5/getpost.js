/*
 * Name: Benjamin Tate
 * Date: 7/24/16
 * Filename: getpost.js
 * Class: CS290 - Section 400
 * Assignment: GET and POST checker
 * URL: http://52.41.46.3:3030/
 */

var express = require('express');

var app = express();
var handlebars = require('express-handlebars').create({defaultLayout:'main'});

var bodyParser = require('body-parser');
app.use(bodyParser.urlencoded({ extended: false }));
app.use(bodyParser.json());

app.engine('handlebars', handlebars.engine);
app.set('view engine', 'handlebars');
app.set('port', 3030);

//Route GET requests to gethome.handlebars
app.get('/', function(req, res) {
	var dataArr = [];

	for(var stuff in req.query) {
		dataArr.push({'name':stuff,'value':req.query[stuff]});
	}

	var dispObj = {};

	dispObj.things = dataArr;

	res.render('gethome', dispObj);
});

//Route POST requests to posthome.handlebars
app.post('/', function(req, res) {
	var dataArr = [];

	for(var stuff in req.body) {
		dataArr.push({'name':stuff, 'value':req.body[stuff]});
	}

	var dispObj = {};

	dispObj.things = dataArr;

	res.render('posthome', dispObj);
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
