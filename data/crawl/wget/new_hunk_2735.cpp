msgstr "%s: az opci�hoz sz�ks�g van argumentumra -- %c\n"

#: src/getopt.c:862
#, c-format
msgid "%s: option `-W %s' is ambiguous\n"
msgstr "%s: a `-W %s' opci� k�tes �rtelm�\n"

#: src/getopt.c:880
#, c-format
msgid "%s: option `-W %s' doesn't allow an argument\n"
msgstr "%s: a `-W %s' opci�hoz nem kell argumentum\n"

#: src/host.c:636
#, c-format
msgid "Resolving %s... "
msgstr "IP keres�s %s... "

#: src/host.c:656 src/host.c:672
#, c-format
msgid "failed: %s.\n"
msgstr "sikertelen: %s.\n"

#: src/host.c:674
msgid "failed: timed out.\n"
msgstr "sikertelen: id�t�ll�p�s.\n"

#: src/host.c:762
msgid "Host not found"
msgstr "G�p nem tal�lhat�"

#: src/host.c:764
msgid "Unknown error"
msgstr "Ismeretlen hiba"

#: src/html-url.c:293
#, c-format
msgid "%s: Cannot resolve incomplete link %s.\n"
msgstr "%s: nem lehet megtal�lni a hi�nyos %s linket.\n"

#. this is fatal
#: src/http.c:674
msgid "Failed to set up an SSL context\n"
msgstr "SSL-k�rnyezet be�ll�t�sa sikertelen\n"

#: src/http.c:680
#, c-format
msgid "Failed to load certificates from %s\n"
msgstr "Tan�s�tv�nyok bet�lt�se %s-r�l sikertelen\n"

#: src/http.c:684 src/http.c:692
msgid "Trying without the specified certificate\n"
msgstr "Megpr�b�lom a megadott igazol�s n�lk�l\n"

#: src/http.c:688
#, c-format
msgid "Failed to get certificate key from %s\n"
msgstr "Tan�s�tv�nykulcs megszerz�se %s-r�l sikertelen\n"

#: src/http.c:761 src/http.c:1809
msgid "Unable to establish SSL connection.\n"
msgstr "Nem lehet l�trehozni SSL-kapcsolatot.\n"

#: src/http.c:770
#, c-format
msgid "Reusing connection to %s:%hu.\n"
msgstr "�jrahaszn�lom a kapcsolatot %s:%hu-hoz.\n"

#: src/http.c:1034
#, c-format
msgid "Failed writing HTTP request: %s.\n"
msgstr "A HTTP k�r�s �r�sa sikertelen: %s.\n"

#: src/http.c:1039
#, c-format
msgid "%s request sent, awaiting response... "
msgstr "%s k�r�s elk�ldve, v�rom a v�laszt... "

#: src/http.c:1083
msgid "End of file while parsing headers.\n"
msgstr "F�jl v�ge mik�zben a fejl�cet olvasom.\n"

#: src/http.c:1093
#, c-format
msgid "Read error (%s) in headers.\n"
msgstr "Olvas�si hiba (%s) a fejl�cben.\n"

#: src/http.c:1128
msgid "No data received"
msgstr "Nem �rkezett adat"

#: src/http.c:1130
msgid "Malformed status line"
msgstr "Rosszul form�zott �llapot vonal"

#: src/http.c:1135
msgid "(no description)"
msgstr "(nincs le�r�s)"

#: src/http.c:1267
msgid "Authorization failed.\n"
msgstr "Azonos�t�s sikertelen.\n"

#: src/http.c:1274
msgid "Unknown authentication scheme.\n"
msgstr "Ismeretlen azonos�t�si m�dszer.\n"

#: src/http.c:1314
#, c-format
msgid "Location: %s%s\n"
msgstr "Hely: %s%s\n"

#: src/http.c:1315 src/http.c:1454
msgid "unspecified"
msgstr "nem megadott"

#: src/http.c:1316
msgid " [following]"
msgstr " [k�vetkezik]"

#: src/http.c:1383
msgid ""
"\n"
"    The file is already fully retrieved; nothing to do.\n"
"\n"
msgstr ""
"\n"
"    A f�jl m�r teljesen le van t�ltve; nincs mit csin�lni.\n"
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
"Folytatott let�lt�s sikertelen enn�l a f�jln�l, ami ellentmond `-c'-val.\n"
"Nem t�rdelem a l�tez� `%s' f�jlt.\n"
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
msgstr " (m�g %s)"

#: src/http.c:1454
msgid "ignored"
msgstr "figyelmen k�v�l hagyva"

#: src/http.c:1598
msgid "Warning: wildcards not supported in HTTP.\n"
msgstr "Figyelem: * �s ? nem haszn�lhat� HTTP-n�l.\n"

#. If opt.noclobber is turned on and file already exists, do not
#. retrieve the file
#: src/http.c:1628
#, c-format
msgid "File `%s' already there, will not retrieve.\n"
msgstr "A(z) `%s' f�jl m�r l�tezik, nem t�lt�m le.\n"

#: src/http.c:1800
#, c-format
msgid "Cannot write to `%s' (%s).\n"
msgstr "Nem tudok �rni `%s'-ba (%s).\n"

#: src/http.c:1819
#, c-format
msgid "ERROR: Redirection (%d) without location.\n"
msgstr "HIBA: �tir�ny�t�s (%d) helyzet n�lk�l.\n"

#: src/http.c:1851
#, c-format
msgid "%s ERROR %d: %s.\n"
msgstr "%s HIBA %d: %s.\n"

#: src/http.c:1864
msgid "Last-modified header missing -- time-stamps turned off.\n"
msgstr "Utols� m�dos�tott fejl�c hi�nyzik -- id�bejegyz�s kikapcsolva.\n"

#: src/http.c:1872
msgid "Last-modified header invalid -- time-stamp ignored.\n"
msgstr "Utols� m�dos�tott fejl�c helytelen -- id�bejegyz�s figyelmen k�v�l hagyva.\n"

#: src/http.c:1895
#, c-format
msgid ""
"Server file no newer than local file `%s' -- not retrieving.\n"
"\n"
msgstr ""
"A szerveren l�v� `%s' f�jl nem �jabb mint a helyi -- nem t�lt�m le.\n"
"\n"

#: src/http.c:1903
#, c-format
msgid "The sizes do not match (local %ld) -- retrieving.\n"
msgstr "A m�retek nem egyeznek (helyi %ld) -- let�lt�m.\n"

#: src/http.c:1907
msgid "Remote file is newer, retrieving.\n"
msgstr "T�voli f�jl �jabb, let�lt�m.\n"

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
msgstr "%s (%s) - Kapcsolat bez�rva a %ld. b�jtn�l. "

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
msgstr "%s (%s) - Kapcsolat bez�rva a %ld/%ld. b�jtn�l. "

#: src/http.c:2040
#, c-format
msgid "%s (%s) - Read error at byte %ld (%s)."
msgstr "%s (%s) - Olvas�si hiba a %ld. b�jtn�l (%s). "

#: src/http.c:2049
#, c-format
msgid "%s (%s) - Read error at byte %ld/%ld (%s). "
msgstr "%s (%s) - Olvas�si hiba a %ld/%ld. b�jtn�l (%s). "

#: src/init.c:342
#, c-format
msgid "%s: WGETRC points to %s, which doesn't exist.\n"
msgstr "%s: WGETRC %s-ra mutat, ami nem l�tezik.\n"

#: src/init.c:398 src/netrc.c:276
#, c-format
msgid "%s: Cannot read %s (%s).\n"
msgstr "%s: Nem lehet olvasni %s-t (%s).\n"

#: src/init.c:416 src/init.c:422
#, c-format
msgid "%s: Error in %s at line %d.\n"
msgstr "%s: Hiba %s-ban a %d-ik sorn�l.\n"

#: src/init.c:454
#, c-format
msgid "%s: Warning: Both system and user wgetrc point to `%s'.\n"
msgstr "%s: Figyelem: Mind a rendszer �s a felhaszn�l�i wgetrc `%s'-re mutat.\n"

#: src/init.c:594
#, c-format
msgid "%s: Invalid --execute command `%s'\n"
msgstr "%s: Hib�s --execute parancs `%s'\n"

#: src/init.c:630
#, c-format
msgid "%s: %s: Invalid boolean `%s', use `on' or `off'.\n"
msgstr "%s: %s: Hib�s boolean `%s', haszn�lja az `on' vagy `off' szavakat.\n"

#: src/init.c:673
#, c-format
msgid "%s: %s: Invalid boolean `%s', use always, on, off, or never.\n"
msgstr "%s: %s: Hib�s boolean `%s', haszn�lja az always, on, off vagy never szavakat.\n"

#: src/init.c:691
#, c-format
msgid "%s: %s: Invalid number `%s'.\n"
msgstr "%s: %s:Hib�s sz�m `%s'.\n"

#: src/init.c:930 src/init.c:949
#, c-format
msgid "%s: %s: Invalid byte value `%s'\n"
msgstr "%s: %s: Hib�s b�jt �rt�k `%s'.\n"

#: src/init.c:974
#, c-format
msgid "%s: %s: Invalid time period `%s'\n"
msgstr "%s: %s: Hib�s id� intervallum `%s'.\n"

#: src/init.c:1051
#, c-format
msgid "%s: %s: Invalid header `%s'.\n"
msgstr "%s: %s: Hib�s fejl�c `%s'.\n"

#: src/init.c:1106
#, c-format
msgid "%s: %s: Invalid progress type `%s'.\n"
msgstr "%s: %s: Helytelen t�pus `%s'.\n"

#: src/init.c:1157
#, c-format
msgid "%s: %s: Invalid restriction `%s', use `unix' or `windows'.\n"
msgstr "%s: %s: Hib�s megk�t�s `%s', haszn�lja a `unix'-t vagy `windows'-t.\n"

#: src/init.c:1198
#, c-format
msgid "%s: %s: Invalid value `%s'.\n"
msgstr "%s: %s: Hib�s �rt�k `%s'.\n"

#: src/log.c:636
#, c-format
msgid ""
"\n"
