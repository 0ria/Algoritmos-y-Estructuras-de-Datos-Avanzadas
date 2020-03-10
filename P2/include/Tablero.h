#pragma once
#include <iostream>
#include <vector>
class Tablero {
private:
  int rows;
  int columns;
  std::vector<std::vector<char> > tablero;
public:
  Tablero(int, int);
  ~Tablero();
  void printTablero(void);
};
