/* Implementacion clase Inscripcion */
#include "inscripcion.h";

/* Constructor y destructor */
Inscripcion::Inscripcion(Fecha fecha, Socio *socio); {
	this->fecha = Fecha(getDia(fecha), getMes(fecha), getAnio(fecha));
	this->socio = socio;
};

Inscripcion::~Inscripcion() {};
/* Fin constructor y desctructor */

/* Getters and Setters */

Fecha Inscripcion::getFecha() {
	return this->fecha;
};

Socio Inscripcion::getSocio() {
	return this->socio;
};

void setFecha(Fecha fecha) {
	this->fecha = Fecha(getDia(fecha), getMes(fecha), getAnio(fecha));
};
void setSocio(Socio * socio) {
	this->socio = socio;
};

/* Fin Getters and Setters */