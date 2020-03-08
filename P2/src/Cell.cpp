#include "../include/Cell.h"

Cell::Cell(/* args */) :
alive(0),
vecinas(0) {

}

Cell::~Cell() {

}

void Cell::setEstado(int nextEstado) {
  alive = nextEstado;
}

std::ostream& Cell::write(std::ostream& os) {
  if (getEstado() == 1) {
    os << 'X';
    return os;
  }
  else {
    os << ' ';
    return os; 
  }
}

int Cell::getEstado(void) const{
  return alive;
}

void Cell::setPos(int i, int j) {
  pairPos = std::make_pair(i, j);
}

std::pair<int, int> Cell::getPos(void) {
  return pairPos;
}

void Cell::actualizarEstado(void) {
  if (vecinas == 3 && getEstado() == 0) {
    setEstado(1);
  }
  if ((vecinas != 2 || vecinas != 3) && getEstado() == 1) {
    setEstado(0);
  }
}

int Cell::contarVecinas(const Board& malla) {
  /*if (sumTotal(malla) == 3 && getEstado() == 0) {
    setEstado(1);
  }
  if ((sumTotal(malla) != 2 || sumTotal(malla) != 3) && getEstado() == 1) {
    setEstado(0);
  }*/
  vecinas = sumTotal(malla);
}

int Cell::sumVertical(const Board& malla) {
  return malla.getMalla()[getPos().first - 1][getPos().second] -> getEstado() + 
      malla.getMalla()[getPos().first + 1][getPos().second] -> getEstado();
}

int Cell::sumHorizontal(const Board& malla) {
  return malla.getMalla()[getPos().first][ getPos().second - 1] -> getEstado()
      + malla.getMalla()[getPos().first][getPos().second + 1] -> getEstado();
}

int Cell::sumDiagonal(const Board& malla) {
  return malla.getMalla()[getPos().first - 1][getPos().second - 1] -> getEstado() + 
      malla.getMalla()[getPos().first + 1][getPos().second + 1] -> getEstado() +
      malla.getMalla()[getPos().first + 1][getPos().second - 1] -> getEstado() + 
      malla.getMalla()[getPos().first - 1][getPos().second + 1] -> getEstado();
}

int Cell::sumTotal(const Board& malla) {
  return (sumDiagonal(malla) + sumHorizontal(malla) + sumVertical(malla));
}