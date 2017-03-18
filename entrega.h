enum turno = {Manana, Tarde, Noche};
//Hola
using std::string;

class DtSocio{
    private:
      int CI;
      string nombre;
    public:
      DtSocio(int CI,string nombre);
      string getNombre();
      int getCI();
      ~DtSocio();
}

class Fecha{
    private:
        int dia;
        int mes;
        int anio;
    public:
        Fecha(int dia,int mes,int anio);
        ~Fecha();
        int getDia();
        int getMes();
        int getAnio();
}

class DtClase{
    private:
        int id;
        string nombre;
        Turno turno;
    public:
        int getid();
        string getNombre();
        Turno getTurno();
}

class DtSpinning:public DtClase{
    private:
        int cantBicicletas;
    public:
        DtSpinning(int cantBicicletas, int id, string nombre,Turno turno);
        int getCantBicicletas();
        ~DtSpinning();
}

class DtEntrenamiento:public DtClase{
    private:
        bool enRambla;
    public:
        DtEntrenamiento(bool enRambla,int id, string nombre,Turno turno);
        bool getenRambla();
        ~DtEntrenamiento();
}

class Socio{
    private
        int CI;
        string nombre;
    public:
        Socio(int CI,string nombre);
        ~Socio();
        string getNombre();
        int getCI();
        void setNombre(string nombre);
        void setCI(int CI);
}

class Inscripcion{
    private:
        Fecha fecha;
        Socio *socio;
    public:
        Inscripcion(Fecha fecha,Socio *socio);
        ~Inscripcion();
        Fecha getFecha();
        Socio * getSocio();
        void setFecha(Fecha fecha);
        void setSocio(Socio * socio);
}

class Clase{
    private:
        int id;
        string nombre;
        Turno turno;
        Inscripcion **Inscripciones;
        int cantInscriptos;
    public:
        virtual int cupo() = 0;
        int getid();
        string getNombre();
        turno getTurno();
        Inscripcion **getInscriptos();
        int getCantInscriptos();
        void setid(int id);
        void setNombre(string nombre);
        void setTurno(Turno turno);
        void setInscripciones(Inscripcion **Inscripciones);
        void setInscriptos(int cantInscriptos);
}

class Spinning: public Clase{
    private:
        int cantBicicletas;
    public:
        Spinning(int cantBicicletas, int id, string nombre,Turno turno);
        int getCantBicicletas();
        void setCantBicicletas(int cantBicicletas);
        ~Spinning();
}

class Entrenamiento:public Clase{
    private:
        bool enRambla;
    public:
        Entrenamiento(bool enRambla,int id, string nombre,Turno turno);
        bool getenRambla();
        void setenRambla(bool enRambla);
        ~Entrenamiento();
}
