/* Definicion de clase Fecha*/

#ifndef FECHA_H
#define FECHA_H

class Fecha { 
    private:
        int dia;
        int mes;
        int anio;
    public:
        Fecha(int dia, int mes, int anio);
        ~Fecha();
        Fecha(const Fecha &r);
        int getDia();
        int getMes();
        int getAnio();
};

#endif
