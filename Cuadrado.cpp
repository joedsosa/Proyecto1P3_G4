#include "Cuadrado.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void Cuadrado::Dibujar() const {
    std::ifstream archivo("cuadrado.txt");

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
            linea.replace(linea.find("[{a}]"), 5, std::to_string(a)+"    ");
        }
        else if (linea.find("[{4*a}]") != std::string::npos) {
            linea.replace(linea.find("[{4*a}]"), 7, std::to_string(4*a)+"      ");
        }

        else if (linea.find("[{a}]^2") != std::string::npos) {
            linea.replace(linea.find("[{a}]^2"), 7, std::to_string(a) +"^2");
        }
        else if (linea.find("[{a^2}]") != std::string::npos) {
            linea.replace(linea.find("[{a^2}]"), 7,to_string(a*a));
        }

        cout << linea << endl;

    }

    archivo.close();
}
Cuadrado::Cuadrado(int a) : a(a) {}
int Cuadrado::CalcularArea() const {
    return a * a;
}

int Cuadrado::CalcularPerimetro() const {
    return 4 *a;
}