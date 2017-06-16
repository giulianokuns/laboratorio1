
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
	    //void ingresarDtImagen(DtImagen dtImagen);
	    //void ingresarDtVideo(DtVideo dtVideo);
	    //void ingresarDtSimple(DtSimple simCont);
	    void ingresarIDContacto(IKey idContact);
	    void ingresarIDArchi(IKey idArchi);
	    void ingresarIDActiva(IKey idActiva);
	   
	    
	    
}