#include <iostream>
#include <cstring>
#include <string.h>
#include <stdexcept>
#include "Fecha.h"
#include "Hora.h"

#ifndef DTMENSAJE
#define DTMENSAJE

using namespace std;

class DtMensaje : public ICollectible {
    private:
        string  dtCodigo;
        Fecha   dtFecha;
        Hora    dtHora;

    public:
        virtual ~DtMensaje() {};

        string  getCodigo() const;
        Fecha   getFecha() const;
        Hora    getHora() const;
};
#endif