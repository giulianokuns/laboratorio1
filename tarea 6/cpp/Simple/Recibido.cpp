#include <iostream>
#include <cString>
#include <String.h>
#include <stdexcept>
#include "Recibido.h"

Recibido::Recibido(Usuario u){
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

Usuario Recibido::getUsuario () {
	return usuario;
}

void Recibido::setVisto (bool visto) {
	this->visto = visto;
}

void Recibido::setEliminado (bool elim) {
	this->eliminado = elim;
}

void Recibido::setFechaVisto (Fecha fechaVisto) {
	this->fechaVisto = new Fecha(fechaVisto->getdia(), fechaVisto->getmes(), fechaVisto->getanio());
}

void Recibido::setHoraVisto (Hora horaVisto) {
	this->horaVisto = new Hora(horaVisto->gethoras(), horaVisto->getminutos());
}

void Recibido::setUsuario (Usuario usuario) {
	this->usuario = usuario;
}