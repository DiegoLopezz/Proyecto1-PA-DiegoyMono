#include <iostream>
#include "pch.h"

using namespace std;

class Animal {
protected:
	int IDAnimal;
	string tipoAnimal;
	int unidades_comida;
	double probabilidad_nacimiento;
	double probabilidad_enfermedad;
	double precioAnimal;
	bool estado_nutricion = true; //true -> nutrido, false -> desnutrido
	bool estado_salud = true; //true -> sano, false -> enfermo
	bool vida = true; //Vivo o muerto
public:
	Animal (){} //Llenar con parametros despues
	virtual string MostrarDescripcion() = 0 {}
	int Alimentar() { return 0; }
	int Enfermar() { return 0; } //Determina si el animal se enferma, recibe tratamiento y que clase de tratamiento
};
