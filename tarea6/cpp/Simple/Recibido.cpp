#include <iostream>
#include <cstring>
#include <string.h>
#include <stdexcept>
#include "../../h/Simple/Recibido.h"

Recibido::Recibido(Usuario *u) : fechaVisto(FechaSistema::dia,FechaSistema::mes,FechaSistema::anio), horaVisto(HoraSistema::hora, HoraSistema::minutos){
	this->visto = false;
	this->eliminado = false;
	this->usuario = u;
}
Recibido::~Recibido(){
	
}

bool Recibido::getVisto() {
	return visto;
}

bool Recibido::getEliminado() {
	return eliminado;
}

Hora Recibido::getHoraVisto () {
	return horaVisto;

}

Fecha Recibido::getFechaVisto () {
	return fechaVisto;
}

Usuario* Recibido::getUsuario () {
	return usuario;
}

void Recibido::setVisto (bool visto) {
	this->visto = visto;
}

void Recibido::setEliminado (bool elim) {
	this->eliminado = elim;
}

void Recibido::setFechaVisto (Fecha fechaVisto) {
	this->fechaVisto = Fecha(fechaVisto.getdia(), fechaVisto.getmes(), fechaVisto.getanio());
}

void Recibido::setHoraVisto (Hora horaVisto) {
	this->horaVisto = Hora(horaVisto.gethoras(), horaVisto.getminutos());
}

void Recibido::setUsuario (Usuario *usuario) {
	this->usuario = usuario;
}
