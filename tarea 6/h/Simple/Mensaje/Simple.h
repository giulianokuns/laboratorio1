#include <iostream>
#include <cString>
#include <String.h>
#include <stdexcept>

#include "Mensaje.h"

#ifndef DTSIMPLE
#define DTSIMPLE

using namespace std;

class Simple : public Mensaje {
	private:
        String  textSimp;

    public:
        Simple (String codigo, Fecha fecha, Hora hora, String text_simple) : Mensaje (codigo, fecha, hora) {};

        String  getTextSimp() const;
};
#endif