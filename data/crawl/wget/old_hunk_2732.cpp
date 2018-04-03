#. No luck.
#. #### This message SUCKS.  We should see what was the
#. reason that nothing was retrieved.
#: src/ftp.c:1766
#, c-format
msgid "No matches on pattern `%s'.\n"
msgstr "Ni¹ta ne ide uz `%s'.\n"

#: src/ftp.c:1832
#, c-format
msgid "Wrote HTML-ized index to `%s' [%s].\n"
msgstr "Snimio HTML-iziran indeks u `%s' [%s].\n"

#: src/ftp.c:1837
#, c-format
msgid "Wrote HTML-ized index to `%s'.\n"
msgstr "Snimio HTML-iziran indeks u `%s'.\n"

#: src/getopt.c:671
#, c-format
msgid "%s: option `%s' is ambiguous\n"
msgstr "%s: opcija `%s' je dvosmislena\n"

#: src/getopt.c:696
#, c-format
msgid "%s: option `--%s' doesn't allow an argument\n"
msgstr "%s: uz opciju `--%s' ne ide argument\n"

#: src/getopt.c:701
#, c-format
msgid "%s: option `%c%s' doesn't allow an argument\n"
msgstr "%s: opcija `%c%s' ne dopu¹ta argument\n"

#: src/getopt.c:719 src/getopt.c:892
#, c-format
msgid "%s: option `%s' requires an argument\n"
msgstr "%s: opcija `%s' tra¾i argument\n"

#. --option
#: src/getopt.c:748
#, c-format
msgid "%s: unrecognized option `--%s'\n"
msgstr "%s: nepoznata opcija `--%s'\n"

#. +option or -option
#: src/getopt.c:752
#, c-format
msgid "%s: unrecognized option `%c%s'\n"
msgstr "%s: nepoznata opcija `%c%s'\n"

#. 1003.2 specifies the format of this message.
#: src/getopt.c:778
#, c-format
msgid "%s: illegal option -- %c\n"
msgstr "%s: nedopu¹tena opcija -- %c\n"

#: src/getopt.c:781
#, c-format
msgid "%s: invalid option -- %c\n"
msgstr "%s: neispravna opcija -- %c\n"

#. 1003.2 specifies the format of this message.
#: src/getopt.c:811 src/getopt.c:941
#, c-format
msgid "%s: option requires an argument -- %c\n"
msgstr "%s: opcija tra¾i argument -- %c\n"

#: src/getopt.c:858
#, c-format
msgid "%s: option `-W %s' is ambiguous\n"
msgstr "%s: opcija `-W %s' je dvosmislena\n"

#: src/getopt.c:876
#, c-format
msgid "%s: option `-W %s' doesn't allow an argument\n"
msgstr "%s: uz opciju `-W %s' ne ide argument\n"

#: src/host.c:356
msgid "Unknown host"
msgstr "Nepoznat host"

#. Message modeled after what gai_strerror returns in similar
#. circumstances.
#: src/host.c:360
msgid "Temporary failure in name resolution"
msgstr "Privremena pogre¹ka pri pronala¾enju adrese"

#: src/host.c:362
msgid "Unknown error"
msgstr "Nepoznata gre¹ka"

#: src/host.c:739
#, c-format
msgid "Resolving %s... "
msgstr "Tra¾im %s... "

#: src/host.c:786
msgid "failed: No IPv4/IPv6 addresses for host.\n"
msgstr "neuspjeh: raèunalo nema IPv4/IPv6 adresa.\n"

#: src/host.c:809
msgid "failed: timed out.\n"
msgstr "neuspjeh: isteklo vrijeme.\n"

#: src/html-url.c:289
#, c-format
msgid "%s: Cannot resolve incomplete link %s.\n"
msgstr "%s: Ne mogu sastaviti nepotpun link %s.\n"

#: src/html-url.c:696
#, c-format
msgid "%s: Invalid URL %s: %s\n"
msgstr "%s: Neispravan URL %s: %s\n"

#: src/http.c:355 src/http.c:1537
#, c-format
msgid "Failed writing HTTP request: %s.\n"
msgstr "Nisam uspio poslati HTTP zahtjev: %s.\n"

#: src/http.c:669
msgid "No headers, assuming HTTP/0.9"
msgstr "Nema zaglavlja, pretpostavljam HTTP/0.9"

#: src/http.c:1186
msgid "Disabling SSL due to encountered errors.\n"
msgstr "Iskljuèujem SSL zbog navedenih gre¹aka.\n"

#: src/http.c:1356
#, c-format
msgid "POST data file `%s' missing: %s\n"
msgstr "Nema spisa `%s' za POST: %s\n"

#: src/http.c:1405
#, c-format
msgid "Reusing existing connection to %s:%d.\n"
msgstr "Koristim postojeæu vezu prema %s:%d.\n"

#: src/http.c:1467
#, c-format
msgid "Failed writing to proxy: %s.\n"
msgstr "Nisam uspio pisati proxyju: %s.\n"

#: src/http.c:1476
#, c-format
msgid "Failed reading proxy response: %s\n"
msgstr "Nisam uspio procitati proxyjev odgovor: %s.\n"

#: src/http.c:1496
#, c-format
msgid "Proxy tunneling failed: %s"
msgstr "Neuspjeh tuneliranja kroz proxy: %s"

#: src/http.c:1543
#, c-format
msgid "%s request sent, awaiting response... "
msgstr "%s zahtjev poslan, i¹èekujem odgovor... "

#: src/http.c:1554
msgid "No data received.\n"
msgstr "Podaci nisu primljeni.\n"

#: src/http.c:1561
#, c-format
msgid "Read error (%s) in headers.\n"
msgstr "Gre¹ka pri èitanju zaglavlja (%s).\n"

#. If the authentication header is missing or
#. unrecognized, there's no sense in retrying.
#: src/http.c:1646
msgid "Unknown authentication scheme.\n"
msgstr "Nepoznata metoda ovjere.\n"

#: src/http.c:1670
msgid "Authorization failed.\n"
msgstr "Ovjera nije uspjela.\n"

#: src/http.c:1684
msgid "Malformed status line"
msgstr "Deformirana statusna linija"

#: src/http.c:1686
msgid "(no description)"
msgstr "(bez opisa)"

#: src/http.c:1749
#, c-format
msgid "Location: %s%s\n"
msgstr "Polo¾aj: %s%s\n"

#: src/http.c:1750 src/http.c:1857
msgid "unspecified"
msgstr "nenaznaèen"

#: src/http.c:1751
msgid " [following]"
msgstr " [pratim]"

#. If `-c' is in use and the file has been fully downloaded (or
#. the remote file has shrunk), Wget effectively requests bytes
#. after the end of file and the server response with 416.
#: src/http.c:1807
msgid ""
"\n"
"    The file is already fully retrieved; nothing to do.\n"
