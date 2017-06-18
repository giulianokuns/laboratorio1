#include "DtMultimedia.h"

#ifndef DTVIDEO
#define DTVIDEO

using namespace std;

class DtVideo : public DtMultimedia {
	private:
		int 	dtDuracion;
        String  dtURLvideo;

    public:
        DtVideo (IKey codigo, Fecha fecha, Hora hora, int duracion, String urlvideo) : DtMensaje (codigo, fecha, hora) {};
        ~DtVideo ();
        
        int  	getDuracion() const;
        String  getURLvideo() const;
};
#endif