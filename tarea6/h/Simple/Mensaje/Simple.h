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
        String  textSimp;

    public:
        Simple (IKey codigo, Fecha fecha, Hora hora, String text_simple) : Mensaje (codigo, fecha, hora) {};

        String  getTextSimp() const;

        friend ostream& operator<<(ostream& os, const Simple& mens_simple);
};
#endif