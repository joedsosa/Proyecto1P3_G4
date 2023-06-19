#pragma once
#include "Figura.h"
#include <string>
using namespace std;
class Cuadrado : public Figura {
private:
	int a;

public:
	Cuadrado(int a);
	void Dibujar() const override;
	int CalcularArea() const override;
	int CalcularPerimetro() const override;

};

