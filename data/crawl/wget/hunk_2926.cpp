 "      n�zvem po��ta�e\n"
 
 # , c-format
-#: src/netrc.c:398
+#: src/netrc.c:416
 #, c-format
 msgid "%s: %s:%d: unknown token \"%s\"\n"
 msgstr "%s: %s:%d: nezn�m� token \"%s\"\n"
 
 # , c-format
-#: src/netrc.c:462
+#: src/netrc.c:480
 #, c-format
 msgid "Usage: %s NETRC [HOSTNAME]\n"
 msgstr "Pou�it�: %s NETRC [N�ZEV PO��TA�E]\n"
 
 # , c-format
-#: src/netrc.c:472
+#: src/netrc.c:490
 #, c-format
 msgid "%s: cannot stat %s: %s\n"
 msgstr "%s: vol�n� `stat %s' skon�ilo chybou: %s\n"
 
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
+"          [ p�eskakuje se %dK ]"
+
+# , c-format
+#: src/progress.c:410
+#, fuzzy, c-format
+msgid "Invalid dot style specification `%s'; leaving unchanged.\n"
+msgstr "%s: Neplatn� specifikace `%s'\n"
+
+# , c-format
+#: src/recur.c:377
 #, c-format
 msgid "Removing %s since it should be rejected.\n"
 msgstr "Ma�e se %s, proto�e tento soubor nen� po�adov�n.\n"
 
-#: src/recur.c:679
+#: src/res.c:548
 msgid "Loading robots.txt; please ignore errors.\n"
 msgstr "Na��t� se `robots.txt'. Chybov� hl�en� ignorujte, pros�m.\n"
 
 # , c-format
-#: src/retr.c:227
-#, c-format
-msgid "\n          [ skipping %dK ]"
-msgstr "\n          [ p�eskakuje se %dK ]"
-
-#: src/retr.c:373
-msgid "Could not find proxy host.\n"
-msgstr "Nelze naj�t proxy server.\n"
+#: src/retr.c:638
+#, fuzzy, c-format
+msgid "Error parsing proxy URL %s: %s.\n"
+msgstr "P�i z�pisu do `%s' nastala chyba: %s.\n"
 
 # , c-format
-#: src/retr.c:387
-#, c-format
-msgid "Proxy %s: Must be HTTP.\n"
+#: src/retr.c:646
+#, fuzzy, c-format
+msgid "Error in proxy URL %s: Must be HTTP.\n"
 msgstr "Proxy %s: Mus� b�t HTTP.\n"
 
 # , c-format
-#: src/retr.c:481
-#, c-format
-msgid "%s: Redirection cycle detected.\n"
+#: src/retr.c:731
+#, fuzzy, c-format
+msgid "%d redirections exceeded.\n"
 msgstr "%s: Detekov�no zacyklen� p�esm�rov�n�.\n"
 
-#: src/retr.c:587
-msgid "Giving up.\n\n"
-msgstr "Ani posledn� pokus nebyl �sp�n�.\n\n"
+#: src/retr.c:856
+msgid ""
+"Giving up.\n"
+"\n"
+msgstr ""
+"Ani posledn� pokus nebyl �sp�n�.\n"
+"\n"
+
+#: src/retr.c:856
+msgid ""
+"Retrying.\n"
+"\n"
+msgstr ""
+"Zkus� se to znovu.\n"
+"\n"
+
+#: src/url.c:642
+#, fuzzy
+msgid "No error"
+msgstr "Nezn�m� chyba"
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
+msgstr "Neplatn� jm�no stroje"
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
-msgstr "Zkus� se to znovu.\n\n"
+#: src/url.c:656
+msgid "Invalid IPv6 numeric address"
+msgstr ""
+
+#. parent, no error
+#: src/utils.c:347
+#, fuzzy, c-format
+msgid "Continuing in background, pid %d.\n"
+msgstr "Program pokra�uje v b�hu na pozad�.\n"
 
 # , c-format
-#: src/url.c:1329
+#: src/utils.c:391
 #, c-format
-msgid "Converting %s... "
-msgstr "P�ev�d� se %s... "
+msgid "Failed to unlink symlink `%s': %s\n"
+msgstr "Nebylo mo�n� odstranit symbolick� odkaz `%s': %s\n"
 
-#: src/url.c:1342
-msgid "nothing to do.\n"
-msgstr "nic nen� pot�eba p�ev�d�t.\n"
+#: src/xmalloc.c:72
+#, c-format
+msgid "%s: %s: Failed to allocate %ld bytes; memory exhausted.\n"
+msgstr ""
+
+#~ msgid "Syntax error in Set-Cookie at character `%c'.\n"
+#~ msgstr "Syntaktick� chyba v hlavi�ce Set-Cookie na znaku `%c'.\n"
 
 # , c-format
-#: src/url.c:1350 src/url.c:1374
-#, c-format
-msgid "Cannot convert links in %s: %s\n"
-msgstr "Nelze p�ev�st odkazy v %s: %s\n"
+#~ msgid "Connection to %s:%hu refused.\n"
+#~ msgstr "Spojen� s %s:%hu odm�tnuto.\n"
 
 # , c-format
-#: src/url.c:1365
-#, c-format
-msgid "Unable to delete `%s': %s\n"
-msgstr "Nebylo mo�n� odstranit `%s': %s\n"
+#~ msgid "Will try connecting to %s:%hu.\n"
+#~ msgstr "Program se pokus� spojit s %s:%hu.\n"
+
+#~ msgid ""
+#~ "\n"
+#~ "REST failed; will not truncate `%s'.\n"
+#~ msgstr ""
+#~ "\n"
+#~ "P��kaz REST selhal, `%s' nebude zkr�ceno.\n"
 
 # , c-format
-#: src/url.c:1555
-#, c-format
-msgid "Cannot back up %s as %s: %s\n"
-msgstr "Nelze z�lohovat %s jako %s: %s\n"
+#~ msgid " [%s to go]"
+#~ msgstr " [%s zb�v�]"
+
+#~ msgid "Host not found"
+#~ msgstr "Po��ta� nebyl nalezen"
+
+#~ msgid "End of file while parsing headers.\n"
+#~ msgstr "Hlavi�ka nen� �pln�.\n"
+
+#~ msgid ""
+#~ "\n"
+#~ "Continued download failed on this file, which conflicts with `-c'.\n"
+#~ "Refusing to truncate existing file `%s'.\n"
+#~ "\n"
+#~ msgstr ""
+#~ "\n"
+#~ "Na p�eru�en� stahov�n� tohoto souboru nelze nav�zat. Bylo ov�em zad�no `-"
+#~ "c'.\n"
+#~ "Existuj�c� soubor `%s' tedy rad�ji nebude zkr�cen.\n"
+#~ "\n"
 
 # , c-format
-#: src/utils.c:94
-#, c-format
-msgid "%s: %s: Not enough memory.\n"
-msgstr "%s: %s: Nen� dost pam�ti.\n"
+#~ msgid " (%s to go)"
+#~ msgstr " (%s zb�v�)"
 
-#: src/utils.c:417
-msgid "Unknown/unsupported protocol"
-msgstr "Nezn�m�/nepodporovan� protokol"
+# , c-format
+#~ msgid "%s: BUG: unknown command `%s', value `%s'.\n"
+#~ msgstr "%s: CHYBA: Nezn�m� p��kaz `%s', hodnota `%s'.\n"
 
-#: src/utils.c:420
-msgid "Invalid port specification"
-msgstr "Neplatn� specifikace portu"
+#~ msgid "%s: %s: Cannot convert `%s' to an IP address.\n"
+#~ msgstr "%s: %s: `%s' nelze p�ev�st na IP adresu.\n"
 
-#: src/utils.c:423
-msgid "Invalid host name"
-msgstr "Neplatn� jm�no stroje"
+#~ msgid ""
+#~ "Startup:\n"
+#~ "  -V,  --version           display the version of Wget and exit.\n"
+#~ "  -h,  --help              print this help.\n"
+#~ "  -b,  --background        go to background after startup.\n"
+#~ "  -e,  --execute=COMMAND   execute a `.wgetrc'-style command.\n"
+#~ "\n"
+#~ msgstr ""
+#~ "Za��tek:\n"
+#~ "  -V,  --version           vyp�e informaci o verzi programu Wget a "
+#~ "skon��\n"
+#~ "  -h,  --help              vyp�e tuto n�pov�du\n"
+#~ "  -b,  --background        po spu�t�n� pokra�uje program v b�hu na "
+#~ "pozad�\n"
+#~ "  -e,  --execute=P��KAZ    prove�e p��kaz zadan� ve stylu `.wgetrc'\n"
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
+#~ "Protokolov�n� a vstupn� soubor:\n"
+#~ "  -o,  --output-file=SOUBOR   n�zev souboru s protokolem\n"
+#~ "  -a,  --append-output=SOUBOR protokol se p�ipoj� na konec tohoto "
+#~ "souboru\n"
+#~ "  -d,  --debug                vypisuje ladic� informace\n"
+#~ "  -q,  --quiet                nevypisuje v�bec nic\n"
+#~ "  -v,  --verbose              bude upov�dan� (implicitn� zapnuto)\n"
+#~ "  -nv, --non-verbose          vypisuje pouze nejd�le�it�j�� informace\n"
+#~ "  -i,  --input-file=SOUBOR    v�choz� URL odkazy na�te z tohoto souboru\n"
+#~ "  -F,  --force-html           soubor s URL je v HTML form�tu\n"
+#~ "  -B,  --base=URL             p�id� URL na za��tky relat. odkaz� p�i '-F -"
+#~ "i'\n"
+#~ "       --sslcertfile=SOUBOR   voliteln� certifik�t klienta\n"
+#~ "       --sslcertkey=SOUBOR    voliteln� soubor kl��� pro tento "
+#~ "certifik�t\n"
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
+#~ "Stahov�n�:\n"
+#~ "       --bind-address=ADRESA    pou�ij lok�ln� rozhran� s danou adresou "
+#~ "(IP nebo jm�no)\n"
+#~ "  -t,  --tries=��SLO            po�et pokus� st�hnout URL (0 "
+#~ "donekone�na)\n"
+#~ "  -O   --output-document=SOUBOR sta�en� dokumenty ukl�d� do tohoto "
+#~ "souboru\n"
+#~ "  -nc, --no-clobber             nep�episuje existuj�c� soubory\n"
+#~ "  -c,  --continue               pokra�uje ve stahov�n� ��ste�n� "
+#~ "p�enesen�ch dat\n"
+#~ "       --dot-style=STYL         nastav� zp�sob zobrazen� p�i stahov�n� "
+#~ "dat\n"
+#~ "  -N,  --timestamping           nestahuje star�� soubory (zapne �asov� "
+#~ "raz�tka)\n"
+#~ "  -S,  --server-response        vypisuje odpov�di serveru\n"
+#~ "       --spider                 nic nestahuje\n"
+#~ "  -T,  --timeout=SEKUNDY        nastav� timeout p�i �ten� na tuto "
+#~ "hodnotu\n"
+#~ "  -w,  --wait=PO�ET             p�ed ka�d�m stahov�n�m po�k� PO�ET "
+#~ "sekund\n"
+#~ "       --waitretry=PO�ET        �ek� 1...PO�ET sec p�ed nov�m pokusem o "
+#~ "sta�en�\n"
+#~ "  -Y,  --proxy=on/off           zapne p�enos p�es proxy (standardn� "
+#~ "`off')\n"
+#~ "  -Q,  --quota=BAJT�            nastav� limit objemu ulo�en�ch dat\n"
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
+#~ "Adres��e:\n"
+#~ "  -nd  --no-directories            nevytv��� adres��e\n"
+#~ "  -x,  --force-directories         v�dy vytv��� adres��e\n"
+#~ "  -nH, --no-host-directories       nevytv��� adres��e s adresou serveru\n"
+#~ "  -P,  --directory-prefix=PREFIX   ukl�d� data do PREFIX/...\n"
+#~ "       --cut-dirs=PO�ET            nevytv��� prvn�ch PO�ET podadres���\n"
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
+#~ "P�ep�na�e pro HTTP:\n"
+#~ "       --http-user=U�IVATEL  u�ivatelsk� jm�no pro autorizovan� HTTP "
+#~ "p�enos\n"
+#~ "       --http-passwd=HESLO   heslo pro autorizovan� HTTP p�enos \n"
+#~ "  -C,  --cache=on/off        povol� �i zak�e pou�it� vyrovn�vac� pam�ti "
+#~ "na\n"
+#~ "                             stran� serveru (implicitn� `on')\n"
+#~ "  -E,  --html-extension      ulo�� dokumenty typu `text/html' s p��ponou ."
+#~ "html\n"
+#~ "       --ignore-length       ignoruje pole `Content-Length' v hlavi�ce\n"
+#~ "       --header=�ET�ZEC      po�le �ET�ZEC serveru jako sou��st hlavi�ek\n"
+#~ "       --proxy-user=U�IVATEL jm�no u�ivatele vy�adovan� pro proxy p�enos\n"
+#~ "       --proxy-passwd=HESLO  heslo pro proxy p�enos\n"
+#~ "       --referer=URL         pos�l� v hlavi�cce HTTP po�adavku `Referer: "
+#~ "URL'\n"
+#~ "  -s,  --save-headers        do stahovan�ho souboru ulo�� i hlavi�ky "
+#~ "HTTP\n"
+#~ "  -U,  --user-agent=AGENT    m�sto identifikace `Wget/VERZE' pos�l� v "
+#~ "hlavi�ce \n"
+#~ "                             HTTP po�adavku identifika�n� �et�zec AGENT\n"
+#~ "       --no-http-keep-alive  vypne HTTP keep-alive (trval� spojen� se "
+#~ "serverem)\n"
+#~ "       --cookies=off         nebude pou��vat kol��ky (HTTP cookies)\n"
+#~ "       --load-cookies=SOUBOR p�ed sezen�m na�te kol��ky ze souboru "
+#~ "SOUBOR\n"
+#~ "       --save-cookies=SOUBOR po sezen� ulo�� kol��ky do souboru SOUBOR\n"
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
+#~ "P�ep�na�e pro FTP protokol:\n"
+#~ "  -nr, --dont-remove-listing  nema�e soubory `.listing' s obsahy "
+#~ "adres���\n"
+#~ "  -g,  --glob=on/off          zapne �i vypne expanzi �ol�k� ve jm�nech "
+#~ "soubor�\n"
+#~ "       --passive-ftp          pou�ije pasivn� m�d p�enosu dat\n"
+#~ "       --retr-symlinks        v rekurzivn�m m�du stahuje i symbolick� "
+#~ "odkazy na\n"
+#~ "                              soubory (nikoliv na adres��e)\n"
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
+#~ "Rekurzivn� stahov�n�:\n"
+#~ "  -r,  --recursive             rekurzivn� stahov�n� -- bu�te opatrn�!\n"
+#~ "  -l,  --level=��SLO           maxim�ln� hloubka rekurze (0 bez limitu)\n"
+#~ "       --delete-after          po p�enosu sma�e sta�en� soubory\n"
+#~ "  -k,  --convert-links         absolutn� URL p�eve�e na relativn�\n"
+#~ "  -K,  --backup-converted      p�ed konverz� ulo�� `X' jako `X.orig'\n"
+#~ "  -m,  --mirror                zapne p�ep�na�e vhodn� pro zrcadlen� dat \n"
+#~ "  -p,  --page-requisites       st�hne v�e nutn� pro zobrazen� HTML "
+#~ "str�nky\n"
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
+#~ "Omezen� p�i rekurzi:\n"
+#~ "  -A,  --accept=SEZNAM              seznam povolen�ch extenz� soubor�\n"
+#~ "  -R,  --reject=SEZNAM              seznam nepovolen�ch extenz� soubor�\n"
+#~ "  -D,  --domains=SEZNAM             seznam povolen�ch dom�n\n"
+#~ "       --exclude-domains=SEZNAM     seznam nepovolen�ch dom�n\n"
+#~ "       --follow-ftp                 n�sleduje FTP odkazy v HTML "
+#~ "dokumentech\n"
+#~ "       --follow-tags=LIST           seznam n�sledovan�ch HTML zna�ek \n"
+#~ "  -G,  --ignore-tags=LIST           seznam ignorovan�ch HTML zna�ek\n"
+#~ "  -H,  --span-hosts                 na��t� dokumenty i z ostatn�ch "
+#~ "server�\n"
+#~ "  -I,  --include-directories=SEZNAM seznam povolen�ch adres���\n"
+#~ "  -L,  --relative                   n�sleduje pouze relativn� odkazy\n"
+#~ "  -X,  --exclude-directories=SEZNAM seznam vylou�en�ch adres���\n"
+#~ "  -nh, --no-host-lookup             nevyhled�v� adresy v DNS\n"
+#~ "  -np, --no-parent                  nesestupuje do rodi�ovsk�ho adres��e\n"
+#~ "\n"
+
+# , fuzzy
+#~ msgid "%s: debug support not compiled in.\n"
+#~ msgstr "%s: program nebyl zkompilov�n s podporou pro lad�n�.\n"
 
 # , c-format
-#: src/utils.c:620
-#, c-format
-msgid "Failed to unlink symlink `%s': %s\n"
-msgstr "Nebylo mo�n� odstranit symbolick� odkaz `%s': %s\n"
+#~ msgid "%s: %s: invalid command\n"
+#~ msgstr "%s: %s: neplatn� p��kaz\n"
+
+# , c-format
+#~ msgid ""
+#~ "\n"
+#~ "CTRL+Break received, redirecting output to `%s'.\n"
+#~ "Execution continued in background.\n"
+#~ "You may stop Wget by pressing CTRL+ALT+DELETE.\n"
+#~ msgstr ""
+#~ "\n"
+#~ "Stiskli jste CTRL+Break, v�stup byl proto p�esm�rov�n do `%s'.\n"
+#~ "Program pokra�uje v b�hu na pozad�.\n"
+#~ "Wget lze zastavit stiskem CTRL+ALT+DELETE.\n"
+
+# , c-format
+#~ msgid "Starting WinHelp %s\n"
+#~ msgstr "Spou�t� se WinHelp %s\n"
+
+#~ msgid "Could not find proxy host.\n"
+#~ msgstr "Nelze naj�t proxy server.\n"
+
+# , c-format
+#~ msgid "%s: %s: Not enough memory.\n"
+#~ msgstr "%s: %s: Nen� dost pam�ti.\n"
+
+#~ msgid "Unknown/unsupported protocol"
+#~ msgstr "Nezn�m�/nepodporovan� protokol"
+
+#~ msgid "Invalid port specification"
+#~ msgstr "Neplatn� specifikace portu"
 
 #~ msgid "%s: Cannot determine user-id.\n"
 #~ msgstr "%s: Nelze zjistit ID u�ivatele.\n"
 
-#~ # , c-format
+# , c-format
 #~ msgid "%s: Warning: uname failed: %s\n"
 #~ msgstr "%s: Varov�n�: Vol�n� funkce \"uname\" skon�ilo chybou %s\n"
 
