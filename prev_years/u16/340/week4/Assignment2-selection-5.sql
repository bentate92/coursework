/*
 * Name: Benjamin Tate
 * Date: 7/19/2016
 * Filename: Assignment2-selection-5.sql
 * Class: CS340 - Section 400
 * Assignment: SQL Assignment 
 */

/*1 Find all films with maximum length and minimum rental duration (compared to all other films). 
In other words let L be the maximum film length, and let R be the minimum rental duration in the table film. You need to find all films with length L and rental duration R.
You just need to return attribute film id for this query.*/
SELECT film_id FROM film WHERE 
length = (SELECT MAX(length) FROM film) AND
rental_duration = (SELECT MIN(rental_duration) FROM film)
GROUP BY film_id;


/*2 We want to find out how many actors have played in each film, so for each film return the film id, film title, and the number of actors who played in that film. Some films may have no actors, and your query does not need to return those films.*/
SELECT titles.film_id AS film_id, titles.title AS title, actors.actor_count AS actor_count FROM (
	SELECT film_id, title FROM film F
) AS titles
INNER JOIN (
	SELECT film_id AS fid, COUNT(actor_id) AS actor_count FROM film_actor GROUP BY fid
) AS actors ON actors.fid=titles.film_id;

/*3 Find the average length of films for each language. Your query should return every language even if there is no films in that language. language refers to attribute language_id (not attribute original_language_id)*/
SELECT languages.language, languages.lid AS language_id, films.average_length FROM (
	SELECT language_id, AVG(length) AS average_length FROM film GROUP BY language_id
) AS films 
RIGHT JOIN (
	SELECT language_id AS lid, name AS language FROM language
) AS languages ON languages.lid=films.language_id;


/*4 We want to find out how many of each category of film KEVIN BLOOM has started in so return a table with category.name and the count
of the number of films that KEVIN was in which were in that category order by the category name ascending (Your query should return every category even if KEVIN has been in no films in that category).*/
SELECT name AS category, COUNT(actor_id) AS kev_count FROM (
	SELECT first_name, last_name, actor_id FROM actor A WHERE first_name='KEVIN' AND last_name='BLOOM') AS tbl1
INNER JOIN (
	SELECT actor_id AS aaid, film_id AS afid FROM film_actor
) AS tbl2 ON tbl1.actor_id=tbl2.aaid
INNER JOIN (
	SELECT film_id FROM film
) AS tbl3 ON tbl2.afid=tbl3.film_id
RIGHT JOIN (
	SELECT film_id AS cfid, category_id AS ccid FROM film_category
) AS tbl4 ON tbl3.film_id=tbl4.cfid
INNER JOIN (
	SELECT category_id, name FROM category
) AS tbl5 ON tbl4.ccid=tbl5.category_id
GROUP BY name
ORDER BY name ASC;


/*5 Find the film title of all films which do not feature both SCARLETT DAMON and BEN HARRIS(so you will not list a film if both of these actors have played in that film, but if only one or none of these actors have played in a film, that film should be listed).
Order the results by title, descending (use ORDER BY title DESC at the end of the query)
Warning, this is a tricky one and while the syntax is all things you know, you have to think oustide
the box a bit to figure out how to get a table that shows pairs of actors in movies*/
SELECT title FROM (
	SELECT title, COUNT(aid) AS count FROM (
		SELECT film_id AS fid, title FROM film
	) AS tbl1
	INNER JOIN (
		SELECT actor_id AS aaid, film_id AS afid FROM film_actor
	) AS tbl2 ON tbl1.fid=tbl2.afid
	LEFT JOIN (
		SELECT actor_id AS aid, first_name, last_name FROM actor
		WHERE (first_name='BEN' AND last_name='HARRIS') OR (first_name='SCARLETT' AND last_name='DAMON')
	) AS tbl3 ON tbl2.aaid=tbl3.aid
	GROUP BY title
	ORDER BY title DESC
) AS tbl4 WHERE NOT count=2;
