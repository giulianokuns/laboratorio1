#include "DtEntrenamiento.h";

DtEntrenamiento::DtEntrenamiento(bool enRambla,int id, string nombre,Turno turno){
	this->enRambla = enRamla;
	this->setid(id);
	this->setNombre(nombre);
	this->setTurno(turno);
}

DtEntrenamiento::~DtEntrenamiento(){}

bool DtEntrenamiento::getenRambla(){
	return enRambla;
}

ostream& operator<<(ostream& os, const DtEntrenamiento& dt_entrenamiento)  
{  
	string str_enRambla;
	if (dt_spinning.enRambla) {
		str_enRambla = 'Si';
	} else { 
		str_enRambla = 'No';
	}
    os 	<< 'Id Clase: ' 	<< dt_spinning.id 	  << '\n' 
   		<< 'Nombre: ' 		<< dt_spinning.nombre << '\n' 
   		<< 'Turno: ' 		<< dt_spinning.turno  << '\n'
   		<< 'En rambla: ' 	<< str_enRambla;  
    return os;  
}  
