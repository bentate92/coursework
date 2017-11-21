DROP TABLE IF EXISTS pets_lost;
DROP TABLE IF EXISTS pets_found;

CREATE TABLE pets_lost (
	lid SMALLINT UNSIGNED NOT NULL AUTO_INCREMENT,
	species VARCHAR(50) NOT NULL,
	breed VARCHAR(50) NOT NULL,
	color VARCHAR(20) NOT NULL,
	gender VARCHAR(10) NOT NULL,
	approx_size VARCHAR(10) NOT NULL,
	PRIMARY KEY (lid),
	CONSTRAINT `gender_check` CHECK (
		gender = 'male' OR 
		gender = 'female' OR 
		gender = 'unkown'
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
	species VARCHAR(50), NOT NULL
	breed VARCHAR(50) NOT NULL,
	color VARCHAR(20) NOT NULL,
	gender VARCHAR(10) NOT NULL,
	approx_size VARCHAR(10) NOT NULL,
	PRIMARY KEY (lid),
	CONSTRAINT `gender_check` CHECK (
		gender = 'male' OR 
		gender = 'female' OR 
		gender = 'unkown'
	),
	CONSTRAINT `size_check` CHECK (
		approx_size = 'small' OR
		approx_size = 'medium' OR
		approx_size = 'large' OR
		approx_size = 'xl'
	)
)ENGINE=InnoDB DEFAULT CHARSET=utf8;
