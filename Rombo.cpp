#include "Rombo.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
Rombo::Rombo(int a,int d, int D) : a(a), d(d), D(D) {}
void Rombo::Dibujar() const {
    std::ifstream archivo("rombo.txt");

    if (!archivo) {
        std::cout << "Error al abrir el archivo del esquema.\n";
        return;
    }

    std::string linea;
    while (std::getline(archivo, linea)) {
        if (linea.find("[a={a}]") != std::string::npos) {
            linea.replace(linea.find("[a={a}]"), 7, "a =   " + std::to_string(a));
        }
        else if (linea.find("[d={d}]") != std::string::npos) {
            linea.replace(linea.find("[d={d}]"), 7, "d =   " + std::to_string(d));
        }
        else if (linea.find("[D={D}]") != std::string::npos) {
            linea.replace(linea.find("[D={D}]"), 7, "D =   " + std::to_string(D));
        }
        else if (linea.find("[b={b}]") != std::string::npos) {
            linea.replace(linea.find("[b={b}]"), 7, "b =   " + std::to_string(d));
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

int Rombo::CalcularArea() const {
    return 4 * a;
}

int Rombo::CalcularPerimetro() const {
    return (D * d) / 2;
}