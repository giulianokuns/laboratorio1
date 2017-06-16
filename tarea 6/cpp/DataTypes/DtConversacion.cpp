#include "DtConversacion.h"
#include "IKey.h"

DtConversacion::DtConversacion(bool esGrupo, String nombre, String telcel, IKey idConversacion){
	this->esGrupo = esGrupo;
	this->nombre = nombre;
	this->telcel = telcel;
	this->idConversacion = idConversacion;
}
bool DtConversacion::getesGrupo(){
	return esGrupo;
}
String DtConversacion::getnombre(){
	return nombre;
}
String DtConversacion::gettelcel(){
	return telcel;
}
int DtConversacion::getidConversacion(){
	return idConversacion;
}