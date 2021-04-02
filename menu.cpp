#include "menu.h"

Menu::Menu() {
    tablero = new Tablero();
    jugador1 = nullptr;
    jugador2 = nullptr;
    validacion = new Validacion();
    color_ganador = "";
}

Menu::~Menu() {
    delete tablero;
    if(jugador1) {
        delete jugador1;
    }
    if(jugador2) {
        delete jugador2;
    }
    delete validacion;
}

void Menu::iniciar() {
    jugador1 = crear_jugador();
    jugador2 = crear_jugador();
    jugar();
    Jugador* ganador = obtener_ganador(tablero -> obtener_color_ganador());
    mostrar_ganador(ganador);
}

Jugador* Menu::crear_jugador() {
    string nombre, color;
    nombre = validacion -> pedir_dato("Ingrese nombre de jugador:");
    color = validacion -> pedir_dato("Ingrese color (A o R):");
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
        columna = validacion ->pedir_entero_entre_rango("Ingrese columna:", MIN_COLUMNA, MAX_COLUMNA);
        bool inserto = tablero -> insertar_ficha(jugador -> crear_ficha(), columna);
        while(!inserto) {
            columna = validacion ->pedir_entero_entre_rango("Columna llena, ingrese otra:", MIN_COLUMNA, MAX_COLUMNA);
            inserto = tablero -> insertar_ficha(jugador -> crear_ficha(), columna);
        }
        jugador = (jugador == jugador1 ? jugador2 : jugador1);
        termino = tablero -> hay_ganador();
    }
    tablero -> mostrar();
}

Jugador* Menu::obtener_ganador(string color) {
    Jugador* ganador = nullptr;
    if(jugador1 -> obtener_color() == color) {
        ganador = jugador1;
    }
    if(jugador2 -> obtener_color() == color) {
        ganador = jugador2;
    }
    return ganador;
}

void Menu::mostrar_ganador(Jugador* ganador) {
    if(!ganador) {
        cout << "\nEMPATE!" << endl << endl;
    }
    else {
        cout << "\nGANADOR: " << ganador -> obtener_nombre() << endl << endl;
    }
}