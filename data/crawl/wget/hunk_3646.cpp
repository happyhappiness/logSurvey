 msgid "%s: illegal option -- %c\n"
 msgstr "%s: opci�n ilegal -- %c\n"
 
+# nota jjrs: argumento o parametro?
+# mmm... argumento? ;-P -Salva
 #. 1003.2 specifies the format of this message.
 #: src/getopt.c:602
 #, c-format
 msgid "%s: option requires an argument -- %c\n"
 msgstr "%s: la opci�n requiere un argumento -- %c\n"
 
-#: src/host.c:430
-#, c-format
-msgid "%s: Cannot determine user-id.\n"
-msgstr "%s: No se puede determinar el usuario.\n"
-
-#: src/host.c:442
-#, c-format
-msgid "%s: Warning: uname failed: %s\n"
-msgstr "%s: Aviso: fall� uname: %s\n"
-
-#: src/host.c:454
-#, c-format
-msgid "%s: Warning: gethostname failed\n"
-msgstr "%s: Aviso: fall� gethostname\n"
-
-#: src/host.c:482
-#, c-format
-msgid "%s: Warning: cannot determine local IP address.\n"
-msgstr "%s: Aviso: no se puede determinar la direcci�n IP local.\n"
-
-#: src/host.c:496
-#, c-format
-msgid "%s: Warning: cannot reverse-lookup local IP address.\n"
-msgstr ""
-"%s: Aviso: no se puede hacer la b�squeda inversa de la direcci�n IP local.\n"
-
-#. This gets ticked pretty often.  Karl Berry reports
-#. that there can be valid reasons for the local host
-#. name not to be an FQDN, so I've decided to remove the
-#. annoying warning.
-#: src/host.c:509
-#, c-format
-msgid "%s: Warning: reverse-lookup of local address did not yield FQDN!\n"
-msgstr "%s: Aviso: �La b�squeda reversa de la direcci�n local no dio un FQDN!\n"
-
-#: src/host.c:537
+# �Con la Iglesia y el Ej�rcito hemos ido a topar! :)
+#
+# Lo de `host' puede dar lugar a una aut�ntica discusi�n, ... Te ruego
+# por favor que, si no est�s de acuerdo conmigo, te dirijas a la lista
+# para discutirlo all� p�blicamente, ... Es importante que todos los
+# miembros de Spanish GNU Translation Team actuemos de la misma manera
+# y, en este caso, el convenio es emplear el t�rmino `anfitri�n' para
+# `host'. De hecho, yo lo he hecho en la traducci�n del CLisp y empieza
+# a ser habitual verlo en el software comercial traducido al espa�ol, y
+# si no, echa un ojo a los juegos de LucasArts, ... - cll
+#
+#: src/host.c:374
 msgid "Host not found"
-msgstr "Nombre de m�quina no encontrado"
+msgstr "No se ha encontrado el anfitri�n"
 
-#: src/host.c:539
+#: src/host.c:376
 msgid "Unknown error"
 msgstr "Error desconocido"
 
-#: src/html.c:615 src/html.c:617
-#, c-format
-msgid "Index of /%s on %s:%d"
-msgstr "�ndice de /%s en %s:%d"
-
-#: src/html.c:639
-msgid "time unknown       "
-msgstr "tiempo desconocido "
+#. this is fatal
+#: src/http.c:554
+msgid "Failed to set up an SSL context\n"
+msgstr "No se pudo configurar un contexto SSL\n"
 
-#: src/html.c:643
-msgid "File        "
-msgstr "Archivo     "
+#: src/http.c:560
+#, c-format
+msgid "Failed to load certificates from %s\n"
+msgstr "No se pudo descargar los certificados desde %s\n"
 
-#: src/html.c:646
-msgid "Directory   "
-msgstr "Directorio  "
+#: src/http.c:564 src/http.c:572
+msgid "Trying without the specified certificate\n"
+msgstr "Intent�ndolo sin el certificado especificado\n"
 
-#: src/html.c:649
-msgid "Link        "
-msgstr "Enlace      "
+#: src/http.c:568
+#, c-format
+msgid "Failed to get certificate key from %s\n"
+msgstr "No se pudo obtener la clave certificadora desde %s\n"
 
-#: src/html.c:652
-msgid "Not sure    "
-msgstr "No es seguro"
+#: src/http.c:662 src/http.c:1592
+msgid "Unable to establish SSL connection.\n"
+msgstr "No se pudo establecer la conexi�n SSL.\n"
 
-#: src/html.c:670
+#: src/http.c:670
 #, c-format
-msgid " (%s bytes)"
-msgstr ""
+msgid "Reusing connection to %s:%hu.\n"
+msgstr "Reutilizando la conexi�n con %s:%hu.\n"
 
-#: src/http.c:515
-msgid "Failed writing HTTP request.\n"
-msgstr "Fall� la escritura del requerimiento HTTP.\n"
+#: src/http.c:860
+#, c-format
+msgid "Failed writing HTTP request: %s.\n"
+msgstr "Fallo escribiendo petici�n HTTP: %s.\n"
 
-#: src/http.c:519
+#: src/http.c:865
 #, c-format
 msgid "%s request sent, awaiting response... "
-msgstr "Requerimiento %s enviado, esperando respuesta... "
+msgstr "Petici�n %s enviada, esperando respuesta... "
 
-#: src/http.c:558
+#: src/http.c:909
 msgid "End of file while parsing headers.\n"
-msgstr "Final de archivo mientras se analizaban las cabeceras.\n"
+msgstr "Fin de fichero mientras se analizaban las cabeceras.\n"
 
-#: src/http.c:569
+#: src/http.c:919
 #, c-format
 msgid "Read error (%s) in headers.\n"
 msgstr "Error de lectura (%s) en las cabeceras.\n"
 
-#: src/http.c:609
+#: src/http.c:958
 msgid "No data received"
-msgstr "No se recibieron datos"
+msgstr "No se han recibido datos"
 
-#: src/http.c:611
+# Piiiiii: escuchemos a los super-taca�ones :)
+#
+# Como no existe el verbo "malformar" en espa�ol, el participio
+# `malformado' es incorrecto. El �nico t�rmino parecido a �ste que
+# existe en espa�ol es `malformaci�n'. - cll
+#: src/http.c:960
 msgid "Malformed status line"
-msgstr "L�nea de status mal formada"
+msgstr "L�nea de estado mal formada"
 
-#: src/http.c:616
+#: src/http.c:965
 msgid "(no description)"
 msgstr "(sin descripci�n)"
 
-#. If we have tried it already, then there is not point
-#. retrying it.
-#: src/http.c:700
+# En vez de `fall� la autorizaci�n' me parece m�s apropiado
+# `Autorizaci�n denegada' - cll
+#
+#: src/http.c:1088
 msgid "Authorization failed.\n"
-msgstr "Fall� autorizaci�n.\n"
+msgstr "Autorizaci�n denegada.\n"
 
-#: src/http.c:707
+#: src/http.c:1095
 msgid "Unknown authentication scheme.\n"
-msgstr "Esquema de autentificaci�n desconocido.\n"
+msgstr "M�todo de autentificaci�n desconocido.\n"
 
-#: src/http.c:790
+#: src/http.c:1135
 #, c-format
 msgid "Location: %s%s\n"
-msgstr "Ubicaci�n: %s%s\n"
+msgstr "Localizaci�n: %s%s\n"
 
-#: src/http.c:791 src/http.c:816
+#: src/http.c:1136 src/http.c:1268
 msgid "unspecified"
 msgstr "no especificado"
 
-#: src/http.c:792
+# Duda: Hmmm, ... �`siguiendo' o `siguiente'? - cll
+# siguiendo - Salva
+#
+#: src/http.c:1137
 msgid " [following]"
 msgstr " [siguiendo]"
 
+#: src/http.c:1199
+msgid "\n    The file is already fully retrieved; nothing to do.\n\n"
+msgstr "\n    El fichero ya ha sido totalmente recuperado, no hay nada que hacer.\n\n"
+
+#: src/http.c:1215
+#, c-format
+msgid ""
+"\n"
+"The server does not support continued downloads, which conflicts with `-c'.\n"
+"Refusing to truncate existing file `%s'.\n"
+"\n"
+msgstr ""
+"\n"
+"El servidor no permite continuar descargas, lo que choca con la opci�n `-c'.\n"
+"Se rechaza truncar el fichero existente `%s'.\n"
+"\n"
+
 #. No need to print this output if the body won't be
 #. downloaded at all, or if the original server response is
 #. printed.
-#: src/http.c:806
+#: src/http.c:1258
 msgid "Length: "
-msgstr "Tama�o: "
+msgstr "Longitud: "
 
-#: src/http.c:811
+#: src/http.c:1263
 #, c-format
 msgid " (%s to go)"
-msgstr " (faltan %s)"
+msgstr " (%s para acabar)"
 
-#: src/http.c:816
+#: src/http.c:1268
 msgid "ignored"
-msgstr "se ignora"
+msgstr "descartado"
 
-#: src/http.c:917
+#: src/http.c:1398
 msgid "Warning: wildcards not supported in HTTP.\n"
-msgstr "Aviso: no se soportan comodines en HTTP.\n"
+msgstr "Atenci�n: no se admiten comodines en HTTP.\n"
 
+# Has traducido `retrieve' como `recuperar' todo el rato, ... �por qu�
+# lo cambias ahora?. Te lo pongo de nuevo como `recuperar' - cll
+# jjr no solo revis�, sino que adem�s tradujo bastante cacho del po,
+# seguramente se debe a eso - Salva
+#
 #. If opt.noclobber is turned on and file already exists, do not
 #. retrieve the file
-#: src/http.c:938
+#: src/http.c:1416
 #, c-format
 msgid "File `%s' already there, will not retrieve.\n"
-msgstr "El archivo `%s' ya est�, no se trae.\n"
+msgstr "El fichero '%s' ya existe, no se recuperar�.\n"
 
-#: src/http.c:1088
+#: src/http.c:1584
 #, c-format
 msgid "Cannot write to `%s' (%s).\n"
-msgstr "No se pudo escribir a `%s' (%s).\n"
+msgstr "No se puede escribir a `%s' (%s).\n"
 
-#: src/http.c:1099
+#: src/http.c:1601
 #, c-format
 msgid "ERROR: Redirection (%d) without location.\n"
-msgstr "ERROR: Redirecci�n (%d) sin `location'.\n"
+msgstr "ERROR: redirecci�n (%d) sin localizaci�n.\n"
 
-#: src/http.c:1124
+#: src/http.c:1629
 #, c-format
 msgid "%s ERROR %d: %s.\n"
-msgstr ""
+msgstr "%s ERROR %d: %s.\n"
 
-#: src/http.c:1137
+# as� se entiende mejor -Salva
+#: src/http.c:1641
 msgid "Last-modified header missing -- time-stamps turned off.\n"
-msgstr "Falta cabecera Last-modified -- no se usar� time-stamps.\n"
+msgstr "Falta la fecha de la �ltima modificaci�n -- marcas de tiempo apagadas.\n"
 
-#: src/http.c:1145
+#: src/http.c:1649
 msgid "Last-modified header invalid -- time-stamp ignored.\n"
-msgstr "Cabecera Last-modified inv�lido -- se ignora el time-stamp.\n"
+msgstr "La fecha de �ltima modificaci�n es inv�lida -- marca de tiempo descartada.\n"
+
+#: src/http.c:1672
+#, c-format
+msgid "Server file no newer than local file `%s' -- not retrieving.\n\n"
+msgstr "El fichero del servidor no es m�s moderno que el fichero local `%s' -- no se descargar�.\n\n"
+
+#: src/http.c:1679
+#, c-format
+msgid "The sizes do not match (local %ld) -- retrieving.\n"
+msgstr "Los tama�os no concuerdan (%ld local), recuperando.\n"
 
-#: src/http.c:1180
+#: src/http.c:1683
 msgid "Remote file is newer, retrieving.\n"
-msgstr "El archivo remoto es m�s nuevo, se lo trae.\n"
+msgstr "El fichero remoto es nuevo, recuperando.\n"
 
-#: src/http.c:1225
+#: src/http.c:1727
 #, c-format
-msgid ""
-"%s (%s) - `%s' saved [%ld/%ld]\n"
-"\n"
-msgstr ""
-"%s (%s) - `%s' guardado [%ld/%ld]\n"
-"\n"
+msgid "%s (%s) - `%s' saved [%ld/%ld]\n\n"
+msgstr "%s (%s) - `%s' guardado [%ld/%ld]\n\n"
 
-#: src/http.c:1273
+#: src/http.c:1773
 #, c-format
 msgid "%s (%s) - Connection closed at byte %ld. "
-msgstr "%s (%s) - La conexi�n se cerr� en el byte %ld. "
+msgstr "%s (%s) - Conexi�n cerrada en el byte %ld. "
 
-#: src/http.c:1281
+#: src/http.c:1781
 #, c-format
-msgid ""
-"%s (%s) - `%s' saved [%ld/%ld])\n"
-"\n"
-msgstr ""
-"%s (%s) - %s' guardado [%ld/%ld])\n"
-"\n"
+msgid "%s (%s) - `%s' saved [%ld/%ld])\n\n"
+msgstr "%s (%s) - `%s' guardado [%ld/%ld])\n\n"
 
-#: src/http.c:1301
+#: src/http.c:1800
 #, c-format
 msgid "%s (%s) - Connection closed at byte %ld/%ld. "
-msgstr "%s (%s) - La conexi�n se cerr� en el byte %ld/%ld. "
+msgstr "%s (%s) - Conexi�n cerrada en el byte %ld/%ld. "
 
-#: src/http.c:1312
+#: src/http.c:1811
 #, c-format
 msgid "%s (%s) - Read error at byte %ld (%s)."
 msgstr "%s (%s) - Error de lectura en el byte %ld (%s)."
 
-#: src/http.c:1320
+#: src/http.c:1819
 #, c-format
 msgid "%s (%s) - Read error at byte %ld/%ld (%s). "
-msgstr "%s (%s) - Error de lectura en el byte %ld/%ld (%s). "
+msgstr "%s (%s) - Error de lectura en el byte %ld/%ld (%s)."
 
-#: src/init.c:329 src/netrc.c:260
+#: src/init.c:348 src/netrc.c:267
 #, c-format
 msgid "%s: Cannot read %s (%s).\n"
-msgstr "%s: No se puede leer %s (%s).\n"
+msgstr "%s: No se pudo leer %s (%s).\n"
 
-#: src/init.c:347 src/init.c:353
+#: src/init.c:366 src/init.c:372
 #, c-format
 msgid "%s: Error in %s at line %d.\n"
-msgstr "%s: Error en %s, l�nea %d.\n"
+msgstr "%s: Error en %s en la l�nea %d.\n"
 
-#: src/init.c:384
+#: src/init.c:404
 #, c-format
 msgid "%s: Warning: Both system and user wgetrc point to `%s'.\n"
-msgstr "%s: Aviso: El wgetrc de usuario y el de sistema apuntan a `%s'.\n"
+msgstr "%s: Atenci�n: tanto el fichero wgetrc de usuario como el del sistema apuntan a `%s'.\n"
 
-#: src/init.c:476
+#: src/init.c:496
 #, c-format
 msgid "%s: BUG: unknown command `%s', value `%s'.\n"
-msgstr "%s: BUG: comando desconocido `%s', valor `%s'.\n"
+msgstr "%s: Error: orden desconocida `%s', valor `%s'.\n"
 
-#: src/init.c:497
+# �No debiera ser la `direcci�n IP local'? - cll
+# uups - Salva
+#: src/init.c:528
 #, c-format
 msgid "%s: %s: Cannot convert `%s' to an IP address.\n"
-msgstr "%s: %s: No se puede convertir `%s' a una direcci�n IP.\n"
+msgstr "%s: %s: no se pudo convertir `%s' en una direcci�n IP.\n"
 
-#: src/init.c:525
+# Te cambio la `o' antes de `off' por `u' - cll
+#
+#: src/init.c:558
 #, c-format
 msgid "%s: %s: Please specify on or off.\n"
-msgstr "%s: %s: Especifique `on' u `off'.\n"
+msgstr "%s: %s: por favor, especifique on u off.\n"
 
-#: src/init.c:569
+# Te cambio la `o' antes de `off' por `u' - cll
+#: src/init.c:602
 #, c-format
 msgid "%s: %s: Please specify always, on, off, or never.\n"
-msgstr "%s: %s: Por favor especifique `always', `on', `off' o `never'.\n"
+msgstr "%s: %s: por favor especifique siempre, on, off, o nunca.\n"
 
-#: src/init.c:588 src/init.c:845 src/init.c:867 src/init.c:931
+#: src/init.c:621 src/init.c:918 src/init.c:940 src/init.c:1004
 #, c-format
 msgid "%s: %s: Invalid specification `%s'.\n"
-msgstr "%s: %s: Especificaci�n `%s' inv�lida.\n"
+msgstr "%s: %s: especificaci�n inv�lida `%s'.\n"
 
-#: src/init.c:701 src/init.c:723 src/init.c:745 src/init.c:771
+#: src/init.c:774 src/init.c:796 src/init.c:818 src/init.c:844
 #, c-format
 msgid "%s: Invalid specification `%s'\n"
-msgstr "%s: Especificaci�n `%s' inv�lida.\n"
+msgstr "%s: especificaci�n inv�lida `%s'\n"
 
-#: src/main.c:107
+#: src/main.c:119
 #, c-format
 msgid "Usage: %s [OPTION]... [URL]...\n"
-msgstr "Uso: %s [OPCI�N]... [URL]...\n"
+msgstr "Modo de empleo: %s [OPCI�N]... [URL]...\n"
 
-#: src/main.c:115
+#: src/main.c:127
 #, c-format
 msgid "GNU Wget %s, a non-interactive network retriever.\n"
-msgstr "GNU Wget %s, un recuperador de datos de red no interactivo.\n"
+msgstr "GNU Wget %s, un recuperador por red no interactivo.\n"
 
+# Duda: �por qu� has insertado manualmente un `\n'? �es realmente
+# necesario? Probablemente s�, pero yo normalmente traduzco todo en la
+# misma l�nea, ... - cll
+# Hombre, as� deber�a quedar bastante mejor (adem�s creo que no es la �nica vez
+# que lo he hecho), espero que no de problemas. - Salva
+#
 #. Had to split this in parts, so the #@@#%# Ultrix compiler and cpp
 #. don't bitch.  Also, it makes translation much easier.
-#: src/main.c:120
-msgid ""
-"\n"
-"Mandatory arguments to long options are mandatory for short options too.\n"
-"\n"
+#: src/main.c:132
+msgid "\nMandatory arguments to long options are mandatory for short options too.\n\n"
 msgstr ""
 "\n"
-"Los argumentos obligatorios para las opciones largas tambi�n lo son para\n"
-"las cortas.\n"
+"Los argumentos obligatorios para las opciones largas son tambi�n obligatorios\n"
+"para las opciones cortas.\n"
 "\n"
 
-#: src/main.c:123
+# Primero, simplemente pongo `wget' con `W'. Es una pijada :) pero es
+# por hacerlo como en el mensaje original, ...rc' contendr� una
+# orden y, sin embargo, cualquier usuario imaginar� que, al ser un
+# fichero con un nombre acabado en `rc', ser� un fichero de
+# recursos. Esto es, no s�lo servir� para ejecutar varias �rdenes al
+# inicio de Wget, sino que adem�s, probablemente servir� para configurar
+# su ejecuci�n. Por todo ello, �qu� tal te suena `ejecuta el fichero de
+# �rdenes .wgetrc'?. De momento, yo te lo pongo as�, ... - cll
+# bien - Salva
+#
+# --execute ejecuta una orden `del estilo de las incluidas en .wgetrc'
+# (nl)
+#
+#: src/main.c:136
 msgid ""
 "Startup:\n"
 "  -V,  --version           display the version of Wget and exit.\n"
