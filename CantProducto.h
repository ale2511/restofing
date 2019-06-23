#ifndef CANTPRODUCTO_H 
#define	CANTPRODUCTO_H

#include <string>
#include <cstdlib>
#include <iostream>
#include <map>
#include <set>

#include "tipoCantProducto.h"
#include "menu.h"
using namespace std;

class CantProducto {
	private:
		int cant;
		string producto;
	public:
		//constructor
		CantProducto(int,string);
		//getters
		int getCant();
		string getCodProdGral();
		//setters
		void setCant(int);
		void setProdGral(string);
		//resto de operaciones
		bool contiene(string);
		void sum(int);
		//destructor
		~CantProducto();
};

#endif
