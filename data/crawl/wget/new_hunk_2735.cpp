msgstr "%s: az opcióhoz szükség van argumentumra -- %c\n"

#: src/getopt.c:862
#, c-format
msgid "%s: option `-W %s' is ambiguous\n"
msgstr "%s: a `-W %s' opció kétes értelmû\n"

#: src/getopt.c:880
#, c-format
msgid "%s: option `-W %s' doesn't allow an argument\n"
msgstr "%s: a `-W %s' opcióhoz nem kell argumentum\n"

#: src/host.c:636
#, c-format
msgid "Resolving %s... "
msgstr "IP keresés %s... "

#: src/host.c:656 src/host.c:672
#, c-format
msgid "failed: %s.\n"
msgstr "sikertelen: %s.\n"

#: src/host.c:674
msgid "failed: timed out.\n"
msgstr "sikertelen: idõtúllépés.\n"

#: src/host.c:762
msgid "Host not found"
msgstr "Gép nem található"

#: src/host.c:764
msgid "Unknown error"
msgstr "Ismeretlen hiba"

#: src/html-url.c:293
#, c-format
msgid "%s: Cannot resolve incomplete link %s.\n"
msgstr "%s: nem lehet megtalálni a hiányos %s linket.\n"

#. this is fatal
#: src/http.c:674
msgid "Failed to set up an SSL context\n"
msgstr "SSL-környezet beállítása sikertelen\n"

#: src/http.c:680
#, c-format
msgid "Failed to load certificates from %s\n"
msgstr "Tanúsítványok betöltése %s-ról sikertelen\n"

#: src/http.c:684 src/http.c:692
msgid "Trying without the specified certificate\n"
msgstr "Megpróbálom a megadott igazolás nélkül\n"

#: src/http.c:688
#, c-format
msgid "Failed to get certificate key from %s\n"
msgstr "Tanúsítványkulcs megszerzése %s-ról sikertelen\n"

#: src/http.c:761 src/http.c:1809
msgid "Unable to establish SSL connection.\n"
msgstr "Nem lehet létrehozni SSL-kapcsolatot.\n"

#: src/http.c:770
#, c-format
msgid "Reusing connection to %s:%hu.\n"
msgstr "Újrahasználom a kapcsolatot %s:%hu-hoz.\n"

#: src/http.c:1034
#, c-format
msgid "Failed writing HTTP request: %s.\n"
msgstr "A HTTP kérés írása sikertelen: %s.\n"

#: src/http.c:1039
#, c-format
msgid "%s request sent, awaiting response... "
msgstr "%s kérés elküldve, várom a választ... "

#: src/http.c:1083
msgid "End of file while parsing headers.\n"
msgstr "Fájl vége miközben a fejlécet olvasom.\n"

#: src/http.c:1093
#, c-format
msgid "Read error (%s) in headers.\n"
msgstr "Olvasási hiba (%s) a fejlécben.\n"

#: src/http.c:1128
msgid "No data received"
msgstr "Nem érkezett adat"

#: src/http.c:1130
msgid "Malformed status line"
msgstr "Rosszul formázott állapot vonal"

#: src/http.c:1135
msgid "(no description)"
msgstr "(nincs leírás)"

#: src/http.c:1267
msgid "Authorization failed.\n"
msgstr "Azonosítás sikertelen.\n"

#: src/http.c:1274
msgid "Unknown authentication scheme.\n"
msgstr "Ismeretlen azonosítási módszer.\n"

#: src/http.c:1314
#, c-format
msgid "Location: %s%s\n"
msgstr "Hely: %s%s\n"

#: src/http.c:1315 src/http.c:1454
msgid "unspecified"
msgstr "nem megadott"

#: src/http.c:1316
msgid " [following]"
msgstr " [következik]"

#: src/http.c:1383
msgid ""
"\n"
"    The file is already fully retrieved; nothing to do.\n"
"\n"
msgstr ""
"\n"
"    A fájl már teljesen le van töltve; nincs mit csinálni.\n"
"\n"

#: src/http.c:1401
#, c-format
msgid ""
"\n"
"Continued download failed on this file, which conflicts with `-c'.\n"
"Refusing to truncate existing file `%s'.\n"
"\n"
msgstr ""
"\n"
"Folytatott letöltés sikertelen ennél a fájlnál, ami ellentmond `-c'-val.\n"
"Nem tördelem a létezõ `%s' fájlt.\n"
"\n"

#. No need to print this output if the body won't be
#. downloaded at all, or if the original server response is
#. printed.
#: src/http.c:1444
msgid "Length: "
msgstr "Hossz: "

#: src/http.c:1449
#, c-format
msgid " (%s to go)"
msgstr " (még %s)"

#: src/http.c:1454
msgid "ignored"
msgstr "figyelmen kívül hagyva"

#: src/http.c:1598
msgid "Warning: wildcards not supported in HTTP.\n"
msgstr "Figyelem: * és ? nem használható HTTP-nél.\n"

#. If opt.noclobber is turned on and file already exists, do not
#. retrieve the file
#: src/http.c:1628
#, c-format
msgid "File `%s' already there, will not retrieve.\n"
msgstr "A(z) `%s' fájl már létezik, nem töltöm le.\n"

#: src/http.c:1800
#, c-format
msgid "Cannot write to `%s' (%s).\n"
msgstr "Nem tudok írni `%s'-ba (%s).\n"

#: src/http.c:1819
#, c-format
msgid "ERROR: Redirection (%d) without location.\n"
msgstr "HIBA: Átirányítás (%d) helyzet nélkül.\n"

#: src/http.c:1851
#, c-format
msgid "%s ERROR %d: %s.\n"
msgstr "%s HIBA %d: %s.\n"

#: src/http.c:1864
msgid "Last-modified header missing -- time-stamps turned off.\n"
msgstr "Utolsó módosított fejléc hiányzik -- idõbejegyzés kikapcsolva.\n"

#: src/http.c:1872
msgid "Last-modified header invalid -- time-stamp ignored.\n"
msgstr "Utolsó módosított fejléc helytelen -- idõbejegyzés figyelmen kívül hagyva.\n"

#: src/http.c:1895
#, c-format
msgid ""
"Server file no newer than local file `%s' -- not retrieving.\n"
"\n"
msgstr ""
"A szerveren lévõ `%s' fájl nem újabb mint a helyi -- nem töltöm le.\n"
"\n"

#: src/http.c:1903
#, c-format
msgid "The sizes do not match (local %ld) -- retrieving.\n"
msgstr "A méretek nem egyeznek (helyi %ld) -- letöltöm.\n"

#: src/http.c:1907
msgid "Remote file is newer, retrieving.\n"
msgstr "Távoli fájl újabb, letöltöm.\n"

#: src/http.c:1948
#, c-format
msgid ""
"%s (%s) - `%s' saved [%ld/%ld]\n"
"\n"
msgstr ""
"%s (%s) - `%s' lementve [%ld/%ld]\n"
"\n"

#: src/http.c:1998
#, c-format
msgid "%s (%s) - Connection closed at byte %ld. "
msgstr "%s (%s) - Kapcsolat bezárva a %ld. bájtnál. "

#: src/http.c:2007
#, c-format
msgid ""
"%s (%s) - `%s' saved [%ld/%ld])\n"
"\n"
msgstr ""
"%s (%s) - `%s' lementve [%ld/%ld])\n"
"\n"

#: src/http.c:2028
#, c-format
msgid "%s (%s) - Connection closed at byte %ld/%ld. "
msgstr "%s (%s) - Kapcsolat bezárva a %ld/%ld. bájtnál. "

#: src/http.c:2040
#, c-format
msgid "%s (%s) - Read error at byte %ld (%s)."
msgstr "%s (%s) - Olvasási hiba a %ld. bájtnál (%s). "

#: src/http.c:2049
#, c-format
msgid "%s (%s) - Read error at byte %ld/%ld (%s). "
msgstr "%s (%s) - Olvasási hiba a %ld/%ld. bájtnál (%s). "

#: src/init.c:342
#, c-format
msgid "%s: WGETRC points to %s, which doesn't exist.\n"
msgstr "%s: WGETRC %s-ra mutat, ami nem létezik.\n"

#: src/init.c:398 src/netrc.c:276
#, c-format
msgid "%s: Cannot read %s (%s).\n"
msgstr "%s: Nem lehet olvasni %s-t (%s).\n"

#: src/init.c:416 src/init.c:422
#, c-format
msgid "%s: Error in %s at line %d.\n"
msgstr "%s: Hiba %s-ban a %d-ik sornál.\n"

#: src/init.c:454
#, c-format
msgid "%s: Warning: Both system and user wgetrc point to `%s'.\n"
msgstr "%s: Figyelem: Mind a rendszer és a felhasználói wgetrc `%s'-re mutat.\n"

#: src/init.c:594
#, c-format
msgid "%s: Invalid --execute command `%s'\n"
msgstr "%s: Hibás --execute parancs `%s'\n"

#: src/init.c:630
#, c-format
msgid "%s: %s: Invalid boolean `%s', use `on' or `off'.\n"
msgstr "%s: %s: Hibás boolean `%s', használja az `on' vagy `off' szavakat.\n"

#: src/init.c:673
#, c-format
msgid "%s: %s: Invalid boolean `%s', use always, on, off, or never.\n"
msgstr "%s: %s: Hibás boolean `%s', használja az always, on, off vagy never szavakat.\n"

#: src/init.c:691
#, c-format
msgid "%s: %s: Invalid number `%s'.\n"
msgstr "%s: %s:Hibás szám `%s'.\n"

#: src/init.c:930 src/init.c:949
#, c-format
msgid "%s: %s: Invalid byte value `%s'\n"
msgstr "%s: %s: Hibás bájt érték `%s'.\n"

#: src/init.c:974
#, c-format
msgid "%s: %s: Invalid time period `%s'\n"
msgstr "%s: %s: Hibás idõ intervallum `%s'.\n"

#: src/init.c:1051
#, c-format
msgid "%s: %s: Invalid header `%s'.\n"
msgstr "%s: %s: Hibás fejléc `%s'.\n"

#: src/init.c:1106
#, c-format
msgid "%s: %s: Invalid progress type `%s'.\n"
msgstr "%s: %s: Helytelen típus `%s'.\n"

#: src/init.c:1157
#, c-format
msgid "%s: %s: Invalid restriction `%s', use `unix' or `windows'.\n"
msgstr "%s: %s: Hibás megkötés `%s', használja a `unix'-t vagy `windows'-t.\n"

#: src/init.c:1198
#, c-format
msgid "%s: %s: Invalid value `%s'.\n"
msgstr "%s: %s: Hibás érték `%s'.\n"

#: src/log.c:636
#, c-format
msgid ""
"\n"
