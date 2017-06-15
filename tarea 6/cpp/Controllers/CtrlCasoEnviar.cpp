#include "CtrlUsuario.h"
#include "Mensaje.h"
#include "Usuario.h"

// Singleton
CtrlCasoEnviar * CtrlCasoEnviar::getInstancia(){
	if (instancia == NUL)
		this->instancia = new CtrlCasoEnviar;
	return instancia;
}

int CtrlCasoEnviar::cantidadArchivadas(){
	CtrlUsuario:: *ctrl = getInstancia();
	return this->ctrl.cantidadArchivadas();
}

ICollection * CtrlCasoEnviar::listarArchivadas(){
	CtrlUsuario:: *ctrl = getInstancia(),
	return this->ctrl.listarArchivadas();
}
	   
ICollection * CtrlCasoEnviar::listarActivas(){
	CtrlUsuario:: *ctrl = getInstancia();
	return this->ctrl.listarActivas();
}

 string * CtrlCasoEnviar::crearConvrsacion(string idContact){
   
 }