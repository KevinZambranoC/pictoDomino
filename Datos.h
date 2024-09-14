#ifndef DATOS_H
#define DATOS_H

#include <iostream>
#include <cstring>

using namespace std;

class Datos {
private:
    char* fichas_juego[14]; 

public:
    Datos() {
        fichas_juego[0] = "2-perro-tapa-171";
        fichas_juego[1] = "1-599";
        fichas_juego[2] = "1-1010";
        fichas_juego[3] = "2-mesa-perro-226";
        fichas_juego[4] = "2-tapa-morral-326";
        fichas_juego[5] = "2-gato-mesa-164";
        fichas_juego[6] = "1-746";
        fichas_juego[7] = "2-lapiz-gato-100";
        fichas_juego[8] = "1-335";
        fichas_juego[9] = "1-863";
        fichas_juego[10] = "2-baul-lapiz-111";
        fichas_juego[11] = "1-509";
        fichas_juego[12] = "1-950";
        fichas_juego[13] = "1-730";
    }

    char* devolver_fichas(int posicion) {
        return fichas_juego[posicion];
    }

    int devolver_cantidad() {
        return 14; 
    }
};

#endif

