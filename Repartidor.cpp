#include <string>
#include <cstdlib>
#include <iostream>
#include <map>
#include <set> 

#include "Empleado.h"
#include "tipoRepartidor.h"
#include "Domicilio.h"
#include "Repartidor.h"


using namespace std;


Repartidor::Repartidor(int nro, string name, TipoTransporte trans) : Empleado(nro, name){
   Transporte = trans;
   map <string, Domicilio*> nuevo;
   domicilio = nuevo;
    
}

TipoTransporte Repartidor :: getTransporte() {
	return Transporte;
}

map <string, Domicilio*> Repartidor :: getDomicilio(){
     return domicilio;

 }

void Repartidor :: setTransporte(TipoTransporte t) {
	Transporte = t;
}

void Repartidor :: setDomicilio(Domicilio * dom){
    if (dom != NULL) {
	domicilio[dom->getCodVenta()] = dom;
}}

void Repartidor :: borrarDomicilio(Domicilio* dom){
     domicilio.erase(dom->getCodVenta());
}

set<TipoDomicilio*> Repartidor :: getTipoDomicilio(){
    set<TipoDomicilio*> devolver;
    map <string, Domicilio*> :: iterator it;
    for (it = domicilio.begin() ; it != domicilio.end() ; ++it){
       TipoDomicilio* nuevo = new TipoDomicilio(it->second->getNombreCliente(), it->second->getTelCliente(), it->second->getCodVenta(), it->second->getDireccion(), it->second->getEstado());
       devolver.insert(nuevo);
     }
return devolver;	



}
