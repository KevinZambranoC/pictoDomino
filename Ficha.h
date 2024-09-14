#ifndef FICHA_H
#define FICHA_H

#include <iostream>

using namespace std;

class Ficha {
protected:
    int valorNegro;
    int valorBlanco;

public:
    Ficha() : valorNegro(0), valorBlanco(0) {}

    Ficha(int negro, int blanco) : valorNegro(negro), valorBlanco(blanco) {}

    void setValorNegro(int negro) { valorNegro = negro; }
    void setValorBlanco(int blanco) { valorBlanco = blanco; }
    int getValorNegro() { return valorNegro; }
    int getValorBlanco() { return valorBlanco; }

    virtual void imprimir() {
        cout << "Negro: " << valorNegro << ", Blanco: " << valorBlanco << endl;
    }

    int imprimir(bool ladoNegro) {
        return ladoNegro ? valorNegro : valorBlanco;
    }

    void imprimir(int N, Ficha** fichas) {
        int acumulado = 0;
        for (int i = 0; i < N; i++) {
            acumulado += fichas[i]->getValorNegro() + fichas[i]->getValorBlanco();
        }
        cout << "Valor acumulado de las primeras " << N << " fichas: " << acumulado << endl;
    }
};

#endif


