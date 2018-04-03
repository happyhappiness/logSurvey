msgstr "%s: az opcióhoz szükség van argumentumra -- %c\n"

#: src/getopt.c:862
#, fuzzy, c-format
msgid "%s: option `-W %s' is ambiguous\n"
msgstr "%s: a `%s' opció kétes értelmû\n"

#: src/getopt.c:880
#, fuzzy, c-format
msgid "%s: option `-W %s' doesn't allow an argument\n"
msgstr "%s: a `--%s' opcióhoz nem kell argumentum\n"

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
msgstr "IP keresés %s... "

#: src/host.c:800 src/host.c:829
#, c-format
msgid "failed: %s.\n"
msgstr "nem sikerült: %s.\n"

#: src/host.c:809
msgid "failed: No IPv4/IPv6 addresses for host.\n"
msgstr ""

#: src/host.c:832
#, fuzzy
msgid "failed: timed out.\n"
msgstr "nem sikerült: %s.\n"

#: src/html-url.c:298
#, c-format
msgid "%s: Cannot resolve incomplete link %s.\n"
msgstr "%s: nem tudom megtalálni a hiányos %s linket.\n"

#: src/http.c:373 src/http.c:1549
#, c-format
msgid "Failed writing HTTP request: %s.\n"
msgstr "A HTTP kérés írása sikertelen: %s.\n"

#: src/http.c:687
msgid "No headers, assuming HTTP/0.9"
msgstr ""

#: src/http.c:1198
msgid "Disabling SSL due to encountered errors.\n"
msgstr ""

#: src/http.c:1417
#, fuzzy, c-format
msgid "Reusing existing connection to %s:%d.\n"
msgstr "Újrahasználom a kapcsolatot %s:%hu-hoz.\n"

#: src/http.c:1479
#, fuzzy, c-format
msgid "Failed writing to proxy: %s.\n"
msgstr "A HTTP kérés írása sikertelen: %s.\n"

#: src/http.c:1488
#, fuzzy, c-format
msgid "Failed reading proxy response: %s\n"
msgstr "A HTTP kérés írása sikertelen: %s.\n"

#: src/http.c:1508
#, c-format
msgid "Proxy tunneling failed: %s"
msgstr ""

#: src/http.c:1555
#, c-format
msgid "%s request sent, awaiting response... "
msgstr "%s kérés elküldve, várom a választ... "

#: src/http.c:1566
#, fuzzy
msgid "No data received.\n"
msgstr "Nem érkezett adat"

#: src/http.c:1573
#, c-format
msgid "Read error (%s) in headers.\n"
msgstr "Olvasási hiba (%s) a fejlécben.\n"

#. If the authentication header is missing or
#. unrecognized, there's no sense in retrying.
#: src/http.c:1658
msgid "Unknown authentication scheme.\n"
msgstr "Ismeretlen azonosítási módszer.\n"

#: src/http.c:1682
msgid "Authorization failed.\n"
msgstr "Azonosítás sikertelen.\n"

#: src/http.c:1696
msgid "Malformed status line"
msgstr "Rosszul formázott állapot vonal"

#: src/http.c:1698
msgid "(no description)"
msgstr "(nincs leírás)"

#: src/http.c:1769
#, c-format
msgid "Location: %s%s\n"
msgstr "Hely: %s%s\n"

#: src/http.c:1770 src/http.c:1867
msgid "unspecified"
msgstr "nem megadott"

#: src/http.c:1771
msgid " [following]"
msgstr " [következik]"

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
"    Az állomány már teljesen le van töltve; nincs mit csinájak.\n"
"\n"

#. No need to print this output if the body won't be
#. downloaded at all, or if the original server response is
#. printed.
#: src/http.c:1847
msgid "Length: "
msgstr "Hossz: "

#: src/http.c:1867
msgid "ignored"
msgstr "figyelmen kivül hagyva"

#: src/http.c:2007
msgid "Warning: wildcards not supported in HTTP.\n"
msgstr "Figyelem: * és ? nem használható HTTP-nél.\n"

#. If opt.noclobber is turned on and file already exists, do not
#. retrieve the file
#: src/http.c:2042
#, c-format
msgid "File `%s' already there, will not retrieve.\n"
msgstr "A `%s' állomány már létezik, nem töltöm le.\n"

#: src/http.c:2232
#, c-format
msgid "Cannot write to `%s' (%s).\n"
msgstr "Nem tudok írni `%s'-ba (%s).\n"

#. Another fatal error.
#: src/http.c:2239
msgid "Unable to establish SSL connection.\n"
msgstr "Nem sikerült SSL kapcsolatot létrehozni.\n"

#: src/http.c:2248
#, c-format
msgid "ERROR: Redirection (%d) without location.\n"
msgstr "HIBA: Átirányítás (%d) helyzet nélkül.\n"

#: src/http.c:2278
#, c-format
msgid "%s ERROR %d: %s.\n"
msgstr "%s HIBA %d: %s.\n"

#: src/http.c:2291
msgid "Last-modified header missing -- time-stamps turned off.\n"
msgstr "Utolsó módosított fejléc hiányzik -- idõbejegyzés kikapcsolva.\n"

#: src/http.c:2299
msgid "Last-modified header invalid -- time-stamp ignored.\n"
msgstr ""
"Utolsó módosított fejléc helytelen -- idõbejegyzés figyelmen kivûl hagyva.\n"

#: src/http.c:2322
#, c-format
msgid ""
"Server file no newer than local file `%s' -- not retrieving.\n"
"\n"
msgstr ""
"A szerveren lévõ `%s' állomány nem újabb mint a helyi -- nem töltöm le.\n"
"\n"

#: src/http.c:2330
#, fuzzy, c-format
msgid "The sizes do not match (local %s) -- retrieving.\n"
msgstr "A méretek nem eggyeznek (helyi %ld) -- letöltöm.\n"

#: src/http.c:2335
msgid "Remote file is newer, retrieving.\n"
msgstr "Távoli állomány újabb, letöltöm.\n"

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
msgstr "%s (%s) - Kapcsolat bezárva a %ld-ik bájtnál. "

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
msgstr "%s (%s) - Kapcsolat bezárva a %ld/%ld-ik bájtnál. "

#: src/http.c:2483
#, fuzzy, c-format
msgid "%s (%s) - Read error at byte %s (%s)."
msgstr "%s (%s) - Olvasási hiba a %ld-ik bájtnál (%s). "

#: src/http.c:2493
#, fuzzy, c-format
msgid "%s (%s) - Read error at byte %s/%s (%s). "
msgstr "%s (%s) - Olvasási hiba a %ld/%ld-ik bájtnál (%s). "

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
msgstr "%s: Hiba %s-ban a %d-ik sornál.\n"

#: src/init.c:457
#, fuzzy, c-format
msgid "%s: Syntax error in %s at line %d.\n"
msgstr "%s: Hiba %s-ban a %d-ik sornál.\n"

#: src/init.c:462
#, fuzzy, c-format
msgid "%s: Unknown command `%s' in %s at line %d.\n"
msgstr "%s: BUG: ismeretlen parancs `%s', érték `%s'.\n"

#: src/init.c:507
#, c-format
msgid "%s: Warning: Both system and user wgetrc point to `%s'.\n"
msgstr ""
"%s: Figyelem: Mind a rendszer és a felhasználói wgetrc `%s'-re mutat.\n"

#: src/init.c:661
#, fuzzy, c-format
msgid "%s: Invalid --execute command `%s'\n"
msgstr "%s: Helytelen megadás `%s'\n"

#: src/init.c:707
#, fuzzy, c-format
msgid "%s: %s: Invalid boolean `%s', use `on' or `off'.\n"
msgstr "%s: %s: Kérem adja meg, hogy ki vagy bekapcsolva.\n"

#: src/init.c:750
#, fuzzy, c-format
msgid "%s: %s: Invalid boolean `%s', use always, on, off, or never.\n"
msgstr ""
"%s: %s: Kérem adja meg, hogy mindig, kikapcsolva, bekapcsolva vagy soha.\n"

#: src/init.c:767
#, fuzzy, c-format
msgid "%s: %s: Invalid number `%s'.\n"
msgstr "%s: %s: Helytelen megadás `%s'.\n"

#: src/init.c:998 src/init.c:1017
#, fuzzy, c-format
msgid "%s: %s: Invalid byte value `%s'\n"
msgstr "%s: %s: Helytelen tipus `%s'.\n"

#: src/init.c:1042
#, fuzzy, c-format
msgid "%s: %s: Invalid time period `%s'\n"
msgstr "%s: %s: Helytelen megadás `%s'.\n"

#: src/init.c:1096 src/init.c:1186 src/init.c:1281 src/init.c:1306
#, fuzzy, c-format
msgid "%s: %s: Invalid value `%s'.\n"
msgstr "%s: %s: Helytelen megadás `%s'.\n"

#: src/init.c:1133
#, fuzzy, c-format
msgid "%s: %s: Invalid header `%s'.\n"
msgstr "%s: %s: Helytelen megadás `%s'.\n"

#: src/init.c:1198
#, c-format
msgid "%s: %s: Invalid progress type `%s'.\n"
msgstr "%s: %s: Helytelen tipus `%s'.\n"

#: src/init.c:1249
#, fuzzy, c-format
msgid "%s: %s: Invalid restriction `%s', use `unix' or `windows'.\n"
msgstr "%s: %s: Helytelen megadás `%s'.\n"

#: src/log.c:806
#, c-format
msgid ""
"\n"
