#ifndef TIPOMENU_H 
#define	TIPOMENU_H

#include <string>
#include <cstdlib>
#include <iostream>
#include <map>
#include <set> 

#include "tipoCantProdMenu.h"
using namespace std;

class TipoMenu : public TipoProducto {
	private:
		set<TipoCantProdMenu *> prods;
	public:
		//constructor
		TipoMenu(string, string, float, set<TipoCantProdMenu *>);
		//getter
		set<TipoCantProdMenu *> getProds();
		//setter
		void setProds(set<TipoCantProdMenu *>);
		//destructor
		~TipoMenu();
};

                ostream& operator << (ostream &o, TipoMenu* &simple);

#endif
