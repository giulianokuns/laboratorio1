#include <iostream>
#include <cstring>

#include "CtrlCasoEnviar.h"
#include "DtSimple.h"
#include "DtContacto.h"
#include "DtVideo.h"
#include "DtImagen.h"
#include "DtMultimedia.h"

#include "ICollection.h"
#include "IKey"

#ifndef CTRLCASOENVIAR
#define CTRLCASOENVIAR

using namespace std;

class CtrlCasoEnviar{
private:
    static CtrlCasoEnviar *instancia = NULL;
    CtrlCasoEnviar();
    IKey idContact;
    IKey *idConver;
public:
	    static CtrlCasoEnviar *getInstancia();
	    int cantidadArchivadas();
	    ICollection * listarArchivadas();
	    ICollection * listarActivas();
	    ICollection * listarContactos();
	    void crearConversacion(IKey tel, IKey idConver);
	    void crearMensajeContact(string idContact);
	    void crearMensajeImagen(DtImagen dtImagen);
	    void crearMensajeSimple(DtSimple simCont);
	    void crearMensajeVideo(DtVideo dtVideo);
	    void ingresarIDContacto(IKey idContact);
	    void ingresarIDArchi(IKey idArchi);
	    void ingresarIDActiva(IKey idActiva);	    
}

#endif