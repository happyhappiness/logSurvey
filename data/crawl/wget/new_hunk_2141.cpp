# Czech translations for GNU wget
# Copyright (C) 1998, 2000, 2001 Free Software Foundation, Inc.
# Jan Prikryl <prikryl@acm.org>, 1998, 2000, 2001
# Petr Pisar <petr.pisar@atlas.cz>, 2007
#
msgid ""
msgstr ""
"Project-Id-Version: wget 1.11-b2363\n"
"Report-Msgid-Bugs-To: wget@sunsite.dk\n"
"POT-Creation-Date: 2007-10-22 11:58-0700\n"
"PO-Revision-Date: 2007-09-04 14:06+0200\n"
"Last-Translator: Petr Pisar <petr.pisar@atlas.cz>\n"
"Language-Team: Czech <translation-team-cs@lists.sourceforge.net>\n"
"MIME-Version: 1.0\n"
"Content-Type: text/plain; charset=UTF-8\n"
"Content-Transfer-Encoding: 8-bit\n"
"Plural-Forms: nplurals=3; plural=(n%10==1 && n%100!=11 ? 0 : n%10>=2 && n%"
"10<=4 && (n%100<10 || n%100>=20) ? 1 : 2);\n"

#: lib/getopt.c:530 lib/getopt.c:546
#, c-format
msgid "%s: option `%s' is ambiguous\n"
msgstr "%s: přepínač „%s“ není jednoznačný\n"

#: lib/getopt.c:579 lib/getopt.c:583
#, c-format
msgid "%s: option `--%s' doesn't allow an argument\n"
msgstr "%s: přepínač „--%s“ nemá argument\n"

#: lib/getopt.c:592 lib/getopt.c:597
#, c-format
msgid "%s: option `%c%s' doesn't allow an argument\n"
msgstr "%s: přepínač „%c%s“ nemá argument\n"

#: lib/getopt.c:640 lib/getopt.c:659 lib/getopt.c:975 lib/getopt.c:994
#, c-format
msgid "%s: option `%s' requires an argument\n"
msgstr "%s: přepínač „%s“ vyžaduje argument\n"

#: lib/getopt.c:697 lib/getopt.c:700
#, c-format
msgid "%s: unrecognized option `--%s'\n"
msgstr "%s: neznámý přepínač „--%s“\n"

#: lib/getopt.c:708 lib/getopt.c:711
#, c-format
msgid "%s: unrecognized option `%c%s'\n"
msgstr "%s: neznámý přepínač „%c%s“\n"

#: lib/getopt.c:763 lib/getopt.c:766
#, c-format
msgid "%s: illegal option -- %c\n"
msgstr "%s: nepřípustný přepínač – %c\n"

#: lib/getopt.c:772 lib/getopt.c:775
#, c-format
msgid "%s: invalid option -- %c\n"
msgstr "%s: chybný přepínač – %c\n"

#: lib/getopt.c:827 lib/getopt.c:843 lib/getopt.c:1047 lib/getopt.c:1065
#, c-format
msgid "%s: option requires an argument -- %c\n"
msgstr "%s: přepínač vyžaduje argument – %c\n"

#: lib/getopt.c:896 lib/getopt.c:912
#, c-format
msgid "%s: option `-W %s' is ambiguous\n"
msgstr "%s: přepínač „-W %s“ není jednoznačný\n"

#: lib/getopt.c:936 lib/getopt.c:954
#, c-format
msgid "%s: option `-W %s' doesn't allow an argument\n"
msgstr "%s: přepínač „-W %s“ nemá argument\n"

#: src/connect.c:194
#, c-format
msgid "%s: unable to resolve bind address `%s'; disabling bind.\n"
msgstr ""
"%s: adresu „%s“ pro přilepení nelze zjistit, vypínám přilepování (bind(2)).\n"

#: src/connect.c:266
#, c-format
msgid "Connecting to %s|%s|:%d... "
msgstr "Navazuje se spojení s %s|%s|:%d… "

#: src/connect.c:269
#, c-format
msgid "Connecting to %s:%d... "
msgstr "Navazuje se spojení s %s:%d… "

#: src/connect.c:329
msgid "connected.\n"
msgstr "spojeno.\n"

#: src/connect.c:341 src/host.c:752 src/host.c:781
#, c-format
msgid "failed: %s.\n"
msgstr "nezdařilo se: %s.\n"

#: src/connect.c:365 src/http.c:1628
#, fuzzy, c-format
msgid "%s: unable to resolve host address `%s'\n"
msgstr ""
"%s: adresu „%s“ pro přilepení nelze zjistit, vypínám přilepování (bind(2)).\n"

#: src/convert.c:169
#, c-format
msgid "Converted %d files in %s seconds.\n"
msgstr "%d souborů převedeno za %s sekund.\n"

#: src/convert.c:194
#, c-format
msgid "Converting %s... "
msgstr "Převádí se %s… "

#: src/convert.c:207
msgid "nothing to do.\n"
msgstr "nic není potřeba převádět.\n"

#: src/convert.c:215 src/convert.c:239
#, c-format
msgid "Cannot convert links in %s: %s\n"
msgstr "Nelze převést odkazy v %s: %s\n"

#: src/convert.c:230
#, c-format
msgid "Unable to delete `%s': %s\n"
msgstr "Nebylo možné odstranit „%s“: %s\n"

#: src/convert.c:439
#, c-format
msgid "Cannot back up %s as %s: %s\n"
msgstr "Nelze zálohovat %s jako %s: %s\n"

#: src/cookies.c:442
#, c-format
msgid "Syntax error in Set-Cookie: %s at position %d.\n"
msgstr "Syntaktická chyba v hlavičce Set-Cookie: %s na pozici %d.\n"

#: src/cookies.c:684
#, c-format
msgid "Cookie coming from %s attempted to set domain to %s\n"
msgstr "Cookie přiševši z %s se pokusila nastavit doménu na %s\n"

#: src/cookies.c:1131 src/cookies.c:1249
#, c-format
msgid "Cannot open cookies file `%s': %s\n"
msgstr "Nelze otevřít soubor s cookie „%s“: %s\n"

#: src/cookies.c:1286
#, c-format
msgid "Error writing to `%s': %s\n"
msgstr "Při zápisu do „%s“ nastala chyba: %s.\n"

#: src/cookies.c:1289
#, c-format
msgid "Error closing `%s': %s\n"
msgstr "Při uzavírání „%s“ nastala chyba: %s\n"

#: src/ftp-ls.c:835
msgid "Unsupported listing type, trying Unix listing parser.\n"
msgstr "Nepodporovaný typ výpisu, použije se Unixový parser.\n"

#: src/ftp-ls.c:881 src/ftp-ls.c:883
#, c-format
msgid "Index of /%s on %s:%d"
msgstr "Obsah /%s na %s:%d"

#: src/ftp-ls.c:906
#, c-format
msgid "time unknown       "
msgstr "čas neznámý        "

#: src/ftp-ls.c:910
#, c-format
msgid "File        "
msgstr "Soubor      "

#: src/ftp-ls.c:913
#, c-format
msgid "Directory   "
msgstr "Adresář     "

#: src/ftp-ls.c:916
#, c-format
msgid "Link        "
msgstr "Sym. odkaz  "

#: src/ftp-ls.c:919
#, c-format
msgid "Not sure    "
msgstr "Neznámý typ "

#: src/ftp-ls.c:937
#, c-format
msgid " (%s bytes)"
msgstr " (%s bajtů)"

#: src/ftp.c:213
#, c-format
msgid "Length: %s"
msgstr "Délka: %s"

#: src/ftp.c:219 src/http.c:2173
#, c-format
msgid ", %s (%s) remaining"
msgstr ", %s (%s) zbývá"

#: src/ftp.c:223 src/http.c:2177
#, c-format
msgid ", %s remaining"
msgstr ", %s zbývá"

#: src/ftp.c:226
msgid " (unauthoritative)\n"
msgstr " (není směrodatné)\n"

#: src/ftp.c:302
#, c-format
msgid "Logging in as %s ... "
msgstr "Probíhá přihlašování jako %s… "

#: src/ftp.c:315 src/ftp.c:361 src/ftp.c:390 src/ftp.c:442 src/ftp.c:554
#: src/ftp.c:600 src/ftp.c:629 src/ftp.c:686 src/ftp.c:747 src/ftp.c:807
#: src/ftp.c:854
msgid "Error in server response, closing control connection.\n"
msgstr ""
"Řídicí spojení bude ukončeno, protože server odpověděl chybovým hlášením.\n"

#: src/ftp.c:322
msgid "Error in server greeting.\n"
msgstr "Úvodní odpověď serveru je chybná.\n"

#: src/ftp.c:329 src/ftp.c:450 src/ftp.c:562 src/ftp.c:637 src/ftp.c:696
#: src/ftp.c:757 src/ftp.c:817 src/ftp.c:864
msgid "Write failed, closing control connection.\n"
msgstr "Rídicí spojení bude ukončeno, protože nelze zapsat data.\n"

#: src/ftp.c:335
msgid "The server refuses login.\n"
msgstr "Server odmítá přihlášení.\n"

#: src/ftp.c:341
msgid "Login incorrect.\n"
msgstr "Chyba při přihlášení.\n"

#: src/ftp.c:347
msgid "Logged in!\n"
msgstr "Přihlášeno!\n"

#: src/ftp.c:369
msgid "Server error, can't determine system type.\n"
msgstr ""
"Nelze zjistit typ vzdáleného operačního systému, protože server odpověděl "
"chybovým hlášením.\n"

#: src/ftp.c:378 src/ftp.c:673 src/ftp.c:730 src/ftp.c:773
msgid "done.    "
msgstr "hotovo.  "

#: src/ftp.c:430 src/ftp.c:579 src/ftp.c:612 src/ftp.c:837 src/ftp.c:883
msgid "done.\n"
msgstr "hotovo.\n"

#: src/ftp.c:457
#, c-format
msgid "Unknown type `%c', closing control connection.\n"
msgstr ""
"Rídicí spojení bude ukončeno, protože je požadován neznámý typ přenosu „%"
"c“.\n"

#: src/ftp.c:469
msgid "done.  "
msgstr "hotovo."

#: src/ftp.c:475
msgid "==> CWD not needed.\n"
msgstr "==> CWD není potřeba.\n"

#: src/ftp.c:568
#, c-format
msgid ""
"No such directory `%s'.\n"
"\n"
msgstr ""
"Adresář „%s“ neexistuje.\n"
"\n"

#: src/ftp.c:583
msgid "==> CWD not required.\n"
msgstr "==> CWD není potřeba.\n"

#: src/ftp.c:643
msgid "Cannot initiate PASV transfer.\n"
msgstr "Nelze spustit pasivní přenos dat.\n"

#: src/ftp.c:647
msgid "Cannot parse PASV response.\n"
msgstr "Odpověď na PASV není pochopitelná.\n"

#: src/ftp.c:664
#, c-format
msgid "couldn't connect to %s port %d: %s\n"
msgstr "s %s na portu %d se nelze spojit: %s\n"

#: src/ftp.c:712
#, c-format
msgid "Bind error (%s).\n"
msgstr "Chyba při přilepování (bind) (%s).\n"

#: src/ftp.c:718
msgid "Invalid PORT.\n"
msgstr "Neplatný PORT.\n"

#: src/ftp.c:764
msgid ""
"\n"
"REST failed, starting from scratch.\n"
msgstr ""
"\n"
"Příkaz REST selhal, přenos začne od začátku souboru.\n"

#: src/ftp.c:825
#, c-format
msgid ""
"No such file `%s'.\n"
"\n"
msgstr ""
"Soubor „%s“ neexistuje.\n"
"\n"

#: src/ftp.c:872
#, c-format
msgid ""
"No such file or directory `%s'.\n"
"\n"
msgstr ""
"Soubor či adresář „%s“ neexistuje.\n"
"\n"

#: src/ftp.c:934 src/http.c:2235
#, c-format
msgid "%s has sprung into existence.\n"
msgstr "%s se objevil.\n"

#: src/ftp.c:986
#, c-format
msgid "%s: %s, closing control connection.\n"
msgstr "%s: %s, řídicí spojení bude ukončeno.\n"

#: src/ftp.c:995
#, c-format
msgid "%s (%s) - Data connection: %s; "
msgstr "%s (%s) – Datové spojení: %s; "

#: src/ftp.c:1010
msgid "Control connection closed.\n"
msgstr "Řídicí spojení bylo ukončeno.\n"

#: src/ftp.c:1028
msgid "Data transfer aborted.\n"
msgstr "Přenos dat byl předčasně ukončen.\n"

#: src/ftp.c:1096
#, c-format
msgid "File `%s' already there; not retrieving.\n"
msgstr "Soubor „%s“ je již zde, nebudu jej přenášet.\n"

#: src/ftp.c:1164 src/http.c:2393
#, c-format
msgid "(try:%2d)"
msgstr "(pokus:%2d)"

#: src/ftp.c:1234 src/http.c:2716
#, c-format
msgid ""
"%s (%s) - `%s' saved [%s]\n"
"\n"
msgstr ""
"%s (%s) – „%s“ uložen [%s]\n"
"\n"

#: src/ftp.c:1276 src/main.c:1006 src/recur.c:377 src/retr.c:859
#, c-format
msgid "Removing %s.\n"
msgstr "Maže se %s.\n"

#: src/ftp.c:1318
#, c-format
msgid "Using `%s' as listing tmp file.\n"
msgstr "Seznam souborů bude dočasně uložen v „%s“.\n"

#: src/ftp.c:1333
#, c-format
msgid "Removed `%s'.\n"
msgstr "Soubor „%s“ byl vymazán.\n"

#: src/ftp.c:1366
#, c-format
msgid "Recursion depth %d exceeded max. depth %d.\n"
msgstr "Hloubka rekurze %d překročila maximální hloubku %d.\n"

#: src/ftp.c:1436
#, c-format
msgid "Remote file no newer than local file `%s' -- not retrieving.\n"
msgstr ""
"Vzdálený soubor není novější, než lokální soubor „%s“, a není jej třeba "
"stahovat.\n"

#: src/ftp.c:1443
#, c-format
msgid ""
"Remote file is newer than local file `%s' -- retrieving.\n"
"\n"
msgstr ""
"Vzdálený soubor je novější, než lokální soubor „%s“, a je jej třeba "
"stáhnout.\n"
"\n"

#: src/ftp.c:1450
#, c-format
msgid ""
"The sizes do not match (local %s) -- retrieving.\n"
"\n"
msgstr ""
"Velikosti se neshodují (lokální %s), stahuji.\n"
"\n"

#: src/ftp.c:1468
msgid "Invalid name of the symlink, skipping.\n"
msgstr "Přeskakuje se symbolický odkaz, neboť název odkazu není platný.\n"

#: src/ftp.c:1485
#, c-format
msgid ""
"Already have correct symlink %s -> %s\n"
"\n"
msgstr ""
"Korektní symbolický odkaz %s -> %s již existuje.\n"
"\n"

#: src/ftp.c:1493
#, c-format
msgid "Creating symlink %s -> %s\n"
msgstr "Vytváří se symbolický odkaz %s -> %s\n"

#: src/ftp.c:1503
#, c-format
msgid "Symlinks not supported, skipping symlink `%s'.\n"
msgstr ""
"Symbolický odkaz „%s“ bude vynechán, protože systém symbolické odkazy "
"nepodporuje.\n"

#: src/ftp.c:1515
#, c-format
msgid "Skipping directory `%s'.\n"
msgstr "Adresář „%s“ bude vynechán.\n"

#: src/ftp.c:1524
#, c-format
msgid "%s: unknown/unsupported file type.\n"
msgstr "%s: neznámý/nepodporovaný typ souboru.\n"

#: src/ftp.c:1551
#, c-format
msgid "%s: corrupt time-stamp.\n"
msgstr "%s: časové razítko souboru je porušené.\n"

#: src/ftp.c:1579
#, c-format
msgid "Will not retrieve dirs since depth is %d (max %d).\n"
msgstr ""
"Podadresáře se nebudou přenášet, protože již bylo dosaženo hloubky %d "
"(maximum je %d).\n"

#: src/ftp.c:1629
#, c-format
msgid "Not descending to `%s' as it is excluded/not-included.\n"
msgstr ""
"Do adresáře „%s“ se nesetupuje, protože tento adresář se buď má vynechat "
"nebo\n"
"nebyl zadán k procházení.\n"

#: src/ftp.c:1695 src/ftp.c:1709
#, c-format
msgid "Rejecting `%s'.\n"
msgstr "Soubor „%s“ se nemá stahovat.\n"

#: src/ftp.c:1757
#, c-format
msgid "No matches on pattern `%s'.\n"
msgstr "Vzorku „%s“ nic neodpovídá.\n"

#: src/ftp.c:1823
#, c-format
msgid "Wrote HTML-ized index to `%s' [%s].\n"
msgstr "Výpis adresáře v HTML formátu byl zapsán do „%s“ [%s].\n"

#: src/ftp.c:1828
#, c-format
msgid "Wrote HTML-ized index to `%s'.\n"
msgstr "Výpis adresáře v HTML formátu byl zapsán do „%s“.\n"

#: src/host.c:347
msgid "Unknown host"
msgstr "Neznámé jméno počítače"

#: src/host.c:351
msgid "Temporary failure in name resolution"
msgstr "Dočasná chyba při překladu jména"

#: src/host.c:353
msgid "Unknown error"
msgstr "Neznámá chyba"

#: src/host.c:714
#, c-format
msgid "Resolving %s... "
msgstr "Překlad %s… "

#: src/host.c:761
msgid "failed: No IPv4/IPv6 addresses for host.\n"
msgstr "selhal: Pro dané jméno neexistuje žádná IPv4/IPv6 adresa.\n"

#: src/host.c:784
msgid "failed: timed out.\n"
msgstr "selhal: vypršel časový limit.\n"

#: src/html-url.c:288
#, c-format
msgid "%s: Cannot resolve incomplete link %s.\n"
msgstr "%s: Neúplný odkaz %s nelze vyhodnotit.\n"

#: src/html-url.c:695
#, c-format
msgid "%s: Invalid URL %s: %s\n"
msgstr "%s: Neplatné URL %s: %s\n"

#: src/http.c:367
#, c-format
msgid "Failed writing HTTP request: %s.\n"
msgstr "Nebylo možné odeslat HTTP požadavek: %s.\n"

#: src/http.c:736
msgid "No headers, assuming HTTP/0.9"
msgstr "Chybí hlavičky, předpokládám HTTP/0.9"

#: src/http.c:1413
msgid "Disabling SSL due to encountered errors.\n"
msgstr "Vypínám SSL kvůli chybám, které se vyskytly.\n"

#: src/http.c:1566
#, c-format
msgid "POST data file `%s' missing: %s\n"
msgstr "Soubor „%s“ s daty pro POST chybí: %s\n"

#: src/http.c:1615
#, c-format
msgid "Reusing existing connection to %s:%d.\n"
msgstr "Využívám existující spojení s %s:%d.\n"

#: src/http.c:1683
#, c-format
msgid "Failed reading proxy response: %s\n"
msgstr "Chyba při čtení odpovědi od proxy: %s\n"

#: src/http.c:1703
#, c-format
msgid "Proxy tunneling failed: %s"
msgstr "Tunelování zkrz proxy se nezdařilo: %s"

#: src/http.c:1748
#, c-format
msgid "%s request sent, awaiting response... "
msgstr "%s požadavek odeslán, program čeká na odpověď… "

#: src/http.c:1759
msgid "No data received.\n"
msgstr "Nepřišla žádná data.\n"

#: src/http.c:1766
#, c-format
msgid "Read error (%s) in headers.\n"
msgstr "Chyba (%s) při čtení hlaviček.\n"

#: src/http.c:1812
#, c-format
msgid ""
"File `%s' already there; not retrieving.\n"
"\n"
msgstr ""
"Soubor „%s“ je již zde, nebudu jej třeba přenášet.\n"
"\n"

#: src/http.c:1965
msgid "Unknown authentication scheme.\n"
msgstr "Server požaduje neznámý způsob autentifikace.\n"

#: src/http.c:1996
msgid "Authorization failed.\n"
msgstr "Autorizace selhala.\n"

#: src/http.c:2010
msgid "Malformed status line"
msgstr "Odpověď serveru má zkomolený stavový řádek"

#: src/http.c:2012
msgid "(no description)"
msgstr "(žádný popis)"

#: src/http.c:2075
#, c-format
msgid "Location: %s%s\n"
msgstr "Přesměrováno na: %s%s\n"

#: src/http.c:2076 src/http.c:2183
msgid "unspecified"
msgstr "neudáno"

#: src/http.c:2077
msgid " [following]"
msgstr " [následuji]"

#: src/http.c:2133
msgid ""
"\n"
"    The file is already fully retrieved; nothing to do.\n"
"\n"
msgstr ""
"\n"
"    Soubor je již plně přenesen, nebude se nic dělat.\n"
"\n"

#: src/http.c:2163
msgid "Length: "
msgstr "Délka: "

#: src/http.c:2183
msgid "ignored"
msgstr "je ignorována"

#: src/http.c:2254
#, c-format
msgid "Saving to: `%s'\n"
msgstr "Ukládám do: „%s“.\n"

#: src/http.c:2335
msgid "Warning: wildcards not supported in HTTP.\n"
msgstr "Varování: HTTP nepodporuje žolíkové znaky.\n"

#: src/http.c:2382
msgid "Spider mode enabled. Check if remote file exists.\n"
msgstr "Aktivován režim pavouka. Kontroluje, zda vzdálený soubor existuje.\n"

#: src/http.c:2467
#, c-format
msgid "Cannot write to `%s' (%s).\n"
msgstr "Nelze zapsat do „%s“ (%s).\n"

#: src/http.c:2476
msgid "Unable to establish SSL connection.\n"
msgstr "Nebylo možné navázat SSL spojení.\n"

# , c-format
#: src/http.c:2484
#, c-format
msgid "ERROR: Redirection (%d) without location.\n"
msgstr "CHYBA: Přesměrování (%d) bez udané nové adresy.\n"

#: src/http.c:2530
msgid "Remote file does not exist -- broken link!!!\n"
msgstr "Vzdálený soubor neexistuje – slepý odkaz!!!\n"

#: src/http.c:2535
#, c-format
msgid "%s ERROR %d: %s.\n"
msgstr "%s CHYBA %d: %s.\n"

#: src/http.c:2551
msgid "Last-modified header missing -- time-stamps turned off.\n"
msgstr ""
"Nelze použít časová razítka, protože v odpovědi serveru \n"
"schází hlavička „Last-modified“.\n"

#: src/http.c:2559
msgid "Last-modified header invalid -- time-stamp ignored.\n"
msgstr ""
"Časové razítko souboru bude ignorováno, protože hlavička \n"
"„Last-modified“ obsahuje neplatné údaje.\n"

#: src/http.c:2589
#, c-format
msgid ""
"Server file no newer than local file `%s' -- not retrieving.\n"
"\n"
msgstr ""
"Lokální soubor „%s“ není starší než vzdálený soubor a není třeba jej "
"stahovat.\n"
"\n"

#: src/http.c:2597
#, c-format
msgid "The sizes do not match (local %s) -- retrieving.\n"
msgstr "Velikosti se neshodují (lokální %s), stahuji.\n"

#: src/http.c:2604
msgid "Remote file is newer, retrieving.\n"
msgstr "Lokální soubor je starší a vzdálený soubor se proto bude přenášet.\n"

#: src/http.c:2620
msgid ""
"Remote file exists and could contain links to other resources -- "
"retrieving.\n"
"\n"
msgstr ""
"Vzdálený soubor nexistuje a mohl by obsahovat odkazy na další "
"zdroje – stahuji.\n"
"\n"

#: src/http.c:2625
msgid ""
"Remote file exists but does not contain any link -- not retrieving.\n"
"\n"
msgstr ""
"Vzdálený soubor existuje, ale neobsahuje žádné odkazy – nestahuji.\n"
"\n"

#: src/http.c:2633
msgid ""
"Remote file exists but recursion is disabled -- not retrieving.\n"
"\n"
msgstr "Vzdálený soubor existuje, ale rekurze je vypnuta – nestahuji.\n"

#: src/http.c:2685
#, c-format
msgid ""
"%s (%s) - `%s' saved [%s/%s]\n"
"\n"
msgstr ""
"%s (%s) – „%s“ uloženo [%s/%s]\n"
"\n"

#: src/http.c:2740
#, c-format
msgid "%s (%s) - Connection closed at byte %s. "
msgstr "%s (%s) – Spojení ukončeno na bajtu %s. "

#: src/http.c:2755
#, c-format
msgid "%s (%s) - Read error at byte %s (%s)."
msgstr "%s (%s) – Chyba při čtení dat na bajtu %s (%s)."

#: src/http.c:2764
#, c-format
msgid "%s (%s) - Read error at byte %s/%s (%s). "
msgstr "%s (%s) – Chyba při čtení dat na bajtu %s/%s (%s). "

#: src/init.c:386
#, c-format
msgid "%s: WGETRC points to %s, which doesn't exist.\n"
msgstr "%s: WGETRC ukazuje na %s, který ale neexistuje.\n"

#: src/init.c:449 src/netrc.c:264
#, c-format
msgid "%s: Cannot read %s (%s).\n"
msgstr "%s: Nelze přečíst %s (%s).\n"

#: src/init.c:467
#, c-format
msgid "%s: Error in %s at line %d.\n"
msgstr "%s: Chyba v %s na řádku %d.\n"

#: src/init.c:473
#, c-format
msgid "%s: Syntax error in %s at line %d.\n"
msgstr "%s: Syntaktická chyba v %s na řádku %d.\n"

#: src/init.c:478
#, c-format
msgid "%s: Unknown command `%s' in %s at line %d.\n"
msgstr "%s: Neznámý příkaz „%s“ v %s na řádku %d.\n"

#: src/init.c:523
#, c-format
msgid "%s: Warning: Both system and user wgetrc point to `%s'.\n"
msgstr ""
"%s: Varování: Globální i uživatelské wgetrc jsou shodně uloženy v „%s“.\n"

#: src/init.c:676
#, c-format
msgid "%s: Invalid --execute command `%s'\n"
msgstr "%s: Neplatný příkaz --execute „%s“\n"

#: src/init.c:721
#, c-format
msgid "%s: %s: Invalid boolean `%s'; use `on' or `off'.\n"
msgstr ""
"%s: %s: Chybná pravdivostní hodnota „%s“, zadejte „on“ (zapnuto) nebo "
"„off“ (vypnuto).\n"

#: src/init.c:738
#, c-format
msgid "%s: %s: Invalid number `%s'.\n"
msgstr "%s: %s: Neplatné číslo „%s“\n"

#: src/init.c:969 src/init.c:988
#, c-format
msgid "%s: %s: Invalid byte value `%s'\n"
msgstr "%s: %s: Neplatná hodnota bajtu „%s“\n"

#: src/init.c:1013
#, c-format
msgid "%s: %s: Invalid time period `%s'\n"
msgstr "%s: %s: Neplatná časová perioda „%s“\n"

#: src/init.c:1067 src/init.c:1157 src/init.c:1260 src/init.c:1285
#, c-format
msgid "%s: %s: Invalid value `%s'.\n"
msgstr "%s: %s: Neplatná hodnota „%s“.\n"

#: src/init.c:1104
#, c-format
msgid "%s: %s: Invalid header `%s'.\n"
msgstr "%s: %s: Neplatná hlavička „%s“\n"

#: src/init.c:1170
#, c-format
msgid "%s: %s: Invalid progress type `%s'.\n"
msgstr "%s: %s: Neplatný druh indikace postupu „%s“.\n"

#: src/init.c:1229
#, c-format
msgid ""
"%s: %s: Invalid restriction `%s', use [unix|windows],[lowercase|uppercase],"
"[nocontrol].\n"
msgstr ""
"%s: %s: Neplatná hodnota omezení „%s“, použijte [unix|windows], [lowercase|"
"uppercase] (malá/velká písmena), [nocontrol] (bez kontroly)\n"

#: src/log.c:783
#, c-format
msgid ""
"\n"
"%s received, redirecting output to `%s'.\n"
msgstr ""
"\n"
"Obdržen signál %s, výstup přesměrován do „%s“.\n"

#: src/log.c:793
#, c-format
msgid ""
"\n"
"%s received.\n"
msgstr ""
"\n"
"obdržen signál %s.\n"

#: src/log.c:794
#, c-format
msgid "%s: %s; disabling logging.\n"
msgstr "%s: %s: vypínám protokolování\n"

#: src/main.c:356
#, c-format
msgid "Usage: %s [OPTION]... [URL]...\n"
msgstr "Použití: %s [PŘEPÍNAČ]… [URL]…\n"

#: src/main.c:368
msgid ""
"Mandatory arguments to long options are mandatory for short options too.\n"
"\n"
msgstr ""
"Argumenty povinné u dlouhých přepínačů jsou povinné i pro jejich krátké "
"verze.\n"
"\n"

#: src/main.c:370
msgid "Startup:\n"
msgstr "Rozjezd:\n"

#: src/main.c:372
msgid "  -V,  --version           display the version of Wget and exit.\n"
msgstr "  -V,  --version           zobrazí verzi Wgetu a skončí.\n"

#: src/main.c:374
msgid "  -h,  --help              print this help.\n"
msgstr "  -h,  --help              vytiskne tuto nápovědu.\n"

#: src/main.c:376
msgid "  -b,  --background        go to background after startup.\n"
msgstr "  -b,  --background        po spuštění přejde do pozadí.\n"

#: src/main.c:378
msgid "  -e,  --execute=COMMAND   execute a `.wgetrc'-style command.\n"
msgstr "  -e,  --execute=PŘÍKAZ    provede příkaz jako z „.wgetrc“.\n"

#: src/main.c:382
msgid "Logging and input file:\n"
msgstr "Protokolový a vstupní soubor:\n"

#: src/main.c:384
msgid "  -o,  --output-file=FILE    log messages to FILE.\n"
msgstr "  -o,  --output-file=SOUBOR  protokol zapisuje do SOUBORU.\n"

#: src/main.c:386
msgid "  -a,  --append-output=FILE  append messages to FILE.\n"
msgstr ""
"  -a,  --append-output=SOUBOR\n"
"                             zprávy připojuje k SOUBORU.\n"

#: src/main.c:389
msgid "  -d,  --debug               print lots of debugging information.\n"
msgstr "  -d,  --debug               tiskne mnoho ladicích informací.\n"

#: src/main.c:393
#, fuzzy
msgid "       --wdebug              print Watt-32 debug output.\n"
msgstr "  -d,  --debug               tiskne mnoho ladicích informací.\n"

#: src/main.c:396
msgid "  -q,  --quiet               quiet (no output).\n"
msgstr "  -q,  --quiet               tichý režim (žádný výstup).\n"

#: src/main.c:398
msgid "  -v,  --verbose             be verbose (this is the default).\n"
msgstr "  -v,  --verbose             bude upovídaný (implicitní chování).\n"

#: src/main.c:400
msgid ""
"  -nv, --no-verbose          turn off verboseness, without being quiet.\n"
msgstr ""
"  -nv, --no-verbose          vypne upovídanost, aniž by byl zcela zticha.\n"

#: src/main.c:402
msgid "  -i,  --input-file=FILE     download URLs found in FILE.\n"
msgstr "  -i,  --input-file=SOUBOR   stáhne URL uvedená v SOUBORU.\n"

#: src/main.c:404
msgid "  -F,  --force-html          treat input file as HTML.\n"
msgstr "  -F,  --force-html          vstupní soubor považuje za HTML soubor.\n"

#: src/main.c:406
msgid ""
"  -B,  --base=URL            prepends URL to relative links in -F -i file.\n"
msgstr ""
"  -B,  --base=URL            předřadí URL relativním odkazům z -F -i "
"souboru.\n"

#: src/main.c:410
msgid "Download:\n"
msgstr "Stahování:\n"

#: src/main.c:412
msgid ""
"  -t,  --tries=NUMBER            set number of retries to NUMBER (0 "
"unlimits).\n"
msgstr ""
"  -t,  --tries=POČET             nastaví POČET opakování (0 znamená "
"neomezeno).\n"

#: src/main.c:414
msgid "       --retry-connrefused       retry even if connection is refused.\n"
msgstr ""
"       --retry-connrefused       opakuje, i když spojení bude odmítnuto.\n"

#: src/main.c:416
msgid "  -O,  --output-document=FILE    write documents to FILE.\n"
msgstr "  -O,  --output-document=SOUBOR  dokumenty zapisuje do SOUBORU.\n"

#: src/main.c:418
msgid ""
"  -nc, --no-clobber              skip downloads that would download to\n"
"                                 existing files.\n"
msgstr ""
"  -nc, --no-clobber              vynechá stahování, která by přepsala již\n"
"                                 existující soubory.\n"

#: src/main.c:421
msgid ""
"  -c,  --continue                resume getting a partially-downloaded "
"file.\n"
msgstr ""
"  -c,  --continue                obnoví stahování částečně staženého "
"souboru.\n"

#: src/main.c:423
msgid "       --progress=TYPE           select progress gauge type.\n"
msgstr "       --progress=DRUH           vybere druh indikátoru postupu.\n"

#: src/main.c:425
msgid ""
"  -N,  --timestamping            don't re-retrieve files unless newer than\n"
"                                 local.\n"
msgstr ""
"  -N,  --timestamping            nesnaží se znovu získat soubory, jež mají\n"
"                                 mladší místní kopii\n"

#: src/main.c:428
msgid "  -S,  --server-response         print server response.\n"
msgstr "  -S,  --server-response         tiskne odpověď serveru.\n"

#: src/main.c:430
msgid "       --spider                  don't download anything.\n"
msgstr "       --spider                  nestahuje nic.\n"

#: src/main.c:432
msgid "  -T,  --timeout=SECONDS         set all timeout values to SECONDS.\n"
msgstr ""
"  -T,  --timeout=SEKUNDY         nastaví všechny časové limity\n"
"                                 na SEKUND.\n"

#: src/main.c:434
msgid "       --dns-timeout=SECS        set the DNS lookup timeout to SECS.\n"
msgstr ""
"       --dns-timeout=SEKUNDY     nastaví limit pro hledání v DNS\n"
"                                 na SEKUND.\n"

#: src/main.c:436
msgid "       --connect-timeout=SECS    set the connect timeout to SECS.\n"
msgstr ""
"       --connect-timeout=SEKUNDY\n"
"                                 nastaví limit pro navázání spojení\n"
"                                 na SEKUND.\n"

#: src/main.c:438
msgid "       --read-timeout=SECS       set the read timeout to SECS.\n"
msgstr "       --read-timeout=SEKUNDY    nastaví limit pro čtení na SEKUND\n"

#: src/main.c:440
msgid "  -w,  --wait=SECONDS            wait SECONDS between retrievals.\n"
msgstr "  -w,  --wait=SEKUNDY            čeká SEKUND mezi každým stažením.\n"

#: src/main.c:442
msgid ""
"       --waitretry=SECONDS       wait 1..SECONDS between retries of a "
"retrieval.\n"
msgstr ""
"       --waitretry=SEKUNDY       čeká 1 až SEKUND mezi opakováním stažení.\n"

#: src/main.c:444
msgid ""
"       --random-wait             wait from 0...2*WAIT secs between "
"retrievals.\n"
msgstr ""
"       --random-wait             čeká od 0 do 2*WAIT sekund mezi staženími.\n"

#: src/main.c:446
msgid "  -Y,  --proxy                   explicitly turn on proxy.\n"
msgstr "  -Y,  --proxy                   explicitně zapne proxy.\n"

#: src/main.c:448
msgid "       --no-proxy                explicitly turn off proxy.\n"
msgstr "       --no-proxy                explicitně vypne proxy.\n"

#: src/main.c:450
msgid "  -Q,  --quota=NUMBER            set retrieval quota to NUMBER.\n"
msgstr "  -Q,  --quota=POČET             nastaví kvótu na POČET stažení.\n"

#: src/main.c:452
msgid ""
"       --bind-address=ADDRESS    bind to ADDRESS (hostname or IP) on local "
"host.\n"
msgstr ""
"       --bind-address=ADRESA     přilepí se (bind) na ADRESU (jméno nebo "
"IP)\n"
"                                 na tomto stroji.\n"

#: src/main.c:454
msgid "       --limit-rate=RATE         limit download rate to RATE.\n"
msgstr ""
"       --limit-rate=RYCHLOST     omezí rychlost stahování na RYCHLOST.\n"

#: src/main.c:456
msgid "       --no-dns-cache            disable caching DNS lookups.\n"
msgstr "       --no-dns-cache            zakáže kešování DNS odpovědí.\n"

#: src/main.c:458
msgid ""
"       --restrict-file-names=OS  restrict chars in file names to ones OS "
"allows.\n"
msgstr ""
"       --restrict-file-names=OS  omezí znaky ve jménech souborů na ty,\n"
"                                 které dovoluje vybraný operační systém "
"(OS).\n"

#: src/main.c:460
msgid ""
"       --ignore-case             ignore case when matching files/"
"directories.\n"
msgstr ""
"       --ignore-case             při porovnávání jmen souborů/adresářů\n"
"                                 nebere zřetel na velikost písmen.\n"

#: src/main.c:463
msgid "  -4,  --inet4-only              connect only to IPv4 addresses.\n"
msgstr "  -4,  --inet4-only              připojuje se jen na IPv4 adresy.\n"

#: src/main.c:465
msgid "  -6,  --inet6-only              connect only to IPv6 addresses.\n"
msgstr "  -6,  --inet6-only              připojuje se jen na IPv6 adresy.\n"

#: src/main.c:467
msgid ""
"       --prefer-family=FAMILY    connect first to addresses of specified "
"family,\n"
"                                 one of IPv6, IPv4, or none.\n"
msgstr ""
"       --prefer-family=RODINA    připojuje se nejprve na adresu zadané\n"
"                                 RODINY („IPv6“, „IPv4“ nebo "
"„none“ (žádná))\n"

#: src/main.c:471
msgid "       --user=USER               set both ftp and http user to USER.\n"
msgstr ""
"       --user=UŽIVATEL           nastaví přihlašovací jméno uživatele\n"
"                                 pro FTP i pro HTTP na UŽIVATELE.\n"

#: src/main.c:473
msgid ""
"       --password=PASS           set both ftp and http password to PASS.\n"
msgstr ""
"       --password=HESLO          nastaví heslo pro FTP i pro HTTP na HESLO.\n"

#: src/main.c:477
msgid "Directories:\n"
msgstr "Adresáře:\n"

#: src/main.c:479
msgid "  -nd, --no-directories           don't create directories.\n"
msgstr "  -nd, --no-directories           nevytváří adresáře,\n"

#: src/main.c:481
msgid "  -x,  --force-directories        force creation of directories.\n"
msgstr "  -x,  --force-directories        vynutí vytváření adresářů.\n"

#: src/main.c:483
msgid "  -nH, --no-host-directories      don't create host directories.\n"
msgstr ""
"  -nH, --no-host-directories      nevytváří adresáře se jmény počítačů.\n"

#: src/main.c:485
msgid "       --protocol-directories     use protocol name in directories.\n"
msgstr ""
"       --protocol-directories     použije jméno protokolu v adresářích.\n"

#: src/main.c:487
msgid "  -P,  --directory-prefix=PREFIX  save files to PREFIX/...\n"
msgstr "  -P,  --directory-prefix=CESTA   uloží soubory do CESTA/…\n"

#: src/main.c:489
msgid ""
"       --cut-dirs=NUMBER          ignore NUMBER remote directory "
"components.\n"
msgstr ""
"       --cut-dirs=POČET           ignoruje POČET vzdálených adresářových\n"
"                                  komponent.\n"

#: src/main.c:493
msgid "HTTP options:\n"
msgstr "Přepínače pro HTTP:\n"

#: src/main.c:495
msgid "       --http-user=USER        set http user to USER.\n"
msgstr ""
"       --http-user=UŽIVATEL    nastaví přihlašovací jméno uživatele\n"
"                               pro HTTP na UŽIVATELE.\n"

#: src/main.c:497
msgid "       --http-password=PASS    set http password to PASS.\n"
msgstr "       --http-password=HESLO   nastaví heslo pro HTTP na HESLO.\n"

#: src/main.c:499
msgid "       --no-cache              disallow server-cached data.\n"
msgstr "       --no-cache              zakáže kešování na straně serveru.\n"

#: src/main.c:501
msgid ""
"  -E,  --html-extension        save HTML documents with `.html' extension.\n"
msgstr ""
"  -E,  --html-extension        HTML dokumenty ukládá s příponou „.html“.\n"

#: src/main.c:503
msgid "       --ignore-length         ignore `Content-Length' header field.\n"
msgstr "       --ignore-length         ignoruje hlavičku „Content-Length“.\n"

#: src/main.c:505
msgid "       --header=STRING         insert STRING among the headers.\n"
msgstr "       --header=ŘETĚZEC        ke hlavičkám přidá ŘETĚZEC.\n"

#: src/main.c:507
msgid "       --max-redirect          maximum redirections allowed per page.\n"
msgstr ""
"       --max-redirect          maximum přesměrování povolených\n"
"                               na stránku.\n"

#: src/main.c:509
msgid "       --proxy-user=USER       set USER as proxy username.\n"
msgstr ""
"       --proxy-user=UŽIVATEL   nastaví UŽIVATELE jako přihlašovací jméno\n"
"                               uživatele pro proxy.\n"

#: src/main.c:511
msgid "       --proxy-password=PASS   set PASS as proxy password.\n"
msgstr "       --proxy-password=HESLO  nastaví HESLO jako heslo pro proxy.\n"

#: src/main.c:513
msgid ""
"       --referer=URL           include `Referer: URL' header in HTTP "
"request.\n"
msgstr ""
"       --referer=URL           zahrne hlavičku „Referer: URL“ do\n"
"                               HTTP požadavku.\n"

#: src/main.c:515
msgid "       --save-headers          save the HTTP headers to file.\n"
msgstr "       --save-headers          hlavičky HTTP uloží do souboru.\n"

#: src/main.c:517
msgid ""
"  -U,  --user-agent=AGENT      identify as AGENT instead of Wget/VERSION.\n"
msgstr ""
"  -U,  --user-agent=AGENT      identifikuje se jako AGENT místo Wget/VERZE.\n"

#: src/main.c:519
msgid ""
"       --no-http-keep-alive    disable HTTP keep-alive (persistent "
"connections).\n"
msgstr ""
"       --no-http-keep-alive    zakáže HTTP keep-alive (trvalá spojení).\n"

#: src/main.c:521
msgid "       --no-cookies            don't use cookies.\n"
msgstr "       --no-cookies            nepoužívá cookies.\n"

#: src/main.c:523
msgid "       --load-cookies=FILE     load cookies from FILE before session.\n"
msgstr "       --load-cookies=SOUBOR   před relací načte cookies ze SOUBORU.\n"

#: src/main.c:525
msgid "       --save-cookies=FILE     save cookies to FILE after session.\n"
msgstr "       --save-cookies=SOUBOR   po relaci uloží cookies do SOUBORU.\n"

#: src/main.c:527
msgid ""
"       --keep-session-cookies  load and save session (non-permanent) "
"cookies.\n"
msgstr ""
"       --keep-session-cookies  načte a uloží cookies relace (ne-trvalé).\n"

#: src/main.c:529
msgid ""
"       --post-data=STRING      use the POST method; send STRING as the "
"data.\n"
msgstr ""
"       --post-data=ŘETĚZEC     použije metodu POST, jako data pošle "
"ŘETĚZEC.\n"

#: src/main.c:531
msgid ""
"       --post-file=FILE        use the POST method; send contents of FILE.\n"
msgstr ""
"       --post-file=SOUBOR      použije metodu POST, pošle obsah SOUBORU.\n"

#: src/main.c:533
msgid ""
"       --no-content-disposition  don't honor Content-Disposition header.\n"
msgstr ""
"       --no-content-disposition  nebere v úvahu hlavičku Content-"
"Disposition.\n"

#: src/main.c:538
msgid "HTTPS (SSL/TLS) options:\n"
msgstr "Přepínače HTTPS (SSL/TLS):\n"

#: src/main.c:540
msgid ""
"       --secure-protocol=PR     choose secure protocol, one of auto, SSLv2,\n"
"                                SSLv3, and TLSv1.\n"
msgstr ""
"       --secure-protocol=PROT   vybere bezpečnostní protokol, jeden z "
"„auto“,\n"
"                                „SSLv2“, „SSLv3“ a „TLSv1“.\n"

#: src/main.c:543
msgid ""
"       --no-check-certificate   don't validate the server's certificate.\n"
msgstr "       --no-check-certificate   neověřuje certifikát serveru.\n"

#: src/main.c:545
msgid "       --certificate=FILE       client certificate file.\n"
msgstr "       --certificate=SOUBOR     soubor s certifikátem klienta.\n"

#: src/main.c:547
msgid "       --certificate-type=TYPE  client certificate type, PEM or DER.\n"
msgstr ""
"       --certificate-type=DRUH  druh certifikátu klienta: „PEM“ nebo „DER“.\n"

#: src/main.c:549
msgid "       --private-key=FILE       private key file.\n"
msgstr "       --private-key=SOUBOR     soubor se soukromým klíčem.\n"

#: src/main.c:551
msgid "       --private-key-type=TYPE  private key type, PEM or DER.\n"
msgstr ""
"       --private-key-type=DRUH  druh soukromého klíče: „PEM“ nebo „DER“.\n"

#: src/main.c:553
msgid "       --ca-certificate=FILE    file with the bundle of CA's.\n"
msgstr ""
"       --ca-certificate=SOUBOR  soubor se sbírkou certifikačních autorit.\n"

#: src/main.c:555
msgid ""
"       --ca-directory=DIR       directory where hash list of CA's is "
"stored.\n"
msgstr ""
"       --ca-directory=ADRESÁŘ   adresář obsahující hashe jmen\n"
"                                certifikačních autorit.\n"

#: src/main.c:557
msgid ""
"       --random-file=FILE       file with random data for seeding the SSL "
"PRNG.\n"
msgstr ""
"       --random-file=SOUBOR     soubor s náhodnými daty pro zdroj SSL PRNG.\n"

#: src/main.c:559
msgid ""
"       --egd-file=FILE          file naming the EGD socket with random "
"data.\n"
msgstr ""
"       --egd-file=SOUBOR        soubor jmenující soket EGD s náhodnými "
"daty.\n"

#: src/main.c:564
msgid "FTP options:\n"
msgstr "Přepínače FTP:\n"

#: src/main.c:566
msgid "       --ftp-user=USER         set ftp user to USER.\n"
msgstr ""
"       --ftp-user=UŽIVATEL     nastaví přihlašovací jméno na UŽIVATELE.\n"

#: src/main.c:568
msgid "       --ftp-password=PASS     set ftp password to PASS.\n"
msgstr "       --ftp-password=HESLO    nastaví heslo pro FTP na HESLO.\n"

#: src/main.c:570
msgid "       --no-remove-listing     don't remove `.listing' files.\n"
msgstr "       --no-remove-listing     neodstraňuje soubory „.listing“.\n"

#: src/main.c:572
msgid "       --no-glob               turn off FTP file name globbing.\n"
msgstr "       --no-glob               neexpanduje jména FTP souborů.\n"

#: src/main.c:574
msgid "       --no-passive-ftp        disable the \"passive\" transfer mode.\n"
msgstr "       --no-passive-ftp        zakáže pasivní režim přenosu.\n"

#: src/main.c:576
msgid ""
"       --retr-symlinks         when recursing, get linked-to files (not "
"dir).\n"
msgstr ""
"       --retr-symlinks         při rekurzi stáhne soubory (adresáře ne),\n"
"                               na které odkazuje symbolický odkaz.\n"

#: src/main.c:578
msgid "       --preserve-permissions  preserve remote file permissions.\n"
msgstr "       --preserve-permissions  zachová přístupová práva ze serveru.\n"

#: src/main.c:582
msgid "Recursive download:\n"
msgstr "Rekurzivní stahování:\n"

#: src/main.c:584
msgid "  -r,  --recursive          specify recursive download.\n"
msgstr "  -r,  --recursive          zapne rekurzivní stahování.\n"

#: src/main.c:586
msgid ""
"  -l,  --level=NUMBER       maximum recursion depth (inf or 0 for "
"infinite).\n"
msgstr ""
"  -l,  --level=POČET        maximální hloubka rekurze\n"
"                            („inf“ nebo „0“ pro nekonečno).\n"

#: src/main.c:588
msgid ""
"       --delete-after       delete files locally after downloading them.\n"
msgstr ""
"       --delete-after       smaže soubory lokálně po té, co dokončí "
"stahování.\n"

#: src/main.c:590
msgid ""
"  -k,  --convert-links      make links in downloaded HTML point to local "
"files.\n"
msgstr ""
"  -k,  --convert-links      učiní odkazy v HTML odkazující na místní "
"soubory.\n"

#: src/main.c:592
msgid ""
"  -K,  --backup-converted   before converting file X, back up as X.orig.\n"
msgstr ""
"  -K,  --backup-converted   před konverzí souboru X jej zazálohuje jako X."
"orig.\n"

#: src/main.c:594
msgid ""
"  -m,  --mirror             shortcut for -N -r -l inf --no-remove-listing.\n"
msgstr ""
"  -m,  --mirror             zkratka pro -N -r -l inf --no-remove-listing.\n"

#: src/main.c:596
msgid ""
"  -p,  --page-requisites    get all images, etc. needed to display HTML "
"page.\n"
msgstr ""
"  -p,  --page-requisites    získá všechny obrázky apod. potřebné pro\n"
"                            zobrazení HTML stránky.\n"

#: src/main.c:598
msgid ""
"       --strict-comments    turn on strict (SGML) handling of HTML "
"comments.\n"
msgstr ""
"       --strict-comments    zapne přísné zacházení s HTML komentáři podle "
"SGML.\n"

#: src/main.c:602
msgid "Recursive accept/reject:\n"
msgstr "Rekurzivní povolení/zakázání:\n"

#: src/main.c:604
msgid ""
"  -A,  --accept=LIST               comma-separated list of accepted "
"extensions.\n"
msgstr ""
"  -A,  --accept=SEZNAM             čárkou oddělený seznam povolených "
"přípon.\n"

#: src/main.c:606
msgid ""
"  -R,  --reject=LIST               comma-separated list of rejected "
"extensions.\n"
msgstr ""
"  -R,  --reject=SEZNAM             čárkou oddělený seznam zakázaných "
"přípon.\n"

#: src/main.c:608
msgid ""
"  -D,  --domains=LIST              comma-separated list of accepted "
"domains.\n"
msgstr ""
"  -D,  --domains=SEZNAM            čárkou oddělený seznam povolených domén.\n"

#: src/main.c:610
msgid ""
"       --exclude-domains=LIST      comma-separated list of rejected "
"domains.\n"
msgstr ""
"       --exclude-domains=SEZNAM    čárkou oddělený seznam zakázaných domén.\n"

#: src/main.c:612
msgid ""
"       --follow-ftp                follow FTP links from HTML documents.\n"
msgstr ""
"       --follow-ftp                následuje FTP odkazy z HTML dokumentů.\n"

#: src/main.c:614
msgid ""
"       --follow-tags=LIST          comma-separated list of followed HTML "
"tags.\n"
msgstr ""
"       --follow-tags=SEZNAM        čárkou oddělený seznam HTML značek "
"určených\n"
"                                   k následování.\n"

#: src/main.c:616
msgid ""
"       --ignore-tags=LIST          comma-separated list of ignored HTML "
"tags.\n"
msgstr ""
"       --ignore-tags=SEZNAM        čárkou oddělený seznam ignorovaných\n"
"                                   HTML značek.\n"

#: src/main.c:618
msgid ""
"  -H,  --span-hosts                go to foreign hosts when recursive.\n"
msgstr ""
"  -H,  --span-hosts                při rekurzi přechází i na jiné počítače.\n"

#: src/main.c:620
msgid "  -L,  --relative                  follow relative links only.\n"
msgstr "  -L,  --relative                  následuje jen relativní odkazy.\n"

#: src/main.c:622
msgid "  -I,  --include-directories=LIST  list of allowed directories.\n"
msgstr ""
"  -I,  --include-directories=SEZNAM\n"
"                                   seznam povolených adresářů.\n"

#: src/main.c:624
msgid "  -X,  --exclude-directories=LIST  list of excluded directories.\n"
msgstr ""
"  -X,  --exclude-directories=SEZNAM\n"
"                                   seznam zakázaných adresářů.\n"

#: src/main.c:626
msgid ""
"  -np, --no-parent                 don't ascend to the parent directory.\n"
msgstr "  -np, --no-parent                 nestoupá do nadřízeného adresáře.\n"

#: src/main.c:630
msgid "Mail bug reports and suggestions to <bug-wget@gnu.org>.\n"
msgstr ""
"Zprávy o chybách a návrhy na vylepšení programu zasílejte na adresu\n"
"<bug-wget@gnu.org> (pouze anglicky). Komentáře k českému překladu\n"
"zasílejte na adresu <translation-team-cs@lists.sourceforge.net>.\n"

# , c-format
#: src/main.c:635
#, c-format
msgid "GNU Wget %s, a non-interactive network retriever.\n"
msgstr "GNU Wget %s, program pro neinteraktivní stahování souborů.\n"

#: src/main.c:675
msgid "Copyright (C) 2007 Free Software Foundation, Inc.\n"
msgstr "Copyright © 2007 Free Software Foundation, Inc.\n"

#: src/main.c:677
msgid ""
"License GPLv3+: GNU GPL version 3 or later\n"
"<http://www.gnu.org/licenses/gpl.html>.\n"
"This is free software: you are free to change and redistribute it.\n"
"There is NO WARRANTY, to the extent permitted by law.\n"
msgstr ""
"Licence GPLv3+: GNU GPL verze 3 nebo vyšší\n"
"<http://www.gnu.org/licenses/gpl.html>.\n"
"Toto je volné programové vybavení: máte právo jej měnit a dále šířit.\n"
"Není poskytována ŽÁDNÁ ZÁRUKA, jak jen zákon dovoluje.\n"

#: src/main.c:682
msgid ""
"\n"
"Originally written by Hrvoje Niksic <hniksic@xemacs.org>.\n"
msgstr ""
"\n"
"Původním autorem tohoto programu je Hrvoje Nikšić <hniksic@xemacs.org>.\n"

#: src/main.c:684
msgid "Currently maintained by Micah Cowan <micah@cowan.name>.\n"
msgstr "Nyní jej spravuje Micah Cowan <micah@cowan.name>.\n"

#: src/main.c:731 src/main.c:800 src/main.c:900
#, c-format
msgid "Try `%s --help' for more options.\n"
msgstr "Příkaz „%s --help“ vypíše další přepínače.\n"

#: src/main.c:797
#, c-format
msgid "%s: illegal option -- `-n%c'\n"
msgstr "%s: nepřípustný přepínač – „-n%c“\n"

#: src/main.c:855
#, c-format
msgid "Can't be verbose and quiet at the same time.\n"
msgstr "Program nemůže být upovídaný a zticha zároveň.\n"

#: src/main.c:861
#, c-format
msgid "Can't timestamp and not clobber old files at the same time.\n"
msgstr "Nelze používat časová razítka a nemazat přitom staré soubory.\n"

#: src/main.c:869
#, c-format
msgid "Cannot specify both --inet4-only and --inet6-only.\n"
msgstr "--inet4-only a --inet6-only nelze zadat najednou.\n"

#: src/main.c:879
#, c-format
msgid "Cannot specify -r, -p or -N if -O is given.\n"
msgstr "Je-li zadáno -O, nelze současně použí -r, -p nebo -N.\n"

#: src/main.c:887
#, c-format
msgid "Cannot specify both -k and -O if multiple URLs are given.\n"
msgstr "Je-li zadáno více URL, nelze najednou použít jak -k, tak i -O.\n"

#: src/main.c:895
#, c-format
msgid "%s: missing URL\n"
msgstr "%s: chybí URL\n"

#: src/main.c:1021
#, c-format
msgid "No URLs found in %s.\n"
msgstr "V souboru „%s“ nebyla nalezena žádná URL.\n"

#: src/main.c:1039
#, c-format
msgid ""
"FINISHED --%s--\n"
"Downloaded: %d files, %s in %s (%s)\n"
msgstr ""
"KONEC --%s--\n"
"Staženo: %d souborů, %s za %s (%s)\n"

#: src/main.c:1048
#, c-format
msgid "Download quota of %s EXCEEDED!\n"
msgstr "Kvóta %s na stahování PŘEKROČENA!\n"

#: src/mswindows.c:97
#, c-format
msgid "Continuing in background.\n"
msgstr "Program pokračuje v běhu na pozadí.\n"

#: src/mswindows.c:290
#, c-format
msgid "Continuing in background, pid %lu.\n"
msgstr "Program pokračuje v běhu na pozadí, pid %lu.\n"

#: src/mswindows.c:292 src/utils.c:329
#, c-format
msgid "Output will be written to `%s'.\n"
msgstr "Výstup bude zapsán do „%s“.\n"

#: src/mswindows.c:460 src/mswindows.c:467
#, c-format
msgid "%s: Couldn't find usable socket driver.\n"
msgstr "%s: Nelze najít použitelný ovladač soketů.\n"

#: src/netrc.c:372
#, c-format
msgid "%s: %s:%d: warning: \"%s\" token appears before any machine name\n"
msgstr ""
"%s: %s:%d varování: token „%s“ je uveden ještě před jakýmkoliv\n"
"      názvem počítače\n"

#: src/netrc.c:403
#, c-format
msgid "%s: %s:%d: unknown token \"%s\"\n"
msgstr "%s: %s:%d: neznámý token „%s“\n"

#: src/netrc.c:467
#, c-format
msgid "Usage: %s NETRC [HOSTNAME]\n"
msgstr "Použití: %s NETRC [NÁZEV POČÍTAČE]\n"

#: src/netrc.c:477
#, c-format
msgid "%s: cannot stat %s: %s\n"
msgstr "%s: volání „stat %s“ skončilo chybou: %s\n"

#: src/openssl.c:112
msgid "WARNING: using a weak random seed.\n"
msgstr "VAROVÁNÍ: používám slabý zdroj náhodných čísel.\n"

#: src/openssl.c:172
msgid "Could not seed PRNG; consider using --random-file.\n"
msgstr "PRNG nelze zinicializovat, zvažte použití přepínače --random-file.\n"

#: src/openssl.c:487
msgid "ERROR"
msgstr "CHYBA"

#: src/openssl.c:487
msgid "WARNING"
msgstr "VAROVÁNÍ"

#: src/openssl.c:496
#, c-format
msgid "%s: No certificate presented by %s.\n"
msgstr "%s: %s nepředložil žádný certifikát.\n"

#: src/openssl.c:517
#, c-format
msgid "%s: cannot verify %s's certificate, issued by `%s':\n"
msgstr "%s: certifikát pro %s vydaný „%s“ nelze ověřit:\n"

#: src/openssl.c:525
msgid "  Unable to locally verify the issuer's authority.\n"
msgstr "  Autoritu vydavatele nelze lokálně ověřit.\n"

#: src/openssl.c:529
msgid "  Self-signed certificate encountered.\n"
msgstr "  Nalezen certifikát podepsaný sám sebou.\n"

#: src/openssl.c:532
msgid "  Issued certificate not yet valid.\n"
msgstr "  Vydaný certifikát ještě nenabyl platnosti.\n"

#: src/openssl.c:535
msgid "  Issued certificate has expired.\n"
msgstr "  Vydanému certifikátu uplynula doba platnosti.\n"

#: src/openssl.c:567
#, c-format
msgid ""
"%s: certificate common name `%s' doesn't match requested host name `%s'.\n"
msgstr ""
"%s: obecné jméno (CN) „%s“ na certifikátu se neshoduje s požadovaným jménem "
"počítače „%s“.\n"

#: src/openssl.c:580
#, c-format
msgid "To connect to %s insecurely, use `--no-check-certificate'.\n"
msgstr "Pro nezabezpečené spojení s %s použijte „--no-check-certificate“.\n"

#: src/progress.c:238
#, c-format
msgid ""
"\n"
"%*s[ skipping %sK ]"
msgstr ""
"\n"
"%*s[ přeskakuje se %s K ]"

#: src/progress.c:452
#, c-format
msgid "Invalid dot style specification `%s'; leaving unchanged.\n"
msgstr "„%s“ není platné určení způsobu indikace, ponechávám nezměněno.\n"

#: src/progress.c:946
#, c-format
msgid "  eta %s"
msgstr " zbývá %s"

#: src/progress.c:961
msgid "   in "
msgstr "   za "

#: src/ptimer.c:159
#, c-format
msgid "Cannot get REALTIME clock frequency: %s\n"
msgstr "Frekvenci hodin REÁLNÉHO ČASU nelze určit: %s\n"

#: src/recur.c:378
#, c-format
msgid "Removing %s since it should be rejected.\n"
msgstr "Maže se %s, protože tento soubor není požadován.\n"

#: src/res.c:389
#, c-format
msgid "Cannot open %s: %s"
msgstr "%s nelze otevřít: %s"

#: src/res.c:541
msgid "Loading robots.txt; please ignore errors.\n"
msgstr "Načítá se „robots.txt“. Chybová hlášení ignorujte, prosím.\n"

#: src/retr.c:651
#, c-format
msgid "Error parsing proxy URL %s: %s.\n"
msgstr "Chyba rozebírání URL proxy serveru %s: %s.\n"

#: src/retr.c:659
#, c-format
msgid "Error in proxy URL %s: Must be HTTP.\n"
msgstr "Chyba v URL Proxy %s: Musí být HTTP.\n"

#: src/retr.c:745
#, c-format
msgid "%d redirections exceeded.\n"
msgstr "Překročeno %d přesměrování.\n"

#: src/retr.c:880
msgid ""
"Giving up.\n"
"\n"
msgstr ""
"Ani poslední pokus nebyl úspěšný.\n"
"\n"

#: src/retr.c:880
