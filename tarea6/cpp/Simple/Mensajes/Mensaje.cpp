#include "../../../h/Simple/Mensaje/Mensaje.h"

IKey *Mensaje::getcodigo(){
	return codigo;
}
Fecha *Mensaje::getfechaMensaje(){
	return fechaMensaje;
}
Hora *Mensaje::gethoraMensaje(){
	return horaMensaje;
}
IDictionary *Mensaje::getRecibidos() {
	return recibidos;
}

void Mensaje::setcodigo(IKey *codigo){
	this->codigo = codigo;
}
void Mensaje::setfechaMensaje(Fecha *fechaMensaje){
	this->fechaMensaje = new Fecha(fechaMensaje->getdia(), fechaMensaje->getmes(), fechaMensaje->getanio());
}
void Mensaje::sethoraMensaje(Hora *horaMensaje){
	this->horaMensaje = new Hora(horaMensaje->gethoras(), horaMensaje->getminutos());
}
void Mensaje::setRecibidos(IDictionary *recibidos) {
	this->recibidos = recibidos;
}

bool Mensaje::validarFechaHoraMensaje(DtInfoIngreso fecha_hora_ingreso) {
	/*if (this->getfechaMensaje() > fecha_hora_ingreso.getFechaIngreso()) {
		return true;
	} else if (this->getfechaMensaje() == *fecha_hora_ingreso.getFechaIngreso()) {
		//Depende de la hora
		if (this->gethoraMensaje() > *fecha_hora_ingreso.getHoraIngreso() || 
			this->gethoraMensaje() == *fecha_hora_ingreso.getHoraIngreso()) {	
			return true;
		} else {	
			return false;
		}
	} else {
		return false;
	}*/
	if (this->getfechaMensaje()->getanio() > fecha_hora_ingreso.getFechaIngreso().getanio()) {
		return true;		
	} else if (this->getfechaMensaje()->getanio() < fecha_hora_ingreso.getFechaIngreso().getanio()) {
		return false;
	} else {
		if (this->getfechaMensaje()->getmes() > fecha_hora_ingreso.getFechaIngreso().getmes()) {
			return true;
		} else if (this->getfechaMensaje()->getmes() < fecha_hora_ingreso.getFechaIngreso().getmes()) {
			return false;
		} else {
			if (this->getfechaMensaje()->getdia() > fecha_hora_ingreso.getFechaIngreso().getdia()) {
				return true;
			} else if (this->getfechaMensaje()->getdia() < fecha_hora_ingreso.getFechaIngreso().getdia()) {
				return false;
			} else {
				if (this->gethoraMensaje()->gethoras() > fecha_hora_ingreso.getHoraIngreso().gethoras()) {
					return true;
				} else if (this->gethoraMensaje()->gethoras() < fecha_hora_ingreso.getHoraIngreso().gethoras()) {
					return false;
				} else {
					if (this->gethoraMensaje()->getminutos() >= fecha_hora_ingreso.getHoraIngreso().getminutos()) {
						return true;
					} else {
						return false;
					}
				}
			}
		}
	}
}

ICollection *Mensaje::getReceptores() {
	IDictionary *recibidos = this->getRecibidos();
	ICollection *receptores = new List();
	
	for (IIterator *it = recibidos->getIterator(); it->hasCurrent(); it->next()) {
		Recibido r = dynamic_cast<Recibido * > (it->getCurrent());
		Fecha fechaVisto = r->getFechaVisto();
		Hora horaVisto 	 = r->getHoraVisto();
		Usuario *usuario  = r->getUsuario();

		string nombre  	 = usuario->getnomUsuario();
		IKey telCel  	 = usuario->gettelCel();

		DtReceptor receptor = new DtReceptor(nombre, telCel, fechaVisto, horaVisto);
		receptores.add(receptor);
	}

	return receptores
}

void Mensaje::eliminarMensajeEmisor(Conversacion * conversacion) {
	IDictionary * recibidos = this->getRecibidos();
	for (IIterator *it = recibidos->getIterator(); it->hasCurrent(); it->next()) {
		Recibido * r = dynamic_cast<Recibido * > (it->getCurrent());
		r->setEliminado(true);
	}

	IDictionary * mensajes = conversacion->getMensajes();
	mensajes->remove(this->getcodigo());

	delete this;
}

void Mensaje::eliminarMensajeReceptor() {
	IDictionary * recibidos = this->getRecibidos();
	CtrlUsuario *CI = CtrlUsuario::getinstancia();
	Usuario * user_log = CI->getusuarioLog();

	recibidos->remove(user_log->gettelCel());
}