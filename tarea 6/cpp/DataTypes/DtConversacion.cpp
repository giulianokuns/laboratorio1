DtConversacion::DtConversacion(bool esGrupo,String nombre,String telcel,String idConversacion){
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
String DtConversacion::getidConversacion(){
	return idConversacion;
}