#ifndef LOCAL_H 
#define	LOCAL_H

#include <string>
#include <cstdlib>
#include <iostream>
#include <map>
#include <set> 

#include "Venta.h"
#include "Mesa.h"
using namespace std;

class Local : public Venta {
	private:
		map <int, Mesa *> mesas;
		int nroMozo;
	public:
		//constructor
		Local(string);
                Local(string, int);
		//getter
                int getNroMozo();
		//setter
		void setMesas(map <int, Mesa *>);
		//operaciones
		void agregar(int, Mesa*);
		bool tieneMesa(int);
		set<int> numerosMesas();
		//destructor
		~Local(){};
};

#endif
