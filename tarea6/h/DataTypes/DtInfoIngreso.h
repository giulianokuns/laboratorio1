#include <iostream>
#include <cstring>
#include <string.h>
#include "Fecha.h"
#include "Hora.h"

#ifndef DTINFOINGRESO
#define DTINFOINGRESO

using namespace std;

class DtInfoIngreso: public ICollectible {
	private:
		Fecha dtFechaIngreso,
		Hora  dtHoraIngreso;

	public:
		DtInfoIngreso(Fecha fecha_ingreso, Hora hora_ingreso);
		~DtInfoIngreso();
		
		Fecha getFechaIngreso();
		Hora  getHoraIngreso();
}

#endif