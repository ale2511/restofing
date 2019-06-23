#include <string>
#include <cstdlib>
#include <iostream>
#include <map>
#include <set> 

#include "Venta.h"
#include "Mesa.h"
#include "Local.h"
using namespace std;

Local :: Local(string cod) : Venta(cod) {
	map <int, Mesa *> mesas;
}

Local :: Local(string cod, int empl) : Venta(cod) {
		map <int, Mesa *> mesas;
                nroMozo = empl;
}


void Local :: setMesas(map <int, Mesa *> laMesa) {
	mesas = laMesa;
}

void Local :: agregar(int i, Mesa* m) {
	mesas[i] = m;
}

bool Local :: tieneMesa(int i) {
	Mesa* mesi = mesas[i];
	if (mesi != NULL){
		return true;
	} else {return false;}
}


set <int> Local :: numerosMesas() {
	set <int> result;
	map <int, Mesa *> :: iterator it;
	for (it = mesas.begin(); it != mesas.end(); ++it)
		result.insert(it->first);
	return result;
}

int Local :: getNroMozo(){

return nroMozo;
}
