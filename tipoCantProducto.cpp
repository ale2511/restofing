#include <string>
#include <cstdlib>
#include <iostream>
#include <map>
#include <set> 

#include "tipoMenu.h"
#include "tipoCantProducto.h"
using namespace std;

TipoCantProducto :: TipoCantProducto(int miCant, TipoProducto * miProducto) {
	cant = miCant;
	producto = miProducto;
}

TipoProducto * TipoCantProducto :: getTipoProducto() {
	return producto;
}

int TipoCantProducto :: getCant() {
	return cant;
}

void TipoCantProducto :: setTipoProducto(TipoProducto * unProducto) {
	producto = unProducto;
}

void TipoCantProducto :: setCant(int unaCant) {
	cant = unaCant;
}