#. No luck.
#. #### This message SUCKS.  We should see what was the
#. reason that nothing was retrieved.
#: src/ftp.c:1606
#, c-format
msgid "No matches on pattern `%s'.\n"
msgstr "Vzorku `%s' nic neodpov�d�.\n"

# , c-format
#: src/ftp.c:1671
#, c-format
msgid "Wrote HTML-ized index to `%s' [%ld].\n"
msgstr "V�pis adres��e v HTML form�tu byl zaps�n do `%s' [%ld].\n"

# , c-format
#: src/ftp.c:1676
#, c-format
msgid "Wrote HTML-ized index to `%s'.\n"
msgstr "V�pis adres��e v HTML form�tu byl zaps�n do `%s'.\n"

# , c-format
#: src/getopt.c:454
#, c-format
msgid "%s: option `%s' is ambiguous\n"
msgstr "%s: p�ep�na� `%s' nen� jednozna�n�\n"

# , c-format
#: src/getopt.c:478
#, c-format
msgid "%s: option `--%s' doesn't allow an argument\n"
msgstr "%s: p�ep�na� `--%s' nem� argument\n"

# , c-format
#: src/getopt.c:483
#, c-format
msgid "%s: option `%c%s' doesn't allow an argument\n"
msgstr "%s: p�ep�na� `%c%s' nem� argument\n"

# , c-format
#: src/getopt.c:498
#, c-format
msgid "%s: option `%s' requires an argument\n"
msgstr "%s: p�ep�na� `%s' vy�aduje argument\n"

# , c-format
#. --option
#: src/getopt.c:528
#, c-format
msgid "%s: unrecognized option `--%s'\n"
msgstr "%s: nezn�m� p�ep�na� `--%s'\n"

# , c-format
#. +option or -option
#: src/getopt.c:532
#, c-format
msgid "%s: unrecognized option `%c%s'\n"
msgstr "%s: nezn�m� p�ep�na� `%c%s'\n"

# , c-format
#. 1003.2 specifies the format of this message.
#: src/getopt.c:563
#, c-format
msgid "%s: illegal option -- %c\n"
msgstr "%s: nep��pustn� p�ep�na� -- %c\n"

# , c-format
#. 1003.2 specifies the format of this message.
#: src/getopt.c:602
#, c-format
msgid "%s: option requires an argument -- %c\n"
msgstr "%s: p�ep�na� vy�aduje argument -- %c\n"

#: src/host.c:374
msgid "Host not found"
msgstr "Po��ta� nebyl nalezen"

#: src/host.c:376
msgid "Unknown error"
msgstr "Nezn�m� chyba"

#. this is fatal
#: src/http.c:555
msgid "Failed to set up an SSL context\n"
msgstr "Nebylo mo�n� nastavit SSL kontext\n"

#: src/http.c:561
#, c-format
msgid "Failed to load certificates from %s\n"
msgstr "SSL certifik�ty nebylo mo�n� ze souboru `%s' na��st.\n"

#: src/http.c:565 src/http.c:573
msgid "Trying without the specified certificate\n"
msgstr "Program se pokus� pokra�ovat bez zadan�ho certifik�tu.\n"

#: src/http.c:569
#, c-format
msgid "Failed to get certificate key from %s\n"
msgstr "Ze souboru `%s' nebylo mo�n� kl�� k certifik�tu na��st.\n\n"

#: src/http.c:663 src/http.c:1593
msgid "Unable to establish SSL connection.\n"
msgstr "Nebylo mo�n� nav�zat SSL spojen�.\n"

# , c-format
#: src/http.c:671
#, c-format
msgid "Reusing connection to %s:%hu.\n"
msgstr "Program vyu�ije existuj�c� spojen� s %s:%hu.\n"

#: src/http.c:861
#, c-format
msgid "Failed writing HTTP request: %s.\n"
msgstr "Nebylo mo�n� odeslat HTTP po�adavek: %s.\n"

# , c-format
#: src/http.c:866
#, c-format
msgid "%s request sent, awaiting response... "
msgstr "%s po�adavek odesl�n, program �ek� na odpov�� ... "

#: src/http.c:910
msgid "End of file while parsing headers.\n"
msgstr "Hlavi�ka nen� �pln�.\n"

# , c-format
#: src/http.c:920
#, c-format
msgid "Read error (%s) in headers.\n"
msgstr "Chyba (%s) p�i �ten� hlavi�ek.\n"

#: src/http.c:959
msgid "No data received"
msgstr "Nep�i�la ��dn� data"

#: src/http.c:961
msgid "Malformed status line"
msgstr "Odpov�� serveru m� zkomolen� stavov� ��dek"

#: src/http.c:966
msgid "(no description)"
msgstr "(��dn� popis)"

#: src/http.c:1089
msgid "Authorization failed.\n"
msgstr "Autorizace selhala.\n"

#: src/http.c:1096
msgid "Unknown authentication scheme.\n"
msgstr "Server po�aduje nezn�m� zp�sob autentifikace.\n"

# , c-format
#: src/http.c:1136
#, c-format
msgid "Location: %s%s\n"
msgstr "P�esm�rov�no na: %s%s\n"

#: src/http.c:1137 src/http.c:1269
msgid "unspecified"
msgstr "neud�no"

#: src/http.c:1138
msgid " [following]"
msgstr " [n�sleduji]"

#: src/http.c:1200
msgid "\n    The file is already fully retrieved; nothing to do.\n\n"
msgstr "\n    Soubor je ji� pln� p�enesen, nebude se nic d�lat.\n\n"

#: src/http.c:1216
#, c-format
msgid ""
"\n"
"Continued download failed on this file, which conflicts with `-c'.\n"
"Refusing to truncate existing file `%s'.\n"
"\n"
msgstr ""
"\n"
"Na p�eru�en� stahov�n� tohoto souboru nelze nav�zat. Bylo ov�em zad�no `-c'.\n"
"Existuj�c� soubor `%s' tedy rad�ji nebude zkr�cen.\n"
"\n"

#. No need to print this output if the body won't be
#. downloaded at all, or if the original server response is
#. printed.
#: src/http.c:1259
msgid "Length: "
msgstr "D�lka: "

# , c-format
#: src/http.c:1264
#, c-format
msgid " (%s to go)"
msgstr " (%s zb�v�)"

#: src/http.c:1269
msgid "ignored"
msgstr "je ignorov�na"

#: src/http.c:1399
msgid "Warning: wildcards not supported in HTTP.\n"
msgstr "Varov�n�: HTTP nepodporuje �ol�kov� znaky.\n"

# , c-format
#. If opt.noclobber is turned on and file already exists, do not
#. retrieve the file
#: src/http.c:1417
#, c-format
msgid "File `%s' already there, will not retrieve.\n"
msgstr "Soubor `%s' je ji� zde a nebude se znovu p�en�et.\n"

# , c-format
#: src/http.c:1585
#, c-format
msgid "Cannot write to `%s' (%s).\n"
msgstr "Nelze zapsat do `%s' (%s).\n"

# , c-format
#: src/http.c:1602
#, c-format
msgid "ERROR: Redirection (%d) without location.\n"
msgstr "CHYBA: P�esm�rov�n� (%d) bez udan� nov� adresy.\n"

# , c-format
#: src/http.c:1630
#, c-format
msgid "%s ERROR %d: %s.\n"
msgstr "%s CHYBA %d: %s.\n"

#: src/http.c:1642
msgid "Last-modified header missing -- time-stamps turned off.\n"
msgstr ""
"Nelze pou��t �asov� raz�tka (`time-stamps'), proto�e v odpov�di serveru \n"
"sch�z� hlavi�ka \"Last-modified\".\n"

#: src/http.c:1650
msgid "Last-modified header invalid -- time-stamp ignored.\n"
msgstr ""
"�asov� raz�tko souboru (`time-stamp') bude ignorov�no, proto�e hlavi�ka \n"
"\"Last-modified\" obsahuje neplatn� �daje.\n"

#: src/http.c:1673
#, c-format
msgid "Server file no newer than local file `%s' -- not retrieving.\n\n"
msgstr "Lok�ln� soubor `%s' nen� star��, ne� vzd�len� soubor, a nen� jej t�eba stahovat.\n\n"

# , c-format
#: src/http.c:1680
#, c-format
msgid "The sizes do not match (local %ld) -- retrieving.\n"
msgstr "Velikosti se neshoduj� (lok�ln� %ld), soubor je t�eba st�hnout.\n"

#: src/http.c:1684
msgid "Remote file is newer, retrieving.\n"
msgstr "Lok�ln� soubor je star�� a vzd�len� soubor se proto bude p�en�et.\n"

# , c-format
#: src/http.c:1728
#, c-format
msgid "%s (%s) - `%s' saved [%ld/%ld]\n\n"
msgstr "%s (%s) - `%s' ulo�eno [%ld/%ld]\n\n"

# , c-format
#: src/http.c:1774
#, c-format
msgid "%s (%s) - Connection closed at byte %ld. "
msgstr "%s (%s) - Spojen� ukon�eno na bajtu %ld. "

# , c-format
#: src/http.c:1782
#, c-format
msgid "%s (%s) - `%s' saved [%ld/%ld])\n\n"
msgstr "%s (%s) - `%s' ulo�eno [%ld/%ld])\n\n"

# , c-format
#: src/http.c:1801
#, c-format
msgid "%s (%s) - Connection closed at byte %ld/%ld. "
msgstr "%s (%s) - Spojen� ukon�eno na bajtu %ld/%ld. "

# , c-format
#: src/http.c:1812
#, c-format
msgid "%s (%s) - Read error at byte %ld (%s)."
msgstr "%s (%s) - Chyba p�i �ten� dat na bajtu %ld (%s)."

# , c-format
#: src/http.c:1820
#, c-format
msgid "%s (%s) - Read error at byte %ld/%ld (%s). "
msgstr "%s (%s) - Chyba p�i �ten� dat na bajtu %ld/%ld (%s). "

# , c-format
#: src/init.c:349 src/netrc.c:267
#, c-format
msgid "%s: Cannot read %s (%s).\n"
msgstr "%s: Nelze p�e��st %s (%s).\n"

# , c-format
#: src/init.c:367 src/init.c:373
#, c-format
msgid "%s: Error in %s at line %d.\n"
msgstr "%s: Chyba v %s na ��dku %d.\n"

# , c-format
#: src/init.c:405
#, c-format
msgid "%s: Warning: Both system and user wgetrc point to `%s'.\n"
msgstr "%s: Varov�n�: Glob�ln� i u�ivatelsk� wgetrc jsou shodn� ulo�eny v `%s'.\n"

# , c-format
#: src/init.c:497
#, c-format
msgid "%s: BUG: unknown command `%s', value `%s'.\n"
msgstr "%s: CHYBA: Nezn�m� p��kaz `%s', hodnota `%s'.\n"

#: src/init.c:529
#, c-format
msgid "%s: %s: Cannot convert `%s' to an IP address.\n"
msgstr "%s: %s: `%s' nelze p�ev�st na IP adresu.\n"

# , c-format
#: src/init.c:559
#, c-format
msgid "%s: %s: Please specify on or off.\n"
msgstr "%s: %s: Zadejte pros�m `on' (zapnuto) nebo `off' (vypnuto).\n"

# , c-format
#: src/init.c:603
#, c-format
msgid "%s: %s: Please specify always, on, off, or never.\n"
msgstr "%s: %s: Zadejte pros�m `always' (v�dy), `on' (zapnuto), `off' (vypnuto), nebo `never' (nikdy).\n"

# , c-format
#: src/init.c:622 src/init.c:919 src/init.c:941 src/init.c:1005
#, c-format
msgid "%s: %s: Invalid specification `%s'.\n"
msgstr "%s: %s: Neplatn� specifikace `%s'\n"

# , c-format
#: src/init.c:775 src/init.c:797 src/init.c:819 src/init.c:845
#, c-format
msgid "%s: Invalid specification `%s'\n"
msgstr "%s: Neplatn� specifikace `%s'\n"

# , c-format
#: src/main.c:120
#, c-format
msgid "Usage: %s [OPTION]... [URL]...\n"
msgstr "Pou�it�: %s [P�EP�NA�]... [URL]...\n"

# , c-format
#: src/main.c:128
#, c-format
msgid "GNU Wget %s, a non-interactive network retriever.\n"
msgstr "GNU Wget %s, program pro neinteraktivn� stahov�n� soubor�.\n"

#. Had to split this in parts, so the #@@#%# Ultrix compiler and cpp
#. don't bitch.  Also, it makes translation much easier.
#: src/main.c:133
msgid "\nMandatory arguments to long options are mandatory for short options too.\n\n"
msgstr ""
"\n"
"Argumenty, povinn� u dlouh�ch p�ep�na��, jsou povinn� i pro kr�tk� verze\n"
"p�ep�na��.\n"
"\n"

#: src/main.c:137
msgid ""
"Startup:\n"
"  -V,  --version           display the version of Wget and exit.\n"
"  -h,  --help              print this help.\n"
"  -b,  --background        go to background after startup.\n"
"  -e,  --execute=COMMAND   execute a `.wgetrc'-style command.\n"
"\n"
msgstr ""
"Za��tek:\n"
"  -V,  --version           vyp��e informaci o verzi programu Wget a skon��\n"
"  -h,  --help              vyp��e tuto n�pov�du\n"
"  -b,  --background        po spu�t�n� pokra�uje program v b�hu na pozad�\n"
"  -e,  --execute=P��KAZ    prove�e p��kaz zadan� ve stylu `.wgetrc'\n"
"\n"

# , fuzzy
#: src/main.c:144
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
"Protokolov�n� a vstupn� soubor:\n"
"  -o,  --output-file=SOUBOR   n�zev souboru s protokolem\n"
"  -a,  --append-output=SOUBOR protokol se p�ipoj� na konec tohoto souboru\n"
"  -d,  --debug                vypisuje ladic� informace\n"
"  -q,  --quiet                nevypisuje v�bec nic\n"
"  -v,  --verbose              bude upov�dan� (implicitn� zapnuto)\n"
"  -nv, --non-verbose          vypisuje pouze nejd�le�it�j�� informace\n"
"  -i,  --input-file=SOUBOR    v�choz� URL odkazy na�te z tohoto souboru\n"
"  -F,  --force-html           soubor s URL je v HTML form�tu\n"
"  -B,  --base=URL             p�id� URL na za��tky relat. odkaz� p�i '-F -i'\n"
"       --sslcertfile=SOUBOR   voliteln� certifik�t klienta\n"
"       --sslcertkey=SOUBOR    voliteln� soubor kl��� pro tento certifik�t\n"
"\n"

# , fuzzy
#: src/main.c:158
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
"Stahov�n�:\n"
"       --bind-address=ADRESA    pou�ij lok�ln� rozhran� s danou adresou (IP nebo jm�no)\n"
"  -t,  --tries=��SLO            po�et pokus� st�hnout URL (0 donekone�na)\n"
"  -O   --output-document=SOUBOR sta�en� dokumenty ukl�d� do tohoto souboru\n"
"  -nc, --no-clobber             nep�episuje existuj�c� soubory\n"
"  -c,  --continue               pokra�uje ve stahov�n� ��ste�n� p�enesen�ch dat\n"
"       --dot-style=STYL         nastav� zp�sob zobrazen� p�i stahov�n� dat\n"
"  -N,  --timestamping           nestahuje star�� soubory (zapne �asov� raz�tka)\n"
"  -S,  --server-response        vypisuje odpov�di serveru\n"
"       --spider                 nic nestahuje\n"
"  -T,  --timeout=SEKUNDY        nastav� timeout p�i �ten� na tuto hodnotu\n"
"  -w,  --wait=PO�ET             p�ed ka�d�m stahov�n�m po�k� PO�ET sekund\n"
"       --waitretry=PO�ET        �ek� 1...PO�ET sec p�ed nov�m pokusem o sta�en�\n"
"  -Y,  --proxy=on/off           zapne p�enos p�es proxy (standardn� `off')\n"
"  -Q,  --quota=BAJT�            nastav� limit objemu ulo�en�ch dat\n"
"\n"

# , fuzzy
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
"Adres��e:\n"
"  -nd  --no-directories            nevytv��� adres��e\n"
"  -x,  --force-directories         v�dy vytv��� adres��e\n"
"  -nH, --no-host-directories       nevytv��� adres��e s adresou serveru\n"
"  -P,  --directory-prefix=PREFIX   ukl�d� data do PREFIX/...\n"
"       --cut-dirs=PO�ET            nevytv��� prvn�ch PO�ET podadres���\n"
"\n"

# , fuzzy
#: src/main.c:183
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
"P�ep�na�e pro HTTP:\n"
"       --http-user=U�IVATEL  u�ivatelsk� jm�no pro autorizovan� HTTP p�enos\n"
"       --http-passwd=HESLO   heslo pro autorizovan� HTTP p�enos \n"
"  -C,  --cache=on/off        povol� �i zak�e pou�it� vyrovn�vac� pam�ti na\n"
"                             stran� serveru (implicitn� `on')\n"
"  -E,  --html-extension      ulo�� dokumenty typu `text/html' s p��ponou .html\n"
"       --ignore-length       ignoruje pole `Content-Length' v hlavi�ce\n"
"       --header=�ET�ZEC      po�le �ET�ZEC serveru jako sou��st hlavi�ek\n"
"       --proxy-user=U�IVATEL jm�no u�ivatele vy�adovan� pro proxy p�enos\n"
"       --proxy-passwd=HESLO  heslo pro proxy p�enos\n"
"       --referer=URL         pos�l� v hlavi�cce HTTP po�adavku `Referer: URL'\n"
"  -s,  --save-headers        do stahovan�ho souboru ulo�� i hlavi�ky HTTP\n"
"  -U,  --user-agent=AGENT    m�sto identifikace `Wget/VERZE' pos�l� v hlavi�ce \n"
"                             HTTP po�adavku identifika�n� �et�zec AGENT\n"
"       --no-http-keep-alive  vypne HTTP keep-alive (trval� spojen� se serverem)\n"
"       --cookies=off         nebude pou��vat kol��ky (HTTP cookies)\n"
"       --load-cookies=SOUBOR p�ed sezen�m na�te kol��ky ze souboru SOUBOR\n"
"       --save-cookies=SOUBOR po sezen� ulo�� kol��ky do souboru SOUBOR\n"
"\n"

# , fuzzy
#: src/main.c:201
msgid ""
"FTP options:\n"
"  -nr, --dont-remove-listing   don't remove `.listing' files.\n"
"  -g,  --glob=on/off           turn file name globbing on or off.\n"
"       --passive-ftp           use the \"passive\" transfer mode.\n"
"       --retr-symlinks         when recursing, get linked-to files (not dirs).\n"
"\n"
msgstr ""
"P�ep�na�e pro FTP protokol:\n"
"  -nr, --dont-remove-listing  nema�e soubory `.listing' s obsahy adres���\n"
"  -g,  --glob=on/off          zapne �i vypne expanzi �ol�k� ve jm�nech soubor�\n"
"       --passive-ftp          pou�ije pasivn� m�d p�enosu dat\n"
"       --retr-symlinks        v rekurzivn�m m�du stahuje i symbolick� odkazy na\n"
"                              soubory (nikoliv na adres��e)\n"

#: src/main.c:208
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
"Rekurzivn� stahov�n�:\n"
"  -r,  --recursive             rekurzivn� stahov�n� -- bu�te opatrn�!\n"
"  -l,  --level=��SLO           maxim�ln� hloubka rekurze (0 bez limitu)\n"
"       --delete-after          po p�enosu sma�e sta�en� soubory\n"
"  -k,  --convert-links         absolutn� URL p�eve�e na relativn�\n"
"  -K,  --backup-converted      p�ed konverz� ulo�� `X' jako `X.orig'\n"
"  -m,  --mirror                zapne p�ep�na�e vhodn� pro zrcadlen� dat \n"
"  -p,  --page-requisites       st�hne v�e nutn� pro zobrazen� HTML str�nky\n"

# , fuzzy
#: src/main.c:218
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
"Omezen� p�i rekurzi:\n"
"  -A,  --accept=SEZNAM              seznam povolen�ch extenz� soubor�\n"
"  -R,  --reject=SEZNAM              seznam nepovolen�ch extenz� soubor�\n"
"  -D,  --domains=SEZNAM             seznam povolen�ch dom�n\n"
"       --exclude-domains=SEZNAM     seznam nepovolen�ch dom�n\n"
"       --follow-ftp                 n�sleduje FTP odkazy v HTML dokumentech\n"
"       --follow-tags=LIST           seznam n�sledovan�ch HTML zna�ek \n"
"  -G,  --ignore-tags=LIST           seznam ignorovan�ch HTML zna�ek\n"
"  -H,  --span-hosts                 na��t� dokumenty i z ostatn�ch server�\n"
"  -I,  --include-directories=SEZNAM seznam povolen�ch adres���\n"
"  -L,  --relative                   n�sleduje pouze relativn� odkazy\n"
"  -X,  --exclude-directories=SEZNAM seznam vylou�en�ch adres���\n"
"  -nh, --no-host-lookup             nevyhled�v� adresy v DNS\n"
"  -np, --no-parent                  nesestupuje do rodi�ovsk�ho adres��e\n"
"\n"

# , fuzzy
#: src/main.c:234
msgid "Mail bug reports and suggestions to <bug-wget@gnu.org>.\n"
msgstr ""
"Zpr�vy o chyb�ch a n�vrhy na vylep�en� programu zas�lejte na adresu\n"
"<bug-wget@gnu.org> (pouze anglicky).\n"
"Koment��e k �esk�mu p�ekladu zas�lejte na adresu <cs@li.org>. \n"

# , fuzzy
#: src/main.c:420
#, c-format
msgid "%s: debug support not compiled in.\n"
msgstr "%s: program nebyl zkompilov�n s podporou pro lad�n�.\n"

#: src/main.c:472
msgid ""
"Copyright (C) 1995, 1996, 1997, 1998, 2000, 2001 Free Software Foundation, Inc.\n"
"This program is distributed in the hope that it will be useful,\n"
"but WITHOUT ANY WARRANTY; without even the implied warranty of\n"
"MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the\n"
"GNU General Public License for more details.\n"
msgstr ""
"Copyright (C) 1995, 1996, 1997, 1998, 2000, 2001 Free Software Foundation, Inc.\n"
"Tento program je ���en v nad�ji, �e bude u�ite�n�, av�ak\n"
"BEZ JAK�KOLI Z�RUKY; neposkytuj� se ani odvozen� z�ruky PRODEJNOSTI \n"
"anebo VHODNOSTI PRO UR�IT� ��EL. Dal�� podrobnosti hledejte \n"
"v Obecn� ve�ejn� licenci GNU.\n"

#: src/main.c:478
msgid "\nOriginally written by Hrvoje Niksic <hniksic@arsdigita.com>.\n"
msgstr "\nP�vodn�m autorem tohto programu je Hrvoje Nik�i� <hniksic@arsdigita.com>.\n"

# , c-format
#: src/main.c:569
#, c-format
msgid "%s: %s: invalid command\n"
msgstr "%s: %s: neplatn� p��kaz\n"

# , c-format
#: src/main.c:625
#, c-format
msgid "%s: illegal option -- `-n%c'\n"
msgstr "%s: nep��pustn� p�ep�na� -- `-n%c'\n"

# , c-format
#. #### Something nicer should be printed here -- similar to the
#. pre-1.5 `--help' page.
#: src/main.c:628 src/main.c:670 src/main.c:728
#, c-format
msgid "Try `%s --help' for more options.\n"
msgstr "P��kaz `%s --help' vyp��e v�znam platn�ch p�ep�na��.\n"

#: src/main.c:708
msgid "Can't be verbose and quiet at the same time.\n"
msgstr "Program nem��e b�t upov�dan� a zitcha najednou.\n"

#: src/main.c:714
msgid "Can't timestamp and not clobber old files at the same time.\n"
msgstr "Nelze pou��vat �asov� raz�tka a nemazat p�itom star� soubory.\n"

#. No URL specified.
#: src/main.c:723
#, c-format
msgid "%s: missing URL\n"
msgstr "%s: chyb� URL\n"

# , c-format
#: src/main.c:825
#, c-format
msgid "No URLs found in %s.\n"
msgstr "V souboru `%s' nebyla nalezena ��dn� URL.\n"

# , c-format
#: src/main.c:834
#, c-format
msgid ""
"\n"
