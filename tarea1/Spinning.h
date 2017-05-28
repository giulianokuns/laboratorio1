#include "Clase.h"
#include <iostream>
#include <cstring>
#include <string.h>
#include <stdexcept>

#ifndef SPINNING
#define SPINNING


using namespace std;

class Spinning: public Clase{
    private:
        int cantBicicletas;
    public:
        Spinning(int cantBicicletas, int id, string nombre,Turno turno);
        int getCantBicicletas();
        void setCantBicicletas(int cantBicicletas);
        ~Spinning();
        int cupo();
};

#endif
