#ifndef CONTRPRODUCTO_H 
#define	CONTRPRODUCTO_H

#include <string>
#include <cstdlib>
#include <iostream>
#include <map>
#include <set> 

#include "iAltaProducto.h"
#include "iInformacionDeUnProducto.h"
#include "iBajaProducto.h"
#include "ContrVenta.h"
using namespace std;

class ContrVenta;

class ContrProducto : public IAltaProducto, public IInformacionDeUnProducto, public IBajaProducto {
	private:
		static ContrProducto * instancia;
		ContrProducto(){};
		map <string, ProdGral *> prods;
		map <string, Simple *> sim;
		map <string, Menu *> menus;
		string codigo;;
		string descripcion;
		float precio;
		map <string, int> par;
	public:
		static ContrProducto * getInstance();
		//getters
		string getCod();
		string getDesc();
		float getPrecio();
		map <string, int> getPar();
		//setters
		void setCod(string);
		void setDesc(string);
		void setPrecio(float);
		void agregarPar(string, int);
		void borrarPares();
		//Alta Producto
		bool hayProdSim();
		bool noHayCodigo(string);
		void datosProdSim(string, float);
		void datosProdMenu(string);
		set <TipoSimple *> darProdSim();
		void ingrProdSim(string, int);
		void confirmarAltaProd(bool);
		//Informacion de un Producto
		set <TipoProducto *> darProds();
		bool productoValido(string);
		TipoCantProducto * verInfoProducto();
		//Baja Producto
		bool noHayVenta(string);
		void confirmarBajaProd();
		//mas operaciones
		TipoProducto * getDTProd(string);
		bool haySimple(string);
		bool hayProducto();
};

ostream& operator << (ostream &o, set <TipoProducto *> m);
ostream& operator << (ostream &o, TipoCantProducto* m);
ostream& operator << (ostream &o, set <TipoSimple *> m);

#endif