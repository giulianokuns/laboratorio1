/* Definicion de clase Inscripcion*/

#ifndef INSCRIPCION_H
#define INSCRIPCION_H

#include "Fecha.h"
#include "Socio.h"
#include <iostream>
#include <cstring>
#include <string.h>
#include <stdexcept>

class Inscripcion{
    private:
        Fecha *fecha;
        Socio *socio;
    public:
        Inscripcion(Fecha *fecha, Socio *socio);
        ~Inscripcion();
        Fecha * getFecha();
        Socio * getSocio();
        void setFecha(Fecha * fecha);
        void setSocio(Socio * socio);
};

#endif

