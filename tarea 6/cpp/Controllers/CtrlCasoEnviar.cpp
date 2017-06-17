#include "CtrlUsuario.h"
#include "Mensaje.h"
#include "Usuario.h"
#include "CtrlCasoEnviar.h"
#include "Recibido.h"
#include "EstadoConversacion.h"
#include "IDictionary.h"
#include "IKey"

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
    CtrlUsuario *ctrl = CtrlUsuario::getInstancia();
    Usuario log = ctrl->getusuarioLog();
    IDictionary ec_ar = log->getarreglo_ec();
    EstadoConversacion *ec;
    bool encontrado = false;

    for (IIterator *it = ec_ar->getIterator(); (it->hasCurrent() && !encontrado); it->next()){
           ec = dynamic_cast< EstadoConversacion*> it->getCurrent();
           if (!ec->getarchivada()){
              Conversacion c = ec->getconversacion();
              if (idActiva->compare(c.getidConversacion())){
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
    CtrlUsuario *ctrl = CtrlUsuario::getInstancia();
    Usuario log = ctrl->getusuarioLog();
    IDictionary ec_ar = log->getarreglo_ec();
    EstadoConversacion *ec;
    bool encontrado = false;

    for (IIterator *it = ec_ar->getIterator(); (it->hasCurrent() && !encontrado); it->next()){
           ec = dynamic_cast< EstadoConversacion*> it->getCurrent();
           if (ec->getarchivada()){
              Conversacion c = ec->getconversacion();
              if (idArchi->compare(c.getidConversacion())){
                encontrado = true;
                this->idConver = idArchi;
              }
                
           }
    }
    if (!encontrado)
    // lanzar una excepción
        return false;      
}

void ingresarIDContacto(IKey tel){
    CtrlUsuario *ctrl = CtrlUsuario::getinstancia();
    Usuario log = ctrl->getusuarioLog();
    IDictionary contacts = log->getcontactos();
    bool pertenece = contacts->member(tel);
    if (pertenece)
        this->idContact = tel;
    else{
        //lanzar excepción
        return false;
    }

}

void crearMensajeContact(String tel, IKey codigo, Fecha fechaSist, Hora horaSist){
  CtrlUsuario *ctrl = CtrlUsuario::getinstancia();
  Usuario log = ctrl->getusuarioLog();

  //Busco el usuario del cual voy a enviar la información
  //Este usuario es contacto de log
  IDictionary contacts = log->getcontactos();
  IKey *i = new String(tel);
  Usuario *u = dynamic_cast< Usuario* > contacts.find(i);
  
  //Se busca el estado de conversacion y se obtiene la conversacion.
  IDictionary ec_ar = log->getarreglo_ec();
  EstadoConversacion *estado = dynamic_cast< EstadoConversacion* > ec_ar.find(this->idConver);
  Conversacion c = estado->getconversacion();

  //Cambio el estado de conversacion de los usuarios a activa
  //si corresponde

  IDictionary participantes = c->getparticipantes();
  Usuario *u;
  for (IIterator *it = participantes->getIterator(); it->hasCurrent(); it->next()){
    u = dynamic_cast< Usuario*> it->getCurrent();
    IDictionary ec_arrParticipa = u->getarreglo_ec();
    EstadoConversacion *estadoConvU = dynamic_cast< EstadoConversacion* > ec_ar.find(this->idConver);
    // Si el estado de conversacion
    if (estado->getarchivada())
      estado->setarchivada(false);

     //Creo la colección de recibidos para el mensaje 
     //cuya ikey es el telCel de usuario asociado a r
     IDictionary recibidos = new OrderedDictionary();
     Recibido *r = new Recibido(u);
     recibidos->add(u->gettelCel, r);

  }

  //el código del mensaje es autogenerado por el sistema
  //necesito saber donde se va a obtener ese código
  //Se usa la coleccion recibidos como atributo de mensaje
  Mensaje m = new Contacto(codigo, fechaSist, horaSist, u->getnomUsuario(),tel,recibidos);

  //Se agrega el mensaje a la conversacion.

  IDictionary mensajes = c->getmensajes();
  mensajes->add(codigo, m);
  
}

void crearMensajeSimple(DtSimple simCont, IKey codigo, Fecha fechaSist, Hora horaSist){
  CtrlUsuario *ctrl = CtrlUsuario::getinstancia();
  Usuario log = ctrl->getusuarioLog();
  
  //Se busca el estado de conversacion y se obtiene la conversacion.
  IDictionary ec_ar = log->getarreglo_ec();
  EstadoConversacion *estado = dynamic_cast< EstadoConversacion* > ec_ar.find(this->idConver);
  Conversacion c = estado->getconversacion();

  //Cambio el estado de conversacion de los usuarios a activa
  //si corresponde

  IDictionary participantes = c->getparticipantes();
  Usuario *u;
  for (IIterator *it = participantes->getIterator(); it->hasCurrent(); it->next()){
    u = dynamic_cast< Usuario*> it->getCurrent();
    IDictionary ec_arrParticipa = u->getarreglo_ec();
    EstadoConversacion *estadoConvU = dynamic_cast< EstadoConversacion* > ec_ar.find(this->idConver);
    // Si el estado de conversacion
    if (estado->getarchivada())
      estado->setarchivada(false);

     //Creo la colección de recibidos para el mensaje 
     //cuya ikey es el telCel de usuario asociado a r
     IDictionary recibidos = new OrderedDictionary();
     Recibido *r = new Recibido(u);
     recibidos->add(u->gettelCel, r);

  }

  //el código del mensaje es autogenerado por el sistema
  //necesito saber donde se va a obtener ese código
  //Se usa la coleccion recibidos como atributo de mensaje
  Mensaje m = new Simple(codigo, fechaSist, horaSist, simCont, recibidos);

  //Se agrega el mensaje a la conversacion.

  IDictionary mensajes = c->getmensajes();
  mensajes->add(codigo, m);
  
}


void crearMensajeImagen(DtImagen dtImagen, IKey codigo, Fecha fechaSist, Hora horaSist){
  CtrlUsuario *ctrl = CtrlUsuario::getinstancia();
  Usuario log = ctrl->getusuarioLog();
  
  //Se busca el estado de conversacion y se obtiene la conversacion.
  IDictionary ec_ar = log->getarreglo_ec();
  EstadoConversacion *estado = dynamic_cast< EstadoConversacion* > ec_ar.find(this->idConver);
  Conversacion c = estado->getconversacion();

  //Cambio el estado de conversacion de los usuarios a activa
  //si corresponde

  IDictionary participantes = c->getparticipantes();
  Usuario *u;
  for (IIterator *it = participantes->getIterator(); it->hasCurrent(); it->next()){
    u = dynamic_cast< Usuario*> it->getCurrent();
    IDictionary ec_arrParticipa = u->getarreglo_ec();
    EstadoConversacion *estadoConvU = dynamic_cast< EstadoConversacion* > ec_ar.find(this->idConver);
    // Si el estado de conversacion
    if (estado->getarchivada())
      estado->setarchivada(false);

     //Creo la colección de recibidos para el mensaje 
     //cuya ikey es el telCel de usuario asociado a r
     IDictionary recibidos = new OrderedDictionary();
     Recibido *r = new Recibido(u);
     recibidos->add(u->gettelCel, r);

  }

  //el código del mensaje es autogenerado por el sistema
  //necesito saber donde se va a obtener ese código
  //Se usa la coleccion recibidos como atributo de mensaje
  Mensaje m = new Imagen(codigo, fechaSist, horaSist, dtImagen, recibidos);

  //Se agrega el mensaje a la conversacion.

  IDictionary mensajes = c->getmensajes();
  mensajes->add(codigo, m);
  
}


void crearMensajeVideo(DtVideo dtVideo, IKey codigo, Fecha fechaSist, Hora horaSist){
  CtrlUsuario *ctrl = CtrlUsuario::getinstancia();
  Usuario log = ctrl->getusuarioLog();
  
  //Se busca el estado de conversacion y se obtiene la conversacion.
  IDictionary ec_ar = log->getarreglo_ec();
  EstadoConversacion *estado = dynamic_cast< EstadoConversacion* > ec_ar.find(this->idConver);
  Conversacion c = estado->getconversacion();

  //Cambio el estado de conversacion de los usuarios a activa
  //si corresponde

  IDictionary participantes = c->getparticipantes();
  Usuario *u;
  for (IIterator *it = participantes->getIterator(); it->hasCurrent(); it->next()){
    u = dynamic_cast< Usuario*> it->getCurrent();
    IDictionary ec_arrParticipa = u->getarreglo_ec();
    EstadoConversacion *estadoConvU = dynamic_cast< EstadoConversacion* > ec_ar.find(this->idConver);
    // Si el estado de conversacion
    if (estado->getarchivada())
      estado->setarchivada(false);

     //Creo la colección de recibidos para el mensaje 
     //cuya ikey es el telCel de usuario asociado a r
     IDictionary recibidos = new OrderedDictionary();
     Recibido *r = new Recibido(u);
     recibidos->add(u->gettelCel, r);

  }

  //el código del mensaje es autogenerado por el sistema
  //necesito saber donde se va a obtener ese código
  //Se usa la coleccion recibidos como atributo de mensaje
  Mensaje m = new Video(codigo, fechaSist, horaSist, dtVideo, recibidos);

  //Se agrega el mensaje a la conversacion.

  IDictionary mensajes = c->getmensajes();
  mensajes->add(codigo, m);
  
}

 

 

