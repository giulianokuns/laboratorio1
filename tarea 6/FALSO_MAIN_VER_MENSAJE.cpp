//Caso de uso: Ver Mensaje

/*El caso de uso comienza cuando un usuario, que previamente ha iniciado
sesión, desea ver los mensajes de una conversación.
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
usuario fue añadido al grupo. Además, marca aquellos mensajes mostrados
en el cual el usuario es receptor como mensaje visto registrando la fecha y
hora de visto con la fecha y hora actual del sistema.
Finalmente, el usuario puede elegir ver información adicional de sus
mensajes enviados. Seleccionando un mensaje enviado, el sistema muestra
el nombre y número de celular de los receptores que lo han visto junto con
la fecha y hora en que lo hicieron. Esto lo repite para los mensajes que
desee.
Luego, finaliza el caso de uso.
En caso que el usuario no participe en ninguna conversación, el sistema
muestra un aviso y se finaliza el caso de uso. En situaciones análogas se
procede de la misma manera.

Los datos de los mensajes corresponden al valor de sus atributos más la
información de visto en el caso de mensajes enviados por el usuario.*/

cout << "1. " << endl;
cout << "2. " << endl;
cout << "3. Salir" << endl;

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


		cout << "1. Seleccionar una conversación activa " 	<< endl;
		cout << "2. Ver las conversaciones archivadas" 		<< endl;
		int opcion;
		cout << "Opción: ";
		cin >> opcion;

		if (opcion == 1) {
			cout << "Ingrese el identificador de la conversación activa que desea seleccionar: ";
			IKey idConv;
			cin >> idConv;

			ICollection mensaje =  CI->mensajesCoversacion (idConv);
			//Todos los datos de los mensajes AYQQ
			
		} else if (opcion == 2) {
			cout << "Conversaciones archivadas"	<< endl;
			ICollection * lista_archivadas = CI->listarArchivadas();

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
			IKey idConv;
			cin >> idConv;

			ICollection mensaje =  CI->mensajesCoversacion (idConv);
			//Todos los datos de los mensajes AYQQ
		} else {
			throw std::invalid_argument('Opción invalida.')
		}
	} else {
		throw std::invalid_argument('No tiene conversaciones activas.')
	}
} else {
	throw std::invalid_argument('No hay un usuario logeado en el sistema.')
}