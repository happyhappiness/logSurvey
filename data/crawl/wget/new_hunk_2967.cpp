"Altro tentativo in corso.\n"
"\n"

#: src/url.c:642
msgid "No error"
msgstr "Nessun errore"

#: src/url.c:644
msgid "Unsupported scheme"
msgstr "Schema non supportato"

#: src/url.c:646
msgid "Empty host"
msgstr "Host vuoto"

#: src/url.c:648
msgid "Bad port number"
msgstr "Numero di porta non valido"

#: src/url.c:650
msgid "Invalid user name"
msgstr "Nome utente non valido"

#: src/url.c:652
msgid "Unterminated IPv6 numeric address"
msgstr "Indirizzo numerico IPv6 non terminato"

#: src/url.c:654
msgid "IPv6 addresses not supported"
msgstr "Indirizzo IPv6 non supportato"

#: src/url.c:656
msgid "Invalid IPv6 numeric address"
msgstr "Indirizzo numerico IPv6 non valido"

#. parent, no error
#: src/utils.c:347
#, c-format
msgid "Continuing in background, pid %d.\n"
msgstr "Continuo in background, pid %d.\n"

#: src/utils.c:391
#, c-format
msgid "Failed to unlink symlink `%s': %s\n"
msgstr "Rimozione del link simbolico \"%s\" non riuscita: %s\n"

#: src/xmalloc.c:72
#, c-format
msgid "%s: %s: Failed to allocate %ld bytes; memory exhausted.\n"
msgstr ""

# FIXME
#~ msgid "Unable to convert `%s' to a bind address.  Reverting to ANY.\n"
#~ msgstr ""
#~ "Impossibile convertire \"%s\" in un indirizzo di bind. Utilizzato ANY.\n"

# Cos'è questo REST?
#~ msgid ""
#~ "\n"
#~ "REST failed; will not truncate `%s'.\n"
#~ msgstr ""
#~ "\n"
#~ "REST non riuscito; \"%s\" non verrà troncato.\n"

#~ msgid " [%s to go]"
#~ msgstr " [%s alla fine]"

#~ msgid "Host not found"
#~ msgstr "Host non trovato"

# parsing: analisi? lettura?
#~ msgid "End of file while parsing headers.\n"
#~ msgstr "Raggiunta la fine del file durante l'analisi degli header.\n"

#~ msgid ""
#~ "\n"
#~ "Continued download failed on this file, which conflicts with `-c'.\n"
#~ "Refusing to truncate existing file `%s'.\n"
#~ "\n"
#~ msgstr ""
#~ "\n"
#~ "La ripresa dello scaricamento non è riuscita su questo file, in "
#~ "conflitto\n"
#~ "con \"-c\".\n"
#~ "Troncamento del file esistente \"%s\" rifiutato.\n"
#~ "\n"

#~ msgid " (%s to go)"
#~ msgstr " (%s alla fine)"

#~ msgid ""
#~ "Startup:\n"
#~ "  -V,  --version           display the version of Wget and exit.\n"
#~ "  -h,  --help              print this help.\n"
#~ "  -b,  --background        go to background after startup.\n"
#~ "  -e,  --execute=COMMAND   execute a `.wgetrc'-style command.\n"
#~ "\n"
#~ msgstr ""
#~ "Avvio:\n"
#~ "  -V,  --version           mostra la versione di Wget ed esci.\n"
#~ "  -h,  --help              mostra questo aiuto.\n"
#~ "  -b,  --background        va in background dopo l'avvio.\n"
#~ "  -e,  --execute=COMANDO   esegue COMANDO come se fosse scritto in \"."
#~ "wgetrc\".\n"
#~ "\n"

# L'opzione -B è stata tradotta consultando man wget.
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
#~ "\n"
#~ msgstr ""
#~ "File di log e d'ingresso:\n"
#~ "  -o,  --output-file=FILE     registra i messaggi su FILE.\n"
#~ "  -a,  --append-output=FILE   accoda i messaggi a FILE.\n"
#~ "  -d,  --debug                mostra l'output di debug.\n"
#~ "  -q,  --quiet                silenzioso (nessun output).\n"
#~ "  -v,  --verbose              prolisso (comportamento predefinito).\n"
#~ "  -nv, --non-verbose          meno prolisso, ma non silenzioso.\n"
#~ "  -i,  --input-file=FILE      scarica gli URL scritti in FILE.\n"
#~ "  -F,  --force-html           tratta il file di input come HTML.\n"
#~ "  -B,  --base=URL             aggiunge URL ai link relativi quando si usa "
#~ "-F\n"
#~ "                              sul file indicato con -i.\n"

# L'opzione -nc --no-clobber è stata tradotta in modo più breve seguendo
# l'esempio della traduzione francese.
# L'opzione --limit-rate=RATE è stata tradotta consultando man wget.
#~ msgid ""
#~ "Download:\n"
#~ "  -t,  --tries=NUMBER           set number of retries to NUMBER (0 "
#~ "unlimits).\n"
#~ "       --retry-connrefused      retry even if connection is refused.\n"
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
#~ "  -T,  --timeout=SECONDS        set all timeout values to SECONDS.\n"
#~ "       --dns-timeout=SECS       set the DNS lookup timeout to SECS.\n"
#~ "       --connect-timeout=SECS   set the connect timeout to SECS.\n"
#~ "       --read-timeout=SECS      set the read timeout to SECS.\n"
#~ "  -w,  --wait=SECONDS           wait SECONDS between retrievals.\n"
#~ "       --waitretry=SECONDS      wait 1...SECONDS between retries of a "
#~ "retrieval.\n"
#~ "       --random-wait            wait from 0...2*WAIT secs between "
#~ "retrievals.\n"
#~ "  -Y,  --proxy=on/off           turn proxy on or off.\n"
#~ "  -Q,  --quota=NUMBER           set retrieval quota to NUMBER.\n"
#~ "       --bind-address=ADDRESS   bind to ADDRESS (hostname or IP) on local "
#~ "host.\n"
#~ "       --limit-rate=RATE        limit download rate to RATE.\n"
#~ "       --dns-cache=off          disable caching DNS lookups.\n"
#~ "       --restrict-file-names=OS restrict chars in file names to ones OS "
#~ "allows.\n"
#~ "\n"
#~ msgstr ""
#~ "Scaricamento:\n"
#~ "  -t,  --tries=NUMERO           imposta il NUMERO di tentativi (0 = "
#~ "illimitati).\n"
#~ "       --retry-connrefused      riprova anche se la connessione è "
#~ "rifiutata.\n"
#~ "  -O   --output-document=FILE   scrive tutti i documenti in un singolo "
#~ "FILE.\n"
#~ "  -nc, --no-clobber             non sovrascrive i file già esistenti.\n"
#~ "  -c,  --continue               riprende a scaricare un file "
#~ "parzialmente\n"
#~ "                                scaricato.\n"
#~ "       --progress=TIPO          sceglie il TIPO di misurazione di "
#~ "progresso.\n"
#~ "  -N,  --timestamping           non scarica file più vecchi di quelli "
#~ "locali.\n"
#~ "  -S,  --server-response        mostra le risposte del server.\n"
#~ "       --spider                 non scarica niente.\n"
#~ "  -T,  --timeout=SECONDI        imposta tutti i timeout a SECONDI.\n"
#~ "       --dns-timeout=SECONDI    imposta il timeout per la risoluzione del "
#~ "DNS\n"
#~ "                                a SECONDI.\n"
#~ "       --connect-timeout=SEC.   imposta il timeout di connessione a "
#~ "SECONDI.\n"
#~ "       --read-timeout=SECONDI   imposta il timeout di lettura a SECONDI.\n"
#~ "  -w,  --wait=SECONDI           aspetta SECONDI tra i vari download.\n"
#~ "       --waitretry=SECONDI      aspetta 1...SECONDI tra i tentativi di "
#~ "download.\n"
#~ "       --random-wait            aspetta tra 0...2*WAIT secondi tra "
#~ "tentativi.\n"
#~ "  -Y,  --proxy=on/off           attiva/disabilita l'uso del proxy.\n"
#~ "  -Q,  --quota=NUMERO           imposta la quota di scarico a NUMERO.\n"
#~ "       --bind-address=INDIRIZZO lega l'INDIRIZZO (nome dell'host o IP)\n"
#~ "                                all'host locale.\n"
#~ "       --limit-rate=VELOCITÀ    limita la VELOCITÀ di scaricamento in "
#~ "byte.\n"
#~ "       --dns-cache=off          disattiva la cache per la risoluzione del "
#~ "DNS.\n"
#~ "       --restrict-file-names=SO limita i caratteri nei nomi dei file a "
#~ "quelli\n"
#~ "                                permessi dal sistema operativo SO "
#~ "indicato.\n"

#~ msgid ""
#~ "Directories:\n"
#~ "  -nd, --no-directories            don't create directories.\n"
#~ "  -x,  --force-directories         force creation of directories.\n"
#~ "  -nH, --no-host-directories       don't create host directories.\n"
#~ "  -P,  --directory-prefix=PREFIX   save files to PREFIX/...\n"
#~ "       --cut-dirs=NUMBER           ignore NUMBER remote directory "
#~ "components.\n"
#~ "\n"
#~ msgstr ""
#~ "Directory:\n"
#~ "  -nd  --no-directories              non crea directory.\n"
#~ "  -x,  --force-directories           forza la creazione delle directory.\n"
#~ "  -nH, --no-host-directories         non crea directory sull'host.\n"
#~ "  -P,  --directory-prefix=PREFISSO   salva i file in PREFISSO/...\n"
#~ "       --cut-dirs=NUMERO             ignora NUMERO componenti delle\n"
#~ "                                     directory remote.\n"
#~ "\n"

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
#~ "       --post-data=STRING    use the POST method; send STRING as the "
#~ "data.\n"
#~ "       --post-file=FILE      use the POST method; send contents of FILE.\n"
#~ "\n"
#~ msgstr ""
#~ "Opzioni HTTP:\n"
#~ "       --http-user=UTENTE    imposta l'utente http a UTENTE.\n"
#~ "       --http-passwd=PASS    imposta la password http a PASS.\n"
#~ "  -C,  --cache=on/off        permette/non permette la cache dei dati sul\n"
#~ "                             server (normalmente permessa).\n"
#~ "  -E,  --html-extension      salva tutti i documenti di tipo text/html "
#~ "con \n"
#~ "                             estensione .html.\n"
#~ "       --ignore-length       ignora il campo Content-Length degli "
#~ "header.\n"
#~ "       --header=STRINGA      inserisce STRINGA tra gli header.\n"
#~ "       --proxy-user=UTENTE   usa UTENTE come nome utente per il proxy.\n"
#~ "       --proxy-passwd=PASS   usa PASS come password per il proxy.\n"
#~ "       --referer=URL         include l'header \"Referer: URL\" nella "
#~ "richiesta\n"
#~ "                             HTTP.\n"
#~ "  -s,  --save-headers        salva gli header HTTP su file.\n"
#~ "  -U,  --user-agent=AGENT    si identifica come AGENT invece che come\n"
#~ "                             Wget/VERSIONE.\n"
#~ "       --no-http-keep-alive  disabilita l'HTTP keep-alive (connessioni\n"
#~ "                             persistenti).\n"
#~ "       --cookies=off         non usa i cookies.\n"
#~ "       --load-cookies=FILE   carica i cookies dal FILE prima della "
#~ "sessione.\n"
#~ "       --save-cookies=FILE   salva i cookies sul FILE dopo la sessione.\n"
#~ "       --post-data=STRINGA   usa il metodo POST; spedisci STRINGA come "
#~ "dati.\n"
#~ "       --post-file=FILE      usa il metodo POST; spedisci i contenuti del "
#~ "FILE.\n"

# Client-Cert: invariato? certificato del client?
#~ msgid ""
#~ "HTTPS (SSL) options:\n"
#~ "       --sslcertfile=FILE     optional client certificate.\n"
#~ "       --sslcertkey=KEYFILE   optional keyfile for this certificate.\n"
#~ "       --egd-file=FILE        file name of the EGD socket.\n"
#~ "       --sslcadir=DIR         dir where hash list of CA's are stored.\n"
#~ "       --sslcafile=FILE       file with bundle of CA's\n"
#~ "       --sslcerttype=0/1      Client-Cert type 0=PEM (default) / 1=ASN1 "
#~ "(DER)\n"
#~ "       --sslcheckcert=0/1     Check the server cert agenst given CA\n"
#~ "       --sslprotocol=0-3      choose SSL protocol; 0=automatic,\n"
#~ "                              1=SSLv2 2=SSLv3 3=TLSv1\n"
#~ "\n"
#~ msgstr ""
#~ "Opzioni HTTPS (SSL):\n"
#~ "       --sslcertfile=FILE     certificato opzionale del client.\n"
#~ "       --sslcertkey=KEYFILE   keyfile opzionale per questo certificato.\n"
#~ "       --egd-file=FILE        nome del file per il socket EGD.\n"
#~ "       --sslcadir=DIRECTORY   directory dove la lista dei CA è "
#~ "memorizzata.\n"
#~ "       --sslcafile=FILE       file contenente i CA.\n"
#~ "       --sslcerttype=0/1      tipo di Client-Cert:\n"
#~ "                              0=PEM (predefinito), 1=ASN1 (DER)\n"
#~ "       --sslcheckcert=0/1     verifica il certificato del server col CA "
#~ "fornito.\n"
#~ "       --sslprotocol=0-3      sceglie il protocollo SSL:\n"
#~ "                              0=automatico, 1=SSLv2, 2=SSLv3, 3=TLSv1\n"
#~ "\n"

#~ msgid ""
#~ "FTP options:\n"
#~ "  -nr, --dont-remove-listing   don't remove `.listing' files.\n"
#~ "  -g,  --glob=on/off           turn file name globbing on or off.\n"
#~ "       --passive-ftp           use the \"passive\" transfer mode.\n"
#~ "       --retr-symlinks         when recursing, get linked-to files (not "
#~ "dirs).\n"
#~ "\n"
#~ msgstr ""
#~ "Opzioni FTP:\n"
#~ "  -nr, --dont-remove-listing  non elimina i file \".listing\"\n"
#~ "  -g,  --glob=on/off          abilita/disabilita il globbing dei nome di "
#~ "file.\n"
#~ "       --passive-ftp          usa la modalità di trasferimento \"passiva"
#~ "\".\n"
#~ "       --retr-symlinks        scarica i file (non le directory) puntati "
#~ "dai\n"
#~ "                              link simbolici quando si è in modalità "
#~ "ricorsiva.\n"

#~ msgid ""
#~ "Recursive retrieval:\n"
#~ "  -r,  --recursive          recursive download.\n"
#~ "  -l,  --level=NUMBER       maximum recursion depth (inf or 0 for "
#~ "infinite).\n"
#~ "       --delete-after       delete files locally after downloading them.\n"
#~ "  -k,  --convert-links      convert non-relative links to relative.\n"
#~ "  -K,  --backup-converted   before converting file X, back up as X.orig.\n"
#~ "  -m,  --mirror             shortcut option equivalent to -r -N -l inf -"
#~ "nr.\n"
#~ "  -p,  --page-requisites    get all images, etc. needed to display HTML "
#~ "page.\n"
#~ "       --strict-comments    turn on strict (SGML) handling of HTML "
#~ "comments.\n"
#~ "\n"
#~ msgstr ""
#~ "Scaricamento ricorsivo:\n"
#~ "  -r,  --recursive            scaricamento ricorsivo.\n"
#~ "  -l,  --level=NUMERO         profondità massima di ricorsione\n"
#~ "                              (inf o 0 = illimitata).\n"
#~ "       --delete-after         cancella i file dopo averli scaricati.\n"
#~ "  -k,  --convert-links        converte i link assoluti in relativi.\n"
#~ "  -K,  --backup-converted     salva il file X come X.orig prima di "
#~ "convertirlo.\n"
#~ "  -m,  --mirror               opzione equivalente a -r -N -l inf -nr.\n"
#~ "  -p,  --page-requisites      scarica tutte le immagini, ecc, necessarie "
#~ "per\n"
#~ "                              visualizzare la pagina HTML.\n"
#~ "       --strict-comments      tratta i commenti HTML in modalità strict "
#~ "(SGML).\n"
#~ "\n"

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
#~ "Accetto/rifiuto ricorsivo:\n"
#~ "  -A,  --accept=LISTA                lista di estensioni accettate, "
#~ "separate da\n"
#~ "                                     virgole.\n"
#~ "  -R,  --reject=LISTA                lista di estensioni rifiutate, "
#~ "separate da\n"
#~ "                                     virgole.\n"
#~ "  -D,  --domains=LISTA               lista di domini accettati, separati "
#~ "da\n"
#~ "                                     virgole.\n"
#~ "       --exclude-domains=LISTA       lista di domini rifiutati, separati "
#~ "da \n"
#~ "                                     virgole.\n"
#~ "       --follow-ftp                  segue i link FTP dai documenti "
#~ "HTTP.\n"
#~ "       --follow-tags=LISTA           lista di tag HTML, separati da "
#~ "virgole,\n"
#~ "                                     che vengono seguiti nello "
#~ "scaricamento.\n"
#~ "  -G   --ignore-tags=LISTA           lista di tag HTML, separati da "
#~ "virgole,\n"
#~ "                                     che vengono ignorati.\n"
#~ "  -H,  --span-hosts                  visita anche ad altri host quando si "
#~ "è\n"
#~ "                                     in modalità ricorsiva.\n"
#~ "  -L,  --relative                    segue solo i link relativi.\n"
#~ "  -I,  --include-directories=LISTA   lista di directory permesse.\n"
#~ "  -X,  --exclude-directories=LISTA   lista di directory escluse.\n"
#~ "  -np, --no-parent                   non risale alla directory "
#~ "superiore.\n"
#~ "\n"

#~ msgid "%s: debug support not compiled in.\n"
#~ msgstr "%s: supporto per il debug non attivato in fase di compilazione.\n"

#~ msgid "Starting WinHelp %s\n"
#~ msgstr "Avvio di WinHelp %s\n"

#~ msgid "%s: %s: Not enough memory.\n"
#~ msgstr "%s: %s: memoria insufficiente.\n"
