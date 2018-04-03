msgid "Failed writing HTTP request: %s.\n"
msgstr "HTTP-pyynnön kirjoitus epäonnistui: %s.\n"

#: src/http.c:745
msgid "No headers, assuming HTTP/0.9"
msgstr "Ei otsakkeita, oletetaan HTTP/0.9"

#: src/http.c:1430
msgid "Disabling SSL due to encountered errors.\n"
msgstr "SSL otetaan pois päältä tapahtuneiden virheiden johdosta.\n"

#: src/http.c:1548
#, fuzzy, c-format
msgid "POST data file %s missing: %s\n"
msgstr "POST-metodin data-tiedosto ”%s” puuttuu: %s\n"

#: src/http.c:1632
#, c-format
msgid "Reusing existing connection to %s:%d.\n"
msgstr "Käytetään uudelleen yhteyttä %s:%d.\n"

#: src/http.c:1701
#, c-format
msgid "Failed reading proxy response: %s\n"
msgstr "Vastaanotto välityspalvelimelta epäonnistui: %s.\n"

#: src/http.c:1721
#, c-format
msgid "Proxy tunneling failed: %s"
msgstr "Välityspalvelintunnelointi epäonnistui: %s"

#: src/http.c:1766
#, c-format
msgid "%s request sent, awaiting response... "
msgstr "%s-pyyntö lähetetty, odotetaan vastausta... "

#: src/http.c:1777
msgid "No data received.\n"
msgstr "Yhtään dataa ei vastaanotettu.\n"

#: src/http.c:1784
#, c-format
msgid "Read error (%s) in headers.\n"
msgstr "Lukuvirhe (%s) otsakkeissa.\n"

#: src/http.c:1831 src/http.c:2385
#, fuzzy, c-format
msgid ""
"File %s already there; not retrieving.\n"
"\n"
msgstr ""
"Tiedostoa ”%s” ei noudeta, koska se on jo paikalla.\n"
"\n"

#: src/http.c:1985
msgid "Unknown authentication scheme.\n"
msgstr "Tuntematon todennusjärjestelmä.\n"

#: src/http.c:2016
msgid "Authorization failed.\n"
msgstr "Todentaminen epäonnistui.\n"

#: src/http.c:2030
msgid "Malformed status line"
msgstr "Väärin muotoiltu Status-otsake"

#: src/http.c:2032
msgid "(no description)"
msgstr "(ei kuvausta)"

#: src/http.c:2098
#, c-format
msgid "Location: %s%s\n"
msgstr "Sijainti: %s%s\n"

#: src/http.c:2099 src/http.c:2209
msgid "unspecified"
msgstr "määrittelemätön"

#: src/http.c:2100
msgid " [following]"
msgstr " [seurataan]"

#: src/http.c:2156
msgid ""
"\n"
"    The file is already fully retrieved; nothing to do.\n"
