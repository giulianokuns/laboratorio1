#include "../../../h/DataTypes/Mensaje/DtVideo.h"

using namespace std;

DtVideo::DtVideo (string codigo, Fecha *fecha, Hora *hora, int duracion, string urlvideo) {
	this->setCodigo(codigo);
	this->setFecha(fecha);
	this->setHora(hora);
	this->dtDuracion    = duracion;
	this->dtURLvideo    = urlvideo;
}

//DtVideo::~DtVideo () {}

int DtVideo::getDuracion() const{
	return dtDuracion;
}
string DtVideo::getURLvideo() const{
	return dtURLvideo;
}