#include <string.h>
#include "Fecha.h"
#include "Hora.h"

#ifndef DTRECEPTOR
#define DTRECEPTOR

using namespace std;

class DtReceptor : public ICollectible {
	private:
		string 	dtNombre;
		int		dtNumTel;
		Fecha 	dtFechaVisto;
		Hora 	dtHoraVisto;

	public:
		DtReceptor (string nombre, int num_cel, Fecha fecha_visto, hora hora_visto);
		~DtReceptor ();	

		string 	getNombre () {};
		int 	getNumTel () {};
		Fecha 	getFechaVisto () {};
		Hora 	getHoraVisto () {};

		void setNombre (string nombre) {};
		void setNumTel (int num_cel) {};
		void setFechaVisto (Fecha fecha_visto) {};
		void setHoraVisto (Hora hora_visto) {};

};
#endif