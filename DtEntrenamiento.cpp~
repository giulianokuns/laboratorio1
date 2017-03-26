#include "DtEntrenamiento.h"
#include <iostream>
#include <cstring>
#include <string.h>
#include <stdexcept>
#include "DtClase.h"

DtEntrenamiento::DtEntrenamiento(bool enRambla,int id, string nombre,Turno turno){
	this->enRambla = enRambla;
	this->setid(id);
	this->setNombre(nombre);
	this->setTurno(turno);
}

DtEntrenamiento::~DtEntrenamiento(){}

bool DtEntrenamiento::getenRambla() const{
	return enRambla;
}

ostream& operator<<(ostream& os, DtEntrenamiento& dt_entrenamiento)  
{  
	string str_enRambla;
	if (dt_entrenamiento.getenRambla()) {
		str_enRambla = "Si";
	} else { 
		str_enRambla = "No";
	}
    os 	<< "Id Clase: " 	<< dt_entrenamiento.getid() 	  << '\n' 
   		<< "Nombre: " 		<< dt_entrenamiento.getNombre() << '\n' 
   		<< "Turno: " 		<< dt_entrenamiento.getTurno()  << '\n'
   		<< "En rambla: " 	<< str_enRambla;  
    return os;  
} 
