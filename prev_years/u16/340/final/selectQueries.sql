--SEARCH POPULATE
	--If fnameInput,lnameInput IN artists:
		--Name, City, Country, Genre:
			SELECT fname, lname, city, country, genre
			FROM (
				SELECT * 
				FROM genres g
				INNER JOIN (
					SELECT aid, fname, lname, hometown, genre AS genreId
					FROM artists a
					WHERE a.fname=[fnameInput]
					AND a.lname=[lnameInput]
				) AS tbl1 ON tbl1.genreId = g.gid
				INNER JOIN (
					SELECT * 
					FROM hometowns
				) AS h ON h.hid = tbl1.hometown
			) AS tbl2
		--
		--Played [#] instruments:
			--Main:
				SELECT instrument, main
				FROM (
					SELECT * 
					FROM artists a
					INNER JOIN (
						SELECT * 
						FROM art_inst
					) AS ai ON ai.ai_aid = a.aid
					INNER JOIN (
						SELECT * 
						FROM instruments
					) AS i ON ai.ai_iid = i.iid
				) AS tbl
				WHERE tbl.fname = [fnameInput]
				AND tbl.lname = [lnameInput]
			--
			--Count:
				SELECT COUNT(instrument) AS instCount
				FROM (
					SELECT * 
					FROM artists a
					INNER JOIN (
						SELECT * 
						FROM art_inst
					) AS ai ON ai.ai_aid = a.aid
					INNER JOIN (
						SELECT * 
						FROM instruments
					) AS i ON ai.ai_iid = i.iid
				) AS tbl
				WHERE tbl.fname = [fnameInput]
				AND tbl.lname = [lnameInput]
				GROUP BY fname
			--
		--
		--Inspired [#] other artists:
			--Main:
				SELECT ifname, ilname
				FROM (
					SELECT aid AS laid, fname AS lfname, lname AS llname, relationship, iaid, ifname, ilname
					FROM artists l
					INNER JOIN (
						SELECT * 
						FROM inspirations insp
						INNER JOIN (
							SELECT aid AS iaid, fname AS ifname, lname AS ilname
							FROM artists
						) AS i ON insp.inspired = i.iaid
					) AS tbl1 ON tbl1.luminary = l.aid
				) AS tbl2
				WHERE tbl2.lfname = [fnameInput]
				AND tbl2.llname = [lnameInput]
			--
			--Count:
				SELECT COUNT(iaid) AS lumCount
				FROM (
					SELECT aid AS laid, fname AS lfname, lname AS llname, relationship, iaid, ifname, ilname
					FROM artists l
					INNER JOIN (
						SELECT * 
						FROM inspirations insp
						INNER JOIN (
							SELECT aid AS iaid, fname AS ifname, lname AS ilname
							FROM artists
						) AS i ON insp.inspired = i.iaid
					) AS tbl1 ON tbl1.luminary = l.aid
				) AS tbl2
				WHERE tbl2.lfname = [fnameInput]
				AND tbl2.llname = [lnameInput]
				GROUP BY lfname
			--
		--
		--Inspired by [#] of other artists:
			--Main:
				SELECT lfname, llname
				FROM (
					SELECT aid AS laid, fname AS lfname, lname AS llname, relationship, iaid, ifname, ilname
					FROM artists l
					INNER JOIN (
						SELECT * 
						FROM inspirations insp
						INNER JOIN (
							SELECT aid AS iaid, fname AS ifname, lname AS ilname
							FROM artists
						) AS i ON insp.inspired = i.iaid
					) AS tbl1 ON tbl1.luminary = l.aid
				) AS tbl2
				WHERE tbl2.ifname = [fnameInput]
				AND tbl2.ilname = [lnameInput]
			--
			--Count:
				SELECT COUNT(laid) AS inspCount
				FROM (
					SELECT aid AS laid, fname AS lfname, lname AS llname, relationship, iaid, ifname, ilname
					FROM artists l
					INNER JOIN (
						SELECT * 
						FROM inspirations insp
						INNER JOIN (
							SELECT aid AS iaid, fname AS ifname, lname AS ilname
							FROM artists
						) AS i ON insp.inspired = i.iaid
					) AS tbl1 ON tbl1.luminary = l.aid
				) AS tbl2
				WHERE tbl2.ifname = [fnameInput]
				AND tbl2.ilname = [lnameInput]
				GROUP BY ifname
			--
		--
	--
	--Else:
		"Artist not found please try a different name"
	--
--

--ARTIST POPULATE
SELECT fname,lname FROM artists ORDER BY fname,lname ASC

--GENRE POPULATE
SELECT genre FROM genres ORDER BY genre ASC

--HOMETOWN POPULATE
SELECT city,country,current_pop FROM hometowns ORDER BY country,city ASC

--INSTRUMENT POPULATE
SELECT instrument FROM instruments ORDER BY instrument ASC

--ART/INST POPULATE
SELECT fname,lname,instrument,main
FROM (
	SELECT *
	FROM artists a
	INNER JOIN(
		SELECT *
		FROM art_inst
	)AS ai ON ai.ai_aid=a.aid
	INNER JOIN(
		SELECT*
		FROM instruments
	)AS i ON ai.ai_iid=i.iid
)AS tbl

--INSPIRATION POPULATE
SELECT lfname, llname, ifname, ilname, relationship
FROM (
	SELECT aid AS laid, fname AS lfname, lname AS llname, relationship, iaid, ifname, ilname
	FROM artists l
	INNER JOIN (
		SELECT * 
		FROM inspirations insp
		INNER JOIN (
			SELECT aid AS iaid, fname AS ifname, lname AS ilname
			FROM artists
		) AS i ON insp.inspired = i.iaid
	) AS tbl1 ON tbl1.luminary = l.aid
) AS tbl2
