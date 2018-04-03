#. No luck.
#. #### This message SUCKS.  We should see what was the
#. reason that nothing was retrieved.
#: src/ftp.c:1753
#, c-format
msgid "No matches on pattern `%s'.\n"
msgstr "Vzoru `%s' nič nezodpovedá.\n"

# , c-format
#: src/ftp.c:1819
#, c-format
msgid "Wrote HTML-ized index to `%s' [%s].\n"
msgstr "Výpis adresára v HTML formáte bol zapísaný do `%s' [%s].\n"

# , c-format
#: src/ftp.c:1824
#, c-format
msgid "Wrote HTML-ized index to `%s'.\n"
msgstr "Výpis adresára v HTML formáte bol zapísaný do `%s'.\n"

# , c-format
#: src/getopt.c:670
#, c-format
msgid "%s: option `%s' is ambiguous\n"
msgstr "%s: voľba `%s' nie je jednoznačná\n"

# , c-format
#: src/getopt.c:695
#, c-format
msgid "%s: option `--%s' doesn't allow an argument\n"
msgstr "%s: voľba `--%s' nepodporuje parameter\n"

# , c-format
#: src/getopt.c:700
#, c-format
msgid "%s: option `%c%s' doesn't allow an argument\n"
msgstr "%s: voľba `%c%s' nepodporuje parameter\n"

# , c-format
#: src/getopt.c:718 src/getopt.c:891
#, c-format
msgid "%s: option `%s' requires an argument\n"
msgstr "%s: voľba `%s' vyžaduje parameter\n"

# , c-format
#. --option
#: src/getopt.c:747
#, c-format
msgid "%s: unrecognized option `--%s'\n"
msgstr "%s: neznáma voľba `--%s'\n"

# , c-format
#. +option or -option
#: src/getopt.c:751
#, c-format
msgid "%s: unrecognized option `%c%s'\n"
msgstr "%s: neznáma voľba `%c%s'\n"

# , c-format
#. 1003.2 specifies the format of this message.
#: src/getopt.c:777
#, c-format
msgid "%s: illegal option -- %c\n"
msgstr "%s: neprípustná voľba -- %c\n"

# , c-format
#: src/getopt.c:780
#, c-format
msgid "%s: invalid option -- %c\n"
msgstr "%s: neplatná voľba -- %c\n"

# , c-format
#. 1003.2 specifies the format of this message.
#: src/getopt.c:810 src/getopt.c:940
#, c-format
msgid "%s: option requires an argument -- %c\n"
msgstr "%s: voľba vyžaduje parameter -- %c\n"

# , c-format
#: src/getopt.c:857
#, c-format
msgid "%s: option `-W %s' is ambiguous\n"
msgstr "%s: voľba `-W %s' nie je jednoznačná\n"

# , c-format
#: src/getopt.c:875
#, c-format
msgid "%s: option `-W %s' doesn't allow an argument\n"
msgstr "%s: voľba `-W %s' nepodporuje parameter\n"

#: src/host.c:347
msgid "Unknown host"
msgstr "Neznámy hostiteľ"

#. Message modeled after what gai_strerror returns in similar
#. circumstances.
#: src/host.c:351
msgid "Temporary failure in name resolution"
msgstr "Dočasné zlyhanie pri prevode mena"

#: src/host.c:353
msgid "Unknown error"
msgstr "Neznáma chyba"

# , c-format
#: src/host.c:714
#, c-format
msgid "Resolving %s... "
msgstr "Prevádzam %s na IP adresu... "

#: src/host.c:761
msgid "failed: No IPv4/IPv6 addresses for host.\n"
msgstr "zlyhalo: Hostiteľ nemá IPv4/IPv6 adresy.\n"

#: src/host.c:784
msgid "failed: timed out.\n"
msgstr "zlyhalo: časový limit vypršal.\n"

#: src/html-url.c:288
#, c-format
msgid "%s: Cannot resolve incomplete link %s.\n"
msgstr "%s: Nemôžem rozložiť neúplný odkaz %s.\n"

# , c-format
#: src/html-url.c:695
#, c-format
msgid "%s: Invalid URL %s: %s\n"
msgstr "%s: Neplatné URL %s: %s\n"

#: src/http.c:367
#, c-format
msgid "Failed writing HTTP request: %s.\n"
msgstr "Požiadavku HTTP nebolo možné odoslať: %s.\n"

#: src/http.c:736
msgid "No headers, assuming HTTP/0.9"
msgstr "Bez hlavičiek, predpokladám HTTP/0.9"

#: src/http.c:1413
msgid "Disabling SSL due to encountered errors.\n"
msgstr "Deaktivujem SSL z dôvodu výskytu chýb.\n"

#: src/http.c:1566
#, c-format
msgid "POST data file `%s' missing: %s\n"
msgstr "Chýba POST dátový súbor `%s': %s\n"

# , c-format
#: src/http.c:1615
#, c-format
msgid "Reusing existing connection to %s:%d.\n"
msgstr "Používam existujúce spojenie s %s:%d.\n"

#: src/http.c:1684
#, c-format
msgid "Failed reading proxy response: %s\n"
msgstr "Zlyhalo čítanie odpovede z proxy: %s\n"

#: src/http.c:1704
#, c-format
msgid "Proxy tunneling failed: %s"
msgstr "Tunelovanie proxy zlyhalo: %s"

# , c-format
#: src/http.c:1749
#, c-format
msgid "%s request sent, awaiting response... "
msgstr "%s požiadavka odoslaná, čakám na odpoveď... "

#: src/http.c:1760
msgid "No data received.\n"
msgstr "Neboli prijaté žiadne dáta.\n"

# , c-format
#: src/http.c:1767
#, c-format
msgid "Read error (%s) in headers.\n"
msgstr "Chyba (%s) pri čítaní hlavičiek.\n"

# , c-format
#. If opt.noclobber is turned on and file already exists, do not
#. retrieve the file
#: src/http.c:1813
#, c-format
msgid ""
"File `%s' already there; not retrieving.\n"
"\n"
msgstr "Súbor `%s' je už tam, nebudem ho prenášať.\n"

#. If the authentication header is missing or
#. unrecognized, there's no sense in retrying.
#: src/http.c:1966
msgid "Unknown authentication scheme.\n"
msgstr "Neznámy spôsob autentifikácie.\n"

#: src/http.c:1997
msgid "Authorization failed.\n"
msgstr "Autorizácia zlyhala.\n"

#: src/http.c:2011
msgid "Malformed status line"
msgstr "Odpoveď servera má skomolený stavový riadok"

#: src/http.c:2013
msgid "(no description)"
msgstr "(bez popisu)"

# , c-format
#: src/http.c:2076
#, c-format
msgid "Location: %s%s\n"
msgstr "Presmerované na: %s%s\n"

#: src/http.c:2077 src/http.c:2184
msgid "unspecified"
msgstr "neudané"

#: src/http.c:2078
msgid " [following]"
msgstr " [nasledujem]"

#. If `-c' is in use and the file has been fully downloaded (or
#. the remote file has shrunk), Wget effectively requests bytes
#. after the end of file and the server response with 416.
#: src/http.c:2134
msgid ""
"\n"
"    The file is already fully retrieved; nothing to do.\n"
