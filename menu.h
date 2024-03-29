#ifndef MENU_H 
#define	MENU_H

#include <string>
#include <cstdlib>
#include <iostream>
#include <map>
#include <set> 

#include "cantProdMenu.h"
using namespace std;

class Menu : public ProdGral {
	private:
		map <string, CantProdMenu *> cpm;
	public:
		//constructor
		Menu(string, string);
		//getter
		map <string, CantProdMenu *> getCPM();
		//setter
		void setCPM(map <string, CantProdMenu *>);
		//resto de operaciones
		void nuevoCantProdMenu(string, int, Simple *);
		TipoProducto * darDatosProd();
		void vaciadoMenu(Simple *);
		void reCalcularPrecio(CantProdMenu *);
		void elimMenu();
		//destructor
		~Menu(){};
};

#endif