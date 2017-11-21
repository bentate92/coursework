DROP TABLE IF EXISTS pets_lost;
DROP TABLE IF EXISTS pets_found;

CREATE TABLE pets_lost (
	lid SMALLINT UNSIGNED NOT NULL AUTO_INCREMENT,
	species VARCHAR(50),
	breed VARCHAR(50),
	color1 VARCHAR(20),
	color2 VARCHAR(20),
	color3 VARCHAR(20),
	gender VARCHAR(10),
	approx_size VARCHAR(10),
	pet_name VARCHAR(20),
	date_lost DATE,
	
	
	PRIMARY KEY (lid),
	CONSTRAINT `gender_check` CHECK (
		gender = 'male' OR 
		gender = 'female' OR 
		gender = 'unknown'
	),
	CONSTRAINT `size_check` CHECK (
		approx_size = 'small' OR
		approx_size = 'medium' OR
		approx_size = 'large' OR
		approx_size = 'xl'
	)
)ENGINE=InnoDB DEFAULT CHARSET=utf8;

CREATE TABLE pets_found (
	lid SMALLINT UNSIGNED NOT NULL AUTO_INCREMENT,
	species VARCHAR(50),
	breed VARCHAR(50),
	color1 VARCHAR(20),
	color2 VARCHAR(20),
	color3 VARCHAR(20),
	gender VARCHAR(10),
	approx_size VARCHAR(10),
	pet_name VARCHAR(20),
	date_found DATE,
	
	
	PRIMARY KEY (lid),
	CONSTRAINT `gender_check` CHECK (
		gender = 'male' OR 
		gender = 'female' OR 
		gender = 'unknown'
	),
	CONSTRAINT `size_check` CHECK (
		approx_size = 'small' OR
		approx_size = 'medium' OR
		approx_size = 'large' OR
		approx_size = 'xl'
	)
)ENGINE=InnoDB DEFAULT CHARSET=utf8;
