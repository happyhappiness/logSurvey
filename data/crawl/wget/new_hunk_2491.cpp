#. No luck.
#. #### This message SUCKS.  We should see what was the
#. reason that nothing was retrieved.
#: src/ftp.c:1753
#, c-format
msgid "No matches on pattern `%s'.\n"
msgstr "Ni zadetkov za vzorec `%s'.\n"

#: src/ftp.c:1819
#, fuzzy, c-format
msgid "Wrote HTML-ized index to `%s' [%s].\n"
msgstr "Kazalo v HTML zapisal kot `%s' [%ld].\n"

#: src/ftp.c:1824
#, c-format
msgid "Wrote HTML-ized index to `%s'.\n"
msgstr "Kazalo v HTML zapisal kot `%s'.\n"

#: src/getopt.c:670
#, c-format
msgid "%s: option `%s' is ambiguous\n"
msgstr "%s: izbira `%s' je dvoumna\n"

#: src/getopt.c:695
#, c-format
msgid "%s: option `--%s' doesn't allow an argument\n"
msgstr "%s: izbira `--%s' ne dopu��a dodatnih argumentov\n"

#: src/getopt.c:700
#, c-format
msgid "%s: option `%c%s' doesn't allow an argument\n"
msgstr "%s: izbira `%c%s' ne dopu��a dodatnih argumentov\n"

#: src/getopt.c:718 src/getopt.c:891
#, c-format
msgid "%s: option `%s' requires an argument\n"
msgstr "%s: izbira `%s' zahteva argument\n"

#. --option
#: src/getopt.c:747
#, c-format
msgid "%s: unrecognized option `--%s'\n"
msgstr "%s: neprepoznana izbira `--%s'\n"

#. +option or -option
#: src/getopt.c:751
#, c-format
msgid "%s: unrecognized option `%c%s'\n"
msgstr "%s: neznana izbira `%c%s'\n"

#. 1003.2 specifies the format of this message.
#: src/getopt.c:777
#, c-format
msgid "%s: illegal option -- %c\n"
msgstr "%s: nedovoljena izbira -- %c\n"

#: src/getopt.c:780
#, c-format
msgid "%s: invalid option -- %c\n"
msgstr "%s: neveljavna izbira -- %c\n"

#. 1003.2 specifies the format of this message.
#: src/getopt.c:810 src/getopt.c:940
#, c-format
msgid "%s: option requires an argument -- %c\n"
msgstr "%s: izbira zahteva argument -- %c\n"

#: src/getopt.c:857
#, c-format
msgid "%s: option `-W %s' is ambiguous\n"
msgstr "%s: izbira '-W %s' je dvoumna\n"

#: src/getopt.c:875
#, c-format
msgid "%s: option `-W %s' doesn't allow an argument\n"
msgstr "%s: izbira `-W %s' ne dopu��a dodatnih argumentov\n"

#: src/host.c:347
#, fuzzy
msgid "Unknown host"
msgstr "Neznana napaka"

#. Message modeled after what gai_strerror returns in similar
#. circumstances.
#: src/host.c:351
msgid "Temporary failure in name resolution"
msgstr ""

#: src/host.c:353
msgid "Unknown error"
msgstr "Neznana napaka"

#: src/host.c:714
#, c-format
msgid "Resolving %s... "
msgstr "Razre�uje se %s..."

#: src/host.c:761
msgid "failed: No IPv4/IPv6 addresses for host.\n"
msgstr ""

#: src/host.c:784
msgid "failed: timed out.\n"
msgstr "spodletelo: zakasnitev.\n"

#: src/html-url.c:288
#, c-format
msgid "%s: Cannot resolve incomplete link %s.\n"
msgstr "%s: Ni mo� razre�iti nepopolne povezave %s.\n"

#: src/html-url.c:695
#, fuzzy, c-format
msgid "%s: Invalid URL %s: %s\n"
msgstr "%s: %s: Neveljavna vrednost '%s'\n"

#: src/http.c:367
#, c-format
msgid "Failed writing HTTP request: %s.\n"
msgstr "Napaka pri pisanju zahteve HTTP: %s.\n"

#: src/http.c:736
msgid "No headers, assuming HTTP/0.9"
msgstr ""

#: src/http.c:1413
msgid "Disabling SSL due to encountered errors.\n"
msgstr ""

#: src/http.c:1566
#, c-format
msgid "POST data file `%s' missing: %s\n"
msgstr ""

#: src/http.c:1615
#, fuzzy, c-format
msgid "Reusing existing connection to %s:%d.\n"
msgstr "Znova uporabljam povezavo z %s:%hu.\n"

#: src/http.c:1684
#, fuzzy, c-format
msgid "Failed reading proxy response: %s\n"
msgstr "Napaka pri pisanju zahteve HTTP: %s.\n"

#: src/http.c:1704
#, c-format
msgid "Proxy tunneling failed: %s"
msgstr ""

#: src/http.c:1749
#, c-format
msgid "%s request sent, awaiting response... "
msgstr "%s zahteva poslana, �akam odgovor... "

#: src/http.c:1760
#, fuzzy
msgid "No data received.\n"
msgstr "Brez sprejetih podatkov"

#: src/http.c:1767
#, c-format
msgid "Read error (%s) in headers.\n"
msgstr "Napaka pri branju glave (%s).\n"

#. If opt.noclobber is turned on and file already exists, do not
#. retrieve the file
#: src/http.c:1813
#, fuzzy, c-format
msgid ""
"File `%s' already there; not retrieving.\n"
"\n"
msgstr "Datoteka `%s' �e obstaja, ne jemljem.\n"

#. If the authentication header is missing or
#. unrecognized, there's no sense in retrying.
#: src/http.c:1966
msgid "Unknown authentication scheme.\n"
msgstr "Neznata metoda avtentifikacije.\n"

#: src/http.c:1997
msgid "Authorization failed.\n"
msgstr "Avtorizacija neuspe�na.\n"

#: src/http.c:2011
msgid "Malformed status line"
msgstr "Zmali�ena statusna linija"

#: src/http.c:2013
msgid "(no description)"
msgstr "(brez opisa)"

#: src/http.c:2076
#, c-format
msgid "Location: %s%s\n"
msgstr "Polo�aj: %s%s\n"

#: src/http.c:2077 src/http.c:2184
msgid "unspecified"
msgstr "nedolo�en"

#: src/http.c:2078
msgid " [following]"
msgstr " [spremljam]"

#. If `-c' is in use and the file has been fully downloaded (or
#. the remote file has shrunk), Wget effectively requests bytes
#. after the end of file and the server response with 416.
#: src/http.c:2134
msgid ""
"\n"
"    The file is already fully retrieved; nothing to do.\n"