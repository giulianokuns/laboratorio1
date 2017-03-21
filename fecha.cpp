/* Implementacion clase Fecha */
#include "fecha.h";

/* Constructor y destructor */
Fecha::Fecha(int dia, int mes, int anio) {
	if (dia > 31 ||  dia < 1) {
		throw std::invalid_argument('Dia invalido');
	} else {
		this->dia = dia;
	}

	if (mes > 12 ||  mes < 1) {
		throw std::invalid_argument('Mes invalido');
	} else {
		this->mes = mes;		
	}
	
	if (anio < 1900) {
		throw std::invalid_argument('Año invalido');
	} else {
		this->anio = anio;
	}
};

Fecha::~Fecha() {};
/* Fin constructor y desctructor */

/* Getters and Setters */

int Estudiante::getDia() {
	return this->dia;
};
int Estudiante::getMes() {
	return this->mes;
};
int Estudiante::getAnio() {
	return this->anio;
};

/* Fin Getters and Setters */