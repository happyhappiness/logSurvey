#. No luck.
#. #### This message SUCKS.  We should see what was the
#. reason that nothing was retrieved.
#: src/ftp.c:1753
#, c-format
msgid "No matches on pattern `%s'.\n"
msgstr "Pas de concordance avec le patron � %s �.\n"

#: src/ftp.c:1819
#, c-format
msgid "Wrote HTML-ized index to `%s' [%s].\n"
msgstr "Index HTML-is� �crit dans � %s � [%s].\n"

#: src/ftp.c:1824
#, c-format
msgid "Wrote HTML-ized index to `%s'.\n"
msgstr "Index HTML-is� �crit dans � %s �.\n"

#: src/getopt.c:670
#, c-format
msgid "%s: option `%s' is ambiguous\n"
msgstr "%s: l'option � %s � est ambigu�.\n"

#: src/getopt.c:695
#, c-format
msgid "%s: option `--%s' doesn't allow an argument\n"
msgstr "%s: l'option � --%s � ne permet pas d'argument.\n"

#: src/getopt.c:700
#, c-format
msgid "%s: option `%c%s' doesn't allow an argument\n"
msgstr "%s: l'option � %c%s � ne permet pas d'argument.\n"

#: src/getopt.c:718 src/getopt.c:891
#, c-format
msgid "%s: option `%s' requires an argument\n"
msgstr "%s: l'option � %s � requiert un argument.\n"

#. --option
#: src/getopt.c:747
#, c-format
msgid "%s: unrecognized option `--%s'\n"
msgstr "%s: l'option � --%s � n'est pas reconnue.\n"

#. +option or -option
#: src/getopt.c:751
#, c-format
msgid "%s: unrecognized option `%c%s'\n"
msgstr "%s: l'option � %c%s � n'est pas reconnue.\n"

#. 1003.2 specifies the format of this message.
#: src/getopt.c:777
#, c-format
msgid "%s: illegal option -- %c\n"
msgstr "%s: option ill�gale -- %c\n"

#: src/getopt.c:780
#, c-format
msgid "%s: invalid option -- %c\n"
msgstr "%s: option invalide -- %c\n"

#. 1003.2 specifies the format of this message.
#: src/getopt.c:810 src/getopt.c:940
#, c-format
msgid "%s: option requires an argument -- %c\n"
msgstr "%s: l'option requiert un argument -- %c\n"

#: src/getopt.c:857
#, c-format
msgid "%s: option `-W %s' is ambiguous\n"
msgstr "%s: l'option � -W %s � est ambigu�.\n"

#: src/getopt.c:875
#, c-format
msgid "%s: option `-W %s' doesn't allow an argument\n"
msgstr "%s: l'option � -W %s � ne permet pas d'argument.\n"

#: src/host.c:347
msgid "Unknown host"
msgstr "H�te inconnu"

#. Message modeled after what gai_strerror returns in similar
#. circumstances.
#: src/host.c:351
msgid "Temporary failure in name resolution"
msgstr "?chec temporaire dans la r�solution du nom"

#: src/host.c:353
msgid "Unknown error"
msgstr "ERREUR inconnue"

#: src/host.c:714
#, c-format
msgid "Resolving %s... "
msgstr "R�solution de %s... "

#: src/host.c:761
msgid "failed: No IPv4/IPv6 addresses for host.\n"
msgstr "�chec: pas d'adresses IPv4/IPv6 pour l'h�te.\n"

#: src/host.c:784
msgid "failed: timed out.\n"
msgstr "�chec: expiration de la minuterie\n"

#: src/html-url.c:288
#, c-format
msgid "%s: Cannot resolve incomplete link %s.\n"
msgstr "%s: ne peut r�soudre le lien incomplet %s.\n"

#: src/html-url.c:695
#, c-format
msgid "%s: Invalid URL %s: %s\n"
msgstr "%s: URL invalide %s: %s\n"

#: src/http.c:367
#, c-format
msgid "Failed writing HTTP request: %s.\n"
msgstr "�CHEC d'�criture de la requ�te HTTP: %s.\n"

#: src/http.c:736
msgid "No headers, assuming HTTP/0.9"
msgstr "Pas d'en-t�te, HTTP/0.9 assum�"

#: src/http.c:1413
msgid "Disabling SSL due to encountered errors.\n"
msgstr "D�sactivation SSL en raison des erreurs rencontr�s.\n"

#: src/http.c:1566
#, c-format
msgid "POST data file `%s' missing: %s\n"
msgstr "Fichier de donn�es POST `%s' est manquant: %s\n"

#: src/http.c:1615
#, c-format
msgid "Reusing existing connection to %s:%d.\n"
msgstr "R�utilisation de la connexion existante vers %s:%d.\n"

#: src/http.c:1684
#, c-format
msgid "Failed reading proxy response: %s\n"
msgstr "�CHEC de lecture de la r�ponse proxy: %s.\n"

#: src/http.c:1704
#, c-format
msgid "Proxy tunneling failed: %s"
msgstr "�chec du tunneling proxy: %s"

#: src/http.c:1749
#, c-format
msgid "%s request sent, awaiting response... "
msgstr "requ�te %s transmise, en attente de la r�ponse..."

#: src/http.c:1760
msgid "No data received.\n"
msgstr "Aucune donn�e re�ue.\n"

#: src/http.c:1767
#, c-format
msgid "Read error (%s) in headers.\n"
msgstr "ERREUR de lecture (%s) de l'en-t�te.\n"

#. If opt.noclobber is turned on and file already exists, do not
#. retrieve the file
#: src/http.c:1813
#, c-format
msgid ""
"File `%s' already there; not retrieving.\n"
"\n"
msgstr ""
"Fichier � %s � est d�j� l�; pas de r�cup�ration.\n"
"\n"

#. If the authentication header is missing or
#. unrecognized, there's no sense in retrying.
#: src/http.c:1966
msgid "Unknown authentication scheme.\n"
msgstr "Sch�me d'authentification inconnu.\n"

#: src/http.c:1997
msgid "Authorization failed.\n"
msgstr "�CHEC d'autorisation.\n"

#: src/http.c:2011
msgid "Malformed status line"
msgstr "Ligne d'�tat mal compos�e"

#: src/http.c:2013
msgid "(no description)"
msgstr "(pas de description)"

#: src/http.c:2076
#, c-format
msgid "Location: %s%s\n"
msgstr "Emplacement: %s%s\n"

#: src/http.c:2077 src/http.c:2184
msgid "unspecified"
msgstr "non sp�cifi�"

#: src/http.c:2078
msgid " [following]"
msgstr " [suivant]"

#. If `-c' is in use and the file has been fully downloaded (or
#. the remote file has shrunk), Wget effectively requests bytes
#. after the end of file and the server response with 416.
#: src/http.c:2134
msgid ""
"\n"
"    The file is already fully retrieved; nothing to do.\n"
