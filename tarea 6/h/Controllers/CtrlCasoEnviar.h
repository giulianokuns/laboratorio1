
class CtrlCasoEnviar{
private:
    static CtrlCasoEnviar *instancia = NULL;
    CtrlCasoEnviar();
    string idContact;
    string *idConver;
public:
	    static CtrlCasoEnviar *getInstancia();
	    int cantidadArchivadas();
	    ICollection * listarArchivadas();
	    ICollection * listarActivas();
	    ICollection * listarContactos();
	    string * crearConvrsacion(string idContact);
	    void crearMensajeContact(string idContact);
	    void crearMensajeImagen(DtImagen dtImagen);
	    void crearMensajeSimple(DtSimple simCont);
	    void crearMensajeVideo(DtVideo dtVideo);
	    //void ingresarDtImagen(DtImagen dtImagen);
	    //void ingresarDtVideo(DtVideo dtVideo);
	    //void ingresarDtSimple(DtSimple simCont);
	    void ingresarIDContacto(string idContact);
	    //void ingresarIDArchi(string idArchi);
	    //void ingresarIDActiva(string idActiva);
	   
	    
	    
}