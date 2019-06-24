#include <string>
#include <cstdlib>
#include <iostream>
#include <map>
#include <set>

#include "contrProducto.h"
#include "ContrEmpleado.h"
#include "iAgregarProductoAUnaVenta.h"
#include "iQuitarProductoAUnaVenta.h"
#include "iFacturacionDeUnaVenta.h"
#include "IVentaADomicilio.h"
#include "IFacturacionDeUnDia.h"
#include "iConsultarPedidoCliente.h"
#include "iConsultarPedidoAdmin.h"
#include "ContrVenta.h"
using namespace std;





//----------------------------------

void ContrVenta :: AgregarVenta(Venta* venta){
	ventas[venta->getCodVenta()] = venta;
}

void ContrVenta :: AgregarMensaje(TipoActualizacion* nueva){
	actualizaciones.insert(nueva);
}

void ContrVenta :: AgregarCliente(Cliente* cliente){
	clientes[cliente->getTel()] = cliente;
}

void ContrVenta :: AgregarLocal(Local* local){
	locales[local->getCodVenta()] = local;
}

void ContrVenta :: AgregarFactura(Factura* factura){
	facturas[factura->getNrofactura()] = factura;
}


//------------------------------------


ContrVenta * ContrVenta :: instancia = NULL;

ContrVenta * ContrVenta :: getInstance() {
	if (instancia == NULL)
		instancia = new ContrVenta();
	return instancia;
}

ContrVenta :: ContrVenta(){
	map <string, Venta *> ventitas;
	ventas = ventitas;
	map <string, Local *> localcillas;
	locales = localcillas;
	map <string, Factura *> facturitas;
	facturas = facturitas;
	map <string, Cliente *> clientillos;
	clientes = clientillos;
	map <string, Domicilio *> domicilillos;
	domicilios = domicilillos;
    set<TipoActualizacion*> acts;
    actualizaciones = acts;
	nroMesa = 0;
	cod = "Sin codigo";
	cant = 0;
	prod = "sin producto";
	ventilla = "sin venta";
	IVA = 22;
	nombre = "innombrable";
	telefono = "no hay";
	direccion = NULL;
	sumadorcodventa = 0;
	repartidorcillo = 0;

}

//getters

float ContrVenta :: getIVA() {
	return IVA;
}

int ContrVenta :: getnroMesa() {
	return nroMesa;
}

string ContrVenta :: getcod() {
	return cod;
}

int ContrVenta :: getcant() {
	return cant;
}
string ContrVenta :: getprod() {
	return prod;
}

string ContrVenta :: getventa() {
	return ventilla;
}

string ContrVenta :: getTelefono() {
	return telefono;
}

string ContrVenta :: getNombre() {
	return nombre;
}

TipoDireccion * ContrVenta :: getDireccion() {
	return direccion;
}

string ContrVenta :: getSumador() {
	setSumador();
	string str = to_string(sumadorcodventa);
	return str;
}

int ContrVenta :: getRepartidor() {
	return repartidorcillo;
}


map <string, Domicilio *> ContrVenta :: getDomicilios() {
	return domicilios;
}


//setters

void ContrVenta :: setnroMesa(int a) {
	nroMesa = a;
}

void ContrVenta :: setcod(string a) {
	cod = a;
}

void ContrVenta :: setcant(int a) {
	cant = a;
}

void ContrVenta :: setprod(string a) {
	prod = a;
}

void ContrVenta :: setventa(string a) {
	ventilla = a;
}

void ContrVenta :: setTelefono(string a) {
	telefono = a;
}

void ContrVenta :: setNombre(string a) {
	nombre = a;
}

void ContrVenta :: setDireccion(TipoDireccion * a) {
	direccion = a;
}

void ContrVenta :: setSumador() {
	sumadorcodventa++;
}

void ContrVenta :: setRepartidor(int a) {
	repartidorcillo = a;
}


//funciones




bool ContrVenta :: localEsVacia() {
	return locales.empty();
}

bool ContrVenta :: ventaNoFacturada(int nroMesa) {
	map <string, Local *> :: iterator it;
	bool b = false;
	it = locales.begin();
	while(!b && (it!=locales.end())) {
		b = it->second->tieneMesa(nroMesa);
		if (!b){
		it++;}
	}
	if (b) {
		setventa(it->first);
		setnroMesa(nroMesa);
	}
	return b;
}

set <TipoProducto *> ContrVenta :: darProds() {
	ContrProducto *ctrl = ContrProducto :: getInstance();
	return ctrl->darProds();
}

bool ContrVenta :: ingProds(string cod, int cant) { 
	ContrProducto * ctrlp = ContrProducto :: getInstance();
	bool b = ctrlp->noHayCodigo(cod);
	if (!b) {
	setcod(cod);
	}
	setcant(cant);
	return !b;
}

void ContrVenta :: confirmarAgregarProducto() { //solo para mozo
	string cod = getcod();
	int cant = getcant();
	string nroventa = getventa();
	Local * v;
	v = locales[nroventa];
	if (v != NULL) {
		v->agregarProducto(cod, cant);
	}
}

set <TipoProducto *> ContrVenta :: verProdsVenta() {
	string nroventa = getventa();
	Local * v = locales[nroventa];
	set<string> listadoCods = v->mostrarCodProds();
	set<string> :: iterator it;
	set <TipoProducto *> result;
	ContrProducto * ctrl = ContrProducto :: getInstance();
	TipoProducto * s;
	string cod;
	for (it = listadoCods.begin(); it != listadoCods.end(); ++it) {
		cod = *it;
		s = ctrl->getDTProd(cod);
		result.insert(s);
	}
	return result;
}

bool ContrVenta :: prodAEliminar(string prod, int cant) {
	if (cant <0) {
		return false;
	} else {
		ContrProducto * ctrlp = ContrProducto :: getInstance();
		bool b = !ctrlp->noHayCodigo(prod);
		setcod(prod);
		setcant(cant);
		if (b) {
			b = cant>0;
			if (b) {
				string codventa = getventa();
				Local * l = locales[codventa];
				map<string, CantProducto*> loscp = l->getMapCP();
				b = (loscp.find(prod) != loscp.end());
				if (b) {
					CantProducto * cp = loscp[prod];
					b = (cp->getCant() >= cant);
				}
			}
		}
		return b;
	}
}

void ContrVenta :: confirmarQuitarProdVenta() {
	string codventa = getventa();
	Local * v = locales[codventa];
	if (v != NULL){
		v->bajarCp(cod, cant);
	}
}

//-------------------


void ContrVenta :: imprimirAct(){
    int a = actualizaciones.size();
    cout << "dom :    ffff" << domicilios.size() << endl;
 cout <<    "CANTIDAD" << a << endl;   
    
}

//----


map <string, TipoCantProducto*> ContrVenta :: CPMapTCP (map <string, CantProducto *> elmapa) {
	map <string, TipoCantProducto*> result;
	set<string> conjCodigos; //set de codigos
	
	map <string, CantProducto *> :: iterator it1;
	for (it1 = elmapa.begin(); it1!= elmapa.end(); ++it1) {
		string s1 = it1->second->getCodProdGral();
		conjCodigos.insert(s1);
	}
	
	set<int> conjCants;//set de cantidades
	map <string, CantProducto *> :: iterator it2;
	for (it2 = elmapa.begin(); it2!= elmapa.end(); ++it2) {
		int s2 = it2->second->getCant();
		conjCants.insert(s2);
	}
	
	
	set<string> :: iterator at; //recorre codigos
	set<int> :: iterator it; //recorre cantidades
	TipoProducto * tp;
	string cod;
	int cant;
	ContrProducto * ctrl = ContrProducto :: getInstance();
	TipoCantProducto * tcp;
	it = conjCants.begin();
	for (at = conjCodigos.begin(); at != conjCodigos.end(); ++at) {
		cod = *at;
		tp = ctrl->getDTProd(cod);
		cant = *it;
		tcp = new TipoCantProducto(cant, tp);
		result[cod] = tcp;
		it++;
	}
	return result;
}

set <TipoCantProducto*> ContrVenta :: MapTCPSetTPC (map <string, TipoCantProducto*> elmapa) {

	set <TipoCantProducto*> result;

	map <string, TipoCantProducto*> :: iterator it;

	for (it = elmapa.begin(); it != elmapa.end(); ++it)
		result.insert(it->second);

	return result;
}


TipoFactura * ContrVenta :: facturar(float descuentillo) {
	//se necesita mandarle a Factura/TipoFactura:
	//int nroVenta
	//map<string, CantProducto*> mapafactura / set <TipoCantProducto *> setatipofactura
	//TipoFecha fechita
	//TipoHora horita
	//float sub_total
	//float descuentillo
	//float precio_sin_iva
	//float totalcompra 
	string codventa = getventa(); //nroVenta listo
	bool eslocal = true;
	Venta * v;
	
	map <string, Local *> :: iterator busque;
	busque = locales.find(codventa);
	if (busque == locales.end()) {
		eslocal = false;
		v = domicilios[codventa];
	} else {
		v = locales[codventa];
	}
	
	/*v = locales[codventa];
	if (v == NULL) {
		eslocal = false;
		v = domicilios[codventa];
	}*/
	map<string, CantProducto*> mapafactura = v->getMapCP(); //map<string, CantProducto*> listo
	map<string, TipoCantProducto*> mapatipocantproducto = CPMapTCP(mapafactura);
		
	
	
	
	set<string> conjCodigos = v->mostrarCodProds(); //set de codigos
	set<int> conjCants = v->mostrarCantProds();//set de cantidades
	set <TipoCantProducto *> setatipofactura; //set TipoCantProducto nuevo
	
	set<string> :: iterator at; //recorre codigos
	set<int> :: iterator it; //recorre cantidades
	TipoProducto * tp;
	string cod;
	int cant;
	ContrProducto * ctrl = ContrProducto :: getInstance();
	//bool aplica = true; //true mientras no haya menu
	float preciotp;
	float sub_total = 0;
	float precio_sin_iva = 0;
	TipoSimple * s;
	TipoCantProducto * tcp;
	it = conjCants.begin();
	for (at = conjCodigos.begin(); at != conjCodigos.end(); ++at) {
		cod = *at;
		cant = *it;
		tp = ctrl->getDTProd(cod);
		s = dynamic_cast<TipoSimple*>(tp); //a ver si es simple
		preciotp = tp->getPrecio();
		if (s == NULL) {
			precio_sin_iva = precio_sin_iva + preciotp * cant;
			//aplica = false;
		} else {
			precio_sin_iva = precio_sin_iva + preciotp * cant * (1 - descuentillo / 100);
		}
		sub_total = sub_total + preciotp * cant;
		tcp = new TipoCantProducto(cant, tp);
		setatipofactura.insert(tcp);
		it++;
	}//sub_total listo 
	time_t fechaactual = time(0);
	tm * time = localtime(&fechaactual);
	TipoFecha* fecha = new TipoFecha(time->tm_mday, time->tm_mon + 1, time->tm_year + 1900); //fechita lista
	TipoHora* hora = new TipoHora(time->tm_sec, time->tm_min, time->tm_hour); //horita lista
	//float precio_sin_iva = sub_total; //precio_sin_iva listo
	//if (aplica)
		//precio_sin_iva = sub_total*(1 - descuentillo / 100);
	float elimpuesto = getIVA();
	float totalcompra = precio_sin_iva * (elimpuesto / 100 + 1); //totalcompra listo
	
	//listos para crear la Factura y TipoFactura *
	//primero Factura
	ContrEmpleado * ctrle = ContrEmpleado :: getInstance();
	int h;
	TipoEmpleado * te = NULL;
	if (eslocal) {
		h = ctrle->getNroMozo(getnroMesa());
		te = ctrle->obtenerTipoMozo(h);
	} else {
		te = ctrle->obtenerTipoRepartidor(repartidorcillo);
	}
	Factura * f = new Factura(codventa, mapatipocantproducto, fecha, hora, sub_total, descuentillo, precio_sin_iva, totalcompra, te);
	facturas[codventa] = f;
	
	//ahora TipoFactura
	TipoFactura * tf = new TipoFactura(codventa, setatipofactura, fecha, hora, sub_total, descuentillo, precio_sin_iva, totalcompra, te);
	if (eslocal) {
		Local * l = locales[codventa];
		set <int> mandar = l->numerosMesas();
		ctrle->CambiarEstado(mandar, h);
		locales.erase(codventa);
	} else {
		domicilios.erase(codventa);
	}
	v->~Venta();
	return tf;
}


set <TipoMozo *> ContrVenta :: verMozos() {
	ContrEmpleado * ctrl = ContrEmpleado :: getInstance();
	return ctrl->VerMozos();
}

set <TipoFactura *> ContrVenta :: verFacturasMozo(int numMozo, TipoFecha * f1, TipoFecha * f2) {
	set <TipoFactura *> result;
	map <string, Factura *> :: iterator it;
	it = facturas.begin();
	Factura * f;
	while ((it != facturas.end()) && (f2 < it->second->getFecha())) {
		if (! (it->second->getFecha() < f1 )) {
			//se necesita mandarle a TipoFactura:
			//string nroVenta
			//set <TipoCantProducto *> setatipofactura
			//TipoFecha fechita
			//TipoHora horita
			//float sub_total
			//float descuentillo
			//float precio_sin_iva
			//float totalcompra
			string nroventa = it->second->getNrofactura();
			
			f = it->second;
			set<TipoCantProducto*> setdesalida;
			map<string, TipoCantProducto*> siche = f->mostrarTipoProds();
			setdesalida = MapTCPSetTPC(siche);

			TipoFecha* fechita = it->second->getFecha();
			TipoHora* hora = it->second->getHora();
			float subtotal = it->second->getSubtotal();
			float descuentillo = it->second->getDescuento();
			float preciosiniva = it->second->getPreciosSinIva();
			float totalito = it->second->getTotal();
			TipoEmpleado * te = it->second->getEmpleado();
			TipoFactura * tf = new TipoFactura(nroventa, setdesalida, fechita, hora, subtotal, descuentillo, preciosiniva, totalito, te);
			result.insert(tf);
		}
	}
	return result;
}


set <TipoFactura *> ContrVenta :: verFacturasFecha(TipoFecha * fecha) {
	set <TipoFactura *> result;
	map <string, Factura *> :: iterator it;
	it = facturas.begin();
	Factura * f;
	while ((it != facturas.end()) && (!fechasIguales(it->second->getFecha(), fecha))) {
		++it;
		
	}
	while ((it != facturas.end()) && fechasIguales(fecha, it->second->getFecha())) {
		
			//se necesita mandarle a TipoFactura:
			//string nroVenta
			//set <TipoCantProducto *> setatipofactura
			//TipoFecha fechita
			//TipoHora horita
			//float sub_total
			//float descuentillo
			//float precio_sin_iva
			//float totalcompra
			string nroventa = it->second->getNrofactura();
			
			f = it->second;
			set<TipoCantProducto*> setdesalida;
			map<string, TipoCantProducto*> siche = f->mostrarTipoProds();
			setdesalida = MapTCPSetTPC(siche);
			
			TipoFecha* fechita = it->second->getFecha();
			TipoHora* hora = it->second->getHora();
			float subtotal = it->second->getSubtotal();
			float descuentillo = it->second->getDescuento();
			float preciosiniva = it->second->getPreciosSinIva();
			float totalito = it->second->getTotal();
			TipoEmpleado * te = it->second->getEmpleado();
			TipoFactura * tf = new TipoFactura(nroventa, setdesalida, fechita, hora, subtotal, descuentillo, preciosiniva, totalito, te);
			result.insert(tf);
			++it;
	}

	return result;
}




void ContrVenta :: datosCliente(string nom, TipoDireccion * dir) {
	setNombre(nom);
	setDireccion(dir);
}

void ContrVenta :: confirmarAgregarCliente(bool recibe) {
	Cliente * cl = new Cliente(getTelefono(), getNombre(), getDireccion(), recibe);
	clientes[getTelefono()] = cl;
}

bool ContrVenta :: noHayCliente(string tel) {
	setTelefono(tel);
	return NULL == clientes[getTelefono()];
}

void ContrVenta :: iniciarVentaEnMesas(set<Mesa*> m, int nromozo) {
	string a = getSumador();
	map <int, Mesa *> amesas;
	map <int, Mesa *> :: iterator it1;
	set <Mesa *> :: iterator it;
	int clave;
	ContrEmpleado * ctrl = ContrEmpleado :: getInstance();
	it = m.begin();
	for (it = m.begin(); it != m.end(); ++it) {
		Mesa* mesita = *it;
		clave = ctrl->getNroMesa(mesita);
		amesas[clave] = mesita;
	}
	it1 = amesas.begin();
	if (it1 != amesas.end()){
	Local * l = new Local(a, nromozo);
	locales[a] = l;
	ventas[a] = l;
	l->setMesas(amesas);}
}


void ContrVenta :: iniciarVentaDomicilio() {
	string a = getSumador();
	setventa(a);
	Cliente * c = clientes[telefono];
	Domicilio * d = new Domicilio(a, c);
	domicilios[a] = d;
}

void ContrVenta :: confirmarProductoEnDomicilio() {
	iniciarVentaDomicilio();
	string cod = getcod();
  
	int cant = getcant();
	string nroventa = getventa();
	Domicilio * d = domicilios[nroventa];
	if (d != NULL) {
		d->agregarProducto(cod, cant);
	}
}

set <TipoRepartidor *> ContrVenta :: verRepartidores() {
	ContrEmpleado * ctrl = ContrEmpleado :: getInstance();
	return ctrl->VerRepartidores();
}

void ContrVenta :: elegirRepartidor(int repartidor) {
	string a = getventa();
      cout << "ESTE ES: " <<   a << endl;
	Domicilio * d = domicilios[a];
    if (d != NULL){
	d->setRepartidor(repartidor);
    ContrEmpleado* ce = ContrEmpleado::getInstance();
    ce->guardarVentaRepartidor(repartidor, d);
    }
}

void ContrVenta :: inicializarEstado(int estado) {
	string nroventa = getventa();
	ContrEmpleado * ce = ContrEmpleado :: getInstance();
	ce->setCodVenta(nroventa);
	ce->elegirEstado(estado);
	ce->confirmarNuevoEstado();
}

bool ContrVenta :: recibeMensajes() {
	map <string, Cliente *> :: iterator it;
	it = clientes.find(getTelefono());
	return (it->second->getActualizaciones());
}

bool ContrVenta :: compareFechas(TipoFecha * vieja, TipoFecha * nueva) {
	bool devolver = false;
	if (vieja->getanio() < nueva->getanio()) {
		devolver = true;
	} else if (vieja->getanio() == nueva->getanio()) {
		if (vieja->getmes() < nueva->getmes()) {
			devolver = true;
		} else if (vieja->getmes() == nueva->getmes()) {
			if (vieja->getdia() < nueva->getdia()) {
				devolver =true;
			}
		}

	}
	return devolver;
}

bool ContrVenta :: fechasIguales(TipoFecha * vieja, TipoFecha * nueva) {
	return ((vieja->getanio() == nueva->getanio()) && (vieja->getmes() == nueva->getmes()) && (vieja->getdia() == nueva->getdia()));
}
	
bool ContrVenta :: compareHoras(TipoHora * vieja, TipoHora * nueva) {
	bool devolver = false;
	if (vieja->getHora() < nueva->getHora()) {
		devolver = true;
	} else if (vieja->getHora() == nueva->getHora()) {
		if (vieja->getMinuto() < nueva->getMinuto()) {
			devolver = true;
		} else if (vieja->getMinuto() == nueva->getMinuto()) {
			if (vieja->getSegundos() < nueva->getSegundos()) {
				devolver =true;
			}
		}

	}
	return devolver;
}

TipoActualizacion * ContrVenta :: ConfirmarMensaje() { 
	map <string, Cliente *> :: iterator it;
	it = clientes.find(getTelefono());
	set <TipoActualizacion*> ta = it->second->getMensajes();
	set <TipoActualizacion*> :: iterator it1;
	set <TipoActualizacion*> :: iterator aux;
	aux = ta.begin();
	TipoActualizacion * currentAux = *aux;
	TipoFecha * fechaAux = currentAux->getFecha();
	TipoHora * horaAux = currentAux->getHora();
	bool huboCambios = false;
	for (it1 = ta.begin(); it1 != ta.end(); ++it1) {
		TipoActualizacion * current = *it1;
		TipoFecha * fecha = current->getFecha();
		TipoHora * hora = current->getHora();
		huboCambios = compareFechas(fechaAux, fecha);
		if (huboCambios) {
			fechaAux = fecha;
			horaAux = hora;
			currentAux = current;
		} else if (fechasIguales(fechaAux, fecha)) {
			huboCambios = compareHoras(horaAux, hora);
			if (huboCambios) {
				horaAux = hora;
				currentAux = current;
			}
		}
	}
	return currentAux;
}

set<TipoActualizacion*> ContrVenta :: ListarActualizaciones() {
	set<TipoActualizacion*> res;
	map <string, Domicilio *> :: iterator it;
	Cliente * c;
	for (it = domicilios.begin(); it != domicilios.end(); ++it) {
		c = it->second->getCliente();
		set<TipoActualizacion*> ta = c->getMensajes();
		set<TipoActualizacion*> :: iterator it1;
		for (it1 = ta.begin(); it1 != ta.end(); ++it1) {
			TipoActualizacion * current = *it1;
			res.insert(current);
		}
	}
	return res;
}

set<TipoActualizacion*> ContrVenta :: ListarActualizacionesSistema(){
 return actualizaciones;   
}

TipoCantProducto * ContrVenta :: obtenerTCPFact(string cod, TipoProducto * tp) {
	TipoCantProducto * tcp = new TipoCantProducto(0, tp);
	map <string, Factura *> :: iterator it;
	for (it = facturas.begin(); it != facturas.end(); ++it)
		tcp = it->second->verProdsFacturados(cod, tcp);
	return tcp;
}

TipoFecha * ContrVenta :: hacedorFecha(int a, int m, int d) {
	TipoFecha * f = new TipoFecha(d, m, a);
	return f;
}

bool ContrVenta :: noHayVenta(string cod) {
	bool nohayprod = true;
	map <string, Local *> :: iterator loc;
	loc = locales.begin();
	set <string> :: iterator stri;
	Local * l;
	while ((loc != locales.end()) && (nohayprod)) {
		l = loc->second;
		set<string> setcillo = l->mostrarCodProds();
		stri = setcillo.find(cod);
		nohayprod = (stri == setcillo.end());
		++loc;
	}
	
	Domicilio * d;
	map <string, Domicilio *> :: iterator dom;
	dom = domicilios.begin();
	while ((dom != domicilios.end()) && (nohayprod)) {
		d = dom->second;
		set<string> setcillotres = d->mostrarCodProds();
		stri = setcillotres.find(cod);
		nohayprod = (stri == setcillotres.end());
		++dom;
	}
	return nohayprod;
}

TipoDireccion * ContrVenta :: hacedorDir(string calle, int nro, string c1, string c2) {
	TipoDireccion * d = new TipoDireccion(calle, nro, c1, c2);
	return d;
}

TipoDireccionApart * ContrVenta :: hacedorApar(string calle, int nro, string c1, string c2, string edif, int nroedif) {
	TipoDireccionApart * tda = new TipoDireccionApart(calle, nro, c1, c2, edif, nroedif);
	return tda;
}


bool ContrVenta :: existeVentaDom(string cod) {
	map <string, Domicilio *> :: iterator it;
	it = domicilios.find(cod);
	return (it != domicilios.end());
}
