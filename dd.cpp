
#include <string>
#include <cstdlib>
#include <iostream>
#include <map>
#include "TipoHora.h"

using namespace std;



int main (){

map<int, TipoHora*> hola;

cout << "tamaño: " << hola.size() << endl;

TipoHora* hori = new TipoHora(4,4,4);

hola[5] = hori;
cout << "tamaño: " << hola.size() << endl;

TipoHora* sacar = hola[5];

cout << sacar->getSegundos() << endl; 

TipoHora* razon = hola[10];

if (razon == NULL){

cout << "imprime NULL" << endl;
cout << "tamaño: " << hola.size() << endl;
}

TipoHora* razoon = hola[10];
if (razon != NULL){
cout << razoon->getSegundos() << endl;
}







return 0;
}
