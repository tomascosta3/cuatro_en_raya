#ifndef MENU_H
#define MENU_H

#include "constantes.h"
#include "tablero.h"
#include "jugador.h"
#include "validacion.h"

class Menu {
private:
    Tablero* tablero;
    Jugador* jugador1;
    Jugador* jugador2;
    Validacion* validacion;
    string color_ganador;
public:
    Menu();
    ~Menu();
    void iniciar();
    Jugador* crear_jugador();
    void jugar();
    Jugador* obtener_ganador(string color_ganador);
    void mostrar_ganador(Jugador* ganador);
};

#endif // MENU_H