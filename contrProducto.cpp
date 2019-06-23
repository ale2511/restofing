#include <string>
#include <cstdlib>
#include <iostream>
#include <map>
#include <set> 

#include "iAltaProducto.h"
#include "iInformacionDeUnProducto.h"
#include "iBajaProducto.h"
#include "ContrVenta.h"
#include "contrProducto.h"
using namespace std;

ContrProducto * ContrProducto :: instancia = NULL;

ContrProducto * ContrProducto :: getInstance() {
	if (instancia == NULL)
		instancia = new ContrProducto();
	return instancia;
}

//getters

string ContrProducto :: getCod() {
	return codigo;
}

string ContrProducto :: getDesc() {
	return descripcion;
}

float ContrProducto :: getPrecio() {
	return precio;
}

map <string, int> ContrProducto :: getPar() {
	return par;
}

//setters

void ContrProducto :: setCod(string unCodigo) {
	codigo = unCodigo;
}

void ContrProducto :: setDesc(string unaDescripcion) {
	descripcion = unaDescripcion;
}

void ContrProducto :: setPrecio(float unPrecio) {
	precio = unPrecio;
}

void ContrProducto :: agregarPar(string cod, int cant) {
	par[cod] = cant;
}

void ContrProducto :: borrarPares() {
	if (!par.empty()) {
		map <string, int> :: iterator it;
		for (it = par.begin(); it != par.end(); ++it)
			par.erase(it->first);
	}
}

//Alta Producto

bool ContrProducto :: hayProdSim() {
	return (!sim.empty());
}

bool ContrProducto :: noHayCodigo(string cod) {
	setCod(cod);
	bool nhc = true;
	map <string, ProdGral *> :: iterator it;
	it = prods.find(cod);
	if ((it != prods.end()) && (cod == it->first))
		nhc = false;
	return nhc;
}

void ContrProducto :: datosProdSim(string desc, float pr) {
	setDesc(desc);
	setPrecio(pr);
}

void ContrProducto :: datosProdMenu(string desc) {
	setDesc(desc);
}

set <TipoSimple *> ContrProducto :: darProdSim() {
	set <TipoSimple *> res;
	map <string, Simple *> :: iterator it;
	for (it = sim.begin(); it != sim.end(); ++it) {
		TipoProducto * tp = it->second->darDatosProd();
		TipoSimple * ts = dynamic_cast<TipoSimple*>(tp);
		if (ts != NULL)
			res.insert(ts);
	}
	return res;
}

void ContrProducto :: ingrProdSim(string cod, int cant) {
	agregarPar(cod, cant);
}

void ContrProducto :: confirmarAltaProd(bool esSimple) {
	if (esSimple) {
		Simple * s = new Simple(getCod(), getDesc(), getPrecio());
		sim[getCod()] = s;
		prods[getCod()] = s;
	} else {
		Menu * m = new Menu(getCod(), getDesc());
		map <string, int> :: iterator itPar;
		string cod;
		int cant;
		for (itPar = par.begin(); itPar != par.end(); ++itPar) {
			cod = itPar->first;
			cant = itPar->second;
			map <string, Simple *> :: iterator itS;
			itS = sim.find(cod);
			m->nuevoCantProdMenu(cod, cant, itS->second);
		};
		menus[getCod()] = m;
		prods[getCod()] = m;
	}
}

//Informacion de un Producto

set <TipoProducto *> ContrProducto :: darProds() {
	set <TipoProducto *> res;
	map <string, ProdGral *> :: iterator it;
	for (it = prods.begin(); it != prods.end(); ++it) {
		TipoProducto * tp = it->second->darDatosProd();
		res.insert(tp);
	};
	return res;
}

bool ContrProducto :: productoValido(string cod) {
	setCod(cod);
	bool pv = false;
	map <string, ProdGral *> :: iterator it;
	it = prods.find(cod);
	if ((it != prods.end()) && (cod == it->first))
		pv = true;
	return pv;
}

TipoCantProducto * ContrProducto :: verInfoProducto() {
	TipoProducto * tp  = getDTProd(getCod());
	ContrVenta * cv = ContrVenta :: getInstance();
	TipoCantProducto * tcp = cv->obtenerTCPFact(getCod(), tp);
	return tcp;
}

//Baja Producto

bool ContrProducto :: noHayVenta(string cod) {
	ContrVenta * cv = ContrVenta :: getInstance();
	bool res = cv->noHayVenta(cod);
	return res;
}

void ContrProducto :: confirmarBajaProd() {
	map <string, ProdGral *> :: iterator itP;
	itP = prods.find(getCod());
	ProdGral * p = itP->second;
	prods.erase(itP->first);
	Simple * s = dynamic_cast<Simple*>(p);
	if (s != NULL) {
		map <string, Menu *> :: iterator itM;
		for (itM = menus.begin(); itM != menus.end(); ++itM) {
			bool vacio = itM->second->vaciadoMenu(s);
			if (vacio) {
				Menu * aBorrarM = itM->second;
				menus.erase(itM->first);
                    prods.erase(getCod());
				aBorrarM->~Menu();
			} else {
				itM->second->reCalcularPrecio(s);
			}
		}
		sim.erase(getCod());
		s->~Simple();
	} else {
		Menu * m = dynamic_cast<Menu*>(p);
		m->elimMenu();
		menus.erase(getCod());
		m->~Menu();
	}
}

//mas operaciones

TipoProducto * ContrProducto :: getDTProd(string cod) {
	map <string, ProdGral *> :: iterator it;
	it = prods.find(cod);
	TipoProducto * tp  = it->second->darDatosProd();
	return tp;
}

bool ContrProducto :: haySimple(string cod) {
	bool hs = false;
	map <string, Simple *> :: iterator it;
	it = sim.find(cod);
	if ((it != sim.end()) && (cod == it->first))
		hs = true;
	return hs;
}

bool ContrProducto :: hayProducto() {
	return (!prods.empty());
}








//----------------------------------------------------------------sobrecarga operador tipo simple
ostream& operator << (ostream &o, TipoSimple* m) {
  if (m != NULL){
    o << "Codigo: " << m->getCod() << "\n" << "Descripcion: " << m->getDescripcion() << "\n" << "Precio: " << m->getPrecio() << "\n"<<  endl;
  } else {
    o << " " << endl;
  }
  return o;
}
ostream& operator << (ostream &o,   set <TipoSimple *> r) {
  o<<"";
  set <TipoSimple *>::iterator it;

    for (it=r.begin(); it!=r.end(); ++it)
    { o<<"-------"<<"\n";
      o << *it;
    }
  
  return o;}



//----------------------------------------------------------------sobrecarga operador tipo producto
ostream& operator << (ostream &o, TipoProducto* m) {
  if (m != NULL){
    o << "Codigo: " << m->getCod() << "\n" << "Descripcion: " << m->getDescripcion() << "\n" << endl;
  } else {
    o << " " << endl;
  }
  return o;
}

  ostream& operator << (ostream &o,   set <TipoProducto *> r) {
  o<<"";
  set <TipoProducto *>::iterator it;

    for (it=r.begin(); it!=r.end(); ++it)
    { o<<"-------"<<"\n";
      o << *it;
    }
  
  return o;}


//----------------------------------------------------------------sobrecarga operador tipo menu

ostream& operator << (ostream &o, 	TipoCantProdMenu* m) {
   if (m != NULL){
    o << m->getTipoS() << "\n" << "Cantidad: " << m->getCant() << "\n"<<  endl;
  } else {
    o << " " << endl;
  }
  return o;
}

ostream& operator << (ostream &o, 	set<TipoCantProdMenu *> r) {
  o<<"";
  	set<TipoCantProdMenu *>::iterator it;

    for (it=r.begin(); it!=r.end(); ++it)
    { o<<"-------"<<"\n";
      o << *it;
    }
  return o;
}
ostream& operator << (ostream &o, TipoMenu* m) {
  if (m != NULL){
    o << m->getProds() <<  endl;
  } else {
    o << " " << endl;
  }
  return o;
}


//----------------------------------------------------------------sobrecarga operador tipo cant producto menu

ostream& operator << (ostream &o, TipoCantProducto* m) {
	
	
  if (m != NULL){
  	TipoMenu * tm = dynamic_cast<TipoMenu*>(m->getTipoProducto());
     if (tm!=NULL)
     {	set<TipoCantProdMenu *> ps=tm->getProds();
       o << m->getTipoProducto() << "Precio: " << tm->getPrecio()<<"\n"<< "Cantidad: " << m->getCant() << "\n"<< "Productos : " <<"\n" << ps <<  endl;	
     }	
     else{
     	TipoSimple * tm = dynamic_cast<TipoSimple*>(m->getTipoProducto());
    	o << m->getTipoProducto() << "Precio: "<< tm->getPrecio()<<"\n"<<  "Cantidad: " << m->getCant() << "\n"<<  endl;
    }
  } else {
    o << " " << endl;
  }
  return o;
}
