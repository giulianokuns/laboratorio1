#include "../../h/Controllers/CtrlUsuario.h"
#include "../../lab6-colecciones/interfaces/IKey.h"

class ICtrlUsuario{
public:
	static ICtrlUsuario * getinstancia() = 0;
	virtual Usuario * getusuarioLog() = 0;
	virtual	IDictionary *getusuarios() = 0;
	virtual	void setusuarioLog(Usuario * u) =0;
	virtual	void setusuarios(IDictionary *lista_usuarios) =0;

		/* Ver Mensaje */
	virtual	ICollection *mensajesCoversacion (IKey *idConv) = 0;
		
		/*archivar_conversacion*/
	virtual	ICollection *listarActivas() = 0;
	virtual	void archivar_conversacion(IKey *ID) = 0;

		/*agregarContacto*/
	virtual	ICollection *getContactos() = 0;
	virtual	bool existeUsuario(IKey *telCel) = 0;
	virtual	bool esContacto(IKey *telCel) = 0;
	virtual	DtInfoContacto agregarContacto(IKey *telcel) = 0;
	virtual	void confirmarAgregarContacto(IKey *telcel) = 0;

		/*eliminar mensaje*/
	virtual void eliminarMensaje (IKey *codigo, IKey *idConv) = 0;

		/*cerrar GUASAP*/
	virtual	void cerrarGuasap() = 0;

		/*abrir GUASAP*/

	virtual	bool inicioSesion() = 0;
	virtual	DtFecha altaUsuario(IKey *numero, string nombre, string URL, string Descripcion) = 0;
	virtual	bool ingresar(IKey *numero) = 0;
	virtual ICollection *getNotificaciones() = 0;
	virtual void eliminarNotificaciones() = 0;
	virtual void agregarSuscriptor(IKey *s) = 0;
	virtual void eliminarSuscriptor(IKey *telCel) = 0; 
        
}
