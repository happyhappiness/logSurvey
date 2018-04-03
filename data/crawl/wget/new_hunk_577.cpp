"Obstaja ¾e pravilna simbolna povezava %s -> %s\n"
"\n"

#: src/ftp.c:1788
#, c-format
msgid "Creating symlink %s -> %s\n"
msgstr "Ustvarjam simbolno povezavo %s -> %s\n"

#: src/ftp.c:1798
#, fuzzy, c-format
msgid "Symlinks not supported, skipping symlink %s.\n"
msgstr "Povezave niso podprte, preskakujem simbolno povezavo `%s'.\n"

#: src/ftp.c:1810
#, fuzzy, c-format
msgid "Skipping directory %s.\n"
msgstr "Preskakujem imenik `%s'.\n"

#: src/ftp.c:1819
#, c-format
msgid "%s: unknown/unsupported file type.\n"
msgstr "%s: neznana/nepodprta vrsta datoteke.\n"

#: src/ftp.c:1856
#, c-format
msgid "%s: corrupt time-stamp.\n"
msgstr "%s: okvarjena oznaèba èasa.\n"

#: src/ftp.c:1878
#, c-format
msgid "Will not retrieve dirs since depth is %d (max %d).\n"
msgstr "Ne jemljem imenikov, ker je globina %d (maksimalno %d).\n"

#: src/ftp.c:1928
#, fuzzy, c-format
msgid "Not descending to %s as it is excluded/not-included.\n"
msgstr "Ne grem v `%s', ker je izkljuèen ali pa ni vkljuèen.\n"

#: src/ftp.c:1994 src/ftp.c:2008
#, fuzzy, c-format
msgid "Rejecting %s.\n"
msgstr "Zavraèam `%s'.\n"

#: src/ftp.c:2031
#, c-format
msgid "Error matching %s against %s: %s\n"
msgstr "Napaka pri ujemanju %s z %s: %s\n"

#: src/ftp.c:2073
#, fuzzy, c-format
msgid "No matches on pattern %s.\n"
msgstr "Ni zadetkov za vzorec `%s'.\n"

#: src/ftp.c:2144
#, fuzzy, c-format
msgid "Wrote HTML-ized index to %s [%s].\n"
msgstr "Kazalo v HTML zapisal kot ,%s` [%s].\n"

#: src/ftp.c:2149
#, fuzzy, c-format
msgid "Wrote HTML-ized index to %s.\n"
msgstr "Kazalo v HTML zapisal kot `%s'.\n"

#: src/gnutls.c:219 src/openssl.c:495
msgid "ERROR"
msgstr "NAPAKA"

#: src/gnutls.c:219 src/openssl.c:495
msgid "WARNING"
msgstr "OPOZORILO"

#: src/gnutls.c:225 src/openssl.c:504
#, c-format
msgid "%s: No certificate presented by %s.\n"
msgstr "%s: %s ni podal certifikata.\n"

#: src/gnutls.c:233
#, fuzzy, c-format
msgid "%s: The certificate of %s is not trusted.\n"
msgstr "%s: %s ni podal certifikata.\n"

#: src/gnutls.c:239
#, c-format
msgid "%s: The certificate of %s hasn't got a known issuer.\n"
msgstr ""

#: src/gnutls.c:245
#, fuzzy, c-format
msgid "%s: The certificate of %s has been revoked.\n"
msgstr "  Izdani certifikat je ¾e potekel.\n"

#: src/gnutls.c:259
#, c-format
msgid "Error initializing X509 certificate: %s\n"
msgstr ""

#: src/gnutls.c:268
#, fuzzy
msgid "No certificate found\n"
msgstr "%s: %s ni podal certifikata.\n"

#: src/gnutls.c:275
#, fuzzy, c-format
msgid "Error parsing certificate: %s\n"
msgstr "Napaka pri razèlenjevanju URL zastopnika %s: %s.\n"

#: src/gnutls.c:282
#, fuzzy
msgid "The certificate has not yet been activated\n"
msgstr "  Izdani certifikat ¹e ne velja.\n"

#: src/gnutls.c:287
#, fuzzy
msgid "The certificate has expired\n"
msgstr "  Izdani certifikat je ¾e potekel.\n"

#: src/gnutls.c:293
#, fuzzy, c-format
msgid "The certificate's owner does not match hostname '%s'\n"
msgstr ""
"%s: obièajno ime ,%s` na certifikatu ne ustreza imenu raèunalnika ,%s`.\n"

#: src/host.c:358
msgid "Unknown host"
msgstr "Neznan raèunalnik"

#: src/host.c:362
msgid "Temporary failure in name resolution"
msgstr "Zaèasna napaka pri razre¹evanju imena"

#: src/host.c:364
msgid "Unknown error"
msgstr "Neznana napaka"

#: src/host.c:737
#, c-format
msgid "Resolving %s... "
msgstr "Razre¹uje se %s..."

#: src/host.c:789
msgid "failed: No IPv4/IPv6 addresses for host.\n"
msgstr "spodletelo: Ni naslova IPv4/IPv6 za raèunalnik.\n"

#: src/host.c:812
msgid "failed: timed out.\n"
msgstr "spodletelo: zakasnitev.\n"

#: src/html-url.c:286
#, c-format
msgid "%s: Cannot resolve incomplete link %s.\n"
msgstr "%s: Ni moè razre¹iti nepopolne povezave %s.\n"

#: src/html-url.c:762
#, c-format
msgid "%s: Invalid URL %s: %s\n"
msgstr "%s: Neveljaven URL %s: %s\n"

#: src/http.c:377
#, c-format
msgid "Failed writing HTTP request: %s.\n"
msgstr "Napaka pri pisanju zahteve HTTP: %s.\n"

#: src/http.c:754
msgid "No headers, assuming HTTP/0.9"
msgstr "Ni glav, privzema se HTTP/0.9"

#: src/http.c:1456
msgid "Disabling SSL due to encountered errors.\n"
msgstr "SSL se onemogoèa zaradi opa¾enih te¾av.\n"

#: src/http.c:1576
#, fuzzy, c-format
msgid "POST data file %s missing: %s\n"
msgstr "Manjka podatkovna datoteka ,%s` za POST: %s\n"

#: src/http.c:1660
#, c-format
msgid "Reusing existing connection to %s:%d.\n"
msgstr "Znova se uporablja povezava z %s:%d.\n"

#: src/http.c:1729
#, c-format
msgid "Failed reading proxy response: %s\n"
msgstr "Napaka pri branju odgovora posrednika: %s\n"

#: src/http.c:1750
#, c-format
msgid "Proxy tunneling failed: %s"
msgstr "Posredni¹ko tuneliranje spodletelo: %s"

#: src/http.c:1795
#, c-format
msgid "%s request sent, awaiting response... "
msgstr "%s zahteva poslana, èakam odgovor... "

#: src/http.c:1806
msgid "No data received.\n"
msgstr "Brez sprejetih podatkov.\n"

#: src/http.c:1813
#, c-format
msgid "Read error (%s) in headers.\n"
msgstr "Napaka pri branju glave (%s).\n"

#: src/http.c:1884
msgid "Unknown authentication scheme.\n"
msgstr "Neznata metoda avtentikacije.\n"

#: src/http.c:1918
msgid "Authorization failed.\n"
msgstr "Avtorizacija neuspe¹na.\n"

#: src/http.c:1956 src/http.c:2466
#, fuzzy, c-format
msgid ""
"File %s already there; not retrieving.\n"
