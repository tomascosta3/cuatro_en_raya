#ifndef VALIDACION_H
#define VALIDACION_H

#include <cstdlib>
#include <iostream>

using namespace std;

class Validacion {
public:
    // Constructor
    Validacion();

    // Destructor
    ~Validacion();

    // PRE: maximo >= minimo
    // POS: genera un numero aleatorio con minimo y maximo incluidos
    int generar_entero_aleatorio(int minimo, int maximo);

    // PRE: mensaje es lo que muestra el programa para que el usuario ingrese el dato que necesites
    // POS: devuelve valor ingresado por teclado
    string pedir_dato(string mensaje);

    // PRE: mensaje es lo que muestra el programa para que el usuario ingrese el dato que necesites
    // POS: devuelve valor entero
    int pedir_entero(string mensaje);

    // PRE: -
    // POS: si dato es entero devuelve true, si no false
    bool es_entero(string dato);

    // PRE: mensaje es lo que muestra el programa para que el usuario ingrese el dato que necesites
    // POS: devuelve un valor entero, entre minimo y maximo incluidos
    int pedir_entero_entre_rango(string mensaje, int minimo, int maximo);

    // PRE: palabra con letras solamente
    // POS: modifica todas las letras de la palabra a minuscula
    void minuscula(string& palabra);

    // PRE: palabra con solo letras
    // POS: modifica todas las letras de la palabra a minuscula y la primera a mayuscula
    void primera_mayuscula(string& palabra);
};

#endif // VALIDACION_H