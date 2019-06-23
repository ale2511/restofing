#include <string>
#include <cstdlib>
#include <iostream>
#include <map>
#include <set> 

#include "TipoDireccionApart.h"
#include "tipocliente.h"
using namespace std;

TipoCliente :: TipoCliente(string tel, string name, TipoDireccion lugar, bool recibe){
	telefono = tel;
	nombre = name;
	direccion = lugar;
	recibeact = recibe;
}

string TipoCliente :: getTelefono(){
	return telefono;
}

string TipoCliente :: getNombre(){
	return nombre;
}

TipoDireccion TipoCliente :: getDireccion(){
	return direccion;
}

bool TipoCliente :: getRecibeactualizaciones(){
	return recibeact;
	
}

void TipoCliente :: setRecibeactualizaciones(bool recibe){
	recibeact = recibe;
}