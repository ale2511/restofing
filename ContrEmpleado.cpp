#include <string>
#include <cstdlib>
#include <iostream>
#include <map>
#include <set>
#include <cmath>

#include "ContrVenta.h"
#include "iAltaEmpleado.h"
#include "iAsignarMozosAMesas.h"
#include "iIniciarVentaEnMesas.h"
#include "iModificarEstadoPedido.h"
#include "ContrEmpleado.h"
using namespace std; 


set<TipoDomicilio*> ContrEmpleado :: getVentasRepartidor(int nro){
	set<TipoDomicilio*> devolver;
    Repartidor* repartidor = CRepartidor[nro];
    if (repartidor != NULL){
       devolver = repartidor->getTipoDomicilio();
   }
 return devolver;
}


//---------------------------------
void ContrEmpleado :: AgregarMozo(Mozo* mozo){
	CMozo[mozo->getnroEmpleado()] = mozo;
}

void ContrEmpleado :: AgregarMesa(Mesa* mesa){
	CMesa[mesa->DarMesa()] = mesa;
}

void ContrEmpleado :: AgregarRepartidor(Repartidor* repartidor){
	CRepartidor[repartidor->getnroEmpleado()] = repartidor;
}

//------------------------

ContrEmpleado * ContrEmpleado :: instancia = NULL;

ContrEmpleado * ContrEmpleado :: getInstance() {
	if (instancia == NULL)
		instancia = new ContrEmpleado();
	return instancia;
}

int ContrEmpleado :: getNroMozo(int nroMesa) {
	map <int, Mozo*> :: iterator it;
	it = CMozo.begin();
	while ((it != CMozo.end()) && (!(it->second->tieneMesa(nroMesa))))
		++it;
	return it->first;
}
string ContrEmpleado :: getNombreMozo(int nroMesa) {
	map <int,Mozo*> :: iterator it;
	it = CMozo.begin();
	while ((it != CMozo.end()) && (!(it->second->tieneMesa(nroMesa))))
		++it;
	return it->second->getNombre();
}

void ContrEmpleado :: CambiarEstado(set<int> mesas, int nroMozo){
  Mozo* mozo = CMozo[nroMozo];
  set<int> :: iterator it;
  mozo->CambiarEstadoMesas(mesas, false);
  for (it = mesas.begin(); it != mesas.end(); ++it)
  {
  	mozo->QuitarMesaMozo(*it);
  }

}

//getters

string ContrEmpleado :: getNombreEmpleado() {
	return nombreEmpleado;
}

int ContrEmpleado :: getVehiculo() {
	return vehiculo;
}

string ContrEmpleado :: getCodVenta() {
	return codVenta;
}

int ContrEmpleado :: getNroEstado() {
	return nroEstado;
}

int ContrEmpleado :: getNroEmpleado() {
	return nroEmpleado;
}

//setters
void ContrEmpleado :: setNombreEmpleado(string unNombre) {
	nombreEmpleado = unNombre;
}

void ContrEmpleado :: setVehiculo(int veh) {
	vehiculo = veh;
}

void ContrEmpleado :: setCodVenta(string cod) {
	codVenta = cod;
}

void ContrEmpleado :: setNroEstado(int estado) {
	nroEstado = estado;
}

void ContrEmpleado :: setNroEmpleado(int nro) {
	nroEmpleado = nro;
}

//Alta Empleado

void ContrEmpleado :: ingresarNombre(string n) {
	setNombreEmpleado(n);
}

set<TipoTransporte> ContrEmpleado :: DarTransporte() {
	set<TipoTransporte> t;
	t.insert(Pie);
	t.insert(Bicicleta);
	t.insert(Moto);
    return t;     
}

void ContrEmpleado :: ingresarTransporte(int veh) {
	setVehiculo(veh);
}
	
void ContrEmpleado :: ConfirmarEmpleado(bool esMozo) {
	int nro = CEmpleado.size() + 1;
	if (esMozo) {
		Mozo * m = new Mozo(nro, getNombreEmpleado());
		CMozo[nro] = m;
		CEmpleado[nro] = m;
	} else {
		TipoTransporte t;
		switch (getVehiculo()) {
			case 0: {
				t = Pie;
				break; 
			}
			case 1: {
				t = Bicicleta;
				break;
			}
			case 2: {
				t = Moto;
				break;
			}
		};
		Repartidor * r = new Repartidor(nro, getNombreEmpleado(), t);
		CRepartidor[nro] = r;
		CEmpleado[nro] = r;
	}
}

void ContrEmpleado :: VaciarMesas(){
   map<int, Mozo*> :: iterator it;
   it = CMozo.begin();
   if (it != CMozo.end()){ 
   for (   it = CMozo.begin(); it != CMozo.end(); ++it)
   {
   	   it->second->VaciarLasMesas();
   }}

}


//Asignar Mozos a Mesas
set <TipoMesaMozo*> ContrEmpleado :: AsignarMozoMesas() { //HACER //falta lo de aleatorio y llenar el tipomesa set
	VaciarMesas();
	set <TipoMesaMozo*> res;
	//TipoMesaMozo* nuevo = new TipoMesaMozo(2,2);
	//res.insert(nuevo);
	//cout << CMesa.size();
	ContrVenta* vent = ContrVenta::getInstance();
	if (vent->localEsVacia()){
	int cantRepartir = floor (CMesa.size()/CMozo.size());
	map<int, Mozo*> :: iterator it;
	map<int, Mesa*> :: iterator it1;
	int i = 1;
	int tamaMozo = CMozo.size();
	it = CMozo.begin();
	it1 = CMesa.begin();
	while ((it1 != CMesa.end()) && ( i <= (tamaMozo*cantRepartir))) {
		int j = i;
		while (i <= j+cantRepartir-1){
			it->second->AgregarMesaEstatica(it1->second);
			i = i + 1;
			++it1;
     
		}
		++it;
	}

	if (it1 != CMesa.end()){
		int resto = CMesa.size() % CMozo.size();
        it = CMozo.begin();
        int k = 1;
		while((it != CMozo.end()) && (it1 != CMesa.end()) && (k <= resto)){
			it->second->AgregarMesaEstatica(it1->second);
                        ++it;
			it1++;
		}
	}

	for (it = CMozo.begin(); it != CMozo.end(); ++it)
	{
		TipoMesaMozo* nuevo = it->second->getMesasMozo();
		res.insert(nuevo);
			}}
	return res;
}
  
//FUNCIÓN AUXILIAR:

int ContrEmpleado :: getNroMesa(Mesa* mesa){
	return mesa->DarMesa();
}


//Iniciar Venta en Mesas

set <TipoMesa*> ContrEmpleado :: VerMesasMozo(int nro) {
   set<TipoMesa*> mesas;
  bool existeMozo = (CMozo.find(nro) != CMozo.end());
  if (existeMozo) { //Chequear con la screen
   Mozo* mozo = CMozo[nro];
   
   	  setNroEmpleado(nro);
      mesas = mozo->MesasLibres();



   }
   return mesas;
         
 }
 
void ContrEmpleado::ElegirMesaMozo(set<int> mesas) { 
	set<int> quedan;
	Mozo * mozo = CMozo[getNroEmpleado()];
       if (mozo != NULL){

	set<int> :: iterator it;
	for (it = mesas.begin(); it != mesas.end(); ++it)
	{
       if(mozo->MesaPertenece(*it)){
       	quedan.insert(*it);
       }

	}

	}
	eleccionMesaMozo = quedan;
    
}
	 
void ContrEmpleado :: ConfirmarVentaEnMesa() { 
   Mozo* mozo = CMozo[getNroEmpleado()];
   if (mozo != NULL){
   mozo->CambiarEstadoMesas(eleccionMesaMozo, true);
   map<int, Mesa*> mesasenviar = mozo->DevolverMesasElegidas(eleccionMesaMozo);
   map<int, Mesa*> :: iterator it;
   set <Mesa*> rily;
   it = mesasenviar.begin();
   if (it != mesasenviar.end()){
   for (it = mesasenviar.begin(); it != mesasenviar.end(); ++it)
	   rily.insert(it->second);
   ContrVenta* CVenta = ContrVenta::getInstance();
   CVenta->iniciarVentaEnMesas(rily, getNroEmpleado());}}
} 


//Modificar Estado Pedido

bool ContrEmpleado :: existeVentaDom(string cod) {
	ContrVenta* cv = ContrVenta :: getInstance();
	bool res = cv->existeVentaDom(cod);
	return res;
}


set <TipoEstado> ContrEmpleado :: ingrPedido(string cod) { //Hecha
	setCodVenta(cod);
	set<TipoEstado> e;
	e.insert(Pedido);
	e.insert(Encamino);
	e.insert(Entregado);
	e.insert(Cancelado);
	return e;
}

void ContrEmpleado :: elegirEstado(int estado) {
	setNroEstado(estado);
}

void ContrEmpleado :: guardarVentaRepartidor(int nroR, Domicilio* d){
  Repartidor* rep = CRepartidor[nroR];
  if (rep != NULL){
    rep->setDomicilio(d);
    
  }
  
}

void ContrEmpleado :: confirmarNuevoEstado() {
 
	Repartidor* repartidor ;
	map <int,Repartidor*> :: iterator it;
	it = CRepartidor.begin();
	Domicilio * d  = NULL;

	while ((it != CRepartidor.end()) && (d == NULL)) {
		map <string, Domicilio*> CDom = it->second->getDomicilio();
	//	map <string, Domicilio*> :: iterator itD;
	//	itD = CDom.find(getCodVenta());
		cout << "bruno            sdddddddddddddddddddddd                     " << getCodVenta() << endl;
		Domicilio* gg = CDom[getCodVenta()];
		if (gg != NULL){
			d  = CDom[getCodVenta()];
			repartidor = it->second;
		}
		else
			++it;
	};
	if (d != NULL) {
		TipoEstado e;
		switch (getNroEstado()) {
			case 1: {
				e = Pedido;
				break; 
			}
			case 2: {
				e = Encamino;
				break;
			}
			case 3: {
				e = Entregado;
				break;
			}
			case 4: {
				e = Cancelado;
				break;
			}
		};
		set<TipoCantProducto*> losprods;
		
		time_t fechaactual = time(0);  //guardo fecha pc
		tm * time = localtime(&fechaactual); //convierto fecha pc en struct - uso ctime
		TipoFecha * newFecha = new TipoFecha(time->tm_mday, time->tm_mon, time->tm_year + 1900);  // creo un objeto con la fecha
		TipoHora * newHora = new TipoHora(time->tm_sec, time->tm_min, time->tm_hour);
		map<string, CantProducto*> cp = d->getMapCP();
		map<string, CantProducto*> :: iterator it;
		ContrProducto* producto = ContrProducto::getInstance();

		for(it = cp.begin(); it != cp.end(); ++it){
			TipoCantProducto* nuevo = new TipoCantProducto(it->second->getCant(),producto->getDTProd(it->second->getCodProdGral()) );
			losprods.insert(nuevo);

		}

		Cliente* cliente = d->getCliente();
		string nombre = cliente->getNombre();


		TipoActualizacion* nueva = new TipoActualizacion(newHora, newFecha,  repartidor->getNombre(), nombre, losprods, d->getCliente()->getTel(), e);
		cout << "imprimr actu" << nueva->getNombrerepartidor() << endl;
		ContrVenta* venta = ContrVenta::getInstance();
		venta->AgregarMensaje(nueva);
		d->setEstado(nueva, e);
		

	}
}


TipoFactura * ContrEmpleado :: facturar(float descuento) {
	string cod = getCodVenta();
	ContrVenta * cv = ContrVenta :: getInstance();
	cv->setventa(cod);
	map <string, Domicilio *> doms = cv->getDomicilios();
	map <string, Domicilio *> :: iterator it;
	it = doms.find(cod);
	if (it != doms.end()) {
		cv->setRepartidor(it->second->getRepartidor());
	}		
	TipoFactura * fac = cv->facturar(descuento);
	return fac;
}
	


set<TipoMozo*> ContrEmpleado :: VerMozos(){
   set<TipoMozo*> mozos;
   map<int, Mozo*> :: iterator it;
   for (it = CMozo.begin(); it != CMozo.end(); ++it)
   {
   	 TipoMozo* nuevo = new TipoMozo(it->second->getnroEmpleado(), it->second->getNombre(), it->second->mesasTipoDevolver());
   	 mozos.insert(nuevo);
 
}
return mozos;
}

set<TipoRepartidor*> ContrEmpleado :: VerRepartidores(){
   set<TipoRepartidor*> repartidores;
   map<int, Repartidor*> :: iterator it;
   for (it = CRepartidor.begin(); it != CRepartidor.end(); ++it)
   {
   	 TipoRepartidor* nuevo = new TipoRepartidor(it->second->getnroEmpleado(), it->second->getNombre(), it->second->getTransporte());
   	 repartidores.insert(nuevo);
   }
return repartidores;
}



TipoRepartidor* ContrEmpleado :: obtenerTipoRepartidor(int nro){
   TipoRepartidor* nuevo;
   Repartidor* reparte = CRepartidor[nro];
   if (reparte != NULL){
   	nuevo = new TipoRepartidor(reparte->getnroEmpleado(), reparte->getNombre(), reparte->getTransporte());
   } else{
   	nuevo = NULL;
   }
return nuevo;
}

TipoMozo* ContrEmpleado :: obtenerTipoMozo(int nro){
	TipoMozo* nuevo;
	Mozo* mozi = CMozo[nro];
	if (mozi != NULL){
		nuevo = new TipoMozo(mozi->getnroEmpleado(), mozi->getNombre(), mozi->mesasTipoDevolver());
	} else {
		nuevo = NULL;
	}
	return nuevo;
}

void ContrEmpleado::crearmesa(int a){
	Mesa *m;
	m=new Mesa(a);
	CMesa[a]=m;
}