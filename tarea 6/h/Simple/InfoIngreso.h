#include "Fecha.h"
#include "Hora.h"

#ifndef INFOINGRESO
#define INFOINGRESO

using namespace std;

class InfoIngreso {
	private:
		Fecha fechaIngreso;
		Hora horaIngreso;

	public:
	Fecha getfechaIngreso();
	Hora gethoraIngreso();

	void setfechaIngreso(Fecha fechaIngreso);
	void sethoraIngreso(Hora horaIngreso);
}

#endif