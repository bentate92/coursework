CREATE TABLE `bsg_cert` (
	  `id` int(11) NOT NULL AUTO_INCREMENT,
	  `title` varchar(255) NOT NULL,
	  PRIMARY KEY (`id`)
) ENGINE=InnoDB

CREATE TABLE `bsg_cert_people` (
	  `cid` int(11) NOT NULL DEFAULT '0',
	  `pid` int(11) NOT NULL DEFAULT '0',
	  PRIMARY KEY (`cid`,`pid`),
	  KEY `pid` (`pid`),
	  CONSTRAINT `bsg_cert_people_ibfk_1` FOREIGN KEY (`cid`) REFERENCES `bsg_cert` (`id`),
	  CONSTRAINT `bsg_cert_people_ibfk_2` FOREIGN KEY (`pid`) REFERENCES `bsg_people` (`id`)
) ENGINE=InnoDB

CREATE TABLE `bsg_people` (
	  `id` int(11) NOT NULL AUTO_INCREMENT,
	  `fname` varchar(255) NOT NULL,
	  `lname` varchar(255) DEFAULT NULL,
	  `homeworld` int(11) DEFAULT NULL,
	  `age` int(11) DEFAULT NULL,
	  PRIMARY KEY (`id`),
	  KEY `homeworld` (`homeworld`),
	  CONSTRAINT `bsg_people_ibfk_1` FOREIGN KEY (`homeworld`) REFERENCES `bsg_planets` (`id`) ON DELETE SET NULL ON UPDATE CASCADE
) ENGINE=InnoDB

CREATE TABLE `bsg_planets` (
	  `id` int(11) NOT NULL AUTO_INCREMENT,
	  `name` varchar(255) NOT NULL,
	  `population` bigint(20) DEFAULT NULL,
	  `language` varchar(255) DEFAULT NULL,
	  `capital` varchar(255) DEFAULT NULL,
	  PRIMARY KEY (`id`),
	  UNIQUE KEY `name` (`name`)
) ENGINE=InnoDB
