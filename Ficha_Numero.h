#ifndef FICHA_NUMERO_H
#define FICHA_NUMERO_H

#include "Ficha.h"

class Ficha_Numero : public Ficha {
public:
    Ficha_Numero() : Ficha() {}

    Ficha_Numero(int negro, int blanco) : Ficha(negro, blanco) {}

    void imprimir() override {
        cout << "Ficha Numerica - Negro: " << valorNegro << ", Blanco: " << valorBlanco << endl;
    }
};

#endif

