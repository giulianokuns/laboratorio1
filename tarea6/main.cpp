/* Main */



using namespace std;

	void setFechaHora(int año, int mes, int dia, int hora, int minutos) 
	{
            HoraSistema::
	}

	void agregarClase(DtClase& clase) {
		/* Diferenciar si la variable clases es de DtSpinning o de DtEntrenamiento */
		int i = 0;
		if (tope_clases < MAX_CLASES) {
			while ((i < tope_clases) && (clases[i]->getid()!=clase.getid())) {
				i++;
			}	
			if (i < tope_clases) {
				throw std::invalid_argument("Ya existe la clase");
			} else {
				if (dynamic_cast<DtEntrenamiento*> (&clase) != NULL){ 
					//Entrenamiento
                                        DtEntrenamiento * aux = dynamic_cast<DtEntrenamiento*> (&clase);
					Entrenamiento * entrenamiento = new Entrenamiento(aux->getenRambla(), aux->getid(), aux->getNombre(), aux->getTurno());
                                        clases[tope_clases] = entrenamiento;
				} else {
					//Spinning
                                        DtSpinning * aux = dynamic_cast<DtSpinning*> (&clase);
                                        Spinning *spinning = new Spinning(aux->getCantBicicletas(), aux->getid(), aux->getNombre(), aux->getTurno());
                                        clases[tope_clases] = spinning;           
		 		}
                tope_clases++;
			}
		} else {
			throw std::invalid_argument("No hay mas clases disponible");
		}
	}


    void agregarInscripcion(string ciSocio, int idClase, Fecha fecha){
        int i = 0;
        //se busca la clase donde se debe inscribir al socio
        while((i < tope_clases) && (clases[i]->getid() != idClase)) {
            i++;
        }
        
        if (i >= tope_clases) {
            throw std::invalid_argument("No existe la clase");
        } else if (clases[i]->cupo() == 0) {
            throw std::invalid_argument("No hay cupos");
        } else {
            
            int cantidad = clases[i]->getCantInscriptos();
            Inscripcion **inscriptos = clases[i]->getInscriptos();
  
            int j = 0;
            while ((j < cantidad) && (inscriptos[j]->getSocio()->getCI() != ciSocio)) {
                j++;
            }
        
            if (j < cantidad) {
                throw std::invalid_argument("Ya está inscripto");
            } else {
                
                int z = 0;
                while((z < tope_socios) && (socios[z]->getCI() != ciSocio)) {
                   z++;
                }
                
                if (z >= tope_socios) {
                    throw std::invalid_argument("No existe el socio");
                } else {
                    Inscripcion * ins = new Inscripcion(&fecha, socios[z]);
                   
                    inscriptos[j] = ins;
                   
                    clases[i]->setInscriptos(cantidad + 1);
                    clases[i]->setInscripciones(inscriptos);    
                }
            }
        }
    }
        
    void borrarInscripcion(string ciSocio, int idClase){
        int i=0;
        while (( i < tope_clases) && (clases[i]->getid()!=idClase)) {
            i++;
        }

        if (i >= tope_clases) {
            throw std::invalid_argument("La clase no existe");
        } else {
            //busco la inscripción
            Inscripcion **inscriptos = clases[i]->getInscriptos();
            int cantidad = clases[i]->getCantInscriptos();
            
            int j=0;
            while ((j < cantidad) && (inscriptos[j]->getSocio()->getCI() != ciSocio)) {
                j++;
            }
            
            if (j >= cantidad) {
                throw std::invalid_argument("No esta inscripto");
            } else {
                inscriptos[j] = inscriptos[cantidad-1];
                clases[i]->setInscriptos(cantidad-1);
            }
        }
    }
    
    DtSocio** obtenerInfoSocioPorClase (int idClase, int& cantSocios) {
        
        int i = 0;
        while (( i < tope_clases) && (clases[i]->getid() != idClase)) {
            i++;
        }

        DtSocio ** infoSocio = new DtSocio*[cantSocios];

        if (i < tope_clases){
            Inscripcion **inscriptos = clases[i]->getInscriptos();
            for(int j = 0; j < cantSocios; j++) {
                infoSocio[j] = new DtSocio(inscriptos[j]->getSocio()->getCI(), inscriptos[j]->getSocio()->getNombre());
            }
        }
        return infoSocio;
    }
    
    DtClase& obtenerClase(int idClase){
        DtClase * resultado;
        int j=0;
        while((j < tope_clases) && (clases[j]->getid() != idClase)) {
            j++;
        }

        if (j < tope_clases) { //control de error
            if (dynamic_cast<Entrenamiento *>(clases[j]) != NULL) {
                Entrenamiento  * entr = dynamic_cast<Entrenamiento *>(clases[j]);
                DtEntrenamiento * res = new DtEntrenamiento(entr->getenRambla(), entr->getid(), entr->getNombre(), entr->getTurno());
                resultado = res;
            } else {
                Spinning  * entr = dynamic_cast<Spinning *>(clases[j]);
                DtSpinning * res = new DtSpinning(entr->getCantBicicletas(), entr->getid(), entr->getNombre(), entr->getTurno());
                resultado = res;
            }
        } else {
            throw std::invalid_argument("No existe la clase");
        }   
        return *resultado;
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
        cout << "6. Imprimir Clase" << endl;
        cout << "7. salir" << endl << endl; 
        
        cout << "Ingrese opcion:";
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
            else if(opcion == 2){
                int tipoclase, id, numeroturno;
                string nombre;
                Turno turno;

                cout << "1. Spinning"       << endl;
                cout << "2. Entrenamiento"  << endl;
                cin >> tipoclase;
                
                cout << "Ingrese id: ";
                cin >> id;

                cout << "Ingrese el nombre: ";
                cin >> nombre;

                cout << "Ingrese el turno: " << endl;
                cout << "1. Mañana" << endl;
                cout << "2. Tarde"  << endl;
                cout << "3. Noche"  << endl;
                cin >> numeroturno;

                switch (numeroturno) {
                    case 1: turno = Manana;
                        break;
                    case 2: turno = Tarde;
                        break;
                    case 3: turno = Noche;
                        break;
                    default: throw std::invalid_argument("Turno invalido");
                }

                if (tipoclase == 1) {
                   int bicis;

                   cout << "Ingrese cantidad de bicis: ";
                   cin >> bicis;

                   DtSpinning dtspinning(bicis, id, nombre, turno);
                   agregarClase(dtspinning);
                } else if (tipoclase == 2) {
                    int enrambla;

                    cout << "0. No es en la rambla" << endl;
                    cout << "1. Es en la rambla"    << endl;
                    cin >> enrambla;
                    
                    bool rambla;
                    if (enrambla == 1) {
                        rambla = true;
                    } else if (enrambla == 0) {
                        rambla = false;
                    } else {
                        throw std::invalid_argument("Modalidad de clase invalida");    
                    }

                    DtEntrenamiento dtentrenamiento(rambla,id,nombre,turno);
                    agregarClase(dtentrenamiento);
                } else {
                    throw std::invalid_argument("Tipo de clase invalido");
                }
            }
            
            else if(opcion == 3){
                string ciSocio;
                int idclase,dia,mes,anio;
                
                cout << "Ingrese la cedula del socio: ";
                cin >> ciSocio;

                cout << "Ingrese el ID de la clase: ";
                cin >> idclase;
                
                cout << "Fecha de Inscripcion: ";
                cout << "Ingrese el dia: ";
                cin >> dia;

                cout << "Ingrese le mes: ";
                cin >> mes;

                cout << "Ingrese el año: ";
                cin >> anio;

                Fecha *f = new Fecha(dia,mes,anio);
                
                agregarInscripcion(ciSocio, idclase, *f);
                
            }
            else if(opcion == 4){
                string CI;
                int ID;

                cout << "Ingrese la CI del socio: ";
                cin >> CI;

                cout << "Ingrese el ID de la clase: ";
                cin >> ID;

                borrarInscripcion(CI,ID);
            }
            else if(opcion == 5){
                
                int idClase, cantSocios;
                
                cout << "Ingrese Clase: ";
                cin >> idClase;
                cout << endl;
                
                
                cout << "Ingrese CantidadSocios: ";
                cin >> cantSocios;
                cout << endl;

                int i = 0;
                while (( i < tope_clases) && (clases[i]->getid() != idClase)) {
                    i++;
                } 
                if (i >= tope_clases) {
                    throw std::invalid_argument("No existe la clase");
                } else if (clases[i]->getCantInscriptos() > cantSocios) {
                    DtSocio** socios = obtenerInfoSocioPorClase(idClase, cantSocios); 
                    for(int i = 0; i < cantSocios; i++) {
                        cout << socios[i]->getCI() << " - " << socios[i]->getNombre() << endl;
                    }
                    delete socios;
                } else {
                    int cant_inscriptos = clases[i]->getCantInscriptos();
                    DtSocio** socios = obtenerInfoSocioPorClase(idClase, cant_inscriptos);    
                    for(int i = 0; i < cant_inscriptos; i++) {
                        cout << socios[i]->getCI() << " - " << socios[i]->getNombre() << endl;
                    }
                    delete socios;
                }
                    
                
            }
            else if(opcion == 6){
                int id;
                cout << "Ingrese el ID de la clase: ";
                cin >> id;
                
                if(dynamic_cast<DtEntrenamiento*> (&obtenerClase(id)) != NULL){
                    DtEntrenamiento * imp = dynamic_cast<DtEntrenamiento*>(&obtenerClase(id));
                    cout << *imp <<endl;	
                }
                else{
 		            DtSpinning * imp = dynamic_cast<DtSpinning*>(&obtenerClase(id));
                    cout << *imp <<endl;	
                }
            }
            else {
                invalid_argument("Opcion no valida");
            }
        }catch(invalid_argument &ia){
            cout << "Error: " << ia.what() << endl;
        }
    }
    return 0;
}
