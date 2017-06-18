#include "../../h/DataTypes/DtConversacion.h"
#include "../../../lab6-colecciones/interfaces/IKey.h"

DtConversacion::DtConversacion(bool esGrupo, string nombre, IKey telCel, IKey idConversacion){
	this->esGrupo = esGrupo;
	this->nombre = nombre;
	this->telcel = telcel;
	this->idConversacion = idConversacion;
}
bool DtConversacion::getesGrupo(){
	return esGrupo;
}
string DtConversacion::getnombre(){
	return nombre;
}
IKey DtConversacion::gettelcel(){
	return telcel;
}
int DtConversacion::getidConversacion(){
	return idConversacion;
}