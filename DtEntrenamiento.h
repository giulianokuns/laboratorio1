#include <iostream>
#include "DtClase.h"

#ifndef DTENTRENAMIENTO
#define DTENTRENAMIENTO;

using namespace std;

class DtEntrenamiento:public DtClase{
    private:
        bool enRambla;
    public:
        DtEntrenamiento(bool enRambla,int id, string nombre,Turno turno);
        bool getenRambla();
        ~DtEntrenamiento();
}

#endif 