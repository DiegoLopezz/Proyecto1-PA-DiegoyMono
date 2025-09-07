#include <iostream>
#include "pch.h"
#include "ClaseAnimal.h"
#include "Animal-Hijas.h"

using namespace std;

string Ave::MostrarDescripcion() {
	cout << "Ingrese la descripcion del ave: " << endl;
	cin >> descripcionAve;

	return descripcionAve;
}

string Mamifero::MostrarDescripcion() {
	cout << "Ingrese la descripcion del mamifero: " << endl;
	cin >> descripcionMamifero;

	return descripcionMamifero;
}

string Reptil::MostrarDescripcion() {
	cout << "Ingrese la descripcion del reptil: " << endl;
	cin >> descripcionReptil;

	return descripcionReptil;
}

string Pez::MostrarDescripcion() {
	cout << "Ingrese la descripcion del pez: " << endl;
	cin >> descripcionPez;

	return descripcionPez;
}

string Anfibio::MostrarDescripcion() {
	cout << "Ingrese la descripcion del anfibio: " << endl;
	cin >> descripcionAnfibio;

	return descripcionAnfibio;
}