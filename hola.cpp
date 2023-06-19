#include "Paralelogramo.h"
#include "Cuadrado.h"
#include <iostream>
#include <sstream>
#include <vector>
#include "Cometa.h"

void MostrarAyuda() {
    std::cout << "Calculos de per�metro y �rea de Figuras Planas.\n";
    std::cout << "Donde:\n";
    std::cout << "ACCION:\n";
    std::cout << "  ayuda             | Informaci�n sobre el uso del programa.\n";
    std::cout << "  triangulo a b c   | VARIABLES: a b c\n";
    std::cout << "  paralelogramo a h | VARIABLES: a h\n";
    // Agregar el resto de figuras aqu�
}

void RealizarCalculos(const std::string& opcion, const std::vector<int>& variables) {
    Paralelogramo* figura = nullptr;
    Cuadrado* figura1 = nullptr;
    Cometa* figura2 = nullptr;

    if (opcion == "triangulo" && variables.size() == 3) {
        // Realizar c�lculos para Tri�ngulo
        std::cout << "Tri�ngulo: No implementado" << std::endl;
    }
    else if (opcion == "paralelogramo" && variables.size() == 3) {
        figura = new Paralelogramo(variables[0], variables[1], variables[2]);
        figura->Dibujar();
        std::cout << "�rea: " << figura->CalcularArea() << std::endl;
        std::cout << "Per�metro: " << figura->CalcularPerimetro() << std::endl;
        delete figura;
    }
    else if (opcion == "cuadrado" && variables.size() == 1) {
        figura1 = new Cuadrado(variables[0]);
        figura1->Dibujar();
        cout << "Area: " << figura1->CalcularArea() << endl;
        std::cout << "Per�metro: " << figura1->CalcularPerimetro() << std::endl;
        delete figura1;
    }
    else if (opcion == "cometa" && variables.size() == 4) {
        figura2 = new Cometa(variables[0],variables[1],variables[2],variables[3]);
        figura2->Dibujar();
        cout << "Area: " << figura2->CalcularArea() << endl;
        std::cout << "Per�metro: " << figura2->CalcularPerimetro() << std::endl;
        delete figura2;
    }
    else {
        std::cout << "Opci�n inv�lida o faltan variables.\n";
        return;
    }
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        MostrarAyuda();
    }
    else {
        std::string opcion(argv[1]);
        std::vector<int> variables;

        for (int i = 2; i < argc; i++) {
            variables.push_back(std::stod(argv[i]));
        }

        RealizarCalculos(opcion, variables);
    }

    return 0;
}