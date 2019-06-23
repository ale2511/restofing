#ifndef CANTPRODMENU_H 
#define	CANTPRODMENU_H

#include <string>
#include <cstdlib>
#include <iostream>
#include <map>
#include <set> 

#include "simple.h"
using namespace std;

class CantProdMenu {
	private:
		int cant;
		Simple * simple;
	public:
		//constructor
		CantProdMenu(int, Simple *);
		//getters
		int getCant();
		Simple * getSimple();
		//setters
		void setCant(int);
		void setSimple(Simple *);
		//resto de operaciones
		bool contiene(Simple *);
		//destructor
		~CantProdMenu(){};
};

#endif