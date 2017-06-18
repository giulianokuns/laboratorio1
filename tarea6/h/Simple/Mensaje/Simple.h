#include <iostream>
#include <cstring>
#include <string.h>
#include <stdexcept>

#include "Mensaje.h"

#ifndef DTSIMPLE
#define DTSIMPLE

using namespace std;

class Simple : public Mensaje {
	private:
        string  textSimp;

    public:
        Simple (IKey *codigo, Fecha fecha, Hora hora, string text_simple) : Mensaje (codigo, fecha, hora) {};

        string  getTextSimp() const;

        friend ostream& operator<<(ostream& os, const Simple& mens_simple);
};
#endif