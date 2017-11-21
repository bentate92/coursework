
#include "Stack.hpp"
#include "Queue.hpp"
using namespace std;

int main() {
  int choice;
  int size;

  cout << "Would you like to make a Stack or a Queue? (enter 1 or 2)" << endl;
  cout << "1 - Stack" << endl;
  cout << "2 - Queue" << endl;
  cin >> choice;

  if(choice == 1) {
    cout << "How many integers would you like to have in the stack?" << endl;
    cin >> size;

    Stack stack(size);
  }
  else if(choice == 2) {
    cout << "How many integers would you like to have in the queue?" << endl;
    cin >> size;

    Queue queue(size);
  }
  else {
    cout << "You didn't enter 1 or 2!" << endl;
  }

  return 0;
}
