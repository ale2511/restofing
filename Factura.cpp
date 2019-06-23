
#include "Factura.h"

using namespace std;


Factura :: Factura(string nro, map<string, CantProducto*> prods, TipoFecha* fechita, TipoHora* horita, float sub_total, float descuentillo, float precio_sin_iva, float totalcompra, TipoEmpleado * f){
	nroFactura = nro;
	fecha = fechita;
	hora = horita;
	subtotal = sub_total;
	descuento = descuentillo;
	precioSinIva = precio_sin_iva;
	total = totalcompra;
	map<string, CantProducto*> :: iterator it;
	for (it=prods.begin(); it != prods.end(); ++it){
		productos.insert(*it);
	}
	empleado = f;
}
string Factura :: getNrofactura(){
	 return nroFactura;
}

set<string> Factura :: mostrarCodProds() {
	set <string> result;
	map <string, CantProducto *> :: iterator it;
	for (it = productos.begin(); it!= productos.end(); ++it) {
		string s = it->second->getCodProdGral();
		result.insert(s);
	}
	return result;
}

set<int> Factura :: mostrarCantProds() {
	set <int> result;
	map <string, CantProducto *> :: iterator it;
	for (it = productos.begin(); it!= productos.end(); ++it) {
		int s = it->second->getCant();
		result.insert(s);
	}
	return result;
}

TipoFecha* Factura :: getFecha(){
	return fecha;
}

TipoHora* Factura :: getHora(){
	return hora;
}

float Factura :: getSubtotal() {
	return subtotal;
}

float Factura :: getDescuento() {
	return descuento;
}

float Factura :: getPreciosSinIva() {
	return precioSinIva;
}
 
 float Factura :: getTotal(){
	 return total;
 }
 
TipoEmpleado* Factura :: getEmpleado() {
	return empleado;
}
 

TipoCantProducto * Factura :: verProdsFacturados(string cod, TipoCantProducto * tcp) {
	map <string, CantProducto *> :: iterator it;
	it = productos.find(cod);
	if((it != productos.end()) && (it->first == cod))
		tcp->setCant(tcp->getCant() + it->second->getCant());
	return tcp;
}