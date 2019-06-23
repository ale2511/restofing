#include <string>
#include <cstdlib>
#include <iostream>
#include <map>
#include <set> 

#include "prodGral.h"
#include "simple.h"
using namespace std;

//constructor

Simple :: Simple(string miCod, string miDescripcion, float miPrecio) : ProdGral(miCod, miDescripcion) {
	setPrecio(miPrecio);
}

//resto de operaciones

TipoProducto * Simple :: darDatosProd() {
	TipoSimple * s = new TipoSimple(getCod(), getDescripcion(), getPrecio());
	return s;
}
