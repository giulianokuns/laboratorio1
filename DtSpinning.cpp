#include "DtSpinning.h"
#include <iostream>
#include <cstring>
#include <string.h>
#include <stdexcept>

DtSpinning::DtSpinning(int cantBicicletas, int id, string nombre,Turno turno){
	this->cantBicicletas = cantBicicletas;
	this->setid(id);
	this->setNombre(nombre);
	this->setTurno(turno);
}

DtSpinning::~DtSpinning(){}

int DtSpinning::getCantBicicletas(){
	return cantBicicletas;
}

ostream& operator<<(ostream& os, const DtSpinning& dt_spinning)  
{  
    os 	<< "Id Clase: " 				<< dt_spinning.id 	  << '\n' 
   		<< "Nombre: " 					<< dt_spinning.nombre << '\n' 
   		<< "Turno: " 					<< dt_spinning.turno  << '\n'
   		<< "Cantidad de bicicletas: " 	<< dt_spinning.cantBicicletas;  
    return os;  
}  
