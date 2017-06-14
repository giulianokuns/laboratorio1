#include <iostream>
#include <cString>
#include <String.h>
#include <stdexcept>
#include "Fecha.h"
#include "Hora.h"

#ifndef DTMENSAJE
#define DTMENSAJE

using namespace std;

class DtMensaje : public ICollectible {
    private:
        String  dtCodigo;
        Fecha   dtFecha;
        Hora    dtHora;

    public:
        virtual ~DtMensaje() {};

        String  getCodigo() const;
        Fecha   getFecha() const;
        Hora    getHora() const;
};
#endif