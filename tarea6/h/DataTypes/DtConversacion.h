#include <iostream>
#include <cstring>
#include <string.h>
#include <stdexcept>

#ifndef DTCONVERSACION
#define DTCONVERSACION
#include "../../lab6-colecciones/interfaces/ICollectible.h"
#include "../../../lab6-colecciones/interfaces/IKey.h"


using namespace std;

class DtConversacion : public ICollectible {
	private:
		IKey *idConversacion;
		bool esGrupo;
		string nombre;
		IKey *telCel;

	public:
		DtConversacion(bool esGrupo, string nombre, IKey *telCel, IKey *idConversacion);
		~DtConversacion();
		IKey *getidConversacion();
		bool getesGrupo();
		string getnombre();
		//en caso de ser esgrupo true no deveria tomarseen cuenta telcel
		IKey *gettelcel();
};

#endif