#include <iostream>
#include <cstring>
#include <string.h>
#include <stdexcept>

#include "Mensaje.h"

#ifndef MULTIMEDIA
#define MULTIMEDIA

using namespace std;

class Multimedia : public Mensaje {
    public:
        virtual ~Multimedia() : Mensaje (codigo, fecha, hora) {}; 
};

#endif