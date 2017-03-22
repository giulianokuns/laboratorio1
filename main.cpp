/* Main */
#include "Clase.h";
#include "DtClase.h";
#include "Entrenamiento.h";
#include "DtEntrenamiento.h";
#include "Spinning.h";
#include "DtSpinning.h";
#include "Socio.h";
#include "DtSocio.h";
#include "Fecha.h";
#include "Incripcion.h";
#include <iostream>;
#include <string.h>

using namespace std;

#define MAX_CLASES 20
#define MAX_SOCIOS 50
	
	Clase clases[MAX_CLASES];
	Socio socios[MAX_SOCIOS];

	int tope_clases = 0;
	int tope_socios = 0;

	void agregarSocio (string ci, string nombre) 
	{
		int i = 0;
		if (tope_socios < MAX_SOCIOS) {
			while (i <= tope_socios && strcmp(socios[i].getNombre(),nombre) != 0) {
				i++;
			}

			if (i <= tope_socios) {
				throw std::invalid_argument('Ya existe el socio');
			} else {
		 		Socio *socio = new Socio(ci, nombre);
		 		socios[tope_socios] = socio;
		 		tope_socios++;
			}
		} else {
			throw std::invalid_argument('No hay mas lugar disponible');
		}
	}

	void agregarClase(DtClase& clase) {
		/* Diferenciar si la variable clases es de DtSpinning o de DtEntrenamiento */
		int i = 0;
		if (tope_clases < MAX_CLASES) {
			while (i <= tope_clases && strcmp(clases[i].getid(),clase.getid()) != 0) {
				i++;
			}	
			if (i <= tope_clases) {
				throw std::invalid_argument('Ya existe la clase');
			} else {
				if (dynamic_cast<DtEntrenamiento &> clase != null) { 
					//Entrenamiento
					Entrenamiento *entrenamiento = new Entrenamiento(clase.getenRambla(), clase.getid(), clase.getNombre(), clase.getTurno());
			 		clases[tope_clases] = entrenamiento;
					
				} else {
					//Spinning
					Spinning *spinning = new Spinning(clase.getCantBicicletas(), clase.getid(), clase.getNombre(), clase.getTurno());
					clases[tope_clases] = spinning;
				}
		 		tope_clases++;
			}
		} else {
			throw std::invalid_argument('No hay mas clases disponible');
		}
	}


        void agregarInscripcion(string ciSocio, int idClase, Fecha fecha){
                int i=0;
                //se busca la clase donde se debe inscribir al socio
                while(i<tope_clase)&&(clases[i].getid()!=idClase)
                i++;
                if (i>tope_clases)
                throw std::invalid_argument("No existe la clase");
                else if (clases[i].cupo==0)
                throw std::invalid_argument("No hay cupos");
                else {
                int cantidad=clases[i].getCantInscriptos;
                Inscripcion **inscriptos=clases[i].getInscriptos();
                /*if (dynamic_cast<Entrenamiento &> c[i] !=NULL)
                    if (c[i].getenRambla())
                        capacidad=20;
                    else
                        capacidad=10;
                else
                    capacidad=50;*/

                //itero enel arreglo de inscriptos buscando la inscripción
                int j=0;
                bool esta=false;
                while (j<cantidad)&&(!(esta)){
                    esta=(strcomp(((**inscriptos[j]).getSocio()).getCI(),ciSocio)==0);// en caso de no funcionar, probar inscriptos[i]->getSocio()->getCI() para el primer argumento
                    j++;
                }
                if (j<cantidad)
                    throw std::invalid_argument("Ya está inscripto");
                else{
                agregarSocio(ciSocio,clases[i].getNombre());
                Inscripcion(*socio[tope_socios],*fecha);
                }


                }

        }
        
        void borrarInscripcion(string ciSocio, int idClase){
            int i=0;
            while (i<tope_clases)&&(clases[i].getid()!=idClase)
                i++;
            if (i>tope_clases)
                throw std::invalid_argument("La clase no existe");
            else{
                //busco la inscripción
                Inscripcion **inscriptos=c[i].getInscriptos();
                int cantidad=clases[i].getCantInscriptos();
                int j=0;
                bool esta= (strcmp(((**inscriptos[j]).getSocio()).getCI(),ciSocio)==0);
                while ((j<cantidad)&&(!(esta))){
                        esta= (strcmp(((**inscriptos[j]).getSocio()).getCI(),ciSocio)==0);
                        j++;
                }
                if (j>cantidad)
                        throw std::invalid_argument("No hay inscriptos")
                else{
                        inscriptos[j]=inscriptos[cantidad-1];
                        clases[i].setInscriptos(cantidad-1);
                }

            }
        }
        
        DtSocio** obtenerInfoSocioPorClase(int idClase,int& cantSocios){
                int i=0;
                while (i<tope_clases)&&(c[i].getid()!=idClase)
                        i++;
                DtSocio *infoSocio[cantSocios];
                if (i<tope_clases){
                    Inscripcion **inscriptos=c[i].getInscriptos();
                    for(int j=0; j<cantSocios;j++)
                        infoSocio[j]=inscriptos[j].getSocio();

                }
                else
                        infoSocio=NULL;
                return infoSocio;
        }
        DtClase obtenerClase(int idClase){
	     //se asume que debe existir la clase del id correspondiente
	            DtClase datosClase;
	            int j=0;
	            while(j<=tope_clases)&&(clases[j].getid()!=idClase)
		            j++;
	            if (j<tope_clases) //control de error
		            if (dynamic_cast<Entrenamiento &> clases[j]!=NULL) 
	                    datosClase.DtSpinning(clases[j].getCantBicicletas(),clases[j].getid(),clases[j].getNombre(),clases[j].getTurno());
	            else
	                datosClase.DtEntrenamiento(clases[j].getenRambla(),clases[j].getid(),clases[j].getNombre(),clases[j].getTurno());
                return datosClase;
        } 

int main()
{
    int opcion = 0;
    
    while(opcion != 7){
        
        cout << "1. Agregar Socio" << endl;
        cout << "2. Agregar Clase" << endl;
        cout << "3. Agregar Inscripcion" << endl;
        cout << "4. Borrar Inscripcion" << endl;
        cout << "5. Imprimir Socios por clase" << endl;
        cout << "6. Imprimir Clase" << endl << endl;
        
        cout << "Ingrese opcion:"
        cin >> opcion;
        cout << endl << endl;
        
        try{
            if(opcion == 1){
                
                string ci,nombre;
                
                cout << "Ingrese ci:";
                cin >> ci;
                cout << endl;
                
                
                cout << "Ingrese Nombre:";
                cin >> nombre;
                cout << endl;
                
                agregarSocio(ci,nombre);
                
            }
            else if(opcion == 3){
                
            }
            else if(opcion == 4){
                
            }
            else if(opcion == 5){
                
                string ciSocio; int idClase;
                
                cout << "Ingrese ci:";
                cin >> ciSocio;
                cout << endl;
                
                
                cout << "Ingrese Clase:";
                cin >> idClase;
                cout << endl;
                
                borrarInscripcion(ciSocio,idClase);
                
            }
            else if(opcion == 6){
                
            }
            else if(opcion == 7){
                
            }
            else {
                
                invalid_argument("opcion no valida");
            }
        }catch(invalid_argument &ia){
            
            cout << "Error: " << ia.what() << endl;
            
        }
    }
    
    return 0
}
