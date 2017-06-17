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
	CtrlUsuario *ctrl = CtrlUsuario::getinstancia();
	return this->ctrl.cantidadArchivadas();
}

ICollection * CtrlCasoEnviar::listarArchivadas(){
	CtrlUsuario *ctrl = CtrlUsuario::getinstancia(),
	return this->ctrl.listarArchivadas();
}
	   
ICollection * CtrlCasoEnviar::listarActivas(){
	CtrlUsuario *ctrl = CtrlUsuario::getinstancia();
	return this->ctrl.listarActivas();
}

ICollection * listarContactos(){
	CtrlUsuario *ctrl = CtrlUsuario::getinstancia();
	return this->ctrl.getInfoContactos();
}

// El idConver ingresado es el id de conversación autogenerado
//por el sistema. Se debe setear este idConver para la posterior creación
// de un mensaje en la operación crearMensaje.

void CtrlCasoEnviar::crearConversacion(IKey tel, IKey idConver) {
   CtrlUsuario *ctrl = CtrlUsuario::getInstancia();
   this->idConver = ctrl->crearConversacion(tel, idConver);
}

void ingresarIDActiva(IKey idActiva){
	CtrlUsuario *ctrl = CtrlUsuario::getinstancia();
	Usuario log = ctrl->getusuarioLog();
	IDictionary ec_ar = log->getarreglo_ec();
	EstadoConversacion *ec;
	bool encontrado = false;

	for (IIterator *it = ec_ar->getIterator(); (it->hasCurrent() && !encontrado); it->next()){
           ec = dinamic_cast< EstadoConversacion*> it->getCurrent();
           if (!ec->getarchivada()){
              Conversacion c = ec->getconversacion();
              if (compararConversaciones(c.getidConversacion(),idActiva)){
              	encontrado = true;
              	this->idConver = idActiva
              }
              	
           }
    }
    if (!encontrado)
    // lanzar una excepción
        return false;      
}

void ingresarIDArchi(IKey idArchi){
	CtrlUsuario *ctrl = CtrlUsuario::getinstancia();
	Usuario log = ctrl->getusuarioLog();
	IDictionary ec_ar = log->getarreglo_ec();
	EstadoConversacion *ec;
	bool encontrado = false;

	for (IIterator *it = ec_ar->getIterator(); (it->hasCurrent() && !encontrado); it->next()){
           ec = dinamic_cast< EstadoConversacion*> it->getCurrent();
           if (ec->getarchivada()){
              Conversacion c = ec->getconversacion();
              //compararConversaciones es una operación que tiene que estar en conversacion
              //o estar en un controlador de conversaciones.
              if (compararConversaciones(c.getidConversacion(),idArchi)){
              	encontrado = true;
              	this->idConver = idArchi;
              }
              	
           }
    }
    if (!encontrado)
    // lanzar una excepción
        return false;      
}


void ingresarIDContacto(IKey idContact){
	CtrlUsuario *ctrl = CtrlUsuario::getinstancia();
	Usuario log = ctrl->getusuarioLog();
	IDictionary contacts = log->getcontactos();
	bool pertenece = contacts->member(idContact);
	if (pertenece)
		this->idContact = idContact;
	else{
		//lanzar excepción
		return false;
	}

}

