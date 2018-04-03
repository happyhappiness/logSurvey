msgstr "%s: az opci�hoz sz�ks�g van argumentumra -- %c\n"

#: src/getopt.c:862
#, fuzzy, c-format
msgid "%s: option `-W %s' is ambiguous\n"
msgstr "%s: a `%s' opci� k�tes �rtelm�\n"

#: src/getopt.c:880
#, fuzzy, c-format
msgid "%s: option `-W %s' doesn't allow an argument\n"
msgstr "%s: a `--%s' opci�hoz nem kell argumentum\n"

#: src/host.c:371
#, fuzzy
msgid "Unknown host"
msgstr "Ismeretlen hiba"

#. Message modeled after what gai_strerror returns in similar
#. circumstances.
#: src/host.c:375
msgid "Temporary failure in name resolution"
msgstr ""

#: src/host.c:377
msgid "Unknown error"
msgstr "Ismeretlen hiba"

#: src/host.c:756
#, c-format
msgid "Resolving %s... "
msgstr "IP keres�s %s... "

#: src/host.c:800 src/host.c:829
#, c-format
msgid "failed: %s.\n"
msgstr "nem siker�lt: %s.\n"

#: src/host.c:809
msgid "failed: No IPv4/IPv6 addresses for host.\n"
msgstr ""

#: src/host.c:832
#, fuzzy
msgid "failed: timed out.\n"
msgstr "nem siker�lt: %s.\n"

#: src/html-url.c:298
#, c-format
msgid "%s: Cannot resolve incomplete link %s.\n"
msgstr "%s: nem tudom megtal�lni a hi�nyos %s linket.\n"

#: src/http.c:373 src/http.c:1549
#, c-format
msgid "Failed writing HTTP request: %s.\n"
msgstr "A HTTP k�r�s �r�sa sikertelen: %s.\n"

#: src/http.c:687
msgid "No headers, assuming HTTP/0.9"
msgstr ""

#: src/http.c:1198
msgid "Disabling SSL due to encountered errors.\n"
msgstr ""

#: src/http.c:1417
#, fuzzy, c-format
msgid "Reusing existing connection to %s:%d.\n"
msgstr "�jrahaszn�lom a kapcsolatot %s:%hu-hoz.\n"

#: src/http.c:1479
#, fuzzy, c-format
msgid "Failed writing to proxy: %s.\n"
msgstr "A HTTP k�r�s �r�sa sikertelen: %s.\n"

#: src/http.c:1488
#, fuzzy, c-format
msgid "Failed reading proxy response: %s\n"
msgstr "A HTTP k�r�s �r�sa sikertelen: %s.\n"

#: src/http.c:1508
#, c-format
msgid "Proxy tunneling failed: %s"
msgstr ""

#: src/http.c:1555
#, c-format
msgid "%s request sent, awaiting response... "
msgstr "%s k�r�s elk�ldve, v�rom a v�laszt... "

#: src/http.c:1566
#, fuzzy
msgid "No data received.\n"
msgstr "Nem �rkezett adat"

#: src/http.c:1573
#, c-format
msgid "Read error (%s) in headers.\n"
msgstr "Olvas�si hiba (%s) a fejl�cben.\n"

#. If the authentication header is missing or
#. unrecognized, there's no sense in retrying.
#: src/http.c:1658
msgid "Unknown authentication scheme.\n"
msgstr "Ismeretlen azonos�t�si m�dszer.\n"

#: src/http.c:1682
msgid "Authorization failed.\n"
msgstr "Azonos�t�s sikertelen.\n"

#: src/http.c:1696
msgid "Malformed status line"
msgstr "Rosszul form�zott �llapot vonal"

#: src/http.c:1698
msgid "(no description)"
msgstr "(nincs le�r�s)"

#: src/http.c:1769
#, c-format
msgid "Location: %s%s\n"
msgstr "Hely: %s%s\n"

#: src/http.c:1770 src/http.c:1867
msgid "unspecified"
msgstr "nem megadott"

#: src/http.c:1771
msgid " [following]"
msgstr " [k�vetkezik]"

#. If `-c' is in use and the file has been fully downloaded (or
#. the remote file has shrunk), Wget effectively requests bytes
#. after the end of file and the server response with 416.
#: src/http.c:1817
msgid ""
"\n"
"    The file is already fully retrieved; nothing to do.\n"
"\n"
msgstr ""
"\n"
"    Az �llom�ny m�r teljesen le van t�ltve; nincs mit csin�jak.\n"
"\n"

#. No need to print this output if the body won't be
#. downloaded at all, or if the original server response is
#. printed.
#: src/http.c:1847
msgid "Length: "
msgstr "Hossz: "

#: src/http.c:1867
msgid "ignored"
msgstr "figyelmen kiv�l hagyva"

#: src/http.c:2007
msgid "Warning: wildcards not supported in HTTP.\n"
msgstr "Figyelem: * �s ? nem haszn�lhat� HTTP-n�l.\n"

#. If opt.noclobber is turned on and file already exists, do not
#. retrieve the file
#: src/http.c:2042
#, c-format
msgid "File `%s' already there, will not retrieve.\n"
msgstr "A `%s' �llom�ny m�r l�tezik, nem t�lt�m le.\n"

#: src/http.c:2232
#, c-format
msgid "Cannot write to `%s' (%s).\n"
msgstr "Nem tudok �rni `%s'-ba (%s).\n"

#. Another fatal error.
#: src/http.c:2239
msgid "Unable to establish SSL connection.\n"
msgstr "Nem siker�lt SSL kapcsolatot l�trehozni.\n"

#: src/http.c:2248
#, c-format
msgid "ERROR: Redirection (%d) without location.\n"
msgstr "HIBA: �tir�ny�t�s (%d) helyzet n�lk�l.\n"

#: src/http.c:2278
#, c-format
msgid "%s ERROR %d: %s.\n"
msgstr "%s HIBA %d: %s.\n"

#: src/http.c:2291
msgid "Last-modified header missing -- time-stamps turned off.\n"
msgstr "Utols� m�dos�tott fejl�c hi�nyzik -- id�bejegyz�s kikapcsolva.\n"

#: src/http.c:2299
msgid "Last-modified header invalid -- time-stamp ignored.\n"
msgstr ""
"Utols� m�dos�tott fejl�c helytelen -- id�bejegyz�s figyelmen kiv�l hagyva.\n"

#: src/http.c:2322
#, c-format
msgid ""
"Server file no newer than local file `%s' -- not retrieving.\n"
"\n"
msgstr ""
"A szerveren l�v� `%s' �llom�ny nem �jabb mint a helyi -- nem t�lt�m le.\n"
"\n"

#: src/http.c:2330
#, fuzzy, c-format
msgid "The sizes do not match (local %s) -- retrieving.\n"
msgstr "A m�retek nem eggyeznek (helyi %ld) -- let�lt�m.\n"

#: src/http.c:2335
msgid "Remote file is newer, retrieving.\n"
msgstr "T�voli �llom�ny �jabb, let�lt�m.\n"

#: src/http.c:2377
#, fuzzy, c-format
msgid ""
"%s (%s) - `%s' saved [%s/%s]\n"
"\n"
msgstr ""
"%s (%s) - `%s' lementve [%ld/%ld]\n"
"\n"

#: src/http.c:2434
#, fuzzy, c-format
msgid "%s (%s) - Connection closed at byte %s. "
msgstr "%s (%s) - Kapcsolat bez�rva a %ld-ik b�jtn�l. "

#: src/http.c:2443
#, fuzzy, c-format
msgid ""
"%s (%s) - `%s' saved [%s/%s])\n"
"\n"
msgstr ""
"%s (%s) - `%s' lementve [%ld/%ld])\n"
"\n"

#: src/http.c:2469
#, fuzzy, c-format
msgid "%s (%s) - Connection closed at byte %s/%s. "
msgstr "%s (%s) - Kapcsolat bez�rva a %ld/%ld-ik b�jtn�l. "

#: src/http.c:2483
#, fuzzy, c-format
msgid "%s (%s) - Read error at byte %s (%s)."
msgstr "%s (%s) - Olvas�si hiba a %ld-ik b�jtn�l (%s). "

#: src/http.c:2493
#, fuzzy, c-format
msgid "%s (%s) - Read error at byte %s/%s (%s). "
msgstr "%s (%s) - Olvas�si hiba a %ld/%ld-ik b�jtn�l (%s). "

#: src/init.c:369
#, c-format
msgid "%s: WGETRC points to %s, which doesn't exist.\n"
msgstr ""

#: src/init.c:433 src/netrc.c:277
#, c-format
msgid "%s: Cannot read %s (%s).\n"
msgstr "%s: Nem tudom olvasni %s-t (%s).\n"

#: src/init.c:451
#, c-format
msgid "%s: Error in %s at line %d.\n"
msgstr "%s: Hiba %s-ban a %d-ik sorn�l.\n"

#: src/init.c:457
#, fuzzy, c-format
msgid "%s: Syntax error in %s at line %d.\n"
msgstr "%s: Hiba %s-ban a %d-ik sorn�l.\n"

#: src/init.c:462
#, fuzzy, c-format
msgid "%s: Unknown command `%s' in %s at line %d.\n"
msgstr "%s: BUG: ismeretlen parancs `%s', �rt�k `%s'.\n"

#: src/init.c:507
#, c-format
msgid "%s: Warning: Both system and user wgetrc point to `%s'.\n"
msgstr ""
"%s: Figyelem: Mind a rendszer �s a felhaszn�l�i wgetrc `%s'-re mutat.\n"

#: src/init.c:661
#, fuzzy, c-format
msgid "%s: Invalid --execute command `%s'\n"
msgstr "%s: Helytelen megad�s `%s'\n"

#: src/init.c:707
#, fuzzy, c-format
msgid "%s: %s: Invalid boolean `%s', use `on' or `off'.\n"
msgstr "%s: %s: K�rem adja meg, hogy ki vagy bekapcsolva.\n"

#: src/init.c:750
#, fuzzy, c-format
msgid "%s: %s: Invalid boolean `%s', use always, on, off, or never.\n"
msgstr ""
"%s: %s: K�rem adja meg, hogy mindig, kikapcsolva, bekapcsolva vagy soha.\n"

#: src/init.c:767
#, fuzzy, c-format
msgid "%s: %s: Invalid number `%s'.\n"
msgstr "%s: %s: Helytelen megad�s `%s'.\n"

#: src/init.c:998 src/init.c:1017
#, fuzzy, c-format
msgid "%s: %s: Invalid byte value `%s'\n"
msgstr "%s: %s: Helytelen tipus `%s'.\n"

#: src/init.c:1042
#, fuzzy, c-format
msgid "%s: %s: Invalid time period `%s'\n"
msgstr "%s: %s: Helytelen megad�s `%s'.\n"

#: src/init.c:1096 src/init.c:1186 src/init.c:1281 src/init.c:1306
#, fuzzy, c-format
msgid "%s: %s: Invalid value `%s'.\n"
msgstr "%s: %s: Helytelen megad�s `%s'.\n"

#: src/init.c:1133
#, fuzzy, c-format
msgid "%s: %s: Invalid header `%s'.\n"
msgstr "%s: %s: Helytelen megad�s `%s'.\n"

#: src/init.c:1198
#, c-format
msgid "%s: %s: Invalid progress type `%s'.\n"
msgstr "%s: %s: Helytelen tipus `%s'.\n"

#: src/init.c:1249
#, fuzzy, c-format
msgid "%s: %s: Invalid restriction `%s', use `unix' or `windows'.\n"
msgstr "%s: %s: Helytelen megad�s `%s'.\n"

#: src/log.c:806
#, c-format
msgid ""
"\n"
