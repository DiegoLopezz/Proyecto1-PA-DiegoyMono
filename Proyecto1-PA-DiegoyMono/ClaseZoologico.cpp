#include "ClaseZoologico.h"
#include "ClaseAnimal.h"
#include <iostream>
using namespace std;

void Zoologico::configurarHabitats(int num) {
    string tipos[] = { "Aviario", "Acuario", "Laguna", "Bosque" }; //Arreglo con los 4 habitats posibles
    for (int i = 0; i < num; i++) {
        Habitat h; //Instancia de habitat temporal
        h.IDHabitat = i + 1; //Asigna cada habitat a un id unico i+1 para empezar desde 1
        h.tipoHabitat = tipos[rand() % 4]; //Se asigna de manera aleatoria segun el random de 4 posibilidades
        habitats.push_back(h); //Pushea el habitat al vector de habitats
    }
}

void Zoologico::asignarAnimal(Animal* animal, int habitatID) {
    for (auto& h : habitats) { //foreach que busca la direccion de memoria de h en vector habitats para trabajar directamente con el valor original, auto es una indicacion al compilador de que deduzca el tipo de variable a conveniencia, optimizado por chatGPT
        if (h.IDHabitat == habitatID) { //El id del habitat dentro del vector debe de ser igual al enviado como parametro
            h.animalesAsignados.push_back(animal);
            return;
        }
    }
    cout << "Habitat no encontrado." << endl;
}

void Zoologico::alimentarAnimales() {
    for (auto& h : habitats) {
        for (auto a : h.animalesAsignados) { //Dentro de cada habitat recorre cada animal a
            a->Alimentar(a->getID()); //LLama al metodo alimentar a-> porque son punteros 
            gastosTotales += 50; // cada unidad cuesta 50
        }
    }
}

void Zoologico::aplicarTratamiento(int idAnimal, int opcion) {
    for (auto& h : habitats) {
        for (auto a : h.animalesAsignados) {
            if (a->getID() == idAnimal) { //Valida la existencia de ese id del animal
                switch (opcion) {
                case 1: a->TratarSuero(); gastosTotales += 100; break;
                case 2: a->TratarMedicina(); gastosTotales += 250; break;
                case 3: a->Vacunar(); gastosTotales += 500; break;
                }
                return;
            }
        }
    }
}

void Zoologico::avanzarDia() {
    double ingresoDia = 0;
    for (auto& h : habitats) {
        for (auto a : h.animalesAsignados) {
            if (a->estaVivo()) {
                a->Enfermar(); //enfermar segun las probabilidades
                ingresoDia += 0.5 * a->getPrecio(); //al finalizar el dia, en este caso el bloque de codigo, le suma la mitad del precio original del animal como ganancia
            }
        }
    }
    ingresosTotales += ingresoDia; //a ingresos totales se le añadira el ingreso del dia constantemente
    cout << "Ingreso del dia: " << ingresoDia << endl;
}

void Zoologico::mostrarReporteAnimales() const {
    for (auto& h : habitats) {
        //Para cada habitat su informacion
        cout << "\nHabitat " << h.IDHabitat << " (" << h.tipoHabitat << "):" << endl;
        //para cada animal su informacion
        for (auto a : h.animalesAsignados) {
            cout << " - ID: " << a->getID()
                << " Tipo: " << a->getTipo()
                << " Precio: " << a->getPrecio()
                << " Estado: " << (a->estaVivo() ? "Vivo" : "Muerto") //Asigna el estado con el operador ternario
                << endl;
        }
    }
    cout << "\nIngresos totales: " << ingresosTotales << endl;
    cout << "Gastos totales: " << gastosTotales << endl;
}
