#include <iostream>
#include <cstring>
#include <string.h>
#include <stdexcept>
#include "DtMultimedia.h"

#ifndef DTVIDEO
#define DTVIDEO

using namespace std;

class DtVideo : public DtMultimedia {
	private:
		int 	dtDuracion;
        string  dtURLvideo;

    public:
        virtual ~DtVideo() {};

        int  	getDuracion() const;
        string  getURLvideo() const;

        void setDuracion (int text);
        void setURLvideo (string url);
};
#endif