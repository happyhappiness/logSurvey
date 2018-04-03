"Oikea symbolinen linkki %s -> %s on jo paikallaan.\n"
"\n"

#: src/ftp.c:1533
#, c-format
msgid "Creating symlink %s -> %s\n"
msgstr "Luodaan symbolinen linkki %s -> %s\n"

#: src/ftp.c:1543
#, fuzzy, c-format
msgid "Symlinks not supported, skipping symlink %s.\n"
msgstr "Ei tukea symbolisille linkeille, ohitetaan ”%s”.\n"

#: src/ftp.c:1555
#, fuzzy, c-format
msgid "Skipping directory %s.\n"
msgstr "Ohitetaan hakemisto ”%s”.\n"

#: src/ftp.c:1564
#, c-format
msgid "%s: unknown/unsupported file type.\n"
msgstr "%s: tuntematon/tukematon tiedostotyyppi.\n"

#: src/ftp.c:1591
#, c-format
msgid "%s: corrupt time-stamp.\n"
msgstr "%s: vääristynyt aikaleima.\n"

#: src/ftp.c:1619
#, c-format
msgid "Will not retrieve dirs since depth is %d (max %d).\n"
msgstr "Hakemistoja ei noudeta, koska syvyys on %d (raja %d).\n"

#: src/ftp.c:1669
#, fuzzy, c-format
msgid "Not descending to %s as it is excluded/not-included.\n"
msgstr "Hakemiston ”%s” sisältöä ei noudeta, koska se on poissuljettu.\n"

#: src/ftp.c:1735 src/ftp.c:1749
#, fuzzy, c-format
msgid "Rejecting %s.\n"
msgstr "Hylätään ”%s”.\n"

#: src/ftp.c:1772
#, c-format
msgid "Error matching %s against %s: %s\n"
msgstr "Virhe kohteessa %s; ﻿se on erilainen kuin ﻿%s: %s\n"

#: src/ftp.c:1814
#, fuzzy, c-format
msgid "No matches on pattern %s.\n"
msgstr "Hakulause ”%s” ei löytänyt mitään.\n"

#: src/ftp.c:1880
#, fuzzy, c-format
msgid "Wrote HTML-ized index to %s [%s].\n"
msgstr "HTML-muotoiltu indeksi on kirjoitettu tiedostoon ”%s” [%s].\n"

#: src/ftp.c:1885
#, fuzzy, c-format
msgid "Wrote HTML-ized index to %s.\n"
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

#: src/host.c:763
msgid "failed: No IPv4/IPv6 addresses for host.\n"
msgstr "epäonnistui: Palvelimelle ei ole IPv4/IPv6-osoitteita.\n"

#: src/host.c:786
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
