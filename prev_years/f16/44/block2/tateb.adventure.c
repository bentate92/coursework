/*****************************************************************************************
* Name: Benjamin Tate
* Date: 10/27/2016
* Class: CS344
* Assignment: Prog2
* Description: Implementation of a simple text adventure that randomly creates rooms and
*	connections for the player to find their way through
******************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <sys/stat.h>

//Declaration of room struct to write files from
struct room {
	const char* name;
	const char* connections[6];
	const char* type;
	int countConns;
};

//Declaration of gameRoom struct to read from files
//	(uses literally defined strings for later type-compatibility)
struct gameRoom {
	char name[32];
	char connections[6][32];
	char type[32];
	int countConns;
};

//Function prototypes (see full declarations below for details)
void roomGen(const char**, const char**, int*);
int checkUnique(const char*, const char**, int);
void connTypeGen(struct room*, const char**); 
void fileGen(struct room*, char*);
void playGame(struct gameRoom*);
void copyStruct(struct gameRoom, struct gameRoom);

int main() {
	//Seed rand()
    srand((unsigned int)time(NULL));

	//Get process id and create string that holds the name of the directory
    int pid = getpid();
    char* prefix = "./tateb.rooms.";
    char* dirName = malloc(256);
    snprintf(dirName, 256, "%s%d", prefix, pid);

	//Create directory with permissions drwxr-xr-x to hold files
    struct stat st = {0};
    if(stat(dirName, &st) == -1) {
        mkdir(dirName, 0755);
    }

	//List of 10 possible room names
    const char* roomNames[] = {
        "kitchen",
        "garden",
        "study",
        "bedroom",
        "balcony",
        "bathroom",
        "basement",
        "laundry",
        "deck",
        "office",
    };
	
	//Create int numRooms to hold number of rooms that have been selected
	int numRooms = 0;
	//Create string array to hold selected room names
	const char* roomList[7];

	//Call roomGen() for each desired room
	//	(numRooms incremented in roomGen())
	while(numRooms < 7) {
		roomGen(roomNames, roomList, &numRooms);
    }

	//Create room struct array to hold rooms and assign names from roomList
	struct room rooms[7];
	int i;
	for(i = 0; i < numRooms; i++) {
		rooms[i].name = roomList[i];
	}

	//Call connTypeGen() to initialize each room's connections and type
	connTypeGen(rooms, roomList);

	//Call fileGen() to write a file from each room
	fileGen(rooms, dirName);

	//Create gameRoom struct array to hold rooms that are read back from files
	struct gameRoom gameRooms[7];
	for(i = 0; i < 7; i++) {
		//Initialize each gameRoom's connection count to 0
		gameRooms[i].countConns = 0;
	}

	//Loop through each of the 7 files and read info into appropriate element 
	//	of gameRooms array
	for(i = 0; i < 7; i++) {
		//Create and initialize string to hold file path
		char* thisFile = malloc(256);
		snprintf(thisFile, 256, "%s/%s.txt", dirName, roomList[i]);

		//Create file pointer and open file in read mode
		FILE* fp;
		fp = fopen(thisFile, "r");
	
		//Check that fopen succeeded and throw error if not
		if(fp == NULL) {
			fprintf(stderr, "Error: Cannot open %s\n", thisFile);
			fclose(fp);
			exit(1);
		}		

		//Loop through whole file
		while(!feof(fp)) {
			//Count lines based on ':' chars, as there is a colon on every line
			char ch = fgetc(fp);
			if(ch == ':') {
				//Increment current gameRoom's connection count
				gameRooms[i].countConns++;
			}
		}
		//Subtract 2 from connection count to account for room name and type lines
		gameRooms[i].countConns -= 2;
		//Initialize conns int as shortcut to countConns
		int conns = gameRooms[i].countConns;

		//Rewind to start of file
		rewind(fp);

		//Read name from file
		fscanf(fp, "ROOM NAME: %s\n", gameRooms[i].name);

		//Read first 3 connections from file
		fscanf(fp, "CONNECTION 1: %s\n", (gameRooms[i].connections)[0]);
		fscanf(fp, "CONNECTION 2: %s\n", (gameRooms[i].connections)[1]);
		fscanf(fp, "CONNECTION 3: %s\n", (gameRooms[i].connections)[2]);

		//For connections 4-6, only read if they exist
		if(conns >= 4) {
			fscanf(fp, "CONNECTION 4: %s\n", (gameRooms[i].connections)[3]);
		}
		if(conns >= 5) {
			fscanf(fp, "CONNECTION 5: %s\n", (gameRooms[i].connections)[4]);
		}
		if(conns == 6) {
			fscanf(fp, "CONNECTION 6: %s\n", (gameRooms[i].connections)[5]);
		}

		//Read type from file
		fscanf(fp, "ROOM TYPE: %s\n", gameRooms[i].type);

		//Close file
		fclose(fp);
	}

	//Call playGame()
	playGame(gameRooms);

	exit(0);
}

/*
 * Function: roomGen()
 * Description: Randomly selects a one of the 10 room names that isn't already
 *   in roomList
 * Parameters: String array of possible names, string array of names that have
 *   been selected, pointer to number of rooms that have been selected
 * Returns: Nothing
 * Variables altered: roomList, numRooms
 * Pre-Conditions: roomNames must be initialized with at least 10 strings. Any
 *   strings after 10 will be ignored.
 *   numRooms must be initialized with a valid integer.
 */
void roomGen(const char** roomNames, const char** roomList, int* numRooms) {
	//Set roomNum to random number from 0-9
	int roomNum = rand() % 10;

	//If this isn't the first room, call checkUnique and reset roomNum until
	//	unique room is found
	if(*numRooms > 0) {
		while(checkUnique(roomNames[roomNum], roomList, *numRooms) == 0) {
			roomNum = rand() % 10;
		}
	}

	//Create string to hold the selected roomName, and assign to next spot in
	//	roomList
	const char* thisRoom = roomNames[roomNum];
	roomList[*numRooms] = thisRoom;
	//Increment numRooms
	(*numRooms)++;
}

/*
 * Function: checkUnique()
 * Description: Checks if a given string is already in a string array
 * Parameters: String being tested, string array to test against, number of
 *   elements in array
 * Returns: 1 if string is not found in array, 0 if it is
 * Variables altered: None
 * Pre-Conditions: currRoom must be a valid string.
 *   roomList must contain at least 1 string.
 *   length must accurately describe number of elements in roomList.
 */
int checkUnique(const char* currRoom, const char** roomList, int length) {
	//Initialize unique to 1
	int unique = 1;

	//Loop through elements of roomList, update unique to 0 and return if
	//	currRoom is found
	int i;
	for(i = 0; i < length; i++) {
		if(strcmp(currRoom, roomList[i]) == 0) {
			unique = 0;

			return unique;
		}
	}

	//Return unique
	return unique;
}

/*
 * Function: connTypeGen()
 * Description: Randomly chooses number of connections and assigns them to each
 *   room, randomly chooses start and end rooms, and sets type of other rooms to
 *   mid
 * Parameters: Array of room structs, string array of names of rooms
 * Returns: Nothing
 * Variables altered: Elements of rooms
 * Pre-Conditions: rooms must be initialized with 7 elements, and each element
 *   must have a name that can be found in roomList
 *   roomList must contain 7 valid strings
 */
void connTypeGen(struct room* rooms, const char** roomList) {
	//Loop through rooms and set each room's connection count to 0
	int i;
	for(i = 0; i < 7; i++) {
		rooms[i].countConns = 0;
	}

	//Loop through rooms again
	for(i = 0; i < 7; i++) {
		//Initialize connCount as shortcut access to room's connection count
		int connCount = rooms[i].countConns;
		//Randomly set number of connections
		int numConns = rand() % 4 + 3;

		//Make sure numConns does not exceed number of free connections
		//	(connections will not be added backwards in the array, to 
		//	 make sure limit of 6 is not exceeded)
		while(8 - i + connCount < numConns) {
			numConns--;
		}


		//Loop until numConns is reached
		while(connCount < numConns) {
			//Select random index from 0-6
			int currConn = rand() % 7;

			//Reset currConn if selected room is not unique, or if the current room was selected
			while(checkUnique(roomList[currConn], rooms[i].connections, connCount) == 0 
				  || roomList[currConn] == rooms[i].name) {
				currConn = rand() % 7;
			}

			//Set current connection
			(rooms[i].connections)[connCount] = roomList[currConn];
			
			//Loop through rooms again to make new connection bilateral
			int j;
			for(j = 0; j < 7; j++) {
				//Find new connection and connect it back to current room
				if((rooms[i].connections)[connCount] == rooms[j].name) {
					(rooms[j].connections)[rooms[j].countConns] = rooms[i].name;
					//Increment connection's connection count
					rooms[j].countConns++;
				}
			}

			//Increment connCount and connection count
			rooms[i].countConns++;
			connCount++;
		}
	}

	//Randomly select index from 0-6 to be the start and end rooms
	int startIdx = rand() % 7;
	int endIdx = rand() % 7;
	//Make sure they aren't the same room
	while(endIdx == startIdx) {
		endIdx = rand() % 7;
	}

	//Loop through rooms and assign appropriate type
	for(i = 0; i < 7; i++) {
		if(i == startIdx) {
			rooms[i].type = "START_ROOM";
		} else if(i == endIdx) {
			rooms[i].type = "END_ROOM";
		} else {
			rooms[i].type = "MID_ROOM";
		}
	}
}

/*
 * Function: fileGen()
 * Description: Creates files for each of the room structs in rooms
 * Parameters: Array of room structs, string holding directory name
 * Returns: Nothing
 * Variables altered: None
 * Pre-Conditions: Directory dirName must exist.
 *   rooms array must contain 7 fully-initialized room structs
 *   room names should not include spaces
 */
void fileGen(struct room* rooms, char* dirName) {
	//Loop through rooms
	int i;
	for(i = 0; i < 7; i++) {
		//Create string to hold file path
		char* fileDest = malloc(256);
		snprintf(fileDest, 256, "%s/%s.txt", dirName, rooms[i].name);

		//Create file pointer and open file for creation mode
		FILE* f;
		f = fopen(fileDest, "w+");

		//Print room name
		fprintf(f, "ROOM NAME: %s\n", rooms[i].name);

		//Loop through connections and print each
		int j;
		for(j = 0; j < rooms[i].countConns; j++) {
			fprintf(f, "CONNECTION %d: %s\n", j + 1, (rooms[i].connections)[j]);
		}

		//Print room type
		fprintf(f, "ROOM TYPE: %s\n", rooms[i].type);

		//Close file
		fclose(f);
	}
}

/*
 * Function: playGame()
 * Description: Provides messages and prompts that make up the user interface
 *   of the game
 * Parameters: Array of gameRooms
 * Returns: Nothing
 * Variables altered: None
 * Pre-Conditions: gameRooms must be initialized with elements
 */
void playGame(struct gameRoom* gameRooms) {
	//Create gameRoom struct to keep track of current room
	struct gameRoom currRoom;
	//Create int to keep track of step count
	int steps = 0;
	//Create string to keep track of path taken
	char path[2048] = "\n";

	//Find start room by searching each gameRoom's type
	int i;
	for(i = 0; i < 7; i++) {
		if(strncmp(gameRooms[i].type, "START_ROOM", 32) == 0) {
			//When found, assign start room to currRoom and break loop
			currRoom = gameRooms[i];
			break;
		}
	}

	//Loop until end room is found
	while(strncmp(currRoom.type, "END_ROOM", 32) != 0) {
		//Print current location and label for possible connections
		printf("\nCURRENT LOCATION: %s\nPOSSIBLE CONNECTIONS: ", currRoom.name);

		//Loop through currRoom's connections and print
		for(i = 0; i < currRoom.countConns; i++) {
			//Use period and newline after last connection,
			//  and use comma and space after other connections
			if(i == currRoom.countConns - 1) {
				printf("%s.\n", (currRoom.connections)[i]);
			} else {
				printf("%s, ", (currRoom.connections)[i]);
			}
		}

		//Print prompt and accept reply
		printf("WHERE TO? >");
		char dest[128];
		scanf("%s", dest);

		//Declare int for validating input, initialize to 0
		int validInput = 0;

		//Loop through connections, compare dest to each connection
		for(i = 0; i < currRoom.countConns; i++) {
			//If connection is found...
			if(strncmp((currRoom.connections)[i], dest, 32) == 0) {
				//Compare dest to each gameRoom's name
				int j;
				for(j = 0; j < 7; j++) {
					//When selected gameRoom is found...
					if(strncmp(gameRooms[j].name, dest, 32) == 0) {
						//Update currRoom to selected gameRoom
						currRoom = gameRooms[j];
						//Set validInput to 1
						validInput = 1;
						//Update path with new gameRoom name and newline
						strcat(path, currRoom.name);
						strcat(path, "\n");
						//Increment steps and break
						steps++;
						break;
					}
				}
			} 
		}
		
		//If dest was not found (i.e. invalid) print error
		if(validInput == 0) {
			printf("\nHUH? I DON'T UNDERSTAND THAT ROOM. TRY AGAIN.\n");
		}
	}

	//Print victory message with step count and path taken
	printf("\nYOU HAVE FOUND THE END ROOM. CONGRATULATIONS!\n");
	if(steps > 1) {
		printf("YOU TOOK %d STEPS. YOUR PATH TO VICTORY WAS:%s", steps, path);
	} else {
		printf("YOU TOOK %d STEP. YOUR PATH TO VICTORY WAS:%s", steps, path);
	}
}
