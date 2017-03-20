#include <iostream>
#include "DtClase.h"

#ifndef CLASE
#define CLASE;

using namespace std;

class Clase{
    private:
        int id;
        string nombre;
        Turno turno;
        Inscripcion **Inscripciones;
        int cantInscriptos;
    public:
        virtual int cupo() = 0;
        int getid();
        string getNombre();
        turno getTurno();
        Inscripcion **getInscriptos();
        int getCantInscriptos();
        void setid(int id);
        void setNombre(string nombre);
        void setTurno(Turno turno);
        void setInscripciones(Inscripcion **Inscripciones);
        void setInscriptos(int cantInscriptos);
}

#endif 