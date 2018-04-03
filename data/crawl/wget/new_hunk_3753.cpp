msgid "Unknown error"
msgstr "ERREUR inconnue"

#: src/http.c:625 src/http.c:1437
msgid "Unable to establish SSL connection.\n"
msgstr ""

#: src/http.c:633
#, fuzzy, c-format
msgid "Reusing connection to %s:%hu.\n"
msgstr "Tentative de connexion vers %s:%hu.\n"

#: src/http.c:809
#, fuzzy, c-format
msgid "Failed writing HTTP request: %s.\n"
msgstr "Échec d'écriture de la requête HTTP.\n"

#: src/http.c:814
#, c-format
msgid "%s request sent, awaiting response... "
msgstr "requête %s transmise, en attente de la réponse..."

#: src/http.c:858
msgid "End of file while parsing headers.\n"
msgstr "Fin de fichier lors de l'analyse du l'en-tête.\n"

#: src/http.c:869
#, c-format
msgid "Read error (%s) in headers.\n"
msgstr "ERREUR de lecture (%s) de l'en-tête.\n"

#: src/http.c:909
msgid "No data received"
msgstr "Aucune donnée reçue"

#: src/http.c:911
msgid "Malformed status line"
msgstr "Ligne d'état mal composée"

#: src/http.c:916
msgid "(no description)"
msgstr "(pas de description)"

#: src/http.c:1034
msgid "Authorization failed.\n"
msgstr "Échec d'autorisation.\n"

#: src/http.c:1041
msgid "Unknown authentication scheme.\n"
msgstr "Schème inconnu d'authentification.\n"

#: src/http.c:1131
#, c-format
msgid "Location: %s%s\n"
msgstr "Location: %s%s\n"

#: src/http.c:1132 src/http.c:1157
msgid "unspecified"
msgstr "non spécifié"

#: src/http.c:1133
msgid " [following]"
msgstr " [suivant]"

#. No need to print this output if the body won't be
#. downloaded at all, or if the original server response is
#. printed.
#: src/http.c:1147
msgid "Length: "
msgstr "Longueur: "

#: src/http.c:1152
#, c-format
msgid " (%s to go)"
msgstr " (%s restant)"

#: src/http.c:1157
msgid "ignored"
msgstr "ignoré"

#: src/http.c:1258
msgid "Warning: wildcards not supported in HTTP.\n"
msgstr "AVERTISSEMENT: les métacaractères ne sont pas supportés en HTTP.\n"

#. If opt.noclobber is turned on and file already exists, do not
#. retrieve the file
#: src/http.c:1279
#, c-format
msgid "File `%s' already there, will not retrieve.\n"
msgstr "Fichier `%s' est déjà là, pas de récupération.\n"

#: src/http.c:1429
#, c-format
msgid "Cannot write to `%s' (%s).\n"
msgstr "Ne peut écrire dans `%s' (%s).\n"

#: src/http.c:1447
#, c-format
msgid "ERROR: Redirection (%d) without location.\n"
msgstr "ERREUR: redirection (%d) sans destination.\n"

#: src/http.c:1472
#, c-format
msgid "%s ERROR %d: %s.\n"
msgstr "%s ERREUR %d: %s.\n"

#: src/http.c:1485
msgid "Last-modified header missing -- time-stamps turned off.\n"
msgstr ""
"En-tête manquante de la dernière modification -- tampon date-heure ignoré.\n"

#: src/http.c:1493
msgid "Last-modified header invalid -- time-stamp ignored.\n"
msgstr ""
"En-tête erronée de la dernière modification -- tampon date-heure ignoré.\n"

#: src/http.c:1528
msgid "Remote file is newer, retrieving.\n"
msgstr "Fichier éloigné est plus récent, récupération.\n"

#: src/http.c:1573
#, c-format
msgid ""
"%s (%s) - `%s' saved [%ld/%ld]\n"
