#include "datalogger.h"

#include "linkedlist.h"

void DataLogger::addData(int sector, int iron, int silicon) {
  SensorData* newData = new SensorData(sector, iron, silicon);
  linkedList.addSensorData(newData);
}

bool DataLogger::containsSector(int sector) {
  return linkedList.containsSector(sector);
}

void DataLogger::removeSector(int sector) {}

void DataLogger::printReport() {
  cout << "--------------------------------------------------------------------"
          "--"
       << endl;
  cout << "Data Values" << endl;
  cout << "--------------------------------------------------------------------"
          "--"
       << endl;
  linkedList.printListBySector();
  linkedList.printListByIron();
  linkedList.printListBySilicon();
  cout << "--------------------------------------------------------------------"
          "--"
       << endl;
  cout << "Averages per sector" << endl;
  cout << "--------------------------------------------------------------------"
          "--"
       << endl;
  linkedList.printAverageBySector();
}

void DataLogger::printSectorList() { linkedList.printSectorList(); }