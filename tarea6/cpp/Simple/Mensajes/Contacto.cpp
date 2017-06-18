#include <iostream>
#include <cstring>
#include <string.h>
#include <stdexcept>

#include "Contacto.h"

using namespace std;

Contacto::Contacto (IKey codigo, Fecha fecha, Hora hora, string nom_contacto, string tel_cont) : Mensaje (codigo, fecha, hora)  {
	this->codigo 	 	= codigo;
	this->fecha 	 	= fecha;
	this->hora 	 		= hora;
	this->nomContacto 	= nom_contacto;
	this->telContacto 	= tel_cont;
}

Contacto::~Contacto () {}

string  Contacto::getNomContacto() {
	return nomContacto;
}

string  Contacto::getTelContacto() {
	return telContacto;
}

ostream& operator<<(ostream& os, const Contacto& mens_contacto) {  
	string codigo = new string (mens_contacto.getodigo());	
	
    os 	<< "Código: " 	 	<< codigo 					  		<< '\n' 
   		<< "Fecha: " 		<< mens_contacto.getfechaMensaje() 	<< '\n' 
   		<< "Hora: " 		<< mens_contacto.gethoraMensaje()  	<< '\n'
   		<< "Duración: " 	<< mens_contacto.getNomContacto()  	<< '\n'
   		<< "URL: " 			<< mens_contacto.getTelContacto(); 
    return os;  
}