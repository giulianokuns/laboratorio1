DtConversacion::DtConversacion(bool esGrupo,string nombre,string telcel,string idConversacion){
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
string DtConversacion::gettelcel(){
	return telcel;
}
string DtConversacion::getidConversacion(){
	return idConversacion;
}