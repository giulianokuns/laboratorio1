#include "../../../h/DataTypes/Mensaje/DtContacto.h"

using namespace std;

DtContacto::DtContacto (string codigo, Fecha *fecha, Hora *hora, string nom_contacto, string tel_cont) {
	this->setCodigo(codigo);
	this->setFecha(fecha);
	this->setHora(hora);
	this->dtNomContacto = nom_contacto;
	this->dtTelContacto = tel_cont;
}

//DtContacto::~DtContacto () {}

string  DtContacto::getNomContacto() const {
	return dtNomContacto;
}

string  DtContacto::getTelContacto() const {
	return dtTelContacto;
}