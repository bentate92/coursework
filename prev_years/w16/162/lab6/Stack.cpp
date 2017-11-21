
#include "Stack.hpp"
using namespace std;

Stack::Stack() {
  head = NULL;
}

Stack::Stack(int stackSize) {
  head = NULL;  

  int input;

  cout << "Please enter " << stackSize << " integers." << endl;

  for(int i = 0; i < stackSize; i++) {
    cin >> input;
    add(input);
  }

  cout << "\nStack created. Now we'll remove the integers, one at a time." << endl;
  
  for(int i = 0; i < stackSize; i++) {
    cout << remove() << endl;
  }
}

void Stack::add(int newest) {
  head = new StackNode(newest, head);

//  if(head == NULL) {
//    head = new StackNode(newest);
//  }
//  else {
//    StackNode *nodePtr = head;
//    
//    while(nodePtr->next != NULL) {
//      nodePtr = nodePtr->next;
//    }
//  
//    nodePtr->next = new StackNode(newest);
//  }
//  
//  head = nodePtr->next;
}

int Stack::remove() {
  StackNode *temp;

  int topNum;

  if(head == NULL) {
    cout << "The stack is empty!" << endl;
  } 
  else {
    topNum = head->nodeVal;
    temp = head;
    head = head->next;
    delete temp;
  }

  return topNum;
}
