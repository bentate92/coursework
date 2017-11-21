
#include "Queue.hpp"
using namespace std;

Queue::Queue() {
  front = NULL;
  back = NULL;
}

Queue::Queue(int queueSize) { 
  front = NULL;
  back = NULL;

  int input;

  cout << "Please enter " << queueSize << " integers." << endl;

  for(int i = 0; i < queueSize; i++) {
    cin >> input;
    add(input);
  }

  cout << "Queue created. Now we'll remove the integers, one at a time." << endl;

  for(int i = 0; i < queueSize; i++) {
    cout << remove() << endl;
  }
}

//Queue::~Queue() {
//  
//}

void Queue::add(int newest){
  if(front == NULL) {
    front = new QueueNode(newest);
    back = front;
  }
  else {
    back->next = new QueueNode(newest);
    back = back->next;
  }
}

int Queue::remove(){
  QueueNode *temp;

  int frontNum;

  if(front == NULL) {
    cout << "The queue is empty!" << endl;
  }
  else {
    frontNum = front->nodeVal;
    temp = front;
    front = front->next;
    delete temp;
  }

  return frontNum;
}
