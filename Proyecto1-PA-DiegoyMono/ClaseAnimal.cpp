#include <iostream>
#include "pch.h"
#include "ClaseAnimal.h"

using namespace std;


int Animal:: Alimentar() {
	int ctdComida;
	cout << "Ingrese la cantidad de comida que desea suministrar al animal: " << endl;
	cin >> ctdComida;

	if (vida == true) {
		if (estado_nutricion == false) {
			//Llamada a AplicarTratamientoSuero
		}
		else {
			//Actualizar el estado de nutricion
		}
	}
	else {
		cout << "No se puede alimentar un animal fallecido." << endl;
	}

	return 0;
}

int Animal::Enfermar() {
	if (vida == true) {
		if (estado_salud == false) {
			//AplicarTratamientoMedico
		}
		else {
			cout << "El animal esta sano." << endl;
		}
	}
	else {
		cout << "No se puede curar un animal fallecido." << endl;
	}

	return 0;
}