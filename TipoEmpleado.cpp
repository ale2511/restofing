#include <string>
#include <cstdlib>
#include <iostream>
#include <map>
#include <set> 

#include "TipoEmpleado.h"
using namespace std; 

TipoEmpleado :: TipoEmpleado (int nro, string name) {
	nroEmpleado = nro;
	Nombre = name;
}

int TipoEmpleado :: getnroEmpleado () {
	return nroEmpleado;
}

string TipoEmpleado :: getNombre() {
	return Nombre;
}

void TipoEmpleado :: setnroEmpleado (int a) {
	nroEmpleado = a;
}

void TipoEmpleado :: setNombre (string a) {
	Nombre = a;
}