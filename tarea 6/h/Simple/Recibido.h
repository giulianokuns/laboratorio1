class Recibido{
	private:
        bool visto;
        bool eliminado;
        Fecha fechaVisto;
        Hora horaVisto;
	public:
		bool getVisto();
		bool getEliminado();
		Fecha getFechaVisto();
		Hora getHoraVisto();
		void setVisto(bool vist);
		void setEliminado(bool elim);
		void setFechaVisto(Fecha fechaVist);
		void setHoraVisto(Hora horaVist);
};
