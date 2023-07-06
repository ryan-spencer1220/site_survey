#pragma once
#include <cstring>
#include <fstream>
#include <iostream>

#include "sensordata.h"
using namespace std;

class Node {
 public:
  SensorData data;
  Node* nextBySector;
  Node* nextByIron;
  Node* nextBySilicon;

  Node(SensorData data) {
    this->data = data;
    this->nextBySector = nullptr;
    this->nextByIron = nullptr;
    this->nextBySilicon = nullptr;
  }
};

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

  // destructors
  ~LinkedList();
  void operator=(const LinkedList& linkedList);

  // add & print functions
  void addSensorData(int sector, int iron, int silicon);
  void printListBySector();
};