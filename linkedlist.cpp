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
      addSensorData(&curr->data);
      curr = curr->nextBySector;
    }
  }
}

// add & print methods
void LinkedList::addSensorData(SensorData* newData) {
  Node* newNode = new Node(*newData);
  addSectorData(newNode);
  addIronData(newNode);
  addSiliconData(newNode);
  count++;
}

void LinkedList::addSectorData(Node* newNode) {
  if (count == 0) {
    headBySector = newNode;
  } else if (headBySector->data.getSector() > newNode->data.getSector()) {
    newNode->nextBySector = headBySector;
    headBySector = newNode;
  } else {
    Node* curr = headBySector;
    while (curr->nextBySector &&
           curr->nextBySector->data.getSector() < newNode->data.getSector()) {
      curr = curr->nextBySector;
    }
    newNode->nextBySector = curr->nextBySector;
    curr->nextBySector = newNode;
  }
}

void LinkedList::addIronData(Node* newNode) {
  if (count == 0) {
    headByIron = newNode;
  } else if (headByIron->data.getIron() > newNode->data.getIron()) {
    newNode->nextByIron = headByIron;
    headByIron = newNode;
  } else {
    Node* curr = headByIron;
    while (curr->nextByIron &&
           curr->nextByIron->data.getIron() < newNode->data.getIron()) {
      curr = curr->nextByIron;
    }
    newNode->nextByIron = curr->nextByIron;
    curr->nextByIron = newNode;
  }
}

void LinkedList::addSiliconData(Node* newNode) {
  if (count == 0) {
    headBySilicon = newNode;
  } else if (headBySilicon->data.getSilicon() > newNode->data.getSilicon()) {
    newNode->nextBySilicon = headBySilicon;
    headBySilicon = newNode;
  } else {
    Node* curr = headBySilicon;
    while (curr->nextBySilicon && curr->nextBySilicon->data.getSilicon() <
                                      newNode->data.getSilicon()) {
      curr = curr->nextBySilicon;
    }
    newNode->nextBySilicon = curr->nextBySilicon;
    curr->nextBySilicon = newNode;
  }
}

void LinkedList::printListBySector() {
  cout << "Data by Sector" << endl;
  Node* curr = headBySector;
  while (curr) {
    cout << "Sector: #" << curr->data.getSector() << " " << curr->data.getIron()
         << " grams iron, " << curr->data.getSilicon() << " milligrams silicon"
         << endl;
    curr = curr->nextBySector;
  }
}

void LinkedList::printListByIron() {
  Node* curr = headByIron;
  cout << "Data by Iron Level" << endl;
  while (curr) {
    cout << "Sector: #" << curr->data.getSector() << " " << curr->data.getIron()
         << " grams iron, " << curr->data.getSilicon() << " milligrams silicon"
         << endl;
    curr = curr->nextByIron;
  }
}

void LinkedList::printListBySilicon() {
  Node* curr = headBySilicon;
  cout << "Data by Silicon Level" << endl;
  while (curr) {
    cout << "Sector: #" << curr->data.getSector() << " " << curr->data.getIron()
         << " grams iron, " << curr->data.getSilicon() << " milligrams silicon"
         << endl;
    curr = curr->nextBySilicon;
  }
}

void LinkedList::printAverageBySector() {
  Node* curr = headBySector;
  int sector = 1;
  while (curr) {
    int iron = 0;
    int silicon = 0;
    int count = 0;
    while (curr && curr->data.getSector() == sector) {
      iron += curr->data.getIron();
      silicon += curr->data.getSilicon();
      count++;
      curr = curr->nextBySector;
    }
    if (iron || silicon) {
      cout << "Sector: #" << sector << " " << iron / count << " grams iron, "
           << silicon / count << " milligrams silicon" << endl;
    } else {
      cout << "Sector: #" << sector << "  -- no data --" << endl;
    }
    sector++;
  }
}

bool LinkedList::containsSector(int sector) {
  Node* curr = headBySector;
  while (curr) {
    if (curr->data.getSector() == sector) {
      return true;
    }
    curr = curr->nextBySector;
  }
  return false;
}

void LinkedList::printSectorList() {
  Node* curr = headBySector;
  while (curr) {
    cout << curr->data.getSector() << " ";
    curr = curr->nextBySector;
  }
}