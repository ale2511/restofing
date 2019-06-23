#ifndef MESA_H
#define	MESA_H

#include <string>
#include <cstdlib>
#include <iostream>
#include <map>
#include <set>

using namespace std; 



class Mesa {
	private:
		int nroMesa;
		bool activa;
	public:
		//-----------------constr
		Mesa(int);
		//-----------------get
		int  DarMesa();
		bool Activa();
		//-----------------set
		void setActiva(bool);
		void setDarMesa(int);  
};


#endif
