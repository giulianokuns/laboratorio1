#include "DtSpinning.h"
#include <iostream>
#include <cstring>
#include <string.h>
#include <stdexcept>
#include "DtClase.h"

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

ostream& operator<<(ostream& os,  DtSpinning& dt_spinning)  
{  
    os 	<< "Id Clase: " 				<< dt_spinning.getid ()	  << '\n' 
   		<< "Nombre: " 					<< dt_spinning.getNombre() << '\n' 
   		<< "Turno: " 					<< dt_spinning.getTurno()  << '\n'
   		<< "Cantidad de bicicletas: " 	<< dt_spinning.getCantBicicletas();  
    return os;  
}  
