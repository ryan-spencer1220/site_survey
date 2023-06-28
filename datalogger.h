#include "linkedlist.h"

class DataLogger {
 private:
  LinkedList linkedList;

 public:
  void addData(int sector, int iron, int silicon);

  bool containsSector(int sector);

  void removeSector(int sector);

  void printReport();

  void printSectorList();
};