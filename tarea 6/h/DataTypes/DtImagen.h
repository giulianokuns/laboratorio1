#include <iostream>
#include <cstring>
#include <string.h>
#include <stdexcept>
#include "DtMultimedia.h"

#ifndef DTIMAGEN
#define DTIMAGEN

using namespace std;

class DtImagen : public DtMultimedia {
	private:
        string  dtFormato;
        int  	dtTamanio;
        string  dtTextMulti;
        string  dtURLpicture;

    public:
        DtImagen (string codigo, Fecha fecha, Hora hora, string formato, int tamanio, string textmulti, string urlpicture) {};
        ~DtImagen ();
        
        string  getFormato() const;
        int  	getTamanio() const;
        string  getTextMulti() const;
        string  getURLpicture() const;

        void setFormato (string formato);
        void setTamanio (int tamanio);
        void setTextMulti (string text_multi);
        void setURLpicture (string url);
};
#endif