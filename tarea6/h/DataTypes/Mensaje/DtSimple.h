#include "DtMensaje.h"

#ifndef DTSIMPLE
#define DTSIMPLE

using namespace std;

class DtSimple : public DtMensaje {
	private:
        String  dtTextSimp;

    public:
        DtSimple (IKey codigo, Fecha fecha, Hora hora, String text_simple) : DtMensaje (codigo, fecha, hora) {};

        String  getTextSimp() const;
};
#endif