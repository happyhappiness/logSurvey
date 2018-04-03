#. No luck.
#. #### This message SUCKS.  We should see what was the
#. reason that nothing was retrieved.
#: src/ftp.c:1778
#, c-format
msgid "No matches on pattern `%s'.\n"
msgstr "Nincs találat a(z) \"%s\" mintához .\n"

#: src/ftp.c:1844
#, c-format
msgid "Wrote HTML-ized index to `%s' [%s].\n"
msgstr "A HTML-esített index kiírva a(z) \"%s\" [%s] fájlba.\n"

#: src/ftp.c:1849
#, c-format
msgid "Wrote HTML-ized index to `%s'.\n"
msgstr "A HTML-esített index kiírva a(z) \"%s\" fájlba.\n"

#: src/getopt.c:675
#, c-format
msgid "%s: option `%s' is ambiguous\n"
msgstr "%s: a(z) \"%s\" kapcsoló nem egyértelmű\n"

#: src/getopt.c:700
#, c-format
msgid "%s: option `--%s' doesn't allow an argument\n"
msgstr "%s: a(z) \"--%s\" kapcsoló nem enged meg argumentumot\n"

#: src/getopt.c:705
#, c-format
msgid "%s: option `%c%s' doesn't allow an argument\n"
msgstr "%s: a(z) \"%c%s\" kapcsoló nem enged meg argumentumot\n"

#: src/getopt.c:723 src/getopt.c:896
#, c-format
msgid "%s: option `%s' requires an argument\n"
msgstr "%s: a(z) \"%s\" kapcsolóhoz argumentum szükséges\n"

#. --option
#: src/getopt.c:752
#, c-format
msgid "%s: unrecognized option `--%s'\n"
msgstr "%s: a(z) \"--%s\" kapcsoló ismeretlen\n"

#. +option or -option
#: src/getopt.c:756
#, c-format
msgid "%s: unrecognized option `%c%s'\n"
msgstr "%s: a(z) \"%c%s\" kapcsoló ismeretlen\n"

#. 1003.2 specifies the format of this message.
#: src/getopt.c:782
#, c-format
msgid "%s: illegal option -- %c\n"
msgstr "%s: illegális kapcsoló -- %c\n"

#: src/getopt.c:785
#, c-format
msgid "%s: invalid option -- %c\n"
msgstr "%s: érvénytelen kapcsoló -- %c\n"

#. 1003.2 specifies the format of this message.
#: src/getopt.c:815 src/getopt.c:945
#, c-format
msgid "%s: option requires an argument -- %c\n"
msgstr "%s: a kapcsoló egy argumentumot igényel -- %c\n"

#: src/getopt.c:862
#, c-format
msgid "%s: option `-W %s' is ambiguous\n"
msgstr "%s: a \"-W %s\" kapcsoló nem egyértelmű\n"

#: src/getopt.c:880
#, c-format
msgid "%s: option `-W %s' doesn't allow an argument\n"
msgstr "%s: a \"-W %s\" kapcsoló nem enged meg argumentumot\n"

#: src/host.c:366
msgid "Unknown host"
msgstr "Ismeretlen kiszolgáló"

#. Message modeled after what gai_strerror returns in similar
#. circumstances.
#: src/host.c:370
msgid "Temporary failure in name resolution"
msgstr "Átmeneti névfeloldási hiba"

#: src/host.c:372
msgid "Unknown error"
msgstr "Ismeretlen hiba"

#: src/host.c:751
#, c-format
msgid "Resolving %s... "
msgstr "%s feloldása... "

#: src/host.c:798
msgid "failed: No IPv4/IPv6 addresses for host.\n"
msgstr "meghiúsult: nem található IPv4/IPv6 cím a géphez.\n"

#: src/host.c:821
msgid "failed: timed out.\n"
msgstr "meghiúsult: időtúllépés.\n"

#: src/html-url.c:298
#, c-format
msgid "%s: Cannot resolve incomplete link %s.\n"
msgstr "%s: nem oldható fel a hiányos %s hivatkozás.\n"

#: src/html-url.c:705
#, c-format
msgid "%s: Invalid URL %s: %s\n"
msgstr "%s: Érvénytelen URL: %s: %s.\n"

#: src/http.c:373
#, c-format
msgid "Failed writing HTTP request: %s.\n"
msgstr "A HTTP kérés írása meghiúsult: %s.\n"

#: src/http.c:687
msgid "No headers, assuming HTTP/0.9"
msgstr "Nincsenek fejlécek, HTTP/0.9 feltételezése"

#: src/http.c:1204
msgid "Disabling SSL due to encountered errors.\n"
msgstr "A tapasztalt hibák miatt az SSL letiltásra kerül.\n"

#: src/http.c:1374
#, c-format
msgid "POST data file `%s' missing: %s\n"
msgstr "A(z) \"%s\" POST adatfájl hiányzik: %s\n"

#: src/http.c:1423
#, c-format
msgid "Reusing existing connection to %s:%d.\n"
msgstr "Újrahasználom a kapcsolatot a következőhöz: %s:%d.\n"

#: src/http.c:1492
#, c-format
msgid "Failed reading proxy response: %s\n"
msgstr "A proxy válasz olvasása meghiúsult: %s\n"

#: src/http.c:1512
#, c-format
msgid "Proxy tunneling failed: %s"
msgstr "A proxy alagutazás meghiúsult: %s"

#: src/http.c:1557
#, c-format
msgid "%s request sent, awaiting response... "
msgstr "%s kérés elküldve, várom a választ... "

#: src/http.c:1568
msgid "No data received.\n"
msgstr "Nem érkezett adat.\n"

#: src/http.c:1575
#, c-format
msgid "Read error (%s) in headers.\n"
msgstr "Olvasási hiba (%s) a fejlécekben.\n"

#. If the authentication header is missing or
#. unrecognized, there's no sense in retrying.
#: src/http.c:1660
msgid "Unknown authentication scheme.\n"
msgstr "Ismeretlen hitelesítési séma.\n"

#: src/http.c:1684
msgid "Authorization failed.\n"
msgstr "A hitelesítés meghiúsult.\n"

#: src/http.c:1698
msgid "Malformed status line"
msgstr "Rosszul formázott állapotsor"

#: src/http.c:1700
msgid "(no description)"
msgstr "(nincs leírás)"

#: src/http.c:1763
#, c-format
msgid "Location: %s%s\n"
msgstr "Hely: %s%s\n"

#: src/http.c:1764 src/http.c:1871
msgid "unspecified"
msgstr "nincs megadva"

#: src/http.c:1765
msgid " [following]"
msgstr " [következik]"

#. If `-c' is in use and the file has been fully downloaded (or
#. the remote file has shrunk), Wget effectively requests bytes
#. after the end of file and the server response with 416.
#: src/http.c:1821
msgid ""
"\n"
"    The file is already fully retrieved; nothing to do.\n"
