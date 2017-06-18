#include "DtMensaje.h"

#ifndef DTMULTIMEDIA
#define DTMULTIMEDIA

using namespace std;

class DtMultimedia : public DtMensaje {
    public:
        virtual ~DtMultimedia() : DtMensaje (codigo, fecha, hora) {}; 
};

#endif