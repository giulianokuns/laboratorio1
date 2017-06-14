#include <iostream>
#include <cString>
#include <String.h>
#include <stdexcept>
#include "Fecha.h"
#include "Hora.h"

#ifndef RECIBIDO
#define RECIBIDO

using namespace std;

class Recibido {
	private:
        bool visto;
        bool eliminado;
        Fecha fechaVisto;
        Hora horaVisto;

	public:
		bool getVisto();
		bool getEliminado();
		Fecha getFechaVisto();
		Hora getHoraVisto();

		void setVisto(bool visto);
		void setEliminado(bool elim);
		void setFechaVisto(Fecha fechaVisto);
		void setHoraVisto(Hora horaVisto);
};

#endif