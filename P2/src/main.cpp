#include "../include/Board.h"
#include <chrono>
#include <thread>
#include <stdlib.h>

int main (void) {
  int filas;
  int columnas;
  int turnos;
  int numCelVivas;
  int coordX;
  int coordY;
  std::vector<std::pair<int, int> > vectorCelulasVivas;

  std::cout << "Introduzca el número de filas de la malla: ";
  std::cin >> filas;
  std::cout << std::endl;
  std::cout << "Introduzca el número de columnas de la malla: ";
  std::cin >> columnas;
  std::cout << std::endl;
  std::cout << "Introduzca el número de turnos que desea correr el programa: ";
  std::cin >> turnos;
  std::cout << std::endl;

  // Crea un objeto tablero con todas sus celulas inicializadas a muertas;
  Board tablero(filas, columnas);

  /* Solicita las posiciones de las células que deben estar en estado "viva"  
      en el turno 0 y actualiza el estado de dichas células */
  std::cout << "Introduzca cuántas células quiere cambiar a vivas: ";
  std::cin >> numCelVivas;
  std::cout << std::endl;
  for (int i = 0; i < numCelVivas; i++) {
    std::cout << "Introduzca las coordenadas de la " << i + 1 << " célula viva: ";
    std::cout << std::endl;
    std::cout << "Coordenada i: ";
    std::cin >> coordX;
    std::cout << "Coordenada j: ";
    std::cin >> coordY;
    vectorCelulasVivas.push_back(std::make_pair(coordX + 2, coordY + 2));
  }

  tablero.actualizar(vectorCelulasVivas);

  /* Muestra por pantalla el estado de la malla del tablero 
  std::cout << "La malla antes de empezar" << std::endl;
  tablero.write(std::cout); */

  /* Ejecuta un bucle donde cada iteración se corresponde a un turno en la 
      evolución de juego. En cada turno se actualiza y se muestra por pantalla
      el estado de la malla del tablero */
  for (int i = 0; i < turnos; i++) {
    tablero.actualizar();
    system("clear");
    std::cout << "La malla en el turno " << i + 1 << std::endl;
    tablero.write(std::cout);
    std::this_thread::sleep_for(std::chrono::milliseconds(200));
  }
}