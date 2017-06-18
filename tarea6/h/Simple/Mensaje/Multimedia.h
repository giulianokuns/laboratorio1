#include <iostream>
#include <cString>
#include <String.h>
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