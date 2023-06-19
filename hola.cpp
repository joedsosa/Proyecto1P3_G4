#include "Paralelogramo.h"
#include "Cuadrado.h"
#include <iostream>
#include <sstream>
#include <vector>
#include "Cometa.h"

void MostrarAyuda() {
    std::cout << "Calculos de perímetro y área de Figuras Planas.\n";
    std::cout << "Donde:\n";
    std::cout << "ACCION:\n";
    std::cout << "  ayuda             | Información sobre el uso del programa.\n";
    std::cout << "  triangulo a b c   | VARIABLES: a b c\n";
    std::cout << "  paralelogramo a h | VARIABLES: a h\n";
    // Agregar el resto de figuras aquí
}

void RealizarCalculos(const std::string& opcion, const std::vector<int>& variables) {
    Paralelogramo* figura = nullptr;
    Cuadrado* figura1 = nullptr;
    Cometa* figura2 = nullptr;

    if (opcion == "triangulo" && variables.size() == 3) {
        // Realizar cálculos para Triángulo
        std::cout << "Triángulo: No implementado" << std::endl;
    }
    else if (opcion == "paralelogramo" && variables.size() == 3) {
        figura = new Paralelogramo(variables[0], variables[1], variables[2]);
        figura->Dibujar();
        std::cout << "Área: " << figura->CalcularArea() << std::endl;
        std::cout << "Perímetro: " << figura->CalcularPerimetro() << std::endl;
        delete figura;
    }
    else if (opcion == "cuadrado" && variables.size() == 1) {
        figura1 = new Cuadrado(variables[0]);
        figura1->Dibujar();
        cout << "Area: " << figura1->CalcularArea() << endl;
        std::cout << "Perímetro: " << figura1->CalcularPerimetro() << std::endl;
        delete figura1;
    }
    else if (opcion == "cometa" && variables.size() == 4) {
        figura2 = new Cometa(variables[0],variables[1],variables[2],variables[3]);
        figura2->Dibujar();
        cout << "Area: " << figura2->CalcularArea() << endl;
        std::cout << "Perímetro: " << figura2->CalcularPerimetro() << std::endl;
        delete figura2;
    }
    else {
        std::cout << "Opción inválida o faltan variables.\n";
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