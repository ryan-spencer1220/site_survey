#include "datalogger.h"

#include "linkedlist.h"

void DataLogger::addData(int sector, int iron, int silicon) {
  linkedList.addSensorData(sector, iron, silicon);
}

bool DataLogger::containsSector(int sector) { return true; }

void DataLogger::removeSector(int sector) {}

void DataLogger::printReport() { linkedList.printListBySector(); }

void DataLogger::printSectorList() {}