#ifndef _MOZO_H
#define	_MOZO_H

#include <string>
#include <cstdlib>
#include <iostream>
#include <map>
#include <set> 

#include "Mesa.h"
#include "Empleado.h"
#include "tipoMozo.h"
using namespace std; 


class Mozo: public Empleado{

private:
	map <int, Mesa*> mesas_dinamicas;
	map <int, Mesa*> mesas_estaticas;

public:
    Mozo(int, string);
    map <int, Mesa*> mesaDevolverEstaticas();
	map <int, Mesa*> mesaDevolverDinamicas();
	set<TipoMesa*> mesasTipoDevolver();
    void AgregarMesaEstatica(Mesa*);
	void AgregarMesaDinamica(Mesa*);
	void CambiarEstadoMesas(set<int>, bool estado);
	void QuitarMesaMozo(int);
	set<TipoMesa*> MesasLibres();  
	map<int, Mesa*> DevolverMesasElegidas(set<int>);
	bool tieneMesa(int);
        TipoMesaMozo* getMesasMozo();
void VaciarLasMesas();
bool MesaPertenece(int);

};
   
#endif
