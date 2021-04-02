#include "tablero.h"

Tablero::Tablero() {
    tablero = new Ficha**[ALTO];
    for(int i = 0; i < ALTO; i++) {
        tablero[i] = new Ficha*[ANCHO];
    }
    inicializar();
    color_ganador = "";
}

Tablero::~Tablero() {
    for(int i = 0; i < ALTO; i++) {
        for(int j = 0; j < ANCHO; j++) {
            if(tablero[i][j]) {
                delete tablero[i][j];
            }
        }
        delete [] tablero[i];
    }
    delete [] tablero;
}

void Tablero::inicializar() {
    for(int i = 0; i < ALTO; i++) {
        for(int j = 0; j < ANCHO; j++) {
            tablero[i][j] = nullptr;
        }
    }
}

void Tablero::mostrar() {
    cout << "\n   0   1   2   3   4   5   6" << endl;
    cout << " -----------------------------" << endl;
    for(int i = 0; i < ALTO; i++) {
        cout << " | ";
        for(int j = 0; j < ANCHO; j++) {
            if(!tablero[i][j]) {
                cout << VACIO;
            }
            else {
                cout << tablero[i][j] -> obtener_color();
            }
            cout << " | ";
        }
        cout << "\n -----------------------------" << endl;
    }
}

bool Tablero::insertar_ficha(Ficha* ficha, int columna) {
    bool inserto = false;
    int fila = ALTO - 1;
    while (!inserto && fila >= 0) {
        if(!tablero[fila][columna]) {
            tablero[fila][columna] = ficha;
            inserto = true;
        }
        fila--;
    }
    if(!inserto) {
        delete ficha;
    }
    return inserto;
}

bool Tablero::hay_ganador() {
    bool filas, columnas, diagonal, lleno;
    filas = comprobar_ganador_filas();
    columnas = comprobar_ganador_columnas();
    diagonal = comprobar_ganador_diagonal();
    lleno = esta_lleno();
    return filas || columnas || diagonal || lleno;
}

bool Tablero::esta_lleno() {
    bool lleno = true;
    for(int i = 0; i < ALTO; i++) {
        for(int j = 0; j < ANCHO; j++) {
            if(!tablero[i][j]) {
                lleno = false;
            }
        }
    }
    return lleno;
}

string Tablero::obtener_color_ganador() {
    return color_ganador;
}

bool Tablero::comprobar_ganador_filas() {
    bool hay_ganador = false;
    for(int f = 0; f < ALTO; f++) {
        int contador = 0;
        string color = VACIO;
        for(int c = 0; c < ANCHO; c++) {
            Ficha* ficha = tablero[f][c];
            if(ficha) {
                if(color != ficha -> obtener_color()) {
                    color = ficha -> obtener_color();
                    contador = 1;
                }
                else {
                    contador++;
                }
                if(contador >= MIN_FICHAS_EN_RAYA) {
                    hay_ganador = true;
                    color_ganador = ficha -> obtener_color();
                }
            }
        }
    }
    return hay_ganador;
}

bool Tablero::comprobar_ganador_columnas() {
    bool hay_ganador = false;
    for(int c = 0; c < ANCHO; c++) {
        int contador = 0;
        string color = VACIO;
        for(int f = 0; f < ALTO; f++) {
            Ficha* ficha = tablero[f][c];
            if(ficha) {
                if(color != ficha -> obtener_color()) {
                    color = ficha -> obtener_color();
                    contador = 1;
                }
                else {
                    contador++;
                }
                if(contador >= MIN_FICHAS_EN_RAYA) {
                    hay_ganador = true;
                    color_ganador = ficha -> obtener_color();
                }
            }
        }
    }
    return hay_ganador;
}

bool Tablero::comprobar_ganador_diagonal() {
    bool superior = comprobar_diagonal_superior();
    bool inferior = comprobar_diagonal_inferior();
    return superior || inferior;
}

bool Tablero::comprobar_diagonal_superior() {
    bool hay_ganador = false;
    // 3-0  2-1  1-2  0-3
    // 4-0  3-1  2-2  1-3  0-4
    // 5-0  4-1  3-2  2-3  1-4  0-5 
    for(int f = 3; f < 6; f++) {
        int contador = 0;
        string color = VACIO;
        for(int c = 0 ; c <= f ; c++) { 
            Ficha* ficha = tablero[f - c][c];
            if(ficha) {
                if(color != ficha -> obtener_color()) {
                    color = ficha -> obtener_color();
                    contador = 1;
                }
                else {
                    contador++;
                }
                if(contador >= MIN_FICHAS_EN_RAYA) {
                    hay_ganador = true;
                    color_ganador = ficha -> obtener_color();
                }
            }
        }
    }
    return hay_ganador;
}

bool Tablero::comprobar_diagonal_inferior() {
    bool hay_ganador = false;
    // 5-1  4-2  3-3  2-4  1-5  0-6
    // 5-2  4-3  3-4  2-5  1-6
    // 5-3  4-4  3-5  2-6
    for(int c = 1; c < 4; c++) {
        int contador = 0;
        string color = VACIO;
        for(int f = 5; f >= c - 1 ; f--) {
            Ficha* ficha = tablero[f][c + (ALTO - f - 1)];
            if(ficha) {
                if(color != ficha -> obtener_color()) {
                    color = ficha -> obtener_color();
                    contador = 1;
                }
                else {
                    contador++;
                }
                if(contador >= MIN_FICHAS_EN_RAYA) {
                    hay_ganador = true;
                    color_ganador = ficha -> obtener_color();
                }
            }
        }
    }
    return hay_ganador;
}