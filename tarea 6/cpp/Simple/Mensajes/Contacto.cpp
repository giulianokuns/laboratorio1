#include <iostream>
#include <cString>
#include <String.h>
#include <stdexcept>

#include "Contacto.h"

using namespace std;

Contacto::Contacto (IKey codigo, Fecha fecha, Hora hora, String nom_contacto, String tel_cont) : Mensaje (codigo, fecha, hora)  {
	this->codigo 	 	= codigo;
	this->fecha 	 	= fecha;
	this->hora 	 		= hora;
	this->nomContacto 	= nom_contacto;
	this->telContacto 	= tel_cont;
}

Contacto::~Contacto () {}

String  Contacto::getNomContacto() {
	return nomContacto;
}

String  Contacto::getTelContacto() {
	return telContacto;
}