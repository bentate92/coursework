--ARTISTS INSERT
	INSERT INTO artists (fname,lname,hometown,genre) 
	VALUES ([artFNameInput],[artLNameInput],[artHomeInput],[artGenInput])

--GENRE INSERT
	INSERT INTO genres (genre) VALUES ([genNameInput])

--HOMETOWN INSERT
	INSERT INTO hometowns (city,country,current_pop) 
	VALUES ([homeCityInput],[homeCountryInput],[currentPopInput])

--INSTRUMENT INSERT
	INSERT INTO instruments (instrument) VALUES ([instNameInput])

--ART/INST INSERT
	INSERT INTO art_inst (ai_aid,ai_iid,main) 
	VALUES ([artInstArtInput],[artInstInstInput],[artInstMainInput])

--INSPIRATION INSERT
	INSERT INTO inspirations (luminary,inspired,relationship)
	VALUES ([inspLumInput],[inspInspInput],[inspRelInput])
