#include <cstring>
#include <string.h>
#include <stdexcept>

#include "DtMensaje.h"

#ifndef DTSIMPLE
#define DTSIMPLE

using namespace std;

class DtSimple : public DtMensaje {
	private:
        string  dtTextSimp;

    public:
        DtSimple (string codigo, Fecha *fecha, Hora *hora, string text_simple);

        string getTextSimp() const;
};
#endif