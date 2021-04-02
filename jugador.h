#ifndef JUGADOR_H
#define JUGADOR_H

#include <string>
#include "ficha.h"
using namespace std;

class Jugador {
private:
    string nombre;
    string color;
public:
    Jugador(string nombre, string color);
    ~Jugador();
    string obtener_nombre();
    string obtener_color();
    void asignar_nombre(string nombre);
    void asignar_color(string nombre);
    Ficha* crear_ficha();
};

#endif // JUGADOR_H