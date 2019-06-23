#ifndef DOMICILIO_H
#define DOMICILIO_H

#include <string>
#include <cstdlib>
#include <iostream>
#include <map>
#include <set> 

#include "Venta.h"
#include "Cliente.h"
using namespace std;

class Domicilio : public Venta {
	private:
	Cliente* cliente;
	TipoEstado estado;
	int nroRepartidor;
	set<ObserverDomicilio*> observers;
	void notificar(TipoActualizacion*);
	public:
	void AgregarObserver(ObserverDomicilio*);
	void EliminarObserver(ObserverDomicilio*);
	Domicilio(string, Cliente*);
	Cliente* getCliente();
	TipoEstado getEstado();
        string getNombreCliente();
        string getTelCliente();
        string getDireccion();
	void setEstado(TipoActualizacion*, TipoEstado);
	void setRepartidor(int);
	int getRepartidor();
//	Repartidor getFromRepartidor();
	~Domicilio(){};
	
	
};

#endif
