"Deja existã symlinkul corect %s -> %s\n"
"\n"

#: src/ftp.c:1788
#, c-format
msgid "Creating symlink %s -> %s\n"
msgstr "Creare symlink %s -> %s\n"

#: src/ftp.c:1798
#, fuzzy, c-format
msgid "Symlinks not supported, skipping symlink %s.\n"
msgstr "Symlinkuri nesuportate, se omite symlinkul `%s'.\n"

#: src/ftp.c:1810
#, fuzzy, c-format
msgid "Skipping directory %s.\n"
msgstr "Se omite directorul `%s.\n"

#: src/ftp.c:1819
#, c-format
msgid "%s: unknown/unsupported file type.\n"
msgstr "%s: tip fiºier necunoscut/nesuportat.\n"

#: src/ftp.c:1856
#, c-format
msgid "%s: corrupt time-stamp.\n"
msgstr "%s: identificator-timp(time-stamp) corupt.\n"

#: src/ftp.c:1878
#, c-format
msgid "Will not retrieve dirs since depth is %d (max %d).\n"
msgstr "Nu vor fi aduse directoare pentru adãncime setatã la %d (max %d).\n"

#: src/ftp.c:1928
#, fuzzy, c-format
msgid "Not descending to %s as it is excluded/not-included.\n"
msgstr "Nu se coboarã la `%s' daca este exclus/neinclus.\n"

#: src/ftp.c:1994 src/ftp.c:2008
#, fuzzy, c-format
msgid "Rejecting %s.\n"
msgstr "Refuzare `%s'.\n"

#: src/ftp.c:2031
#, fuzzy, c-format
msgid "Error matching %s against %s: %s\n"
msgstr "Eroare la scriere în `%s': %s\n"

#: src/ftp.c:2073
#, fuzzy, c-format
msgid "No matches on pattern %s.\n"
msgstr "Nu s-au gãsit potriviri pentru tiparul `%s'.\n"

#: src/ftp.c:2144
#, fuzzy, c-format
msgid "Wrote HTML-ized index to %s [%s].\n"
msgstr "S-a scris indexul HTML în `%s' [%ld].\n"

#: src/ftp.c:2149
#, fuzzy, c-format
msgid "Wrote HTML-ized index to %s.\n"
msgstr "S-a scris indexul HTML în `%s'\n"

#: src/gnutls.c:219 src/openssl.c:495
msgid "ERROR"
msgstr ""

#: src/gnutls.c:219 src/openssl.c:495
msgid "WARNING"
msgstr ""

#: src/gnutls.c:225 src/openssl.c:504
#, c-format
msgid "%s: No certificate presented by %s.\n"
msgstr ""

#: src/gnutls.c:233
#, c-format
msgid "%s: The certificate of %s is not trusted.\n"
msgstr ""

#: src/gnutls.c:239
#, c-format
msgid "%s: The certificate of %s hasn't got a known issuer.\n"
msgstr ""

#: src/gnutls.c:245
#, c-format
msgid "%s: The certificate of %s has been revoked.\n"
msgstr ""

#: src/gnutls.c:259
#, c-format
msgid "Error initializing X509 certificate: %s\n"
msgstr ""

#: src/gnutls.c:268
msgid "No certificate found\n"
msgstr ""

#: src/gnutls.c:275
#, fuzzy, c-format
msgid "Error parsing certificate: %s\n"
msgstr "Eroare în analiza URL proxy: %s: %s.\n"

#: src/gnutls.c:282
msgid "The certificate has not yet been activated\n"
msgstr ""

#: src/gnutls.c:287
msgid "The certificate has expired\n"
msgstr ""

#: src/gnutls.c:293
#, c-format
msgid "The certificate's owner does not match hostname '%s'\n"
msgstr ""

#: src/host.c:358
#, fuzzy
msgid "Unknown host"
msgstr "Eroare necunoscutã"

#: src/host.c:362
msgid "Temporary failure in name resolution"
msgstr ""

#: src/host.c:364
msgid "Unknown error"
msgstr "Eroare necunoscutã"

#: src/host.c:737
#, c-format
msgid "Resolving %s... "
msgstr "Rezolvare %s... "

#: src/host.c:789
msgid "failed: No IPv4/IPv6 addresses for host.\n"
msgstr ""

#: src/host.c:812
msgid "failed: timed out.\n"
msgstr "eºuare: .expirat(ã)\n"

#: src/html-url.c:286
#, c-format
msgid "%s: Cannot resolve incomplete link %s.\n"
msgstr "%s: Nu s-a rezolvat linkul incomplet %s.\n"

#: src/html-url.c:762
#, fuzzy, c-format
msgid "%s: Invalid URL %s: %s\n"
msgstr "%s: %s: Valoare invalidã `%s'.\n"

#: src/http.c:377
#, c-format
msgid "Failed writing HTTP request: %s.\n"
msgstr "Scriere cerere HTTP eºuatã: %s.\n"

#: src/http.c:754
msgid "No headers, assuming HTTP/0.9"
msgstr ""

#: src/http.c:1456
msgid "Disabling SSL due to encountered errors.\n"
msgstr ""

#: src/http.c:1576
#, c-format
msgid "POST data file %s missing: %s\n"
msgstr ""

#: src/http.c:1660
#, fuzzy, c-format
msgid "Reusing existing connection to %s:%d.\n"
msgstr "Reutilizare conexiune cãtre %s:%hu.\n"

#: src/http.c:1729
#, fuzzy, c-format
msgid "Failed reading proxy response: %s\n"
msgstr "Scriere cerere HTTP eºuatã: %s.\n"

#: src/http.c:1750
#, c-format
msgid "Proxy tunneling failed: %s"
msgstr ""

#: src/http.c:1795
#, c-format
msgid "%s request sent, awaiting response... "
msgstr "Cerere %s trimisã, se aºteaptã rãspuns... "

#: src/http.c:1806
#, fuzzy
msgid "No data received.\n"
msgstr "Nici o datã recepþionatã"

#: src/http.c:1813
#, c-format
msgid "Read error (%s) in headers.\n"
msgstr "Eroare de citire (%s) în headere.\n"

#: src/http.c:1884
msgid "Unknown authentication scheme.\n"
msgstr "Schemã autentificare necunoscutã.\n"

#: src/http.c:1918
msgid "Authorization failed.\n"
msgstr "Autorizare eºuatã.\n"

#: src/http.c:1956 src/http.c:2466
#, fuzzy, c-format
msgid ""
"File %s already there; not retrieving.\n"
"\n"
msgstr "Fiºierul `%s' existã deja, nu se mai aduce.\n"

#: src/http.c:2070
msgid "Malformed status line"
msgstr "Linie de stare malformatã"

#: src/http.c:2072
msgid "(no description)"
msgstr "(fãrã descriere)"

#: src/http.c:2149
#, c-format
msgid "Location: %s%s\n"
msgstr "Locaþie: %s%s\n"

#: src/http.c:2150 src/http.c:2258
msgid "unspecified"
msgstr "nespecificat(ã)"

#: src/http.c:2151
msgid " [following]"
msgstr " [urmeazã]"

#: src/http.c:2203
msgid ""
"\n"
"    The file is already fully retrieved; nothing to do.\n"
