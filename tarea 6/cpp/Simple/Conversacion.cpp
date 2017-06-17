#include "Conversacion.h"
#include "FechaSistema.h"
#include "HoraSistema.h"
#include "DtSimple.h"
#include "DtContacto.h"
#include "DtVideo.h"
#include "DtImagen.h"
#include "DtMultimedia.h"


Conversacion::Conversacion(bool visto, IKey idConversacion, bool esGrupo, Grupo grupo, IDictionary participantes, IDictionary mensajes){
	this->visto 			= visto;
	this->idConversacion 	= idConversacion;
	this->esGrupo 			= esGrupo;
	this->grupo 			= grupo;
	this->participantes 	= participantes;
	this->mensajes 			= mensajes;
}

bool Conversacion::getvisto(){
	return visto;
}
IKey Conversacion::getidConversacion(){
	return idConversacion;
}
bool Conversacion::getesGrupo(){
	return esGrupo;
}
Grupo Conversacion::getgrupo(){
	return grupo;
}
IDictionary Conversacion::getparticipantes(){
	return participantes;
}
IDictionary Conversacion::getMensajes() {
	return mensajes;
}

void Conversacion::setvisto(bool visto){
	this->visto = visto;
}
void Conversacion::setidConversacion(IKey ID){
	this->idConversacion = ID;
}
void Conversacion::setesGrupo(bool esgrupo){
	this->esGrupo = esgrupo;
}
void Conversacion::setgrupo(Grupo g){
	this->grupo = grupo;
}
void Conversacion::setparticipantes(IDictionary participantes){
	this->participantes = participantes;
}
void Conversacion::setMensajes(IDictionary mensajes) {
	this->mensajes = mensajes;
}

/* Archivar conversacion */
DtConversacion Conversacion::getinfo(){
	DtConversacion *dtc;
	if(getesGrupo()){
		Grupo *g = getgrupo();
		dtc = new DtConversacion(true, g->getnomGrupo(), 0000, getidConversacion());
	}
	else{
		IDictionary *participantes =	getparticipantes();
		IIterator *it = participantes->getIterator();
		Usuario *u = getCurrent();
		dtc = new DtConversacion(false, u->getnomUsuario, u->gettelCel, getidConversacion());
	}
	return dtc;
}

ICollection Conversacion::obtenerMensajesGrupo() {
	CtrlUsuario *CI = getinstancia();
	Usuario * user_log = CI->getusuarioLog();
	ICollection lista_mensajes = new list();
	Grupo * g = this->getgrupo();

	//Buscamos la fecha y hora de ingreso del usuario logeado al Grupo
	IDictionary arr_info_ingresos = g->getInfoIngresos();
	bool encontrado = false;

	for (IIterator *it = arr_info_ingresos->getIterator(); (it->hasCurrent() && !encontrado); it->next()) {
		InfoIngreso * info_i = getCurrent();
		Usuario * usuario = info_i->getUsuario();
		if (user_log->gettelCel() == usuario->gettelCel()) {
			DtInfoIngreso fecha_hora_ingreso = new DtInfoIngreso(info_i->getfechaIngreso(), info_i->gethoraIngreso());
			encontrado = true;
		}
	}

	//Obtenemos los mensajes de la conversacion.
	IDictionary arr_mensj = this->getMensajes();
	for (IIterator *it = arr_mensj->getIterator(); it->hasCurrent(); it->next()) {
		Mensaje * m = getCurrent();

		bool es_valido = m->validarFechaHoraMensaje(fecha_hora_ingreso);
		if (es_valido) {
			if (dynamic_cast<Simple*> (&m) != NULL) {
				//Es Simple
				DtSimple mensaje = new DtSimple(
											m->getcodigo(), 
											m->getfechaMensaje(), 
											m->gethoraMensaje(), 
											m->getTextSimp()
										);
			} else if (dynamic_cast<Contacto*> (&m) != NULL) {
				//Es Contacto
				DtContacto mensaje = new DtContacto(
												m->getcodigo(), 
												m->getfechaMensaje(), 
												m->gethoraMensaje(), 
												m->getNomContacto(), 
												m->getTelContacto()
											);
			} else {
				//Es Multimedia
				if (dynamic_cast<Imagen*> (&m) != NULL) {
					//Es Imagen
					DtImagen mensaje = new DtImagen(
												m->getcodigo(), 
												m->getfechaMensaje(), 
												m->gethoraMensaje(), 
												m->getFormato(),
												m->getTamanio(),
												m->getTextMulti(),
												m->getURLpicture(),
											);
				} else {
					//Es Video
					DtVideo mensaje = new DtVideo(
											m->getcodigo(), 
											m->getfechaMensaje(), 
											m->gethoraMensaje(), 
											m->getDuracion(),
											m->getURLvideo()
										);
				}
			}
			
			// Agrego el mensaje a la lista de mensajes a retornar.
			lista_mensajes.add(mensaje);

			// Marco el mensaje como visto.
			IDictionary recibidos = m->getRecibidos();		
			for (IIterator *it_r = recibidos->getIterator(); it_r->hasCurrent(); it_r->next()) {
				Recibido * r = getCurrent();
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
}

ICollection Conversacion::obtenerMensajesConv() {
	CtrlUsuario *CI = CtrlUsuario::getinstancia();
	Usuario * user_log = CI->getusuarioLog();
	
	IDictionary arr_mensj = this->getMensajes();
	ICollection lista_mensajes = new list();

	for (IIterator *it = arr_mensj->getIterator(); it->hasCurrent(); it->next()) {
		Mensaje * m = getCurrent();
		//DtMensaje mensaje = m->darMensaje();

		if (dynamic_cast<Simple*> (&m) != NULL) {
			//Es Simple
			DtSimple mensaje = DtSimple::DtSimple(
											m->getcodigo(), 
											m->getfechaMensaje(), 
											m->gethoraMensaje(), 
											m->getTextSimp()
										);
		} else if (dynamic_cast<Contacto*> (&m) != NULL) {
			//Es Contacto
			DtContacto mensaje = DtContacto::DtContacto(
													m->getcodigo(), 
													m->getfechaMensaje(), 
													m->gethoraMensaje(), 
													m->getNomContacto(), 
													m->getTelContacto()
												);
		} else {
			//Es Multimedia
			if (dynamic_cast<Imagen*> (&m) != NULL) {
				//Es Imagen
				DtImagen mensaje = DtImagen::DtImagen(
												m->getcodigo(), 
												m->getfechaMensaje(), 
												m->gethoraMensaje(), 
												m->getFormato(),
												m->getTamanio(),
												m->getTextMulti(),
												m->getURLpicture(),
											);
			} else {
				//Es Video
				DtVideo mensaje = DtVideo::DtVideo(
												m->getcodigo(), 
												m->getfechaMensaje(), 
												m->gethoraMensaje(), 
												m->getDuracion(),
												m->getURLvideo()
											);
			}
		}
		
		// Agrego el mensaje a la lista de mensajes a retornar.
		lista_mensajes.add(mensaje);

		// Marco el mensaje como visto.
		IDictionary recibidos = m->getRecibidos();		
		for (IIterator *it_r = recibidos->getIterator(); it_r->hasCurrent(); it_r->next()) {
			Recibido * r = getCurrent();
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