#include "Conversacion.h"
#include "FechaSistema.h"
#include "HoraSistema.h"


Conversacion::Conversacion(bool visto, String idConversacion, bool esGrupo, Grupo grupo, Usuario receptor, IDictionary mensajes){
	this->visto 			= visto;
	this->idConversacion 	= idConversacion;
	this->esGrupo 			= esGrupo;
	this->grupo 			= grupo;
	this->receptor 			= receptor;
	this->mensajes 			= mensajes;
}

bool Conversacion::getvisto(){
	return visto;
}
String Conversacion::getidConversacion(){
	return idConversacion;
}
bool Conversacion::getesGrupo(){
	return esGrupo;
}
Grupo Conversacion::getgrupo(){
	return grupo;
}
Usuario Conversacion::getreceptor(){
	return receptor;
}
IDictionary Conversacion::getMensajes() {
	return mensajes;
}

void Conversacion::setvisto(bool visto){
	this->visto = visto;
}
void Conversacion::setidConversacion(String ID){
	this->idConversacion = ID;
}
void Conversacion::setesGrupo(bool esgrupo){
	this->esGrupo = esgrupo;
}
void Conversacion::setgrupo(Grupo g){
	this->grupo = grupo;
}
void Conversacion::setreceptor(Usuario u){
	this->receptor = receptor;
}
void Conversacion::setMensajes(IDictionary mensajes) {
	this->mensajes = mensajes;
}

/* Archivar conversacion */
DtConversacion Conversacion::getinfo(){
	DtConversacion *dtc;
	if(getesGrupo()){
		Grupo g = getgrupo();
		dtc = new DtConversacion(true, g->getnomGrupo(), 0000, getidConversacion());
	}
	else{
		Usuario u = getreceptor();
		dtc = new DtConversacion(false, u->getnomUsuario, u->gettelCel, getidConversacion());
	}
	return dtc;
}

ICollection Conversacion::obtenerMensajesGrupo() {
	Usuario user_log = CtrlUsuario::getusuarioLog();

	Grupo * g = this->getgrupo();
	IDictionary InfoIngreso * info_ingreso = g->getFechaHoraIngreso();

}

ICollection Conversacion::obtenerMensajesConv() {
	IDictionary arr_mensj = this->getMensajes();
	ICollection lista_mensajes = new list();
	Usuario user_log = CtrlUsuario::getusuarioLog();

	for (IIterator *it = arr_mensj->getIterator(); it->hasCurrent(); it->next()) {
		Mensaje m = getCurrent();
		DtMensaje mensaje = m->darMensaje();
		// Agrego el mensaje a la lista de mensajes a retornar.
		lista_mensajes->add(mensaje);

		if (dynamic_cast<Simple*> (&this) != NULL) {
			//Es Simple
		} else if (dynamic_cast<Contacto*> (&this) != NULL) {
			//Es Contacto
		} else {
			//Es Multimedia
			if (dynamic_cast<Imagen*> (&this) != NULL) {
				//Es Imagen
			} else {
				//Es Video
			}
		}
		
		// Marco el mensaje como visto.
		IDictionary recibidos = m->getRecibidos();		
		for (IIterator *it_r = recibidos->getIterator(); it_r->hasCurrent(); it_r->next()) {
			Recibido r = getCurrent();
			Usuario * user = r->getUsuario();
			if (user_log->gettelCel() == user->gettelCel()) {
				Fecha fecha_visto = new Fecha (FechaSistema::getDia(), FechaSistema::getMes(), FechaSistema::getAnio());
				Hora Hora_visto   = new Hora (HoraSistema::getHora(), HoraSistema::getMinutos());
				
				r->setVisto(true);		
				r->setFechaVisto(fecha_visto);
				r->setHoraVisto(Hora_visto);
			}
		}
	}

}














