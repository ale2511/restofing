#include <string>
#include <cstdlib>
#include <iostream>
#include <map>
#include <set> 

#include "tipocliente.h"
#include "tipoactualizacion.h"
#include "Cliente.h"
using namespace std;

Cliente :: Cliente(string cel, string nom, TipoDireccion * lugar, bool recibe) : ObserverDomicilio(){
tel = cel;
nombre = nom;
direccion = lugar;
recibeActualizaciones = recibe;
set<TipoActualizacion *> sms;
mensajes = sms;

}

void Cliente :: setActualizaciones(bool recibe){
	recibeActualizaciones = recibe;
	
}

TipoDireccion * Cliente :: getDireccion(){
	return direccion;
}

string Cliente :: getTel(){
	return tel;
}

void Cliente :: actualizar(TipoActualizacion* actu){
	mensajes.insert(actu);
}

string Cliente :: getNombre(){
	return nombre;
}

set<TipoActualizacion*> Cliente :: getMensajes() {
	return mensajes;
}

bool Cliente :: getActualizaciones() {
	return recibeActualizaciones;
}