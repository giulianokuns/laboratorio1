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

};