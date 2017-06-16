#include "Simple.h"
#include <iostream>
#include <cString>
#include <String.h>
#include <stdexcept>

using namespace std;

Simple::Simple (IKey codigo, Fecha fecha, Hora hora, String text_simple) : Mensaje (codigo, fecha, hora)  {
	this->Codigo 	= codigo;
	this->Fecha 	= fecha;
	this->Hora 	 	= hora;
	this->TextSimp 	= text_simple;
}

Simple::~Simple () {}

String  Simple::getTextSimp() {
	return textSimp;
}
