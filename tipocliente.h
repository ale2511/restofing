#ifndef TIPOCLIENTE_H
#define TIPOCLIENTE_H

#include <string>
#include <cstdlib>
#include <iostream>
#include <map>
#include <set> 

#include "TipoDireccionApart.h"
using namespace std;

class TipoCliente
{
private:
	string telefono;
	string nombre;
	TipoDireccion direccion;
    bool recibeact;

public:
    TipoCliente(string, string, TipoDireccion, bool);
	TipoCliente(){};
	string getTelefono();
	string getNombre();
	TipoDireccion getDireccion();
	bool getRecibeactualizaciones();
	void setRecibeactualizaciones(bool);
	
	
};

#endif