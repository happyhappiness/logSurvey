#. No luck.
#. #### This message SUCKS.  We should see what was the
#. reason that nothing was retrieved.
#: src/ftp.c:1608
#, c-format
msgid "No matches on pattern `%s'.\n"
msgstr "No hay nada que se ajuste al patr�n `%s'.\n"

#: src/ftp.c:1673
#, c-format
msgid "Wrote HTML-ized index to `%s' [%ld].\n"
msgstr "Se escribi� un �ndice en HTML a `%s' [%ld].\n"

#: src/ftp.c:1678
#, c-format
msgid "Wrote HTML-ized index to `%s'.\n"
msgstr "Se escribi� un �ndice en HTML a `%s'.\n"

#: src/gen_sslfunc.c:109
msgid "Could not seed OpenSSL PRNG; disabling SSL.\n"
msgstr "No se pudo alimentar el PRNG de OpenSSL; deshabilitando SSL.\n"

#: src/getopt.c:454
#, c-format
msgid "%s: option `%s' is ambiguous\n"
msgstr "%s: la opci�n `%s' es ambigua\n"

#: src/getopt.c:478
#, c-format
msgid "%s: option `--%s' doesn't allow an argument\n"
msgstr "%s: la opci�n `--%s' no admite ning�n argumento\n"

#: src/getopt.c:483
#, c-format
msgid "%s: option `%c%s' doesn't allow an argument\n"
msgstr "%s: la opci�n `%c%s' no admite ning�n argumento\n"

#: src/getopt.c:498
#, c-format
msgid "%s: option `%s' requires an argument\n"
msgstr "%s: la opci�n `%s' requiere un argumento\n"

#. --option
#: src/getopt.c:528
#, c-format
msgid "%s: unrecognized option `--%s'\n"
msgstr "%s: opci�n no reconocida `--%s'\n"

#. +option or -option
#: src/getopt.c:532
#, c-format
msgid "%s: unrecognized option `%c%s'\n"
msgstr "%s: opci�n no reconocida `%c%s\n"

#. 1003.2 specifies the format of this message.
#: src/getopt.c:563
#, c-format
msgid "%s: illegal option -- %c\n"
msgstr "%s: opci�n ilegal -- %c\n"

# nota jjrs: argumento o parametro?
# mmm... argumento? ;-P -Salva
#. 1003.2 specifies the format of this message.
#: src/getopt.c:602
#, c-format
msgid "%s: option requires an argument -- %c\n"
msgstr "%s: la opci�n requiere un argumento -- %c\n"

#: src/host.c:271
#, c-format
msgid "Resolving %s... "
msgstr "Resolviendo %s... "

#: src/host.c:278
#, c-format
msgid "failed: %s.\n"
msgstr "fall�: %s.\n"

# �Con la Iglesia y el Ej�rcito hemos ido a topar! :)
#
# Lo de `host' puede dar lugar a una aut�ntica discusi�n, ... Te ruego
# por favor que, si no est�s de acuerdo conmigo, te dirijas a la lista
# para discutirlo all� p�blicamente, ... Es importante que todos los
# miembros de Spanish GNU Translation Team actuemos de la misma manera
# y, en este caso, el convenio es emplear el t�rmino `anfitri�n' para
# `host'. De hecho, yo lo he hecho en la traducci�n del CLisp y empieza
# a ser habitual verlo en el software comercial traducido al espa�ol, y
# si no, echa un ojo a los juegos de LucasArts, ... - cll
#
#: src/host.c:348
msgid "Host not found"
msgstr "No se ha encontrado el anfitri�n"

#: src/host.c:350
msgid "Unknown error"
msgstr "Error desconocido"

#: src/html-url.c:336
#, c-format
msgid "%s: Cannot resolve incomplete link %s.\n"
msgstr "%s: no se pudo resolver el enlace incompleto %s.\n"

#. this is fatal
#: src/http.c:573
msgid "Failed to set up an SSL context\n"
msgstr "No se pudo configurar un contexto SSL\n"

#: src/http.c:579
#, c-format
msgid "Failed to load certificates from %s\n"
msgstr "No se pudo descargar los certificados desde %s\n"

#: src/http.c:583 src/http.c:591
msgid "Trying without the specified certificate\n"
msgstr "Intent�ndolo sin el certificado especificado\n"

#: src/http.c:587
#, c-format
msgid "Failed to get certificate key from %s\n"
msgstr "No se pudo obtener la clave certificadora desde %s\n"

#: src/http.c:657 src/http.c:1620
msgid "Unable to establish SSL connection.\n"
msgstr "No se pudo establecer la conexi�n SSL.\n"

#: src/http.c:666
#, c-format
msgid "Reusing connection to %s:%hu.\n"
msgstr "Reutilizando la conexi�n con %s:%hu.\n"

#: src/http.c:868
#, c-format
msgid "Failed writing HTTP request: %s.\n"
msgstr "Fallo escribiendo petici�n HTTP: %s.\n"

#: src/http.c:873
#, c-format
msgid "%s request sent, awaiting response... "
msgstr "Petici�n %s enviada, esperando respuesta... "

#: src/http.c:917
msgid "End of file while parsing headers.\n"
msgstr "Fin de fichero mientras se analizaban las cabeceras.\n"

#: src/http.c:927
#, c-format
msgid "Read error (%s) in headers.\n"
msgstr "Error de lectura (%s) en las cabeceras.\n"

#: src/http.c:962
msgid "No data received"
msgstr "No se han recibido datos"

# Piiiiii: escuchemos a los super-taca�ones :)
#
# Como no existe el verbo "malformar" en espa�ol, el participio
# `malformado' es incorrecto. El �nico t�rmino parecido a �ste que
# existe en espa�ol es `malformaci�n'. - cll
#: src/http.c:964
msgid "Malformed status line"
msgstr "L�nea de estado mal formada"

#: src/http.c:969
msgid "(no description)"
msgstr "(sin descripci�n)"

# En vez de `fall� la autorizaci�n' me parece m�s apropiado
# `Autorizaci�n denegada' - cll
#
#: src/http.c:1101
msgid "Authorization failed.\n"
msgstr "Autorizaci�n denegada.\n"

#: src/http.c:1108
msgid "Unknown authentication scheme.\n"
msgstr "M�todo de autentificaci�n desconocido.\n"

#: src/http.c:1148
#, c-format
msgid "Location: %s%s\n"
msgstr "Localizaci�n: %s%s\n"

#: src/http.c:1149 src/http.c:1282
msgid "unspecified"
msgstr "no especificado"

# Duda: Hmmm, ... �`siguiendo' o `siguiente'? - cll
# siguiendo - Salva
#
#: src/http.c:1150
msgid " [following]"
msgstr " [siguiendo]"

#: src/http.c:1213
msgid "\n    The file is already fully retrieved; nothing to do.\n\n"
msgstr "\n    El fichero ya ha sido totalmente recuperado, no hay nada que hacer.\n\n"

#: src/http.c:1229
#, c-format
msgid ""
"\n"
"Continued download failed on this file, which conflicts with `-c'.\n"
"Refusing to truncate existing file `%s'.\n"
"\n"
msgstr ""
"\n"
"No se pudo continuar la descarga de este fichero, lo que choca con `-c'.\n"
"Se rechaza truncar el fichero existente `%s'.\n"
"\n"

#. No need to print this output if the body won't be
#. downloaded at all, or if the original server response is
#. printed.
#: src/http.c:1272
msgid "Length: "
msgstr "Longitud: "

#: src/http.c:1277
#, c-format
msgid " (%s to go)"
msgstr " (%s para acabar)"

#: src/http.c:1282
msgid "ignored"
msgstr "descartado"

#: src/http.c:1413
msgid "Warning: wildcards not supported in HTTP.\n"
msgstr "Atenci�n: no se admiten comodines en HTTP.\n"

# Has traducido `retrieve' como `recuperar' todo el rato, ... �por qu�
# lo cambias ahora?. Te lo pongo de nuevo como `recuperar' - cll
# jjr no solo revis�, sino que adem�s tradujo bastante cacho del po,
# seguramente se debe a eso - Salva
#
#. If opt.noclobber is turned on and file already exists, do not
#. retrieve the file
#: src/http.c:1443
#, c-format
msgid "File `%s' already there, will not retrieve.\n"
msgstr "El fichero '%s' ya existe, no se recuperar�.\n"

#: src/http.c:1611
#, c-format
msgid "Cannot write to `%s' (%s).\n"
msgstr "No se puede escribir a `%s' (%s).\n"

#: src/http.c:1630
#, c-format
msgid "ERROR: Redirection (%d) without location.\n"
msgstr "ERROR: redirecci�n (%d) sin localizaci�n.\n"

#: src/http.c:1662
#, c-format
msgid "%s ERROR %d: %s.\n"
msgstr "%s ERROR %d: %s.\n"

# as� se entiende mejor -Salva
#: src/http.c:1675
msgid "Last-modified header missing -- time-stamps turned off.\n"
msgstr "Falta la fecha de la �ltima modificaci�n -- marcas de tiempo apagadas.\n"

#: src/http.c:1683
msgid "Last-modified header invalid -- time-stamp ignored.\n"
msgstr "La fecha de �ltima modificaci�n es inv�lida -- marca de tiempo descartada.\n"

#: src/http.c:1706
#, c-format
msgid "Server file no newer than local file `%s' -- not retrieving.\n\n"
msgstr "El fichero del servidor no es m�s moderno que el fichero local `%s' -- no se descargar�.\n\n"

#: src/http.c:1714
#, c-format
msgid "The sizes do not match (local %ld) -- retrieving.\n"
msgstr "Los tama�os no concuerdan (%ld local), recuperando.\n"

#: src/http.c:1718
msgid "Remote file is newer, retrieving.\n"
msgstr "El fichero remoto es nuevo, recuperando.\n"

#: src/http.c:1759
#, c-format
msgid "%s (%s) - `%s' saved [%ld/%ld]\n\n"
msgstr "%s (%s) - `%s' guardado [%ld/%ld]\n\n"

#: src/http.c:1809
#, c-format
msgid "%s (%s) - Connection closed at byte %ld. "
msgstr "%s (%s) - Conexi�n cerrada en el byte %ld. "

#: src/http.c:1818
#, c-format
msgid "%s (%s) - `%s' saved [%ld/%ld])\n\n"
msgstr "%s (%s) - `%s' guardado [%ld/%ld])\n\n"

#: src/http.c:1839
#, c-format
msgid "%s (%s) - Connection closed at byte %ld/%ld. "
msgstr "%s (%s) - Conexi�n cerrada en el byte %ld/%ld. "

#: src/http.c:1851
#, c-format
msgid "%s (%s) - Read error at byte %ld (%s)."
msgstr "%s (%s) - Error de lectura en el byte %ld (%s)."

#: src/http.c:1860
#, c-format
msgid "%s (%s) - Read error at byte %ld/%ld (%s). "
msgstr "%s (%s) - Error de lectura en el byte %ld/%ld (%s)."

#: src/init.c:355 src/netrc.c:265
#, c-format
msgid "%s: Cannot read %s (%s).\n"
msgstr "%s: No se pudo leer %s (%s).\n"

#: src/init.c:373 src/init.c:379
#, c-format
msgid "%s: Error in %s at line %d.\n"
msgstr "%s: Error en %s en la l�nea %d.\n"

#: src/init.c:411
#, c-format
msgid "%s: Warning: Both system and user wgetrc point to `%s'.\n"
msgstr "%s: Atenci�n: tanto el fichero wgetrc de usuario como el del sistema apuntan a `%s'.\n"

#: src/init.c:503
#, c-format
msgid "%s: BUG: unknown command `%s', value `%s'.\n"
msgstr "%s: Error: orden desconocida `%s', valor `%s'.\n"

# �No debiera ser la `direcci�n IP local'? - cll
# uups - Salva
#: src/init.c:537
#, c-format
msgid "%s: %s: Cannot convert `%s' to an IP address.\n"
msgstr "%s: %s: no se pudo convertir `%s' en una direcci�n IP.\n"

# Te cambio la `o' antes de `off' por `u' - cll
#
#: src/init.c:570
#, c-format
msgid "%s: %s: Please specify on or off.\n"
msgstr "%s: %s: por favor, especifique on u off.\n"

# Te cambio la `o' antes de `off' por `u' - cll
#: src/init.c:614
#, c-format
msgid "%s: %s: Please specify always, on, off, or never.\n"
msgstr "%s: %s: por favor especifique siempre, on, off, o nunca.\n"

#: src/init.c:633 src/init.c:900 src/init.c:981
#, c-format
msgid "%s: %s: Invalid specification `%s'.\n"
msgstr "%s: %s: especificaci�n inv�lida `%s'.\n"

#: src/init.c:789 src/init.c:811 src/init.c:833 src/init.c:859
#, c-format
msgid "%s: Invalid specification `%s'\n"
msgstr "%s: especificaci�n inv�lida `%s'\n"

#: src/init.c:949
#, c-format
msgid "%s: %s: Invalid progress type `%s'.\n"
msgstr "%s: %s: tipo de progreso no v�lido `%s'.\n"

#: src/log.c:641
#, c-format
msgid "\n%s received, redirecting output to `%s'.\n"
msgstr "\n%s recibido, redirigiendo la salida a `%s'.\n"

#. Eek!  Opening the alternate log file has failed.  Nothing we
#. can do but disable printing completely.
#: src/log.c:648
#, c-format
msgid "%s: %s; disabling logging.\n"
msgstr "%s: %s; deshabilitando el registro.\n"

#: src/main.c:116
#, c-format
msgid "Usage: %s [OPTION]... [URL]...\n"
msgstr "Modo de empleo: %s [OPCI�N]... [URL]...\n"

#: src/main.c:124
#, c-format
msgid "GNU Wget %s, a non-interactive network retriever.\n"
msgstr "GNU Wget %s, un recuperador por red no interactivo.\n"

# Duda: �por qu� has insertado manualmente un `\n'? �es realmente
# necesario? Probablemente s�, pero yo normalmente traduzco todo en la
# misma l�nea, ... - cll
# Hombre, as� deber�a quedar bastante mejor (adem�s creo que no es la �nica vez
# que lo he hecho), espero que no de problemas. - Salva
#
#. Had to split this in parts, so the #@@#%# Ultrix compiler and cpp
#. don't bitch.  Also, it makes translation much easier.
#: src/main.c:129
msgid "\nMandatory arguments to long options are mandatory for short options too.\n\n"
msgstr ""
"\n"
"Los argumentos obligatorios para las opciones largas son tambi�n obligatorios\n"
"para las opciones cortas.\n"
"\n"

# Primero, simplemente pongo `wget' con `W'. Es una pijada :) pero es
# por hacerlo como en el mensaje original, ...rc' contendr� una
# orden y, sin embargo, cualquier usuario imaginar� que, al ser un
# fichero con un nombre acabado en `rc', ser� un fichero de
# recursos. Esto es, no s�lo servir� para ejecutar varias �rdenes al
# inicio de Wget, sino que adem�s, probablemente servir� para configurar
# su ejecuci�n. Por todo ello, �qu� tal te suena `ejecuta el fichero de
# �rdenes .wgetrc'?. De momento, yo te lo pongo as�, ... - cll
# bien - Salva
#
# --execute ejecuta una orden `del estilo de las incluidas en .wgetrc'
# (nl)
#
#: src/main.c:133
msgid ""
"Startup:\n"
"  -V,  --version           display the version of Wget and exit.\n"
"  -h,  --help              print this help.\n"
"  -b,  --background        go to background after startup.\n"
"  -e,  --execute=COMMAND   execute a `.wgetrc'-style command.\n"
"\n"
msgstr ""
"Inicio:\n"
"  -V,  --version           muestra la versi�n de wget y termina.\n"
"  -h,  --help              muestra esta ayuda.\n"
"  -b,  --background        pasa a segundo plano al iniciar.\n"
"  -e,  --execute=ORDEN     ejecuta una orden como las de `.wgetrc'.\n"
"\n"

# tengo que dejar los porros! (pero que conste que se entiende)
# me refiero por supuesto a la traducci�n de verbose y quiet - Salva,
# d�jala tal cual, ... solo que lo de ��CALLADITO!! :) :) Me parece
# exagerado, ... como bien dices, ���seguro que estabas fumado!!! :) :)
# (ni se entiende, ni leches, seguro que estabas literalmente fumado ;)
#: src/main.c:140
msgid ""
"Logging and input file:\n"
"  -o,  --output-file=FILE     log messages to FILE.\n"
"  -a,  --append-output=FILE   append messages to FILE.\n"
"  -d,  --debug                print debug output.\n"
"  -q,  --quiet                quiet (no output).\n"
"  -v,  --verbose              be verbose (this is the default).\n"
"  -nv, --non-verbose          turn off verboseness, without being quiet.\n"
"  -i,  --input-file=FILE      download URLs found in FILE.\n"
"  -F,  --force-html           treat input file as HTML.\n"
"  -B,  --base=URL             prepends URL to relative links in -F -i file.\n"
"       --sslcertfile=FILE     optional client certificate.\n"
"       --sslcertkey=KEYFILE   optional keyfile for this certificate.\n"
"       --egd-file=FILE        file name of the EGD socket.\n"
"\n"
msgstr ""
"Fichero de entrada y registro:\n"
"  -o,  --output-file=FICHERO   registra los mensajes en FICHERO.\n"
"  -a,  --append-output=FICHERO a�ade los mensajes a FICHERO.\n"
"  -d,  --debug                 imprime la salida de depurado.\n"
"  -q,  --quiet                 modo silencioso (no muestra ninguna salida).\n"
"  -v,  --verbose               modo informativo (predeterminado).\n"
"  -nv, --non-verbose           muestra el m�nimo necesario de informaci�n.\n"
"  -i,  --input-file=FICHERO    descarga las URLs que haya en FICHERO.\n"
"  -F,  --force-html            trata el fichero de entrada como HTML.\n"
"  -B,  --base=URL              a�ade URL delante de los enlaces relativos\n"
"                               en el fichero -F -i.\n"
"       --sslcertfile=FICHERO   certificado opcional del cliente.\n"
"       --sslcertkey=FICHERO    llave opcional para este certificado.\n"
"       --egd-file=FICHERO     fichero del socket EGD.\n"
"\n"

# `pone' me parece demasiado coloquial. Prefiero la traducci�n textual
# `establece''?. Te lo dejo como `recuperando'.ue me parece importante, porque har�s seguro que la
# salida no sea c�modamente legible para el usuario. Te la desdoblo en
# dos l�neas.
#: src/main.c:155
msgid ""
"Download:\n"
"       --bind-address=ADDRESS   bind to ADDRESS (hostname or IP) on local host.\n"
"  -t,  --tries=NUMBER           set number of retries to NUMBER (0 unlimits).\n"
"  -O   --output-document=FILE   write documents to FILE.\n"
"  -nc, --no-clobber             don't clobber existing files or use .# suffixes.\n"
"  -c,  --continue               resume getting a partially-downloaded file.\n"
"       --progress=TYPE          select progress gauge type.\n"
"  -N,  --timestamping           don't re-retrieve files unless newer than local.\n"
"  -S,  --server-response        print server response.\n"
"       --spider                 don't download anything.\n"
"  -T,  --timeout=SECONDS        set the read timeout to SECONDS.\n"
"  -w,  --wait=SECONDS           wait SECONDS between retrievals.\n"
"       --waitretry=SECONDS      wait 1...SECONDS between retries of a retrieval.\n"
"       --random-wait            wait from 0...2*WAIT secs between retrievals.\n"
"  -Y,  --proxy=on/off           turn proxy on or off.\n"
"  -Q,  --quota=NUMBER           set retrieval quota to NUMBER.\n"
"       --limit-rate=RATE        limit download rate to RATE.\n"
"\n"
msgstr ""
"Descarga:\n"
"       --bind-address=DIRECCI�N   realiza un bind a la DIRECCI�N (m�quina o IP)\n"
"                                  en la m�quina local.\n"
"  -t,  --tries=N�MERO             establece en N�MERO el n�mero de reintentos\n"
"                                  (0 no pone l�mite).\n"
"  -O,  --output-document=FICHERO  escribe los documentos en FICHERO.\n"
"  -nc, --no-clobber               no sobreescribir ficheros existentes. o \n"
"                                  utilizar sufijos .#\n"
"  -c,  --continue                 continuar recuperando un fichero existente.\n"
"       --dot-style=ESTILO         establece el estilo de la pantalla de\n"
"                                  recuperaci�n.\n"
"  -N,  --timestamping             no recupera ficheros m�s viejos que los\n"
"                                  locales.\n"
"  -S,  --server-response          imprime la respuesta del servidor.\n"
"       --spider                   no recupera nada.\n"
"  -T,  --timeout=SEGUNDOS         establece el tiempo de espera de lectura\n"
"                                  en SEGUNDOS.\n"
"  -w,  --wait=SEGUNDOS            espera SEGUNDOS entre recuperaciones.\n"
"       --waitretry=SEGUNDOS       espera 1...SEGUNDOS entre reintentos.\n"
"       --random-wait            espera de 0 a 2*WAIT segundos entre reintentos.\n"
"  -Y,  --proxy=on/off             habilita/deshabilita el uso de proxies.\n"
"  -Q,  --quota=N�MERO             establece la cuota de recuperaci�n en N�MERO.\n"
"       --limit-rate=TASA        limita la tasa de descarga a TASA.\n"
"\n"

# Te he cambiado lo de `host' por el t�rmino apropiado (que tu ya ven�as
# utilizando en los mensajes anteriores): `anfitri�n'. Adem�s, hab�as
# puesto `/...' al final de la misma l�nea, cuando no es ah� donde ten�a
# que ir. - cll
#
# Ojo con --no-host-directories, los directorios no se crean
# "en el anfitri�n", sino que se crean directorios cuyo nombre
# coincide con el anfitri�n. Ya lo he cambiado. sv
#
#: src/main.c:174
msgid ""
"Directories:\n"
"  -nd  --no-directories            don't create directories.\n"
"  -x,  --force-directories         force creation of directories.\n"
"  -nH, --no-host-directories       don't create host directories.\n"
"  -P,  --directory-prefix=PREFIX   save files to PREFIX/...\n"
"       --cut-dirs=NUMBER           ignore NUMBER remote directory components.\n"
"\n"
msgstr ""
"Directorios:\n"
"  -nd  --no-directories            no crea directorios.\n"
"  -x   --force-directories         fuerza la creaci�n de directorios.\n"
"  -nH, --no-host-directories       no crea directorios en el anfitri�n\n"
"  -P,  --directory-prefix=PREFIJO  guarda ficheros en PREFIJO/...\n"
"       --cut-dirs=N�MERO           descarta N�MERO componentes del directorio\n"
"                                   remoto.\n"
"\n"

# Como en otros mensajes, sustituyo `poner' por `establecer' u otro
# sin�nimo parecido.es espa�ol, ... sino spanglish. Este es, precisamente,
# el tipo de t�rminos que debieran evitarse en la medida de lo posible.
#: src/main.c:182
msgid ""
"HTTP options:\n"
"       --http-user=USER      set http user to USER.\n"
"       --http-passwd=PASS    set http password to PASS.\n"
"  -C,  --cache=on/off        (dis)allow server-cached data (normally allowed).\n"
"  -E,  --html-extension      save all text/html documents with .html extension.\n"
"       --ignore-length       ignore `Content-Length' header field.\n"
"       --header=STRING       insert STRING among the headers.\n"
"       --proxy-user=USER     set USER as proxy username.\n"
"       --proxy-passwd=PASS   set PASS as proxy password.\n"
"       --referer=URL         include `Referer: URL' header in HTTP request.\n"
"  -s,  --save-headers        save the HTTP headers to file.\n"
"  -U,  --user-agent=AGENT    identify as AGENT instead of Wget/VERSION.\n"
"       --no-http-keep-alive  disable HTTP keep-alive (persistent connections).\n"
"       --cookies=off         don't use cookies.\n"
"       --load-cookies=FILE   load cookies from FILE before session.\n"
"       --save-cookies=FILE   save cookies to FILE after session.\n"
"\n"
msgstr ""
"Opciones de HTTP:\n"
"       --http-user=USUARIO   establece que el usuario de http es USUARIO.\n"
"       --http-passwd=CLAVE   utiliza CLAVE como contrase�a de http.\n"
"  -C,  --cache=on/off        (des)habilita la cach� del servidor de datos.\n"
"                             (normalmente habilitada).\n"
"  -E,  --html-extension      guarda todos los ficheros de texto/html con la\n"
"                             extensi�n .html.\n"
"       --ignore-length       ignora el campo 'Content-Length' de la cabecera.\n"
"       --header=TEXTO        inserta el TEXTO entre las cabeceras.\n"
"       --proxy-user=USUARIO  establece que el usuario del proxy es USUARIO.\n"
"       --proxy-passwd=CLAVE  utiliza CLAVE como contrase�a del proxy.\n"
"       --referer=URL         incluir cabecera 'Referer: URL' en petici�n HTTP.\n"
"  -s,  --save-headers        guarda las cabeceras de HTTP en un fichero.\n"
"  -U,  --user-agent=AGENTE   identificarse como AGENTE en vez de Wget/VERSI�N.\n"
"       --no-http-keep-alive  deshabilita las conexiones persistentes de HTTP.\n"
"       --cookies=off         no utiliza cookies.\n"
"       --load-cookies=FICH.  carga las cookies desde FICH. antes de la sesi�n.\n"
"       --save-cookies=FICH.  guarda las cookies en FICH. tras la sesi�n.\n"
"\n"

# `turn on/off' significa `encender' o `apagar', por supuesto, ..., pero
# en estos casos resulta mucho m�s apropiado `habilitar', `deshabilitar'
# o, si quieres, `activar' y `desactivar' - cll
#: src/main.c:200
msgid ""
"FTP options:\n"
"  -nr, --dont-remove-listing   don't remove `.listing' files.\n"
"  -g,  --glob=on/off           turn file name globbing on or off.\n"
"       --passive-ftp           use the \"passive\" transfer mode.\n"
"       --retr-symlinks         when recursing, get linked-to files (not dirs).\n"
"\n"
msgstr ""
"Opciones de FTP:\n"
"  -nr, --dont-remove-listing   no elimina los ficheros '.listing'.\n"
"  -g,  --glob=on/off           habilita/deshabilita el uso de comodines en\n"
"                               ficheros.\n"
"       --passive-ftp           usa el m�todo de trasferencia \"pasivo\".\n"
"       --retr-symlinks         al descender por los directorios, recupera los\n"
"                               ficheros a los que apunta un enlace (no los\n"
"                               directorios).\n"
"\n"

#: src/main.c:207
msgid ""
"Recursive retrieval:\n"
"  -r,  --recursive          recursive web-suck -- use with care!\n"
"  -l,  --level=NUMBER       maximum recursion depth (inf or 0 for infinite).\n"
"       --delete-after       delete files locally after downloading them.\n"
"  -k,  --convert-links      convert non-relative links to relative.\n"
"  -K,  --backup-converted   before converting file X, back up as X.orig.\n"
"  -m,  --mirror             shortcut option equivalent to -r -N -l inf -nr.\n"
"  -p,  --page-requisites    get all images, etc. needed to display HTML page.\n"
"\n"
msgstr ""
"Recuperaci�n recursiva:\n"
"  -r,  --recursive            succionado de web recursivo, ��selo con cuidado!\n"
"  -l,  --level=N�MERO         profundidad m�xima de recursi�n (0=ilimitada)\n"
"       --delete-after         borra los ficheros locales una vez descargados.\n"
"  -k,  --convert-links        convierte los enlaces no relativos en relativos.\n"
"  -K,  --backup-converted     antes de transformar el fichero X, hace una\n"
"                              copia como X.orig.\n"
"  -m,  --mirror               atajo equivalente a -r -N -l inf -nr.\n"
"  -p,  --page-requisites      descarga todas las im�genes, etc. necesarias\n"
"                              para mostrar la p�gina HTML.\n"
"\n"

# En la opci�n --exclude-domains, date cuenta de que son los dominios
# los que est�n separados por comas, no la lista, ... ;) sin
# traducir. Te pongo `anfitriones' donde ten�as `hosts'
#: src/main.c:217
msgid ""
"Recursive accept/reject:\n"
"  -A,  --accept=LIST                comma-separated list of accepted extensions.\n"
"  -R,  --reject=LIST                comma-separated list of rejected extensions.\n"
"  -D,  --domains=LIST               comma-separated list of accepted domains.\n"
"       --exclude-domains=LIST       comma-separated list of rejected domains.\n"
"       --follow-ftp                 follow FTP links from HTML documents.\n"
"       --follow-tags=LIST           comma-separated list of followed HTML tags.\n"
"  -G,  --ignore-tags=LIST           comma-separated list of ignored HTML tags.\n"
"  -H,  --span-hosts                 go to foreign hosts when recursive.\n"
"  -L,  --relative                   follow relative links only.\n"
"  -I,  --include-directories=LIST   list of allowed directories.\n"
"  -X,  --exclude-directories=LIST   list of excluded directories.\n"
"  -np, --no-parent                  don't ascend to the parent directory.\n"
"\n"
msgstr ""
"Aceptar/rechazar recursivo:\n"
"  -A,  --accept=LISTA                lista, separada por comas, de extensiones\n"
"                                     aceptadas.\n"
"  -R,  --reject=LISTA                lista, separada por comas, de extensiones\n"
"                                     rechazadas.\n"
"  -D,  --domains=LISTA               lista, separada por comas, de dominios\n"
"                                     aceptados.\n"
"       --exclude-domains=LISTA       lista de dominios rechazados, separados\n"
"                                     por comas.\n"
"       --follow-ftp                  sigue enlaces a FTP desde documentos HTML.\n"
"       --follow-tags=LISTA           lista de etiquetas HTML a las que se sigue.\n"
"  -G,  --ignore-tags=LISTA           lista de etiquetas HTML que se ignorar�n.\n"
"  -H,  --span-hosts                  ir a anfitriones distintos en la recursi�n.\n"
"  -L,  --relative                    sigue s�lo enlaces relativos.\n"
"  -I,  --include-directories=LISTA   lista de directorios permitidos.\n"
"  -X,  --exclude-directories=LISTA   lista de directorios excluidos.\n"
"  -np, --no-parent                   no asciende al directorio padre.\n"
"\n"

#: src/main.c:232
msgid "Mail bug reports and suggestions to <bug-wget@gnu.org>.\n"
msgstr "Env�e informaci�n sobre errores y sugerencias a <bug-wget@gnu.org>.\n"

#: src/main.c:420
#, c-format
msgid "%s: debug support not compiled in.\n"
msgstr "%s: el soporte para la depuraci�n no ha sido compilado.\n"

#: src/main.c:472
msgid "Copyright (C) 1995, 1996, 1997, 1998, 2000, 2001 Free Software Foundation, Inc.\n"
msgstr "Copyright (C) 1995, 1996, 1997, 1998, 2000, 2001 Free Software Foundation, Inc.\n"

# Pongo el texto "est�ndar", extraido de recode, por ejemplo. sv
#: src/main.c:474
msgid ""
"This program is distributed in the hope that it will be useful,\n"
"but WITHOUT ANY WARRANTY; without even the implied warranty of\n"
"MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the\n"
"GNU General Public License for more details.\n"
msgstr ""
"Este programa se distribuye con la esperanza de que sea �til,\n"
"pero SIN NINGUNA GARANT�A; ni siquiera la garant�a impl�cita de\n"
"COMERCIABILIDAD o IDONEIDAD PARA UN FIN DETERMINADO. V�ase la\n"
"Licencia P�blica General de GNU para obtener m�s detalles.\n"

#: src/main.c:479
msgid "\nOriginally written by Hrvoje Niksic <hniksic@arsdigita.com>.\n"
msgstr "\nEscrito originalmente por Hrvoje Niksic <hniksic@arsdigita.com>.\n"

#: src/main.c:578
#, c-format
msgid "%s: %s: invalid command\n"
msgstr "%s: %s: orden no v�lida\n"

#: src/main.c:631
#, c-format
msgid "%s: illegal option -- `-n%c'\n"
msgstr "%s: opci�n ilegal -- `-n%c'\n"

#. #### Something nicer should be printed here -- similar to the
#. pre-1.5 `--help' page.
#: src/main.c:634 src/main.c:676 src/main.c:722
#, c-format
msgid "Try `%s --help' for more options.\n"
msgstr "Ejecute `%s --help' para obtener la lista de opciones.\n"

# Como otras veces, te propongo que sustituyas `sacar' por `ofrecer' -
# cll
#
#: src/main.c:702
msgid "Can't be verbose and quiet at the same time.\n"
msgstr "No se puede ofrecer informaci�n y estar silencioso al mismo tiempo.\n"

#: src/main.c:708
msgid "Can't timestamp and not clobber old files at the same time.\n"
msgstr "No se pueden usar marcas de tiempo y no sobreescribir ficheros al mismo tiempo.\n"

#. No URL specified.
#: src/main.c:717
#, c-format
msgid "%s: missing URL\n"
msgstr "%s: falta la URL\n"

#: src/main.c:834
#, c-format
msgid "No URLs found in %s.\n"
msgstr "No se han encontrado URLs en %s.\n"
