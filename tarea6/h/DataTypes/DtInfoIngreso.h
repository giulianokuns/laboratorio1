#include <iostream>
#include <cstring>
#include <string.h>

#include "../Simple/Fecha.h"
#include "../Simple/Hora.h"
#include "../../lab6-colecciones/interfaces/ICollectible.h"


#ifndef DTINFOINGRESO
#define DTINFOINGRESO

using namespace std;

class DtInfoIngreso  : public ICollectible {
	private:
		Fecha dtFechaIngreso;
		Hora  dtHoraIngreso;

	public:
		DtInfoIngreso(Fecha *fecha_ingreso, Hora *hora_ingreso);
		~DtInfoIngreso();
		
		Fecha getFechaIngreso();
		Hora  getHoraIngreso();
};

#endif