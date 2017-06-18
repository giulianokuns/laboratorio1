/* Main */



using namespace std;
        
        /*CASO DE USO: SETEAR HORA Y FECHA*/
	void setFechaHora(int año, int mes, int dia, int hora, int minutos) 
	{
            HoraSistema::setHora(hora);
            HoraSistema::setMinutos(minutos);
            FechaSistema::setAño(año);
            FechaSistema::setMes(mes);
            FechaSistema::setDia(dia);
	}
	
	/*CASO DE USO: MOSTRAR HORA Y FECHA*/
	
	string getFechaHora() 
	{
            cout FechaSistema::getDia() << "/" << FechaSistema::getMes()  << "/" << FechaSistema::getAño()  << " " << HoraSistema::getHora() << ":" << HoraSistema::getMinutos; 
	}

	
	/*CASO DE USO: CERRAR GUASAP*/
	void cerrarGuasap(){
            
            ICtrlUsuario *instancia= ICtrlUsuario::getinstancia();
            instancia->cerrarGuasap();
            
	}
	
	/*CASO DE USO: ABRIR GUASAP*/
	void abrirGuasap(){
           
            ICtrlUsuario *instancia= ICtrlUsuario::getinstancia();
            
            string numero;
            bool seDioDeAlta = false;
            
            cout << "Ingrese su numero: ";
            cin << numero;
            cout << endl;
            
            while(!seDioDeAlta && !instancia->ingresar(new String(numero))){
                
                cout << "Quiere darse de alta en el sistema?(s/n): ";
                string op;
                cin >> op;
                
                if(op == "n"){
                    cout << "Ingrese su numero nuevamente: ";
                    cin << numero;
                    cout << endl;
                }else{
                    /*DtFecha CtrlUsuario::altaUsuario(IKey numero, string nombre, string URL,string Descripcion)*/
                    string tel,nombre,URL,descripcion;
                    
                    cout << "Ingrese su numero de telefono: ";
                    cin >> tel;
                    cout << endl;
                    
                    cout << "Ingrese su nombre: ";
                    cin >> nombre;
                    cout << endl;
                    
                    cout << "Ingrese su imagen: ";
                    cin >> URL;
                    cout << endl;
                    
                    cout << "Ingrese su descripcion: ";
                    cin >> descripcion;
                    cout << endl << endl << endl;
                    
                    DtFecha fchAlta = instancia->altaUsuario(new String(tel),nombre,URL,descripcion);
                    
                    cout << "Usuario dado de alta el " << fchAlta->getDia() << "/" << fchAlta->getMes() << "/" << fchAlta->getAño();
                }
            
            }
            
            if(!seDioDeAlta){
                /*MOSTRAR NOTIFICACIONES*/
                cout << endl << endl << endl
                ICollection notificaciones = instancia->getNotificaciones();
                for(IIterator *it = notificaciones->getIterator(); it->hasCurrent(); it-next()){
                    DtNotificaciones notificacion = dynamic_cast<DtNotificaciones *>(it->getCurrent());
                    cout << "El usuario :" << notificacion->gettelCel() << "Cambio su " << notificacion->getTipo() << "Por " << notificacion->getDesc() << endl;
                    cout << notificacion->getFecha()->getDia() << "/" << notificacion->getFecha()->getMes() << "/" << notificacion->getFecha()->getAño() << " " << notificacion->getHora()->getHora() << ":" << notificacion->getHora()->getMinutos();
                    cout << endl << endl;
                }
                instancia->eliminarNotificaciones();
            }
        }

/*CASO DE USO: AGREGAR CONTACTO*/

void agregarContacto(){
Usuario *u = instancia->getusuarioLog();
ICollection contactos = u->getInfoContactos();
bool se_dese_agrear = true;
while (se_dese_agrear){
	cout << "Sus contactos son:" endl;
	//imprimo los contactos del usuario
	String telcel,nombre,urlimagen;
	for (IIterator *it = contactos->getIterator(); it->hasCurrent(); it->next()) {
		DtInfoContacto contacto_mostrar = it->getCurrent();
		tecel = contacto_mostrar->gettelCel();
		nombre = contacto_mostrar->getnombre();
		urlimagen = contacto_mostrar->geturlImagen();
		cout << telcel "  " nombre "  " urlimagen endl;
	}
	cout << "1. Agregar un contacto " endl;
	cout << "2.finalizar el caso de uso" endl;
	int l;
	cin >> l;
	if(l==1){
		cout << "Ingrese el telefono del contacto que desea agregar" endl;
		cin >>telcel;
		Ikey *telcelkey = new String(telcel);
		if (u->esContacto(telcelkey)){
			throw std::invalid_argument("Ya es tu contacto") endl;
		}else{
			if(!(u->existeUsuario(telCelkey))){
				throw std::invalid_argument("Ese usuario no existe") endl;
			}else{
				contacto_mostrar = u->agregarContacto(telcelkey);
				tecel = contacto_mostrar->gettelCel();
				nombre = contacto_mostrar->getnombre();
				urlimagen = contacto_mostrar->geturlImagen();
				cout << "Su informacion es:"endl;
				cout << telcel "  " nombre "  " urlimagen endl;
				cout << "1. Agregar"endl;
				cout << "2. No agregar"endl;
				cin >> l; 
				if (l==1){
					u->confirmarAgregarContacto(telcelkey);
				}else{}
				cout << "1. Agregar otro contacto"endl;
				cout << "2. No agregar otro contacto"endl;
				cin >> l;
				if(l==1){
				}else{
					se_dese_agrear = false;
				}

			}
		}
	}else{
		se_dese_agrear = false;
	}
}}

/*CASO DE USO: ALTA GRUPO*/
void altaGrupo(){
ICtrlUsuario *instancia= ICtrlUsuario::getinstancia();
Usuario *u = instancia->getusuarioLog();
IDictionary *contactos = u->getcontactos();
if(contactos->isEmpty()){
	throw std::invalid_argument("No tienes ningun contacto") endl;
}else{
	IDictionary *lista_agregados = new OrderedDictionaryEntry();
	IDictionary *lista_no_agregados = new OrderedDictionaryEntry();
	//agrego al usuario logeado
	DtInfoContacto usuario_agregar = new DtInfoContacto(u->getnombre(),u->gettelCel()->getValue(), u->geturlImagen());
	lista_agregados->add(u->gettelCel(),usuario_agregar);
	//agrego todos a la lista de no agregados
	for (IIterator *it = contactos->getIterator(); it->hasCurrent(); it->next()) {
		Usuario *actual = it->getCurrent();
		DtInfoContacto actual_agregar = new DtInfoContacto(actual->getnombre(),actual->gettelCel()->getValue(), actual-actualgeturlImagen());
		lista_no_agregados->add(actual->gettelCel(),actual_agregar);
	}
	//mientrasse quiera edito
	while(desea_editar){
		String nombre,telcel;
		cout << "Agregados:" endl;
		for (IIterator *it_a = lista_agregados->getIterator(); it_a->hasCurrent(); it_a->next()) {
			DtInfoContacto *actual_agregado = it_a->getCurrent();
			nombre = actual_agregado->getnombre();
			telcel = actual_agregado->gettelCel();
			cout << nombre "   " telcel endl;
		}
		for (IIterator *it_n = lista_no_agregados->getIterator(); it_n->hasCurrent(); it_n->next()) {
			DtInfoContacto *actual_no_agregado = it_n->getCurrent();
			nombre = actual_no_agregado->getnombre();
			telcel = actual_no_agregado->gettelCel();
			cout << nombre "   " telcel endl;
		}
		//se elije una opcion
		cout << "1. Agregar un contacto al grupo" endl;
		cout << "2. Eliminar un contacto del grupo" endl;
		cout << "3.Terminar la edicion de contactos" endl;
		int p;
		cin >> p;
		if(p == 1){
			cout << "Ingrese el telefono del contacto que desea agregar" endl;
			cin >> telcel;
			ikey *telefono_agregar = new String(telcel);
			DtInfoContacto contacto_a_agregar = find(telefono_agregar);
			DtInfoContacto contacto_a_agrega_aux = new DtInfoContacto(contacto_a_agregar->nombre(),contacto_a_agregar->gettelCel(),contacto_a_agregar->geturlImagen());
			lista_no_agregados->remove(telefono_agregar);
			lista_agregados->add(telefono_agregar,contacto_a_agrega_aux);
		}else if(p == 2){
			cout << "Ingrese el telefono del contacto que desea eliminar" endl;
			cin >> telcel;
			ikey *telefono_eliminar = new String(telcel);
			if(telefono_eliminar->equals(u->gettelCel())){
				throw std::invalid_argument("NO puedes eliminarte del grupo") endl;
			}else{
				DtInfoContacto contacto_a_eliminar = find(telefono_eliminar);
				DtInfoContacto contacto_a_eliminar_aux = new DtInfoContacto(contacto_a_eliminar->nombre(),contacto_a_eliminar->gettelCel(),contacto_a_eliminar->geturlImagen());
				lista_agregados->remove(telefono_eliminar);
				lista_no_agregados->add(telefono_eliminar,contacto_a_eliminar_aux);
			}
		}else{
			if(lista_agregados->getSize()==1){
				throw std::invalid_argument("Tienes que agregar al menos un contacto") endl;
			}else{desea_editar = false;	}
		}
	}
	cout << "Ingrese el nombre del grupo" endl;
	cin >> nombre;
	cout << "Ingrese el URL de la imagen" endl;
	cin >> telcel; // que ahora es el url de la imagen
	//creo el grupo sin los info ingreso
	Fecha *fechaIngreso = new Fecha(FechaSistema::getdia(), FechaSistema::getmes(), FechaSistema::getanio());
	Hora *horaIngreso = new Hora(HoraSistema::gethoras(), HoraSistema::getminutos());
 	Grupo *g = new Grupo(nombre, telcel, fechaIngreso, horaIngreso;  NULL);
	IDictionary *infoIngresos = new OrderedDictionaryEntry();
	//agrego al usuario logueado
	fechaIngreso = new Fecha(FechaSistema::getdia(), FechaSistema::getmes(), FechaSistema::getanio());
	horaIngreso = new Hora(HoraSistema::gethoras(), HoraSistema::getminutos());
	InfoIngreso *info_loegueado_agregar = new InfoIngreso(fechaIngreso, horaIngreso, u);
	infoIngresos->add(u->gettelCel(), info_logueado_agregar);
	Conversacion *c = new (false, idconversaciones, true, g, NULL);
	EstadoConversacion * ec = new EstadoConversacion(false, c);
	u->getcarreglo_ec()->add(idconversaciones, ec);
	idconversaciones++;
	for (IIterator *it_i = lista_agregados->getIterator(); it_i->hasCurrent(); it_i->next()) {
		//itero entre usuarios
		DtInfoContacto *actual_a_crear = it_i->getCurrent();
		ikey *tel = new String(actual_a_crear->gettelCel());
		Usuario *usuario_a_agregar = instancia->getusuarios()->find(tel);
		//creo los info ingreso y los agrego a los info ingreso del grupo(que se agregan al grupo luego de la iteracion)
		//para info ingreso tengo que crear una fecha y hora nueva
		fechaIngreso = new Fecha(FechaSistema::getdia(), FechaSistema::getmes(), FechaSistema::getanio());
		horaIngreso = new Hora(HoraSistema::gethoras(), HoraSistema::getminutos());
		info_a_agregar = new InfoIngreso(fechaIngreso, horaIngreso, usuario_a_agregar);
		infoIngresos->add(tel, info_a_agregar);
		//para cada usuario creo una conversacion y su ec correspondiente y los agrego al arreglo de ec
		c = new (false, idconversaciones, true, g, NULL);
		ec = new EstadoConversacion(false, c);
		usuario_a_agregar->getcarreglo_ec()->add(idconversaciones, ec);
		idconversaciones++;
	}
	g->setInfoIngresos(infoIngresos);

	//libero memoria
}}

/*CASO DE USO: ENVIAR MENSAJE*/
void enviarMensaje(){
ICtrlUsuario *CI = ICtrlUsuario::getinstancia();

Usuario * user_log = CI->getusuarioLog();

if (user_log != NULL) {
	ICollection * lista_activas = CI->listarActivas();
	int cantidad_archivadas     = CI->cantidadArchivadas();

	if (!lista_activas.isEmpty()) {
		string nombre, tel_cel;
		cout << "Conversaciones activas" << endl;

		for (IIterator *it = lista_activas->getIterator(); it->hasCurrent(); it->next()) {
			Conversacion * c = getCurrent();
			bool es_grupo = c->getesGrupo();
			if (es_grupo) {
				Grupo g = c->getgrupo();
				nombre = g->getnomGrupo();
			} else {
				IDictionary * participantes = getparticipantes();
				/*Es una conversacion Simple, tiene 2 participantes, si no es el usuario logeado entonces es el
				otro*/
				for (IIterator *it_p = participantes->getIterator(); it_p->hasCurrent(); it_p->next()) {
					Usuario * u = getCurrent();
					if (!userlog->gettelCel()->compare(u->gettelCel())) {
						nombre  = u->getnomUsuario();
						tel_cel = u->gettelCel();
					}
				}		
			}
			cout << nombre + " " + tel_cel << endl;
		}
		cout << "" << endl;
		cout << "Archivadas :" + cantidad_archivadas << endl;

		cout << "****************************************" 	<< endl;
		cout << "1. Seleccionar una conversación activa " 	<< endl;
		cout << "2. Ver las conversaciones archivadas " 		<< endl;
		cout << "3. Enviar un mensaje a un contacto con el cuál aún no ha iniciado una conversación" <<endl
		int opcion;
		cout << "Opción: ";
		cin >> opcion;

		if (opcion == 1) {
			cout << "Ingrese el identificador de la conversación activa que desea seleccionar: ";
			int idC;
			cin >> idC;
			IKey * idConv = new int (idC);
			ICtrlCasoEnviar *i = ICtrlCasoEnviar::getinstancia();
			i->ingresarIDActiva(idConv)

		} else if (opcion == 2){
			// se llama a la funcion listarArchivadas y se muestra las conversaciones archivadas
			cout << "Conversaciones archivadas"	<< endl;
			ICollection * lista_archivadas = i->listarArchivadas();

			if (!lista_archivadas->isEmpty()) {
				for (IIterator *it = lista_archivadas->getIterator(); it->hasCurrent(); it->next()) {
					Conversacion * c = getCurrent();
					bool es_grupo = c->getesGrupo();
					if (es_grupo) {
						Grupo g = c->getgrupo();
						nombre = g->getnomGrupo();
					} else {
						IDictionary * participantes = getparticipantes();
						/*Es una conversacion Simple, tiene 2 participantes, si no es el usuario logeado entonces es el
						otro*/
						for (IIterator *it_p = participantes->getIterator(); it_p->hasCurrent(); it_p->next()) {
							Usuario * u = getCurrent();
							if (!userlog->gettelCel()->compare(u->gettelCel())) {
								nombre  = u->getnomUsuario();
								tel_cel = u->gettelCel();
							}
						}		
					}
					cout << nombre + " " + tel_cel << endl;	
				}
				cout << "Ingrese el identificador de la conversación archivada que desea seleccionar: ";
				int idC;
				cin >> idC;
				IKey * idConvArchi = new int (idC);
				i->ingresarIDArchi(idConvArchi);
	    
		} else if (opcion == 3){
			//se llama a la funcion listarContactos y se muestra la lista
			ICollection * contactos = i->listarContactos();
			for (IIterator *it_c = contactos->getIterator(); it_c->hasCurrent(); it_c->next()){
				Usuario *u = dynamic_cast <Usuario *> it_c->getCurrent();
				cout << u->getnomUsuario() + " " + u->gettelCel() << endl;
			}
			cout <<"Ingrese el número de teléfono a iniciar una conversación nueva";
			string telefono;
			cin >> telefono;
			IKey * keytel = new String(telefono)
			//El actualIdConver es el identificador de la coversacion actual
			i->ingresarIDActiva(crearConversacion(keytel, actualIdConver));

		} else {
            //lanzar una excepción de opcion invalida
			throw std::invalid_argument('Opción invalida.');
		}

		cout << "****************************************" 	<< endl;
		cout << "Seleccione el tipo de mensaje a enviar";
		cout << "1. Simple " << endl;
		cout << "2. Imagen " << endl;
		cout << "3. Video" <<endl;
		cout << "4. Contacto" <<endl;

		int mensaje;
		cin >> mensaje;
		if (mensaje == 1){
			cout << "Ingrese el texto";
			string text;
			cin >> text;
			i->crearMensajeSimple(text, codigoMensAct, fechaSist, horaSist)
		} else if (mensaje == 2){
			cout << "Ingrese datos de la imagen";
            string formato;
            int tamanio;
            string textMulti;
            string urlImg;
            cin >> formato;
            cin >> tamanio;
            cin >> textMulti;
            cin >> urlImg;
            i->crearMensajeImagen(formato, tamanio, textMulti, urlImg, codigoMensAct, fechaSist, horaSist);
		} else if (mensaje == 3){
			cout << "Ingrese datos video";
			string urlVideo;
			int duracion;
			cin >> urlVideo;
			cin >> duracion;
			i->crearMensajeVideo(urlVideo, duracion, codigoMensAct, fechaSist, horaSist);
		} else if (mensaje == 4){
			cout << "Ingrese teléfono del contacto";
            string telContact;
            cin >> telContact;
            i->crearMensajeContacto(telContact, codigoMensAct, fechaSist, horaSist);
		} else 
			throw std::invalid_argument('Opción invalida.');
	}else
	    throw std::invalid_argument('No tiene conversaciones activas.');	
}else 
    throw std::invalid_argument('No hay un usuario logeado en el sistema.');
}}

/*CASO DE USO: VER MENSAJE*/
void verMensaje(){
    ICtrlUsuario *CI = ICtrlUsuario::getinstancia();

Usuario * user_log = CI->getusuarioLog();

if (user_log != NULL) {
	ICollection * lista_activas = CI->listarActivas();
	int cantidad_archivadas     = CI->cantidadArchivadas();

	if (!lista_activas.isEmpty()) {
		String nombre, tel_cel;
		cout << "Conversaciones activas" << endl;

		for (IIterator *it = lista_activas->getIterator(); it->hasCurrent(); it->next()) {
			Conversacion * c = getCurrent();
			bool es_grupo = c->getesGrupo();
			if (es_grupo) {
				Grupo g = c->getgrupo();
				nombre = g->getnomGrupo();
			} else {
				IDictionary * participantes = getparticipantes();
				/*Es una conversacion Simple, tiene 2 participantes, si no es el usuario logeado entonces es el
				otro*/
				for (IIterator *it_p = participantes->getIterator(); it_p->hasCurrent(); it_p->next()) {
					Usuario * u = getCurrent();
					if (!userlog->gettelCel()->compare(u->gettelCel())) {
						nombre  = u->getnomUsuario();
						tel_cel = u->gettelCel();
					}
				}		
			}
			cout << nombre + " " + tel_cel << endl;
		}
		cout << "" << endl;
		cout << "Archivadas :" + cantidad_archivadas << endl;

		cout << "****************************************" 	<< endl;
		cout << "1. Seleccionar una conversación activa " 	<< endl;
		cout << "2. Ver las conversaciones archivadas" 		<< endl;
		int opcion;
		cout << "Opción: ";
		cin >> opcion;

		if (opcion == 1) {
			cout << "Ingrese el identificador de la conversación activa que desea seleccionar: ";
			int idC;
			cin >> idC;
			IKey * idConv = new int (idC);
			ICollection * mensajes =  CI->mensajesCoversacion (idConv);

			if (!mensajes->isEmpty()) {
				for (IIterator *it_m = mensajes->getIterator(); it_m->hasCurrent(); it_m->next()) {
					Mensaje m = getCurrent();

					if (dynamic_cast<Simple*> (&m) != NULL) {
						//Es Simple
						Simple * mensj = dynamic_cast<Simple*> (&m);
						cout << * mensj << endl;
					} else if (dynamic_cast<Contacto*> (&m) != NULL) {
						//Es Contacto
						Contacto * mensj = dynamic_cast<Contacto*> (&m);
						cout << * mensj << endl;
					} else {
						//Es Multimedia
						if (dynamic_cast<Imagen*> (&m) != NULL) {
							//Es Imagen
							Imagen * mensj = dynamic_cast<Imagen*> (&m);
							cout << * mensj << endl;
						} else {
							//Es Video
							Video * mensj = dynamic_cast<Video*> (&m);
							cout << * mensj << endl;
						}
					}
				}
			
				int opt = 1;				
				while (opt == 1) {
					cout << "Ingrese el código del mensaje enviado que desea ver la información adicional." << endl;
					String codigo;
					cin >> codigo;

					IKey * codigo = new String (codigo);
					ICollection * receptores = obtenerInfoAdicional(codigo);

					if (!receptores->isEmpty()) {
						for (IIterator *it_r = receptores->getIterator(); it_r->hasCurrent(); it_r->next()) {
							Receptor receptor = getCurrent();
							cout << receptor << endl;	
							cout << "*****************************************" << endl;
						}
					} else {
						cout << "Ningun usuario vio este mensaje." << endl;
					}

					cout << "" << endl;
					cout << "1. Continuar viendo información adicional." << endl;
					cout << "2. Salir." << endl;
					cout << "Opción: ";
					cin >> opt;					
				}
			} else {
				throw std::invalid_argument("No hay mensajes para mostrar.");
			}				
		} else if (opcion == 2) {
			cout << "Conversaciones archivadas"	<< endl;
			ICollection * lista_archivadas = CI->listarArchivadas();

			if (!lista_archivadas->isEmpty()) {
				for (IIterator *it = lista_archivadas->getIterator(); it->hasCurrent(); it->next()) {
					Conversacion * c = getCurrent();
					bool es_grupo = c->getesGrupo();
					if (es_grupo) {
						Grupo g = c->getgrupo();
						nombre = g->getnomGrupo();
					} else {
						IDictionary * participantes = getparticipantes();
						/*Es una conversacion Simple, tiene 2 participantes, si no es el usuario logeado entonces es el
						otro*/
						for (IIterator *it_p = participantes->getIterator(); it_p->hasCurrent(); it_p->next()) {
							Usuario * u = getCurrent();
							if (!userlog->gettelCel()->compare(u->gettelCel())) {
								nombre  = u->getnomUsuario();
								tel_cel = u->gettelCel();
							}
						}		
					}
					cout << nombre + " " + tel_cel << endl;	
				}
				cout << "Ingrese el identificador de la conversación archivada que desea seleccionar: ";
				int idC;
				cin >> idC;
				IKey * idConv = new int (idC);

				ICollection * mensajes =  CI->mensajesCoversacion (idConv);
				
				if (!mensajes->isEmpty()) {
					for (IIterator *it_m = mensajes->getIterator(); it_m->hasCurrent(); it_m->next()) {
						Mensaje m = getCurrent();

						if (dynamic_cast<Simple*> (&m) != NULL) {
							//Es Simple
							Simple * mensj = dynamic_cast<Simple*> (&m);
							cout << * mensj << endl;
						} else if (dynamic_cast<Contacto*> (&m) != NULL) {
							//Es Contacto
							Contacto * mensj = dynamic_cast<Contacto*> (&m);
							cout << * mensj << endl;
						} else {
							//Es Multimedia
							if (dynamic_cast<Imagen*> (&m) != NULL) {
								//Es Imagen
								Imagen * mensj = dynamic_cast<Imagen*> (&m);
								cout << * mensj << endl;
							} else {
								//Es Video
								Video * mensj = dynamic_cast<Video*> (&m);
								cout << * mensj << endl;
							}
						}
					}

					int opt = 1;				
					while (opt == 1) {
						cout << "Ingrese el código del mensaje enviado que desea ver la información adicional." << endl;
						String codigo;
						cin >> codigo;

						IKey * codigo = new String (codigo);
						ICollection * receptores = obtenerInfoAdicional(codigo);

						if (!receptores->isEmpty()) {
							for (IIterator *it_r = receptores->getIterator(); it_r->hasCurrent(); it_r->next()) {
								Receptor receptor = getCurrent();
								cout << receptor << endl;	
								cout << "*****************************************" << endl;
							}
						} else {
							cout << "Ningun usuario vio este mensaje." << endl;
						}

						cout << "" << endl;
						cout << "1. Continuar viendo información adicional." << endl;
						cout << "2. Salir." << endl;
						cout << "Opción: ";
						cin >> opt;					
					}
				} else {
					throw std::invalid_argument("No hay mensajes para mostrar.");
				}
			} else {
				throw std::invalid_argument("No tiene conversaciones archivadas.");
			}
		} else {
			throw std::invalid_argument('Opción invalida.');
		}
	} else {
		throw std::invalid_argument('No tiene conversaciones activas.');
	}
} else {
	throw std::invalid_argument('No hay un usuario logeado en el sistema.');
}

/*CASO DE USO: ARCHIVAR CONVERSACIONES*/

void archivarConversacion(){
    ARCHIVAR CONVERSACION 
ICollection *conversaciones = get_lista_activos();
bool desea_archivar = true;
while ( desea_archivar){
	//imprimo las conversaciones no archivadas 
	for (IIterator *it = conversaciones->getIterator(); it->hasCurrent(); it->next()) {
		DtConversacion *dtc = it->getCurrent();
		String nombre,idconv;
		nombre = dtc->getnombre();
		idconv = dtc->getidConversacion();
		if(dtc->esgrupo()){
			//imprimir
		}else{
			String telcel = dtc->gettelCel();
			//imprimir
		}
	}
	cout << "Ingrese el id de la conversacion que desea archivar" endl;
	String id;
	cin >> id;
	ikey *idkey = new String(id);
	instancia->getusuarioLog()->archivar(idkey);
	cout << "1. Archivar otra conversacion" endl;
	cout << "2. Terminar caso de uso" endl;
	int k;
	cin >> k;
	if(k==1){

	}else {desea_archivar = false}	
}
}

/*CASO DE USO: MODIFICAR USUARIO*/

void modificarUsuario(){
    bool desea_modificar = true;
while(desea_modificar){
	cout << "Que desea modificar?" << endl;
	cout << "1. Nombre de usuario" << endl;
	cout << "2. URL de la imagen" << endl;
        cout << "3. Descripcion de usuario" << endl
	
	int i;
	cin >> i;
	ICtrlUsuario *instancia= ICtrlUsuario::getinstancia();
	Usuario *u = instancia->getusuarioLog();
	if (i==1){
		cout << "Ingrese el nombre" << endl;
		String nombre;
		cin >> nombre;
		u->setnomUsuario(nombre);
                
                DtNotificaciones notificacion = new DtNotificaciones(u->gettelCel(),"nombre",nombre);
                
                u->agregarNotificaciones(notificacion);
                
	} else if (i==2){
		cout << "Ingrese el URL" << endl;
		String URL;
		cin >> URL;
		u->setimaPerfil(URL);
                
                DtNotificaciones notificacion = new DtNotificaciones(u->gettelCel(),"imagen",URL);
                
                u->agregarNotificaciones(notificacion);
	 }else{
                cout << "Ingrese el Descripcion" << endl;
		String Descripcion;
		cin >> Descripcion;
		u->setimaPerfil(Descripcion);
                
                DtNotificaciones notificacion = new DtNotificaciones(u->gettelCel(),"descripcion",Descripcion);
                
                u->agregarNotificaciones(notificacion);
             
         }
	 cout << "1. Seguir modificando" endl;
	 cout << "2. Terminar caso de uso" endl;
	 cin >> i;
	 if (i==1){

	 }else{desea_modificar = false;}
}
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

/*CASO DE USO: ELIMINAR MENSAJE*/

void eliminarMensaje(){
    
    ICtrlUsuario *CI = ICtrlUsuario::getinstancia();

Usuario * user_log = CI->getusuarioLog();

if (user_log != NULL) {
	ICollection * lista_activas = CI->listarActivas();
	int cantidad_archivadas     = CI->cantidadArchivadas();

	if (!lista_activas.isEmpty()) {
		string nombre, tel_cel;
		cout << "Conversaciones activas" << endl;

		for (IIterator *it = lista_activas->getIterator(); it->hasCurrent(); it->next()) {
			Conversacion * c = getCurrent();
			bool es_grupo = c->getesGrupo();
			if (es_grupo) {
				Grupo g = c->getgrupo();
				nombre = g->getnomGrupo();
			} else {
				IDictionary * participantes = getparticipantes();
				/*Es una conversacion Simple, tiene 2 participantes, si no es el usuario logeado entonces es el
				otro*/
				for (IIterator *it_p = participantes->getIterator(); it_p->hasCurrent(); it_p->next()) {
					Usuario * u = getCurrent();
					if (!userlog->gettelCel()->compare(u->gettelCel())) {
						nombre  = u->getnomUsuario();
						tel_cel = u->gettelCel();
					}
				}		
			}
			cout << nombre + " " + tel_cel << endl;
		}
		cout << "" << endl;
		cout << "Archivadas :" + cantidad_archivadas << endl;

		cout << "****************************************" 	<< endl;
		cout << "1. Seleccionar una conversación activa " 	<< endl;
		cout << "2. Ver las conversaciones archivadas" 		<< endl;
		int opcion;
		cout << "Opción: ";
		cin >> opcion;

		if (opcion == 1) {
			cout << "Ingrese el identificador de la conversación activa que desea seleccionar: ";
			int idC;
			cin >> idC;
			IKey * idConv = new int (idC);
			ICollection * mensajes =  CI->mensajesCoversacion (idConv);

			if (!mensajes->isEmpty()) {
				for (IIterator *it_m = mensajes->getIterator(); it_m->hasCurrent(); it_m->next()) {
					Mensaje m = getCurrent();

					if (dynamic_cast<Simple*> (&m) != NULL) {
						//Es Simple
						Simple * mensj = dynamic_cast<Simple*> (&m);
						cout << * mensj << endl;
					} else if (dynamic_cast<Contacto*> (&m) != NULL) {
						//Es Contacto
						Contacto * mensj = dynamic_cast<Contacto*> (&m);
						cout << * mensj << endl;
					} else {
						//Es Multimedia
						if (dynamic_cast<Imagen*> (&m) != NULL) {
							//Es Imagen
							Imagen * mensj = dynamic_cast<Imagen*> (&m);
							cout << * mensj << endl;
						} else {
							//Es Video
							Video * mensj = dynamic_cast<Video*> (&m);
							cout << * mensj << endl;
						}
					}
				}
						
				cout << "Ingrese el código del mensaje que desea eliminar.";
				string codigo;
				cin >> codigo;

				IKey * codigo = new String (codigo);
				CI->eliminarMensaje(codigo, idConv);

			} else {
				throw std::invalid_argument("No hay mensajes para mostrar.");
			}				
		} else if (opcion == 2) {
			cout << "Conversaciones archivadas"	<< endl;
			ICollection * lista_archivadas = CI->listarArchivadas();

			if (!lista_archivadas->isEmpty()) {
				for (IIterator *it = lista_archivadas->getIterator(); it->hasCurrent(); it->next()) {
					Conversacion * c = getCurrent();
					bool es_grupo = c->getesGrupo();
					if (es_grupo) {
						Grupo g = c->getgrupo();
						nombre = g->getnomGrupo();
					} else {
						IDictionary * participantes = getparticipantes();
						/*Es una conversacion Simple, tiene 2 participantes, si no es el usuario logeado entonces es el
						otro*/
						for (IIterator *it_p = participantes->getIterator(); it_p->hasCurrent(); it_p->next()) {
							Usuario * u = getCurrent();
							if (!userlog->gettelCel()->compare(u->gettelCel())) {
								nombre  = u->getnomUsuario();
								tel_cel = u->gettelCel();
							}
						}		
					}
					cout << nombre + " " + tel_cel << endl;	
				}
				cout << "Ingrese el identificador de la conversación archivada que desea seleccionar: ";
				int idC;
				cin >> idC;
				IKey * idConv = new int (idC);

				ICollection * mensajes =  CI->mensajesCoversacion (idConv);
				
				if (!mensajes->isEmpty()) {
					for (IIterator *it_m = mensajes->getIterator(); it_m->hasCurrent(); it_m->next()) {
						Mensaje m = getCurrent();

						if (dynamic_cast<Simple*> (&m) != NULL) {
							//Es Simple
							Simple * mensj = dynamic_cast<Simple*> (&m);
							cout << * mensj << endl;
						} else if (dynamic_cast<Contacto*> (&m) != NULL) {
							//Es Contacto
							Contacto * mensj = dynamic_cast<Contacto*> (&m);
							cout << * mensj << endl;
						} else {
							//Es Multimedia
							if (dynamic_cast<Imagen*> (&m) != NULL) {
								//Es Imagen
								Imagen * mensj = dynamic_cast<Imagen*> (&m);
								cout << * mensj << endl;
							} else {
								//Es Video
								Video * mensj = dynamic_cast<Video*> (&m);
								cout << * mensj << endl;
							}
						}

						cout << "Ingrese el código del mensaje que desea eliminar.";
						string codigo;
						cin >> codigo;

						IKey * codigo = new String (codigo);
						CI->eliminarMensaje(codigo, idConv);
					}
				} else {
					throw std::invalid_argument("No hay mensajes para mostrar.");
				}
			} else {
				throw std::invalid_argument("No tiene conversaciones archivadas.");
			}
		} else {
			throw std::invalid_argument('Opción invalida.');
		}
	} else {
		throw std::invalid_argument('No tiene conversaciones activas.');
	}
} else {
	throw std::invalid_argument('No hay un usuario logeado en el sistema.');
}
    
}

/*CASO DE USO: AGREGAR SUSCRIPTORES*/

void agregarSuscriptores(){
    
    ICtrlUsuario *CI = ICtrlUsuario::getinstancia();
    string numero;
    
    cout << "Ingrese usuario al que desea suscribirse: ";
    cin >> numero;
    
    CI->agregarSuscriptor(new String(numero));
    
}

int main(){
    
    int op = 0;
    
    while(op != ?){
        
        cout << "1.Establecer fecha y hora del sistema" << endl;
        cout << "2.Mostrar fecha y hora del sistema" << endl;
        cout << "3.Abrir Guasap" << endl;
        cout << "4.Cerar Guasap" << endl;
        cout << "5.Agregar Contacto" << endl;
        cout << "6.Alta Grupo" << endl;
        cout << "7.Enviar Mensaje" << endl;
        cout << "8.Ver Mensajes" << endl;
        
    }
}

