/*
 * Name: Benjamin Tate
 * Date: 7/19/2016
 * Filename: Assignment2-definition-6.sql
 * Class: CS340 - Section 400
 * Assignment: SQL Assignment 
 */

-- For part one of this assignment you are to make a database with the following specifications and run the following queries
-- The drop table queries below are to facilitate testing on my end

DROP TABLE IF EXISTS `os_support`;
DROP TABLE IF EXISTS `device`;
DROP TABLE IF EXISTS `operating_system`;
DROP TABLE IF EXISTS `category_tbl`;


-- Create a table called category_tbl with the following properties:
-- id - an auto incrementing integer which is the primary key
-- name - a varchar with a maximum length of 255 characters, cannot be null
-- subcategory - a varchar with a maximum length of 255 characters, cannot be null
-- the combinatino of a name and subcategory must be unique
CREATE TABLE `category_tbl` (
	`id` int(11) NOT NULL AUTO_INCREMENT,
	`name` varchar(255) NOT NULL,
	`subcategory` varchar(255) NOT NULL,
	PRIMARY KEY(`id`),
	UNIQUE KEY(`name`, `subcategory`)
) ENGINE=InnoDB;

-- Create a table called operating_system with the following properties:
-- id - an auto incrementing integer which is the primary key
-- name - a varchar of maximum length 255, cannot be null
-- version - a varchar of maximum length 255, cannot be null
-- name version combinations must be unique
CREATE TABLE `operating_system` (
	`id` int(11) NOT NULL AUTO_INCREMENT,
	`name` varchar(255) NOT NULL,
	`version` varchar(255) NOT NULL,
	PRIMARY KEY(`id`),
	UNIQUE KEY(`name`, `version`)
) ENGINE=InnoDB;

-- Create a table called device with the following properties:
-- id - an auto incrementing integer which is the primary key
-- cid - an integer which is a foreign key reference to the category_tbl table
-- name - a varchar of maximum length 255 which cannot be null
-- received - a date type (you can read about it here http://dev.mysql.com/doc/refman/5.0/en/datetime.html)
-- isbroken - a boolean
CREATE TABLE `device` (
	`id` int(11) NOT NULL AUTO_INCREMENT,
	`cid` int(11) NOT NULL DEFAULT '0',
	`name` varchar(255) NOT NULL,
	`received` date,
	`isbroken` boolean,
	PRIMARY KEY(`id`),
	UNIQUE KEY(`name`),
	CONSTRAINT `device_fk` FOREIGN KEY(`cid`) REFERENCES `category_tbl`(`id`)
) ENGINE=InnoDB;

-- Create a table called os_support with the following properties, this is a table representing a many-to-many relationship
-- between devices and operating systems:
-- did - an integer which is a foreign key reference to device
-- osid - an integer which is a foreign key reference to operating_system
-- notes - a text type
-- The primary key is a combination of did and osid
CREATE TABLE `os_support` (
	`did` int(11),
	`osid` int(11),
	`notes` text,
	CONSTRAINT `os_support_fk1` FOREIGN KEY(`did`) REFERENCES `device`(`id`),
	CONSTRAINT `os_support_fkr2` FOREIGN KEY(`osid`) REFERENCES `operating_system`(`id`)
) ENGINE=InnoDB;

-- insert the following into the category_tbl table:

-- name: phone
-- subcategory: maybe a tablet?

-- name: tablet
-- subcategory: but kind of a laptop

-- name: tablet
-- subcategory: ereader
INSERT INTO `category_tbl` (name, subcategory) VALUES
	("phone", "maybe a tablet?"),
	("tablet", "but kind of a laptop"),
	("tablet", "ereader");


-- insert the folowing into the operating_system table:
-- name: Android
-- version: 1.0

-- name: Android
-- version: 2.0

-- name: iOS
-- version: 4.0
INSERT INTO `operating_system` (name, version) VALUES 
	("Android", "1.0"),
	("Android", "2.0"),
	("iOS", "4.0");


-- insert the following devices instances into the device table (you should use a subquery to set up foriegn keys referecnes, no hard coded numbers):
-- cid - reference to name: phone subcategory: maybe a tablet?
-- name - Samsung Atlas
-- received - 1/2/1970
-- isbroken - True

-- cid - reference to name: tablet subcategory: but kind of a laptop
-- name - Nokia
-- received - 5/6/1999
-- isbroken - False

-- cid - reference to name: tablet subcategory: ereader
-- name - jPad
-- received - 11/18/2005
-- isbroken - False
INSERT INTO `device` (cid, name, received, isbroken) VALUES
	((SELECT id FROM category_tbl WHERE name="phone" AND subcategory="maybe a tablet?"),
		'Samsung Atlas', '1970-01-02', TRUE),
	((SELECT id FROM category_tbl WHERE name="tablet" AND subcategory="but kind of a laptop"),
		'Nokia', '1999-05-06', FALSE),
	((SELECT id FROM category_tbl WHERE name="tablet" AND subcategory="ereader"),
		'jPad', '2005-11-18', FALSE);


-- insert the following into the os_support table using subqueries to look up data as needed:
-- device: Samsung Atlas
-- os: Android 1.0
-- notes: Works poorly

-- device: Samsung Atlas
-- os: Android 2.0
-- notes: NULL

-- device: jPad
-- os: iOS 4.0
-- notes: NULL
INSERT INTO `os_support` (did, osid, notes) VALUES 
	((SELECT id AS did FROM device WHERE name="Samsung Atlas"),
		(SELECT id AS osid FROM operating_system WHERE name="Android" AND version="1.0"),
		'Works poorly'),
	((SELECT id AS did FROM device WHERE name="Samsung Atlas"),
		(SELECT id AS osid FROM operating_system WHERE name="Android" AND version="2.0"),
		NULL),
	((SELECT id AS did FROM device WHERE name="jPad"),
		(SELECT id AS osid FROM operating_system WHERE name="iOS" AND version="4.0"),
		NULL);


