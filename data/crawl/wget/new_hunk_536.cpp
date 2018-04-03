"Korrektne nimeviide on juba olemas %s -> %s\n"
"\n"

#: src/ftp.c:1788
#, c-format
msgid "Creating symlink %s -> %s\n"
msgstr "Loon nimeviite %s -> %s\n"

#: src/ftp.c:1798
#, fuzzy, c-format
msgid "Symlinks not supported, skipping symlink %s.\n"
msgstr "Ei toeta nimeviiteid, jätan `%s' vahele.\n"

#: src/ftp.c:1810
#, fuzzy, c-format
msgid "Skipping directory %s.\n"
msgstr "Jätan kataloogi `%s' vahele.\n"

#: src/ftp.c:1819
#, c-format
msgid "%s: unknown/unsupported file type.\n"
msgstr "%s: tundmatu faili tüüp.\n"

#: src/ftp.c:1856
#, c-format
msgid "%s: corrupt time-stamp.\n"
msgstr "%s: vigane ajatempel.\n"

#: src/ftp.c:1878
#, c-format
msgid "Will not retrieve dirs since depth is %d (max %d).\n"
msgstr "Ei tõmba katalooge, kuna sügavus on %d (maks. %d).\n"

#: src/ftp.c:1928
#, fuzzy, c-format
msgid "Not descending to %s as it is excluded/not-included.\n"
msgstr "Jätame `%s' vahele, ta on välistatud või pole kaasatud.\n"

#: src/ftp.c:1994 src/ftp.c:2008
#, fuzzy, c-format
msgid "Rejecting %s.\n"
msgstr "Keelame `%s'.\n"

#: src/ftp.c:2031
#, fuzzy, c-format
msgid "Error matching %s against %s: %s\n"
msgstr "Ei saa kirjutada faili `%s': %s\n"

#: src/ftp.c:2073
#, fuzzy, c-format
msgid "No matches on pattern %s.\n"
msgstr "Jokker `%s' ei anna midagi.\n"

#: src/ftp.c:2144
#, fuzzy, c-format
msgid "Wrote HTML-ized index to %s [%s].\n"
msgstr "Kirjutasin HTML-iseeritud indeksi faili `%s' [%s].\n"

#: src/ftp.c:2149
#, fuzzy, c-format
msgid "Wrote HTML-ized index to %s.\n"
msgstr "Kirjutasin HTML-iseeritud indeksi faili `%s'.\n"

#: src/gnutls.c:219 src/openssl.c:495
msgid "ERROR"
msgstr "VIGA"

#: src/gnutls.c:219 src/openssl.c:495
msgid "WARNING"
msgstr "HOIATUS"

#: src/gnutls.c:225 src/openssl.c:504
#, c-format
msgid "%s: No certificate presented by %s.\n"
msgstr "%s: %s ei esitanud sertifikaati.\n"

#: src/gnutls.c:233
#, fuzzy, c-format
msgid "%s: The certificate of %s is not trusted.\n"
msgstr "%s: %s ei esitanud sertifikaati.\n"

#: src/gnutls.c:239
#, c-format
msgid "%s: The certificate of %s hasn't got a known issuer.\n"
msgstr ""

#: src/gnutls.c:245
#, fuzzy, c-format
msgid "%s: The certificate of %s has been revoked.\n"
msgstr "%s: %s ei esitanud sertifikaati.\n"

#: src/gnutls.c:259
#, c-format
msgid "Error initializing X509 certificate: %s\n"
msgstr ""

#: src/gnutls.c:268
#, fuzzy
msgid "No certificate found\n"
msgstr "%s: %s ei esitanud sertifikaati.\n"

#: src/gnutls.c:275
#, fuzzy, c-format
msgid "Error parsing certificate: %s\n"
msgstr "Viga proxy urli parsimisel %s: %s.\n"

#: src/gnutls.c:282
msgid "The certificate has not yet been activated\n"
msgstr ""

#: src/gnutls.c:287
msgid "The certificate has expired\n"
msgstr ""

#: src/gnutls.c:293
#, fuzzy, c-format
msgid "The certificate's owner does not match hostname '%s'\n"
msgstr "%s: sertifikaadi üldine nimi `%s' ei sobi küsitud nimega `%s'.\n"

#: src/host.c:358
msgid "Unknown host"
msgstr "Tundmatu host"

#: src/host.c:362
msgid "Temporary failure in name resolution"
msgstr "Nime lahendamisel tekkis ajutine viga"

#: src/host.c:364
msgid "Unknown error"
msgstr "Tundmatu viga"

#: src/host.c:737
#, c-format
msgid "Resolving %s... "
msgstr "Lahendan %s... "

#: src/host.c:789
msgid "failed: No IPv4/IPv6 addresses for host.\n"
msgstr "ebaõnnestus: Masinal pole IPv4/IPv6 aadresse.\n"

#: src/host.c:812
msgid "failed: timed out.\n"
msgstr "ebaõnnestus: aegus.\n"

#: src/html-url.c:286
#, c-format
msgid "%s: Cannot resolve incomplete link %s.\n"
msgstr "%s: Ei õnnestu lahendada poolikut viidet %s.\n"

#: src/html-url.c:762
#, c-format
msgid "%s: Invalid URL %s: %s\n"
msgstr "%s: Vigane URL %s: %s\n"

#: src/http.c:377
#, c-format
msgid "Failed writing HTTP request: %s.\n"
msgstr "HTTP päringu kirjutamine ebaõnnestus: %s.\n"

#: src/http.c:754
msgid "No headers, assuming HTTP/0.9"
msgstr "Päiseid pole, eeldan HTTP/0.9"

#: src/http.c:1456
msgid "Disabling SSL due to encountered errors.\n"
msgstr "Kuna tekkis vigu, siis blokeerin SSLi.\n"

#: src/http.c:1576
#, fuzzy, c-format
msgid "POST data file %s missing: %s\n"
msgstr "POST andmete fail `%s' puudub: %s\n"

#: src/http.c:1660
#, c-format
msgid "Reusing existing connection to %s:%d.\n"
msgstr "Kasutan ühendust serveriga %s:%d.\n"

#: src/http.c:1729
#, c-format
msgid "Failed reading proxy response: %s\n"
msgstr "Proksi vastuse lugemine ebaõnnestus: %s.\n"

#: src/http.c:1750
#, c-format
msgid "Proxy tunneling failed: %s"
msgstr "Proksi tunneldamine ebaõnnestus: %s"

#: src/http.c:1795
#, c-format
msgid "%s request sent, awaiting response... "
msgstr "%s päring saadetud, ootan vastust... "

#: src/http.c:1806
msgid "No data received.\n"
msgstr "Andmeid ei saanudki.\n"

#: src/http.c:1813
#, c-format
msgid "Read error (%s) in headers.\n"
msgstr "Päiste lugemise viga (%s).\n"

#: src/http.c:1884
msgid "Unknown authentication scheme.\n"
msgstr "Tundmatu autentimis skeem.\n"

#: src/http.c:1918
msgid "Authorization failed.\n"
msgstr "Autoriseerimine ebaõnnestus.\n"

#: src/http.c:1956 src/http.c:2466
#, fuzzy, c-format
msgid ""
"File %s already there; not retrieving.\n"
