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
