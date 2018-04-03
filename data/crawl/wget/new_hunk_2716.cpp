msgid "No headers, assuming HTTP/0.9"
msgstr "Sen ĉapoj, supozante HTTP/0.9"

#: src/http.c:1194
msgid "Disabling SSL due to encountered errors.\n"
msgstr ""

#: src/http.c:1413
#, c-format
msgid "Reusing existing connection to %s:%d.\n"
msgstr ""

#: src/http.c:1475
#, fuzzy, c-format
msgid "Failed writing to proxy: %s.\n"
msgstr "Eraro dum registrado al proxy: %s.\n"

#: src/http.c:1484
#, c-format
msgid "Failed reading proxy response: %s\n"
msgstr ""

#: src/http.c:1504
#, c-format
msgid "Proxy tunneling failed: %s"
msgstr ""

#: src/http.c:1551
#, c-format
msgid "%s request sent, awaiting response... "
msgstr ""

#: src/http.c:1562
msgid "No data received.\n"
msgstr "Ne datumo ricevita.\n"

#: src/http.c:1569
#, c-format
msgid "Read error (%s) in headers.\n"
msgstr "Leg-eraro (%s) ĉe ĉapoj.\n"

#. If the authentication header is missing or
#. unrecognized, there's no sense in retrying.
#: src/http.c:1657
msgid "Unknown authentication scheme.\n"
msgstr "Nekonata aŭtentokontrola ŝablono.\n"

#: src/http.c:1681
msgid "Authorization failed.\n"
msgstr ""

#: src/http.c:1695
msgid "Malformed status line"
msgstr ""

#: src/http.c:1697
msgid "(no description)"
msgstr ""

#: src/http.c:1768
#, c-format
msgid "Location: %s%s\n"
msgstr ""

#: src/http.c:1769 src/http.c:1869
msgid "unspecified"
msgstr ""

#: src/http.c:1770
msgid " [following]"
msgstr ""

#. If `-c' is in use and the file has been fully downloaded (or
#. the remote file has shrunk), Wget effectively requests bytes
#. after the end of file and the server response with 416.
#: src/http.c:1819
msgid ""
"\n"
"    The file is already fully retrieved; nothing to do.\n"
