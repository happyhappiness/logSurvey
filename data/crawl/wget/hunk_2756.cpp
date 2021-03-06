 "Posku�am ponovno.\n"
 "\n"
 
-#: src/url.c:626
+#: src/url.c:621
 msgid "No error"
 msgstr "Brez napake"
 
-#: src/url.c:628
+#: src/url.c:623
 msgid "Unsupported scheme"
 msgstr "Nepodprta shema"
 
-#: src/url.c:630
+#: src/url.c:625
 msgid "Empty host"
 msgstr "Prazen gostitelj"
 
-#: src/url.c:632
+#: src/url.c:627
 msgid "Bad port number"
 msgstr "Slaba stevilka vrat"
 
-#: src/url.c:634
+#: src/url.c:629
 msgid "Invalid user name"
 msgstr "Neveljavno uporabnisko ime"
 
-#: src/url.c:636
+#: src/url.c:631
 msgid "Unterminated IPv6 numeric address"
 msgstr "Neprekinjen �tevilski naslov IPv6"
 
-#: src/url.c:638
+#: src/url.c:633
 msgid "IPv6 addresses not supported"
 msgstr "Naslovi IPv6 niso podprti"
 
-#: src/url.c:640
+#: src/url.c:635
 msgid "Invalid IPv6 numeric address"
 msgstr "Neveljaven �tevilski naslov IPv6"
 
+#: src/utils.c:120
+#, c-format
+msgid "%s: %s: Not enough memory.\n"
+msgstr "%s: %s: Ni dovolj pomnilnika.\n"
+
 #. parent, no error
-#: src/utils.c:346
+#: src/utils.c:485
 #, c-format
 msgid "Continuing in background, pid %d.\n"
 msgstr "Nadaljujem v ozadju, pid %d.\n"
 
-#: src/utils.c:394
+#: src/utils.c:529
 #, c-format
 msgid "Failed to unlink symlink `%s': %s\n"
 msgstr "Ne morem odstraniti simbolne povezave `%s': %s\n"
-
-#: src/xmalloc.c:72
-#, c-format
-msgid "%s: %s: Failed to allocate %ld bytes; memory exhausted.\n"
-msgstr ""
-
-#~ msgid "Failed to set up an SSL context\n"
-#~ msgstr "Vzpostavljanje konteksta SSL ni uspelo.\n"
-
-#~ msgid "Failed to load certificates from %s\n"
-#~ msgstr "Ni bilo mo� nalo�iti certifikatov od %s\n"
-
-#~ msgid "Trying without the specified certificate\n"
-#~ msgstr "Posku�am brez dolo�enega certifikata\n"
-
-#~ msgid "Failed to get certificate key from %s\n"
-#~ msgstr "Ni bilo mo� dobiti certifikatskega klju�a od %s\n"
-
-#~ msgid "Unable to convert `%s' to a bind address.  Reverting to ANY.\n"
-#~ msgstr ""
-#~ "Ni mo� pretvoriti '%s' v naslov za povezavo. Vra�am na KATERIKOLI.\n"
-
-#~ msgid ""
-#~ "\n"
-#~ "REST failed; will not truncate `%s'.\n"
-#~ msgstr ""
-#~ "\n"
-#~ "REST neuspe�en; ne bom skraj�al ,%s`.\n"
-
-#~ msgid " [%s to go]"
-#~ msgstr " [�e %s]"
-
-#~ msgid "Host not found"
-#~ msgstr "Gostitelj ni bil najden"
-
-#~ msgid "End of file while parsing headers.\n"
-#~ msgstr "Pri raz�lenjevanju glave naletel na konec datoteke.\n"
-
-#~ msgid ""
-#~ "\n"
-#~ "Continued download failed on this file, which conflicts with `-c'.\n"
-#~ "Refusing to truncate existing file `%s'.\n"
-#~ "\n"
-#~ msgstr ""
-#~ "\n"
-#~ "Nadaljevani prenos za to datoteko ni uspel, kar se tepe z ,-c`.\n"
-#~ "No�em prepisati obstoje�e datoteke ,%s`.\n"
-#~ "\n"
-
-#~ msgid " (%s to go)"
-#~ msgstr " (�e %s)"
-
-#~ msgid ""
-#~ "Startup:\n"
-#~ "  -V,  --version           display the version of Wget and exit.\n"
-#~ "  -h,  --help              print this help.\n"
-#~ "  -b,  --background        go to background after startup.\n"
-#~ "  -e,  --execute=COMMAND   execute a `.wgetrc'-style command.\n"
-#~ "\n"
-#~ msgstr ""
-#~ "Zagon:\n"
-#~ "  -V,  --version           prika�i razli�ico Wgeta in se vrni.\n"
-#~ "  -h,  --help              izpi�i pomo�.\n"
-#~ "  -b,  --background        po zagonu pojdi v ozadje.\n"
-#~ "  -e,  --execute=UKAZ      izvedi ukaz v slogu `.wgetrc'.\n"
-#~ "\n"
-
-#~ msgid ""
-#~ "Logging and input file:\n"
-#~ "  -o,  --output-file=FILE     log messages to FILE.\n"
-#~ "  -a,  --append-output=FILE   append messages to FILE.\n"
-#~ "  -d,  --debug                print debug output.\n"
-#~ "  -q,  --quiet                quiet (no output).\n"
-#~ "  -v,  --verbose              be verbose (this is the default).\n"
-#~ "  -nv, --non-verbose          turn off verboseness, without being quiet.\n"
-#~ "  -i,  --input-file=FILE      download URLs found in FILE.\n"
-#~ "  -F,  --force-html           treat input file as HTML.\n"
-#~ "  -B,  --base=URL             prepends URL to relative links in -F -i "
-#~ "file.\n"
-#~ "\n"
-#~ msgstr ""
-#~ "Bele�enje in vhodna datoteka:\n"
-#~ "  -o,  --output-file=DATOTEKA    shranjuj sporo�ila v DATOTEKO.\n"
-#~ "  -a,  --append-output=DATOTEKA  dodajaj sporo�ila v DATOTEKO.\n"
-#~ "  -d,  --debug                   izpisuj razhro��evalni izhod.\n"
-#~ "  -q,  --quiet                   ti�ina (brez izpisa).\n"
-#~ "  -v,  --verbose                 vklju�i polni izpis (privzeto).\n"
-#~ "  -nv, --non-verbose             izklju�i ve�ino izpisa, a brez ti�ine.\n"
-#~ "  -i,  --input-file=DATOTEKA     poberi URL-je iz DATOTEKE.\n"
-#~ "  -F,  --force-html              privzemi, da je vhodna datoteka HTML.\n"
-#~ "  -B,  --base=URL                pripni URL pred relativne povezave v -F -"
-#~ "i\n"
-#~ "                                   datoteka.\n"
-#~ "\n"
-
-#~ msgid ""
-#~ "Download:\n"
-#~ "  -t,  --tries=NUMBER           set number of retries to NUMBER (0 "
-#~ "unlimits).\n"
-#~ "       --retry-connrefused      retry even if connection is refused.\n"
-#~ "  -O   --output-document=FILE   write documents to FILE.\n"
-#~ "  -nc, --no-clobber             don't clobber existing files or use .# "
-#~ "suffixes.\n"
-#~ "  -c,  --continue               resume getting a partially-downloaded "
-#~ "file.\n"
-#~ "       --progress=TYPE          select progress gauge type.\n"
-#~ "  -N,  --timestamping           don't re-retrieve files unless newer than "
-#~ "local.\n"
-#~ "  -S,  --server-response        print server response.\n"
-#~ "       --spider                 don't download anything.\n"
-#~ "  -T,  --timeout=SECONDS        set all timeout values to SECONDS.\n"
-#~ "       --dns-timeout=SECS       set the DNS lookup timeout to SECS.\n"
-#~ "       --connect-timeout=SECS   set the connect timeout to SECS.\n"
-#~ "       --read-timeout=SECS      set the read timeout to SECS.\n"
-#~ "  -w,  --wait=SECONDS           wait SECONDS between retrievals.\n"
-#~ "       --waitretry=SECONDS      wait 1...SECONDS between retries of a "
-#~ "retrieval.\n"
-#~ "       --random-wait            wait from 0...2*WAIT secs between "
-#~ "retrievals.\n"
-#~ "  -Y,  --proxy=on/off           turn proxy on or off.\n"
-#~ "  -Q,  --quota=NUMBER           set retrieval quota to NUMBER.\n"
-#~ "       --bind-address=ADDRESS   bind to ADDRESS (hostname or IP) on local "
-#~ "host.\n"
-#~ "       --limit-rate=RATE        limit download rate to RATE.\n"
-#~ "       --dns-cache=off          disable caching DNS lookups.\n"
-#~ "       --restrict-file-names=OS restrict chars in file names to ones OS "
-#~ "allows.\n"
-#~ "\n"
-#~ msgstr ""
-#~ "Jemanje:\n"
-#~ "  -t,  --tries=�TEVILO             nastavi �TEVILO poskusov (0 za "
-#~ "neskon�no).\n"
-#~ "       --retry-connrefused         znova poskusi, tudi �e je povezava "
-#~ "zavrnjena.\n"
-#~ "  -O   --output-document=DATOTEKA  zapisuj dokumente v DATOTEKO.\n"
-#~ "  -nc, --no-clobber                ne pi�i prek obstoje�ih datotek ali "
-#~ "pa\n"
-#~ "                                     uporabljal pripone .#.\n"
-#~ "  -c,  --continue                  nadaljuj z jemanjem obstoje�e "
-#~ "datoteke.\n"
-#~ "       --progress=VRSTA            dolo�i slog prikaza jemanja.\n"
-#~ "  -N,  --timestamping              ne jemlji datotek, starej�ih od "
-#~ "lokalnih.\n"
-#~ "  -S,  --server-response           izpisuj gostiteljev odziv.\n"
-#~ "       --spider                    ni�esar ne jemlji.\n"
-#~ "  -T,  --timeout=SEKUNDE           dolo�i vse zakasnitve na SEKUNDE.\n"
-#~ "       --dns-timeout=SEKUNDE       dolo�i zakasnitev poizvedbe DNS na "
-#~ "SEKUNDE.\n"
-#~ "       --connect-timeout=SECS      dolo�i povezovalno zakasnitev na "
-#~ "SEKUNDE.\n"
-#~ "       --read-timeout=SECS         dolo�i bralno zakasnitev na SEKUNDE.\n"
-#~ "  -w,  --wait=SEKUNDE              po�akaj toliko SEKUND med jemanji.\n"
-#~ "       --waitretry=SEKUNDE         po�akaj 1..SEKUNDE med ponovnimi "
-#~ "poskusi \n"
-#~ "                                     jemanja.\n"
-#~ "       --random-wait               po�akaj od 0...2*WAIT sek. med "
-#~ "jemanji.\n"
-#~ "  -Y,  --proxy=on/off              vklju�i ali izklju�i zastopnika "
-#~ "(proxy).\n"
-#~ "  -Q,  --quota=�TEVILO             dolo�i omejitev jemanja na �TEVILO.\n"
-#~ "       --bind-address=NASLOV       pove�i se z NASLOVOM (ime ali IP) na \n"
-#~ "                                     lokalnem ra�unalniku.\n"
-#~ "       --limit-rate=HITROST        omeji hitrost jemanja na HITROST.\n"
-#~ "       --dns-cache=off             onemogo�i predpomnjenje poizvedb DNS.\n"
-#~ "       --restrict-file-names=OS    omeji znake v imenih datotek na tiste, "
-#~ "ki\n"
-#~ "                                     so dovoljeni v OS.\n"
-#~ "\n"
-
-#~ msgid ""
-#~ "Directories:\n"
-#~ "  -nd, --no-directories            don't create directories.\n"
-#~ "  -x,  --force-directories         force creation of directories.\n"
-#~ "  -nH, --no-host-directories       don't create host directories.\n"
-#~ "  -P,  --directory-prefix=PREFIX   save files to PREFIX/...\n"
-#~ "       --cut-dirs=NUMBER           ignore NUMBER remote directory "
-#~ "components.\n"
-#~ "\n"
-#~ msgstr ""
-#~ "Imeniki:\n"
-#~ "  -nd  --no-directories             ne ustvarjaj imenikov.\n"
-#~ "  -x,  --force-directories          vedno ustvarjaj imenike.\n"
-#~ "  -nH, --no-host-directories        ne ustvarjaj imenikov po "
-#~ "gostiteljih.\n"
-#~ "  -P,  --directory-prefix=PREDPONA  shranjuj datoteke v PREDPONA/...\n"
-#~ "       --cut-dirs=�TEVILO           ignoriraj �TEVILO oddaljenih "
-#~ "imenikov.\n"
-#~ "\n"
-
-#~ msgid ""
-#~ "HTTP options:\n"
-#~ "       --http-user=USER      set http user to USER.\n"
-#~ "       --http-passwd=PASS    set http password to PASS.\n"
-#~ "  -C,  --cache=on/off        (dis)allow server-cached data (normally "
-#~ "allowed).\n"
-#~ "  -E,  --html-extension      save all text/html documents with .html "
-#~ "extension.\n"
-#~ "       --ignore-length       ignore `Content-Length' header field.\n"
-#~ "       --header=STRING       insert STRING among the headers.\n"
-#~ "       --proxy-user=USER     set USER as proxy username.\n"
-#~ "       --proxy-passwd=PASS   set PASS as proxy password.\n"
-#~ "       --referer=URL         include `Referer: URL' header in HTTP "
-#~ "request.\n"
-#~ "  -s,  --save-headers        save the HTTP headers to file.\n"
-#~ "  -U,  --user-agent=AGENT    identify as AGENT instead of Wget/VERSION.\n"
-#~ "       --no-http-keep-alive  disable HTTP keep-alive (persistent "
-#~ "connections).\n"
-#~ "       --cookies=off         don't use cookies.\n"
-#~ "       --load-cookies=FILE   load cookies from FILE before session.\n"
-#~ "       --save-cookies=FILE   save cookies to FILE after session.\n"
-#~ "       --post-data=STRING    use the POST method; send STRING as the "
-#~ "data.\n"
-#~ "       --post-file=FILE      use the POST method; send contents of FILE.\n"
-#~ "\n"
-#~ msgstr ""
-#~ "Izbire za HTTP:\n"
-#~ "       --http-user=UPORABNIK   dolo�i uporabnika HTTP na UPORABNIK.\n"
-#~ "       --http-passwd=GESLO     dolo�i geslo za HTTP kot GESLO.\n"
-#~ "  -C,  --cache=on/off          dovolitev predpomnenja (navadno "
-#~ "dovoljeno).\n"
-#~ "  -E,  --html-extension        vse nadbesedilne spise shranjuj s pripono ."
-#~ "html.\n"
-#~ "       --ignore-length         ignoriraj glavo `Content-Length'.\n"
-#~ "       --header=NIZ            vstavi NIZ v glavo.\n"
-#~ "       --proxy-user=UPORABNIK  dolo�i UPORABNIKA kot uporabnika proxy-"
-#~ "ja.\n"
-#~ "       --proxy-passwd=GESLO    dolo�i geslo za proxy GESLO.\n"
-#~ "       --referer=URL           vklju�i ,Referer: URL` v zahtevek HTTP.\n"
-#~ "  -s,  --save-headers          shranjuj glave HTTP v datoteko.\n"
-#~ "  -U,  --user-agent=ODJEMNIK   predstavi se kot ODJEMNIK namesto Wget/"
-#~ "RAZLI�ICA.\n"
-#~ "       --no-http-keep-alive    onemogo�i stalne povezave HTTP.\n"
-#~ "       --cookies=off           ne uporabljaj pi�kotov.\n"
-#~ "       --load-cookies=DATOT.   pred sejo nalo�i pi�kote iz DATOTEKE.\n"
-#~ "       --save-cookies=DATOT.   po seji shrani pi�kote v DATOTEKO.\n"
-#~ "       --post-data=NIZ         uporabi metodo POST; po�lji NIZ kot "
-#~ "podatke.\n"
-#~ "       --post-file=DATOTEKA    uporabi metodo POST; po�lji vsebino "
-#~ "DATOTEKE.\n"
-#~ "\n"
-
-#~ msgid ""
-#~ "HTTPS (SSL) options:\n"
-#~ "       --sslcertfile=FILE     optional client certificate.\n"
-#~ "       --sslcertkey=KEYFILE   optional keyfile for this certificate.\n"
-#~ "       --egd-file=FILE        file name of the EGD socket.\n"
-#~ "       --sslcadir=DIR         dir where hash list of CA's are stored.\n"
-#~ "       --sslcafile=FILE       file with bundle of CA's\n"
-#~ "       --sslcerttype=0/1      Client-Cert type 0=PEM (default) / 1=ASN1 "
-#~ "(DER)\n"
-#~ "       --sslcheckcert=0/1     Check the server cert agenst given CA\n"
-#~ "       --sslprotocol=0-3      choose SSL protocol; 0=automatic,\n"
-#~ "                              1=SSLv2 2=SSLv3 3=TLSv1\n"
-#~ "\n"
-#~ msgstr ""
-#~ " Izbire za HTTPS (SSL):\n"
-#~ "       --sslcertfile=DATOTEKA    morebitni certifikat odjemnika.\n"
-#~ "       --sslcertkey=KLJU�I       morebitna datoteka s klju�i za ta "
-#~ "certifikat.\n"
-#~ "       --egd-file=DATOTEKA       ime datoteke vti�a EGD.\n"
-#~ "       --sslcadir=IMENIK         imenik s presko�nim seznamom CA.\n"
-#~ "       --sslcafile=DATOTEKA      datoteka z ve� CA-ji\n"
-#~ "       --sslcerttype=0/1         vrsta odjemnika Cert 0=PEM (privzeto)\n"
-#~ "                                                    / 1=ASN1 (DER)\n"
-#~ "       --sslcheckcert=0/1        preveri stre�nik cert za dano CA\n"
-#~ "       --sslprotocol=0-3         izberi protokol SSL; 0=samodejno,\n"
-#~ "                                   1=SSLv2 2=SSLv3 3=TLSv1\n"
-#~ "\n"
-
-#~ msgid ""
-#~ "FTP options:\n"
-#~ "  -nr, --dont-remove-listing   don't remove `.listing' files.\n"
-#~ "  -g,  --glob=on/off           turn file name globbing on or off.\n"
-#~ "       --passive-ftp           use the \"passive\" transfer mode.\n"
-#~ "       --retr-symlinks         when recursing, get linked-to files (not "
-#~ "dirs).\n"
-#~ "\n"
-#~ msgstr ""
-#~ "Izbire za FTP:\n"
-#~ "  -nr, --dont-remove-listing   ne odstranjuj datotek ,.listing`.\n"
-#~ "  -g,  --glob=on/off           vklju�i ali izklju�i `globbing' imen "
-#~ "datotek.\n"
-#~ "       --passive-ftp           uporabljaj \"pasivni\" na�in prenosa.\n"
-#~ "       --retr-symlinks         pri rekurzivnem jemanju jemlji cilje, ne "
-#~ "pa samih\n"
-#~ "                                 simbolnih povezav (ne velja za "
-#~ "imenike).\n"
-#~ "\n"
-
-#~ msgid ""
-#~ "Recursive retrieval:\n"
-#~ "  -r,  --recursive          recursive download.\n"
-#~ "  -l,  --level=NUMBER       maximum recursion depth (inf or 0 for "
-#~ "infinite).\n"
-#~ "       --delete-after       delete files locally after downloading them.\n"
-#~ "  -k,  --convert-links      convert non-relative links to relative.\n"
-#~ "  -K,  --backup-converted   before converting file X, back up as X.orig.\n"
-#~ "  -m,  --mirror             shortcut option equivalent to -r -N -l inf -"
-#~ "nr.\n"
-#~ "  -p,  --page-requisites    get all images, etc. needed to display HTML "
-#~ "page.\n"
-#~ "       --strict-comments    turn on strict (SGML) handling of HTML "
-#~ "comments.\n"
-#~ "\n"
-#~ msgstr ""
-#~ "Rekurzivno jemanje:\n"
-#~ "  -r,  --recursive            rekurzivno jemanje.\n"
-#~ "  -l,  --level=NUMBER         najve�ja dovoljena globina rekurzije (inf "
-#~ "ali 0\n"
-#~ "                                za neskon�no).\n"
-#~ "       --delete-after         bri�i krajevne datoteke, ko jih pobere�.\n"
-#~ "  -k,  --convert-links        pretvori absolutne povezave v relativne.\n"
-#~ "  -K,  --backup-converted     pred pretvorbo datoteke X shrani izvorno \n"
-#~ "                                datoteko kot X.orig.\n"
-#~ "  -m,  --mirror               bli�njica, ekvivalentna -r -N -l inf -nr.\n"
-#~ "  -p,  --page-requisites      vzemi vse slike itd., potrebne za prikaz "
-#~ "spletne\n"
-#~ "                                strani HTML.\n"
-#~ "       --strict-comments      vklju�i striktno rokovanje SGML s "
-#~ "komentarji HTML.\n"
-#~ "\n"
-
-#~ msgid ""
-#~ "Recursive accept/reject:\n"
-#~ "  -A,  --accept=LIST                comma-separated list of accepted "
-#~ "extensions.\n"
-#~ "  -R,  --reject=LIST                comma-separated list of rejected "
-#~ "extensions.\n"
-#~ "  -D,  --domains=LIST               comma-separated list of accepted "
-#~ "domains.\n"
-#~ "       --exclude-domains=LIST       comma-separated list of rejected "
-#~ "domains.\n"
-#~ "       --follow-ftp                 follow FTP links from HTML "
-#~ "documents.\n"
-#~ "       --follow-tags=LIST           comma-separated list of followed HTML "
-#~ "tags.\n"
-#~ "  -G,  --ignore-tags=LIST           comma-separated list of ignored HTML "
-#~ "tags.\n"
-#~ "  -H,  --span-hosts                 go to foreign hosts when recursive.\n"
-#~ "  -L,  --relative                   follow relative links only.\n"
-#~ "  -I,  --include-directories=LIST   list of allowed directories.\n"
-#~ "  -X,  --exclude-directories=LIST   list of excluded directories.\n"
-#~ "  -np, --no-parent                  don't ascend to the parent "
-#~ "directory.\n"
-#~ "\n"
-#~ msgstr ""
-#~ "Rekurzivno sprejemanje/zavra�anje:\n"
-#~ "  -A,  --accept=SEZNAM               seznam sprejemljivih pripon.\n"
-#~ "  -R,  --reject=SEZNAM               seznam zavrnljivih pripon.\n"
-#~ "  -D,  --domains=SEZNAM              seznam sprejemljivih domen.\n"
-#~ "       --exclude-domains=SEZNAM      seznam (z vejicami) zavrnljivih "
-#~ "domen.\n"
-#~ "       --follow-ftp                  sledi povezavam FTP iz spisov HTML.\n"
-#~ "       --follow-tags=SEZNAM          seznam sledenim zna�kam HTML.\n"
-#~ "  -G,  --ignore-tags=SEZNAM          seznam ignoriranih zna�k HTML.\n"
-#~ "  -H,  --span-hosts                  pri rekurzivneh shranjevanju pojdi "
-#~ "tudi\n"
-#~ "                                       na druge ra�unalnike.\n"
-#~ "  -L,  --relative                    spremljaj samo relativne povezave.\n"
-#~ "  -I,  --include-directories=SEZNAM  seznam dovoljenih imenikov.\n"
-#~ "  -X,  --exclude-directories=SEZNAM  seznam nedovoljenih imenikov.\n"
-#~ "  -np, --no-parent                   ne pojdi v star�evski imenik.\n"
-#~ "\n"
-
-#~ msgid "%s: debug support not compiled in.\n"
-#~ msgstr "%s: podpora za razhro��evanje ni vgrajena.\n"
-
-#~ msgid "Starting WinHelp %s\n"
-#~ msgstr "Zaganjam WinHelp %s\n"
-
-#~ msgid "%s: %s: Not enough memory.\n"
-#~ msgstr "%s: %s: Ni dovolj pomnilnika.\n"
