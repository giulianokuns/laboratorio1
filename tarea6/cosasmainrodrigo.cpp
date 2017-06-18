
MODIFICAR USUARIO

bool desea_modificar = true;
while(desea_modificar){
	cout << "Que desea modificar?" endl;
	cout << "1. Nombre de usuario" endl;
	cout << "2. URL de la imagen" endl;
	
	int i;
	cin >> i;
	ICtrlUsuario *instancia= ICtrlUsuario::getinstancia();
	Usuario *u = instancia->getusuarioLog();
	if (i==1){
		cout << "Ingrese el nombre" endl;
		String nombre;
		cin >> nombre;
		u->setnomUsuario(nombre);
	} else{
		cout << "Ingrese el URL" endl;
		String URL;
		cin >> URL;
		u->setimaPerfil(String URL);
	 }
	 cout << "1. Seguir modificando" endl;
	 cout << "2. Terminar caso de uso" endl;
	 cin >> i;
	 if (i==1){

	 }else{desea_modificar = false;}
}





ALTA GRUPO
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
}





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
//se libera memoria





AGREGAR CONTACTO 

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
}	
//listo contactos
//ingrese el telefono del contacto que desea agregar
//sea agrega
//desea agregar otro contacto?


