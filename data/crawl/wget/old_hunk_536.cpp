"Korrektne nimeviide on juba olemas %s -> %s\n"
"\n"

#: src/ftp.c:1533
#, c-format
msgid "Creating symlink %s -> %s\n"
msgstr "Loon nimeviite %s -> %s\n"

#: src/ftp.c:1543
#, fuzzy, c-format
msgid "Symlinks not supported, skipping symlink %s.\n"
msgstr "Ei toeta nimeviiteid, jätan `%s' vahele.\n"

#: src/ftp.c:1555
#, fuzzy, c-format
msgid "Skipping directory %s.\n"
msgstr "Jätan kataloogi `%s' vahele.\n"

#: src/ftp.c:1564
#, c-format
msgid "%s: unknown/unsupported file type.\n"
msgstr "%s: tundmatu faili tüüp.\n"

#: src/ftp.c:1591
#, c-format
msgid "%s: corrupt time-stamp.\n"
msgstr "%s: vigane ajatempel.\n"

#: src/ftp.c:1619
#, c-format
msgid "Will not retrieve dirs since depth is %d (max %d).\n"
msgstr "Ei tõmba katalooge, kuna sügavus on %d (maks. %d).\n"

#: src/ftp.c:1669
#, fuzzy, c-format
msgid "Not descending to %s as it is excluded/not-included.\n"
msgstr "Jätame `%s' vahele, ta on välistatud või pole kaasatud.\n"

#: src/ftp.c:1735 src/ftp.c:1749
#, fuzzy, c-format
msgid "Rejecting %s.\n"
msgstr "Keelame `%s'.\n"

#: src/ftp.c:1772
#, fuzzy, c-format
msgid "Error matching %s against %s: %s\n"
msgstr "Ei saa kirjutada faili `%s': %s\n"

#: src/ftp.c:1814
#, fuzzy, c-format
msgid "No matches on pattern %s.\n"
msgstr "Jokker `%s' ei anna midagi.\n"

#: src/ftp.c:1880
#, fuzzy, c-format
msgid "Wrote HTML-ized index to %s [%s].\n"
msgstr "Kirjutasin HTML-iseeritud indeksi faili `%s' [%s].\n"

#: src/ftp.c:1885
#, fuzzy, c-format
msgid "Wrote HTML-ized index to %s.\n"
msgstr "Kirjutasin HTML-iseeritud indeksi faili `%s'.\n"

#: src/host.c:348
msgid "Unknown host"
msgstr "Tundmatu host"

#: src/host.c:352
msgid "Temporary failure in name resolution"
msgstr "Nime lahendamisel tekkis ajutine viga"

#: src/host.c:354
msgid "Unknown error"
msgstr "Tundmatu viga"

#: src/host.c:715
#, c-format
msgid "Resolving %s... "
msgstr "Lahendan %s... "

#: src/host.c:763
msgid "failed: No IPv4/IPv6 addresses for host.\n"
msgstr "ebaõnnestus: Masinal pole IPv4/IPv6 aadresse.\n"

#: src/host.c:786
msgid "failed: timed out.\n"
msgstr "ebaõnnestus: aegus.\n"

#: src/html-url.c:289
#, c-format
msgid "%s: Cannot resolve incomplete link %s.\n"
msgstr "%s: Ei õnnestu lahendada poolikut viidet %s.\n"

#: src/html-url.c:696
#, c-format
msgid "%s: Invalid URL %s: %s\n"
msgstr "%s: Vigane URL %s: %s\n"

#: src/http.c:368
#, c-format
msgid "Failed writing HTTP request: %s.\n"
msgstr "HTTP päringu kirjutamine ebaõnnestus: %s.\n"

#: src/http.c:745
msgid "No headers, assuming HTTP/0.9"
msgstr "Päiseid pole, eeldan HTTP/0.9"

#: src/http.c:1430
msgid "Disabling SSL due to encountered errors.\n"
msgstr "Kuna tekkis vigu, siis blokeerin SSLi.\n"

#: src/http.c:1548
#, fuzzy, c-format
msgid "POST data file %s missing: %s\n"
msgstr "POST andmete fail `%s' puudub: %s\n"

#: src/http.c:1632
#, c-format
msgid "Reusing existing connection to %s:%d.\n"
msgstr "Kasutan ühendust serveriga %s:%d.\n"

#: src/http.c:1701
#, c-format
msgid "Failed reading proxy response: %s\n"
msgstr "Proksi vastuse lugemine ebaõnnestus: %s.\n"

#: src/http.c:1721
#, c-format
msgid "Proxy tunneling failed: %s"
msgstr "Proksi tunneldamine ebaõnnestus: %s"

#: src/http.c:1766
#, c-format
msgid "%s request sent, awaiting response... "
msgstr "%s päring saadetud, ootan vastust... "

#: src/http.c:1777
msgid "No data received.\n"
msgstr "Andmeid ei saanudki.\n"

#: src/http.c:1784
#, c-format
msgid "Read error (%s) in headers.\n"
msgstr "Päiste lugemise viga (%s).\n"

#: src/http.c:1831 src/http.c:2385
#, fuzzy, c-format
msgid ""
"File %s already there; not retrieving.\n"
