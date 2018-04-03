msgid "%s: option `-W %s' doesn't allow an argument\n"
msgstr "%s: valinta \"-W %s\" ei hyväksy parametrejä\n"

#: src/host.c:636
#, c-format
msgid "Resolving %s... "
msgstr "Selvitetään osoitetta %s... "

#: src/host.c:656 src/host.c:672
#, c-format
msgid "failed: %s.\n"
msgstr "epäonnistui: %s.\n"

#: src/host.c:674
msgid "failed: timed out.\n"
msgstr "epäonnistui: aikaraja ylittyi.\n"

#: src/host.c:762
msgid "Host not found"
msgstr "Palvelinta ei löytynyt"

#: src/host.c:764
msgid "Unknown error"
msgstr "Tuntematon virhe"

#: src/html-url.c:293
#, c-format
msgid "%s: Cannot resolve incomplete link %s.\n"
msgstr "%s: Epätäydellistä linkkiä %s ei voi selvittää.\n"

#. this is fatal
#: src/http.c:674
msgid "Failed to set up an SSL context\n"
msgstr "SSL-kontekstin asettaminen epäonnistui\n"

#: src/http.c:680
#, c-format
msgid "Failed to load certificates from %s\n"
msgstr "Varmenteen lataaminen epäonnistui kohteesta %s\n"

#: src/http.c:684 src/http.c:692
msgid "Trying without the specified certificate\n"
msgstr "Yritetään ilman määriteltyä varmennetta\n"

#: src/http.c:688
#, c-format
msgid "Failed to get certificate key from %s\n"
msgstr "Varmenteen haku ei onnistunut kohteesta %s\n"

#: src/http.c:761 src/http.c:1809
msgid "Unable to establish SSL connection.\n"
msgstr "SSL-yhteyden muodostaminen ei onnistu.\n"

#: src/http.c:770
#, c-format
msgid "Reusing connection to %s:%hu.\n"
msgstr "Uudelleenkäytetään yhteyttä %s:%hu.\n"

#: src/http.c:1034
#, c-format
msgid "Failed writing HTTP request: %s.\n"
msgstr "HTTP-pyynnön kirjoitus epäonnistui: %s.\n"

#: src/http.c:1039
#, c-format
msgid "%s request sent, awaiting response... "
msgstr "%s-pyyntö lähetetty, odotetaan vastausta... "

#: src/http.c:1083
msgid "End of file while parsing headers.\n"
msgstr "Tiedoston loppu otsakkeita jäsennettäessä.\n"

#: src/http.c:1093
#, c-format
msgid "Read error (%s) in headers.\n"
msgstr "Lukuvirhe (%s) otsakkeissa.\n"

#: src/http.c:1128
msgid "No data received"
msgstr "Dataa ei ole vastaanotettu"

#: src/http.c:1130
msgid "Malformed status line"
msgstr "Väärin muotoiltu tilarivi"

#: src/http.c:1135
msgid "(no description)"
msgstr "(ei kuvausta)"

#: src/http.c:1267
msgid "Authorization failed.\n"
msgstr "Todentaminen epäonnistui.\n"

#: src/http.c:1274
msgid "Unknown authentication scheme.\n"
msgstr "Tuntematon varmennusjärjestelmä.\n"

#: src/http.c:1314
#, c-format
msgid "Location: %s%s\n"
msgstr "Sijainti: %s%s\n"

#: src/http.c:1315 src/http.c:1454
msgid "unspecified"
msgstr "määrittelemätön"

#: src/http.c:1316
msgid " [following]"
msgstr " [seurataan]"

#: src/http.c:1383
msgid ""
"\n"
"    The file is already fully retrieved; nothing to do.\n"
