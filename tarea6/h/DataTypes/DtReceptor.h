#include <iostream>
#include <cstring>
#include <string.h>

#include "../Simple/Fecha.h"
#include "../Simple/Hora.h"
#include "../../lab6-colecciones/interfaces/ICollectible.h"
#include "../../../lab6-colecciones/interfaces/IKey.h"



#ifndef DTRECEPTOR
#define DTRECEPTOR

using namespace std;

class DtReceptor : public ICollectible {
	private:
		string 	dtNombre;
		IKey	*dtNumTel;
		Fecha 	dtFechaVisto;
		Hora 	dtHoraVisto;

	public:
		DtReceptor (string nombre, IKey *num_cel, Fecha fecha_visto, Hora hora_visto);
		~DtReceptor ();	

		string 	getNombre ();
		IKey 	*getNumTel ();
		Fecha 	getFechaVisto ();
		Hora 	getHoraVisto ();

		ostream& operator<<(ostream& os);
};
#endif