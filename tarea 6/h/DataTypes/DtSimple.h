#include <iostream>
#include <cstring>
#include <string.h>
#include <stdexcept>

#ifndef DTSIMPLE
#define DTSIMPLE

using namespace std;

class DtSimple : public DtMensaje {
	private:
        string  dtTextSimp;

    public:
        virtual ~DtSimple() {};

        string  getTextSimp() const;
        void setTextSimp (string text);
};
#endif