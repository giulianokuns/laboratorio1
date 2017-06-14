#include <String.h>
#include "Fecha.h"
#include "Hora.h"

#ifndef DTRECEPTOR
#define DTRECEPTOR

using namespace std;

class DtReceptor : public ICollectible {
	private:
		String 	dtNombre;
		int		dtNumTel;
		Fecha 	dtFechaVisto;
		Hora 	dtHoraVisto;

	public:
		DtReceptor (String nombre, int num_cel, Fecha fecha_visto, hora hora_visto);
		~DtReceptor ();	

		String 	getNombre () {};
		int 	getNumTel () {};
		Fecha 	getFechaVisto () {};
		Hora 	getHoraVisto () {};
};
#endif