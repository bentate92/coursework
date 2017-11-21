--NAME, HOMETOWN, & GENRE
	SELECT fname,lname,city,country,genre
	FROM (
		SELECT * 
		FROM genres g 
		INNER JOIN (
			SELECT aid, fname, lname, hometown, genre AS genreId 
			FROM artists a 
			WHERE a.aid = [searchArtInput]
		) AS tbl1 ON tbl1.genreId = g.gid 
		INNER JOIN (
			SELECT * 
			FROM hometowns
		) AS h ON h.hid = tbl1.hometown
	) AS tbl2

--INSTRUMENT COUNT
	SELECT COUNT(instrument) AS instCount 
	FROM (
		SELECT * FROM artists a 
		INNER JOIN (
			SELECT *
			FROM art_inst
		) AS ai ON ai.ai_aid = a.aid 
		INNER JOIN (
			SELECT * 
			FROM instruments 
		) AS i ON ai.ai_iid = i.iid
	) AS tbl 
	WHERE tbl.aid = [searchArtInput] 
	GROUP BY fname

--MAIN INSTRUMENTS
	SELECT instrument,main 
	FROM (
		SELECT * FROM artists a 
		INNER JOIN (
			SELECT * 
			FROM art_inst
		) AS ai ON ai.ai_aid = a.aid 
		INNER JOIN (
			SELECT * 
			FROM instruments 
		) AS i ON ai.ai_iid = i.iid
	) AS tbl 
	WHERE tbl.aid = [searchArtInput]  
	AND tbl.main = '1'

--SECONDARY INSTRUMENTS
	SELECT instrument,main 
	FROM (
		SELECT * FROM artists a 
		INNER JOIN (
			SELECT * 
			FROM art_inst
		) AS ai ON ai.ai_aid = a.aid 
		INNER JOIN (
			SELECT * 
			FROM instruments 
		) AS i ON ai.ai_iid = i.iid
	) AS tbl 
	WHERE tbl.aid = [searchArtInput]  
	AND tbl.main = '0'

--INSPIRED COUNT
	SELECT COUNT(iaid) AS lumCount 
	FROM (
		SELECT aid AS laid, fname AS lfname, lname AS llname, relationship, iaid, ifname, ilname 
		FROM artists l 
		INNER JOIN (
			SELECT * FROM inspirations insp 
			INNER JOIN (
				SELECT aid AS iaid, fname AS ifname, lname AS ilname 
				FROM artists
			) AS i ON insp.inspired = i.iaid
		) AS tbl1 ON tbl1.luminary = l.aid 
		WHERE tbl1.luminary = [searchArtInput]
	) AS tbl2 GROUP BY lfname

--INSPIRATION TO
	SELECT ifname,ilname
	FROM (
		SELECT aid AS laid, fname AS lfname, lname AS llname, relationship, iaid, ifname, ilname 
		FROM artists l 
		INNER JOIN (
			SELECT * FROM inspirations insp 
			INNER JOIN (
				SELECT aid AS iaid, fname AS ifname, lname AS ilname 
				FROM artists
			) AS i ON insp.inspired = i.iaid
		) AS tbl1 ON tbl1.luminary = l.aid 
		WHERE tbl1.luminary = [searchArtInput]
	) AS tbl2 GROUP BY lfname

--INSPIRED BY COUNT
	SELECT COUNT(laid) AS inspCount 
	FROM (
		SELECT aid AS laid, fname AS lfname, lname AS llname, relationship, iaid, ifname, ilname 
		FROM artists l 
		INNER JOIN (
			SELECT * FROM inspirations insp 
			INNER JOIN (
				SELECT aid AS iaid, fname AS ifname, lname AS ilname 
				FROM artists
			) AS i ON insp.inspired = i.iaid
		) AS tbl1 ON tbl1.luminary = l.aid 
		WHERE tbl1.inspired = [searchArtInput]
	) AS tbl2 GROUP BY ifname

--INSPIRATION FROM
	SELECT COUNT(laid) AS inspCount 
	FROM (
		SELECT aid AS laid, fname AS lfname, lname AS llname, relationship, iaid, ifname, ilname 
		FROM artists l 
		INNER JOIN (
			SELECT * FROM inspirations insp 
			INNER JOIN (
				SELECT aid AS iaid, fname AS ifname, lname AS ilname 
				FROM artists
			) AS i ON insp.inspired = i.iaid
		) AS tbl1 ON tbl1.luminary = l.aid 
		WHERE tbl1.inspired = [searchArtInput]
	) AS tbl2 GROUP BY ifname
