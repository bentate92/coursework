#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	string string = "HeLlO W0oooOrlD!!!\n";
	
	cout << "string = " << string;

	transform(string.begin(), string.end(), string.begin(), (int (*)(int))tolower);

	cout << "tolower'd = " << string;

	return 0;
}
