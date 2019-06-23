#include <string>
#include <cstdlib>
#include <iostream>
#include <map>
#include <set> 

#include "tipoProducto.h"
using namespace std;

//constructor

TipoProducto :: TipoProducto(string miCod, string miDescripcion, float miPrecio) {
	cod = miCod;
	descripcion = miDescripcion;
	precio = miPrecio;
}

//getters

string TipoProducto :: getCod() {
	return cod;
}

string TipoProducto :: getDescripcion() {
	return descripcion;
}

float TipoProducto :: getPrecio() {
	return precio;
}

//setters

void TipoProducto :: setCod(string unCod) {
	cod = unCod;
}

void TipoProducto :: setDescripcion(string unaDescripcion) {
	descripcion = unaDescripcion;
}

void TipoProducto :: setPrecio(float unPrecio) {
	precio = unPrecio;
}