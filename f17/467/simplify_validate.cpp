#include <string>
#include <algorithm>	//not in plan
#include <vector>
using namespace std;


//Function to simplify user command
//(will need to rework to incorporate Alan's classes)
string command(Game* g, string command) {
	enum noun_type {place, feature, item, none};
	string verb = "";
	string noun = "";
	noun_type nType;
	string outCmd = "";
	
	//Lists of accepted words
	vector<string> verb_list = {
		"look at", "inspect", "investigate", "examine", "study",
		"look", "look around",
		"go", "head", "exit to", "travel", "walk", "move",
		"take", "pick up", "grab", "acquire", "obtain", "get",
		"help",
		"inventory", "bag", "pouch",
		"savegame", "save",
		"loadgame", "load",
		"use",
		"drop", "place", "put", "set", "discard"
	};
	vector<string> place_list = {
		"north", "south", "east", "west", "l1 hall 1", "l1 hall 2", "warehouse", "chow hall", "pantry", 
		"med bay", "hangar bay", "elevator", "l2 hall 1", "l2 hall 2", "l2 hall 3", "sleeping quarters", "officer quarters 1", 
		"officer quarters 2", "officer quarters 3", "officer quarters 4", "officer quarters 5", "commander's quarters", 
		"l3 hall 1", "armory", "control room", "deck"
	};
	vector<string> feature_list = {
		"l1 map", "flashing red light", "warehouse kiosk", "toolbox", "kitchen appliances", 
		"prep table", "footprints", "fridge", "supply cabinet", "gauze", "generator", "ship", "bay doors", "dead", "buttons",
		"l2 map", "foot locker", "bed", "notebook", "vent cover", "photo", "journal", "book", "badge", "mirror", "makeup", "barbell",
		"tablet", "charging station", "desk", "safe", "soap", "l3 map", "bars", "control console", "window", "guns", "schematics"
		
	};
	vector<string> item_list = {
		"tubing", "elevator key", "commander's key", "warehouse code book", "navigation system", 
		"cleaver", "gun", "torch", "tank", "screwdriver"
	};

	//Convert command to all lowercase letters
	transform(command.begin(), command.end(), command.begin(), (int (*)(int))tolower);

	//Find verb
	for (vector<string>::iterator t = verb_list.begin(); t != verb_list.end(); ++t) {
		size_t found = command.find(*t);
		if (found != string::npos) {
			verb = *t;
			break;
		}
	}

	//Find feature
	for (vector<string>::iterator t = feature_list.begin(); t != feature_list.end(); ++t) {
		size_t found = command.find(*t);
		if (found != string::npos) {
			noun = *t;
			nType = feature;
			break;
		}
	}

	//Find place
	for (vector<string>::iterator t = place_list.begin(); t != place_list.end(); ++t) {
		size_t found = command.find(*t);
		if (found != string::npos) {
			noun = *t;
			nType = place;
			break;
		}
	}

	//Find item
	for (vector<string>::iterator t = item_list.begin(); t != item_list.end(); ++t) {
		size_t found = command.find(*t);
		if (found != string::npos) {
			noun = *t;
			nType = item;
			break;
		}
	}
	
	if (noun == "") {
		nType = none;
	}

	//Simplify verb aliases
	if (has_verb) {
		if (verb == "look around") {
			verb = "look";
		} else if (verb == "inspect" || verb == "investigate" || verb == "examine" || verb == "study") {
			verb = "look at";
		} else if (verb == "head" || verb == "exit to" || verb == "travel" || verb == "walk" || verb == "move") {
			verb = "go";
		} else if (verb == "pick up" || verb == "grab" || verb == "acquire" || verb == "obtain" || verb == "get") {
			verb = "take";
		} else if (verb == "bag" || verb == "pouch") {
			verb = "inventory";
		} else if (verb == "save") {
			verb = "savegame";
		} else if (verb == "load") {
			verb = "loadgame";
		} else if (verb == "place" || verb == "put" || verb == "set" || verb == "discard") {
			verb = "drop";
		}
	} 

	outCmd = validate(g, verb, noun, nType);

	return outCmd;
}

string validate(Game* game, string verb, string noun, string nType) {
	Room currRoom = game->currentRoom;
	vector<string> inventory = make_list(game, "inventory");
	vector<string> items = make_list(game, "items");
	vector<string> features = make_list(game, "features");
	vector<string> neighbors = make_list(game, "neighbors");

	if (verb == "look at") {
		if (nType == none) {
			return "INVAL:Please specify something to look at.";
		} else if (!is_in(currRoom.items, noun) && !is_in(currRoom.features, noun) && !is_in(currRoom.neighbors, noun) && !is_in(game->inventory, noun)) {
			return "INVAL:That isn't around right now.";
		} else {
			return verb + ":" + noun;
		}
	} else if (verb == "look") {
		return verb + ":NONE";
	} else if (verb == "go" || verb == "") {
		if (nType != place) {
			if (verb == "") {
				return "INVAL:No command recognized. Use the 'help' command for examples of acceptable commands.";
			} else {
				return "INVAL:You must specify somewhere you can go.";
			}
		} else if (!is_in(currRoom->neighbors, noun)) {
			return "INVAL:You can't get there from here.";
		} else { 
			return "go:" + noun;	
		}
	} else if (verb == "take") {
		if (nType == feature || nType == place) {
			return "INVAL:You can't take that with you.";
		} else if (nType == none) {
			return "INVAL: What do you want to pick up?";
		} else {
			if (is_in(game->inventory, noun)) {
				return "INVAL:You're already holding that.";
			} else if (!is_in(currRoom.items, noun)) {
				return "INVAL:That isn't around right now.";
			} else {
				return verb + ":" noun;
			}
		}
	} else if (verb == "drop") {
		if (nType == feature || nType == place) {
			return "INVAL:You can't drop something that you can't hold.";
		} else if (nType == none) {
			return "INVAL: What do you want to drop?";
		} else {
			if (!is_in(game->inventory, noun)) {
				return "INVAL:You can't drop something you aren't holding.";
			} else {
				return verb + ":" noun;
			}
		}
	} else if (verb == "use") {
		if (nType == feature || nType == place) {
			return "INVAL:You can't use that.";
		} else if (nType == none) {
			return "INVAL: What do you want to use?";
		} else {
			if (!is_in(game->inventory, noun)) {
				return "INVAL:You can't use something you aren't holding.";
			} else {
				return verb + ":" noun;
			}
		}
	} else if (verb == "inventory") {
		return verb + ":NONE";
	} else if (verb == "savegame") {
		return verb + ":NONE";
	} else if (verb == "loadgame") {
		return verb + ":NONE";
	} else if (verb == "help") {
		return verb + ":NONE";
	} else {
		return "INVAL:No command recognized. Use the 'help' command for examples of acceptable commands.";
	}
}

bool is_in(vector<string> list, string search) {
	if (find(list.begin(), list.end(), search) != list.end()) {
		return true;
	} else {
		return false;
	}
}

vector<string> make_list(Game* game, string type) {
	vector<string> list;
	
	if (type == "inventory") {
		vector<Object> inventory = game->inventoryList;
		
		for (int i = 0; i < inventory.size(); i++) {
			list.push_back(inventory->name);
		}
	} else if (type == "items") {
		vector<Object> items = game->currentRoom->objectsInRoom;
		
		for (int i = 0; i < items.size(); i++) {
			list.push_back(items->name);
		}
	} else if (type == "features") {
		vector<Object> features = game->currentRoom->features;
		
		for (int i = 0; i < features.size(); i++) {
			list.push_back(features->name);
		}
	} else if (type == "neighbors") {
		vector<Object> neighbors = game->currentRoom->doors;
		
		for (int i = 0; i < neighbors.size(); i++) {
			list.push_back(doors->name);
		}
	}
}
