#include <iostream>
#include <cstring>
#include <string.h>

#include "../../../h/DataTypes/Mensaje/DtContacto.h"

using namespace std;

DtContacto::DtContacto (IKey codigo, Fecha fecha, Hora hora, string nom_contacto, string tel_cont) : DtMensaje (codigo, fecha, hora)  {
	this->dtCodigo 	 	= codigo;
	this->dtFecha 	 	= fecha;
	this->dtHora 	 	= hora;
	this->dtNomContacto = nom_contacto;
	this->dtTelContacto = tel_cont;
}

DtContacto::~DtContacto () {}

string  DtContacto::getNomContacto() {
	return dtNomContacto;
}

string  DtContacto::getTelContacto() {
	return dtTelContacto;
}