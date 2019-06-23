#ifndef TIPOCANTPRODMENU_H 
#define	TIPOCANTPRODMENU_H

#include <string>
#include <cstdlib>
#include <iostream>
#include <map>
#include <set> 

#include "tipoSimple.h"
using namespace std;

class TipoCantProdMenu {
	private:
		int cant;
		TipoSimple * tipoS;
	public:
		//constructor
		TipoCantProdMenu(int, TipoSimple *);
		//getters
		int getCant();
		TipoSimple * getTipoS();
		//setters
		void setCant(int);
		void setTipoS(TipoSimple *);
		//destructor
		~TipoCantProdMenu(){};
};

#endif