--Q10 (Nexus)
SELECT name, COUNT(name) AS CertCount FROM bsg_planets Pl
INNER JOIN (SELECT id AS pe_id, homeworld FROM bsg_people) AS Pe ON Pe.homeworld = Pl.id
INNER JOIN bsg_cert_people CP ON CP.pid = Pe.pe_id
GROUP BY name
--Q11 (glider)
SELECT DISTINCT tbl1.fname, tbl1.lname FROM (
	SELECT * FROM bsg_people P
	INNER JOIN bsg_ship_assignment SA ON SA.pid=P.id
	INNER JOIN (SELECT class FROM bsg_ship_instance) AS SI ON SI.class = SA.cid
	INNER JOIN (SELECT id AS class_id, name FROM bsg_ship_class) AS SC ON SC.class_id=SI.class) AS tbl1
WHERE name='Viper'
--Q12 (lamy)
SELECT people.fname AS fname, people.lname AS lname, ships.si_id AS id FROM
(SELECT id, fname, lname FROM bsg_people P
	    WHERE P.id !=2 && P.id != 4) AS people
	INNER JOIN (
		SELECT * FROM bsg_ship_assignment SA
		INNER JOIN (SELECT id AS si_id, class FROM bsg_ship_instance) AS SI ON SI.si_id=SA.sid AND SI.class = SA.cid
		INNER JOIN (SELECT id AS sc_id, name FROM bsg_ship_class WHERE name ='Viper') AS SC ON SC.sc_id = SI.class
	) AS ships ON people.id = ships.pid
