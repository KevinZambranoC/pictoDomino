#ifndef PRINCIPAL_H
#define PRINCIPAL_H

#include "Ficha.h"
#include "Ficha_Numero.h"
#include "Ficha_Palabra.h"

class Principal {
public:
    int calcular_secuencia(Ficha** fichas, int cantidad, int tipo) {
        if (cantidad == 0) return 3;

        int inicio = -1;
        int fin = -1;
        bool secuenciaValida = true; 


        for (int i = 0; i < cantidad; i++) {
            if ((tipo == 1 && dynamic_cast<Ficha_Numero*>(fichas[i])) || 
                (tipo == 2 && dynamic_cast<Ficha_Palabra*>(fichas[i]))) {
                if (inicio == -1) {
                    inicio = fichas[i]->getValorNegro();
                    fin = fichas[i]->getValorBlanco();
                } else {

                    if (fin == fichas[i]->getValorNegro()) {
                        fin = fichas[i]->getValorBlanco();
                    } else if (inicio == fichas[i]->getValorBlanco()) {
                        inicio = fichas[i]->getValorNegro();
                    } else {
                        secuenciaValida = false;
                    }
                }
            }
        }


        if (secuenciaValida && inicio == fin) {
            return 1;
        }
        if (secuenciaValida) {
            return 2;
        }

        return 3;
    }

    void imprimir_fichas(Ficha** fichas, int cantidad, int tipo) {
        if (tipo == 1) {
            cout << "Fichas Numericas:" << endl;
            for (int i = 0; i < cantidad; i++) {
                if (dynamic_cast<Ficha_Numero*>(fichas[i])) {
                    cout << i + 1 << ". ";
                    fichas[i]->imprimir();
                }
            }
        } else if (tipo == 2) {
            cout << "Fichas de Palabras:" << endl;
            for (int i = 0; i < cantidad; i++) {
                if (dynamic_cast<Ficha_Palabra*>(fichas[i])) {
                    cout << i + 1 << ". ";
                    fichas[i]->imprimir();
                }
            }
        }
    }
};

#endif



