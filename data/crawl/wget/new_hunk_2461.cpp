#. No luck.
#. #### This message SUCKS.  We should see what was the
#. reason that nothing was retrieved.
#: src/ftp.c:1753
#, c-format
msgid "No matches on pattern `%s'.\n"
msgstr "Nincs találat a(z) \"%s\" mintához .\n"

#: src/ftp.c:1819
#, c-format
msgid "Wrote HTML-ized index to `%s' [%s].\n"
msgstr "A HTML-esített index kiírva a(z) \"%s\" [%s] fájlba.\n"

#: src/ftp.c:1824
#, c-format
msgid "Wrote HTML-ized index to `%s'.\n"
msgstr "A HTML-esített index kiírva a(z) \"%s\" fájlba.\n"

#: src/getopt.c:670
#, c-format
msgid "%s: option `%s' is ambiguous\n"
msgstr "%s: a(z) \"%s\" kapcsoló nem egyértelmű\n"

#: src/getopt.c:695
#, c-format
msgid "%s: option `--%s' doesn't allow an argument\n"
msgstr "%s: a(z) \"--%s\" kapcsoló nem enged meg argumentumot\n"

#: src/getopt.c:700
#, c-format
msgid "%s: option `%c%s' doesn't allow an argument\n"
msgstr "%s: a(z) \"%c%s\" kapcsoló nem enged meg argumentumot\n"

#: src/getopt.c:718 src/getopt.c:891
#, c-format
msgid "%s: option `%s' requires an argument\n"
msgstr "%s: a(z) \"%s\" kapcsolóhoz argumentum szükséges\n"

#. --option
#: src/getopt.c:747
#, c-format
msgid "%s: unrecognized option `--%s'\n"
msgstr "%s: a(z) \"--%s\" kapcsoló ismeretlen\n"

#. +option or -option
#: src/getopt.c:751
#, c-format
msgid "%s: unrecognized option `%c%s'\n"
msgstr "%s: a(z) \"%c%s\" kapcsoló ismeretlen\n"

#. 1003.2 specifies the format of this message.
#: src/getopt.c:777
#, c-format
msgid "%s: illegal option -- %c\n"
msgstr "%s: illegális kapcsoló -- %c\n"

#: src/getopt.c:780
#, c-format
msgid "%s: invalid option -- %c\n"
msgstr "%s: érvénytelen kapcsoló -- %c\n"

#. 1003.2 specifies the format of this message.
#: src/getopt.c:810 src/getopt.c:940
#, c-format
msgid "%s: option requires an argument -- %c\n"
msgstr "%s: a kapcsoló egy argumentumot igényel -- %c\n"

#: src/getopt.c:857
#, c-format
msgid "%s: option `-W %s' is ambiguous\n"
msgstr "%s: a \"-W %s\" kapcsoló nem egyértelmű\n"

#: src/getopt.c:875
#, c-format
msgid "%s: option `-W %s' doesn't allow an argument\n"
msgstr "%s: a \"-W %s\" kapcsoló nem enged meg argumentumot\n"

#: src/host.c:347
msgid "Unknown host"
msgstr "Ismeretlen kiszolgáló"

#. Message modeled after what gai_strerror returns in similar
#. circumstances.
#: src/host.c:351
msgid "Temporary failure in name resolution"
msgstr "Átmeneti névfeloldási hiba"

#: src/host.c:353
msgid "Unknown error"
msgstr "Ismeretlen hiba"

#: src/host.c:714
#, c-format
msgid "Resolving %s... "
msgstr "%s feloldása... "

#: src/host.c:761
msgid "failed: No IPv4/IPv6 addresses for host.\n"
msgstr "meghiúsult: nem található IPv4/IPv6 cím a géphez.\n"

#: src/host.c:784
msgid "failed: timed out.\n"
msgstr "meghiúsult: időtúllépés.\n"

#: src/html-url.c:288
#, c-format
msgid "%s: Cannot resolve incomplete link %s.\n"
msgstr "%s: nem oldható fel a hiányos %s hivatkozás.\n"

#: src/html-url.c:695
#, c-format
msgid "%s: Invalid URL %s: %s\n"
msgstr "%s: Érvénytelen URL: %s: %s.\n"

#: src/http.c:367
#, c-format
msgid "Failed writing HTTP request: %s.\n"
msgstr "A HTTP kérés írása meghiúsult: %s.\n"

#: src/http.c:736
msgid "No headers, assuming HTTP/0.9"
msgstr "Nincsenek fejlécek, HTTP/0.9 feltételezése"

#: src/http.c:1413
msgid "Disabling SSL due to encountered errors.\n"
msgstr "A tapasztalt hibák miatt az SSL letiltásra kerül.\n"

#: src/http.c:1566
#, c-format
msgid "POST data file `%s' missing: %s\n"
msgstr "A(z) \"%s\" POST adatfájl hiányzik: %s\n"

#: src/http.c:1615
#, c-format
msgid "Reusing existing connection to %s:%d.\n"
msgstr "Újrahasználom a kapcsolatot a következőhöz: %s:%d.\n"

#: src/http.c:1684
#, c-format
msgid "Failed reading proxy response: %s\n"
msgstr "A proxy válasz olvasása meghiúsult: %s\n"

#: src/http.c:1704
#, c-format
msgid "Proxy tunneling failed: %s"
msgstr "A proxy alagutazás meghiúsult: %s"

#: src/http.c:1749
#, c-format
msgid "%s request sent, awaiting response... "
msgstr "%s kérés elküldve, várom a választ... "

#: src/http.c:1760
msgid "No data received.\n"
msgstr "Nem érkezett adat.\n"

#: src/http.c:1767
#, c-format
msgid "Read error (%s) in headers.\n"
msgstr "Olvasási hiba (%s) a fejlécekben.\n"

#. If opt.noclobber is turned on and file already exists, do not
#. retrieve the file
#: src/http.c:1813
#, c-format
msgid ""
"File `%s' already there; not retrieving.\n"
"\n"
msgstr ""
"A(z) \"%s\" fájl már létezik, nem töltöm le.\n"
"\n"

#. If the authentication header is missing or
#. unrecognized, there's no sense in retrying.
#: src/http.c:1966
msgid "Unknown authentication scheme.\n"
msgstr "Ismeretlen hitelesítési séma.\n"

#: src/http.c:1997
msgid "Authorization failed.\n"
msgstr "A hitelesítés meghiúsult.\n"

#: src/http.c:2011
msgid "Malformed status line"
msgstr "Rosszul formázott állapotsor"

#: src/http.c:2013
msgid "(no description)"
msgstr "(nincs leírás)"

#: src/http.c:2076
#, c-format
msgid "Location: %s%s\n"
msgstr "Hely: %s%s\n"

#: src/http.c:2077 src/http.c:2184
msgid "unspecified"
msgstr "nincs megadva"

#: src/http.c:2078
msgid " [following]"
msgstr " [következik]"

#. If `-c' is in use and the file has been fully downloaded (or
#. the remote file has shrunk), Wget effectively requests bytes
#. after the end of file and the server response with 416.
#: src/http.c:2134
msgid ""
"\n"
"    The file is already fully retrieved; nothing to do.\n"
