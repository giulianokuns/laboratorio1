#include "DtContacto.h"
#include <iostream>
#include <cString>
#include <String.h>
#include <stdexcept>

using namespace std;

DtContacto::DtContacto (IKey codigo, Fecha fecha, Hora hora, String nom_contacto, String tel_cont) : DtMensaje (codigo, fecha, hora)  {
	this->dtCodigo 	 	= codigo;
	this->dtFecha 	 	= fecha;
	this->dtHora 	 	= hora;
	this->dtNomContacto = nom_contacto;
	this->dtTelContacto = tel_cont;
}

DtContacto::~DtContacto () {}

String  DtContacto::getNomContacto() {
	return dtNomContacto;
}

String  DtContacto::getTelContacto() {
	return dtTelContacto;
}