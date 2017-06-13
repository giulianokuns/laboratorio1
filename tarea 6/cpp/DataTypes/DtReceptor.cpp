#include "DtReceptor.h"
#include <string.h>

using namespace std;

DtReceptor::DtReceptor (string nombre, int num_cel, Fecha fecha_visto, hora hora_visto) {
	this->dtNombre 		= nombre;
	this->dtNumTel 		= num_cel;
	this->dtFechaVisto 	= fecha_visto;
	this->dtHoraVisto 	= hora_visto;
}

DtReceptor::~DtReceptor () {}

string DtReceptor::getNombre () {
	return dtNombre;
}

int DtReceptor::getNumTel () {
	return dtNumTel;
}
Fecha DtReceptor::getFechaVisto () {
	return dtFechaVisto;
}
Hora DtReceptor::getHoraVisto () {
	return dtHoraVisto;
}