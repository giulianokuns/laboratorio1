#include <iostream>
#include <cString>
#include <String.h>
#include <stdexcept>
#include "DtMensaje.h"

using namespace std;

int DtMensaje::getCodigo() const{
	return dtCodigo;
}

Fecha DtMensaje::getFecha() const{
	return dtFecha;
}

Hora DtMensaje::getHora() const{
	return dtHora;
}
