#ifndef TIPOMOZOMESA_H
#define	TIPOMOZOMESA_H

#include <string>
#include <cstdlib>
#include <iostream>
#include <map>
#include <set> 

using namespace std; 


class TipoMesaMozo {
	private:
		int nroMozo; 
		int cantmesas;
	public:
		TipoMesaMozo(int, int);
		int getMozo();
		int getCantMesas();
		void setMozo(int);
		void setCantMesas(int);

};

                ostream& operator << (ostream &o, TipoMesaMozo* &mesa);

#endif
