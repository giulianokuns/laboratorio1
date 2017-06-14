#include <iostream>
#include <cstring>
#include <string.h>
#include <stdexcept>
#include "Recibido.h"

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