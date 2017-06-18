#include "../../h/DataTypes/DtReceptor.h"

#include <string.h>

using namespace std;

DtReceptor::DtReceptor (string nombre, IKey *num_cel, Fecha fecha_visto, Hora hora_visto) {
	this->dtNombre 		= nombre;
	this->dtNumTel 		= num_cel;
	this->dtFechaVisto 	= fecha_visto;
	this->dtHoraVisto 	= hora_visto;
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

<<<<<<< HEAD
ostream& operator<<(ostream& os, const DtReceptor& dt_receptor) {
	IKey *tel_cel = new string (dt_receptor.getNumTel());
=======
ostream& operator<<(ostream& os) {
	string tel_cel = new string (this->getNumTel());
>>>>>>> ca3a662782c2b8cb8a512d5f9eb6e512ca4af96c

	os 	<< "Nombre: " 		<< this->getNombre()	  	<< '\n' 
   		<< "Teléfono: " 	<< tel_cel  				<< '\n' 
   		<< "Fecha Visto: " 	<< this->getFechaVisto() 	<< '\n' 
   		<< "Hora Visto:" 	<< this->getHoraVisto();
    return os;  	
}
