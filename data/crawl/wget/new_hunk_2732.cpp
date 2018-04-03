#. No luck.
#. #### This message SUCKS.  We should see what was the
#. reason that nothing was retrieved.
#: src/ftp.c:1772
#, c-format
msgid "No matches on pattern `%s'.\n"
msgstr "Ni¹ta ne ide uz `%s'.\n"

#: src/ftp.c:1838
#, c-format
msgid "Wrote HTML-ized index to `%s' [%s].\n"
msgstr "Snimio HTML-iziran indeks u `%s' [%s].\n"

#: src/ftp.c:1843
#, c-format
msgid "Wrote HTML-ized index to `%s'.\n"
msgstr "Snimio HTML-iziran indeks u `%s'.\n"

#: src/getopt.c:675
#, c-format
msgid "%s: option `%s' is ambiguous\n"
msgstr "%s: opcija `%s' je dvosmislena\n"

#: src/getopt.c:700
#, c-format
msgid "%s: option `--%s' doesn't allow an argument\n"
msgstr "%s: uz opciju `--%s' ne ide argument\n"

#: src/getopt.c:705
#, c-format
msgid "%s: option `%c%s' doesn't allow an argument\n"
msgstr "%s: opcija `%c%s' ne dopu¹ta argument\n"

#: src/getopt.c:723 src/getopt.c:896
#, c-format
msgid "%s: option `%s' requires an argument\n"
msgstr "%s: opcija `%s' tra¾i argument\n"

#. --option
#: src/getopt.c:752
#, c-format
msgid "%s: unrecognized option `--%s'\n"
msgstr "%s: nepoznata opcija `--%s'\n"

#. +option or -option
#: src/getopt.c:756
#, c-format
msgid "%s: unrecognized option `%c%s'\n"
msgstr "%s: nepoznata opcija `%c%s'\n"

#. 1003.2 specifies the format of this message.
#: src/getopt.c:782
#, c-format
msgid "%s: illegal option -- %c\n"
msgstr "%s: nedopu¹tena opcija -- %c\n"

#: src/getopt.c:785
#, c-format
msgid "%s: invalid option -- %c\n"
msgstr "%s: neispravna opcija -- %c\n"

#. 1003.2 specifies the format of this message.
#: src/getopt.c:815 src/getopt.c:945
#, c-format
msgid "%s: option requires an argument -- %c\n"
msgstr "%s: opcija tra¾i argument -- %c\n"

#: src/getopt.c:862
#, c-format
msgid "%s: option `-W %s' is ambiguous\n"
msgstr "%s: opcija `-W %s' je dvosmislena\n"

#: src/getopt.c:880
#, c-format
msgid "%s: option `-W %s' doesn't allow an argument\n"
msgstr "%s: uz opciju `-W %s' ne ide argument\n"

#: src/host.c:370
msgid "Unknown host"
msgstr "Nepoznat host"

#. Message modeled after what gai_strerror returns in similar
#. circumstances.
#: src/host.c:374
msgid "Temporary failure in name resolution"
msgstr "Privremena pogre¹ka pri pronala¾enju adrese"

#: src/host.c:376
msgid "Unknown error"
msgstr "Nepoznata gre¹ka"

#: src/host.c:755
#, c-format
msgid "Resolving %s... "
msgstr "Tra¾im %s... "

#: src/host.c:799 src/host.c:828
#, c-format
msgid "failed: %s.\n"
msgstr "nije uspjelo: %s.\n"

#: src/host.c:808
msgid "failed: No IPv4/IPv6 addresses for host.\n"
msgstr "neuspjeh: raèunalo nema IPv4/IPv6 adresa.\n"

#: src/host.c:831
msgid "failed: timed out.\n"
msgstr "neuspjeh: isteklo vrijeme.\n"

#: src/html-url.c:298
#, c-format
msgid "%s: Cannot resolve incomplete link %s.\n"
msgstr "%s: Ne mogu sastaviti nepotpun link %s.\n"

#: src/http.c:373 src/http.c:1545
#, c-format
msgid "Failed writing HTTP request: %s.\n"
msgstr "Nisam uspio poslati HTTP zahtjev: %s.\n"

#: src/http.c:687
msgid "No headers, assuming HTTP/0.9"
msgstr "Nema zaglavlja, pretpostavljam HTTP/0.9"

#: src/http.c:1194
msgid "Disabling SSL due to encountered errors.\n"
msgstr "Iskljuèujem SSL zbog navedenih gre¹aka.\n"

#: src/http.c:1413
#, c-format
msgid "Reusing existing connection to %s:%d.\n"
msgstr "Koristim postojeæu vezu prema %s:%d.\n"

#: src/http.c:1475
#, fuzzy, c-format
msgid "Failed writing to proxy: %s.\n"
msgstr "Nisam uspio poslati HTTP zahtjev: %s.\n"

#: src/http.c:1484
#, c-format
msgid "Failed reading proxy response: %s\n"
msgstr "Nisam uspio procitati proxyjev odgovor: %s.\n"

#: src/http.c:1504
#, c-format
msgid "Proxy tunneling failed: %s"
msgstr "Neuspjeh tuneliranja kroz proxy: %s"

#: src/http.c:1551
#, c-format
msgid "%s request sent, awaiting response... "
msgstr "%s zahtjev poslan, i¹èekujem odgovor... "

#: src/http.c:1562
msgid "No data received.\n"
msgstr "Podaci nisu primljeni.\n"

#: src/http.c:1569
#, c-format
msgid "Read error (%s) in headers.\n"
msgstr "Gre¹ka pri èitanju zaglavlja (%s).\n"

#. If the authentication header is missing or
#. unrecognized, there's no sense in retrying.
#: src/http.c:1657
msgid "Unknown authentication scheme.\n"
msgstr "Nepoznata metoda ovjere.\n"

#: src/http.c:1681
msgid "Authorization failed.\n"
msgstr "Ovjera nije uspjela.\n"

#: src/http.c:1695
msgid "Malformed status line"
msgstr "Deformirana statusna linija"

#: src/http.c:1697
msgid "(no description)"
msgstr "(bez opisa)"

#: src/http.c:1768
#, c-format
msgid "Location: %s%s\n"
msgstr "Polo¾aj: %s%s\n"

#: src/http.c:1769 src/http.c:1869
msgid "unspecified"
msgstr "nenaznaèen"

#: src/http.c:1770
msgid " [following]"
msgstr " [pratim]"

#. If `-c' is in use and the file has been fully downloaded (or
#. the remote file has shrunk), Wget effectively requests bytes
#. after the end of file and the server response with 416.
#: src/http.c:1819
msgid ""
"\n"
"    The file is already fully retrieved; nothing to do.\n"
