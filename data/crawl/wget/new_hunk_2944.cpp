msgid "%s: option `-W %s' doesn't allow an argument\n"
msgstr "%s: v�ti `-W %s' ei luba argumenti\n"

#: src/host.c:368
#, fuzzy
msgid "Unknown host"
msgstr "Tundmatu viga"

#. Message modeled after what gai_strerror returns in similar
#. circumstances.
#: src/host.c:372
msgid "Temporary failure in name resolution"
msgstr ""

#: src/host.c:374
msgid "Unknown error"
msgstr "Tundmatu viga"

#: src/host.c:748
#, c-format
msgid "Resolving %s... "
msgstr "Lahendan %s... "

#: src/host.c:792 src/host.c:839
#, c-format
msgid "failed: %s.\n"
msgstr "eba�nnestus: %s.\n"

#: src/host.c:801
msgid "failed: No IPv4/IPv6 addresses for host.\n"
msgstr ""

#: src/host.c:842
msgid "failed: timed out.\n"
msgstr "eba�nnestus: aegus.\n"

#: src/html-url.c:297
#, c-format
msgid "%s: Cannot resolve incomplete link %s.\n"
msgstr "%s: Ei �nnestu lahendada poolikut viidet %s.\n"

#: src/http.c:349 src/http.c:1504
#, c-format
msgid "Failed writing HTTP request: %s.\n"
msgstr "HTTP p�ringu kirjutamine eba�nnestus: %s.\n"

#: src/http.c:663
msgid "No headers, assuming HTTP/0.9"
msgstr ""

#. this is fatal
#: src/http.c:1151
msgid "Failed to set up an SSL context\n"
msgstr "SSL konteksti m��ramine eba�nnestus\n"

#: src/http.c:1156
#, c-format
msgid "Failed to load certificates from %s\n"
msgstr "Sertifikaadi laadimine failist %s eba�nnestus\n"

#: src/http.c:1159 src/http.c:1166
msgid "Trying without the specified certificate\n"
msgstr "Proovin n�idatud sertifikaati mitte kasutada\n"

#: src/http.c:1163
#, c-format
msgid "Failed to get certificate key from %s\n"
msgstr "Sertifikaadi v�tme laadimine failist %s eba�nnestus\n"

#: src/http.c:1382
#, fuzzy, c-format
msgid "Reusing existing connection to %s:%d.\n"
msgstr "Kasutan �hendust serveriga %s:%hu.\n"

#: src/http.c:1434
#, fuzzy, c-format
msgid "Failed writing to proxy: %s.\n"
msgstr "HTTP p�ringu kirjutamine eba�nnestus: %s.\n"

#: src/http.c:1443
#, fuzzy, c-format
msgid "Failed reading proxy response: %s\n"
msgstr "HTTP p�ringu kirjutamine eba�nnestus: %s.\n"

#: src/http.c:1463
#, c-format
msgid "Proxy tunneling failed: %s"
msgstr ""

#: src/http.c:1510
#, c-format
msgid "%s request sent, awaiting response... "
msgstr "%s p�ring saadetud, ootan vastust... "

#: src/http.c:1521
#, fuzzy
msgid "No data received.\n"
msgstr "Andmeid ei saanudki"

#: src/http.c:1528
#, c-format
msgid "Read error (%s) in headers.\n"
msgstr "P�iste lugemise viga (%s).\n"

#. If we have tried it already, then there is not point
#. retrying it.
#: src/http.c:1595
msgid "Authorization failed.\n"
msgstr "Autoriseerimine eba�nnestus.\n"

#: src/http.c:1609
msgid "Unknown authentication scheme.\n"
msgstr "Tundmatu autentimis skeem.\n"

#: src/http.c:1634
msgid "Malformed status line"
msgstr "Katkine staatuse rida"

#: src/http.c:1636
msgid "(no description)"
msgstr "(kirjeldus puudub)"

#: src/http.c:1700
#, c-format
msgid "Location: %s%s\n"
msgstr "Asukoht: %s%s\n"

#: src/http.c:1701 src/http.c:1801
msgid "unspecified"
msgstr "m��ramata"

#: src/http.c:1702
msgid " [following]"
msgstr " [j�rgnev]"

#. If `-c' is in use and the file has been fully downloaded (or
#. the remote file has shrunk), Wget effectively requests bytes
#. after the end of file and the server response with 416.
#: src/http.c:1751
msgid ""
"\n"
"    The file is already fully retrieved; nothing to do.\n"
