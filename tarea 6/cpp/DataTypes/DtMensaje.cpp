#include <iostream>
#include <cstring>
#include <string.h>
#include <stdexcept>
#include "DtMensaje.h"

using namespace std;

int DtMensaje::getCodigo() const{
	return codigo;
}

Fecha DtMensaje::getFecha() const{
	return dtfecha;
}

Hora DtMensaje::getHora() const{
	return dthora;
}

void DtMensaje::setCodigo (int codigo) {
	this->dtcodigo = codigo;
}

void DtMensaje::setFecha (Fecha fecha) {
	this->dtfecha = fecha;
}

void DtMensaje::setHora (Hora hora) {
	this->dthora = hora;
}
