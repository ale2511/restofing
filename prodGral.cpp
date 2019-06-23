#include <string>
#include <cstdlib>
#include <iostream>
#include <map>
#include <set> 

#include "tipoMenu.h"
#include "prodGral.h"
using namespace std;

//constructor

ProdGral :: ProdGral(string miCod, string miDescripcion) {
	cod = miCod;
	descripcion = miDescripcion;
	precio = 0;
}

//getters

string ProdGral :: getCod() {
	return cod;
}

string ProdGral :: getDescripcion() {
	return descripcion;
}

float ProdGral :: getPrecio() {
	return precio;
}

//setters

void ProdGral :: setCod(string unCod) {
	cod = unCod;
}

void ProdGral :: setDescripcion(string unaDescripcion) {
	descripcion = unaDescripcion;
}

void ProdGral :: setPrecio(float unPrecio) {
	precio = unPrecio;
}