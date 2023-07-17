#include "node.h"

Node::Node() {
  this->data = SensorData();
  this->nextBySector = nullptr;
  this->nextByIron = nullptr;
  this->nextBySilicon = nullptr;
}

Node::Node(SensorData data) {
  this->data = data;
  this->nextBySector = nullptr;
  this->nextByIron = nullptr;
  this->nextBySilicon = nullptr;
}

void Node::operator=(const Node& node) {
  this->data = node.data;
  this->nextBySector = node.nextBySector;
  this->nextByIron = node.nextByIron;
  this->nextBySilicon = node.nextBySilicon;
}