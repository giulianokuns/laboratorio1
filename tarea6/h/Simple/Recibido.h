#include <iostream>
#include <cstring>
#include <string.h>
#include <stdexcept>

#include "Fecha.h"
#include "Hora.h"
#include "Usuario.h"

#ifndef RECIBIDO
#define RECIBIDO

using namespace std;

class Recibido: public ICollectible {
	private:
        bool visto;
        bool eliminado;
        Fecha fechaVisto;
        Hora horaVisto;
        Usuario usuario;
        
	public:
		Recibido(Usuario u);
		~Recibido();

		bool getVisto();
		bool getEliminado();
		Fecha getFechaVisto();
		Hora getHoraVisto();
		Usuario getUsuario();

		void setVisto(bool visto);
		void setEliminado(bool elim);
		void setFechaVisto(Fecha fechaVisto);
		void setHoraVisto(Hora horaVisto);
		void setUsuario(Usuario usuario);
};

#endif