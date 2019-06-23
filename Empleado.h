#ifndef _EMPLEADO_H
#define	_EMPLEADO_H

#include <string>
#include <cstdlib>
#include <iostream>
#include <map>
#include <set> 

using namespace std; 


class Empleado {
	private:
		int nroEmpleado;
		string Nombre;   
	public:
		Empleado(int, string);
		//----------geters
		int getnroEmpleado();
		string getNombre();
		//----------seters
		void setnroEmpleado(int);
		void setNombre(string);
};

#endif
