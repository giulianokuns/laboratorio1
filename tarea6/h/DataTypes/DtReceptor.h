#include <string.h>
#include "Fecha.h"
#include "Hora.h"

#ifndef DTRECEPTOR
#define DTRECEPTOR

using namespace std;

class DtReceptor : public ICollectible {
	private:
		string 	dtNombre;
		IKey	dtNumTel;
		Fecha 	dtFechaVisto;
		Hora 	dtHoraVisto;

	public:
		DtReceptor (string nombre, IKey num_cel, Fecha fecha_visto, hora hora_visto);
		~DtReceptor ();	

		string 	getNombre () {};
		IKey 	getNumTel () {};
		Fecha 	getFechaVisto () {};
		Hora 	getHoraVisto () {};

		ostream& operator<<(ostream& os);
};
#endif