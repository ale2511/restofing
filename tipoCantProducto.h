#ifndef TIPOCANTPRODUCTO_H 
#define	TIPOCANTPRODUCTO_H

#include <string>
#include <cstdlib>
#include <iostream>
#include <map>
#include <set> 

#include "tipoMenu.h"
using namespace std;

class TipoCantProducto {
	private:
		int cant;
		TipoProducto * producto;
	public:
		//constructor
		TipoCantProducto(int, TipoProducto *);
		//getters
		TipoProducto * getTipoProducto();
		int getCant();
		//setters
		void setTipoProducto(TipoProducto *);
		void setCant(int);
		//destructor
		~TipoCantProducto(){};
};

#endif