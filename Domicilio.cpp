#include <string>
#include <cstdlib>
#include <iostream>
#include <map>
#include <set> 

#include "Venta.h"
#include "Cliente.h"
#include "tipoactualizacion.h"
#include "Domicilio.h"
using namespace std;

Domicilio :: Domicilio(string codigo, Cliente* comprador) : Venta(codigo){
	cliente = comprador;
	estado = Pedido;
	nroRepartidor = -1;
	observers.insert(comprador);
	
}

void Domicilio :: notificar(TipoActualizacion* act){
	set<ObserverDomicilio*> :: iterator it;
	for (it = observers.begin(); it != observers.end(); ++it)
	{
		ObserverDomicilio* observer = *it;
		observer->actualizar(act);
	}
}


 void Domicilio :: AgregarObserver(ObserverDomicilio* nuevo){
 	observers.insert(nuevo);
 }

 void Domicilio :: EliminarObserver(ObserverDomicilio* sacar){
 	observers.erase(sacar);
 }



Cliente* Domicilio :: getCliente(){
	return cliente;
}



TipoEstado Domicilio :: getEstado(){
	return estado;
}

void Domicilio :: setEstado(TipoActualizacion* act, TipoEstado t) {
	estado = t;
	notificar(act);
	
	//notificar(nueva);

}

void Domicilio :: setRepartidor(int a) {
	nroRepartidor = a;
}

int Domicilio :: getRepartidor(){
	return nroRepartidor;
}

string Domicilio :: getNombreCliente(){
    string devolver;
    if (cliente != NULL){
    devolver = cliente->getNombre();

} else{ devolver = "No hay cliente asignado"; }
return devolver;

}

string Domicilio :: getTelCliente(){
 string devolver;
 if (cliente != NULL){
    devolver = cliente->getTel();

} else{ devolver = "No hay cliente asignado"; }

return devolver;


}

string Domicilio :: getDireccion(){
 string devolver;
 if (cliente != NULL){
    TipoDireccion* di = cliente->getDireccion();
    devolver = di->getCalle();

} else{ devolver = "No hay cliente asignado"; }

return devolver;


}
