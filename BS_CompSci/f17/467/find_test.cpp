#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	static const string arr[] = {"look at", "inspect", "investigate", "examine", "study",
		"look", "look around",
		"go", "head", "head to", "exit to", "go to", "travel", "walk", "walk to", "move", "move to",
		"take", "pick up", "grab", "acquire", "obtain", "get",
		"help",
		"inventory", "check inventory", "check bag", "check pouch",
		"savegame", "save",
		"loadgame", "load",
		"use",
		"drop", "place", "put", "put down", "set down", "set", "discard"};
	vector<string> verb_list (arr, arr+sizeof(arr) / sizeof(arr[0]));

	string natural = "would you just look at that?!!";

	string verb = "";

	for (vector<string>::iterator t = verb_list.begin(); t != verb_list.end(); ++t) {
		size_t found = natural.find(*t);
		if (found != string::npos) {
			verb = *t;
			break;
		}
	}

	cout << "verb = " << verb << endl;

	return 0;
}

