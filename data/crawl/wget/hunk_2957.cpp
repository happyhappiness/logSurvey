 "Intent�ndoo de novo.\n"
 "\n"
 
-#: src/url.c:621
+#: src/url.c:642
 msgid "No error"
 msgstr "Ning�n erro"
 
-#: src/url.c:623
+#: src/url.c:644
 msgid "Unsupported scheme"
 msgstr "Esquema non soportado"
 
-#: src/url.c:625
+#: src/url.c:646
 msgid "Empty host"
 msgstr "Nome baleiro"
 
-#: src/url.c:627
+#: src/url.c:648
 msgid "Bad port number"
 msgstr "N�mero de porto incorrecto"
 
-#: src/url.c:629
+#: src/url.c:650
 msgid "Invalid user name"
 msgstr "O nome do usuario non � v�lido"
 
-#: src/url.c:631
+#: src/url.c:652
 msgid "Unterminated IPv6 numeric address"
 msgstr "Enderezo IPv6 num�rico sen rematar"
 
-#: src/url.c:633
+#: src/url.c:654
 msgid "IPv6 addresses not supported"
 msgstr "Non se soportan os enderezos IPv6"
 
-#: src/url.c:635
+#: src/url.c:656
 msgid "Invalid IPv6 numeric address"
 msgstr "Enderezo IPv6 num�rico non v�lido"
 
-#: src/utils.c:120
-#, c-format
-msgid "%s: %s: Not enough memory.\n"
-msgstr "%s: %s: Non hai memoria dabondo.\n"
-
 #. parent, no error
-#: src/utils.c:485
+#: src/utils.c:347
 #, c-format
 msgid "Continuing in background, pid %d.\n"
 msgstr "Seguindo en segundo plano, pid %d.\n"
 
-#: src/utils.c:529
+#: src/utils.c:391
 #, c-format
 msgid "Failed to unlink symlink `%s': %s\n"
 msgstr "Fallo ao desligar `%s': %s\n"
 
+#: src/xmalloc.c:72
+#, c-format
+msgid "%s: %s: Failed to allocate %ld bytes; memory exhausted.\n"
+msgstr ""
+
+#~ msgid "Unable to convert `%s' to a bind address.  Reverting to ANY.\n"
+#~ msgstr ""
+#~ "Non se puido converter `%s' a un enderezo de asignaci�n. Cambiando a "
+#~ "CALQUERA.\n"
+
+#~ msgid ""
+#~ "\n"
+#~ "REST failed; will not truncate `%s'.\n"
+#~ msgstr ""
+#~ "\n"
+#~ "REST fallou; non se ha truncar `%s'.\n"
+
+#~ msgid " [%s to go]"
+#~ msgstr " [quedan %s por descargar]"
+
+#~ msgid "Host not found"
+#~ msgstr "Non se atopou o servidor"
+
+#~ msgid "End of file while parsing headers.\n"
+#~ msgstr "Fin de ficheiro mentres se analizaban as cabeceiras.\n"
+
+#~ msgid ""
+#~ "\n"
+#~ "Continued download failed on this file, which conflicts with `-c'.\n"
+#~ "Refusing to truncate existing file `%s'.\n"
+#~ "\n"
+#~ msgstr ""
+#~ "\n"
+#~ "Non se puido continua-la descarga do ficheiro, o que � incompatible con `-"
+#~ "c'.\n"
+#~ "Non se ha trunca-lo ficheiro existente `%s'.\n"
+#~ "\n"
+
+#~ msgid " (%s to go)"
+#~ msgstr " (quedan %s por descargar)"
+
+#~ msgid ""
+#~ "Startup:\n"
+#~ "  -V,  --version           display the version of Wget and exit.\n"
+#~ "  -h,  --help              print this help.\n"
+#~ "  -b,  --background        go to background after startup.\n"
+#~ "  -e,  --execute=COMMAND   execute a `.wgetrc'-style command.\n"
+#~ "\n"
+#~ msgstr ""
+#~ "Comezo:\n"
+#~ "  -V,  --version           amosa a versi�n de Wget e sae.\n"
+#~ "  -h,  --help              amosa esta axuda.\n"
+#~ "  -b,  --background        deixa o proceso en segundo plano.\n"
+#~ "  -e,  --execute=COMANDO   executa un comando esto�p `.wgetrc'.\n"
+#~ "\n"
+
+#~ msgid ""
+#~ "Logging and input file:\n"
+#~ "  -o,  --output-file=FILE     log messages to FILE.\n"
+#~ "  -a,  --append-output=FILE   append messages to FILE.\n"
+#~ "  -d,  --debug                print debug output.\n"
+#~ "  -q,  --quiet                quiet (no output).\n"
+#~ "  -v,  --verbose              be verbose (this is the default).\n"
+#~ "  -nv, --non-verbose          turn off verboseness, without being quiet.\n"
+#~ "  -i,  --input-file=FILE      download URLs found in FILE.\n"
+#~ "  -F,  --force-html           treat input file as HTML.\n"
+#~ "  -B,  --base=URL             prepends URL to relative links in -F -i "
+#~ "file.\n"
+#~ "\n"
+#~ msgstr ""
+#~ "Rexistro e ficheiro de entrada:\n"
+#~ "  -o,  --output-file=FICHEIRO   rexistra-las mensaxes no FICHEIRO.\n"
+#~ "  -a,  --append-output=FICHEIRO engadir mensaxes ao FICHEIRO.\n"
+#~ "  -d,  --debug                  amosar informaci�n de depuraci�n.\n"
+#~ "  -q,  --quiet                  en silencio (sen mensaxes).\n"
+#~ "  -v,  --verbose                moi falador (esta � a opci�n por "
+#~ "defecto).\n"
+#~ "  -nv, --non-verbose            non moi falador, sen estar en silencio.\n"
+#~ "  -i,  --input-file=FICHEIRO    descarga-las URLs indicadas no FICHEIRO.\n"
+#~ "  -F,  --force-html             trata-lo ficheiro de entrada coma HTML.\n"
+#~ "  -B,  --base=URL               precede-la URL nas ligaz�ns relativas\n"
+#~ "                                   en -F -i ficheiro.\n"
+#~ "\n"
+
+#~ msgid ""
+#~ "Download:\n"
+#~ "  -t,  --tries=NUMBER           set number of retries to NUMBER (0 "
+#~ "unlimits).\n"
+#~ "       --retry-connrefused      retry even if connection is refused.\n"
+#~ "  -O   --output-document=FILE   write documents to FILE.\n"
+#~ "  -nc, --no-clobber             don't clobber existing files or use .# "
+#~ "suffixes.\n"
+#~ "  -c,  --continue               resume getting a partially-downloaded "
+#~ "file.\n"
+#~ "       --progress=TYPE          select progress gauge type.\n"
+#~ "  -N,  --timestamping           don't re-retrieve files unless newer than "
+#~ "local.\n"
+#~ "  -S,  --server-response        print server response.\n"
+#~ "       --spider                 don't download anything.\n"
+#~ "  -T,  --timeout=SECONDS        set all timeout values to SECONDS.\n"
+#~ "       --dns-timeout=SECS       set the DNS lookup timeout to SECS.\n"
+#~ "       --connect-timeout=SECS   set the connect timeout to SECS.\n"
+#~ "       --read-timeout=SECS      set the read timeout to SECS.\n"
+#~ "  -w,  --wait=SECONDS           wait SECONDS between retrievals.\n"
+#~ "       --waitretry=SECONDS      wait 1...SECONDS between retries of a "
+#~ "retrieval.\n"
+#~ "       --random-wait            wait from 0...2*WAIT secs between "
+#~ "retrievals.\n"
+#~ "  -Y,  --proxy=on/off           turn proxy on or off.\n"
+#~ "  -Q,  --quota=NUMBER           set retrieval quota to NUMBER.\n"
+#~ "       --bind-address=ADDRESS   bind to ADDRESS (hostname or IP) on local "
+#~ "host.\n"
+#~ "       --limit-rate=RATE        limit download rate to RATE.\n"
+#~ "       --dns-cache=off          disable caching DNS lookups.\n"
+#~ "       --restrict-file-names=OS restrict chars in file names to ones OS "
+#~ "allows.\n"
+#~ "\n"
+#~ msgstr ""
+#~ "Descarga de ficheiros:\n"
+#~ "  -t,  --tries=N�MERO             facer N�MERO tentativas (0 � sen "
+#~ "l�mite).\n"
+#~ "       --retry-connrefused        volver tentar se se rexeita a "
+#~ "conexi�n.\n"
+#~ "  -O   --output-document=FICHEIRO escribi-los documentos ao FICHEIRO.\n"
+#~ "  -nc, --no-clobber               non esmaga-los ficheiros que xa "
+#~ "existan\n"
+#~ "                                        ou empregar sufixos .n�\n"
+#~ "  -c,  --continue                 seguir descargando un ficheiro que xa "
+#~ "exista.\n"
+#~ "       --progress=TIPO            escolle-lo tipo de indicador de "
+#~ "progreso.\n"
+#~ "  -N,  --timestamping             non descarga-los ficheiros se son m�is\n"
+#~ "                                        vellos que os locais.\n"
+#~ "  -S,  --server-response          amosa-las respostas do servidor.\n"
+#~ "       --spider                   non descargar nada.\n"
+#~ "  -T,  --timeout=SEGUNDOS         estabrecer t�dolos tempos de "
+#~ "vencemento\n"
+#~ "                                        en SEGUNDOS.\n"
+#~ "       --dns-timeout=SEGUNDOS     estabrece-lo tempo de vencemento de "
+#~ "busca\n"
+#~ "                                        en DNS en SEGUNDOS.\n"
+#~ "       --connect-timeout=SEGUNDOS estabrece-lo tempo de vencemento de "
+#~ "conexi�n\n"
+#~ "                                        en SEGUNDOS.\n"
+#~ "       --read-timeout=SEGUNDOS    estabrece-lo tempo de vencemento de "
+#~ "lectura\n"
+#~ "                                        en SEGUNDOS.\n"
+#~ "  -w,  --wait=SEGUNDOS            agardar SEGUNDOS entre descargas.\n"
+#~ "       --waitretry=SEGUNDOS       agardar 1...SEGUNDOS entre intentos.\n"
+#~ "       --random-wait              agardar de 0 a 2*ESPERA seg. entre "
+#~ "intentos.\n"
+#~ "  -Y,  --proxy=on/off             activar ou desactiva-lo proxy.\n"
+#~ "  -Q,  --quota=N�MERO             establece-lo l�mite de descarga a "
+#~ "N�MERO.\n"
+#~ "       --bind-address=ENDEREZO    emprega-lo ENDEREZO (nome/IP) desta "
+#~ "m�quina.\n"
+#~ "       --limit-rate=RAZON         limita-la velocidade de descarga a "
+#~ "RAZ�N.\n"
+#~ "       --dns-cache=off            desactiva-la cach� de buscas DNS.\n"
+#~ "       --restric-file-names=SO    restrinxi-los caracteres dos nomes dos\n"
+#~ "                                        ficheiros aos que admite o SO.\n"
+#~ "\n"
+
+#~ msgid ""
+#~ "Directories:\n"
+#~ "  -nd, --no-directories            don't create directories.\n"
+#~ "  -x,  --force-directories         force creation of directories.\n"
+#~ "  -nH, --no-host-directories       don't create host directories.\n"
+#~ "  -P,  --directory-prefix=PREFIX   save files to PREFIX/...\n"
+#~ "       --cut-dirs=NUMBER           ignore NUMBER remote directory "
+#~ "components.\n"
+#~ "\n"
+#~ msgstr ""
+#~ "Directorios:\n"
+#~ "  -nd, --no-directories            non crear directorios.\n"
+#~ "  -x,  --force-directories         forza-la creaci�n de directorios.\n"
+#~ "  -nH, --no-host-directories       non crea-los directorios do servidor.\n"
+#~ "  -P,  --directory-prefix=PREFIXO  garda-los ficheiros a PREFIXO/...\n"
+#~ "       --cut-dirs=N�MERO           ignorar NUMERO compo�entes dos "
+#~ "directorios\n"
+#~ "                                        remotos.\n"
+#~ "\n"
+
+#~ msgid ""
+#~ "HTTP options:\n"
+#~ "       --http-user=USER      set http user to USER.\n"
+#~ "       --http-passwd=PASS    set http password to PASS.\n"
+#~ "  -C,  --cache=on/off        (dis)allow server-cached data (normally "
+#~ "allowed).\n"
+#~ "  -E,  --html-extension      save all text/html documents with .html "
+#~ "extension.\n"
+#~ "       --ignore-length       ignore `Content-Length' header field.\n"
+#~ "       --header=STRING       insert STRING among the headers.\n"
+#~ "       --proxy-user=USER     set USER as proxy username.\n"
+#~ "       --proxy-passwd=PASS   set PASS as proxy password.\n"
+#~ "       --referer=URL         include `Referer: URL' header in HTTP "
+#~ "request.\n"
+#~ "  -s,  --save-headers        save the HTTP headers to file.\n"
+#~ "  -U,  --user-agent=AGENT    identify as AGENT instead of Wget/VERSION.\n"
+#~ "       --no-http-keep-alive  disable HTTP keep-alive (persistent "
+#~ "connections).\n"
+#~ "       --cookies=off         don't use cookies.\n"
+#~ "       --load-cookies=FILE   load cookies from FILE before session.\n"
+#~ "       --save-cookies=FILE   save cookies to FILE after session.\n"
+#~ "       --post-data=STRING    use the POST method; send STRING as the "
+#~ "data.\n"
+#~ "       --post-file=FILE      use the POST method; send contents of FILE.\n"
+#~ "\n"
+#~ msgstr ""
+#~ "Opci�ns HTTP:\n"
+#~ "       --http-user=USUARIO   establece-lo USUARIO coma o usuario de "
+#~ "http.\n"
+#~ "       --http-passwd=CLAVE   establece-la CLAVE coma a clave de http.\n"
+#~ "  -C,  --cache=on/off        (non) admitir datos da cach� do servidor\n"
+#~ "                                (normalmente adm�tense).\n"
+#~ "  -E,  --html-extension      gravar t�dolos documentos text/html con\n"
+#~ "                                extensi�n .html\n"
+#~ "       --ignore-length       ignora-lo campo da cabeceira `Content-"
+#~ "Length'.\n"
+#~ "       --header=CADEA        inserta-la CADEA entre as cabeceiras.\n"
+#~ "       --proxy-user=USUARIO  establece-lo USUARIO coma o usuario do "
+#~ "proxy.\n"
+#~ "       --proxy-passwd=CLAVE  establece-la CLAVE coma a clave do proxy.\n"
+#~ "       --referer=URL         incluir `Referer: URL' na petici�n HTTP\n"
+#~ "  -s,  --save-headers        garda-las cabeceiras HTTP ao ficheiro.\n"
+#~ "  -U,  --user-agent=AXENTE   identificar coma AXENTE no canto de Wget/"
+#~ "VERSION.\n"
+#~ "       --no-http-keep-alive  desactiva-las conexi�ns persistentes de "
+#~ "HTTP.\n"
+#~ "       --cookies=off         non empregar cookies.\n"
+#~ "       --load-cookies=FICH   carga-las cookies do FICHeiro antes da "
+#~ "sesi�n\n"
+#~ "       --save-cookies=FICH   grava-las cookies no FICHeiro trala sesi�n\n"
+#~ "       --post-data=CADEA     emprega-lo m�todo POST; envia-la CADEA coma "
+#~ "datos.\n"
+#~ "       --post-file=FICH      emprega-lo m�todo POST; envia-lo FICHeiro.\n"
+#~ "\n"
+
+#~ msgid ""
+#~ "HTTPS (SSL) options:\n"
+#~ "       --sslcertfile=FILE     optional client certificate.\n"
+#~ "       --sslcertkey=KEYFILE   optional keyfile for this certificate.\n"
+#~ "       --egd-file=FILE        file name of the EGD socket.\n"
+#~ "       --sslcadir=DIR         dir where hash list of CA's are stored.\n"
+#~ "       --sslcafile=FILE       file with bundle of CA's\n"
+#~ "       --sslcerttype=0/1      Client-Cert type 0=PEM (default) / 1=ASN1 "
+#~ "(DER)\n"
+#~ "       --sslcheckcert=0/1     Check the server cert agenst given CA\n"
+#~ "       --sslprotocol=0-3      choose SSL protocol; 0=automatic,\n"
+#~ "                              1=SSLv2 2=SSLv3 3=TLSv1\n"
+#~ "\n"
+#~ msgstr ""
+#~ "Opci�ns de HTTPS (SSL):\n"
+#~ "       --sslcertfile=FICHEIRO  certificado opcional do cliente.\n"
+#~ "       --sslcertkey=FICHCLAVE  ficheiro de clave opcional para o "
+#~ "certificado.\n"
+#~ "       --egd-file=FICHEIRO     nome de ficheiro do socket EGD.\n"
+#~ "       --sslcadir=DIR          directorio no que se armacena a lista de "
+#~ "CAs.\n"
+#~ "       --sslcafile=FICHEIRO    ficheiro cun lote de CAs\n"
+#~ "       --sslcerttype=0/1       tipo de certificado de cliente\n"
+#~ "                               0=PEM (valor por defecto) / 1=ASN1 (DER)\n"
+#~ "       --sslcheckcert=0/1      compara-lo certificado do servidor coa CA "
+#~ "dada\n"
+#~ "       --sslprotocol=0-3       escolle-lo protocolo SSL; 0=autom�tico,\n"
+#~ "                               1=SSLv2 2=SSLv3 3=TLSv1\n"
+#~ "\n"
+
+#~ msgid ""
+#~ "FTP options:\n"
+#~ "  -nr, --dont-remove-listing   don't remove `.listing' files.\n"
+#~ "  -g,  --glob=on/off           turn file name globbing on or off.\n"
+#~ "       --passive-ftp           use the \"passive\" transfer mode.\n"
+#~ "       --retr-symlinks         when recursing, get linked-to files (not "
+#~ "dirs).\n"
+#~ "\n"
+#~ msgstr ""
+#~ "Opci�ns FTP:\n"
+#~ "  -nr, --dont-remove-listing   non elimina-los ficheiros `.listing'.\n"
+#~ "  -g,  --glob=on/off           usar ou non comparaci�n de nomes de "
+#~ "ficheiros\n"
+#~ "                                  con patr�ns.\n"
+#~ "       --passive-ftp           usa-lo modo de transferencia \"passive\".\n"
+#~ "       --retr-symlinks         ao descargar recursivamente, descarga-los\n"
+#~ "                                  ficheiros ligados (non os "
+#~ "directorios).\n"
+#~ "\n"
+
+#~ msgid ""
+#~ "Recursive retrieval:\n"
+#~ "  -r,  --recursive          recursive download.\n"
+#~ "  -l,  --level=NUMBER       maximum recursion depth (inf or 0 for "
+#~ "infinite).\n"
+#~ "       --delete-after       delete files locally after downloading them.\n"
+#~ "  -k,  --convert-links      convert non-relative links to relative.\n"
+#~ "  -K,  --backup-converted   before converting file X, back up as X.orig.\n"
+#~ "  -m,  --mirror             shortcut option equivalent to -r -N -l inf -"
+#~ "nr.\n"
+#~ "  -p,  --page-requisites    get all images, etc. needed to display HTML "
+#~ "page.\n"
+#~ "       --strict-comments    turn on strict (SGML) handling of HTML "
+#~ "comments.\n"
+#~ "\n"
+#~ msgstr ""
+#~ "Descarga recursiva:\n"
+#~ "  -r,  --recursive             descarga recursiva.\n"
+#~ "  -l,  --level=NUMERO          m�ximo nivel de recursi�n (empregue inf ou "
+#~ "0\n"
+#~ "                                  para infinito).\n"
+#~ "       --delete-after          borra-los ficheiros despois de "
+#~ "descargalos.\n"
+#~ "  -k,  --convert-links         converti-las ligaz�ns non relativas a "
+#~ "relativas.\n"
+#~ "  -K,  --backup-converted      antes de converti-lo ficheiro X, facer "
+#~ "unha\n"
+#~ "                                  copia chamada X.orig\n"
+#~ "  -m,  --mirror                opci�n atallo equivalente a -r -N -l inf -"
+#~ "nr.\n"
+#~ "  -nr, --dont-remove-listing   non borra-los ficheiros `.listing'.\n"
+#~ "  -p,  --page-requisites       obter t�dalas imaxes, etc. necesarias "
+#~ "para\n"
+#~ "                                  amosa-la p�xina HTML.\n"
+#~ "       --strict-comments       activa-lo manexo estricto (SGML) dos\n"
+#~ "                                  comentarios HTML.\n"
+#~ "\n"
+
+#~ msgid ""
+#~ "Recursive accept/reject:\n"
+#~ "  -A,  --accept=LIST                comma-separated list of accepted "
+#~ "extensions.\n"
+#~ "  -R,  --reject=LIST                comma-separated list of rejected "
+#~ "extensions.\n"
+#~ "  -D,  --domains=LIST               comma-separated list of accepted "
+#~ "domains.\n"
+#~ "       --exclude-domains=LIST       comma-separated list of rejected "
+#~ "domains.\n"
+#~ "       --follow-ftp                 follow FTP links from HTML "
+#~ "documents.\n"
+#~ "       --follow-tags=LIST           comma-separated list of followed HTML "
+#~ "tags.\n"
+#~ "  -G,  --ignore-tags=LIST           comma-separated list of ignored HTML "
+#~ "tags.\n"
+#~ "  -H,  --span-hosts                 go to foreign hosts when recursive.\n"
+#~ "  -L,  --relative                   follow relative links only.\n"
+#~ "  -I,  --include-directories=LIST   list of allowed directories.\n"
+#~ "  -X,  --exclude-directories=LIST   list of excluded directories.\n"
+#~ "  -np, --no-parent                  don't ascend to the parent "
+#~ "directory.\n"
+#~ "\n"
+#~ msgstr ""
+#~ "Aceptar/rexeitar en descargas recursivas:\n"
+#~ "  -A,  --accept=LISTA               lista de extensi�ns aceptadas,\n"
+#~ "                                        separadas por comas.\n"
+#~ "  -R,  --reject=LISTA               lista de extensi�ns rexeitadas,\n"
+#~ "                                        separadas por comas.\n"
+#~ "  -D,  --domains=LISTA              lista de dominios aceptados,\n"
+#~ "                                        separadas por comas.\n"
+#~ "       --exclude-domains=LISTA      lista de dominios rexeitados,\n"
+#~ "                                        separadas por comas.\n"
+#~ "       --follow-ftp                 segui-las ligaz�ns a FTP dende "
+#~ "documentos\n"
+#~ "                                        en HTML.\n"
+#~ "       --follow-tags=LISTA          lista de etiquetas HTML que se "
+#~ "siguen,\n"
+#~ "                                        separadas por comas.\n"
+#~ "  -G,  --ignore-tags=LISTA          lista de etiquetas HTML que se "
+#~ "ignoran,\n"
+#~ "                                        separadas por comas.\n"
+#~ "  -H,  --span-hosts                 ir a servidores de f�ra durante a\n"
+#~ "                                        recursi�n.\n"
+#~ "  -L,  --relative                   seguir s� as ligaz�ns relativas.\n"
+#~ "  -I,  --include-directories=LISTA  lista de directorios admitidos.\n"
+#~ "  -X,  --exclude-directories=LISTA  lista de directorios exclu�dos.\n"
+#~ "  -np, --no-parent                  non ascender ao directorio pai.\n"
+#~ "\n"
+
+#~ msgid "%s: debug support not compiled in.\n"
+#~ msgstr "%s: non se compilou con soporte de depuraci�n.\n"
+
+#~ msgid "Starting WinHelp %s\n"
+#~ msgstr "Comezando WinHelp %s\n"
+
+#~ msgid "%s: %s: Not enough memory.\n"
+#~ msgstr "%s: %s: Non hai memoria dabondo.\n"
+
 #~ msgid "Syntax error in Set-Cookie at character `%c'.\n"
 #~ msgstr "Erro de sintaxe en Set-Cookie no car�cter `%c'.\n"
 