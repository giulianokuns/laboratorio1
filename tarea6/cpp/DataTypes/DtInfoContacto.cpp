#include "../../h/DataTypes/DtContacto.h"
#include "../../../lab6-colecciones/interfaces/IKey.h"

DtInfoContacto::DtInfoContacto(String nombre, IKey telCel, String urlImagen){
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