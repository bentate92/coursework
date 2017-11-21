INSERT INTO hometowns (city, country, current_pop) VALUES 
	("Hazlehurst, MS", "US", 4009),
	("Como, MS", "US", 1310),
	("Cheltenham, Gloucestershire", "ENG", 116495),
	("Seattle, WA", "US", 684451),
	("Port Arthur, TX", "US", 57755),
	("Melborne, FL", "US", 76068),
	("San Bruno, CA", "US", 41114),
	("Boone, NC", "US", 17186),
	("Aberdeen, WA", "US", 16276);

INSERT INTO genres (genre) VALUES
	("blues"), ("r&b"), ("rock"), ("country");

INSERT INTO instruments (instrument) VALUES
	("guitar"), ("vocals"), ("harmonica"), ("organ"), ("fiddle");

INSERT INTO artists (fname, lname, hometown, genre) VALUES
	("Robert", "Johnson", 1, 1),
	("Joe", "Henderson", 2, 2),
	("Brian", "Jones", 3, 3),
	("Jimi", "Hendrix", 4, 3),
	("Janis", "Joplin", 5, 3),
	("Jim", "Morrison", 6, 3),
	("Ron", "McKernan", 7, 1),
	("Chris", "Austin", 8, 4),
	("Kurt", "Cobain", 9, 3);

INSERT INTO art_inst (ai_aid, ai_iid, main) VALUES
	(1, 1, true), (1, 2, true),
	(2, 2, true),
	(3, 1, true), (3, 3, false),
	(4, 1, true), (4, 2, false),
	(5, 1, false), (5, 2, true),
	(6, 2, true),
	(7, 2, true), (7, 3, false), (7, 4, false),
	(8, 1, true), (8, 2, true), (8, 5, false),
	(9, 1, true), (9, 2, true);

INSERT INTO inspirations (luminary, inspired, relationship) VALUES
	(1, 3, null), (1, 4, null), (1, 6, null),
	(1, 9, null), (5, 4, null), (4, 9, null);
