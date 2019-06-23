#include <string>
#include <cstdlib>
#include <iostream>
#include <map>
#include <set>

#include "Mesa.h"
using namespace std; 

//-----------------constr
Mesa :: Mesa(int a) {
   activa = false;
   nroMesa = a;
}

//-----------------get

int Mesa :: DarMesa() {
	return nroMesa;
}

bool Mesa::Activa() {
	return activa;
}

//-----------------set

void Mesa :: setActiva(bool a) {
	activa = a;
}

void Mesa :: setDarMesa(int a) {
	nroMesa = a;
}

