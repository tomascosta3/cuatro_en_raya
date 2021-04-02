#ifndef FICHA_H
#define FICHA_H

#include "constantes.h"

class Ficha {
private:
    string color;
public:
    Ficha(string color);
    ~Ficha();
    string obtener_color();
    void asignar_color(string color);
};

#endif // FICHA_H