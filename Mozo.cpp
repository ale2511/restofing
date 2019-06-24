#include <string>
#include <cstdlib>
#include <iostream>
#include <map>
#include <set> 

#include "Mesa.h"
#include "Empleado.h"
#include "tipoMozo.h"
#include "Mozo.h"
using namespace std; 

Mozo :: Mozo (int nro, string name) : Empleado(nro, name) {
    map<int, Mesa*> mesas_din;
    map<int, Mesa*> mesas_est;
    mesas_dinamicas = mesas_din;
    mesas_estaticas = mesas_est;
}

map <int, Mesa*> Mozo :: mesaDevolverEstaticas() {
	return mesas_estaticas;
}

map <int, Mesa*> Mozo :: mesaDevolverDinamicas() {
	return mesas_dinamicas;
}

void Mozo :: AgregarMesaEstatica(Mesa * m) {
      mesas_estaticas[m->DarMesa()] = m;
}

void Mozo :: AgregarMesaDinamica(Mesa * m) {
	mesas_dinamicas[m->DarMesa()] = m;
}

TipoMesaMozo* Mozo :: getMesasMozo(){
     int i = mesas_estaticas.size();
    TipoMesaMozo* nuevo = new TipoMesaMozo(getnroEmpleado(), i);
    return nuevo;
  
}

bool Mozo :: MesaPertenece(int m){
 map<int, Mesa*> :: iterator mesi;
  mesi = mesas_estaticas.find(m);
  if (mesi != mesas_estaticas.end()){
    return true;
  } else{
    return false;
  }

}



void Mozo :: CambiarEstadoMesas(set<int> mesas, bool estado){
	set<int> :: iterator it;
	for (it = mesas.begin(); it != mesas.end(); ++it)
   {
   	   map<int, Mesa*> :: iterator mesita;
      mesita = mesas_estaticas.find(*it);
      if (mesita != mesas_estaticas.end()){
      mesita->second->setActiva(estado);
   	  if (estado){
   	  mesas_dinamicas[*it] = mesita->second  ;
      } else { mesas_dinamicas.erase(*it); }
   }}


}

void Mozo :: QuitarMesaMozo(int nro){
    mesas_dinamicas.erase(nro);
}

map<int, Mesa*> Mozo :: DevolverMesasElegidas(set<int> mesas){
    set<int> :: iterator it;
    map<int, Mesa*> devolver;
    for (it = mesas.begin() ; it != mesas.end(); ++it)
    {
    	Mesa* mesita = mesas_estaticas[*it];
      if (mesita != NULL){
    	devolver[*it] = mesita;}

    }
    return devolver;


}

set<TipoMesa*> Mozo :: mesasTipoDevolver(){
	set<TipoMesa*> mesas;
	map<int, Mesa*> :: iterator it;
	for (it = mesas_estaticas.begin(); it != mesas_estaticas.end(); ++it)
	{
      TipoMesa* nuevo = new TipoMesa(it->second->DarMesa());
      mesas.insert(nuevo);
  	}
  	return mesas;
}


set<TipoMesa*> Mozo :: MesasLibres(){
	set<TipoMesa*> mesas;
	map<int, Mesa*> :: iterator it;
	for (it = mesas_estaticas.begin(); it != mesas_estaticas.end(); ++it){
	
		if(!(it->second->Activa())){
        TipoMesa* nuevo = new TipoMesa(it->second->DarMesa(), it->second->Activa());
        mesas.insert(nuevo);
		}

	}
	return mesas;
}

bool Mozo :: tieneMesa(int nroMesa) {
	map<int, Mesa*> :: iterator it;
	it = mesas_estaticas.find(nroMesa);
	return (it != mesas_estaticas.end());
}


void Mozo :: VaciarLasMesas(){
   map <int, Mesa*> :: iterator it;
   for( it = mesas_estaticas.begin(); it != mesas_estaticas.end(); ++it){
    int m = it->first;
   mesas_estaticas.erase(m);


}


}
