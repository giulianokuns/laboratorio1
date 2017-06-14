#include <iostream>
#include <cString>
#include <String.h>
#include <stdexcept>
#include "DtMultimedia.h"

#ifndef DTIMAGEN
#define DTIMAGEN

using namespace std;

class DtImagen : public DtMultimedia {
	private:
        String  dtFormato;
        int  	dtTamanio;
        String  dtTextMulti;
        String  dtURLpicture;

    public:
        DtImagen (String codigo, Fecha fecha, Hora hora, String formato, int tamanio, String textmulti, String urlpicture) : DtMensaje (codigo, fecha, hora) {};
        ~DtImagen ();
        
        String  getFormato() const;
        int  	getTamanio() const;
        String  getTextMulti() const;
        String  getURLpicture() const;
};
#endif