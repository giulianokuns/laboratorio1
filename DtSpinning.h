#include <iostream>
#include "DtClase.h"

#ifndef DTSPINNING
#define DTSPINNING;

using namespace std;

class DtSpinning:public DtClase{
    private:
        int cantBicicletas;
    public:
        DtSpinning(int cantBicicletas, int id, string nombre,Turno turno);
        int getCantBicicletas();
        ~DtSpinning();
}

#endif 