#include "Simple.h"
#include <iostream>
#include <cstring>
#include <string.h>
#include <stdexcept>

using namespace std;

Simple::Simple (IKey codigo, Fecha fecha, Hora hora, string text_simple) : Mensaje (codigo, fecha, hora)  {
	this->Codigo 	= codigo;
	this->Fecha 	= fecha;
	this->Hora 	 	= hora;
	this->TextSimp 	= text_simple;
}

Simple::~Simple () {}

string  Simple::getTextSimp() {
	return textSimp;
}

ostream& operator<<(ostream& os, const Simple& mens_simple) {  
	string codigo = new string (mens_simple.getodigo());

    os 	<< "Código: " 	<< codigo 					  	 << '\n' 
   		<< "Fecha: " 	<< mens_simple.getfechaMensaje() << '\n' 
   		<< "Hora: " 	<< mens_simple.gethoraMensaje()  << '\n'
   		<< "Texto: " 	<< mens_simple.getTextSimp();  
    return os;  
} 