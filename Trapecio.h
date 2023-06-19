#pragma once
#include "Figura.h"
#include <string>
using namespace std;
class Trapecio: public Figura {
private:
	int a;
	int b;
	int B;
	int c;
	int h;

public:
	Trapecio(int a, int b, int B, int c,int h);
	void Dibujar() const override;
	int CalcularArea() const override;
	int CalcularPerimetro() const override;

};
