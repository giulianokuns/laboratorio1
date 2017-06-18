#include <cstring>
#include <string.h>
 
#include "../Simple/Fecha.h"
#include "../Simple/Hora.h"
#include "../Simple/FechaSistema.h"
#include "../Simple/HoraSistema.h"

#include "../../../lab6-colecciones/interfaces/ICollectible.h"

#ifndef DTNOTIFICACIONES
#define DTNOTIFICACIONES

using namespace std;

class DtNotificaciones : public ICollectible {
	private:
		string 	telCel;
        string 	tipo;
        string 	desc;
		Fecha 	*fecha;
		Hora 	*hora;

	public:
        DtNotificaciones(string telCel, string tipo, string desc);
		~DtNotificaciones();
		string 	gettelCel();
        string 	getTipo();
        string 	getDesc();
		Fecha 	*getFecha();
		Hora 	*getHora();
};

#endif
