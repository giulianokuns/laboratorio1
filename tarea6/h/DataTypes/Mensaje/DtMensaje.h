#include <iostream>
#include <cstring>
#include <string.h>
#include <stdexcept>

#include "../../Simple/Fecha.h"
#include "../../Simple/Hora.h"
#include "../../../lab6-colecciones/interfaces/ICollectible.h"
#include "../../../lab6-colecciones/interfaces/IKey.h"

#ifndef DTMENSAJE
#define DTMENSAJE

using namespace std;

class DtMensaje : public ICollectible {
    private:
        string  dtCodigo;
        Fecha   dtFecha;
        Hora    dtHora;

    public:
        DtMensaje (string dtcodigo, Fecha &dtfecha, Hora &dthora);
        virtual ~DtMensaje() {};

        string 	getCodigo() const;
        Fecha   getFecha() const;
        Hora    getHora() const;
};

#endif