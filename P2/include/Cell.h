#pragma once
#include "../include/Board.h"
#include <utility>
#include <iostream>
#include <ostream>

class Board;

class Cell
{
private:
  int alive;
  int vecinas;
  std::pair<int, int> pairPos;
  //int position;
public:
  Cell();
  ~Cell();
  int getEstado(void) const;
  void setEstado(int);
  void actualizarEstado(void);
  int contarVecinas(const Board&);
  void setVecinas(int);
  int getVecinas(void);
  std::ostream& write(std::ostream&);
  void setPos(int, int);
  std::pair<int, int> getPos(void);
  int sumVertical(const Board&);
  int sumHorizontal(const Board&);
  int sumDiagonal(const Board&);
  int sumTotal(const Board&);
  //inline void printCell();
};
