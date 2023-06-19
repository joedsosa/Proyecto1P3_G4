
#include "Triangulo.h"
#include <iostream>
#include <iomanip>
#include <cmath>

Triangulo::Triangulo(int a, int b, int c) : ladoA(a), ladoB(b), ladoC(c) {}

void Triangulo::Dibujar() const {
    
}

int Triangulo::CalcularArea() const {
    int s = (ladoA + ladoB + ladoC) / 2.0;
    return std::sqrt(s * (s - ladoA) * (s - ladoB) * (s - ladoC));
}

int Triangulo::CalcularPerimetro() const {
    return ladoA + ladoB + ladoC;
}