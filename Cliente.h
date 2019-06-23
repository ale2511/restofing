#ifndef CLIENTE_H
#define CLIENTE_H

#include <string>
#include <cstdlib>
#include <iostream>
#include <map>
#include <set> 

#include "tipocliente.h"
#include "tipoactualizacion.h"
#include "ObserverDomicilio.h"
using namespace std;

class Cliente : public ObserverDomicilio {
	private:
	string tel;
	string nombre;
	TipoDireccion * direccion;
	bool recibeActualizaciones;
        set<TipoActualizacion*> mensajes;
	public:
	Cliente(string, string, TipoDireccion *, bool);
	void setActualizaciones(bool);
	string getTel();
	string getNombre();
	TipoDireccion * getDireccion();
	set<TipoActualizacion*> getMensajes();
	bool getActualizaciones();
	void actualizar(TipoActualizacion*);
	
};

#endif 
