#include <iostream>
#include <cstring>
#include "Datos.h"
#include "Ficha.h"
#include "Ficha_Numero.h"
#include "Ficha_Palabra.h"
#include "Principal.h"

using namespace std;

int main() {
    Datos datos;
    int cantidad = datos.devolver_cantidad();
    Ficha** fichas = new Ficha*[cantidad];
    

    for (int i = 0; i < cantidad; i++) {
        char* fichaStr = datos.devolver_fichas(i);
        char tipo = fichaStr[0];
        
        if (tipo == '1') {

            int valor;
            sscanf(fichaStr + 2, "%d", &valor);
            int valorNegro = (valor >> 3) & 31;
            int valorBlanco = (valor >> 11) & 31;
            fichas[i] = new Ficha_Numero(valorNegro, valorBlanco);
        } else if (tipo == '2') {

            char negro[20], blanco[20];
            int valor;
            sscanf(fichaStr, "2-%[^-]-%[^-]-%d", negro, blanco, &valor);
            int valorNegro = (valor >> 3) & 31;
            int valorBlanco = (valor >> 11) & 31;
            fichas[i] = new Ficha_Palabra(negro, blanco, valorNegro, valorBlanco);
        }
    }

    Principal principal;
    
    cout << "Fichas Numericas:" << endl;
    for (int i = 0; i < cantidad; i++) {
        if (dynamic_cast<Ficha_Numero*>(fichas[i])) {
            cout << i + 1 << ". ";
            fichas[i]->imprimir();
        }
    }
    
    cout << "Fichas de Palabras:" << endl;
    for (int i = 0; i < cantidad; i++) {
        if (dynamic_cast<Ficha_Palabra*>(fichas[i])) {
            cout << i + 1 << ". ";
            fichas[i]->imprimir();
        }
    }

    int resultado = principal.calcular_secuencia(fichas, cantidad, 1);
    if (resultado == 1) {
        cout << "Secuencia cerrada con fichas numericas." << endl;
    } else if (resultado == 2) {
        cout << "Secuencia abierta con fichas numericas." << endl;
    } else {
        cout << "Juego perdido con fichas numericas." << endl;
    }

    resultado = principal.calcular_secuencia(fichas, cantidad, 2);
    if (resultado == 1) {
        cout << "Secuencia cerrada con fichas de palabras." << endl;
    } else if (resultado == 2) {
        cout << "Secuencia abierta con fichas de palabras." << endl;
    } else {
        cout << "Juego perdido con fichas de palabras." << endl;
    }

    int N = 5;
    fichas[0]->imprimir(N, fichas);

    for (int i = 0; i < cantidad; i++) {
        delete fichas[i];
    }
    delete[] fichas;

    return 0;
}



