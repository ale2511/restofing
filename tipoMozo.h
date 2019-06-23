#ifndef TIPOMOZO_H
#define	TIPOMOZO_H

#include <string>
#include <cstdlib>
#include <iostream>
#include <map>
#include <set> 
#include "TipoEmpleado.h"
#include "tipoMesa.h"
using namespace std; 


class TipoMozo : public TipoEmpleado{

private:
    set <TipoMesa*> mesas;
public:
    TipoMozo(int, string, set <TipoMesa*>);
	set<TipoMesa*> getMesas();
	void SetMesas(TipoMesa*);
	~TipoMozo(){};
};

ostream& operator << (ostream &o, TipoMozo* &raparte);


#endif
