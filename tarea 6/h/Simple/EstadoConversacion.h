#include "Conversacion.h"

#ifndef USUARIO
#define USUARIO

using namespace std;

class EstadoConversacion: public ICollectible {
	private:
		bool archivada;
		Conversacion conversacion;
	public:
		EstadoConversacion(bool archivada, Conversacion c);
		~EstadoConversacion();
		bool getarchivada();
		Conversacion getconversacion();
		void setarchivada(bool archivada);
		void setconversacion( Conversacion c); 
		Conversacion * compararConv (int idConv);
};
#endif