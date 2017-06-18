#ifndef DTCONVERSACION
#define DTCONVERSACION
#include "../../cpp/DataTypes/DtConversacion.cpp"
#include "../../lab6-colecciones/interfaces/ICollectible.h"
#include "../../../lab6-colecciones/interfaces/IKey.h"

using namespace std;

class DtConversacion: public ICollectibe {
	private:
		IKey idConversacion;
		bool esGrupo;
		String nombre;
		IKey telCel;

	public:
		DtConversacion(bool esGrupo, String nombre, IKey telCel, IKey idConversacion);
		~DtConversacion();
		IKey getidConversacion();
		bool getesGrupo();
		String getnombre();
		//en caso de ser esgrupo true no deveria tomarseen cuenta telcel
		IKey gettelcel();
}

#endif