#include <iostream>
#include <cstring>
#include <string.h>

#include "DtMensaje.h"

#ifndef DTVIDEO
#define DTVIDEO

using namespace std;

class DtVideo : public DtMensaje{
	private:
		int 	dtDuracion;
        string  dtURLvideo;

    public:
        DtVideo (string codigo, Fecha *fecha, Hora *hora, int duracion, string urlvideo);
        ~DtVideo ();
        
        int  	getDuracion() const;
        string  getURLvideo() const;
};
#endif