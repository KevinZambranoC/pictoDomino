#ifndef FICHA_PALABRA_H
#define FICHA_PALABRA_H

#include "Ficha.h"
#include <cstring>

class Ficha_Palabra : public Ficha {
private:
    char palabraNegro[40];
    char palabraBlanco[40];

public:
    Ficha_Palabra() : Ficha() {
        strcpy(palabraNegro, "");
        strcpy(palabraBlanco, "");
    }

    Ficha_Palabra(const char* negro, const char* blanco, int valorNegro, int valorBlanco) 
    : Ficha(valorNegro, valorBlanco) {
        strcpy(palabraNegro, negro);
        strcpy(palabraBlanco, blanco);
    }

    void setPalabraNegro(const char* negro) { strcpy(palabraNegro, negro); }
    void setPalabraBlanco(const char* blanco) { strcpy(palabraBlanco, blanco); }
    const char* getPalabraNegro() { return palabraNegro; }
    const char* getPalabraBlanco() { return palabraBlanco; }

    void imprimir() override {
        cout << "Ficha de Palabra - Negro: " << palabraNegro << ", Blanco: " << palabraBlanco;
        cout << " (Valores - Negro: " << valorNegro << ", Blanco: " << valorBlanco << ")" << endl;
    }
};

#endif

