#include <iostream>
#include <cstring>
#include <string.h>

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
        Fecha   *dtFecha;
        Hora    *dtHora;

    public:
       	//DtMensaje(string dtcodigo, Fecha *fecha, Hora *hora);
       	~DtMensaje();

        string 	getCodigo() const;
        Fecha   *getFecha() const;
        Hora    *getHora() const;

        void setCodigo(string *codigo);
        void setFecha(Fecha *fecha);
        void setHora(Hora *hora);
};

#endif