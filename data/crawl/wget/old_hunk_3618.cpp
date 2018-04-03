msgid "%s: option requires an argument -- %c\n"
msgstr "%s: l'option requiert le param�tre -- %c\n"

#: src/host.c:394
#, c-format
msgid "%s: Cannot determine user-id.\n"
msgstr "%s: ne peut d�terminer le UID de l'usager.\n"

#: src/host.c:406
#, c-format
msgid "%s: Warning: uname failed: %s\n"
msgstr "%s: AVERTISSEMENT: �chec de `uname': %s\n"

#: src/host.c:418
#, c-format
msgid "%s: Warning: gethostname failed\n"
msgstr "%s: AVERTISSEMENT: �chec de la fonction gethostname()\n"

#: src/host.c:446
#, c-format
msgid "%s: Warning: cannot determine local IP address.\n"
msgstr "%s: AVERTISSEMENT: ne peut d�terminer l'adresse IP locale.\n"

#: src/host.c:460
#, c-format
msgid "%s: Warning: cannot reverse-lookup local IP address.\n"
msgstr ""
"%s: AVERTISSEMENT: ne peut rep�rer l'adresse IP locale par requ�te inverse.\n"

#. This gets ticked pretty often.  Karl Berry reports
#. that there can be valid reasons for the local host
#. name not to be an FQDN, so I've decided to remove the
#. annoying warning.
#: src/host.c:473
#, c-format
msgid "%s: Warning: reverse-lookup of local address did not yield FQDN!\n"
msgstr ""
"%s: AVERTISSEMENT: requ�te inverse de l'adresse IP locale n'est pas "
"compl�t�e par FQDN!\n"

#: src/host.c:501
msgid "Host not found"
msgstr "H�te non rep�r�"

#: src/host.c:503
msgid "Unknown error"
msgstr "ERREUR inconnue"

#. this is fatal
#: src/http.c:549
msgid "Failed to set up an SSL context\n"
msgstr ""

#: src/http.c:555
#, c-format
msgid "Failed to load certificates from %s\n"
msgstr ""

#: src/http.c:559 src/http.c:567
msgid "Trying without the specified certificate\n"
msgstr ""

#: src/http.c:563
#, c-format
msgid "Failed to get certificate key from %s\n"
msgstr ""

#: src/http.c:657 src/http.c:1470
msgid "Unable to establish SSL connection.\n"
msgstr ""

#: src/http.c:665
#, fuzzy, c-format
msgid "Reusing connection to %s:%hu.\n"
msgstr "Tentative de connexion vers %s:%hu.\n"

#: src/http.c:841
#, fuzzy, c-format
msgid "Failed writing HTTP request: %s.\n"
msgstr "�chec d'�criture de la requ�te HTTP.\n"

#: src/http.c:846
#, c-format
msgid "%s request sent, awaiting response... "
msgstr "requ�te %s transmise, en attente de la r�ponse..."

#: src/http.c:890
msgid "End of file while parsing headers.\n"
msgstr "Fin de fichier lors de l'analyse du l'en-t�te.\n"

#: src/http.c:901
#, c-format
msgid "Read error (%s) in headers.\n"
msgstr "ERREUR de lecture (%s) de l'en-t�te.\n"

#: src/http.c:941
msgid "No data received"
msgstr "Aucune donn�e re�ue"

#: src/http.c:943
msgid "Malformed status line"
msgstr "Ligne d'�tat mal compos�e"

#: src/http.c:948
msgid "(no description)"
msgstr "(pas de description)"

#: src/http.c:1066
msgid "Authorization failed.\n"
msgstr "�chec d'autorisation.\n"

#: src/http.c:1073
msgid "Unknown authentication scheme.\n"
msgstr "Sch�me inconnu d'authentification.\n"

#: src/http.c:1163
#, c-format
msgid "Location: %s%s\n"
msgstr "Location: %s%s\n"

#: src/http.c:1164 src/http.c:1189
msgid "unspecified"
msgstr "non sp�cifi�"

#: src/http.c:1165
msgid " [following]"
msgstr " [suivant]"

#. No need to print this output if the body won't be
#. downloaded at all, or if the original server response is
#. printed.
#: src/http.c:1179
msgid "Length: "
msgstr "Longueur: "

#: src/http.c:1184
#, c-format
msgid " (%s to go)"
msgstr " (%s restant)"

#: src/http.c:1189
msgid "ignored"
msgstr "ignor�"

#: src/http.c:1290
msgid "Warning: wildcards not supported in HTTP.\n"
msgstr "AVERTISSEMENT: les m�tacaract�res ne sont pas support�s en HTTP.\n"

#. If opt.noclobber is turned on and file already exists, do not
#. retrieve the file
#: src/http.c:1311
#, c-format
msgid "File `%s' already there, will not retrieve.\n"
msgstr "Fichier `%s' est d�j� l�, pas de r�cup�ration.\n"

#: src/http.c:1462
#, c-format
msgid "Cannot write to `%s' (%s).\n"
msgstr "Ne peut �crire dans `%s' (%s).\n"

#: src/http.c:1480
#, c-format
msgid "ERROR: Redirection (%d) without location.\n"
msgstr "ERREUR: redirection (%d) sans destination.\n"

#: src/http.c:1505
#, c-format
msgid "%s ERROR %d: %s.\n"
msgstr "%s ERREUR %d: %s.\n"

#: src/http.c:1518
msgid "Last-modified header missing -- time-stamps turned off.\n"
msgstr ""
"En-t�te manquante de la derni�re modification -- tampon date-heure ignor�.\n"

#: src/http.c:1526
msgid "Last-modified header invalid -- time-stamp ignored.\n"
msgstr ""
"En-t�te erron�e de la derni�re modification -- tampon date-heure ignor�.\n"

#: src/http.c:1549
#, c-format
msgid ""
"Server file no newer than local file `%s' -- not retrieving.\n"
"\n"
msgstr ""

#: src/http.c:1557
#, fuzzy, c-format
msgid "The sizes do not match (local %ld) -- retrieving.\n"
msgstr "La taille des fichiers ne concorde pas (local %ld), r�cup�ration.\n"

#: src/http.c:1561
msgid "Remote file is newer, retrieving.\n"
msgstr "Fichier �loign� est plus r�cent, r�cup�ration.\n"

#: src/http.c:1606
#, c-format
msgid ""
"%s (%s) - `%s' saved [%ld/%ld]\n"
"\n"
msgstr ""
"%s (%s) - `%s' sauvegard� [%ld/%ld]\n"
"\n"

#: src/http.c:1654
#, c-format
msgid "%s (%s) - Connection closed at byte %ld. "
msgstr "%s (%s) - Fermeture de la connexion � l'octet %ld. "

#: src/http.c:1662
#, c-format
msgid ""
"%s (%s) - `%s' saved [%ld/%ld])\n"
"\n"
msgstr ""
"%s (%s) - `%s' sauvegard� [%ld/%ld]\n"
"\n"

#: src/http.c:1682
#, c-format
msgid "%s (%s) - Connection closed at byte %ld/%ld. "
msgstr "%s (%s) - Fermeture de la connexion � l'octet %ld/%ld. "

#: src/http.c:1693
#, c-format
msgid "%s (%s) - Read error at byte %ld (%s)."
msgstr "%s (%s) - ERREUR de lecture � l'octet %ld (%s)."

#: src/http.c:1701
#, c-format
msgid "%s (%s) - Read error at byte %ld/%ld (%s). "
msgstr "%s (%s) - ERREUR de lecture � l'octet %ld/%ld (%s)."

#: src/init.c:336 src/netrc.c:261
#, c-format
msgid "%s: Cannot read %s (%s).\n"
msgstr "%s: ne peut lire %s (%s).\n"

#: src/init.c:354 src/init.c:360
#, c-format
msgid "%s: Error in %s at line %d.\n"
msgstr "%s: ERREUR dans %s � la ligne %d.\n"

#: src/init.c:391
#, c-format
msgid "%s: Warning: Both system and user wgetrc point to `%s'.\n"
msgstr ""
"%s: AVERTISSEMENT wgetrc tant du syst�me que de l'usager pointe vers `%s'.\n"

#: src/init.c:483
#, c-format
msgid "%s: BUG: unknown command `%s', value `%s'.\n"
msgstr "%s: ERREUR: commande inconnue `%s', valeur `%s'.\n"

#: src/init.c:504
#, fuzzy, c-format
msgid "%s: %s: Cannot convert `%s' to an IP address.\n"
msgstr ""
"%s: AVERTISSEMENT: ne peut rep�rer l'adresse IP locale par requ�te inverse.\n"

#: src/init.c:532
#, c-format
msgid "%s: %s: Please specify on or off.\n"
msgstr "%s: %s: SVP sp�cifier `on' ou `off'.\n"

#: src/init.c:576
#, fuzzy, c-format
msgid "%s: %s: Please specify always, on, off, or never.\n"
msgstr "%s: %s: SVP sp�cifier `on' ou `off'.\n"

#: src/init.c:595 src/init.c:852 src/init.c:874 src/init.c:938
#, c-format
msgid "%s: %s: Invalid specification `%s'.\n"
msgstr "%s: %s: sp�cification erronn�e `%s'.\n"

#: src/init.c:708 src/init.c:730 src/init.c:752 src/init.c:778
#, c-format
msgid "%s: Invalid specification `%s'\n"
msgstr "%s: sp�cification erronn�e `%s'\n"
