"Oikea symbolinen linkki %s -> %s on jo paikallaan.\n"
"\n"

#: src/ftp.c:1494
#, c-format
msgid "Creating symlink %s -> %s\n"
msgstr "Luodaan symbolinen linkki %s -> %s\n"

#: src/ftp.c:1504
#, c-format
msgid "Symlinks not supported, skipping symlink `%s'.\n"
msgstr "Ei tukea symbolisille linkeille, ohitetaan ”%s”.\n"

#: src/ftp.c:1516
#, c-format
msgid "Skipping directory `%s'.\n"
msgstr "Ohitetaan hakemisto ”%s”.\n"

#: src/ftp.c:1525
#, c-format
msgid "%s: unknown/unsupported file type.\n"
msgstr "%s: tuntematon/tukematon tiedostotyyppi.\n"

#: src/ftp.c:1552
#, c-format
msgid "%s: corrupt time-stamp.\n"
msgstr "%s: vääristynyt aikaleima.\n"

#: src/ftp.c:1580
#, c-format
msgid "Will not retrieve dirs since depth is %d (max %d).\n"
msgstr "Hakemistoja ei noudeta, koska syvyys on %d (raja %d).\n"

#: src/ftp.c:1630
#, c-format
msgid "Not descending to `%s' as it is excluded/not-included.\n"
msgstr "Hakemiston ”%s” sisältöä ei noudeta, koska se on poissuljettu.\n"

#: src/ftp.c:1696 src/ftp.c:1710
#, c-format
msgid "Rejecting `%s'.\n"
msgstr "Hylätään ”%s”.\n"

#: src/ftp.c:1733
#, fuzzy, c-format
msgid "Error matching %s against %s: %s\n"
msgstr "Kirjoitettaessa tiedostoon ”%s” tapahtui virhe: %s\n"

#: src/ftp.c:1774
#, c-format
msgid "No matches on pattern `%s'.\n"
msgstr "Hakulause ”%s” ei löytänyt mitään.\n"

#: src/ftp.c:1840
#, c-format
msgid "Wrote HTML-ized index to `%s' [%s].\n"
msgstr "HTML-muotoiltu indeksi on kirjoitettu tiedostoon ”%s” [%s].\n"

#: src/ftp.c:1845
#, c-format
msgid "Wrote HTML-ized index to `%s'.\n"
msgstr "HTML-muotoiltu indeksi on kirjoitettu tiedostoon ”%s”.\n"

#: src/host.c:348
msgid "Unknown host"
msgstr "Tuntematon palvelin"

#: src/host.c:352
msgid "Temporary failure in name resolution"
msgstr "Väliaikainen virhe nimipalvelussa"

#: src/host.c:354
msgid "Unknown error"
msgstr "Tuntematon virhe"

#: src/host.c:715
#, c-format
msgid "Resolving %s... "
msgstr "Selvitetään osoitetta %s... "

#: src/host.c:762
msgid "failed: No IPv4/IPv6 addresses for host.\n"
msgstr "epäonnistui: Palvelimelle ei ole IPv4/IPv6-osoitteita.\n"

#: src/host.c:785
msgid "failed: timed out.\n"
msgstr "epäonnistui: aikaraja ylittyi.\n"

#: src/html-url.c:289
#, c-format
msgid "%s: Cannot resolve incomplete link %s.\n"
msgstr "%s: Epätäydellistä linkkiä %s ei voitu selvittää.\n"

#: src/html-url.c:696
#, c-format
msgid "%s: Invalid URL %s: %s\n"
msgstr "%s: virheellinen URL %s: %s\n"

#: src/http.c:368
#, c-format
msgid "Failed writing HTTP request: %s.\n"
msgstr "HTTP-pyynnön kirjoitus epäonnistui: %s.\n"

#: src/http.c:737
msgid "No headers, assuming HTTP/0.9"
msgstr "Ei otsakkeita, oletetaan HTTP/0.9"

#: src/http.c:1417
msgid "Disabling SSL due to encountered errors.\n"
msgstr "SSL otetaan pois päältä tapahtuneiden virheiden johdosta.\n"

#: src/http.c:1570
#, c-format
msgid "POST data file `%s' missing: %s\n"
msgstr "POST-metodin data-tiedosto ”%s” puuttuu: %s\n"

#: src/http.c:1619
#, c-format
msgid "Reusing existing connection to %s:%d.\n"
msgstr "Käytetään uudelleen yhteyttä %s:%d.\n"

#: src/http.c:1687
#, c-format
msgid "Failed reading proxy response: %s\n"
msgstr "Vastaanotto välityspalvelimelta epäonnistui: %s.\n"

#: src/http.c:1707
#, c-format
msgid "Proxy tunneling failed: %s"
msgstr "Välityspalvelintunnelointi epäonnistui: %s"

#: src/http.c:1752
#, c-format
msgid "%s request sent, awaiting response... "
msgstr "%s-pyyntö lähetetty, odotetaan vastausta... "

#: src/http.c:1763
msgid "No data received.\n"
msgstr "Yhtään dataa ei vastaanotettu.\n"

#: src/http.c:1770
#, c-format
msgid "Read error (%s) in headers.\n"
msgstr "Lukuvirhe (%s) otsakkeissa.\n"

#: src/http.c:1816 src/http.c:2368
#, c-format
msgid ""
"File `%s' already there; not retrieving.\n"
"\n"
msgstr ""
"Tiedostoa ”%s” ei noudeta, koska se on jo paikalla.\n"
"\n"

#: src/http.c:1969
msgid "Unknown authentication scheme.\n"
msgstr "Tuntematon todennusjärjestelmä.\n"

#: src/http.c:2000
msgid "Authorization failed.\n"
msgstr "Todentaminen epäonnistui.\n"

#: src/http.c:2014
msgid "Malformed status line"
msgstr "Väärin muotoiltu Status-otsake"

#: src/http.c:2016
msgid "(no description)"
msgstr "(ei kuvausta)"

#: src/http.c:2082
#, c-format
msgid "Location: %s%s\n"
msgstr "Sijainti: %s%s\n"

#: src/http.c:2083 src/http.c:2193
msgid "unspecified"
msgstr "määrittelemätön"

#: src/http.c:2084
msgid " [following]"
msgstr " [seurataan]"

#: src/http.c:2140
msgid ""
"\n"
"    The file is already fully retrieved; nothing to do.\n"
