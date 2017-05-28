#include "Clase.h"
#include <iostream>
#include <cstring>
#include <string.h>
#include <stdexcept>

#ifndef ENTRENAMIENTO
#define ENTRENAMIENTO

using namespace std;

class Entrenamiento:public Clase{
    private:
        bool enRambla;
    public:
        Entrenamiento(bool enRambla,int id, string nombre,Turno turno);
        bool getenRambla();
        void setenRambla(bool enRambla);
        ~Entrenamiento();
        int cupo();
};

#endif
