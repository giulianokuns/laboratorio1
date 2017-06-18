/*
El caso de uso comienza cuando un usuario, que previamente ha iniciado
sesión, desea eliminar un mensaje.
Primero, el sistema lista las conversaciones del usuario. Para cada
conversación activa, si se corresponde a un grupo se muestra el nombre del
grupo. Si es una conversación simple, se muestra nombre y número de
celular del contacto con el cual se mantiene la misma. Para el caso de las
conversaciones archivadas, se muestra una sola entrada con la etiqueta
“Archivadas” y la cantidad de conversaciones archivadas.
A continuación, el usuario puede elegir entre las siguientes opciones:
1. Seleccionar una conversación activa
2. Ver las conversaciones archivadas
Si el usuario elige la primera opción, luego ingresa el identificador de la
conversación activa que quiere seleccionar.
En caso de elegir la segunda opción, el sistema lista las conversaciones
archivadas de igual forma a la que se listan las conversaciones activas.
Luego el usuario ingresa el identificador de la conversación archivada que
quiere seleccionar.
A continuación, el sistema muestra todos los datos de los mensajes de esa
conversación. En caso de que sea de un grupo, sólo muestra los mensajes
cuya fecha y hora de envío sea mayor o igual a la fecha y hora en que el
usuario fue añadido al grupo.
Finalmente el usuario selecciona el mensaje que desea eliminar. Si el
usuario es el emisor del mensaje, el sistema elimina el mensaje
desvinculándolo incluso de la conversación y de manera que no pueda ser
visto ni por su emisor ni por sus receptores en el futuro. Si el usuario es
receptor del mensaje se lo elimina de manera que pueda ser visto por el
emisor y los otros receptores. Dicho de otra forma, el primer caso
corresponde a una eliminación física y en el segundo caso a una eliminación
lógica para el usuario.
En caso que el usuario no participe en ninguna conversación, el sistema
muestra un aviso y se finaliza el caso de uso. En situaciones análogas se
procede de la misma manera.
*/

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
