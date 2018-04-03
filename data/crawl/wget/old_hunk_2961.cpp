msgid "%s: Cannot resolve incomplete link %s.\n"
msgstr "%s: Ne mogu sastaviti nepotpun link %s.\n"

#: src/http.c:340 src/http.c:1469
#, c-format
msgid "Failed writing HTTP request: %s.\n"
msgstr "Nisam uspio poslati HTTP zahtjev: %s.\n"

#: src/http.c:654
msgid "No headers, assuming HTTP/0.9"
msgstr "Nema zaglavlja, pretpostavljam HTTP/0.9"

#. this is fatal
#: src/http.c:1116
msgid "Failed to set up an SSL context\n"
msgstr "Gre¹ka pri uspostavljanju SSL konteksta\n"

#: src/http.c:1121
#, c-format
msgid "Failed to load certificates from %s\n"
msgstr "Nisam uspio uèitati ovjere iz %s\n"

#: src/http.c:1124 src/http.c:1131
msgid "Trying without the specified certificate\n"
msgstr "Poku¹avam bez zadane ovjere\n"

#: src/http.c:1128
#, c-format
msgid "Failed to get certificate key from %s\n"
msgstr "Nisam uspio dobiti certifikat kljuèa iz %s\n"

#: src/http.c:1347
#, c-format
msgid "Reusing existing connection to %s:%d.\n"
msgstr "Koristim postojeæu vezu prema %s:%d.\n"

#: src/http.c:1399
#, c-format
msgid "Failed writing to proxy: %s.\n"
msgstr "Nisam uspio pisati proxyju: %s.\n"

#: src/http.c:1408
#, c-format
msgid "Failed reading proxy response: %s\n"
msgstr "Nisam uspio procitati proxyjev odgovor: %s.\n"

#: src/http.c:1428
#, c-format
msgid "Proxy tunneling failed: %s"
msgstr "Neuspjeh tuneliranja kroz proxy: %s"

#: src/http.c:1475
#, c-format
msgid "%s request sent, awaiting response... "
msgstr "%s zahtjev poslan, i¹èekujem odgovor... "

#: src/http.c:1486
msgid "No data received.\n"
msgstr "Podaci nisu primljeni.\n"

#: src/http.c:1493
#, c-format
msgid "Read error (%s) in headers.\n"
msgstr "Gre¹ka pri èitanju zaglavlja (%s).\n"

#. If we have tried it already, then there is not point
#. retrying it.
#: src/http.c:1558
msgid "Authorization failed.\n"
msgstr "Ovjera nije uspjela.\n"

#: src/http.c:1572
msgid "Unknown authentication scheme.\n"
msgstr "Nepoznata metoda ovjere.\n"

#: src/http.c:1597
msgid "Malformed status line"
msgstr "Deformirana statusna linija"

#: src/http.c:1599
msgid "(no description)"
msgstr "(bez opisa)"

#: src/http.c:1663
#, c-format
msgid "Location: %s%s\n"
msgstr "Polo¾aj: %s%s\n"

#: src/http.c:1664 src/http.c:1760
msgid "unspecified"
msgstr "nenaznaèen"

#: src/http.c:1665
msgid " [following]"
msgstr " [pratim]"

#. If `-c' is in use and the file has been fully downloaded (or
#. the remote file has shrunk), Wget effectively requests bytes
#. after the end of file and the server response with 416.
#: src/http.c:1710
msgid ""
"\n"
"    The file is already fully retrieved; nothing to do.\n"
