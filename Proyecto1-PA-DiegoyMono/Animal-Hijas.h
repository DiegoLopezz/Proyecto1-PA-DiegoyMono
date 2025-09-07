#include <iostream>
#include "pch.h"
#include "ClaseAnimal.h"

using namespace std;

class Ave : public Animal {
protected:
	string descripcionAve;
public:
	string MostrarDescripcion() override {
		return "";
	}
};

class Mamifero : public Animal {
protected:
	string descripcionMamifero;
public:
	string MostrarDescripcion() override {
		return "";
	}
};

class Reptil : public Animal {
protected:
	string descripcionReptil;
public:
	string MostrarDescripcion() override {
		return "";
	}
};

class Pez : public Animal {
protected:
	string descripcionPez;
public:
	string MostrarDescripcion() override {
		return "";
	}
};

class Anfibio : public Animal {
protected:
	string descripcionAnfibio;
public:
	string MostrarDescripcion() override {
		return "";
	}
};

