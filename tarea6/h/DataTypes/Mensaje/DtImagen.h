#include <iostream>
#include <cstring>
#include <string.h>
#include <stdexcept>

#include "DtMensaje.h"

#ifndef DTIMAGEN
#define DTIMAGEN

using namespace std;

class DtImagen : public DtMensaje {
	private:
        string  dtFormato;
        int  	dtTamanio;
        string  dtTextMulti;
        string  dtURLpicture;

    public:
        DtImagen (string codigo, Fecha *fecha, Hora *hora, string formato, int tamanio, string textmulti, string urlpicture);
        ~DtImagen ();
        
        string  getFormato() const;
        int  	getTamanio() const;
        string  getTextMulti() const;
        string  getURLpicture() const;
};
#endif