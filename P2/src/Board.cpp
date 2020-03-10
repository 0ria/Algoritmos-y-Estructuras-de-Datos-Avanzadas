#include "../include/Board.h"

Board::Board(/* args */) {

}

Board::~Board() {
}

Board::Board(int f, int c) : 
filas(f),
columnas(c),
mallaCelulas() {
  for (int i = 0; i < filas + 4; i++) {
    std::vector<Cell*> aux;
    for (int j = 0; j < columnas + 4; j++) {
      aux.push_back(new Cell);
    }
    mallaCelulas.push_back(aux);
  }

  for (int i = 2; i < filas + 2; i++)
    for (int j = 2; j < columnas + 2; j++)
      mallaCelulas[i][j] -> setPos(i, j);
}

void Board::actualizar(std::vector<std::pair<int, int> >& coordenadas) {
  for (auto coord : coordenadas) {
    mallaCelulas[coord.first][coord.second] -> setEstado(1);
  }
}

void Board::actualizar(void) {
  for (int i = 2; i < filas + 2; i++) {
    for (int j = 2; j < columnas + 2; j++) {
      mallaCelulas[i][j] -> contarVecinas(*this);
    }
  }
  for (int i = 2; i < filas + 2; i++) {
    for (int j = 2; j < columnas + 2; j++) {
      mallaCelulas[i][j] -> actualizarEstado();
    }
  }
}

void Board::write(std::ostream& os) {
  for (int i = 2; i < filas + 2; i++) {
    os << "|";
    for (int j = 2; j < columnas + 2; j++) {
      mallaCelulas[i][j] -> write(os);
      os << "|";
    }
    os << std::endl;
  }
}
/*
Cell* Board::operator[](int pos) {
  return mallaCelulas[pos];
}*/

std::vector<std::vector<Cell*> > Board::getMalla(void) const{
  return mallaCelulas;
}
