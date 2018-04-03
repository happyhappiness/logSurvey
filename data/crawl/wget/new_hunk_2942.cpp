#. Align the [ skipping ... ] line with the dots.  To do
#. that, insert the number of spaces equal to the number of
#. digits in the skipped amount in K.
#: src/progress.c:243
#, c-format
msgid ""
"\n"
"%*s[ skipping %dK ]"
msgstr ""
"\n"
"%*s[ omitiendo %dK ]"

#: src/progress.c:410
#, c-format
msgid "Invalid dot style specification `%s'; leaving unchanged.\n"
msgstr ""
"El estilo de la pantalla '%s' no es v�lido; se utilizar� el predeterminado.\n"

#: src/recur.c:377
#, c-format
msgid "Removing %s since it should be rejected.\n"
msgstr "Eliminando %s puesto que deber�a ser rechazado.\n"

#: src/res.c:548
msgid "Loading robots.txt; please ignore errors.\n"
msgstr "Cargando robots.txt; por favor ignore los errores.\n"

#: src/retr.c:638
#, c-format
msgid "Error parsing proxy URL %s: %s.\n"
msgstr "Error parseando la URL del proxy `%s': %s\n"

#: src/retr.c:646
#, c-format
msgid "Error in proxy URL %s: Must be HTTP.\n"
msgstr "Error en la URL del proxy %s: debe ser HTTP.\n"

#: src/retr.c:731
#, c-format
msgid "%d redirections exceeded.\n"
msgstr "Sobrepasadas las %d redirecciones.\n"

#: src/retr.c:856
msgid ""
"Giving up.\n"
"\n"
msgstr ""
"Abandonando.\n"
"\n"

#: src/retr.c:856
msgid ""
"Retrying.\n"
"\n"
msgstr ""
"Reintentando.\n"
"\n"

#: src/url.c:642
#, fuzzy
msgid "No error"
msgstr "Error desconocido"

#: src/url.c:644
msgid "Unsupported scheme"
msgstr ""

#: src/url.c:646
msgid "Empty host"
msgstr ""

#: src/url.c:648
msgid "Bad port number"
msgstr ""

#: src/url.c:650
msgid "Invalid user name"
msgstr ""

#: src/url.c:652
msgid "Unterminated IPv6 numeric address"
msgstr ""

#: src/url.c:654
msgid "IPv6 addresses not supported"
msgstr ""

#: src/url.c:656
msgid "Invalid IPv6 numeric address"
msgstr ""

# Lo mismo que antes, ... `background' es `segundo plano' - cll
#. parent, no error
#: src/utils.c:347
#, c-format
msgid "Continuing in background, pid %d.\n"
msgstr "Continuando en segundo plano, pid %d.\n"

#: src/utils.c:391
#, c-format
msgid "Failed to unlink symlink `%s': %s\n"
msgstr "No se ha podido deshacer el enlace simb�lico `%s': %s\n"

#: src/xmalloc.c:72
#, c-format
msgid "%s: %s: Failed to allocate %ld bytes; memory exhausted.\n"
msgstr ""

#~ msgid "Syntax error in Set-Cookie at character `%c'.\n"
#~ msgstr "Error de sintaxis al asignar cookie, en el car�cter `%c'.\n"

#~ msgid ""
#~ "\n"
#~ "REST failed; will not truncate `%s'.\n"
#~ msgstr ""
#~ "\n"
#~ "El comando REST no funcion�, no se truncar� `%s'.\n"

#~ msgid " [%s to go]"
#~ msgstr " [%s para acabar]"

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
#~ msgid "Host not found"
#~ msgstr "No se ha encontrado el anfitri�n"

#~ msgid "End of file while parsing headers.\n"
#~ msgstr "Fin de fichero mientras se analizaban las cabeceras.\n"

#~ msgid ""
#~ "\n"
#~ "Continued download failed on this file, which conflicts with `-c'.\n"
#~ "Refusing to truncate existing file `%s'.\n"
#~ "\n"
#~ msgstr ""
#~ "\n"
#~ "No se pudo continuar la descarga de este fichero, lo que choca con `-c'.\n"
#~ "Se rechaza truncar el fichero existente `%s'.\n"
#~ "\n"

#~ msgid " (%s to go)"
#~ msgstr " (%s para acabar)"

#~ msgid "%s: BUG: unknown command `%s', value `%s'.\n"
#~ msgstr "%s: Error: orden desconocida `%s', valor `%s'.\n"

# �No debiera ser la `direcci�n IP local'? - cll
# uups - Salva
#~ msgid "%s: %s: Cannot convert `%s' to an IP address.\n"
#~ msgstr "%s: %s: no se pudo convertir `%s' en una direcci�n IP.\n"

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
#~ msgid ""
#~ "Startup:\n"
#~ "  -V,  --version           display the version of Wget and exit.\n"
#~ "  -h,  --help              print this help.\n"
#~ "  -b,  --background        go to background after startup.\n"
#~ "  -e,  --execute=COMMAND   execute a `.wgetrc'-style command.\n"
#~ "\n"
#~ msgstr ""
#~ "Inicio:\n"
#~ "  -V,  --version           muestra la versi�n de wget y termina.\n"
#~ "  -h,  --help              muestra esta ayuda.\n"
#~ "  -b,  --background        pasa a segundo plano al iniciar.\n"
#~ "  -e,  --execute=ORDEN     ejecuta una orden como las de `.wgetrc'.\n"
#~ "\n"

# tengo que dejar los porros! (pero que conste que se entiende)
# me refiero por supuesto a la traducci�n de verbose y quiet - Salva,
# d�jala tal cual, ... solo que lo de ��CALLADITO!! :) :) Me parece
# exagerado, ... como bien dices, ���seguro que estabas fumado!!! :) :)
# (ni se entiende, ni leches, seguro que estabas literalmente fumado ;)
#~ msgid ""
#~ "Logging and input file:\n"
#~ "  -o,  --output-file=FILE     log messages to FILE.\n"
#~ "  -a,  --append-output=FILE   append messages to FILE.\n"
#~ "  -d,  --debug                print debug output.\n"
#~ "  -q,  --quiet                quiet (no output).\n"
#~ "  -v,  --verbose              be verbose (this is the default).\n"
#~ "  -nv, --non-verbose          turn off verboseness, without being quiet.\n"
#~ "  -i,  --input-file=FILE      download URLs found in FILE.\n"
#~ "  -F,  --force-html           treat input file as HTML.\n"
#~ "  -B,  --base=URL             prepends URL to relative links in -F -i "
#~ "file.\n"
#~ "       --sslcertfile=FILE     optional client certificate.\n"
#~ "       --sslcertkey=KEYFILE   optional keyfile for this certificate.\n"
#~ "       --egd-file=FILE        file name of the EGD socket.\n"
#~ "\n"
#~ msgstr ""
#~ "Fichero de entrada y registro:\n"
#~ "  -o,  --output-file=FICHERO   registra los mensajes en FICHERO.\n"
#~ "  -a,  --append-output=FICHERO a�ade los mensajes a FICHERO.\n"
#~ "  -d,  --debug                 imprime la salida de depurado.\n"
#~ "  -q,  --quiet                 modo silencioso (no muestra ninguna "
#~ "salida).\n"
#~ "  -v,  --verbose               modo informativo (predeterminado).\n"
#~ "  -nv, --non-verbose           muestra el m�nimo necesario de "
#~ "informaci�n.\n"
#~ "  -i,  --input-file=FICHERO    descarga las URLs que haya en FICHERO.\n"
#~ "  -F,  --force-html            trata el fichero de entrada como HTML.\n"
#~ "  -B,  --base=URL              a�ade URL delante de los enlaces "
#~ "relativos\n"
#~ "                               en el fichero -F -i.\n"
#~ "       --sslcertfile=FICHERO   certificado opcional del cliente.\n"
#~ "       --sslcertkey=FICHERO    llave opcional para este certificado.\n"
#~ "       --egd-file=FICHERO     fichero del socket EGD.\n"
#~ "\n"

# `pone' me parece demasiado coloquial. Prefiero la traducci�n textual
# `establece''?. Te lo dejo como `recuperando'.ue me parece importante, porque har�s seguro que la
# salida no sea c�modamente legible para el usuario. Te la desdoblo en
# dos l�neas.
#~ msgid ""
#~ "Download:\n"
#~ "       --bind-address=ADDRESS   bind to ADDRESS (hostname or IP) on local "
#~ "host.\n"
#~ "  -t,  --tries=NUMBER           set number of retries to NUMBER (0 "
#~ "unlimits).\n"
#~ "  -O   --output-document=FILE   write documents to FILE.\n"
#~ "  -nc, --no-clobber             don't clobber existing files or use .# "
#~ "suffixes.\n"
#~ "  -c,  --continue               resume getting a partially-downloaded "
#~ "file.\n"
#~ "       --progress=TYPE          select progress gauge type.\n"
#~ "  -N,  --timestamping           don't re-retrieve files unless newer than "
#~ "local.\n"
#~ "  -S,  --server-response        print server response.\n"
#~ "       --spider                 don't download anything.\n"
#~ "  -T,  --timeout=SECONDS        set the read timeout to SECONDS.\n"
#~ "  -w,  --wait=SECONDS           wait SECONDS between retrievals.\n"
#~ "       --waitretry=SECONDS      wait 1...SECONDS between retries of a "
#~ "retrieval.\n"
#~ "       --random-wait            wait from 0...2*WAIT secs between "
#~ "retrievals.\n"
#~ "  -Y,  --proxy=on/off           turn proxy on or off.\n"
#~ "  -Q,  --quota=NUMBER           set retrieval quota to NUMBER.\n"
#~ "       --limit-rate=RATE        limit download rate to RATE.\n"
#~ "\n"
#~ msgstr ""
#~ "Descarga:\n"
#~ "       --bind-address=DIRECCI�N   realiza un bind a la DIRECCI�N (m�quina "
#~ "o IP)\n"
#~ "                                  en la m�quina local.\n"
#~ "  -t,  --tries=N�MERO             establece en N�MERO el n�mero de "
#~ "reintentos\n"
#~ "                                  (0 no pone l�mite).\n"
#~ "  -O,  --output-document=FICHERO  escribe los documentos en FICHERO.\n"
#~ "  -nc, --no-clobber               no sobreescribir ficheros existentes. "
#~ "o \n"
#~ "                                  utilizar sufijos .#\n"
#~ "  -c,  --continue                 continuar recuperando un fichero "
#~ "existente.\n"
#~ "       --dot-style=ESTILO         establece el estilo de la pantalla de\n"
#~ "                                  recuperaci�n.\n"
#~ "  -N,  --timestamping             no recupera ficheros m�s viejos que "
#~ "los\n"
#~ "                                  locales.\n"
#~ "  -S,  --server-response          imprime la respuesta del servidor.\n"
#~ "       --spider                   no recupera nada.\n"
#~ "  -T,  --timeout=SEGUNDOS         establece el tiempo de espera de "
#~ "lectura\n"
#~ "                                  en SEGUNDOS.\n"
#~ "  -w,  --wait=SEGUNDOS            espera SEGUNDOS entre recuperaciones.\n"
#~ "       --waitretry=SEGUNDOS       espera 1...SEGUNDOS entre reintentos.\n"
#~ "       --random-wait            espera de 0 a 2*WAIT segundos entre "
#~ "reintentos.\n"
#~ "  -Y,  --proxy=on/off             habilita/deshabilita el uso de "
#~ "proxies.\n"
#~ "  -Q,  --quota=N�MERO             establece la cuota de recuperaci�n en "
#~ "N�MERO.\n"
#~ "       --limit-rate=TASA        limita la tasa de descarga a TASA.\n"
#~ "\n"

# Te he cambiado lo de `host' por el t�rmino apropiado (que tu ya ven�as
# utilizando en los mensajes anteriores): `anfitri�n'. Adem�s, hab�as
# puesto `/...' al final de la misma l�nea, cuando no es ah� donde ten�a
# que ir. - cll
#
# Ojo con --no-host-directories, los directorios no se crean
# "en el anfitri�n", sino que se crean directorios cuyo nombre
# coincide con el anfitri�n. Ya lo he cambiado. sv
#
#~ msgid ""
#~ "Directories:\n"
#~ "  -nd  --no-directories            don't create directories.\n"
#~ "  -x,  --force-directories         force creation of directories.\n"
#~ "  -nH, --no-host-directories       don't create host directories.\n"
#~ "  -P,  --directory-prefix=PREFIX   save files to PREFIX/...\n"
#~ "       --cut-dirs=NUMBER           ignore NUMBER remote directory "
#~ "components.\n"
#~ "\n"
#~ msgstr ""
#~ "Directorios:\n"
#~ "  -nd  --no-directories            no crea directorios.\n"
#~ "  -x   --force-directories         fuerza la creaci�n de directorios.\n"
#~ "  -nH, --no-host-directories       no crea directorios en el anfitri�n\n"
#~ "  -P,  --directory-prefix=PREFIJO  guarda ficheros en PREFIJO/...\n"
#~ "       --cut-dirs=N�MERO           descarta N�MERO componentes del "
#~ "directorio\n"
#~ "                                   remoto.\n"
#~ "\n"

# Como en otros mensajes, sustituyo `poner' por `establecer' u otro
# sin�nimo parecido.es espa�ol, ... sino spanglish. Este es, precisamente,
# el tipo de t�rminos que debieran evitarse en la medida de lo posible.
#~ msgid ""
#~ "HTTP options:\n"
#~ "       --http-user=USER      set http user to USER.\n"
#~ "       --http-passwd=PASS    set http password to PASS.\n"
#~ "  -C,  --cache=on/off        (dis)allow server-cached data (normally "
#~ "allowed).\n"
#~ "  -E,  --html-extension      save all text/html documents with .html "
#~ "extension.\n"
#~ "       --ignore-length       ignore `Content-Length' header field.\n"
#~ "       --header=STRING       insert STRING among the headers.\n"
#~ "       --proxy-user=USER     set USER as proxy username.\n"
#~ "       --proxy-passwd=PASS   set PASS as proxy password.\n"
#~ "       --referer=URL         include `Referer: URL' header in HTTP "
#~ "request.\n"
#~ "  -s,  --save-headers        save the HTTP headers to file.\n"
#~ "  -U,  --user-agent=AGENT    identify as AGENT instead of Wget/VERSION.\n"
#~ "       --no-http-keep-alive  disable HTTP keep-alive (persistent "
#~ "connections).\n"
#~ "       --cookies=off         don't use cookies.\n"
#~ "       --load-cookies=FILE   load cookies from FILE before session.\n"
#~ "       --save-cookies=FILE   save cookies to FILE after session.\n"
#~ "\n"
#~ msgstr ""
#~ "Opciones de HTTP:\n"
#~ "       --http-user=USUARIO   establece que el usuario de http es "
#~ "USUARIO.\n"
#~ "       --http-passwd=CLAVE   utiliza CLAVE como contrase�a de http.\n"
#~ "  -C,  --cache=on/off        (des)habilita la cach� del servidor de "
#~ "datos.\n"
#~ "                             (normalmente habilitada).\n"
#~ "  -E,  --html-extension      guarda todos los ficheros de texto/html con "
#~ "la\n"
#~ "                             extensi�n .html.\n"
#~ "       --ignore-length       ignora el campo 'Content-Length' de la "
#~ "cabecera.\n"
#~ "       --header=TEXTO        inserta el TEXTO entre las cabeceras.\n"
#~ "       --proxy-user=USUARIO  establece que el usuario del proxy es "
#~ "USUARIO.\n"
#~ "       --proxy-passwd=CLAVE  utiliza CLAVE como contrase�a del proxy.\n"
#~ "       --referer=URL         incluir cabecera 'Referer: URL' en petici�n "
#~ "HTTP.\n"
#~ "  -s,  --save-headers        guarda las cabeceras de HTTP en un fichero.\n"
#~ "  -U,  --user-agent=AGENTE   identificarse como AGENTE en vez de Wget/"
#~ "VERSI�N.\n"
#~ "       --no-http-keep-alive  deshabilita las conexiones persistentes de "
#~ "HTTP.\n"
#~ "       --cookies=off         no utiliza cookies.\n"
#~ "       --load-cookies=FICH.  carga las cookies desde FICH. antes de la "
#~ "sesi�n.\n"
#~ "       --save-cookies=FICH.  guarda las cookies en FICH. tras la sesi�n.\n"
#~ "\n"

# `turn on/off' significa `encender' o `apagar', por supuesto, ..., pero
# en estos casos resulta mucho m�s apropiado `habilitar', `deshabilitar'
# o, si quieres, `activar' y `desactivar' - cll
#~ msgid ""
#~ "FTP options:\n"
#~ "  -nr, --dont-remove-listing   don't remove `.listing' files.\n"
#~ "  -g,  --glob=on/off           turn file name globbing on or off.\n"
#~ "       --passive-ftp           use the \"passive\" transfer mode.\n"
#~ "       --retr-symlinks         when recursing, get linked-to files (not "
#~ "dirs).\n"
#~ "\n"
#~ msgstr ""
#~ "Opciones de FTP:\n"
#~ "  -nr, --dont-remove-listing   no elimina los ficheros '.listing'.\n"
#~ "  -g,  --glob=on/off           habilita/deshabilita el uso de comodines "
#~ "en\n"
#~ "                               ficheros.\n"
#~ "       --passive-ftp           usa el m�todo de trasferencia \"pasivo\".\n"
#~ "       --retr-symlinks         al descender por los directorios, recupera "
#~ "los\n"
#~ "                               ficheros a los que apunta un enlace (no "
#~ "los\n"
#~ "                               directorios).\n"
#~ "\n"

#~ msgid ""
#~ "Recursive retrieval:\n"
#~ "  -r,  --recursive          recursive web-suck -- use with care!\n"
#~ "  -l,  --level=NUMBER       maximum recursion depth (inf or 0 for "
#~ "infinite).\n"
#~ "       --delete-after       delete files locally after downloading them.\n"
#~ "  -k,  --convert-links      convert non-relative links to relative.\n"
#~ "  -K,  --backup-converted   before converting file X, back up as X.orig.\n"
#~ "  -m,  --mirror             shortcut option equivalent to -r -N -l inf -"
#~ "nr.\n"
#~ "  -p,  --page-requisites    get all images, etc. needed to display HTML "
#~ "page.\n"
#~ "\n"
#~ msgstr ""
#~ "Recuperaci�n recursiva:\n"
#~ "  -r,  --recursive            succionado de web recursivo, ��selo con "
#~ "cuidado!\n"
#~ "  -l,  --level=N�MERO         profundidad m�xima de recursi�n "
#~ "(0=ilimitada)\n"
#~ "       --delete-after         borra los ficheros locales una vez "
#~ "descargados.\n"
#~ "  -k,  --convert-links        convierte los enlaces no relativos en "
#~ "relativos.\n"
#~ "  -K,  --backup-converted     antes de transformar el fichero X, hace "
#~ "una\n"
#~ "                              copia como X.orig.\n"
#~ "  -m,  --mirror               atajo equivalente a -r -N -l inf -nr.\n"
#~ "  -p,  --page-requisites      descarga todas las im�genes, etc. "
#~ "necesarias\n"
#~ "                              para mostrar la p�gina HTML.\n"
#~ "\n"

# En la opci�n --exclude-domains, date cuenta de que son los dominios
# los que est�n separados por comas, no la lista, ... ;) sin
# traducir. Te pongo `anfitriones' donde ten�as `hosts'
#~ msgid ""
#~ "Recursive accept/reject:\n"
#~ "  -A,  --accept=LIST                comma-separated list of accepted "
#~ "extensions.\n"
#~ "  -R,  --reject=LIST                comma-separated list of rejected "
#~ "extensions.\n"
#~ "  -D,  --domains=LIST               comma-separated list of accepted "
#~ "domains.\n"
#~ "       --exclude-domains=LIST       comma-separated list of rejected "
#~ "domains.\n"
#~ "       --follow-ftp                 follow FTP links from HTML "
#~ "documents.\n"
#~ "       --follow-tags=LIST           comma-separated list of followed HTML "
#~ "tags.\n"
#~ "  -G,  --ignore-tags=LIST           comma-separated list of ignored HTML "
#~ "tags.\n"
#~ "  -H,  --span-hosts                 go to foreign hosts when recursive.\n"
#~ "  -L,  --relative                   follow relative links only.\n"
#~ "  -I,  --include-directories=LIST   list of allowed directories.\n"
#~ "  -X,  --exclude-directories=LIST   list of excluded directories.\n"
#~ "  -np, --no-parent                  don't ascend to the parent "
#~ "directory.\n"
#~ "\n"
#~ msgstr ""
#~ "Aceptar/rechazar recursivo:\n"
#~ "  -A,  --accept=LISTA                lista, separada por comas, de "
#~ "extensiones\n"
#~ "                                     aceptadas.\n"
#~ "  -R,  --reject=LISTA                lista, separada por comas, de "
#~ "extensiones\n"
#~ "                                     rechazadas.\n"
#~ "  -D,  --domains=LISTA               lista, separada por comas, de "
#~ "dominios\n"
#~ "                                     aceptados.\n"
#~ "       --exclude-domains=LISTA       lista de dominios rechazados, "
#~ "separados\n"
#~ "                                     por comas.\n"
#~ "       --follow-ftp                  sigue enlaces a FTP desde documentos "
#~ "HTML.\n"
#~ "       --follow-tags=LISTA           lista de etiquetas HTML a las que se "
#~ "sigue.\n"
#~ "  -G,  --ignore-tags=LISTA           lista de etiquetas HTML que se "
#~ "ignorar�n.\n"
#~ "  -H,  --span-hosts                  ir a anfitriones distintos en la "
#~ "recursi�n.\n"
#~ "  -L,  --relative                    sigue s�lo enlaces relativos.\n"
#~ "  -I,  --include-directories=LISTA   lista de directorios permitidos.\n"
#~ "  -X,  --exclude-directories=LISTA   lista de directorios excluidos.\n"
#~ "  -np, --no-parent                   no asciende al directorio padre.\n"
#~ "\n"

#~ msgid "%s: debug support not compiled in.\n"
#~ msgstr "%s: el soporte para la depuraci�n no ha sido compilado.\n"

#~ msgid "%s: %s: invalid command\n"
#~ msgstr "%s: %s: orden no v�lida\n"

# Eso de `comenzando ...' ha sido demasiado literal, ... ;) �Qu� te
# parece `iniciando'? Es lo mismo pero es un t�rmino m�s com�n en
# inform�tica, ... - cll
#
#~ msgid "Starting WinHelp %s\n"
#~ msgstr "Iniciando WinHelp %s\n"

# `host' es traducido como `anfitri�n'. Debes evitar los t�rminos en
# ingl�s tanto como puedas, ... - cll
#
#~ msgid "Could not find proxy host.\n"
#~ msgstr "No se pudo encontrar el anfitri�n de proxy.\n"

#~ msgid "%s: Redirection cycle detected.\n"
#~ msgstr "%s: redirecci�n c�clica detectada.\n"

#~ msgid "%s: %s: Not enough memory.\n"
#~ msgstr "%s: %s: no hay suficiente memoria.\n"
