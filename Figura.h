#ifndef FIGURA_H
#define FIGURA_H
class Figura {
public:
    virtual void Dibujar() const = 0;
    virtual int CalcularArea() const = 0;
    virtual int CalcularPerimetro() const = 0;
};

#endif