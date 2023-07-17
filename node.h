#include "sensordata.h"

class Node {
 public:
  SensorData data;
  Node* nextBySector;
  Node* nextByIron;
  Node* nextBySilicon;

  Node();
  Node(SensorData data);
  void operator=(const Node& node);
};