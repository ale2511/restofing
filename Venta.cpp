#include <string>
#include <cstdlib>
#include <iostream>
#include <map>
#include <set> 

#include "CantProducto.h"
#include "Venta.h"
using namespace std;

Venta :: Venta(string cod) {
	codVenta = cod;
    map<string, CantProducto*> aux_prod;
	cp = aux_prod;

}

string Venta :: getCodVenta() {
	return codVenta;
}

void Venta :: agregarProducto(string cod, int i) {
	map <string, CantProducto *> :: iterator it;
	CantProducto* saco = cp[cod];
	if (saco != NULL) {
		saco->sum(i);
	} else {
		CantProducto * cprod = new CantProducto(i,cod);
		cp[cod] = cprod;
	}
}

set<string> Venta :: mostrarCodProds() {
	set <string> result;
	map <string, CantProducto *> :: iterator it;
	for (it = cp.begin(); it!= cp.end(); ++it) {
		string s = it->second->getCodProdGral();
		result.insert(s);
	}
	return result;
}

set<int> Venta :: mostrarCantProds() {
	set <int> result;
	map <string, CantProducto *> :: iterator it;
	for (it = cp.begin(); it!= cp.end(); ++it) {
		int s = it->second->getCant();
		result.insert(s);
	}
	return result;
}

void Venta :: bajarCp(string cod, int i) {

	CantProducto* nuevo = cp[cod];

	if (nuevo != NULL){
		int n = nuevo->getCant();
		if (n > i) {
			nuevo->setCant(n-i);
		} else {
			cp.erase(cod);
			nuevo->~CantProducto();
		}
	}


}

map <string, CantProducto *> Venta :: getMapCP() {
	return cp;
}