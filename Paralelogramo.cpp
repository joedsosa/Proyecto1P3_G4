#include "Paralelogramo.h"
#include "paralelogramo.h"
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

Paralelogramo::Paralelogramo(int a, int b, int h) : a(a), b(b), h(h) {}

void Paralelogramo::Dibujar() const {
    std::ifstream archivo("paralelogramo_02.txt");

    if (!archivo) {
        std::cout << "Error al abrir el archivo del esquema.\n";
        return;
    }

    std::string linea;
    while (std::getline(archivo, linea)) {
        if (linea.find("[h = {h}]") != std::string::npos) {
            linea.replace(linea.find("[h = {h}]"), 9, "    h = " + std::to_string(h));
        }
        else if (linea.find("[a = {a}]") != std::string::npos) {
            linea.replace(linea.find("[a = {a}]"), 9, "    a = "+ std::to_string(a));
        }
        else if (linea.find("[b = {b}]") != std::string::npos) {
            linea.replace(linea.find("[b = {b}]"), 9, "    b = " + std::to_string(b));
        }
        else if (linea.find("[{a}]+[{b}]") != std::string::npos) {
            linea.replace(linea.find("([{a}]+[{b}])"), 13,"( " +std::to_string(a)+" + "+std::to_string(b)+" )    ");
        }
        else if (linea.find("[{b*h}]") != std::string::npos) {
            linea.replace(linea.find("[{b*h}]"), 7, std::to_string(b * h));
        }
        else if (linea.find("([{a+b}])") != std::string::npos) {
            linea.replace(linea.find("([{a+b}])"), 9,"( "+std::to_string(a + b)+" )    ");
        }

        else if (linea.find("[{2*a+b}]") != std::string::npos) {
            linea.replace(linea.find("[{2*a+b}]"), 9, std::to_string(2 * (b + a))+"        ");
        }
        else if (linea.find("[{b}] * [{h}]") != std::string::npos) {
            linea.replace(linea.find("[{b}] * [{h}]"), 13,"    "+std::to_string(b) + " * " + to_string(h) + "    ");
        }
        
        cout << linea << endl;

    }

    archivo.close();
}

int Paralelogramo::CalcularArea() const {
    return b*h;
}

int Paralelogramo::CalcularPerimetro() const {
    return 2 * (b + a);
}