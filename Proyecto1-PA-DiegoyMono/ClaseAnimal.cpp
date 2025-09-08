#include "ClaseAnimal.h"
#include <iostream>
#include <cstdlib> //para la generacion de numeros aleatorios

using namespace std;

Animal::Animal(int id, string tipo, int comida, double probNac, double probEnf, double precio) {
    //Asignacion de cada elemento local a su respectivo elemento en el contructor
    IDAnimal = id;
    tipoAnimal = tipo;
    unidades_comida = comida;
    probabilidad_nacimiento = probNac;
    probabilidad_enfermedad = probEnf;
    precioAnimal = precio;
    estadoNutricion = EstadoNutricion::Nutrido; //Instancia del enum, nutrido por default
    estadoSalud = EstadoSalud::Saludable; //Saludable por default
}

void Animal::Alimentar(int comida) {
    if (!estaVivo()) { //estaVivo es vivo por defualt por lo que su negacion es que esta muerto
        cout << "No se puede alimentar un animal muerto." << endl;
        return;
    }

    if (comida < unidades_comida) { //Si la comida administrada es menor a sus unidades de comida requeridas
        if (estadoNutricion == EstadoNutricion::Desnutrido) {
            estadoSalud = EstadoSalud::Fallecido;
            cout << "El animal murió por desnutrición." << endl;
        }
        else {
            estadoNutricion = EstadoNutricion::Desnutrido;
            cout << "El animal está desnutrido." << endl;
        }
    }
    else {
        estadoNutricion = EstadoNutricion::Nutrido;
        cout << "El animal fue alimentado correctamente." << endl;
    }
}

void Animal::Enfermar() {
    if (!estaVivo()) return; //Sino esta vivo el metodo no hace nada

    int prob = rand() % 10 + 1; //rand funciona con rangos pseudoaleatorios 0, 453, 12983, 32767, modulo 10 devuelve el residuo de la division entre 10 y le suma uno para que el rango de numeros aleatorios este en 1,2,3,4...
    if (prob <= probabilidad_enfermedad) { //Compara el numero random con la probabilidad verdadera de que se enferme
        estadoSalud = (rand() % 2 == 0) ? EstadoSalud::EnfermoLeve : EstadoSalud::EnfermoGrave; //Similarmente, devolvera un residuo de 0 o 1, y el operador ternario asigna respectivamente, operador ternario en lugar de if para ahorrar lineas
        cout << "El animal se enfermó (" << (estadoSalud == EstadoSalud::EnfermoLeve ? "leve" : "grave") << ")." << endl; //Como se manejan solo dos estados, sino es estado leve se aginara respectivamente a la salida correspondiente
    }
}

void Animal::TratarSuero() {
    if (estadoNutricion == EstadoNutricion::Desnutrido) {
        estadoNutricion = EstadoNutricion::Nutrido; //lo nutre si se trata con suero
        cout << "Tratamiento con suero aplicado." << endl;
    }
}

void Animal::TratarMedicina() {
    if (estadoSalud == EstadoSalud::EnfermoLeve || estadoSalud == EstadoSalud::EnfermoGrave) {
        estadoSalud = EstadoSalud::Saludable; //lo cura si se trata con medicina y esta enfermo
        cout << "El animal fue curado con medicina." << endl;
    }
}

void Animal::Vacunar() {
    if (probabilidad_enfermedad > 1) probabilidad_enfermedad--;
    cout << "El animal fue vacunado. Ahora tiene menor probabilidad de enfermar." << endl;
}
