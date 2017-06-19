#include "../../../h/DataTypes/Mensaje/DtImagen.h"

using namespace std;

DtImagen::DtImagen (string codigo, Fecha *fecha, Hora *hora, string formato, int tamanio, string textmulti, string urlpicture) {
	this->setCodigo(codigo);
	this->setFecha(fecha);
	this->setHora(hora);
	this->dtFormato    = formato;
	this->dtTamanio    = tamanio;
	this->dtTextMulti  = textmulti;
	this->dtURLpicture = urlpicture;
}

DtImagen::~DtImagen () {}

string DtImagen::getFormato() const{
	return dtFormato;
}
int DtImagen::getTamanio() const {
	return dtTamanio;
}
string DtImagen::getTextMulti()  const {
	return dtTextMulti;
}
string DtImagen::getURLpicture()  const {
	return dtURLpicture;
}