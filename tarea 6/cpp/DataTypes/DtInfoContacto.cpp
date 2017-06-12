DtInfoContacto::DtInfoContacto(string nombre,string telCel, string urlImagen){
	this->nombre = nombre;
	this->telCel = telCel;
	this->urlImagen = urlImagen;
}
string DtInfoContacto::getnombre(){
	return nombre;
}
string DtInfoContacto::gettelCel(){
	return telCel;
}
string DtInfoContacto::geturlImagen(){
	return urlImagen;
}