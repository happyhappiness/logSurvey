"Berriz saiatzen.\n"
"\n"

#: src/url.c:626
msgid "No error"
msgstr "Errorerik ez"

#: src/url.c:628
msgid "Unsupported scheme"
msgstr "Sostengu gabeko eskema"

#: src/url.c:630
msgid "Empty host"
msgstr "Ostalaria hutsa"

#: src/url.c:632
msgid "Bad port number"
msgstr "Portu zenbaki akastuna"

#: src/url.c:634
msgid "Invalid user name"
msgstr "Baliogabeko erabiltzaile izena"

#: src/url.c:636
msgid "Unterminated IPv6 numeric address"
msgstr "IPv6 zenbaki helbide amaitugabea"

#: src/url.c:638
msgid "IPv6 addresses not supported"
msgstr "IPV6 motako helbideak ez daude erabilgarri"

#: src/url.c:640
msgid "Invalid IPv6 numeric address"
msgstr "Baliogabeko IPv6 zenbaki helbidea"

#. parent, no error
#: src/utils.c:346
#, c-format
msgid "Continuing in background, pid %d.\n"
msgstr "Atzeko planoan jarraitzen, pid %d.\n"

#: src/utils.c:394
#, c-format
msgid "Failed to unlink symlink `%s': %s\n"
msgstr "Huts egin da `%s' link sinbolikoa askatzerakoan: %s\n"

#: src/xmalloc.c:72
#, c-format
msgid "%s: %s: Failed to allocate %ld bytes; memory exhausted.\n"
msgstr ""

#~ msgid "Failed to set up an SSL context\n"
#~ msgstr "Huts egin da SSL kontextua eratzen\n"

#~ msgid "Failed to load certificates from %s\n"
#~ msgstr "%s-tik zertifikazioak kargatzerakoan huts egin da\n"

#~ msgid "Trying without the specified certificate\n"
#~ msgstr "Zehaztutako zertifikaziorik gabe saiatzen\n"

#~ msgid "Failed to get certificate key from %s\n"
#~ msgstr "Huts egin da zertifikazio gakoa hartzerakoan %s-tik\n"

#~ msgid "Unable to convert `%s' to a bind address.  Reverting to ANY.\n"
#~ msgstr ""
#~ "Ezin da `%s' lotura helbide batetara bihurtu.  BESTE batera bihurtzen.\n"

#~ msgid ""
#~ "\n"
#~ "REST failed; will not truncate `%s'.\n"
#~ msgstr ""
#~ "\n"
#~ "REST komanduak huts egin du, ez da`%s' moztuko.\n"

#~ msgid " [%s to go]"
#~ msgstr " [%s amaitzeko]"

#~ msgid "Host not found"
#~ msgstr "Host-a ez da aurkitu"

#~ msgid "End of file while parsing headers.\n"
#~ msgstr "Fitxategiaren amaiera goi-buruak parseatzen ziren bitartean.\n"

#~ msgid ""
#~ "\n"
#~ "Continued download failed on this file, which conflicts with `-c'.\n"
#~ "Refusing to truncate existing file `%s'.\n"
#~ "\n"
#~ msgstr ""
#~ "\n"
#~ "Deskargaren jarrapienak huts egin du fitxategi hontan, eta `-c'-rekin "
#~ "gatazka sortzen du.\n"
#~ "Existitzen den `%s' fitxategia moztea ukatzen da.\n"

#~ msgid " (%s to go)"
#~ msgstr " (%s amaitzeko)"

#~ msgid ""
#~ "Startup:\n"
#~ "  -V,  --version           display the version of Wget and exit.\n"
#~ "  -h,  --help              print this help.\n"
#~ "  -b,  --background        go to background after startup.\n"
#~ "  -e,  --execute=COMMAND   execute a `.wgetrc'-style command.\n"
#~ "\n"
#~ msgstr ""
#~ "Hasteko:\n"
#~ "  -V,  --version           Wget-en bertsioa erakutsi eta irten.\n"
#~ "  -h,  --help              laguntza hau erakutsi.\n"
#~ "  -b,  --background        asterakoan atzealdean ipini.\n"
#~ "  -e,  --execute=KOMANDUA   `.wgetrc'-motako komandua ejekutatzen du.\n"
#~ "\n"

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
#~ "Logeatze eta irteera fitxategia:\n"
#~ "  -o,  --output-file=FITXATEGIA     log mezuak FITXATEGIAN idatzi.\n"
#~ "  -a,  --append-output=FITXATEGIA   erantsi mezuak FITXATEGIARI.\n"
#~ "  -d,  --debug                erakutsi debug-aren irteera.\n"
#~ "  -q,  --quiet                ixilik (irteerarik gabe).\n"
#~ "  -v,  --verbose              irteera luzea (lehenetsia).\n"
#~ "  -nv, --non-verbose          irteera luzerik gabe, baina ixilik egon "
#~ "gabe.\n"
#~ "  -i,  --input-file=FITXATEGIA      emandako FITXATEGIAN dauden URLak "
#~ "jaitsi.\n"
#~ "  -F,  --force-html           sarrera fitxategia HTML bezala tratatu.\n"
#~ "  -B,  --base=URL             URLa geitu hasieran -F -i fitxategien link "
#~ "erlatiboetan.\n"
#~ "\n"

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
#~ "Jaitsi:\n"
#~ "  -t,  --tries=ZENBAKIA           jaisteko egingo diren saiakera kopurua "
#~ "(0 limiterik gabe).\n"
#~ "       --retry-connrefused      konexioa ukatzen bada ere berriz saiatu.\n"
#~ "  -O   --output-document=FITXATEGIA   idatzi dokumentuak FITXATEGIAN.\n"
#~ "  -nc, --no-clobber             ez jaitsi dagoeneko exisitzen bada edo "
#~ "erabili .# luzapen bezala.\n"
#~ "  -c,  --continue               jarraitu jaisten partzialki jatsirik "
#~ "dagoen fitxategia.\n"
#~ "       --progress=MOTA          progresu mota aukeratu.\n"
#~ "  -N,  --timestamping           ez jaitsi fitxategiak bertakoak baina "
#~ "berriagoak ez badira.\n"
#~ "  -S,  --server-response        erakutsi zerbitzariaren erantzuna.\n"
#~ "       --spider                 ez jaitsi ezer.\n"
#~ "  -T,  --timeout=SEGUNDUAK        ezarri denboraz kanpo balio guztiak "
#~ "emandako SEGUNDUTAN.\n"
#~ "       --dns-timeout=SEGUNDUAK       ezarri DNS ikustatze limitea "
#~ "emandako SEGUNDUTAN.\n"
#~ "       --connect-timeout=SEGUNDUAK   ezarri konexioa denboraz kanpo "
#~ "egotea emandako SEGUNDUTAN.\n"
#~ "       --read-timeout=SEGUNDUAK      ezarri irakurtzea denboraz kanpo "
#~ "egotea emandako SEGUNDUTAN.\n"
#~ "  -w,  --wait=SEGUNDUAK           itxaron emandako SEGUNDUAK jaitsieren "
#~ "artean.\n"
#~ "       --waitretry=SEGUNDUAK      itxaron emandako SEGUNDUAK huts "
#~ "egindako jaitsiera bat jarraitzeko.\n"
#~ "       --random-wait            itxaron 0 tik 2*ra saiatzeen artean.\n"
#~ "  -Y,  --proxy=on/off           gaitu ala ez gaitu proxya.\n"
#~ "  -Q,  --quota=ZENBAKIA           ezarri saiatze kuota ZENBAKIRA.\n"
#~ "       --bind-address=HELBIDEA  itsutu HELBIEARA (host izena edo IPa) "
#~ "host lokalean.\n"
#~ "       --limit-rate=TASA        ezarri jaitsiera limitea TASARA.\n"
#~ "       --dns-cache=off          ezgaitu katxeaturiko DNSak ikustatzea.\n"
#~ "       --restrict-file-names=SE SE (Sistema Eragile)ak onartzen dituen "
#~ "karaktereak soilik erabili.\n"
#~ "\n"

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
#~ "Direktorioak:\n"
#~ "  -nd, --no-directories            ez sortu direkoriorik.\n"
#~ "  -x,  --force-directories         behartu direktorioak sortzera.\n"
#~ "  -nH, --no-host-directories       ez sortu host direktoriorik.\n"
#~ "  -P,  --directory-prefix=AURREZKI   gorde fitxategiak AURREZKI/-an...\n"
#~ "       --cut-dirs=KOPURUA           ez egin jaramonik urruneko direktorio "
#~ "KOPURUAri.\n"
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
#~ "HTTP aukerak:\n"
#~ "       --http-user=ERABILTZAILEA      ezarri http erabiltzaile bezala "
#~ "ERABILTZAILEA.\n"
#~ "       --http-passwd=PASAHITZA    ezarri http pasahitz bezala PASAHITZA.\n"
#~ "  -C,  --cache=on/off        zerbitzari katxea gaitu ala ezgaitu "
#~ "(normalean onartua).\n"
#~ "  -E,  --html-extension      gorde text/html dokumentuak .html "
#~ "luzapenarekin.\n"
#~ "       --ignore-length       ignoratu `Content-Length' goiburua.\n"
#~ "       --header=KATEA       gehitu KATEA goiburua beste goiburuekin.\n"
#~ "       --proxy-user=ERABILTZAILEA     ezarri proxy erabiltzaile bezela "
#~ "ERABILTZAILEA.\n"
#~ "       --proxy-passwd=PASAHITZA   ezarri proxy pasahitz bezela "
#~ "PASAHITZA.\n"
#~ "       --referer=URL         sartu `Referer: URL' goiburua HTTP "
#~ "eskaeran.\n"
#~ "  -s,  --save-headers        gorde HTTP goiburuak fitxategi batean.\n"
#~ "  -U,  --user-agent=AGENTEA    identifikatu AGENTE bezala Wget/BERTSIOA-"
#~ "ren ordez.\n"
#~ "       --no-http-keep-alive  ezgaitu HTTP keep alive (konexio "
#~ "iraunkorrak).\n"
#~ "       --cookies=off         ez erabili cookieak.\n"
#~ "       --load-cookies=FITXATEGIA   kargatu cookieak FITXATEGITIK saioa "
#~ "hasi aurretik.\n"
#~ "       --save-cookies=FITXATEGIA   gorde cookieak FITXATEGIAN saioa "
#~ "amaitzean.\n"
#~ "       --post-data=KATEA    erabili POST metodoa; bidali KATEA datu "
#~ "bezala.\n"
#~ "       --post-file=FITXATEGIA      erabili POST metodoa; bidali "
#~ "FITXATEGIAREN edukia datu bezala.\n"
#~ "\n"

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
#~ "HTTPS (SSL) aukerak:\n"
#~ "       --sslcertfile=FITXATEGIA     aukerazko bezero zertifikatua.\n"
#~ "       --sslcertkey=GILTZA-FITXATEGIA   zertifikatu honentzat aukerazko "
#~ "giltza-fitxategia.\n"
#~ "       --egd-file=FITXATEGIA        EGD socket-aren fitxategi izena.\n"
#~ "       --sslcadir=DIR         CA hash zerrendak gordetzen diren "
#~ "direktorioa.\n"
#~ "       --sslcafile=FITXATEGIA       CA zertifikatudun fitxategiak\n"
#~ "       --sslcerttype=0/1      Bezeroaren zertifikazio mota 0=PEM "
#~ "(lehenetsia) / 1=ASN1 (DER)\n"
#~ "       --sslcheckcert=0/1     Egiaztatu zerbitzariaren zertifikatua "
#~ "emandako CArekin\n"
#~ "       --sslprotocol=0-3      aukeratu SSL protokoloa; 0=automatikoa,\n"
#~ "                              1=SSLv2 2=SSLv3 3=TLSv1\n"
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
#~ "FTP aukerak:\n"
#~ "  -nr, --dont-remove-listing   ez ezabatu `.listing' fitxategiak.\n"
#~ "  -g,  --glob=on/off           fitxategi izen komodinak gaitu ala ez.\n"
#~ "       --passive-ftp           transferentzia modu \"pasiboa\" erabili.\n"
#~ "       --retr-symlinks         errekurtsibitatean, linkaturiko "
#~ "fitxategiak hartu (direktorioak ez).\n"
#~ "\n"

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
#~ "Eskuratze errekurtsiboa:\n"
#~ "  -r,  --recursive          jaitsiera errekurtsiboa.\n"
#~ "  -l,  --level=ZENBAKIA       errekurtsibitate sakonera maximoa(inf edo 0 "
#~ "infiturentzat).\n"
#~ "       --delete-after       ezabatu fitxategiak lokalki jaitsi ondoren.\n"
#~ "  -k,  --convert-links      link erlatiboak ez erlatiboetan bihurtu.\n"
#~ "  -K,  --backup-converted   X fitxategia bihurtu aurretik segurtasun "
#~ "kopia egin X.orig bezala.\n"
#~ "  -m,  --mirror             laster-bide bat -r -N -l inf -nr egiteko.\n"
#~ "  -p,  --page-requisites    irudiak eta besteak hartu, HTML orriak "
#~ "erakusteko beharrezkoak.\n"
#~ "       --strict-comments    HTML komentarioak SGML bidez maneiatu.\n"
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
#~ "Errekurtsibitatean onartu/ezetsi:\n"
#~ "  -A,  --accept=ZERRENDA                onartutako luzapenen zerrenda "
#~ "komaz bereiztua.\n"
#~ "  -R,  --reject=ZERRENDA                ezetsitako luzapen zerrenda komaz "
#~ "bereiztua.\n"
#~ "  -D,  --domains=ZERRENDA               onartutako dominioen zerrenda "
#~ "komaz bereiztua.\n"
#~ "       --exclude-domains=ZERRENDA       ezetsitako dominio zerrenda komaz "
#~ "bereiztua.\n"
#~ "       --follow-ftp                 jarraitu FTP linkak HTML dokumentu "
#~ "batean.\n"
#~ "       --follow-tags=ZERRENDA           jarraituko diren HTML tag "
#~ "zerrenda komaz bereiztua.\n"
#~ "  -G,  --ignore-tags=ZERRENDA           ignoratuak izango diren HTML tag "
#~ "zerrenda komaz bereiztua.\n"
#~ "  -H,  --span-hosts                 joan kanpo-hostalarietara "
#~ "errekurtsibitatean.\n"
#~ "  -L,  --relative                   jarraitu link erlatiboak soilik.\n"
#~ "  -I,  --include-directories=ZERRENDA   onartutako direktorio zerrenda.\n"
#~ "  -X,  --exclude-directories=ZERRENDA   egotzitako direktorio zerrenda.\n"
#~ "  -np, --no-parent                  ez igo direktorio gurasora.\n"
#~ "\n"

#~ msgid "%s: debug support not compiled in.\n"
#~ msgstr "%s: ez dago debug euskarriarekin konpilatua.\n"

#~ msgid "Starting WinHelp %s\n"
#~ msgstr "WinHelp %s hasten\n"

#~ msgid "%s: %s: Not enough memory.\n"
#~ msgstr "%s: %s: Behar adina memoriarik gabe.\n"