
/* Clase Fecha */

/* Constructor y destructor */
Fecha::Fecha(int nuevo_dia, int nuevo_mes, int nuevo_anio) {
	if (new_dia > 31 ||  new_dia < 1) {
		throw std::invalid_argument;
	} else {
		dia = new_dia;
		
	}

	if (nuevo_mes > 12 ||  nuevo_mes < 1) {
		throw std::invalid_argument;
	} else {
		mes = nuevo_mes;		
	}
	if (nuevo_anio < 1900) {
		throw std::invalid_argument;
	} else {
		anio = nuevo_anio;
	}
};

Fecha::~Fecha() {};

int Estudiante::getDia() {
	return dia;
};
int Estudiante::getMes() {
	return mes;
};
int Estudiante::getAnio() {
	return anio;
};