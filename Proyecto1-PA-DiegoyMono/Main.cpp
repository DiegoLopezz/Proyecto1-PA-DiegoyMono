#include <iostream>
#include <string>
#include "ClaseAnimal.h"
#include "Animal-Hijas.h"
#include "ClaseZoologico.h"
#include "EstructuraHabitat.h"
using namespace std;

int cantidadAnimales(int numAnimales) { //pide al usuario que ingrese la cantidad de animales que desea crear
	cout << "Indique la cantidad de animales que desea crear: ";
	cin >> numAnimales;
    return numAnimales;
}
int cantidadHabitats(int numHabitats){ //pide al ususario que ingrese la cantidad de habitats que desea crear
    cout << "Indique la cantidad de habitats que desea crear: ";
    cin >>
}
void crearHabitatsRandom(int numHabitats, string tiposHabitat[], vector<string>& Habitats){ //crea habitats random, segun la cantidad que se desea crear
    int random;

    for(int i = 0; i < numHabitats; i++){
		random = 0 + rand() % 4;

        Habitats.push_back(tiposHabitat[random]);
    }
}
void cantidadDiasSimulacion(){

}

int main(){
    int numAnimales;
    int numHabitats;
    int numDias;
    int eleccion;
    string tiposAnimal[] = { "Ave", "Mamifero", "Reptil", "Pez", "Anfibio" };
    string tiposHabitat[] = { "Aviario", "Acuario", "Laguna", "Bosque" };

    
    return 0;
}
