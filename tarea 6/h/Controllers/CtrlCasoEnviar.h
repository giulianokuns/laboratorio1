
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
	    void crearMensajeContact(String idContact);
	    void crearMensajeImagen(DtImagen dtImagen);
	    void crearMensajeSimple(DtSimple simCont);
	    void crearMensajeVideo(DtVideo dtVideo);
	    void ingresarIDContacto(IKey idContact);
	    void ingresarIDArchi(IKey idArchi);
	    void ingresarIDActiva(IKey idActiva);
	   
	    
	    
}