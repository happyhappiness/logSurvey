 "      názvem poèítaèe\n"
 
 # , c-format
-#: src/netrc.c:398
+#: src/netrc.c:416
 #, c-format
 msgid "%s: %s:%d: unknown token \"%s\"\n"
 msgstr "%s: %s:%d: neznámý token \"%s\"\n"
 
 # , c-format
-#: src/netrc.c:462
+#: src/netrc.c:480
 #, c-format
 msgid "Usage: %s NETRC [HOSTNAME]\n"
 msgstr "Pou¾ití: %s NETRC [NÁZEV POÈÍTAÈE]\n"
 
 # , c-format
-#: src/netrc.c:472
+#: src/netrc.c:490
 #, c-format
 msgid "%s: cannot stat %s: %s\n"
 msgstr "%s: volání `stat %s' skonèilo chybou: %s\n"
 
 # , c-format
-#: src/recur.c:484
+#. Align the [ skipping ... ] line with the dots.  To do
+#. that, insert the number of spaces equal to the number of
+#. digits in the skipped amount in K.
+#: src/progress.c:243
+#, fuzzy, c-format
+msgid ""
+"\n"
+"%*s[ skipping %dK ]"
+msgstr ""
+"\n"
+"          [ pøeskakuje se %dK ]"
+
+# , c-format
+#: src/progress.c:410
+#, fuzzy, c-format
+msgid "Invalid dot style specification `%s'; leaving unchanged.\n"
+msgstr "%s: Neplatná specifikace `%s'\n"
+
+# , c-format
+#: src/recur.c:377
 #, c-format
 msgid "Removing %s since it should be rejected.\n"
 msgstr "Ma¾e se %s, proto¾e tento soubor není po¾adován.\n"
 
-#: src/recur.c:679
+#: src/res.c:548
 msgid "Loading robots.txt; please ignore errors.\n"
 msgstr "Naèítá se `robots.txt'. Chybová hlá¹ení ignorujte, prosím.\n"
 
 # , c-format
-#: src/retr.c:227
-#, c-format
-msgid "\n          [ skipping %dK ]"
-msgstr "\n          [ pøeskakuje se %dK ]"
-
-#: src/retr.c:373
-msgid "Could not find proxy host.\n"
-msgstr "Nelze najít proxy server.\n"
+#: src/retr.c:638
+#, fuzzy, c-format
+msgid "Error parsing proxy URL %s: %s.\n"
+msgstr "Pøi zápisu do `%s' nastala chyba: %s.\n"
 
 # , c-format
-#: src/retr.c:387
-#, c-format
-msgid "Proxy %s: Must be HTTP.\n"
+#: src/retr.c:646
+#, fuzzy, c-format
+msgid "Error in proxy URL %s: Must be HTTP.\n"
 msgstr "Proxy %s: Musí být HTTP.\n"
 
 # , c-format
-#: src/retr.c:481
-#, c-format
-msgid "%s: Redirection cycle detected.\n"
+#: src/retr.c:731
+#, fuzzy, c-format
+msgid "%d redirections exceeded.\n"
 msgstr "%s: Detekováno zacyklené pøesmìrování.\n"
 
-#: src/retr.c:587
-msgid "Giving up.\n\n"
-msgstr "Ani poslední pokus nebyl úspì¹ný.\n\n"
+#: src/retr.c:856
+msgid ""
+"Giving up.\n"
+"\n"
+msgstr ""
+"Ani poslední pokus nebyl úspì¹ný.\n"
+"\n"
+
+#: src/retr.c:856
+msgid ""
+"Retrying.\n"
+"\n"
+msgstr ""
+"Zkusí se to znovu.\n"
+"\n"
+
+#: src/url.c:642
+#, fuzzy
+msgid "No error"
+msgstr "Neznámá chyba"
+
+#: src/url.c:644
+msgid "Unsupported scheme"
+msgstr ""
+
+#: src/url.c:646
+msgid "Empty host"
+msgstr ""
+
+#: src/url.c:648
+msgid "Bad port number"
+msgstr ""
+
+#: src/url.c:650
+#, fuzzy
+msgid "Invalid user name"
+msgstr "Neplatné jméno stroje"
+
+#: src/url.c:652
+msgid "Unterminated IPv6 numeric address"
+msgstr ""
+
+#: src/url.c:654
+msgid "IPv6 addresses not supported"
+msgstr ""
 
-#: src/retr.c:587
-msgid "Retrying.\n\n"
-msgstr "Zkusí se to znovu.\n\n"
+#: src/url.c:656
+msgid "Invalid IPv6 numeric address"
+msgstr ""
+
+#. parent, no error
+#: src/utils.c:347
+#, fuzzy, c-format
+msgid "Continuing in background, pid %d.\n"
+msgstr "Program pokraèuje v bìhu na pozadí.\n"
 
 # , c-format
-#: src/url.c:1329
+#: src/utils.c:391
 #, c-format
-msgid "Converting %s... "
-msgstr "Pøevádí se %s... "
+msgid "Failed to unlink symlink `%s': %s\n"
+msgstr "Nebylo mo¾né odstranit symbolický odkaz `%s': %s\n"
 
-#: src/url.c:1342
-msgid "nothing to do.\n"
-msgstr "nic není potøeba pøevádìt.\n"
+#: src/xmalloc.c:72
+#, c-format
+msgid "%s: %s: Failed to allocate %ld bytes; memory exhausted.\n"
+msgstr ""
+
+#~ msgid "Syntax error in Set-Cookie at character `%c'.\n"
+#~ msgstr "Syntaktická chyba v hlavièce Set-Cookie na znaku `%c'.\n"
 
 # , c-format
-#: src/url.c:1350 src/url.c:1374
-#, c-format
-msgid "Cannot convert links in %s: %s\n"
-msgstr "Nelze pøevést odkazy v %s: %s\n"
+#~ msgid "Connection to %s:%hu refused.\n"
+#~ msgstr "Spojení s %s:%hu odmítnuto.\n"
 
 # , c-format
-#: src/url.c:1365
-#, c-format
-msgid "Unable to delete `%s': %s\n"
-msgstr "Nebylo mo¾né odstranit `%s': %s\n"
+#~ msgid "Will try connecting to %s:%hu.\n"
+#~ msgstr "Program se pokusí spojit s %s:%hu.\n"
+
+#~ msgid ""
+#~ "\n"
+#~ "REST failed; will not truncate `%s'.\n"
+#~ msgstr ""
+#~ "\n"
+#~ "Pøíkaz REST selhal, `%s' nebude zkráceno.\n"
 
 # , c-format
-#: src/url.c:1555
-#, c-format
-msgid "Cannot back up %s as %s: %s\n"
-msgstr "Nelze zálohovat %s jako %s: %s\n"
+#~ msgid " [%s to go]"
+#~ msgstr " [%s zbývá]"
+
+#~ msgid "Host not found"
+#~ msgstr "Poèítaè nebyl nalezen"
+
+#~ msgid "End of file while parsing headers.\n"
+#~ msgstr "Hlavièka není úplná.\n"
+
+#~ msgid ""
+#~ "\n"
+#~ "Continued download failed on this file, which conflicts with `-c'.\n"
+#~ "Refusing to truncate existing file `%s'.\n"
+#~ "\n"
+#~ msgstr ""
+#~ "\n"
+#~ "Na pøeru¹ené stahování tohoto souboru nelze navázat. Bylo ov¹em zadáno `-"
+#~ "c'.\n"
+#~ "Existující soubor `%s' tedy radìji nebude zkrácen.\n"
+#~ "\n"
 
 # , c-format
-#: src/utils.c:94
-#, c-format
-msgid "%s: %s: Not enough memory.\n"
-msgstr "%s: %s: Není dost pamìti.\n"
+#~ msgid " (%s to go)"
+#~ msgstr " (%s zbývá)"
 
-#: src/utils.c:417
-msgid "Unknown/unsupported protocol"
-msgstr "Neznámý/nepodporovaný protokol"
+# , c-format
+#~ msgid "%s: BUG: unknown command `%s', value `%s'.\n"
+#~ msgstr "%s: CHYBA: Neznámý pøíkaz `%s', hodnota `%s'.\n"
 
-#: src/utils.c:420
-msgid "Invalid port specification"
-msgstr "Neplatná specifikace portu"
+#~ msgid "%s: %s: Cannot convert `%s' to an IP address.\n"
+#~ msgstr "%s: %s: `%s' nelze pøevést na IP adresu.\n"
 
-#: src/utils.c:423
-msgid "Invalid host name"
-msgstr "Neplatné jméno stroje"
+#~ msgid ""
+#~ "Startup:\n"
+#~ "  -V,  --version           display the version of Wget and exit.\n"
+#~ "  -h,  --help              print this help.\n"
+#~ "  -b,  --background        go to background after startup.\n"
+#~ "  -e,  --execute=COMMAND   execute a `.wgetrc'-style command.\n"
+#~ "\n"
+#~ msgstr ""
+#~ "Zaèátek:\n"
+#~ "  -V,  --version           vypí¹e informaci o verzi programu Wget a "
+#~ "skonèí\n"
+#~ "  -h,  --help              vypí¹e tuto nápovìdu\n"
+#~ "  -b,  --background        po spu¹tìní pokraèuje program v bìhu na "
+#~ "pozadí\n"
+#~ "  -e,  --execute=PØÍKAZ    proveïe pøíkaz zadaný ve stylu `.wgetrc'\n"
+#~ "\n"
+
+# , fuzzy
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
+#~ "\n"
+#~ msgstr ""
+#~ "Protokolování a vstupní soubor:\n"
+#~ "  -o,  --output-file=SOUBOR   název souboru s protokolem\n"
+#~ "  -a,  --append-output=SOUBOR protokol se pøipojí na konec tohoto "
+#~ "souboru\n"
+#~ "  -d,  --debug                vypisuje ladicí informace\n"
+#~ "  -q,  --quiet                nevypisuje vùbec nic\n"
+#~ "  -v,  --verbose              bude upovídaný (implicitnì zapnuto)\n"
+#~ "  -nv, --non-verbose          vypisuje pouze nejdùle¾itìj¹í informace\n"
+#~ "  -i,  --input-file=SOUBOR    výchozí URL odkazy naète z tohoto souboru\n"
+#~ "  -F,  --force-html           soubor s URL je v HTML formátu\n"
+#~ "  -B,  --base=URL             pøidá URL na zaèátky relat. odkazù pøi '-F -"
+#~ "i'\n"
+#~ "       --sslcertfile=SOUBOR   volitelný certifikát klienta\n"
+#~ "       --sslcertkey=SOUBOR    volitelný soubor klíèù pro tento "
+#~ "certifikát\n"
+#~ "\n"
+
+# , fuzzy
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
+#~ "       --dot-style=STYLE        set retrieval display style.\n"
+#~ "  -N,  --timestamping           don't re-retrieve files unless newer than "
+#~ "local.\n"
+#~ "  -S,  --server-response        print server response.\n"
+#~ "       --spider                 don't download anything.\n"
+#~ "  -T,  --timeout=SECONDS        set the read timeout to SECONDS.\n"
+#~ "  -w,  --wait=SECONDS           wait SECONDS between retrievals.\n"
+#~ "       --waitretry=SECONDS      wait 1...SECONDS between retries of a "
+#~ "retrieval.\n"
+#~ "  -Y,  --proxy=on/off           turn proxy on or off.\n"
+#~ "  -Q,  --quota=NUMBER           set retrieval quota to NUMBER.\n"
+#~ "\n"
+#~ msgstr ""
+#~ "Stahování:\n"
+#~ "       --bind-address=ADRESA    pou¾ij lokální rozhraní s danou adresou "
+#~ "(IP nebo jméno)\n"
+#~ "  -t,  --tries=ÈÍSLO            poèet pokusù stáhnout URL (0 "
+#~ "donekoneèna)\n"
+#~ "  -O   --output-document=SOUBOR sta¾ené dokumenty ukládá do tohoto "
+#~ "souboru\n"
+#~ "  -nc, --no-clobber             nepøepisuje existující soubory\n"
+#~ "  -c,  --continue               pokraèuje ve stahování èásteènì "
+#~ "pøenesených dat\n"
+#~ "       --dot-style=STYL         nastaví zpùsob zobrazení pøi stahování "
+#~ "dat\n"
+#~ "  -N,  --timestamping           nestahuje star¹í soubory (zapne èasová "
+#~ "razítka)\n"
+#~ "  -S,  --server-response        vypisuje odpovìdi serveru\n"
+#~ "       --spider                 nic nestahuje\n"
+#~ "  -T,  --timeout=SEKUNDY        nastaví timeout pøi ètení na tuto "
+#~ "hodnotu\n"
+#~ "  -w,  --wait=POÈET             pøed ka¾dým stahováním poèká POÈET "
+#~ "sekund\n"
+#~ "       --waitretry=POÈET        èeká 1...POÈET sec pøed novým pokusem o "
+#~ "sta¾ení\n"
+#~ "  -Y,  --proxy=on/off           zapne pøenos pøes proxy (standardnì "
+#~ "`off')\n"
+#~ "  -Q,  --quota=BAJTÙ            nastaví limit objemu ulo¾ených dat\n"
+#~ "\n"
+
+# , fuzzy
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
+#~ "Adresáøe:\n"
+#~ "  -nd  --no-directories            nevytváøí adresáøe\n"
+#~ "  -x,  --force-directories         v¾dy vytváøí adresáøe\n"
+#~ "  -nH, --no-host-directories       nevytváøí adresáøe s adresou serveru\n"
+#~ "  -P,  --directory-prefix=PREFIX   ukládá data do PREFIX/...\n"
+#~ "       --cut-dirs=POÈET            nevytváøí prvních POÈET podadresáøù\n"
+#~ "\n"
+
+# , fuzzy
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
+#~ "Pøepínaèe pro HTTP:\n"
+#~ "       --http-user=U®IVATEL  u¾ivatelské jméno pro autorizovaný HTTP "
+#~ "pøenos\n"
+#~ "       --http-passwd=HESLO   heslo pro autorizovaný HTTP pøenos \n"
+#~ "  -C,  --cache=on/off        povolí èi zaká¾e pou¾ití vyrovnávací pamìti "
+#~ "na\n"
+#~ "                             stranì serveru (implicitnì `on')\n"
+#~ "  -E,  --html-extension      ulo¾í dokumenty typu `text/html' s pøíponou ."
+#~ "html\n"
+#~ "       --ignore-length       ignoruje pole `Content-Length' v hlavièce\n"
+#~ "       --header=ØETÌZEC      po¹le ØETÌZEC serveru jako souèást hlavièek\n"
+#~ "       --proxy-user=U®IVATEL jméno u¾ivatele vy¾adované pro proxy pøenos\n"
+#~ "       --proxy-passwd=HESLO  heslo pro proxy pøenos\n"
+#~ "       --referer=URL         posílá v hlaviècce HTTP po¾adavku `Referer: "
+#~ "URL'\n"
+#~ "  -s,  --save-headers        do stahovaného souboru ulo¾í i hlavièky "
+#~ "HTTP\n"
+#~ "  -U,  --user-agent=AGENT    místo identifikace `Wget/VERZE' posílá v "
+#~ "hlavièce \n"
+#~ "                             HTTP po¾adavku identifikaèní øetìzec AGENT\n"
+#~ "       --no-http-keep-alive  vypne HTTP keep-alive (trvalé spojení se "
+#~ "serverem)\n"
+#~ "       --cookies=off         nebude pou¾ívat koláèky (HTTP cookies)\n"
+#~ "       --load-cookies=SOUBOR pøed sezením naète koláèky ze souboru "
+#~ "SOUBOR\n"
+#~ "       --save-cookies=SOUBOR po sezení ulo¾í koláèky do souboru SOUBOR\n"
+#~ "\n"
+
+# , fuzzy
+#~ msgid ""
+#~ "FTP options:\n"
+#~ "  -nr, --dont-remove-listing   don't remove `.listing' files.\n"
+#~ "  -g,  --glob=on/off           turn file name globbing on or off.\n"
+#~ "       --passive-ftp           use the \"passive\" transfer mode.\n"
+#~ "       --retr-symlinks         when recursing, get linked-to files (not "
+#~ "dirs).\n"
+#~ "\n"
+#~ msgstr ""
+#~ "Pøepínaèe pro FTP protokol:\n"
+#~ "  -nr, --dont-remove-listing  nema¾e soubory `.listing' s obsahy "
+#~ "adresáøù\n"
+#~ "  -g,  --glob=on/off          zapne èi vypne expanzi ¾olíkù ve jménech "
+#~ "souborù\n"
+#~ "       --passive-ftp          pou¾ije pasivní mód pøenosu dat\n"
+#~ "       --retr-symlinks        v rekurzivním módu stahuje i symbolické "
+#~ "odkazy na\n"
+#~ "                              soubory (nikoliv na adresáøe)\n"
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
+#~ "Rekurzivní stahování:\n"
+#~ "  -r,  --recursive             rekurzivní stahování -- buïte opatrní!\n"
+#~ "  -l,  --level=ÈÍSLO           maximální hloubka rekurze (0 bez limitu)\n"
+#~ "       --delete-after          po pøenosu sma¾e sta¾ené soubory\n"
+#~ "  -k,  --convert-links         absolutní URL pøeveïe na relativní\n"
+#~ "  -K,  --backup-converted      pøed konverzí ulo¾í `X' jako `X.orig'\n"
+#~ "  -m,  --mirror                zapne pøepínaèe vhodné pro zrcadlení dat \n"
+#~ "  -p,  --page-requisites       stáhne v¹e nutné pro zobrazení HTML "
+#~ "stránky\n"
+
+# , fuzzy
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
+#~ "  -nh, --no-host-lookup             don't DNS-lookup hosts.\n"
+#~ "  -np, --no-parent                  don't ascend to the parent "
+#~ "directory.\n"
+#~ "\n"
+#~ msgstr ""
+#~ "Omezení pøi rekurzi:\n"
+#~ "  -A,  --accept=SEZNAM              seznam povolených extenzí souborù\n"
+#~ "  -R,  --reject=SEZNAM              seznam nepovolených extenzí souborù\n"
+#~ "  -D,  --domains=SEZNAM             seznam povolených domén\n"
+#~ "       --exclude-domains=SEZNAM     seznam nepovolených domén\n"
+#~ "       --follow-ftp                 následuje FTP odkazy v HTML "
+#~ "dokumentech\n"
+#~ "       --follow-tags=LIST           seznam následovaných HTML znaèek \n"
+#~ "  -G,  --ignore-tags=LIST           seznam ignorovaných HTML znaèek\n"
+#~ "  -H,  --span-hosts                 naèítá dokumenty i z ostatních "
+#~ "serverù\n"
+#~ "  -I,  --include-directories=SEZNAM seznam povolených adresáøù\n"
+#~ "  -L,  --relative                   následuje pouze relativní odkazy\n"
+#~ "  -X,  --exclude-directories=SEZNAM seznam vylouèených adresáøù\n"
+#~ "  -nh, --no-host-lookup             nevyhledává adresy v DNS\n"
+#~ "  -np, --no-parent                  nesestupuje do rodièovského adresáøe\n"
+#~ "\n"
+
+# , fuzzy
+#~ msgid "%s: debug support not compiled in.\n"
+#~ msgstr "%s: program nebyl zkompilován s podporou pro ladìní.\n"
 
 # , c-format
-#: src/utils.c:620
-#, c-format
-msgid "Failed to unlink symlink `%s': %s\n"
-msgstr "Nebylo mo¾né odstranit symbolický odkaz `%s': %s\n"
+#~ msgid "%s: %s: invalid command\n"
+#~ msgstr "%s: %s: neplatný pøíkaz\n"
+
+# , c-format
+#~ msgid ""
+#~ "\n"
+#~ "CTRL+Break received, redirecting output to `%s'.\n"
+#~ "Execution continued in background.\n"
+#~ "You may stop Wget by pressing CTRL+ALT+DELETE.\n"
+#~ msgstr ""
+#~ "\n"
+#~ "Stiskli jste CTRL+Break, výstup byl proto pøesmìrován do `%s'.\n"
+#~ "Program pokraèuje v bìhu na pozadí.\n"
+#~ "Wget lze zastavit stiskem CTRL+ALT+DELETE.\n"
+
+# , c-format
+#~ msgid "Starting WinHelp %s\n"
+#~ msgstr "Spou¹tí se WinHelp %s\n"
+
+#~ msgid "Could not find proxy host.\n"
+#~ msgstr "Nelze najít proxy server.\n"
+
+# , c-format
+#~ msgid "%s: %s: Not enough memory.\n"
+#~ msgstr "%s: %s: Není dost pamìti.\n"
+
+#~ msgid "Unknown/unsupported protocol"
+#~ msgstr "Neznámý/nepodporovaný protokol"
+
+#~ msgid "Invalid port specification"
+#~ msgstr "Neplatná specifikace portu"
 
 #~ msgid "%s: Cannot determine user-id.\n"
 #~ msgstr "%s: Nelze zjistit ID u¾ivatele.\n"
 
-#~ # , c-format
+# , c-format
 #~ msgid "%s: Warning: uname failed: %s\n"
 #~ msgstr "%s: Varování: Volání funkce \"uname\" skonèilo chybou %s\n"
 
