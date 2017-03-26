#include <iostream>
#include <cstring>
#include <string.h>
#include <stdexcept>
#include "DtClase.h"

#ifndef DTSPINNING
#define DTSPINNING

using namespace std;

class DtSpinning:public DtClase{
    friend ostream& operator<<(ostream& os,  DtSpinning& dt_spinning);
    private:
        int cantBicicletas;
    public:
        DtSpinning(int cantBicicletas, int id, string nombre,Turno turno);
        int getCantBicicletas();
        ~DtSpinning();
};
#endif