#. No luck.
#. #### This message SUCKS.  We should see what was the
#. reason that nothing was retrieved.
#: src/ftp.c:1753
#, c-format
msgid "No matches on pattern `%s'.\n"
msgstr "No hay nada que se ajuste al patr�n `%s'.\n"

#: src/ftp.c:1819
#, fuzzy, c-format
msgid "Wrote HTML-ized index to `%s' [%s].\n"
msgstr "Se escribi� un �ndice en HTML a `%s' [%ld].\n"

#: src/ftp.c:1824
#, c-format
msgid "Wrote HTML-ized index to `%s'.\n"
msgstr "Se escribi� un �ndice en HTML a `%s'.\n"

#: src/getopt.c:670
#, c-format
msgid "%s: option `%s' is ambiguous\n"
msgstr "%s: la opci�n `%s' es ambigua\n"

#: src/getopt.c:695
#, c-format
msgid "%s: option `--%s' doesn't allow an argument\n"
msgstr "%s: la opci�n `--%s' no admite ning�n argumento\n"

#: src/getopt.c:700
#, c-format
msgid "%s: option `%c%s' doesn't allow an argument\n"
msgstr "%s: la opci�n `%c%s' no admite ning�n argumento\n"

#: src/getopt.c:718 src/getopt.c:891
#, c-format
msgid "%s: option `%s' requires an argument\n"
msgstr "%s: la opci�n `%s' requiere un argumento\n"

#. --option
#: src/getopt.c:747
#, c-format
msgid "%s: unrecognized option `--%s'\n"
msgstr "%s: opci�n no reconocida `--%s'\n"

#. +option or -option
#: src/getopt.c:751
#, c-format
msgid "%s: unrecognized option `%c%s'\n"
msgstr "%s: opci�n no reconocida `%c%s\n"

#. 1003.2 specifies the format of this message.
#: src/getopt.c:777
#, c-format
msgid "%s: illegal option -- %c\n"
msgstr "%s: opci�n ilegal -- %c\n"

#: src/getopt.c:780
#, fuzzy, c-format
msgid "%s: invalid option -- %c\n"
msgstr "%s: opci�n ilegal -- %c\n"

# nota jjrs: argumento o parametro?
# mmm... argumento? ;-P -Salva
#. 1003.2 specifies the format of this message.
#: src/getopt.c:810 src/getopt.c:940
#, c-format
msgid "%s: option requires an argument -- %c\n"
msgstr "%s: la opci�n requiere un argumento -- %c\n"

#: src/getopt.c:857
#, fuzzy, c-format
msgid "%s: option `-W %s' is ambiguous\n"
msgstr "%s: la opci�n `%s' es ambigua\n"

#: src/getopt.c:875
#, fuzzy, c-format
msgid "%s: option `-W %s' doesn't allow an argument\n"
msgstr "%s: la opci�n `--%s' no admite ning�n argumento\n"

#: src/host.c:347
#, fuzzy
msgid "Unknown host"
msgstr "Error desconocido"

#. Message modeled after what gai_strerror returns in similar
#. circumstances.
#: src/host.c:351
msgid "Temporary failure in name resolution"
msgstr ""

#: src/host.c:353
msgid "Unknown error"
msgstr "Error desconocido"

#: src/host.c:714
#, c-format
msgid "Resolving %s... "
msgstr "Resolviendo %s... "

#: src/host.c:761
msgid "failed: No IPv4/IPv6 addresses for host.\n"
msgstr ""

#: src/host.c:784
#, fuzzy
msgid "failed: timed out.\n"
msgstr "fall�: %s.\n"

#: src/html-url.c:288
#, c-format
msgid "%s: Cannot resolve incomplete link %s.\n"
msgstr "%s: no se pudo resolver el enlace incompleto %s.\n"

#: src/html-url.c:695
#, fuzzy, c-format
msgid "%s: Invalid URL %s: %s\n"
msgstr "%s: especificaci�n inv�lida `%s'\n"

#: src/http.c:367
#, c-format
msgid "Failed writing HTTP request: %s.\n"
msgstr "Fallo escribiendo petici�n HTTP: %s.\n"

#: src/http.c:736
msgid "No headers, assuming HTTP/0.9"
msgstr ""

#: src/http.c:1413
msgid "Disabling SSL due to encountered errors.\n"
msgstr ""

#: src/http.c:1566
#, c-format
msgid "POST data file `%s' missing: %s\n"
msgstr ""

#: src/http.c:1615
#, fuzzy, c-format
msgid "Reusing existing connection to %s:%d.\n"
msgstr "Reutilizando la conexi�n con %s:%hu.\n"

#: src/http.c:1684
#, fuzzy, c-format
msgid "Failed reading proxy response: %s\n"
msgstr "Fallo escribiendo petici�n HTTP: %s.\n"

#: src/http.c:1704
#, c-format
msgid "Proxy tunneling failed: %s"
msgstr ""

#: src/http.c:1749
#, c-format
msgid "%s request sent, awaiting response... "
msgstr "Petici�n %s enviada, esperando respuesta... "

#: src/http.c:1760
#, fuzzy
msgid "No data received.\n"
msgstr "No se han recibido datos"

#: src/http.c:1767
#, c-format
msgid "Read error (%s) in headers.\n"
msgstr "Error de lectura (%s) en las cabeceras.\n"

# `no recuperando' no me suena muy espa�ol, te propongo la alternativa
# m�s "humanizada", `no se recupera' - cll
#
#. If opt.noclobber is turned on and file already exists, do not
#. retrieve the file
#: src/http.c:1813
#, fuzzy, c-format
msgid ""
"File `%s' already there; not retrieving.\n"
"\n"
msgstr "El fichero `%s' ya est� ah�, no se recupera.\n"

#. If the authentication header is missing or
#. unrecognized, there's no sense in retrying.
#: src/http.c:1966
msgid "Unknown authentication scheme.\n"
msgstr "M�todo de autentificaci�n desconocido.\n"

# En vez de `fall� la autorizaci�n' me parece m�s apropiado
# `Autorizaci�n denegada' - cll
#
#: src/http.c:1997
msgid "Authorization failed.\n"
msgstr "Autorizaci�n denegada.\n"

# Piiiiii: escuchemos a los super-taca�ones :)
#
# Como no existe el verbo "malformar" en espa�ol, el participio
# `malformado' es incorrecto. El �nico t�rmino parecido a �ste que
# existe en espa�ol es `malformaci�n'. - cll
#: src/http.c:2011
msgid "Malformed status line"
msgstr "L�nea de estado mal formada"

#: src/http.c:2013
msgid "(no description)"
msgstr "(sin descripci�n)"

#: src/http.c:2076
#, c-format
msgid "Location: %s%s\n"
msgstr "Localizaci�n: %s%s\n"

#: src/http.c:2077 src/http.c:2184
msgid "unspecified"
msgstr "no especificado"

# Duda: Hmmm, ... �`siguiendo' o `siguiente'? - cll
# siguiendo - Salva
#
#: src/http.c:2078
msgid " [following]"
msgstr " [siguiendo]"

#. If `-c' is in use and the file has been fully downloaded (or
#. the remote file has shrunk), Wget effectively requests bytes
#. after the end of file and the server response with 416.
#: src/http.c:2134
msgid ""
"\n"
"    The file is already fully retrieved; nothing to do.\n"
"\n"
msgstr ""
"\n"
"    El fichero ya ha sido totalmente recuperado, no hay nada que hacer.\n"
"\n"

#. No need to print this output if the body won't be
#. downloaded at all, or if the original server response is
#. printed.
#: src/http.c:2164
msgid "Length: "
msgstr "Longitud: "

#: src/http.c:2184
msgid "ignored"
msgstr "descartado"

#: src/http.c:2255
#, fuzzy, c-format
msgid "Saving to: `%s'\n"
msgstr "Omitiendo el directorio `%s'.\n"

#: src/http.c:2335
msgid "Warning: wildcards not supported in HTTP.\n"
msgstr "Atenci�n: no se admiten comodines en HTTP.\n"

#: src/http.c:2364
msgid "Spider mode enabled. Check if remote file exists.\n"
msgstr ""

#: src/http.c:2450
#, c-format
msgid "Cannot write to `%s' (%s).\n"
msgstr "No se puede escribir a `%s' (%s).\n"

#. Another fatal error.
#: src/http.c:2459
msgid "Unable to establish SSL connection.\n"
msgstr "No se pudo establecer la conexi�n SSL.\n"

#: src/http.c:2467
#, c-format
msgid "ERROR: Redirection (%d) without location.\n"
msgstr "ERROR: redirecci�n (%d) sin localizaci�n.\n"

#: src/http.c:2505
msgid "Remote file does not exist -- broken link!!!\n"
msgstr ""

#: src/http.c:2510
#, c-format
msgid "%s ERROR %d: %s.\n"
msgstr "%s ERROR %d: %s.\n"

# as� se entiende mejor -Salva
#: src/http.c:2526
msgid "Last-modified header missing -- time-stamps turned off.\n"
msgstr ""
"Falta la fecha de la �ltima modificaci�n -- marcas de tiempo apagadas.\n"

#: src/http.c:2534
msgid "Last-modified header invalid -- time-stamp ignored.\n"
msgstr ""
"La fecha de �ltima modificaci�n es inv�lida -- marca de tiempo descartada.\n"

#: src/http.c:2558
#, c-format
msgid ""
"Server file no newer than local file `%s' -- not retrieving.\n"
"\n"
msgstr ""
"El fichero del servidor no es m�s moderno que el fichero local `%s' -- no se "
"descargar�.\n"
"\n"

#: src/http.c:2566
#, fuzzy, c-format
msgid "The sizes do not match (local %s) -- retrieving.\n"
msgstr "Los tama�os no concuerdan (%ld local), recuperando.\n"

#: src/http.c:2573
msgid "Remote file is newer, retrieving.\n"
msgstr "El fichero remoto es nuevo, recuperando.\n"

#: src/http.c:2596
#, fuzzy
msgid ""
"Remote file exists and could contain links to other resources -- "
"retrieving.\n"
"\n"
msgstr ""
"El fichero remoto es m�s moderno que el fichero local `%s' -- descargando.\n"
"\n"

#: src/http.c:2602
#, fuzzy
msgid ""
"Remote file exists but does not contain any link -- not retrieving.\n"
"\n"
msgstr ""
"El fichero remoto no es m�s moderno que el fichero local `%s' -- no se "
"descargar�.\n"

#: src/http.c:2610
#, fuzzy
msgid ""
"Remote file exists but recursion is disabled -- not retrieving.\n"
"\n"
msgstr ""
"El fichero remoto no es m�s moderno que el fichero local `%s' -- no se "
"descargar�.\n"

#: src/http.c:2652
#, fuzzy, c-format
msgid ""
"%s (%s) - `%s' saved [%s/%s]\n"
"\n"
msgstr ""
"%s (%s) - `%s' guardado [%ld/%ld]\n"
"\n"

#: src/http.c:2707
#, fuzzy, c-format
msgid "%s (%s) - Connection closed at byte %s. "
msgstr "%s (%s) - Conexi�n cerrada en el byte %ld. "

#: src/http.c:2722
#, fuzzy, c-format
msgid "%s (%s) - Read error at byte %s (%s)."
msgstr "%s (%s) - Error de lectura en el byte %ld (%s)."

#: src/http.c:2731
#, fuzzy, c-format
msgid "%s (%s) - Read error at byte %s/%s (%s). "
msgstr "%s (%s) - Error de lectura en el byte %ld/%ld (%s)."

#: src/init.c:371
#, c-format
msgid "%s: WGETRC points to %s, which doesn't exist.\n"
msgstr ""

#: src/init.c:434 src/netrc.c:267
#, c-format
msgid "%s: Cannot read %s (%s).\n"
msgstr "%s: No se pudo leer %s (%s).\n"

#: src/init.c:452
#, c-format
msgid "%s: Error in %s at line %d.\n"
msgstr "%s: Error en %s en la l�nea %d.\n"

#: src/init.c:458
#, fuzzy, c-format
msgid "%s: Syntax error in %s at line %d.\n"
msgstr "%s: Error en %s en la l�nea %d.\n"

#: src/init.c:463
#, fuzzy, c-format
msgid "%s: Unknown command `%s' in %s at line %d.\n"
msgstr "%s: Error: orden desconocida `%s', valor `%s'.\n"

#: src/init.c:508
#, c-format
msgid "%s: Warning: Both system and user wgetrc point to `%s'.\n"
msgstr ""
"%s: Atenci�n: tanto el fichero wgetrc de usuario como el del sistema apuntan "
"a `%s'.\n"

#: src/init.c:661
#, fuzzy, c-format
msgid "%s: Invalid --execute command `%s'\n"
msgstr "%s: especificaci�n inv�lida `%s'\n"

# Te cambio la `o' antes de `off' por `u' - cll
#
#: src/init.c:706
#, fuzzy, c-format
msgid "%s: %s: Invalid boolean `%s'; use `on' or `off'.\n"
msgstr "%s: %s: por favor, especifique on u off.\n"

#: src/init.c:723
#, fuzzy, c-format
msgid "%s: %s: Invalid number `%s'.\n"
msgstr "%s: %s: especificaci�n inv�lida `%s'.\n"

#: src/init.c:954 src/init.c:973
#, fuzzy, c-format
msgid "%s: %s: Invalid byte value `%s'\n"
msgstr "%s: %s: tipo de progreso no v�lido `%s'.\n"

#: src/init.c:998
#, fuzzy, c-format
msgid "%s: %s: Invalid time period `%s'\n"
msgstr "%s: %s: especificaci�n inv�lida `%s'.\n"

#: src/init.c:1052 src/init.c:1142 src/init.c:1245 src/init.c:1270
#, fuzzy, c-format
msgid "%s: %s: Invalid value `%s'.\n"
msgstr "%s: %s: especificaci�n inv�lida `%s'.\n"

#: src/init.c:1089
#, fuzzy, c-format
msgid "%s: %s: Invalid header `%s'.\n"
msgstr "%s: %s: especificaci�n inv�lida `%s'.\n"

#: src/init.c:1155
#, c-format
msgid "%s: %s: Invalid progress type `%s'.\n"
msgstr "%s: %s: tipo de progreso no v�lido `%s'.\n"

#: src/init.c:1214
#, c-format
msgid ""
"%s: %s: Invalid restriction `%s', use [unix|windows],[lowercase|uppercase],"
"[nocontrol].\n"
msgstr ""

#: src/log.c:783
#, c-format
msgid ""
"\n"
"%s received, redirecting output to `%s'.\n"
msgstr ""
"\n"
"%s recibido, redirigiendo la salida a `%s'.\n"

#. Eek!  Opening the alternate log file has failed.  Nothing we
#. can do but disable printing completely.
#: src/log.c:793
#, fuzzy, c-format
msgid ""
"\n"
"%s received.\n"
msgstr "No se han recibido datos"

#: src/log.c:794
#, c-format
msgid "%s: %s; disabling logging.\n"
msgstr "%s: %s; deshabilitando el registro.\n"

#: src/main.c:353
#, c-format
msgid "Usage: %s [OPTION]... [URL]...\n"
msgstr "Modo de empleo: %s [OPCI�N]... [URL]...\n"

# Duda: �por qu� has insertado manualmente un `\n'? �es realmente
# necesario? Probablemente s�, pero yo normalmente traduzco todo en la
# misma l�nea, ... - cll
# Hombre, as� deber�a quedar bastante mejor (adem�s creo que no es la �nica vez
# que lo he hecho), espero que no de problemas. - Salva
#
#: src/main.c:365
#, fuzzy
msgid ""
"Mandatory arguments to long options are mandatory for short options too.\n"
"\n"
msgstr ""
"\n"
"Los argumentos obligatorios para las opciones largas son tambi�n "
"obligatorios\n"
"para las opciones cortas.\n"
"\n"

#: src/main.c:367
msgid "Startup:\n"
msgstr ""

#: src/main.c:369
msgid "  -V,  --version           display the version of Wget and exit.\n"
msgstr ""

#: src/main.c:371
msgid "  -h,  --help              print this help.\n"
msgstr ""

#: src/main.c:373
msgid "  -b,  --background        go to background after startup.\n"
msgstr ""

#: src/main.c:375
msgid "  -e,  --execute=COMMAND   execute a `.wgetrc'-style command.\n"
msgstr ""

#: src/main.c:379
msgid "Logging and input file:\n"
msgstr ""

#: src/main.c:381
msgid "  -o,  --output-file=FILE    log messages to FILE.\n"
msgstr ""

#: src/main.c:383
msgid "  -a,  --append-output=FILE  append messages to FILE.\n"
msgstr ""

#: src/main.c:386
msgid "  -d,  --debug               print lots of debugging information.\n"
msgstr ""

#: src/main.c:389
msgid "  -q,  --quiet               quiet (no output).\n"
msgstr ""

#: src/main.c:391
msgid "  -v,  --verbose             be verbose (this is the default).\n"
msgstr ""

#: src/main.c:393
msgid ""
"  -nv, --no-verbose          turn off verboseness, without being quiet.\n"
msgstr ""

#: src/main.c:395
msgid "  -i,  --input-file=FILE     download URLs found in FILE.\n"
msgstr ""

#: src/main.c:397
msgid "  -F,  --force-html          treat input file as HTML.\n"
msgstr ""

#: src/main.c:399
msgid ""
"  -B,  --base=URL            prepends URL to relative links in -F -i file.\n"
msgstr ""

#: src/main.c:403
msgid "Download:\n"
msgstr ""

#: src/main.c:405
msgid ""
"  -t,  --tries=NUMBER            set number of retries to NUMBER (0 "
"unlimits).\n"
msgstr ""

#: src/main.c:407
msgid "       --retry-connrefused       retry even if connection is refused.\n"
msgstr ""

#: src/main.c:409
msgid "  -O,  --output-document=FILE    write documents to FILE.\n"
msgstr ""

#: src/main.c:411
msgid ""
"  -nc, --no-clobber              skip downloads that would download to\n"
"                                 existing files.\n"
msgstr ""

#: src/main.c:414
msgid ""
"  -c,  --continue                resume getting a partially-downloaded "
"file.\n"
msgstr ""

#: src/main.c:416
msgid "       --progress=TYPE           select progress gauge type.\n"
msgstr ""

#: src/main.c:418
msgid ""
"  -N,  --timestamping            don't re-retrieve files unless newer than\n"
"                                 local.\n"
msgstr ""

#: src/main.c:421
msgid "  -S,  --server-response         print server response.\n"
msgstr ""

#: src/main.c:423
msgid "       --spider                  don't download anything.\n"
msgstr ""

#: src/main.c:425
msgid "  -T,  --timeout=SECONDS         set all timeout values to SECONDS.\n"
msgstr ""

#: src/main.c:427
msgid "       --dns-timeout=SECS        set the DNS lookup timeout to SECS.\n"
msgstr ""

#: src/main.c:429
msgid "       --connect-timeout=SECS    set the connect timeout to SECS.\n"
msgstr ""

#: src/main.c:431
msgid "       --read-timeout=SECS       set the read timeout to SECS.\n"
msgstr ""

#: src/main.c:433
msgid "  -w,  --wait=SECONDS            wait SECONDS between retrievals.\n"
msgstr ""

#: src/main.c:435
msgid ""
"       --waitretry=SECONDS       wait 1..SECONDS between retries of a "
"retrieval.\n"
msgstr ""

#: src/main.c:437
msgid ""
"       --random-wait             wait from 0...2*WAIT secs between "
"retrievals.\n"
msgstr ""

#: src/main.c:439
msgid "  -Y,  --proxy                   explicitly turn on proxy.\n"
msgstr ""

#: src/main.c:441
msgid "       --no-proxy                explicitly turn off proxy.\n"
msgstr ""

#: src/main.c:443
msgid "  -Q,  --quota=NUMBER            set retrieval quota to NUMBER.\n"
msgstr ""

#: src/main.c:445
msgid ""
"       --bind-address=ADDRESS    bind to ADDRESS (hostname or IP) on local "
"host.\n"
msgstr ""

#: src/main.c:447
msgid "       --limit-rate=RATE         limit download rate to RATE.\n"
msgstr ""

#: src/main.c:449
msgid "       --no-dns-cache            disable caching DNS lookups.\n"
msgstr ""

#: src/main.c:451
msgid ""
"       --restrict-file-names=OS  restrict chars in file names to ones OS "
"allows.\n"
msgstr ""

#: src/main.c:453
msgid ""
"       --ignore-case             ignore case when matching files/"
"directories.\n"
msgstr ""

#: src/main.c:456
msgid "  -4,  --inet4-only              connect only to IPv4 addresses.\n"
msgstr ""

#: src/main.c:458
msgid "  -6,  --inet6-only              connect only to IPv6 addresses.\n"
msgstr ""

#: src/main.c:460
msgid ""
"       --prefer-family=FAMILY    connect first to addresses of specified "
"family,\n"
"                                 one of IPv6, IPv4, or none.\n"
msgstr ""

#: src/main.c:464
msgid "       --user=USER               set both ftp and http user to USER.\n"
msgstr ""

#: src/main.c:466
msgid ""
"       --password=PASS           set both ftp and http password to PASS.\n"
msgstr ""

#: src/main.c:470
#, fuzzy
msgid "Directories:\n"
msgstr "Directorio  "

#: src/main.c:472
msgid "  -nd, --no-directories           don't create directories.\n"
msgstr ""

#: src/main.c:474
msgid "  -x,  --force-directories        force creation of directories.\n"
msgstr ""

#: src/main.c:476
msgid "  -nH, --no-host-directories      don't create host directories.\n"
msgstr ""

#: src/main.c:478
msgid "       --protocol-directories     use protocol name in directories.\n"
msgstr ""

#: src/main.c:480
msgid "  -P,  --directory-prefix=PREFIX  save files to PREFIX/...\n"
msgstr ""

#: src/main.c:482
msgid ""
"       --cut-dirs=NUMBER          ignore NUMBER remote directory "
"components.\n"
msgstr ""

#: src/main.c:486
msgid "HTTP options:\n"
msgstr ""

#: src/main.c:488
msgid "       --http-user=USER        set http user to USER.\n"
msgstr ""

#: src/main.c:490
msgid "       --http-password=PASS    set http password to PASS.\n"
msgstr ""

#: src/main.c:492
msgid "       --no-cache              disallow server-cached data.\n"
msgstr ""

#: src/main.c:494
msgid ""
"  -E,  --html-extension        save HTML documents with `.html' extension.\n"
msgstr ""

#: src/main.c:496
msgid "       --ignore-length         ignore `Content-Length' header field.\n"
msgstr ""

#: src/main.c:498
msgid "       --header=STRING         insert STRING among the headers.\n"
msgstr ""

#: src/main.c:500
msgid "       --max-redirect          maximum redirections allowed per page.\n"
msgstr ""

#: src/main.c:502
msgid "       --proxy-user=USER       set USER as proxy username.\n"
msgstr ""

#: src/main.c:504
msgid "       --proxy-password=PASS   set PASS as proxy password.\n"
msgstr ""

#: src/main.c:506
msgid ""
"       --referer=URL           include `Referer: URL' header in HTTP "
"request.\n"
msgstr ""

#: src/main.c:508
msgid "       --save-headers          save the HTTP headers to file.\n"
msgstr ""

#: src/main.c:510
msgid ""
"  -U,  --user-agent=AGENT      identify as AGENT instead of Wget/VERSION.\n"
msgstr ""

#: src/main.c:512
msgid ""
"       --no-http-keep-alive    disable HTTP keep-alive (persistent "
"connections).\n"
msgstr ""

#: src/main.c:514
msgid "       --no-cookies            don't use cookies.\n"
msgstr ""

#: src/main.c:516
msgid "       --load-cookies=FILE     load cookies from FILE before session.\n"
msgstr ""

#: src/main.c:518
msgid "       --save-cookies=FILE     save cookies to FILE after session.\n"
msgstr ""

#: src/main.c:520
msgid ""
"       --keep-session-cookies  load and save session (non-permanent) "
"cookies.\n"
msgstr ""

#: src/main.c:522
msgid ""
"       --post-data=STRING      use the POST method; send STRING as the "
"data.\n"
msgstr ""

#: src/main.c:524
msgid ""
"       --post-file=FILE        use the POST method; send contents of FILE.\n"
msgstr ""

#: src/main.c:526
msgid ""
"       --no-content-disposition  don't honor Content-Disposition header.\n"
msgstr ""

#: src/main.c:531
msgid "HTTPS (SSL/TLS) options:\n"
msgstr ""

#: src/main.c:533
msgid ""
"       --secure-protocol=PR     choose secure protocol, one of auto, SSLv2,\n"
"                                SSLv3, and TLSv1.\n"
msgstr ""

#: src/main.c:536
msgid ""
"       --no-check-certificate   don't validate the server's certificate.\n"
msgstr ""

#: src/main.c:538
msgid "       --certificate=FILE       client certificate file.\n"
msgstr ""

#: src/main.c:540
msgid "       --certificate-type=TYPE  client certificate type, PEM or DER.\n"
msgstr ""

#: src/main.c:542
msgid "       --private-key=FILE       private key file.\n"
msgstr ""

#: src/main.c:544
msgid "       --private-key-type=TYPE  private key type, PEM or DER.\n"
msgstr ""

#: src/main.c:546
msgid "       --ca-certificate=FILE    file with the bundle of CA's.\n"
msgstr ""

#: src/main.c:548
msgid ""
"       --ca-directory=DIR       directory where hash list of CA's is "
"stored.\n"
msgstr ""

#: src/main.c:550
msgid ""
"       --random-file=FILE       file with random data for seeding the SSL "
"PRNG.\n"
msgstr ""

#: src/main.c:552
msgid ""
"       --egd-file=FILE          file naming the EGD socket with random "
"data.\n"
msgstr ""

#: src/main.c:557
msgid "FTP options:\n"
msgstr ""

#: src/main.c:559
msgid "       --ftp-user=USER         set ftp user to USER.\n"
msgstr ""

#: src/main.c:561
msgid "       --ftp-password=PASS     set ftp password to PASS.\n"
msgstr ""

#: src/main.c:563
msgid "       --no-remove-listing     don't remove `.listing' files.\n"
msgstr ""

#: src/main.c:565
msgid "       --no-glob               turn off FTP file name globbing.\n"
msgstr ""

#: src/main.c:567
msgid "       --no-passive-ftp        disable the \"passive\" transfer mode.\n"
msgstr ""

#: src/main.c:569
msgid ""
"       --retr-symlinks         when recursing, get linked-to files (not "
"dir).\n"
msgstr ""

#: src/main.c:571
msgid "       --preserve-permissions  preserve remote file permissions.\n"
msgstr ""

#: src/main.c:575
msgid "Recursive download:\n"
msgstr ""

#: src/main.c:577
msgid "  -r,  --recursive          specify recursive download.\n"
msgstr ""

#: src/main.c:579
msgid ""
"  -l,  --level=NUMBER       maximum recursion depth (inf or 0 for "
"infinite).\n"
msgstr ""

#: src/main.c:581
msgid ""
"       --delete-after       delete files locally after downloading them.\n"
msgstr ""

#: src/main.c:583
msgid ""
"  -k,  --convert-links      make links in downloaded HTML point to local "
"files.\n"
msgstr ""

#: src/main.c:585
msgid ""
"  -K,  --backup-converted   before converting file X, back up as X.orig.\n"
msgstr ""

#: src/main.c:587
msgid ""
"  -m,  --mirror             shortcut for -N -r -l inf --no-remove-listing.\n"
msgstr ""

#: src/main.c:589
msgid ""
"  -p,  --page-requisites    get all images, etc. needed to display HTML "
"page.\n"
msgstr ""

#: src/main.c:591
msgid ""
"       --strict-comments    turn on strict (SGML) handling of HTML "
"comments.\n"
msgstr ""

#: src/main.c:595
msgid "Recursive accept/reject:\n"
msgstr ""

#: src/main.c:597
msgid ""
"  -A,  --accept=LIST               comma-separated list of accepted "
"extensions.\n"
msgstr ""

#: src/main.c:599
msgid ""
"  -R,  --reject=LIST               comma-separated list of rejected "
"extensions.\n"
msgstr ""

#: src/main.c:601
msgid ""
"  -D,  --domains=LIST              comma-separated list of accepted "
"domains.\n"
msgstr ""

#: src/main.c:603
msgid ""
"       --exclude-domains=LIST      comma-separated list of rejected "
"domains.\n"
msgstr ""

#: src/main.c:605
msgid ""
"       --follow-ftp                follow FTP links from HTML documents.\n"
msgstr ""

#: src/main.c:607
msgid ""
"       --follow-tags=LIST          comma-separated list of followed HTML "
"tags.\n"
msgstr ""

#: src/main.c:609
msgid ""
"       --ignore-tags=LIST          comma-separated list of ignored HTML "
"tags.\n"
msgstr ""

#: src/main.c:611
msgid ""
"  -H,  --span-hosts                go to foreign hosts when recursive.\n"
msgstr ""

#: src/main.c:613
msgid "  -L,  --relative                  follow relative links only.\n"
msgstr ""

#: src/main.c:615
msgid "  -I,  --include-directories=LIST  list of allowed directories.\n"
msgstr ""

#: src/main.c:617
msgid "  -X,  --exclude-directories=LIST  list of excluded directories.\n"
msgstr ""

#: src/main.c:619
msgid ""
"  -np, --no-parent                 don't ascend to the parent directory.\n"
msgstr ""

#: src/main.c:623
msgid "Mail bug reports and suggestions to <bug-wget@gnu.org>.\n"
msgstr "Env�e informaci�n sobre errores y sugerencias a <bug-wget@gnu.org>.\n"

#: src/main.c:628
#, c-format
msgid "GNU Wget %s, a non-interactive network retriever.\n"
msgstr "GNU Wget %s, un recuperador por red no interactivo.\n"

#: src/main.c:668
#, fuzzy
msgid "Copyright (C) 2007 Free Software Foundation, Inc.\n"
msgstr ""
"Copyright (C) 1995, 1996, 1997, 1998, 2000, 2001 Free Software Foundation, "
"Inc.\n"

#: src/main.c:670
msgid ""
"License GPLv3+: GNU GPL version 3 or later\n"
"<http://www.gnu.org/licenses/gpl.html>.\n"
"This is free software: you are free to change and redistribute it.\n"
"There is NO WARRANTY, to the extent permitted by law.\n"
msgstr ""

#: src/main.c:675
#, fuzzy
msgid ""
"\n"
"Originally written by Hrvoje Niksic <hniksic@xemacs.org>.\n"
msgstr ""
"\n"
"Escrito originalmente por Hrvoje Niksic <hniksic@arsdigita.com>.\n"

#: src/main.c:677
msgid "Currently maintained by Micah Cowan <micah@cowan.name>.\n"
msgstr ""

#. #### Something nicer should be printed here -- similar to the
#. pre-1.5 `--help' page.
#: src/main.c:724 src/main.c:793 src/main.c:890
#, c-format
msgid "Try `%s --help' for more options.\n"
msgstr "Ejecute `%s --help' para obtener la lista de opciones.\n"

#: src/main.c:790
#, c-format
msgid "%s: illegal option -- `-n%c'\n"
msgstr "%s: opci�n ilegal -- `-n%c'\n"

# Como otras veces, te propongo que sustituyas `sacar' por `ofrecer' -
# cll
#
#: src/main.c:845
#, c-format
msgid "Can't be verbose and quiet at the same time.\n"
msgstr "No se puede ofrecer informaci�n y estar silencioso al mismo tiempo.\n"

#: src/main.c:851
#, c-format
msgid "Can't timestamp and not clobber old files at the same time.\n"
msgstr ""
"No se pueden usar marcas de tiempo y no sobreescribir ficheros al mismo "
"tiempo.\n"

#: src/main.c:859
#, c-format
msgid "Cannot specify both --inet4-only and --inet6-only.\n"
msgstr ""

#: src/main.c:869
#, c-format
msgid "Cannot specify -r, -p or -N if -O is given.\n"
msgstr ""

#: src/main.c:877
#, c-format
msgid "Cannot specify both -k and -O if multiple URLs are given.\n"
msgstr ""

#. No URL specified.
#: src/main.c:885
#, c-format
msgid "%s: missing URL\n"
msgstr "%s: falta la URL\n"

#: src/main.c:1005
#, c-format
msgid "No URLs found in %s.\n"
msgstr "No se han encontrado URLs en %s.\n"
