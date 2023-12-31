
#include "Triangulo.h"
#include <iostream>
#include <iomanip>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

Triangulo::Triangulo(int a, int b, int c, int h) : a(a), b(b), c(c), h(h) {}
void Triangulo::Dibujar() const {
    std::ifstream archivo("triangulo.txt");

    if (!archivo) {
        std::cout << "Error al abrir el archivo del esquema.\n";
        return;
    }

    std::string linea;
    while (std::getline(archivo, linea)) {
        if (linea.find("[a={a}]") != std::string::npos) {
            linea.replace(linea.find("[a={a}]"), 7, "a =   " + std::to_string(a));
        }
        else if (linea.find("[{a}]") != std::string::npos) {
            linea.replace(linea.find("[{a}]"), 5, std::to_string(a) + "    ");
        }
        else if (linea.find("[{4*a}]") != std::string::npos) {
            linea.replace(linea.find("[{4*a}]"), 7, std::to_string(4 * a) + "      ");
        }

        else if (linea.find("[{a}]^2") != std::string::npos) {
            linea.replace(linea.find("[{a}]^2"), 7, std::to_string(a) + "^2");
        }
        else if (linea.find("[{a^2}]") != std::string::npos) {
            linea.replace(linea.find("[{a^2}]"), 7, to_string(a * a));
        }

        cout << linea << endl;

    }

    archivo.close();
}


int Triangulo::CalcularArea() const {
    return (b * h) / 2;
}

int Triangulo::CalcularPerimetro() const {
    return a + b + c;
}