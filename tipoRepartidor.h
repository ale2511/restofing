#ifndef TIPOREPARTIDOR_H
#define	TIPOREPARTIDOR_H

#include <string>
#include <cstdlib>
#include <iostream>
#include <map>
#include <set> 
#include "TipoEmpleado.h"

using namespace std; 

enum TipoTransporte {Pie,Bicicleta,Moto};

class TipoRepartidor : public TipoEmpleado {
	private:
		TipoTransporte transporte; 
	public:
		TipoRepartidor(int, string, TipoTransporte);

		TipoTransporte getTransporte();


		void setTipoTransporte(TipoTransporte);
		
		~TipoRepartidor(){};
};


ostream& operator << (ostream &o, TipoRepartidor* &raparte);

#endif

