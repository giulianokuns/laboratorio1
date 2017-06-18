#include "../../h/DataTypes/DtContacto.h"
#include "../../../lab6-colecciones/interfaces/IKey.h"

DtInfoContacto::DtInfoContacto(string nombre, IKey telCel, string urlImagen){
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