#. No luck.
#. #### This message SUCKS.  We should see what was the
#. reason that nothing was retrieved.
#: src/ftp.c:1778
#, c-format
msgid "No matches on pattern `%s'.\n"
msgstr "Cap coincidència amb el patró «%s».\n"

#: src/ftp.c:1844
#, c-format
msgid "Wrote HTML-ized index to `%s' [%s].\n"
msgstr "S'ha escrit un índex HTMLitzat a «%s» [%s].\n"

#: src/ftp.c:1849
#, c-format
msgid "Wrote HTML-ized index to `%s'.\n"
msgstr "S'ha escrit un índex HTMLitzat a «%s».\n"

#: src/getopt.c:675
#, c-format
msgid "%s: option `%s' is ambiguous\n"
msgstr "%s: l'opció «%s» és ambigua\n"

#: src/getopt.c:700
#, c-format
msgid "%s: option `--%s' doesn't allow an argument\n"
msgstr "%s: l'opció «--%s» no admet arguments\n"

#: src/getopt.c:705
#, c-format
msgid "%s: option `%c%s' doesn't allow an argument\n"
msgstr "%s: l'opció «%c%s» no admet arguments\n"

#: src/getopt.c:723 src/getopt.c:896
#, c-format
msgid "%s: option `%s' requires an argument\n"
msgstr "%s: l'opció «%s» requereix un argument\n"

#. --option
#: src/getopt.c:752
#, c-format
msgid "%s: unrecognized option `--%s'\n"
msgstr "%s: l'opció «--%s» és desconeguda\n"

#. +option or -option
#: src/getopt.c:756
#, c-format
msgid "%s: unrecognized option `%c%s'\n"
msgstr "%s: l'opció «%c%s» és desconeguda\n"

#. 1003.2 specifies the format of this message.
#: src/getopt.c:782
#, c-format
msgid "%s: illegal option -- %c\n"
msgstr "%s: l'opció és il·legal -- %c\n"

#: src/getopt.c:785
#, c-format
msgid "%s: invalid option -- %c\n"
msgstr "%s: l'opció no és vàlida -- %c\n"

#. 1003.2 specifies the format of this message.
#: src/getopt.c:815 src/getopt.c:945
#, c-format
msgid "%s: option requires an argument -- %c\n"
msgstr "%s: l'opció requereix un argument -- %c\n"

#: src/getopt.c:862
#, c-format
msgid "%s: option `-W %s' is ambiguous\n"
msgstr "%s: l'opció «-W %s» és ambigua\n"

#: src/getopt.c:880
#, c-format
msgid "%s: option `-W %s' doesn't allow an argument\n"
msgstr "%s: l'opció «-W %s» no admet arguments\n"

#: src/host.c:366
msgid "Unknown host"
msgstr "Servidor desconegut"

#. Message modeled after what gai_strerror returns in similar
#. circumstances.
#: src/host.c:370
msgid "Temporary failure in name resolution"
msgstr "S'ha produït un error temporal en la resolució de noms"

#: src/host.c:372
msgid "Unknown error"
msgstr "S'ha produït un error desconegut"

#: src/host.c:751
#, c-format
msgid "Resolving %s... "
msgstr "S'està resolent %s... "

#: src/host.c:798
msgid "failed: No IPv4/IPv6 addresses for host.\n"
msgstr "error: No hi ha adreces IPv4/IPv6 per al servidor.\n"

#: src/host.c:821
msgid "failed: timed out.\n"
msgstr "error: s'ha exhaurit el temps.\n"

#: src/html-url.c:298
#, c-format
msgid "%s: Cannot resolve incomplete link %s.\n"
msgstr "%s: No s'ha pogut resoldre l'enllaç incomplet %s.\n"

#: src/html-url.c:705
#, c-format
msgid "%s: Invalid URL %s: %s\n"
msgstr "%s: L'URL %s no és vàlid: %s\n"

#: src/http.c:373
#, c-format
msgid "Failed writing HTTP request: %s.\n"
msgstr "S'ha produït un error en escriure la petició HTTP: %s.\n"

#: src/http.c:687
msgid "No headers, assuming HTTP/0.9"
msgstr "No hi ha capçaleres, s'assumeix HTTP/0.9"

#: src/http.c:1204
msgid "Disabling SSL due to encountered errors.\n"
msgstr "S'està inhabilitant SSL a causa dels errors trobats.\n"

#: src/http.c:1374
#, c-format
msgid "POST data file `%s' missing: %s\n"
msgstr "Manca el fitxer de dades POST «%s»: %s\n"

#: src/http.c:1423
#, c-format
msgid "Reusing existing connection to %s:%d.\n"
msgstr "S'està reutilitzant la connexió a %s:%d.\n"

#: src/http.c:1492
#, c-format
msgid "Failed reading proxy response: %s\n"
msgstr "S'ha produït un error en llegir la resposta del servidor intermediari: %s\n"

#: src/http.c:1512
#, c-format
msgid "Proxy tunneling failed: %s"
msgstr "Ha fallat la tunelització del servidor intermediari: %s"

#: src/http.c:1557
#, c-format
msgid "%s request sent, awaiting response... "
msgstr "%s: s'ha enviat la petició, s'està esperant una resposta..."

#: src/http.c:1568
msgid "No data received.\n"
msgstr "No s'ha rebut cap dada\n"

#: src/http.c:1575
#, c-format
msgid "Read error (%s) in headers.\n"
msgstr "S'ha produït un error de lectura (%s) a les capçaleres.\n"

#. If the authentication header is missing or
#. unrecognized, there's no sense in retrying.
#: src/http.c:1660
msgid "Unknown authentication scheme.\n"
msgstr "L'esquema d'autenticació és desconegut.\n"

#: src/http.c:1684
msgid "Authorization failed.\n"
msgstr "Ha fallat l'autorització.\n"

#: src/http.c:1698
msgid "Malformed status line"
msgstr "La línia d'estat és malformada"

#: src/http.c:1700
msgid "(no description)"
msgstr "(sense descripció)"

#: src/http.c:1763
#, c-format
msgid "Location: %s%s\n"
msgstr "Ubicació: %s%s\n"

# és femení: ubicació/mida. eac
#: src/http.c:1764 src/http.c:1871
msgid "unspecified"
msgstr "no especificada"

#: src/http.c:1765
msgid " [following]"
msgstr " [es segueix]"

#. If `-c' is in use and the file has been fully downloaded (or
#. the remote file has shrunk), Wget effectively requests bytes
#. after the end of file and the server response with 416.
#: src/http.c:1821
msgid ""
"\n"
"    The file is already fully retrieved; nothing to do.\n"
