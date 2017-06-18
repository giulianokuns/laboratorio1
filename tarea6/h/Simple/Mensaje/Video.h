#include <iostream>
#include <cstring>
#include <string.h>
#include <stdexcept>


#ifndef VIDEO
#define VIDEO

using namespace std;

class Video : public Mensaje {
	private:
		int 	duracion;
        string  URLvideo;

    public:
        Video (IKey *codigo, Fecha fecha, Hora hora, int duracion, string urlvideo) : Mensaje (codigo, fecha, hora) {};
        ~Video ();
        
        int  	getDuracion() const;
        string  getURLvideo() const;

        friend ostream& operator<<(ostream& os, const Video& mens_video);
};
#endif