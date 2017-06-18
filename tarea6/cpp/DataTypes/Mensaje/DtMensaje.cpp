#include "../../../h/DataTypes/Mensaje/DtMensaje.h"

using namespace std;

string DtMensaje::getCodigo() const {
	return dtCodigo;
}

Fecha DtMensaje::getFecha() const {
	return dtFecha;
}

Hora DtMensaje::getHora() const {
	return dtHora;
}