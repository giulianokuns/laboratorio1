#include "CtrlUsuario.h"
#include "Mensaje.h"
#include "Usuario.h"
#include "CtrlCasoEnviar.h"

// Singleton
CtrlCasoEnviar * CtrlCasoEnviar::getInstancia() {
	if (instancia == NUL)
		this->instancia = new CtrlCasoEnviar;
	return instancia;
}

int CtrlCasoEnviar::cantidadArchivadas(){
	CtrlUsuario *ctrl = CtrlUsuario::getInstancia();
	return this->ctrl.cantidadArchivadas();
}

ICollection * CtrlCasoEnviar::listarArchivadas(){
	CtrlUsuario *ctrl = CtrlUsuario::getInstancia(),
	return this->ctrl.listarArchivadas();
}
	   
ICollection * CtrlCasoEnviar::listarActivas(){
	CtrlUsuario *ctrl = CtrlUsuario::getInstancia();
	return this->ctrl.listarActivas();
}

ICollection * listarContactos(){
	CtrlUsuario *ctrl = CtrlUsuario::getInstancia();
	return this->ctrl.getInfoContactos();
}

// El idConver ingresado es el id de conversación autogenerado
//por el sistema. Se debe setear este idConver para la posterior creación
// de un mensaje en la operación crearMensaje.

void CtrlCasoEnviar::crearConversacion(IKey tel, IKey idConver) {
   CtrlUsuario *ctrl = CtrlUsuario::getInstancia();
   this->idConver = ctrl->crearConversacion(tel, idConver);
}