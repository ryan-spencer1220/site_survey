#pragma once

class SensorData {
 private:
  int sector;
  int iron;
  int silicon;

 public:
  // constructors
  SensorData();
  SensorData(int sector, int iron, int silicon);

  // accessor methods;
  int getSector();
  int getIron();
  int getSilicon();
};