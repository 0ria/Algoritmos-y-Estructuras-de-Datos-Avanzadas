#pragma once
#include "../include/Cell.h"
#include <list>
#include <vector>
#include <ostream>

class Cell;
class Board
{
private:
  int filas;
  int columnas;
  std::vector<std::vector<Cell*> > mallaCelulas;
public:
  Board(/* args */);
  Board(int, int);
  ~Board();
  void write(std::ostream&);
  void actualizar(void);
  void actualizar(std::vector<std::pair<int, int> >&);
  Cell* operator[](int);
  std::vector<std::vector<Cell*> > getMalla(void) const;
};

