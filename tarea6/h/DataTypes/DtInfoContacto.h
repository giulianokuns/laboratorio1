#include <iostream>
#include <cstring>
#include <string.h>


#include "../../lab6-colecciones/interfaces/ICollectible.h"
#include "../../../lab6-colecciones/interfaces/IKey.h"

#ifndef DTINFOCONTACTO 
#define DTINFOCONTACTO 

using namespace std;

class DtInfoContacto: public ICollectible {
	private:
		string nombre;
		IKey *telCel;
		string urlImagen;
	public:
		DtInfoContacto(string nombre,IKey *telCel, string urlImagen);
		~DtInfoContacto();
		string getnombre();
		IKey *gettelCel();
		string geturlImagen();
};

#endif