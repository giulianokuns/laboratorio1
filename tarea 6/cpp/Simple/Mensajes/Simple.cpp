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

ostream& operator<<(ostream& os, const Simple& mens_simple) {  
	string codigo = new String (mens_simple.getodigo());

    os 	<< "Código: " 	<< codigo 					  	 << '\n' 
   		<< "Fecha: " 	<< mens_simple.getfechaMensaje() << '\n' 
   		<< "Hora: " 	<< mens_simple.gethoraMensaje()  << '\n'
   		<< "Texto: " 	<< mens_simple.getTextSimp();  
    return os;  
} 