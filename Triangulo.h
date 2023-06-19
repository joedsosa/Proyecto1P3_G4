#ifndef TRIANGULO_H
#define TRIANGULO_H

#include "Figura.h"

class Triangulo : public Figura {
private:
    int a;
    int b;
    int c;
    int h;

public:
    Triangulo(int a, int b, int c,int h);
    void Dibujar() const override;
    int CalcularArea() const override;
    int CalcularPerimetro() const override;
};

#endif