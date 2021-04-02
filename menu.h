#ifndef MENU_H
#define MENU_H

#include "constantes.h"
#include "tablero.h"
#include "jugador.h"

class Menu {
private:
    Tablero* tablero;
    Jugador* jugador1;
    Jugador* jugador2;
public:
    Menu();
    ~Menu();
    void iniciar();
    Jugador* crear_jugador();
    void jugar();
};

#endif // MENU_H