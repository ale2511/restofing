#include <ctime>
#include <string>
#include <cstdlib>
#include <iostream>
#include <map>
#include <set>

#include "TipoFecha.h"
using namespace std;


TipoFecha :: TipoFecha(int d, int m, int a) {
	dia = d;
	mes = m;
	anio = a;
}

int TipoFecha :: getdia() {
	return dia;
}

int TipoFecha :: getmes() {
	return mes;
}

int TipoFecha :: getanio() {
	return anio;
}

