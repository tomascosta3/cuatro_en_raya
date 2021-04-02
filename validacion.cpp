#include "validacion.h"

Validacion::Validacion() { }

Validacion::~Validacion() { }

int Validacion::generar_entero_aleatorio(int minimo, int maximo){
    return rand() % (maximo - minimo + 1) + minimo;
}

string Validacion::pedir_dato(string mensaje){

    string dato;

    cout << "\n" << mensaje << " ";
    cin >> dato;

    return dato;
}

int Validacion::pedir_entero(string mensaje){

    string dato = pedir_dato(mensaje);

    while(!es_entero(dato)){
        dato = pedir_dato("Dato invalido, ingrese nuevamente:");
    }

    return stoi(dato);
}

bool Validacion::es_entero(string dato){

    unsigned i = 0;
    bool es_entero = true;

    while(es_entero && i < dato.length()){

        if(!isdigit(dato[i])){
            es_entero = false;
        }
        i++;
    }

    return es_entero;
}

int Validacion::pedir_entero_entre_rango(string mensaje, int minimo, int maximo){

    int dato = pedir_entero(mensaje);

    while(dato < minimo || dato > maximo){
        dato = pedir_entero("Dato invalido, ingrese nuevamente:");
    }

    return dato;
}

void Validacion::minuscula(string& palabra){
    int largo = palabra.length();
    for(int i = 0; i < largo; i++){
        palabra[i] = tolower(palabra[i]);
    }
}

void Validacion::primera_mayuscula(string& palabra){
    minuscula(palabra);
    if(palabra != ""){
        palabra[0] = toupper(palabra[0]);
    }
}
