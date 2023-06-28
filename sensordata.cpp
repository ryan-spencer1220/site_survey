#include "sensordata.h"

SensorData::SensorData(int sector, int iron, int silicon) {
  this->sector = sector;
  this->iron = iron;
  this->silicon = silicon;
}

// accessor functions
int SensorData::getSector() { return sector; }

int SensorData::getIron() { return iron; }

int SensorData::getSilicon() { return silicon; }
