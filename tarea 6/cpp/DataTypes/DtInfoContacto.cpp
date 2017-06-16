#include "DtInfoContacto.h"

DtInfoContacto::DtInfoContacto(String nombre, String telCel, String urlImagen){
	this->nombre = nombre;
	this->telCel = telCel;
	this->urlImagen = urlImagen;
}
String DtInfoContacto::getnombre(){
	return nombre;
}
String DtInfoContacto::gettelCel(){
	return telCel;
}
String DtInfoContacto::geturlImagen(){
	return urlImagen;
}