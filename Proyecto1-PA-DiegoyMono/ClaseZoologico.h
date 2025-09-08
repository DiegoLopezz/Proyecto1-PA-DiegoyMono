/*#include "pch.h"
#include <iostream>
#include <vector>
#include "Animal-Hijas.h"
#include "ClaseAnimal.h"
#include "EstructuraHabitat.h"

using namespace std;

class Zoologico {
	vector<Animal*> animales;
	vector<Habitat*> habitats;
	double ingreso_diario;

	public:
	void configurarHabitats(){}
	void asignarAnimales(){}
	void avanzarDia(){}
	void mostrarReporteAnimales(){}

};*/

#pragma once
#include <iostream>
#include <vector>
#include "EstructuraHabitat.h"

using namespace std;

class Zoologico {
    vector<Habitat> habitats;
    double ingresosTotales = 0;
    double gastosTotales = 0;

public:
    void configurarHabitats(int num);
    void asignarAnimal(Animal* animal, int habitatID);
    void alimentarAnimales();
    void aplicarTratamiento(int idAnimal, int opcion);
    void avanzarDia();
    void mostrarReporteAnimales() const;
};


