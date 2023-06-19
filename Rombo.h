#pragma once
#include "Figura.h"
#include <string>
using namespace std;
class Rombo: public Figura {
private:
	int a;
	int d;
	int D;

public:
	Rombo(int a, int d, int D);
	void Dibujar() const override;
	int CalcularArea() const override;
	int CalcularPerimetro() const override;

};
