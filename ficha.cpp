#include "ficha.h"

Ficha::Ficha(string color) {
    this -> color = color;
}

Ficha::~Ficha() { }

string Ficha::obtener_color() {
    return color;
}

void Ficha::asignar_color(string color) {
    this -> color = color;
}