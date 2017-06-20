#include "../../h/DataTypes/DtReceptor.h"

#include <string.h>

using namespace std;

DtReceptor::DtReceptor (string nombre, IKey *num_cel, Fecha *fecha_visto, Hora *hora_visto): dtFechaVisto(fecha_visto->getdia(), fecha_visto->getmes(), fecha_visto->getanio()), dtHoraVisto(hora_visto->gethoras(), hora_visto->getminutos()) {
	this->dtNombre 		= nombre;
	this->dtNumTel 		= num_cel;
}

DtReceptor::~DtReceptor () {}

string DtReceptor::getNombre () {
	return dtNombre;
}

IKey *DtReceptor::getNumTel () {
	return dtNumTel;
}
Fecha DtReceptor::getFechaVisto () {
	return dtFechaVisto;
}
Hora DtReceptor::getHoraVisto () {

	return dtHoraVisto;
}


/*ostream& operator<<(ostream& os) {
	string tel_cel = new string (this->getNumTel());

	os 	<< "Nombre: " 		<< this->getNombre()	  	<< '\n' 
   		<< "Teléfono: " 	<< tel_cel  				<< '\n' 
   		<< "Fecha Visto: " 	<< this->getFechaVisto() 	<< '\n' 
   		<< "Hora Visto:" 	<< this->getHoraVisto();
    return os;  	
}*/
ostream& operator<<(ostream& os, DtReceptor& dt_receptor)  
{  
	//string tel_cel = new String (dt_receptor.getNumTel()); 
	//string tel_cel = dt_receptor.getNumTel()->getVal();
	
	os 	<< "Nombre: " 		<< dt_receptor.getNombre()	  	<< '\n' 
   		//<< "Teléfono: " 	<< tel_cel  					<< '\n'
		<< "Teléfono: " 	<< dt_receptor.getNumTel() 		<< '\n'
   		<< "Fecha Visto: " 	<< dt_receptor.getFechaVisto() 	<< '\n' 
   		<< "Hora Visto:" 	<< dt_receptor.getHoraVisto();
    return os;  	
}