class FechaSistema{
	private:
		static int hora;
		static int minutos;

	public:
		static int getHora();
		static int getMinutos();
		static void setHora(int hora);
		static void setMinutos(int minutos);
}