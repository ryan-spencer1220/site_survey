#include "linkedlist.h"

// constructor
LinkedList::LinkedList() {
  headBySector = NULL;
  headByIron = NULL;
  headBySilicon = NULL;
  count = 0;
}

// destructor
LinkedList::~LinkedList() {
  Node* curr = headBySector;
  while (curr) {
    Node* temp = curr;
    curr = curr->nextBySector;
    delete temp;
  }
  headBySector = NULL;
  headByIron = NULL;
  headBySilicon = NULL;
  count = 0;
}

// assignment operator overloading
void LinkedList::operator=(const LinkedList& linkedList) {
  if (this != &linkedList) {
    Node* curr = headBySector;
    while (curr) {
      Node* temp = curr;
      curr = curr->nextBySector;
      delete temp;
    }
    headBySector = NULL;
    headByIron = NULL;
    headBySilicon = NULL;
    count = 0;
    curr = linkedList.headBySector;
    while (curr) {
      addSensorData(curr->data.getSector(), curr->data.getIron(),
                    curr->data.getSilicon());
      curr = curr->nextBySector;
    }
  }
}

// add & print methods
void LinkedList::addSensorData(int sector, int iron, int silicon) {
  SensorData* newData = new SensorData(sector, iron, silicon);
  Node* newNode = new Node(*newData);
  if (count == 0) {
    headBySector = newNode;
  } else if (headBySector->data.getSector() > sector) {
    newNode->nextBySector = headBySector;
    headBySector = newNode;
  } else {
    Node* curr = headBySector;
    while (curr->nextBySector &&
           curr->nextBySector->data.getSector() < sector) {
      curr = curr->nextBySector;
    }
    newNode->nextBySector = curr->nextBySector;
    curr->nextBySector = newNode;
  }
  count++;
}

void LinkedList::printListBySector() {
  Node* curr = headBySector;
  while (curr) {
    cout << "Sector: #" << curr->data.getSector() << " " << curr->data.getIron()
         << " grams iron, " << curr->data.getSilicon() << " milligrams silicon"
         << endl;
    curr = curr->nextBySector;
  }
}