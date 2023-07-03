#include "linkedlist.h"

#include <cstring>
#include <fstream>
#include <iostream>

using namespace std;

// constructor
LinkedList::LinkedList() {
  headBySector = NULL;
  count = 0;
}

// destructor
LinkedList::~LinkedList() {}

// assignment operator overloading
void LinkedList::operator=(const LinkedList& linkedList) {}

// add & print methods
void LinkedList::addSensorData(int sector, int iron, int silicon) {
  SensorData* newData = new SensorData(sector, iron, silicon);
  Node* newNode = new Node(*newData);
  if (count == 0) {
    headBySector = newNode;
  } else {
    Node* curr = headBySector;
    while (curr->nextBySector) {
      curr = curr->nextBySector;
    }
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