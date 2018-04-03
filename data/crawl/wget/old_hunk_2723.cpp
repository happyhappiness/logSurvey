msgid "No headers, assuming HTTP/0.9"
msgstr "Pas d'en-tête, HTTP/0.9 assumé"

#: src/http.c:1198
msgid "Disabling SSL due to encountered errors.\n"
msgstr "Désactivation SSL en raison des erreurs rencontrés.\n"

#: src/http.c:1417
#, c-format
msgid "Reusing existing connection to %s:%d.\n"
msgstr "Réutilisation de la connexion existante vers %s:%d.\n"

#: src/http.c:1479
#, c-format
msgid "Failed writing to proxy: %s.\n"
msgstr "ÉCHEC d'écriture vers le proxy: %s.\n"

#: src/http.c:1488
#, c-format
msgid "Failed reading proxy response: %s\n"
msgstr "ÉCHEC de lecture de la réponse proxy: %s.\n"

#: src/http.c:1508
#, c-format
msgid "Proxy tunneling failed: %s"
msgstr "Échec du tunneling proxy: %s"

#: src/http.c:1555
#, c-format
msgid "%s request sent, awaiting response... "
msgstr "requête %s transmise, en attente de la réponse..."

#: src/http.c:1566
msgid "No data received.\n"
msgstr "Aucune donnée reçue.\n"

#: src/http.c:1573
#, c-format
msgid "Read error (%s) in headers.\n"
msgstr "ERREUR de lecture (%s) de l'en-tête.\n"

#. If the authentication header is missing or
#. unrecognized, there's no sense in retrying.
#: src/http.c:1658
msgid "Unknown authentication scheme.\n"
msgstr "Schème d'authentification inconnu.\n"

#: src/http.c:1682
msgid "Authorization failed.\n"
msgstr "ÉCHEC d'autorisation.\n"

#: src/http.c:1696
msgid "Malformed status line"
msgstr "Ligne d'état mal composée"

#: src/http.c:1698
msgid "(no description)"
msgstr "(pas de description)"

#: src/http.c:1769
#, c-format
msgid "Location: %s%s\n"
msgstr "Emplacement: %s%s\n"

#: src/http.c:1770 src/http.c:1867
msgid "unspecified"
msgstr "non spécifié"

#: src/http.c:1771
msgid " [following]"
msgstr " [suivant]"

#. If `-c' is in use and the file has been fully downloaded (or
#. the remote file has shrunk), Wget effectively requests bytes
#. after the end of file and the server response with 416.
#: src/http.c:1817
msgid ""
"\n"
"    The file is already fully retrieved; nothing to do.\n"
