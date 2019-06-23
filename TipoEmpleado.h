#ifndef _TIPOEMPLEADO_H
#define	_TIPOEMPLEADO_H

#include <string>
#include <cstdlib>
#include <iostream>
#include <map>
#include <set> 

using namespace std; 


class TipoEmpleado {
	private:
		int nroEmpleado;
		string Nombre;   
	public:
		TipoEmpleado(int, string);
		//----------geters
		int getnroEmpleado();
		string getNombre();
		//----------seters
		void setnroEmpleado(int);
		void setNombre(string);
		virtual ~TipoEmpleado() = default;
};

#endif