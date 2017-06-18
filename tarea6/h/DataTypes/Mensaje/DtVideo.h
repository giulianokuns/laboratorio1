#include "DtMensaje.h"

#ifndef DTVIDEO
#define DTVIDEO

using namespace std;

class DtVideo : public DtMensaje{
	private:
		int 	dtDuracion;
        string  dtURLvideo;

    public:
        DtVideo (IKey codigo, Fecha fecha, Hora hora, int duracion, string urlvideo) {};
        ~DtVideo ();
        
        int  	getDuracion() const;
        string  getURLvideo() const;
};
#endif