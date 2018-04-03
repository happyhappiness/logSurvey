msgid "%s: option `-W %s' doesn't allow an argument\n"
msgstr "%s: l'option « -W %s » ne permet pas d'argument.\n"

#: src/host.c:368
#, fuzzy
msgid "Unknown host"
msgstr "ERREUR inconnue"

#. Message modeled after what gai_strerror returns in similar
#. circumstances.
#: src/host.c:372
msgid "Temporary failure in name resolution"
msgstr ""

#: src/host.c:374
msgid "Unknown error"
msgstr "ERREUR inconnue"

#: src/host.c:748
#, c-format
msgid "Resolving %s... "
msgstr "Résolution de %s... "

#: src/host.c:792 src/host.c:839
#, c-format
msgid "failed: %s.\n"
msgstr "échec: %s.\n"

#: src/host.c:801
msgid "failed: No IPv4/IPv6 addresses for host.\n"
msgstr ""

#: src/host.c:842
msgid "failed: timed out.\n"
msgstr "échec: expiration de la minuterie\n"

#: src/html-url.c:297
#, c-format
msgid "%s: Cannot resolve incomplete link %s.\n"
msgstr "%s: ne peut résoudre le lien incomplet %s.\n"

#: src/http.c:349 src/http.c:1504
#, c-format
msgid "Failed writing HTTP request: %s.\n"
msgstr "ÉCHEC d'écriture de la requête HTTP: %s.\n"

#: src/http.c:663
msgid "No headers, assuming HTTP/0.9"
msgstr ""

#. this is fatal
#: src/http.c:1151
msgid "Failed to set up an SSL context\n"
msgstr "ÉCHEC d'initialisation du contexte SSL\n"

#: src/http.c:1156
#, c-format
msgid "Failed to load certificates from %s\n"
msgstr "ÉCHEC de chargement des certificats de %s\n"

#: src/http.c:1159 src/http.c:1166
msgid "Trying without the specified certificate\n"
msgstr "Essai sans le certificat spécifié\n"

#: src/http.c:1163
#, c-format
msgid "Failed to get certificate key from %s\n"
msgstr "ÉCHEC d'obtention de la clé du certificat de %s\n"

#: src/http.c:1382
#, fuzzy, c-format
msgid "Reusing existing connection to %s:%d.\n"
msgstr "Réutilisation de la connexion vers %s:%hu.\n"

#: src/http.c:1434
#, fuzzy, c-format
msgid "Failed writing to proxy: %s.\n"
msgstr "ÉCHEC d'écriture de la requête HTTP: %s.\n"

#: src/http.c:1443
#, fuzzy, c-format
msgid "Failed reading proxy response: %s\n"
msgstr "ÉCHEC d'écriture de la requête HTTP: %s.\n"

#: src/http.c:1463
#, c-format
msgid "Proxy tunneling failed: %s"
msgstr ""

#: src/http.c:1510
#, c-format
msgid "%s request sent, awaiting response... "
msgstr "requête %s transmise, en attente de la réponse..."

#: src/http.c:1521
#, fuzzy
msgid "No data received.\n"
msgstr "Aucune donnée reçue"

#: src/http.c:1528
#, c-format
msgid "Read error (%s) in headers.\n"
msgstr "ERREUR de lecture (%s) de l'en-tête.\n"

#. If we have tried it already, then there is not point
#. retrying it.
#: src/http.c:1595
msgid "Authorization failed.\n"
msgstr "ÉCHEC d'autorisation.\n"

#: src/http.c:1609
msgid "Unknown authentication scheme.\n"
msgstr "Schème d'authentification inconnu.\n"

#: src/http.c:1634
msgid "Malformed status line"
msgstr "Ligne d'état mal composée"

#: src/http.c:1636
msgid "(no description)"
msgstr "(pas de description)"

#: src/http.c:1700
#, c-format
msgid "Location: %s%s\n"
msgstr "Emplacement: %s%s\n"

#: src/http.c:1701 src/http.c:1801
msgid "unspecified"
msgstr "non spécifié"

#: src/http.c:1702
msgid " [following]"
msgstr " [suivant]"

#. If `-c' is in use and the file has been fully downloaded (or
#. the remote file has shrunk), Wget effectively requests bytes
#. after the end of file and the server response with 416.
#: src/http.c:1751
msgid ""
"\n"
"    The file is already fully retrieved; nothing to do.\n"
