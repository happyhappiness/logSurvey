#. No luck.
#. #### This message SUCKS.  We should see what was the
#. reason that nothing was retrieved.
#: src/ftp.c:1753
#, c-format
msgid "No matches on pattern `%s'.\n"
msgstr "Cap coincidència amb el patró «%s».\n"

#: src/ftp.c:1819
#, c-format
msgid "Wrote HTML-ized index to `%s' [%s].\n"
msgstr "S'ha escrit un índex HTMLitzat a «%s» [%s].\n"

#: src/ftp.c:1824
#, c-format
msgid "Wrote HTML-ized index to `%s'.\n"
msgstr "S'ha escrit un índex HTMLitzat a «%s».\n"

#: src/getopt.c:670
#, c-format
msgid "%s: option `%s' is ambiguous\n"
msgstr "%s: l'opció «%s» és ambigua\n"

#: src/getopt.c:695
#, c-format
msgid "%s: option `--%s' doesn't allow an argument\n"
msgstr "%s: l'opció «--%s» no admet arguments\n"

#: src/getopt.c:700
#, c-format
msgid "%s: option `%c%s' doesn't allow an argument\n"
msgstr "%s: l'opció «%c%s» no admet arguments\n"

#: src/getopt.c:718 src/getopt.c:891
#, c-format
msgid "%s: option `%s' requires an argument\n"
msgstr "%s: l'opció «%s» requereix un argument\n"

#. --option
#: src/getopt.c:747
#, c-format
msgid "%s: unrecognized option `--%s'\n"
msgstr "%s: l'opció «--%s» és desconeguda\n"

#. +option or -option
#: src/getopt.c:751
#, c-format
msgid "%s: unrecognized option `%c%s'\n"
msgstr "%s: l'opció «%c%s» és desconeguda\n"

#. 1003.2 specifies the format of this message.
#: src/getopt.c:777
#, c-format
msgid "%s: illegal option -- %c\n"
msgstr "%s: l'opció és il·legal -- %c\n"

#: src/getopt.c:780
#, c-format
msgid "%s: invalid option -- %c\n"
msgstr "%s: l'opció no és vàlida -- %c\n"

#. 1003.2 specifies the format of this message.
#: src/getopt.c:810 src/getopt.c:940
#, c-format
msgid "%s: option requires an argument -- %c\n"
msgstr "%s: l'opció requereix un argument -- %c\n"

#: src/getopt.c:857
#, c-format
msgid "%s: option `-W %s' is ambiguous\n"
msgstr "%s: l'opció «-W %s» és ambigua\n"

#: src/getopt.c:875
#, c-format
msgid "%s: option `-W %s' doesn't allow an argument\n"
msgstr "%s: l'opció «-W %s» no admet arguments\n"

#: src/host.c:347
msgid "Unknown host"
msgstr "Servidor desconegut"

#. Message modeled after what gai_strerror returns in similar
#. circumstances.
#: src/host.c:351
msgid "Temporary failure in name resolution"
msgstr "S'ha produït un error temporal en la resolució de noms"

#: src/host.c:353
msgid "Unknown error"
msgstr "S'ha produït un error desconegut"

#: src/host.c:714
#, c-format
msgid "Resolving %s... "
msgstr "S'està resolent %s... "

#: src/host.c:761
msgid "failed: No IPv4/IPv6 addresses for host.\n"
msgstr "error: No hi ha adreces IPv4/IPv6 per al servidor.\n"

#: src/host.c:784
msgid "failed: timed out.\n"
msgstr "error: s'ha exhaurit el temps.\n"

#: src/html-url.c:288
#, c-format
msgid "%s: Cannot resolve incomplete link %s.\n"
msgstr "%s: No s'ha pogut resoldre l'enllaç incomplet %s.\n"

#: src/html-url.c:695
#, c-format
msgid "%s: Invalid URL %s: %s\n"
msgstr "%s: L'URL %s no és vàlid: %s\n"

#: src/http.c:367
#, c-format
msgid "Failed writing HTTP request: %s.\n"
msgstr "S'ha produït un error en escriure la petició HTTP: %s.\n"

#: src/http.c:736
msgid "No headers, assuming HTTP/0.9"
msgstr "No hi ha capçaleres, s'assumeix HTTP/0.9"

#: src/http.c:1413
msgid "Disabling SSL due to encountered errors.\n"
msgstr "S'està inhabilitant SSL a causa dels errors trobats.\n"

#: src/http.c:1566
#, c-format
msgid "POST data file `%s' missing: %s\n"
msgstr "Manca el fitxer de dades POST «%s»: %s\n"

#: src/http.c:1615
#, c-format
msgid "Reusing existing connection to %s:%d.\n"
msgstr "S'està reutilitzant la connexió a %s:%d.\n"

#: src/http.c:1684
#, c-format
msgid "Failed reading proxy response: %s\n"
msgstr ""
"S'ha produït un error en llegir la resposta del servidor intermediari: %s\n"

#: src/http.c:1704
#, c-format
msgid "Proxy tunneling failed: %s"
msgstr "Ha fallat la tunelització del servidor intermediari: %s"

#: src/http.c:1749
#, c-format
msgid "%s request sent, awaiting response... "
msgstr "%s: s'ha enviat la petició, s'està esperant una resposta..."

#: src/http.c:1760
msgid "No data received.\n"
msgstr "No s'ha rebut cap dada\n"

#: src/http.c:1767
#, c-format
msgid "Read error (%s) in headers.\n"
msgstr "S'ha produït un error de lectura (%s) a les capçaleres.\n"

#. If opt.noclobber is turned on and file already exists, do not
#. retrieve the file
#: src/http.c:1813
#, c-format
msgid ""
"File `%s' already there; not retrieving.\n"
"\n"
msgstr ""
"El fitxer «%s» ja existeix, no es descarrega.\n"
"\n"

#. If the authentication header is missing or
#. unrecognized, there's no sense in retrying.
#: src/http.c:1966
msgid "Unknown authentication scheme.\n"
msgstr "L'esquema d'autenticació és desconegut.\n"

#: src/http.c:1997
msgid "Authorization failed.\n"
msgstr "Ha fallat l'autorització.\n"

#: src/http.c:2011
msgid "Malformed status line"
msgstr "La línia d'estat és malformada"

#: src/http.c:2013
msgid "(no description)"
msgstr "(sense descripció)"

#: src/http.c:2076
#, c-format
msgid "Location: %s%s\n"
msgstr "Ubicació: %s%s\n"

# és femení: ubicació/mida. eac
#: src/http.c:2077 src/http.c:2184
msgid "unspecified"
msgstr "no especificada"

#: src/http.c:2078
msgid " [following]"
msgstr " [es segueix]"

#. If `-c' is in use and the file has been fully downloaded (or
#. the remote file has shrunk), Wget effectively requests bytes
#. after the end of file and the server response with 416.
#: src/http.c:2134
msgid ""
"\n"
"    The file is already fully retrieved; nothing to do.\n"
