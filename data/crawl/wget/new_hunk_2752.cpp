msgid "No headers, assuming HTTP/0.9"
msgstr "Bez hlavičiek, predpokladám HTTP/0.9"

#: src/http.c:1204
msgid "Disabling SSL due to encountered errors.\n"
msgstr "Deaktivujem SSL z dôvodu výskytu chýb.\n"

#: src/http.c:1374
#, c-format
msgid "POST data file `%s' missing: %s\n"
msgstr "Chýba POST dátový súbor `%s': %s\n"

# , c-format
#: src/http.c:1423
#, c-format
msgid "Reusing existing connection to %s:%d.\n"
msgstr "Používam existujúce spojenie s %s:%d.\n"

#: src/http.c:1492
#, c-format
msgid "Failed reading proxy response: %s\n"
msgstr "Zlyhalo čítanie odpovede z proxy: %s\n"

#: src/http.c:1512
#, c-format
msgid "Proxy tunneling failed: %s"
msgstr "Tunelovanie proxy zlyhalo: %s"

# , c-format
#: src/http.c:1557
#, c-format
msgid "%s request sent, awaiting response... "
msgstr "%s požiadavka odoslaná, čakám na odpoveď... "

#: src/http.c:1568
msgid "No data received.\n"
msgstr "Neboli prijaté žiadne dáta.\n"

# , c-format
#: src/http.c:1575
#, c-format
msgid "Read error (%s) in headers.\n"
msgstr "Chyba (%s) pri čítaní hlavičiek.\n"

#. If the authentication header is missing or
#. unrecognized, there's no sense in retrying.
#: src/http.c:1660
msgid "Unknown authentication scheme.\n"
msgstr "Neznámy spôsob autentifikácie.\n"

#: src/http.c:1684
msgid "Authorization failed.\n"
msgstr "Autorizácia zlyhala.\n"

#: src/http.c:1698
msgid "Malformed status line"
msgstr "Odpoveď servera má skomolený stavový riadok"

#: src/http.c:1700
msgid "(no description)"
msgstr "(bez popisu)"

# , c-format
#: src/http.c:1763
#, c-format
msgid "Location: %s%s\n"
msgstr "Presmerované na: %s%s\n"

#: src/http.c:1764 src/http.c:1871
msgid "unspecified"
msgstr "neudané"

#: src/http.c:1765
msgid " [following]"
msgstr " [nasledujem]"

#. If `-c' is in use and the file has been fully downloaded (or
#. the remote file has shrunk), Wget effectively requests bytes
#. after the end of file and the server response with 416.
#: src/http.c:1821
msgid ""
"\n"
"    The file is already fully retrieved; nothing to do.\n"
