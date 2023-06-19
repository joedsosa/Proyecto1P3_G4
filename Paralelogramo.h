#ifndef PARALELOGRAMO_H
#define PARALELOGRAMO_H

#include "Figura.h"

class Paralelogramo : public Figura {
private:
    int b;
    int a;
    int h;

public:
    Paralelogramo(int a, int b, int h);
    void Dibujar() const override;
    int CalcularArea() const override;
    int CalcularPerimetro() const override;
};

#endif