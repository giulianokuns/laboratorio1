#include <iostream>
#include <cstring>
#include <string.h>
#include <stdexcept>
#include "DtMensaje.h"

#ifndef DTMULTIMEDIA
#define DTMULTIMEDIA

using namespace std;

class DtMultimedia : public DtMensaje {
    public:
        virtual ~DtMultimedia() {};
};
#endif