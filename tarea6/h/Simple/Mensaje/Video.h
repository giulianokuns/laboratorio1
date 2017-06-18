#include <iostream>
#include <cstring>
#include <string.h>
#include <stdexcept>

#include "Multimedia.h"

#ifndef VIDEO
#define VIDEO

using namespace std;

class Video : public Multimedia {
	private:
		int 	duracion;
        String  URLvideo;

    public:
        Video (IKey codigo, Fecha fecha, Hora hora, int duracion, String urlvideo) : Mensaje (codigo, fecha, hora) {};
        ~Video ();
        
        int  	getDuracion() const;
        String  getURLvideo() const;

        friend ostream& operator<<(ostream& os, const Video& mens_video);
};
#endif