//Caso enviar mensaje
/*El caso de uso comienza cuando un usuario, que previamente ha iniciado sesión,
desea enviar un mensaje.
Primero, el sistema lista las conversaciones del usuario. Para cada conversación
activa, si se corresponde a un grupo se muestra el nombre del grupo. Si es una
conversación simple, se muestra nombre y número de celular del contacto con el
cual se mantiene la misma. Para el caso de las conversaciones archivadas, se muestra una sola entrada con la etiqueta “Archivadas” y la cantidad de
conversaciones archivadas.
A continuación, el usuario puede elegir entre las siguientes opciones:
1. Seleccionar una conversación activa
2. Ver las conversaciones archivadas
3. Enviar un mensaje a un contacto con el cuál aún no ha iniciado una
conversación
Si el usuario elige la primera opción, luego ingresa el identificador de la
conversación activa que quiere seleccionar.
En caso de elegir la segunda opción, el sistema lista las conversaciones
archivadas de igual forma a la que se listan las conversaciones activas. Luego el
usuario ingresa el identificador de la conversación archivada que quiere
seleccionar.
Si elige la tercera opción, el sistema lista todos los contactos del usuario,
mostrando para cada uno su número de celular y nombre. Luego el usuario
indica el contacto con el cual quiere iniciar la conversación individual,
ingresando el número de celular del mismo.
Posteriormente, el usuario elige el tipo de mensaje que desea enviar entre las
opciones simple, imagen, video o contacto. En caso de elegir un mensaje simple
debe ingresar el texto a enviar. En el caso de una imagen, debe ingresar su URL,
formato, tamaño y de forma opcional un texto descriptivo de la imagen. En caso
de elegir un video debe ingresar la URL del mismo y la duración. Por último, si
elige un contacto, el sistema lista el nombre y número de celular de todos los
contactos del usuario. Luego el usuario selecciona el contacto que desea
compartir ingresando el número de celular del mismo.
Finalmente, el sistema crea el mensaje con un código identificatorio
autogenerado por el sistema y la fecha y hora de envío con la fecha y hora actual
del sistema. Adicionalmente, en caso que el mensaje sea enviado en una
conversación archivada, la misma se convierte en activa. Por último, el mensaje
se agrega como no visto.
En caso que el usuario no participe en ninguna conversación, el sistema muestra
un mensaje apropiado y se finaliza el caso de uso. Este comportamiento se repite
para situaciones análogas.*/

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