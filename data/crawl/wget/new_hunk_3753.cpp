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
msgstr "�chec d'�criture de la requ�te HTTP.\n"

#: src/http.c:814
#, c-format
msgid "%s request sent, awaiting response... "
msgstr "requ�te %s transmise, en attente de la r�ponse..."

#: src/http.c:858
msgid "End of file while parsing headers.\n"
msgstr "Fin de fichier lors de l'analyse du l'en-t�te.\n"

#: src/http.c:869
#, c-format
msgid "Read error (%s) in headers.\n"
msgstr "ERREUR de lecture (%s) de l'en-t�te.\n"

#: src/http.c:909
msgid "No data received"
msgstr "Aucune donn�e re�ue"

#: src/http.c:911
msgid "Malformed status line"
msgstr "Ligne d'�tat mal compos�e"

#: src/http.c:916
msgid "(no description)"
msgstr "(pas de description)"

#: src/http.c:1034
msgid "Authorization failed.\n"
msgstr "�chec d'autorisation.\n"

#: src/http.c:1041
msgid "Unknown authentication scheme.\n"
msgstr "Sch�me inconnu d'authentification.\n"

#: src/http.c:1131
#, c-format
msgid "Location: %s%s\n"
msgstr "Location: %s%s\n"

#: src/http.c:1132 src/http.c:1157
msgid "unspecified"
msgstr "non sp�cifi�"

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
msgstr "ignor�"

#: src/http.c:1258
msgid "Warning: wildcards not supported in HTTP.\n"
msgstr "AVERTISSEMENT: les m�tacaract�res ne sont pas support�s en HTTP.\n"

#. If opt.noclobber is turned on and file already exists, do not
#. retrieve the file
#: src/http.c:1279
#, c-format
msgid "File `%s' already there, will not retrieve.\n"
msgstr "Fichier `%s' est d�j� l�, pas de r�cup�ration.\n"

#: src/http.c:1429
#, c-format
msgid "Cannot write to `%s' (%s).\n"
msgstr "Ne peut �crire dans `%s' (%s).\n"

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
"En-t�te manquante de la derni�re modification -- tampon date-heure ignor�.\n"

#: src/http.c:1493
msgid "Last-modified header invalid -- time-stamp ignored.\n"
msgstr ""
"En-t�te erron�e de la derni�re modification -- tampon date-heure ignor�.\n"

#: src/http.c:1528
msgid "Remote file is newer, retrieving.\n"
msgstr "Fichier �loign� est plus r�cent, r�cup�ration.\n"

#: src/http.c:1573
#, c-format
msgid ""
"%s (%s) - `%s' saved [%ld/%ld]\n"
