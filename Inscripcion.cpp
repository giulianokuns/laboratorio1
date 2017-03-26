/* Implementacion clase Inscripcion */
#include "Inscripcion.h"
#include <iostream>
#include <cstring>
#include <string.h>
#include <stdexcept>
#include "Fecha.h"
#include "Socio.h"

/* Constructor y destructor */
Inscripcion::Inscripcion(Fecha fecha, Socio *socio){
	this->fecha = Fecha(fecha.getDia(), fecha.getMes(), fecha.getAnio());
	this->socio = socio;
};

Inscripcion::~Inscripcion() {};
/* Fin constructor y desctructor */

/* Getters and Setters */

Fecha Inscripcion::getFecha() {
	return this->fecha;
};

Socio * Inscripcion::getSocio() {
	return this->socio;
};

void Inscripcion::setFecha(Fecha fecha) {
	this->fecha = Fecha(fecha.getDia(), fecha.getMes(), fecha.getAnio());
};
void Inscripcion::setSocio(Socio *socio) {
	this->socio = socio;
};

/* Fin Getters and Setters */
  