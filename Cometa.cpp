#include "Cometa.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
Cometa::Cometa(int a, int b, int d, int D ) : a(a), b(b), d(d), D(D) {}
void Cometa::Dibujar() const {
    std::ifstream archivo("cometa.txt");

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
            linea.replace(linea.find("[b={b}]"), 7, "b =   " + std::to_string(b));
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

        cout << linea<<endl;

    }

    archivo.close();
}

int Cometa::CalcularArea() const {
    return a * a;
}

int Cometa::CalcularPerimetro() const {
    return 4 * a;
}