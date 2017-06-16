
class CtrlCasoEnviar{
private:
    static CtrlCasoEnviar *instancia = NULL;
    CtrlCasoEnviar();
    String idContact;
    String *idConver;
public:
	    static CtrlCasoEnviar *getInstancia();
	    int cantidadArchivadas();
	    ICollection * listarArchivadas();
	    ICollection * listarActivas();
	    ICollection * listarContactos();
	    IKey * crearConversacion(String idContact);
	    void crearMensajeContact(String idContact);
	    void crearMensajeImagen(DtImagen dtImagen);
	    void crearMensajeSimple(DtSimple simCont);
	    void crearMensajeVideo(DtVideo dtVideo);
	    //void ingresarDtImagen(DtImagen dtImagen);
	    //void ingresarDtVideo(DtVideo dtVideo);
	    //void ingresarDtSimple(DtSimple simCont);
	    void ingresarIDContacto(String idContact);
	    //void ingresarIDArchi(string idArchi);
	    //void ingresarIDActiva(string idActiva);
	   
	    
	    
}