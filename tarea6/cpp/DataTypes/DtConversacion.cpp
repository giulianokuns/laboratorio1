#include "../../h/DataTypes/DtConversacion.h"
#include "../../../lab6-colecciones/interfaces/IKey.h"

DtConversacion::DtConversacion(bool esGrupo, string nombre, IKey *telCel, IKey *idConversacion){
	this->esGrupo = esGrupo;
	this->nombre = nombre;
	this->telCel = telCel;
	this->idConversacion = idConversacion;
}
bool DtConversacion::getesGrupo(){
	return esGrupo;
}
string DtConversacion::getnombre(){
	return nombre;
}
IKey *DtConversacion::gettelcel(){
	return telCel;
}
IKey *DtConversacion::getidConversacion(){
	return idConversacion;
}
