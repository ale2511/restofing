#ifndef VENTA_H 
#define	VENTA_H

#include <string>
#include <cstdlib>
#include <iostream>
#include <map>
#include <set> 

#include "CantProducto.h"
#include "tipoCantProducto.h"
using namespace std;

class Venta {
	private:
		string codVenta;
		map<string, CantProducto*> cp;
	public:
		//constructor
		Venta(string);
		//getter
		string getCodVenta();
		//setter
		//void setCodVenta(int);
		//operaciones
		void agregarProducto(string, int);
		set<string> mostrarCodProds();
		set<int> mostrarCantProds();
		void bajarCp(string, int);
		map<string, CantProducto*> getMapCP();

		//destructor
		virtual ~Venta() = default;
};

#endif
