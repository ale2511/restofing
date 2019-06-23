#ifndef TIPODOMICILIO_H
#define TIPODOMICILIO_H

#include <string>
#include <cstdlib>
#include <iostream>
#include <map>
#include "TipoHora.h"

#include <set> 



//#include "Repartidor.h"
using namespace std;

class TipoDomicilio{
	private:
	string cliente_nombre;
        string cliente_cel;
        string cod_venta;
        string direc;
	TipoEstado estado;
	//int nroRepartidor;
	public:
       TipoDomicilio(string, string, string, string, TipoEstado);
	

	string getNombre();
	TipoEstado getEstado();
        string getDireccion();
	
	string getCelular();
        string getCodVenta();
//	Repartidor getFromRepartidor();
	~TipoDomicilio(){};
	
	
};

ostream& operator << (ostream &o, TipoEstado &raparte);

ostream& operator << (ostream &o, TipoDomicilio* &domicilio);

#endif
