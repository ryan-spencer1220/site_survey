#include "sensordata.h"

class LinkedList {
 private:
  struct Node {
    SensorData data;
    Node* nextBySector;
  };
  Node* headBySector;
  int count;

 public:
  // constructors
  LinkedList();
  LinkedList(LinkedList& linkedList);

  // destructor
  ~LinkedList();

  // assignment operator overloading
  void operator=(const LinkedList& linkedList);

  // add & print methods
  void addSensorData();
  void printListBySector();
};