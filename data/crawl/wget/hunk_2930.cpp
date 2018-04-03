 #. Align the [ skipping ... ] line with the dots.  To do
 #. that, insert the number of spaces equal to the number of
 #. digits in the skipped amount in K.
-#: src/progress.c:224
+#: src/progress.c:243
 #, c-format
-msgid "\n%*s[ skipping %dK ]"
-msgstr "\n%*s[ hopper over %dK ]"
+msgid ""
+"\n"
+"%*s[ skipping %dK ]"
+msgstr ""
+"\n"
+"%*s[ hopper over %dK ]"
 
-#: src/progress.c:391
+#: src/progress.c:410
 #, c-format
 msgid "Invalid dot style specification `%s'; leaving unchanged.\n"
 msgstr "Ugyldig punkt-stils specifikation '%s'; forbliver uændret.\n"
 
-#: src/recur.c:350
+#: src/recur.c:377
 #, c-format
 msgid "Removing %s since it should be rejected.\n"
 msgstr "Fjerner %s fordi den skal forkastes.\n"
 
-#: src/recur.c:935
-#, c-format
-msgid "Converted %d files in %.2f seconds.\n"
-msgstr "Konverterede %d filer på %.2f sekunder.\n"
-
-#: src/res.c:540
+#: src/res.c:548
 msgid "Loading robots.txt; please ignore errors.\n"
 msgstr "Henter robots.txt; ignorer eventuelle fejlmeldinger.\n"
 
-#: src/retr.c:363
-msgid "Could not find proxy host.\n"
-msgstr "Fandt ikke proxy-server.\n"
-
-#: src/retr.c:375
+#: src/retr.c:638
 #, c-format
 msgid "Error parsing proxy URL %s: %s.\n"
 msgstr "Fejl ved fortolkning af proxy-URL %s: %s.\n"
 
-#: src/retr.c:384
+#: src/retr.c:646
 #, c-format
 msgid "Error in proxy URL %s: Must be HTTP.\n"
 msgstr "Fejl i proxy URL %s: Skal være HTTP.\n"
 
-#: src/retr.c:476
+#: src/retr.c:731
 #, c-format
 msgid "%d redirections exceeded.\n"
 msgstr "%d: Omdirigeringer overskredet.\n"
 
-#: src/retr.c:491
-#, c-format
-msgid "%s: Redirection cycle detected.\n"
-msgstr "%s: Omdirigering løber i ring.\n"
+#: src/retr.c:856
+msgid ""
+"Giving up.\n"
+"\n"
+msgstr ""
+"Giver op.\n"
+"\n"
 
-#: src/retr.c:608
-msgid "Giving up.\n\n"
-msgstr "Giver op.\n\n"
+#: src/retr.c:856
+msgid ""
+"Retrying.\n"
+"\n"
+msgstr ""
+"Prøver igen.\n"
+"\n"
 
-#: src/retr.c:608
-msgid "Retrying.\n\n"
-msgstr "Prøver igen.\n\n"
+#: src/url.c:642
+#, fuzzy
+msgid "No error"
+msgstr "Ukendt fejl"
 
-#: src/url.c:1875
-#, c-format
-msgid "Converting %s... "
-msgstr "Konverterer %s... "
+#: src/url.c:644
+msgid "Unsupported scheme"
+msgstr ""
 
-#: src/url.c:1888
-msgid "nothing to do.\n"
-msgstr "ingenting at gøre.\n"
+#: src/url.c:646
+msgid "Empty host"
+msgstr ""
 
-#: src/url.c:1896 src/url.c:1920
-#, c-format
-msgid "Cannot convert links in %s: %s\n"
-msgstr "Kan ikke konvertere lænker i %s: %s\n"
+#: src/url.c:648
+msgid "Bad port number"
+msgstr ""
 
-#: src/url.c:1911
-#, c-format
-msgid "Unable to delete `%s': %s\n"
-msgstr "Kan ikke slette '%s': %s\n"
+#: src/url.c:650
+#, fuzzy
+msgid "Invalid user name"
+msgstr "Værtsnavnet er ugyldigt"
 
-#: src/url.c:2117
-#, c-format
-msgid "Cannot back up %s as %s: %s\n"
-msgstr "Kan ikke sikkerhedskopiere %s som %s: %s\n"
+#: src/url.c:652
+msgid "Unterminated IPv6 numeric address"
+msgstr ""
 
-#: src/utils.c:90
-#, c-format
-msgid "%s: %s: Not enough memory.\n"
-msgstr "%s: %s: Ikke nok hukommelse.\n"
+#: src/url.c:654
+msgid "IPv6 addresses not supported"
+msgstr ""
+
+#: src/url.c:656
+msgid "Invalid IPv6 numeric address"
+msgstr ""
 
 #. parent, no error
-#: src/utils.c:455
+#: src/utils.c:347
 #, c-format
 msgid "Continuing in background, pid %d.\n"
 msgstr "Fortsætter i baggrunden, pid %d.\n"
 
-#: src/utils.c:499
+#: src/utils.c:391
 #, c-format
 msgid "Failed to unlink symlink `%s': %s\n"
 msgstr "Kan ikke slette den symbolske lænke '%s': %s\n"
 
+#: src/xmalloc.c:72
+#, c-format
+msgid "%s: %s: Failed to allocate %ld bytes; memory exhausted.\n"
+msgstr ""
+
+#~ msgid "Syntax error in Set-Cookie at character `%c'.\n"
+#~ msgstr "Syntaksfejl i Set-Cookie ved tegnet '%c'.\n"
+
+#~ msgid ""
+#~ "\n"
+#~ "REST failed; will not truncate `%s'.\n"
+#~ msgstr ""
+#~ "\n"
+#~ "REST mislykkedes; vil ikke afkorte '%s'.\n"
+
+#~ msgid " [%s to go]"
+#~ msgstr " [%s tilbage]"
+
+#~ msgid "Host not found"
+#~ msgstr "Vært ikke fundet"
+
+#~ msgid "End of file while parsing headers.\n"
+#~ msgstr "Filafslutning fundet ved læsning af toptekster.\n"
+
+#~ msgid ""
+#~ "\n"
+#~ "Continued download failed on this file, which conflicts with `-c'.\n"
+#~ "Refusing to truncate existing file `%s'.\n"
+#~ "\n"
+#~ msgstr ""
+#~ "\n"
+#~ "Fortsat hentning mislykkedes for denne fil, hvilket er i modsætning til '-"
+#~ "c'.\n"
+#~ "Nægter at afkorte eksisterende fil '%s'.\n"
+#~ "\n"
+
+#~ msgid " (%s to go)"
+#~ msgstr " (%s tilbage)"
+
+#~ msgid "%s: BUG: unknown command `%s', value `%s'.\n"
+#~ msgstr "%s: FEJL: Ukendt kommando '%s', værdi '%s'.\n"
+
+#~ msgid "%s: %s: Cannot convert `%s' to an IP address.\n"
+#~ msgstr "%s: %s: Kan ikke omforme '%s' til en IP-adresse.\n"
+
+#~ msgid ""
+#~ "Startup:\n"
+#~ "  -V,  --version           display the version of Wget and exit.\n"
+#~ "  -h,  --help              print this help.\n"
+#~ "  -b,  --background        go to background after startup.\n"
+#~ "  -e,  --execute=COMMAND   execute a `.wgetrc'-style command.\n"
+#~ "\n"
+#~ msgstr ""
+#~ "Opstart:\n"
+#~ "  -V,  --version           vis Wget's versionsnummer og afslut.\n"
+#~ "  -h,  --help              udskriv denne hjælpetekst.\n"
+#~ "  -b,  --background        kør i baggrunden efter opstart.\n"
+#~ "  -e,  --execute=KOMMANDO  udfør en '.wgetrc'-kommando.\n"
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
+#~ "       --sslcertfile=FILE     optional client certificate.\n"
+#~ "       --sslcertkey=KEYFILE   optional keyfile for this certificate.\n"
+#~ "       --egd-file=FILE        file name of the EGD socket.\n"
+#~ "\n"
+#~ msgstr ""
+#~ "Logning og indlæsning:\n"
+#~ "  -o,  --output-file=FIL      log beskeder til FIL.\n"
+#~ "  -a,  --append-output=FIL    tilføj beskeder til slutningen af FIL.\n"
+#~ "  -d,  --debug                skriv fejlsøgningsinformation.\n"
+#~ "  -q,  --quiet                stille (ingen udskrifter).\n"
+#~ "  -v,  --verbose              vær udførlig (standard).\n"
+#~ "  -nv, --non-verbose          mindre udførlig, men ikke stille.\n"
+#~ "  -i,  --input-file=FIL       hent URLer fundet i FIL.\n"
+#~ "  -F,  --force-html           behandl inddatafil som HTML.\n"
+#~ "  -B,  --base=URL             foranstiller URL til relative lænker i -F -"
+#~ "i fil.\n"
+#~ "       --sslcertfile=FIL      valgbart klient-certifikat.\n"
+#~ "       --sslcertkey=NØGLEFIL  valgbar nøglefil for dette certifikat.\n"
+#~ "       --egd-file=FIL         filnavn for EGD-soklen.\n"
+#~ "\n"
+
+#~ msgid ""
+#~ "Download:\n"
+#~ "       --bind-address=ADDRESS   bind to ADDRESS (hostname or IP) on local "
+#~ "host.\n"
+#~ "  -t,  --tries=NUMBER           set number of retries to NUMBER (0 "
+#~ "unlimits).\n"
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
+#~ "  -T,  --timeout=SECONDS        set the read timeout to SECONDS.\n"
+#~ "  -w,  --wait=SECONDS           wait SECONDS between retrievals.\n"
+#~ "       --waitretry=SECONDS      wait 1...SECONDS between retries of a "
+#~ "retrieval.\n"
+#~ "       --random-wait            wait from 0...2*WAIT secs between "
+#~ "retrievals.\n"
+#~ "  -Y,  --proxy=on/off           turn proxy on or off.\n"
+#~ "  -Q,  --quota=NUMBER           set retrieval quota to NUMBER.\n"
+#~ "       --limit-rate=RATE        limit download rate to RATE.\n"
+#~ "\n"
+#~ msgstr ""
+#~ "Hentning:\n"
+#~ "       --bind-address=ADRESSE   bind til ADRESSE (værtsnavn eller IP) på "
+#~ "lokal vært.\n"
+#~ "  -t,  --tries=ANTAL            maksimalt antal forsøg (0 for uendelig).\n"
+#~ "  -O   --output-document=FIL    skriv dokumenter til FIL.\n"
+#~ "  -nc, --no-clobber             berør ikke eksisterende filer, eller "
+#~ "brug .#-endelser.\n"
+#~ "  -c,  --continue               fortsæt hentning af en eksisterende fil.\n"
+#~ "       --progress=TYPE          vælg type af fremskridtsvisning.\n"
+#~ "  -N,  --timestamping           hent ikke filer igen som er ældre end "
+#~ "eksisterende.\n"
+#~ "  -S,  --server-response        vis svar fra serveren.\n"
+#~ "       --spider                 hent ikke filer.\n"
+#~ "  -T,  --timeout=SEKUNDER       sæt ventetid ved læsning til SEKUNDER.\n"
+#~ "  -w,  --wait=SEKUNDER          sæt ventetid mellem filer til SEKUNDER.\n"
+#~ "       --waitretry=SEKUNDER\twait 1...SEKUNDER mellem forsøg på "
+#~ "gentagelse af en hentning.\n"
+#~ "       --random-wait            vent fra 0...2*WAIT sekunder mellem "
+#~ "modtagelse.\n"
+#~ "  -Y,  --proxy=on/off           slå brug af proxy til eller fra.\n"
+#~ "  -Q,  --quota=ANTAL            sæt hente-kvote til ANTAL.\n"
+#~ "       --limit-rate=RATE        begræns hentingshastighed til RATE.\n"
+#~ "\n"
+
+#~ msgid ""
+#~ "Directories:\n"
+#~ "  -nd  --no-directories            don't create directories.\n"
+#~ "  -x,  --force-directories         force creation of directories.\n"
+#~ "  -nH, --no-host-directories       don't create host directories.\n"
+#~ "  -P,  --directory-prefix=PREFIX   save files to PREFIX/...\n"
+#~ "       --cut-dirs=NUMBER           ignore NUMBER remote directory "
+#~ "components.\n"
+#~ "\n"
+#~ msgstr ""
+#~ "Kataloger:\n"
+#~ "  -nd  --no-directories             lav ikke kataloger.\n"
+#~ "  -x,  --force-directories          lav kataloger.\n"
+#~ "  -nH, --no-host-directories        lav ikke ovenstående kataloger.\n"
+#~ "  -P,  --directory-prefix=PRÆFIKS   skriv filer til PRÆFIKS/...\n"
+#~ "       --cut-dirs=ANTAL             ignorér ANTAL komponenter af "
+#~ "serverens\n"
+#~ "                                    katalognavn.\n"
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
+#~ "\n"
+#~ msgstr ""
+#~ "HTTP-flag:\n"
+#~ "       --http-user=BRUGER      sæt HTTP-bruger til BRUGER.\n"
+#~ "       --http-passwd=PASSORD   sæt HTTP-adgangskode til PASSORD.\n"
+#~ "  -C,  --cache=on/off          tillad (ikke) brug af mellemlager på "
+#~ "server.\n"
+#~ "  -E,  --html-extension        gem alle tekst/html dokumenter med .html "
+#~ "filkode.\n"
+#~ "       --ignore-length         ignorer 'Content-Length' felt i toptekst.\n"
+#~ "       --header=TEKST          sæt TEKST ind som en toptekst.\n"
+#~ "       --proxy-user=BRUGER     sæt proxy-bruger til BRUGER.\n"
+#~ "       --proxy-passwd=PASSORD  sæt proxy-adgangskode til PASSORD.\n"
+#~ "       --referer=URL           brug `Referer: URL' kommando i HTTP-"
+#~ "forespørgsel.\n"
+#~ "  -s,  --save-headers          skriv HTTP-toptekster til fil.\n"
+#~ "  -U,  --user-agent=AGENT      identificer som AGENT i stedet for \n"
+#~ "                               'Wget/VERSION'.\n"
+#~ "       --no-http-keep-alive    deaktivér HTTP keep-alive (overlevende "
+#~ "forbindelser).\n"
+#~ "       --cookies=off           brug ikke infokager.\n"
+#~ "       --load-cookies=FILE     indlæs infokager fra FIL før session.\n"
+#~ "       --save-cookies=FILE     gem infokager i FIL efter session.\n"
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
+#~ "FTP-flag:\n"
+#~ "  -nr, --dont-remove-listing   fjern ikke `.listing' filer.\n"
+#~ "  -g,  --glob=on/off           tolk (ikke) brug af jokertegn i filnavn.\n"
+#~ "       --passive-ftp           brug passiv overførselsmetode.\n"
+#~ "       --retr-symlinks         hent filer (ikke kataloger) der er lænket "
+#~ "til, ved rekursiv brug.\n"
+#~ "\n"
+
+#~ msgid ""
+#~ "Recursive retrieval:\n"
+#~ "  -r,  --recursive          recursive web-suck -- use with care!\n"
+#~ "  -l,  --level=NUMBER       maximum recursion depth (inf or 0 for "
+#~ "infinite).\n"
+#~ "       --delete-after       delete files locally after downloading them.\n"
+#~ "  -k,  --convert-links      convert non-relative links to relative.\n"
+#~ "  -K,  --backup-converted   before converting file X, back up as X.orig.\n"
+#~ "  -m,  --mirror             shortcut option equivalent to -r -N -l inf -"
+#~ "nr.\n"
+#~ "  -p,  --page-requisites    get all images, etc. needed to display HTML "
+#~ "page.\n"
+#~ "\n"
+#~ msgstr ""
+#~ "Rekursiv nedlasting:\n"
+#~ "  -r,  --recursive             tillad rekursiv nedlasting -- brug med "
+#~ "omtanke!\n"
+#~ "  -l,  --level=ANTAL           maksimalt antal rekursionsniveauer "
+#~ "(0=uendelig).\n"
+#~ "       --delete-after          slet hentede filer.\n"
+#~ "  -k,  --convert-links         konverter absolutte lænker til relative.\n"
+#~ "  -K,  --backup-converted      før fil X konverteres, sikkerhedskopiér "
+#~ "som X.orig.\n"
+#~ "  -m,  --mirror                sæt passende flag for spejling af "
+#~ "servere.\n"
+#~ "  -p,  --page-requisites       hent alle billeder osv. der er nødvendige "
+#~ "for at vise HTML siden.\n"
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
+#~ "Hvad er tilladt ved rekursion:\n"
+#~ "  -A,  --accept=LISTE               liste med tilladte filtyper.\n"
+#~ "  -R,  --reject=LISTE               liste med ikke-tilladte filtyper.\n"
+#~ "  -D,  --domains=LISTE              liste med tilladte domæner.\n"
+#~ "       --exclude-domains=LISTE      liste med ikke-tilladte domæner.\n"
+#~ "       --follow-ftp                 følg FTP-lænker fra HTML-dokumenter.\n"
+#~ "       --follow-tags=LIST           komma-separeret liste af fulgte HTML-"
+#~ "mærker.\n"
+#~ "  -G,  --ignore-tags=LIST           komma-separeret liste af ignorerede "
+#~ "HTML-mærker.\n"
+#~ "  -H,  --span-hosts                 følg lænker til andre værter.\n"
+#~ "  -L,  --relative                   følg kun relative lænker.\n"
+#~ "  -I,  --include-directories=LISTE  liste med tilladte katalognavne.\n"
+#~ "  -X,  --exclude-directories=LISTE  liste med ikke-tilladte "
+#~ "katalognavne.\n"
+#~ "  -np, --no-parent                  følg ikke lænke til ovenliggende "
+#~ "katalog.\n"
+#~ "\n"
+
+#~ msgid "%s: debug support not compiled in.\n"
+#~ msgstr ""
+#~ "%s: understøttelse for fejlsøgning ikke inkluderet ved oversættelse.\n"
+
+#~ msgid "%s: %s: invalid command\n"
+#~ msgstr "%s: %s: ugyldig kommando\n"
+
+#~ msgid "Starting WinHelp %s\n"
+#~ msgstr "Starter WinHelp %s\n"
+
+#~ msgid "Could not find proxy host.\n"
+#~ msgstr "Fandt ikke proxy-server.\n"
+
+#~ msgid "%s: Redirection cycle detected.\n"
+#~ msgstr "%s: Omdirigering løber i ring.\n"
+
+#~ msgid "%s: %s: Not enough memory.\n"
+#~ msgstr "%s: %s: Ikke nok hukommelse.\n"
+
 #~ msgid "Connection to %s:%hu refused.\n"
 #~ msgstr "Kontakt med %s:%hu nægtet.\n"
 
