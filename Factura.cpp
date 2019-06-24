
#include "Factura.h"

using namespace std;


Factura :: Factura(string nro, map<string, TipoCantProducto*> prods, TipoFecha* fechita, TipoHora* horita, float sub_total, float descuentillo, float precio_sin_iva, float totalcompra, TipoEmpleado * f){
	nroFactura = nro;
	fecha = fechita;
	hora = horita;
	subtotal = sub_total;
	descuento = descuentillo;
	precioSinIva = precio_sin_iva;
	total = totalcompra;
	map<string, TipoCantProducto*> :: iterator it;
	for (it=prods.begin(); it != prods.end(); ++it){
		productos.insert(*it);
	}
	empleado = f;
}
string Factura :: getNrofactura(){
	 return nroFactura;
}

map<string, TipoCantProducto*> Factura :: mostrarTipoProds() {
	return productos;
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
	map <string, TipoCantProducto *> :: iterator it;
	it = productos.find(cod);
	if((it != productos.end()) && (it->first == cod))
		tcp->setCant(tcp->getCant() + it->second->getCant());
	return tcp;
}