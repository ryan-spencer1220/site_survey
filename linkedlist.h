#pragma once
#include <cstring>
#include <fstream>
#include <iostream>

#include "node.h"
#include "sensordata.h"
using namespace std;

class LinkedList {
 private:
  Node* headBySector;
  Node* headByIron;
  Node* headBySilicon;
  int count;

 public:
  // constructors
  LinkedList();
  LinkedList(const LinkedList& linkedList);

  // destructor
  ~LinkedList();

  void operator=(const LinkedList& linkedList);

  // CRUD functions
  void addSensorData(SensorData* newData);
  void printListBySector();
  void printListByIron();
  void printListBySilicon();
  void printAverageBySector();
  bool containsSector(int sector);
  void printSectorList();
  void removeSector(int sector);

  // helper functions
  void addSectorData(Node* newNode);
  void addIronData(Node* newNode);
  void addSiliconData(Node* newNode);
  void removeSectorData(int sector);
  void removeIronData(int sector);
  void removeSiliconData(int sector);
};