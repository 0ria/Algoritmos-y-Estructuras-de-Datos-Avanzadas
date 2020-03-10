#include "../include/Tablero.h"

Tablero::Tablero(int x, int y) :
rows(x),
columns(y) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      tablero[i][j] = ' ';
    }
  }
}

Tablero::~Tablero() {
}

void Tablero::printTablero(void) {
  for (int i = 0; i < rows; i++) {
    std::cout << "|"; 
    for (int j = 0; j < columns; j++) {
      std::cout << "|";
    }
    std::cout << std::endl;
}