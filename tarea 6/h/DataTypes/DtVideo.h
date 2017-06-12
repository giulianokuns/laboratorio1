#include <iostream>
#include <cstring>
#include <string.h>
#include <stdexcept>
#include "DtMultimedia.h"

#ifndef DTVIDEO
#define DTVIDEO

using namespace std;

class DtVideo : public DtMultimedia {
	private:
		int 	dtDuracion;
        string  dtURLvideo;

    public:
        DtVideo (string codigo, Fecha fecha, Hora hora, int duracion, string urlvideo) : DtMensaje (codigo, fecha, hora) {};
        ~DtVideo ();
        
        int  	getDuracion() const;
        string  getURLvideo() const;

        void setDuracion (int duracion);
        void setURLvideo (string url);
};
#endif