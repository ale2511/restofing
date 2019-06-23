#ifndef REPARTIDOR_H
#define	REPARTIDOR_H

#include <string>
#include <cstdlib>
#include <iostream>
#include <map>
#include <set> 

#include "Empleado.h"
#include "Domicilio.h"
#include "tipoRepartidor.h"
#include "TipoDomicilio.h"
using namespace std; 

class Repartidor: public Empleado {
	private:
		TipoTransporte Transporte; 
		map <string, Domicilio*> domicilio;

public: 
	Repartidor(int, string, TipoTransporte);
	TipoTransporte getTransporte();
	map <string, Domicilio*> getDomicilio();
        set<TipoDomicilio*> getTipoDomicilio();
	void setTransporte(TipoTransporte);
    void setDomicilio(Domicilio *);
    void borrarDomicilio(Domicilio*);
};

#endif
