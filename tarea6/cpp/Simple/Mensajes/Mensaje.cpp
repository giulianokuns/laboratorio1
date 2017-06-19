#include "../../../h/Simple/Mensaje/Mensaje.h"

IKey Mensaje::getcodigo(){
	return *codigo;
}
Fecha Mensaje::getfechaMensaje(){
	return *fechaMensaje;
}
Hora Mensaje::gethoraMensaje(){
	return *horaMensaje;
}
IDictionary Mensaje::getRecibidos() {
	return *recibidos;
}

void Mensaje::setcodigo(IKey *codigo){
	this->codigo = codigo;
}
void Mensaje::setfechaMensaje(Fecha *fechaMensaje){
	this->fechaMensaje = fechaMensaje;
}
void Mensaje::sethoraMensaje(Hora *horaMensaje){
	this->horaMensaje = horaMensaje;
}
void Mensaje::setRecibidos(IDictionary recibidos) {
	this->recibidos = recibidos;
}

bool Mensaje::validarFechaHoraMensaje(DtInfoIngreso fecha_hora_ingreso) {
	if (this->getfechaMensaje() > fecha_hora_ingreso.getFechaIngreso()) {
		return true;
	} else if (this->getfechaMensaje() == fecha_hora_ingreso.getFechaIngreso()) {
		//Depende de la hora
		if (this->gethoraMensaje() > fecha_hora_ingreso.getHoraIngreso() || 
			this->gethoraMensaje() == fecha_hora_ingreso.getHoraIngreso()) {	
			return true;
		} else {	
			return false;
		}
	} else {
		return false;
	}
}

ICollection Mensaje::getReceptores() {
	IDictionary recibidos = this->getRecibidos();
	ICollection receptores = new List();
	
	for (IIterator *it = recibidos->getIterator(); it->hasCurrent(); it->next()) {
		Recibido * r = dynamic_cast<Recibido * > (it->getCurrent());
		Fecha fechaVisto = r->getFechaVisto();
		Hora horaVisto 	 = r->getHoraVisto();
		Usuario *usuario  = r->getUsuario();

		string nombre  	 = usuario->getnomUsuario();
		IKey telCel  	 = usuario->gettelCel();

		DtReceptor receptor = DtReceptor::DtReceptor(nombre, telCel, fechaVisto, horaVisto);
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