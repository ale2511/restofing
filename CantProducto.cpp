#include <string>
#include <cstdlib>
#include <iostream>
#include <map>
#include <set> 

#include "tipoCantProducto.h"
#include "menu.h"
#include "CantProducto.h"
using namespace std;

CantProducto :: CantProducto(int miCant, string prod) {
	cant = miCant;
	producto = prod;
}

int CantProducto :: getCant() {
	return cant;
}

string CantProducto :: getCodProdGral() {
	return producto;
}

void CantProducto :: setCant(int unaCant) {
	cant = unaCant;
}

void CantProducto :: setProdGral(string produ) {
	producto = produ;
}

bool CantProducto :: contiene(string produ) {
	return producto == produ;
}

void CantProducto :: sum(int i) {
	int j = this->getCant();
	this->setCant(j+i);
}

/*TipoProducto * CantProducto :: getCodProd() {
	string p = this->getProdGral();
	ContrProducto * ctrl = ContrProducto :: getInstance();
	TipoProducto * tp = ctrl->//funcion que dado un string devuelva un TipoProducto
	return tp;
}*/

CantProducto :: ~CantProducto() {
}
