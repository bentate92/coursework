#include <iostream>
#include <string>
using namespace std;

double toKiloms(double);

double toMiles(double);

int main() {
    string startUnit;
    double startVal;
    
    cout << "\nThis is a distance converter!" << endl;

    while (startUnit != "exit") {
        cout << "\nWould you like to start in miles or kilometers? " 
             << "('exit' to quit)" << endl;
        cin >> startUnit;
    
        if (startUnit == "exit") {
            cout << "\nOkay, goodbye!" << endl;
        }
        else {
            if (startUnit == "miles") {
                cout << "\nHow many miles?" << endl;
                cin >> startVal;
            
                cout << "\nThere are " << toKiloms(startVal) 
                     << " kilometers in " << startVal << " miles." << endl;
            }
            else if (startUnit == "kilometers") {
                cout << "\nHow many kilometers?" << endl;
                cin >> startVal;
                
                cout << "\nThere are " << toMiles(startVal) << " miles in " 
                     << startVal << " kilometers." << endl;
            }
        }
    }
    
    return 0;
}

double toKiloms(double miles) {
    double kiloms = miles * 1.609344;
    return kiloms;
}

double toMiles(double kiloms) {
    double miles = kiloms / 1.609344;
    return miles;
}