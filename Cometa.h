#pragma once
#include "Figura.h"
#include <string>
using namespace std;
class Cometa : public Figura {
private:
	int a;
	int b;
	int d;
	int D;

public:
	Cometa(int a, int b, int d, int D);
	void Dibujar() const override;
	int CalcularArea() const override;
	int CalcularPerimetro() const override;

};
