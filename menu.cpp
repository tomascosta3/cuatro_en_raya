#include "menu.h"

Menu::Menu() {
    tablero = new Tablero();
    jugador1 = nullptr;
    jugador2 = nullptr;
}

Menu::~Menu() {
    delete tablero;
    if(jugador1) {
        delete jugador1;
    }
    if(jugador2) {
        delete jugador2;
    }
}

void Menu::iniciar() {
    jugador1 = crear_jugador();
    jugador2 = crear_jugador();
    jugar();
}

Jugador* Menu::crear_jugador() {
    string nombre, color;
    cout << "\nIngrese nombre de jugador 1: ";
    cin >> nombre;
    cout << "\nIngrese color (A o R): ";
    cin >> color;
    Jugador* jugador = new Jugador(nombre, color);
    return jugador;
}

void Menu::jugar() {
    bool termino = false;
    Jugador* jugador = jugador1;
    int columna;
    while(!termino) {
        tablero -> mostrar();
        cout << "\n\nTurno de " << jugador -> obtener_nombre() << endl;
        cout << "\nIngrese columna: ";
        cin >> columna;
        tablero -> insertar_ficha(jugador -> crear_ficha(), columna);
        jugador = (jugador == jugador1 ? jugador2 : jugador1);
        termino = tablero -> hay_ganador();
    }
    tablero -> mostrar();
}