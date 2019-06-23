#ifndef PRODGRAL_H 
#define	PRODGRAL_H

#include <string>
#include <cstdlib>
#include <iostream>
#include <map>
#include <set> 

#include "tipoMenu.h"
using namespace std;

class ProdGral {
	private:
		string cod;
		string descripcion;
		float precio;
	public:
		//constructor
		ProdGral(string, string);
		//getters
		string getCod();
		string getDescripcion();
		float getPrecio();
		//setters
		void setCod(string);
		void setDescripcion(string);
		void setPrecio(float);
		//resto de operaciones
		virtual TipoProducto * darDatosProd() = 0;
		//destructor
		~ProdGral(){};
};

#endif