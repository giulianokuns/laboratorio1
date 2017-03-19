/* Definicion de clase Inscripcion*/

#ifndef INSCRIPCION_H;
#define INSCRIPCION_H;

#include "fecha.h";
#include "socio.h";

class Inscripcion{
    private:
        Fecha fecha;
        Socio *socio;
    public:
        Inscripcion(Fecha fecha,Socio *socio);
        ~Inscripcion();
        Fecha getFecha();
        Socio * getSocio();
        void setFecha(Fecha fecha);
        void setSocio(Socio * socio);
}

#endif
