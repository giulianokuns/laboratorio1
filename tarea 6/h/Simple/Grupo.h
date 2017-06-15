#include <iostream>
#include <cString>
#include <String.h>
#include <stdexcept>

#include "Fecha.h"
#include "Hora.h"
#include "IDictionary.h"

#ifndef GRUPO 
#define GRUPO

using namespace std;

class Grupo {
	private:
		String nomGrupo;
		String imagenGrupo;
		Fecha fechaCreacion;
		Hora horaCreacion;
		IDictionary infoIngresos;

	public:
		String getnomGrupo();
		String getimagenGrupo();
		Fecha getfechaCreacion();
		Hora gethoraCreacion();
		IDictionary getInfoIngresos();

		void setnomGrupo(String nombre);
		void setimagenGrupo(String imagen);
		void setfechaCreacion(Fecha fechaCreacion);
		void sethoraCreacion(Hora horaCreacion);
		void setInfoIngreso(IDictionary info_ingresos)
}

#endif