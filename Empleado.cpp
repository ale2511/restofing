#include <string>
#include <cstdlib>
#include <iostream>
#include <map>
#include <set> 

#include "Empleado.h"
using namespace std; 

Empleado :: Empleado (int nro, string name) {
	nroEmpleado = nro;
	Nombre = name;
}

int Empleado :: getnroEmpleado () {
	return nroEmpleado;
}

string Empleado :: getNombre() {
	return Nombre;
}

void Empleado :: setnroEmpleado (int a) {
	nroEmpleado = a;
}

void Empleado :: setNombre (string a) {
	Nombre = a;
}
