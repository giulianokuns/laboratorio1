#include <iostream>
#include <cString>
#include <String.h>
#include <stdexcept>

#include "Fecha.h"
#include "Hora.h"
#include "Usuario.h"

#ifndef INFOINGRESO
#define INFOINGRESO

using namespace std;

class InfoIngreso {
	private:
		Fecha fechaIngreso;
		Hora horaIngreso;
		Usuario usuario;

	public:
	Fecha 	getfechaIngreso();
	Hora 	gethoraIngreso();
	Usuario getUsuario();

	void setfechaIngreso(Fecha fechaIngreso);
	void sethoraIngreso(Hora horaIngreso);
	void setUsuario(Usuario usuario);
}

#endif