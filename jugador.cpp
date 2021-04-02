#include "jugador.h"

Jugador::Jugador(string nombre, string color) {
    this -> nombre = nombre;
    this -> color = color;
}

Jugador::~Jugador() { }

string Jugador::obtener_nombre() {
    return nombre;
}

string Jugador::obtener_color() {
    return color;
}

void Jugador::asignar_nombre(string nombre) {
    this -> nombre = nombre;
}

void Jugador::asignar_color(string color) {
    this -> color = color;
}

Ficha* Jugador::crear_ficha() {
    Ficha* ficha = new Ficha(color);
    return ficha;
}