#include <iostream>
#include <cstring>
#include <string.h>
#include <stdexcept>

#include "Fecha.h"
#include "Hora.h"
#include "../../lab6-colecciones/interfaces/IDictionary.h"


#ifndef GRUPO 
#define GRUPO

using namespace std;

class Grupo {
	private:
		string nomGrupo;
		string imagenGrupo;
		Fecha fechaCreacion;
		Hora horaCreacion;
		IDictionary *infoIngresos;

	public:
		Grupo(string nomGrupo, string imagenGrupo,	Fecha fechaCreacion,	Hora horaCreacion,	IDictionary *infoIngresos);
		string getnomGrupo();
		string getimagenGrupo();
		Fecha getfechaCreacion();
		Hora gethoraCreacion();
		IDictionary *getInfoIngresos();

		void setnomGrupo(string nombre);
		void setimagenGrupo(string imagen);
		void setfechaCreacion(Fecha fechaCreacion);
		void sethoraCreacion(Hora horaCreacion);
		void setInfoIngreso(IDictionary *info_ingresos);
};

#endif