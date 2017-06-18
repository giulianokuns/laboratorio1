#include <String.h>
#include "Fecha.h"
#include "Hora.h"

#ifndef DTRECEPTOR
#define DTRECEPTOR

using namespace std;

class DtReceptor : public ICollectible {
	private:
		String 	dtNombre;
		IKey	dtNumTel;
		Fecha 	dtFechaVisto;
		Hora 	dtHoraVisto;

	public:
		DtReceptor (String nombre, IKey num_cel, Fecha fecha_visto, hora hora_visto);
		~DtReceptor ();	

		String 	getNombre () {};
		IKey 	getNumTel () {};
		Fecha 	getFechaVisto () {};
		Hora 	getHoraVisto () {};

		ostream& operator<<(ostream& os, const DtReceptor& dt_receptor);
};
#endif