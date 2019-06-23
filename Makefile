# --------------------------------------------------------------------

# Objetivo predeterminado (no se necesita especificarlo al invocar `make').
all:principal 
	@./principal
.PHONY: all clean_bin clean_test clean 
	# compilador
CC = g++
# opciones de compilación
CCFLAGS = -Wall -Werror -I$(HDIR) -g -DNDEBUG




principal:restofing.cpp TipoEmpleado.o tipoMesa.o Empleado.o Mozo.o Mesa.o Repartidor.o ContrEmpleado.o cantProdMenu.o CantProducto.o Cliente.o ContrVenta.o Domicilio.o Factura.o factory.o Venta.o tipoSimple.o tipoRepartidor.o tipoProducto.o tipoMozo.o tipoMozo.o tipoMesaMozo.o tipoMenu.o TipoHora.o TipoFecha.o tipofactura.o TipoDireccionApart.o TipoDireccionApart.o tipodireccion.o tipocliente.o tipoCantProducto.o tipoCantProdMenu.o tipoactualizacion.o simple.o prodGral.o menu.o Local.o IVentaADomicilio.h iQuitarProductoAUnaVenta.h ObserverDomicilio.h iModificarEstadoPedido.h iIniciarVentaEnMesas.h iInformacionDeUnProducto.h IFacturacionDeUnDia.h iFacturacionDeUnaVenta.h iConsultarPedidoCliente.h iConsultarPedidoAdmin.h iBajaProducto.h iAgregarProductoAUnaVenta.h iAltaEmpleado.h iAsignarMozosAMesas.h iAltaProducto.h Factura.o factory.o ContrVenta.o Domicilio.o contrProducto.o Cliente.o CantProducto.o cantProdMenu.o TipoDomicilio.o
	$(CC) $(CCFLAGS) $^ -o $@
	@./principal

TipoEmpleado.o:TipoEmpleado.cpp
	$(CC) $(CCFLAGS) -c $^	
Venta.o:Venta.cpp
	$(CC) $(CCFLAGS) -c $^
tipoSimple.o:tipoSimple.cpp
	$(CC) $(CCFLAGS) -c $^
tipoRepartidor.o:tipoRepartidor.cpp
	$(CC) $(CCFLAGS) -c $^
tipoProducto.o:tipoProducto.cpp
	$(CC) $(CCFLAGS) -c $^
tipoMozo.o:tipoMozo.cpp
	$(CC) $(CCFLAGS) -c $^
tipoMesa.o:tipoMesa.cpp
	$(CC) $(CCFLAGS) -c $^
tipoMesaMozo.o:tipoMesaMozo.cpp
	$(CC) $(CCFLAGS) -c $^
tipoMenu.o:tipoMenu.cpp
	$(CC) $(CCFLAGS) -c $^
TipoHora.o:TipoHora.cpp
	$(CC) $(CCFLAGS) -c $^
TipoFecha.o:TipoFecha.cpp
	$(CC) $(CCFLAGS) -c $^
tipofactura.o:tipofactura.cpp
	$(CC) $(CCFLAGS) -c $^
TipoDireccionApart.o:TipoDireccionApart.cpp
	$(CC) $(CCFLAGS) -c $^
tipodireccion.o:tipodireccion.cpp
	$(CC) $(CCFLAGS) -c $^
tipocliente.o:tipocliente.cpp
	$(CC) $(CCFLAGS) -c $^
tipoCantProducto.o:tipoCantProducto.cpp
	$(CC) $(CCFLAGS) -c $^
tipoCantProdMenu.o:tipoCantProdMenu.cpp
	$(CC) $(CCFLAGS) -c $^
tipoactualizacion.o:tipoactualizacion.cpp
	$(CC) $(CCFLAGS) -c $^
simple.o:simple.cpp
	$(CC) $(CCFLAGS) -c $^
prodGral.o:prodGral.cpp
	$(CC) $(CCFLAGS) -c $^
menu.o:menu.cpp
	$(CC) $(CCFLAGS) -c $^
Local.o:Local.cpp
	$(CC) $(CCFLAGS) -c $^
Factura.o:Factura.cpp
	$(CC) $(CCFLAGS) -c $^
factory.o:factory.cpp
	$(CC) $(CCFLAGS) -c $^
ContrVenta.o:ContrVenta.cpp
	$(CC) $(CCFLAGS) -c $^
Domicilio.o:Domicilio.cpp
	$(CC) $(CCFLAGS) -c $^
contrProducto.o:contrProducto.cpp
	$(CC) $(CCFLAGS) -c $^
Cliente.o:Cliente.cpp
	$(CC) $(CCFLAGS) -c $^
CantProducto.o:CantProducto.cpp	
	$(CC) $(CCFLAGS) -c $^
cantProdMenu.o:cantProdMenu.cpp
	$(CC) $(CCFLAGS) -c $^

Empleado.o:Empleado.cpp 
	$(CC) $(CCFLAGS) -c $^ 

Mozo.o:Mozo.cpp 
	$(CC) $(CCFLAGS) -c $^ 

Mesa.o:Mesa.cpp 
	$(CC) $(CCFLAGS) -c $^ 

Repartidor.o:Repartidor.cpp 
	$(CC) $(CCFLAGS) -c $^ 

ContrEmpleado.o:ContrEmpleado.cpp
	$(CC) $(CCFLAGS) -c $^ 

TipoDomicilio.o:TipoDomicilio.cpp
	$(CC) $(CCFLAGS) -c $^ 
# borra binarios
clean_bin:
	@rm -f principal


# borra binarios, resultados de ejecución y comparación, y copias de respaldo
clean:clean_bin
	@rm -f *~ $(HDIR)/*~ 
	@rm -f *.o 
	@rm -f *.h.gch 
	@clear

check-syntax:
	gcc -o nul -S ${CHK_SOURCES}
