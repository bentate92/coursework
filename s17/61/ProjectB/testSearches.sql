--When someone finds a pet (searching for lost pets)
INSERT INTO pets_found 
	(species, breed, color1, color2, color3, gender, 
		approx_size, pet_name, date_found)
	VALUES ('dog', 'lab', 'brown', 'chocolate', 
		'dark brown', 'male', 'large', 'Mr. Doggo', 
		'2017-06-07');

SELECT * FROM pets_lost
	WHERE species = 'dog'
	AND breed = 'lab'
	AND color1 = 'brown'
	AND color2 = 'chocolate'
	AND color3 = 'dark brown'
	AND gender = 'male'
	AND approx_size = 'large'
	AND pet_name = 'Mr. Doggo';


--When someone lost a pet (searching for found pets)
INSERT INTO pets_lost 
	(species, breed, color1, color2, color3, gender, 
		approx_size, pet_name, date_lost)
	VALUES ('dog', 'lab', 'brown', 'chocolate', 
		'dark brown', 'male', 'large', 'Mr. Doggo', 
		'2017-06-07');

SELECT * FROM pets_found
	WHERE species = 'dog'
	AND breed = 'lab'
	AND color1 = 'brown'
	AND color2 = 'chocolate'
	AND color3 = 'dark brown'
	AND gender = 'male'
	AND approx_size = 'large'
	AND pet_name = 'Mr. Doggo';
