#include <iostream>
#include <cstring>
#include <string.h>
#include <stdexcept>

#ifndef DTSIMPLE
#define DTSIMPLE

using namespace std;

class DtSimple : public DtMensaje {
	private:
        string  dtTextSimp;

    public:
        DtSimple (string codigo, Fecha fecha, Hora hora, string text_simple) {};

        string  getTextSimp() const;
        void setTextSimp (string text);
};
#endif