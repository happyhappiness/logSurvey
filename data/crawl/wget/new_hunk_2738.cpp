#. No luck.
#. #### This message SUCKS.  We should see what was the
#. reason that nothing was retrieved.
#: src/ftp.c:1606
#, c-format
msgid "No matches on pattern `%s'.\n"
msgstr "Ingenting passer med m�nsteret �%s�.\n"

#: src/ftp.c:1671
#, c-format
msgid "Wrote HTML-ized index to `%s' [%ld].\n"
msgstr "Skrev HTML-formattert indeks til �%s� [%ld].\n"

#: src/ftp.c:1676
#, c-format
msgid "Wrote HTML-ized index to `%s'.\n"
msgstr "Skrev HTML-formattert indeks til �%s�.\n"

#: src/getopt.c:454
#, c-format
msgid "%s: option `%s' is ambiguous\n"
msgstr "%s: flagget �%s� er tvetydig\n"

#: src/getopt.c:478
#, c-format
msgid "%s: option `--%s' doesn't allow an argument\n"
msgstr "%s: flagget �--%s� tillater ikke argumenter\n"

#: src/getopt.c:483
#, c-format
msgid "%s: option `%c%s' doesn't allow an argument\n"
msgstr "%s: flagget �%c%s� tillater ikke argumenter\n"

#: src/getopt.c:498
#, c-format
msgid "%s: option `%s' requires an argument\n"
msgstr "%s: flagget �%s� krever et argument\n"

#. --option
#: src/getopt.c:528
#, c-format
msgid "%s: unrecognized option `--%s'\n"
msgstr "%s: ukjent flagg �--%s�\n"

#. +option or -option
#: src/getopt.c:532
#, c-format
msgid "%s: unrecognized option `%c%s'\n"
msgstr "%s: ukjent flagg �%c%s�\n"

#. 1003.2 specifies the format of this message.
#: src/getopt.c:563
#, c-format
msgid "%s: illegal option -- %c\n"
msgstr "%s: ugyldig flagg -- %c\n"

#. 1003.2 specifies the format of this message.
#: src/getopt.c:602
#, c-format
msgid "%s: option requires an argument -- %c\n"
msgstr "%s: flagget krever et argument -- %c\n"

#: src/host.c:374
msgid "Host not found"
msgstr "Tjener ikke funnet"

#: src/host.c:376
msgid "Unknown error"
msgstr "Ukjent feil"

#. this is fatal
#: src/http.c:555
msgid "Failed to set up an SSL context\n"
msgstr ""

#: src/http.c:561
#, c-format
msgid "Failed to load certificates from %s\n"
msgstr ""

#: src/http.c:565 src/http.c:573
msgid "Trying without the specified certificate\n"
msgstr ""

#: src/http.c:569
#, c-format
msgid "Failed to get certificate key from %s\n"
msgstr ""

#: src/http.c:663 src/http.c:1593
msgid "Unable to establish SSL connection.\n"
msgstr ""

#: src/http.c:671
#, fuzzy, c-format
msgid "Reusing connection to %s:%hu.\n"
msgstr "Vil pr�ve � kontakte %s:%hu.\n"

#: src/http.c:861
#, fuzzy, c-format
msgid "Failed writing HTTP request: %s.\n"
msgstr "Feil ved sending av HTTP-foresp�rsel.\n"

#: src/http.c:866
#, c-format
msgid "%s request sent, awaiting response... "
msgstr "%s foresp�rsel sendt, mottar topptekster... "

#: src/http.c:910
msgid "End of file while parsing headers.\n"
msgstr "Filslutt funnet ved lesing av topptekster.\n"

#: src/http.c:920
#, c-format
msgid "Read error (%s) in headers.\n"
msgstr "Lesefeil (%s) i topptekster.\n"

#: src/http.c:959
msgid "No data received"
msgstr "Ingen data mottatt"

#: src/http.c:961
msgid "Malformed status line"
msgstr "Feil i statuslinje"

#: src/http.c:966
msgid "(no description)"
msgstr "(ingen beskrivelse)"

#: src/http.c:1089
msgid "Authorization failed.\n"
msgstr "Autorisasjon mislyktes\n"

#: src/http.c:1096
msgid "Unknown authentication scheme.\n"
msgstr "Ukjent autorisasjons-protokoll.\n"

#: src/http.c:1136
#, c-format
msgid "Location: %s%s\n"
msgstr "Sted: %s%s\n"

#: src/http.c:1137 src/http.c:1269
msgid "unspecified"
msgstr "uspesifisert"

#: src/http.c:1138
msgid " [following]"
msgstr " [omdirigert]"

#: src/http.c:1200
msgid "\n    The file is already fully retrieved; nothing to do.\n\n"
msgstr ""

#: src/http.c:1216
#, c-format
msgid ""
"\n"
"Continued download failed on this file, which conflicts with `-c'.\n"
"Refusing to truncate existing file `%s'.\n"
"\n"
msgstr ""

#. No need to print this output if the body won't be
#. downloaded at all, or if the original server response is
#. printed.
#: src/http.c:1259
msgid "Length: "
msgstr "Lengde: "

#: src/http.c:1264
#, c-format
msgid " (%s to go)"
msgstr " (%s igjen)"

#: src/http.c:1269
msgid "ignored"
msgstr "ignoreres"

#: src/http.c:1399
msgid "Warning: wildcards not supported in HTTP.\n"
msgstr "Advarsel: jokertegn ikke st�ttet i HTTP.\n"

#. If opt.noclobber is turned on and file already exists, do not
#. retrieve the file
#: src/http.c:1417
#, c-format
msgid "File `%s' already there, will not retrieve.\n"
msgstr "Filen �%s� hentes ikke, fordi den allerede eksisterer.\n"

#: src/http.c:1585
#, c-format
msgid "Cannot write to `%s' (%s).\n"
msgstr "Kan ikke skrive til �%s� (%s).\n"

#: src/http.c:1602
#, c-format
msgid "ERROR: Redirection (%d) without location.\n"
msgstr "FEIL: Omdirigering (%d) uten nytt sted.\n"

#: src/http.c:1630
#, c-format
msgid "%s ERROR %d: %s.\n"
msgstr "%s FEIL %d: %s.\n"

#: src/http.c:1642
msgid "Last-modified header missing -- time-stamps turned off.\n"
msgstr "Last-modified topptekst mangler -- tidsstempling sl�s av.\n"

#: src/http.c:1650
msgid "Last-modified header invalid -- time-stamp ignored.\n"
msgstr "Last-modified topptekst ugyldig -- tidsstempel ignoreres.\n"

#: src/http.c:1673
#, c-format
msgid "Server file no newer than local file `%s' -- not retrieving.\n\n"
msgstr ""

#: src/http.c:1680
#, fuzzy, c-format
msgid "The sizes do not match (local %ld) -- retrieving.\n"
msgstr "Filst�rrelsene er forskjellige (local %ld), hentes.\n"

#: src/http.c:1684
msgid "Remote file is newer, retrieving.\n"
msgstr "Fil p� tjener er nyere - hentes.\n"

#: src/http.c:1728
#, c-format
msgid "%s (%s) - `%s' saved [%ld/%ld]\n\n"
msgstr "%s (%s) - �%s� lagret [%ld/%ld]\n\n"

#: src/http.c:1774
#, c-format
msgid "%s (%s) - Connection closed at byte %ld. "
msgstr "%s (%s) - Forbindelse brutt ved byte %ld. "

#: src/http.c:1782
#, c-format
msgid "%s (%s) - `%s' saved [%ld/%ld])\n\n"
msgstr "%s (%s) - �%s� lagret [%ld/%ld]\n\n"

#: src/http.c:1801
#, c-format
msgid "%s (%s) - Connection closed at byte %ld/%ld. "
msgstr "%s (%s) - Forbindelse brutt ved byte %ld/%ld. "

#: src/http.c:1812
#, c-format
msgid "%s (%s) - Read error at byte %ld (%s)."
msgstr "%s (%s) - Lesefeil ved byte %ld (%s)."

#: src/http.c:1820
#, c-format
msgid "%s (%s) - Read error at byte %ld/%ld (%s). "
msgstr "%s (%s) - Lesefeil ved byte %ld/%ld (%s)."

#: src/init.c:349 src/netrc.c:267
#, c-format
msgid "%s: Cannot read %s (%s).\n"
msgstr "%s: Kan ikke lese %s (%s).\n"

#: src/init.c:367 src/init.c:373
#, c-format
msgid "%s: Error in %s at line %d.\n"
msgstr "%s: Feil i %s p� linje %d.\n"

#: src/init.c:405
#, c-format
msgid "%s: Warning: Both system and user wgetrc point to `%s'.\n"
msgstr "%s: Advarsel: B�de systemets og brukerens wgetrc peker til �%s�.\n"

#: src/init.c:497
#, c-format
msgid "%s: BUG: unknown command `%s', value `%s'.\n"
msgstr "%s: Ukjent kommando �%s�, verdi �%s�.\n"

#: src/init.c:529
#, fuzzy, c-format
msgid "%s: %s: Cannot convert `%s' to an IP address.\n"
msgstr "%s: Advarsel: feil fra tilbake-oppslag for lokal IP-adresse.\n"

#: src/init.c:559
#, c-format
msgid "%s: %s: Please specify on or off.\n"
msgstr "%s: %s: Vennligst spesifiser �on� eller �off�.\n"

#: src/init.c:603
#, fuzzy, c-format
msgid "%s: %s: Please specify always, on, off, or never.\n"
msgstr "%s: %s: Vennligst spesifiser �on� eller �off�.\n"

#: src/init.c:622 src/init.c:919 src/init.c:941 src/init.c:1005
#, c-format
msgid "%s: %s: Invalid specification `%s'.\n"
msgstr "%s: %s: Ugyldig spesifikasjon �%s�\n"

#: src/init.c:775 src/init.c:797 src/init.c:819 src/init.c:845
#, c-format
msgid "%s: Invalid specification `%s'\n"
msgstr "%s: Ugyldig spesifikasjon �%s�\n"

#: src/main.c:120
#, c-format
msgid "Usage: %s [OPTION]... [URL]...\n"
msgstr "Bruk: %s [FLAGG]... [URL]...\n"

#: src/main.c:128
#, c-format
msgid "GNU Wget %s, a non-interactive network retriever.\n"
msgstr "GNU Wget %s, en ikke-interaktiv informasjonsagent.\n"

#. Had to split this in parts, so the #@@#%# Ultrix compiler and cpp
#. don't bitch.  Also, it makes translation much easier.
#: src/main.c:133
msgid "\nMandatory arguments to long options are mandatory for short options too.\n\n"
msgstr ""
"\n"
"Obligatoriske argumenter til lange flagg er obligatoriske ogs� \n"
"for korte.\n"
"\n"

#: src/main.c:137
#, fuzzy
msgid ""
"Startup:\n"
"  -V,  --version           display the version of Wget and exit.\n"
"  -h,  --help              print this help.\n"
"  -b,  --background        go to background after startup.\n"
"  -e,  --execute=COMMAND   execute a `.wgetrc'-style command.\n"
"\n"
msgstr ""
"Oppstart:\n"
"  -V,  --version           viser Wget's versjonsnummer og avslutter.\n"
"  -h,  --help              skriver ut denne hjelpeteksten.\n"
"  -b,  --background        kj�rer i bakgrunnen etter oppstart.\n"
"  -e,  --execute=KOMMANDO  utf�r en �.wgetrc�-kommando.\n"
"\n"

#: src/main.c:144
#, fuzzy
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
"\n"
msgstr ""
"Utskrifter og innlesing:\n"
"  -o,  --output-file=FIL      skriv meldinger til ny FIL.\n"
"  -a,  --append-output=FIL    skriv meldinger p� slutten av FIL.\n"
"  -d,  --debug                skriv avlusingsinformasjon.\n"
"  -q,  --quiet                stille (ingen utskrifter).\n"
"  -v,  --verbose              v�r utf�rlig (standard).\n"
"  -nv, --non-verbose          mindre utf�rlig, men ikke stille.\n"
"  -i,  --input-file=FIL       les URLer fra FIL.\n"
"  -F,  --force-html           les inn filer som HTML.\n"
"\n"

#: src/main.c:158
#, fuzzy
msgid ""
"Download:\n"
"       --bind-address=ADDRESS   bind to ADDRESS (hostname or IP) on local host.\n"
"  -t,  --tries=NUMBER           set number of retries to NUMBER (0 unlimits).\n"
"  -O   --output-document=FILE   write documents to FILE.\n"
"  -nc, --no-clobber             don't clobber existing files or use .# suffixes.\n"
"  -c,  --continue               resume getting a partially-downloaded file.\n"
"       --dot-style=STYLE        set retrieval display style.\n"
"  -N,  --timestamping           don't re-retrieve files unless newer than local.\n"
"  -S,  --server-response        print server response.\n"
"       --spider                 don't download anything.\n"
"  -T,  --timeout=SECONDS        set the read timeout to SECONDS.\n"
"  -w,  --wait=SECONDS           wait SECONDS between retrievals.\n"
"       --waitretry=SECONDS      wait 1...SECONDS between retries of a retrieval.\n"
"  -Y,  --proxy=on/off           turn proxy on or off.\n"
"  -Q,  --quota=NUMBER           set retrieval quota to NUMBER.\n"
"\n"
msgstr ""
"Nedlasting:\n"
"  -t,  --tries=ANTALL           maksimalt antall fors�k (0 for uendelig).\n"
"  -O   --output-document=FIL    skriv nedlastede filer til FIL.\n"
"  -nc, --no-clobber             ikke ber�r eksisterende filer.\n"
"  -c,  --continue               fortsett nedlasting av en eksisterende fil.\n"
"       --dot-style=TYPE         velg format for nedlastings-status.\n"
"  -N,  --timestamping           ikke hent filer som er eldre enn eksisterende.\n"
"  -S,  --server-response        vis svar fra tjeneren.\n"
"       --spider                 ikke hent filer.\n"
"  -T,  --timeout=SEKUNDER       sett ventetid ved lesing til SEKUNDER.\n"
"  -w,  --wait=SEKUNDER          sett ventetid mellom filer til SEKUNDER.\n"
"  -Y,  --proxy=on/off           sett bruk av proxy p� eller av.\n"
"  -Q,  --quota=ANTALL           sett nedlastingskvote til ANTALL.\n"
"\n"

#: src/main.c:175
msgid ""
"Directories:\n"
"  -nd  --no-directories            don't create directories.\n"
"  -x,  --force-directories         force creation of directories.\n"
"  -nH, --no-host-directories       don't create host directories.\n"
"  -P,  --directory-prefix=PREFIX   save files to PREFIX/...\n"
"       --cut-dirs=NUMBER           ignore NUMBER remote directory components.\n"
"\n"
msgstr ""
"Kataloger:\n"
"  -nd  --no-directories             ikke lag kataloger.\n"
"  -x,  --force-directories          lag kataloger.\n"
"  -nH, --no-host-directories        ikke lag ovenst�ende kataloger.\n"
"  -P,  --directory-prefix=PREFIKS   skriv filer til PREFIKS/...\n"
"       --cut-dirs=ANTALL            ignorer ANTALL komponenter av tjenerens\n"
"                                    katalognavn.\n"
"\n"

#: src/main.c:183
#, fuzzy
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
"HTTP-flagg:\n"
"       --http-user=BRUKER      sett HTTP-bruker til BRUKER.\n"
"       --http-passwd=PASSORD   sett HTTP-passord til PASSORD.\n"
"  -C,  --cache=on/off          (ikke) tillat bruk av hurtiglager p� tjener.\n"
"       --ignore-length         ignorer �Content-Length� felt i topptekst.\n"
"       --header=TEKST          sett TEKST inn som en topptekst.\n"
"       --proxy-user=BRUKER     sett proxy-bruker til BRUKER.\n"
"       --proxy-passwd=PASSORD  sett proxy-passord til PASSORD.\n"
"  -s,  --save-headers          skriv HTTP-topptekster til fil.\n"
"  -U,  --user-agent=AGENT      identifiser som AGENT i stedet for \n"
"                               �Wget/VERSJON�.\n"
"\n"

#: src/main.c:201
#, fuzzy
msgid ""
"FTP options:\n"
"  -nr, --dont-remove-listing   don't remove `.listing' files.\n"
"  -g,  --glob=on/off           turn file name globbing on or off.\n"
"       --passive-ftp           use the \"passive\" transfer mode.\n"
"       --retr-symlinks         when recursing, get linked-to files (not dirs).\n"
"\n"
msgstr ""
"FTP-flagg:\n"
"       --retr-symlinks   hent symbolske linker via FTP.\n"
"  -g,  --glob=on/off     (ikke) tolk bruk av jokertegn i filnavn.\n"
"       --passive-ftp     bruk passiv overf�ringsmodus.\n"
"\n"

#: src/main.c:208
#, fuzzy
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
"Rekursiv nedlasting:\n"
"  -r,  --recursive             tillat rekursiv nedlasting -- bruk med omtanke!\n"
"  -l,  --level=ANTALL          maksimalt antall rekursjonsniv�er (0=uendelig).\n"
"       --delete-after          slett nedlastede filer.\n"
"  -k,  --convert-links         konverter absolutte linker til relative.\n"
"  -m,  --mirror                sett passende flagg for speiling av tjenere.\n"
"  -nr, --dont-remove-listing   ikke slett �.listing�-filer.\n"
"\n"

#: src/main.c:218
#, fuzzy
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
"  -nh, --no-host-lookup             don't DNS-lookup hosts.\n"
"  -np, --no-parent                  don't ascend to the parent directory.\n"
"\n"
msgstr ""
"Hva er tillatt ved rekursjon:\n"
"  -A,  --accept=LISTE               liste med tillatte filtyper.\n"
"  -R,  --reject=LISTE               liste med ikke tillatte filtyper.\n"
"  -D,  --domains=LISTE              liste med tillatte domener.\n"
"       --exclude-domains=LISTE      liste med ikke tillatte domener.\n"
"  -L,  --relative                   f�lg kun relative linker.\n"
"       --follow-ftp                 f�lg FTP-linker fra HTML-dokumenter.\n"
"  -H,  --span-hosts                 f�lg linker til andre tjenere.\n"
"  -I,  --include-directories=LISTE  liste med tillatte katalognavn.\n"
"  -X,  --exclude-directories=LISTE  liste med ikke tillatte katalognavn.\n"
"  -nh, --no-host-lookup             ikke let etter tjenernavn via DNS.\n"
"  -np, --no-parent                  ikke f�lg linker til ovenst�ende katalog.\n"
"\n"

#: src/main.c:234
msgid "Mail bug reports and suggestions to <bug-wget@gnu.org>.\n"
msgstr "Rapport�r feil og send forslag til <bug-wget@gnu.org>.\n"

#: src/main.c:420
#, c-format
msgid "%s: debug support not compiled in.\n"
msgstr "%s: st�tte for avlusing ikke inkludert ved kompilering.\n"

#: src/main.c:472
#, fuzzy
msgid ""
"Copyright (C) 1995, 1996, 1997, 1998, 2000, 2001 Free Software Foundation, Inc.\n"
"This program is distributed in the hope that it will be useful,\n"
"but WITHOUT ANY WARRANTY; without even the implied warranty of\n"
"MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the\n"
