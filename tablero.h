#ifndef TABLERO_H
#define TABLERO_H

#include <string>
#include "constantes.h"
#include "jugador.h"
#include "ficha.h"
using namespace std;

class Tablero {
private:
    Ficha*** tablero;
    string color_ganador;
public:
    Tablero();
    ~Tablero();
    void mostrar();
    bool insertar_ficha(Ficha* ficha, int columna);
    bool hay_ganador();
    string obtener_color_ganador();
private:
    void inicializar();
    bool comprobar_ganador_filas();
    bool comprobar_ganador_columnas();
    bool comprobar_ganador_diagonal();
    bool comprobar_diagonal_superior();
    bool comprobar_diagonal_inferior();
    bool esta_lleno();
};

#endif // TABLERO_H