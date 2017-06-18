#include "../../h/DataTypes/DtReceptor.h"
#include "../../../lab6-colecciones/interfaces/IKey.h"
#include "../../h/Fecha.h"
#include "../../h/hora.h"
#include <string.h>

using namespace std;

DtReceptor::DtReceptor (string nombre, IKey num_cel, Fecha fecha_visto, hora hora_visto) {
	this->dtNombre 		= nombre;
	this->dtNumTel 		= num_cel;
	this->dtFechaVisto 	= fecha_visto;
	this->dtHoraVisto 	= hora_visto;
}

DtReceptor::~DtReceptor () {}

string DtReceptor::getNombre () {
	return dtNombre;
}

IKey DtReceptor::getNumTel () {
	return dtNumTel;
}
Fecha DtReceptor::getFechaVisto () {
	return dtFechaVisto;
}
Hora DtReceptor::getHoraVisto () {
	return dtHoraVisto;
}

ostream& operator<<(ostream& os, const DtReceptor& dt_receptor) {
	string tel_cel = new string (dt_receptor.getNumTel());

	os 	<< "Nombre: " 		<< dt_receptor.getNombre()	  	<< '\n' 
   		<< "Teléfono: " 	<< tel_cel  					<< '\n' 
   		<< "Fecha Visto: " 	<< dt_receptor.getFechaVisto() 	<< '\n' 
   		<< "Hora Visto:" 	<< mens_simple.getHoraVisto();
    return os;  	
}
