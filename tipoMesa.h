#ifndef TIPOMESA_H
#define	TIPOMESA_H

#include <string>
#include <cstdlib>
#include <iostream>
#include <map>
#include <set>

#include "tipoMesaMozo.h"
using namespace std; 

class TipoMesa{
	private:
		int nroMesa;
		bool activa;
	public:
		//-----------------constr
		TipoMesa(int, bool);
                TipoMesa(int);
		//-----------------get
		int DarMesa();
		bool Activa();
		//-----------------set
		void setActiva(bool);
		void setDarMesa(int);  
};

                ostream& operator << (ostream &o, TipoMesa* &mesa);

#endif
