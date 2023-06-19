#include "Paralelogramo.h"
#include "Cuadrado.h"
#include <iostream>
#include <sstream>
#include <vector>
#include "Cometa.h"
#include "Triangulo.h"
#include "Trapecio.h"
#include"Rombo.h"
using namespace std;
void MostrarAyuda() {
    std::cout << "Calculos de perímetro y área de Figuras Planas.\n";
    std::cout << "Donde:\n";
    std::cout << "       ACCION:\n";
    std::cout << "  ayuda             | Información sobre el uso del programa.\n";
    cout << endl;
    std::cout << "  triangulo         | VARIABLES: a b c\n";
    std::cout << "  paralelogramo     | VARIABLES: a h\n";
    std::cout << "  rectangulo        | VARIABLES: a b\n";
    std::cout << "  cuadrado          | VARIABLES: a \n";
    std::cout << "  rombo             | VARIABLES: a d D\n";
    std::cout << "  cometa            | VARIABLES: a b d D\n";
    std::cout << "  trapecio          | VARIABLES: a b c h B\n";
    std::cout << "  circulo           | VARIABLES: r\n";

    cout << endl;
    // Agregar el resto de figuras aquí
}

void RealizarCalculos(const std::string& opcion, const std::vector<int>& variables) {
    Paralelogramo* figura = nullptr;
    Cuadrado* figura1 = nullptr;
    Cometa* figura2 = nullptr;
    Triangulo* figura3 = nullptr;
    Rombo* figura4 = nullptr;
    Trapecio* figura5 = nullptr;

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
    else if (opcion == "triangulo" && variables.size() == 4) {
        figura3 = new Triangulo(variables[0], variables[1], variables[2], variables[3]);
        figura3->Dibujar();
        cout << "Area: " << figura3->CalcularArea() << endl;
        std::cout << "Perímetro: " << figura3->CalcularPerimetro() << std::endl;
        delete figura3;
    }
    else if (opcion == "rombo" && variables.size() == 4) {
        figura4 = new Rombo(variables[0], variables[1], variables[2]);
        figura4->Dibujar();
        cout << "Area: " << figura4->CalcularArea() << endl;
        std::cout << "Perímetro: " << figura4->CalcularPerimetro() << std::endl;
        delete figura4;
    }
    else if (opcion == "trapecio" && variables.size() == 4) {
        figura5 = new Trapecio(variables[0], variables[1], variables[2], variables[3], variables[4]);
        figura5->Dibujar();
        cout << "Area: " << figura5->CalcularArea() << endl;
        std::cout << "Perímetro: " << figura5->CalcularPerimetro() << std::endl;
        delete figura5;
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