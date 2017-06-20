#include <iostream>
#include <cstring>
#include <string.h>
#include <stdexcept>
#include "DtClase.h"

#ifndef DTSPINNING
#define DTSPINNING

using namespace std;

class DtSpinning:public DtClase{
    private:
        int cantBicicletas;
    public:
        DtSpinning(int cantBicicletas, int id, string nombre,Turno turno);
        int getCantBicicletas() const;
        ~DtSpinning();
	friend ostream& operator<<(ostream& os, const DtSpinning& dt_spinning);
};
#endif
