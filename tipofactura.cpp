#include <string>
#include "tipofactura.h"

using namespace std;

TipoFactura :: TipoFactura(string nro, set<TipoCantProducto*> arreglo_prods, TipoFecha* diacompra, TipoHora* horacompra, float sub_total, float descuentillo, float sin_iva, float totalprecio, TipoEmpleado * f){
	nrofactura = nro;
	fecha = diacompra;
	hora = horacompra;
	subtotal = sub_total;
	descuento = descuentillo;
	preciosiniva = sin_iva;
	total = totalprecio;
	productos = arreglo_prods;
	empleado = f;
}

string TipoFactura :: getNrofactura(){
	return nrofactura;
}

set<TipoCantProducto*> TipoFactura :: getProductos() {
	return productos;
}


TipoFecha* TipoFactura :: getFecha(){
	return fecha;
}

TipoHora* TipoFactura :: getHora(){
	return hora;
}

float TipoFactura :: getSubtotal(){
	return subtotal;
}

float TipoFactura :: getDescuento(){
	return descuento;
}

float TipoFactura :: getPreciosiniva(){
	return preciosiniva;
}

float TipoFactura :: getTotal(){
	return total;
}
 
TipoEmpleado* TipoFactura :: getEmpleado() {
	return empleado;
}