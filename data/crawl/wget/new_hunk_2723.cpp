msgid "No headers, assuming HTTP/0.9"
msgstr "Pas d'en-t�te, HTTP/0.9 assum�"

#: src/http.c:1204
msgid "Disabling SSL due to encountered errors.\n"
msgstr "D�sactivation SSL en raison des erreurs rencontr�s.\n"

#: src/http.c:1374
#, c-format
msgid "POST data file `%s' missing: %s\n"
msgstr "Fichier de donn�es POST `%s' est manquant: %s\n"

#: src/http.c:1423
#, c-format
msgid "Reusing existing connection to %s:%d.\n"
msgstr "R�utilisation de la connexion existante vers %s:%d.\n"

#: src/http.c:1492
#, c-format
msgid "Failed reading proxy response: %s\n"
msgstr "�CHEC de lecture de la r�ponse proxy: %s.\n"

#: src/http.c:1512
#, c-format
msgid "Proxy tunneling failed: %s"
msgstr "�chec du tunneling proxy: %s"

#: src/http.c:1557
#, c-format
msgid "%s request sent, awaiting response... "
msgstr "requ�te %s transmise, en attente de la r�ponse..."

#: src/http.c:1568
msgid "No data received.\n"
msgstr "Aucune donn�e re�ue.\n"

#: src/http.c:1575
#, c-format
msgid "Read error (%s) in headers.\n"
msgstr "ERREUR de lecture (%s) de l'en-t�te.\n"

#. If the authentication header is missing or
#. unrecognized, there's no sense in retrying.
#: src/http.c:1660
msgid "Unknown authentication scheme.\n"
msgstr "Sch�me d'authentification inconnu.\n"

#: src/http.c:1684
msgid "Authorization failed.\n"
msgstr "�CHEC d'autorisation.\n"

#: src/http.c:1698
msgid "Malformed status line"
msgstr "Ligne d'�tat mal compos�e"

#: src/http.c:1700
msgid "(no description)"
msgstr "(pas de description)"

#: src/http.c:1763
#, c-format
msgid "Location: %s%s\n"
msgstr "Emplacement: %s%s\n"

#: src/http.c:1764 src/http.c:1871
msgid "unspecified"
msgstr "non sp�cifi�"

#: src/http.c:1765
msgid " [following]"
msgstr " [suivant]"

#. If `-c' is in use and the file has been fully downloaded (or
#. the remote file has shrunk), Wget effectively requests bytes
#. after the end of file and the server response with 416.
#: src/http.c:1821
msgid ""
"\n"
"    The file is already fully retrieved; nothing to do.\n"
