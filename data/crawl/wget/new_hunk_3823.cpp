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

#: src/http.c:621 src/http.c:1433
msgid "Unable to establish SSL connection.\n"
msgstr ""

#: src/http.c:629
#, fuzzy, c-format
msgid "Reusing connection to %s:%hu.\n"
msgstr "Tentative de connexion vers %s:%hu.\n"

#: src/http.c:805
#, fuzzy, c-format
msgid "Failed writing HTTP request: %s.\n"
msgstr "�chec d'�criture de la requ�te HTTP.\n"

#: src/http.c:810
#, c-format
msgid "%s request sent, awaiting response... "
msgstr "requ�te %s transmise, en attente de la r�ponse..."

#: src/http.c:854
msgid "End of file while parsing headers.\n"
msgstr "Fin de fichier lors de l'analyse du l'en-t�te.\n"

#: src/http.c:865
#, c-format
msgid "Read error (%s) in headers.\n"
msgstr "ERREUR de lecture (%s) de l'en-t�te.\n"

#: src/http.c:905
msgid "No data received"
msgstr "Aucune donn�e re�ue"

#: src/http.c:907
msgid "Malformed status line"
msgstr "Ligne d'�tat mal compos�e"

#: src/http.c:912
msgid "(no description)"
msgstr "(pas de description)"

#: src/http.c:1030
msgid "Authorization failed.\n"
msgstr "�chec d'autorisation.\n"

#: src/http.c:1037
msgid "Unknown authentication scheme.\n"
msgstr "Sch�me inconnu d'authentification.\n"

#: src/http.c:1127
#, c-format
msgid "Location: %s%s\n"
msgstr "Location: %s%s\n"

#: src/http.c:1128 src/http.c:1153
msgid "unspecified"
msgstr "non sp�cifi�"

#: src/http.c:1129
msgid " [following]"
msgstr " [suivant]"

#. No need to print this output if the body won't be
#. downloaded at all, or if the original server response is
#. printed.
#: src/http.c:1143
msgid "Length: "
msgstr "Longueur: "

#: src/http.c:1148
#, c-format
msgid " (%s to go)"
msgstr " (%s restant)"

#: src/http.c:1153
msgid "ignored"
msgstr "ignor�"

#: src/http.c:1254
msgid "Warning: wildcards not supported in HTTP.\n"
msgstr "AVERTISSEMENT: les m�tacaract�res ne sont pas support�s en HTTP.\n"

#. If opt.noclobber is turned on and file already exists, do not
#. retrieve the file
#: src/http.c:1275
#, c-format
msgid "File `%s' already there, will not retrieve.\n"
msgstr "Fichier `%s' est d�j� l�, pas de r�cup�ration.\n"

#: src/http.c:1425
#, c-format
msgid "Cannot write to `%s' (%s).\n"
msgstr "Ne peut �crire dans `%s' (%s).\n"

#: src/http.c:1443
#, c-format
msgid "ERROR: Redirection (%d) without location.\n"
msgstr "ERREUR: redirection (%d) sans destination.\n"

#: src/http.c:1468
#, c-format
msgid "%s ERROR %d: %s.\n"
msgstr "%s ERREUR %d: %s.\n"

#: src/http.c:1481
msgid "Last-modified header missing -- time-stamps turned off.\n"
msgstr ""
"En-t�te manquante de la derni�re modification -- tampon date-heure ignor�.\n"

#: src/http.c:1489
msgid "Last-modified header invalid -- time-stamp ignored.\n"
msgstr ""
"En-t�te erron�e de la derni�re modification -- tampon date-heure ignor�.\n"

#: src/http.c:1524
msgid "Remote file is newer, retrieving.\n"
msgstr "Fichier �loign� est plus r�cent, r�cup�ration.\n"

#: src/http.c:1559
#, c-format
msgid ""
"%s (%s) - `%s' saved [%ld/%ld]\n"
"\n"
msgstr ""
"%s (%s) - `%s' sauvegard� [%ld/%ld]\n"
"\n"

#: src/http.c:1607
#, c-format
msgid "%s (%s) - Connection closed at byte %ld. "
msgstr "%s (%s) - Fermeture de la connexion � l'octet %ld. "

#: src/http.c:1615
#, c-format
msgid ""
"%s (%s) - `%s' saved [%ld/%ld])\n"
"\n"
msgstr ""
"%s (%s) - `%s' sauvegard� [%ld/%ld]\n"
"\n"

#: src/http.c:1635
#, c-format
msgid "%s (%s) - Connection closed at byte %ld/%ld. "
msgstr "%s (%s) - Fermeture de la connexion � l'octet %ld/%ld. "

#: src/http.c:1646
#, c-format
msgid "%s (%s) - Read error at byte %ld (%s)."
msgstr "%s (%s) - ERREUR de lecture � l'octet %ld (%s)."

#: src/http.c:1654
#, c-format
msgid "%s (%s) - Read error at byte %ld/%ld (%s). "
msgstr "%s (%s) - ERREUR de lecture � l'octet %ld/%ld (%s)."

#: src/init.c:332 src/netrc.c:261
#, c-format
msgid "%s: Cannot read %s (%s).\n"
msgstr "%s: ne peut lire %s (%s).\n"

#: src/init.c:350 src/init.c:356
#, c-format
msgid "%s: Error in %s at line %d.\n"
msgstr "%s: ERREUR dans %s � la ligne %d.\n"

#: src/init.c:387
#, c-format
msgid "%s: Warning: Both system and user wgetrc point to `%s'.\n"
msgstr ""
"%s: AVERTISSEMENT wgetrc tant du syst�me que de l'usager pointe vers `%s'.\n"

#: src/init.c:479
#, c-format
msgid "%s: BUG: unknown command `%s', value `%s'.\n"
msgstr "%s: ERREUR: commande inconnue `%s', valeur `%s'.\n"

#: src/init.c:501
#, fuzzy, c-format
msgid "%s: Out of memory.\n"
msgstr "%s: %s: m�moire �puis�e.\n"

#: src/init.c:507
#, fuzzy, c-format
msgid "%s: %s: Cannot convert `%s' to an IP address.\n"
msgstr ""
"%s: AVERTISSEMENT: ne peut rep�rer l'adresse IP locale par requ�te inverse.\n"

#: src/init.c:535
#, c-format
msgid "%s: %s: Please specify on or off.\n"
msgstr "%s: %s: SVP sp�cifier `on' ou `off'.\n"

#: src/init.c:579
#, fuzzy, c-format
msgid "%s: %s: Please specify always, on, off, or never.\n"
msgstr "%s: %s: SVP sp�cifier `on' ou `off'.\n"

#: src/init.c:598 src/init.c:855 src/init.c:877 src/init.c:941
#, c-format
msgid "%s: %s: Invalid specification `%s'.\n"
msgstr "%s: %s: sp�cification erronn�e `%s'.\n"

#: src/init.c:711 src/init.c:733 src/init.c:755 src/init.c:781
#, c-format
msgid "%s: Invalid specification `%s'\n"
msgstr "%s: sp�cification erronn�e `%s'\n"

#: src/main.c:119
#, c-format
msgid "Usage: %s [OPTION]... [URL]...\n"
msgstr "Usage: %s [OPTION]... [URL]...\n"

#: src/main.c:127
#, c-format
msgid "GNU Wget %s, a non-interactive network retriever.\n"
msgstr "GNU Wget %s, un r�cup�rateur r�seau non int�ractif.\n"

#. Had to split this in parts, so the #@@#%# Ultrix compiler and cpp
#. don't bitch.  Also, it makes translation much easier.
#: src/main.c:132
msgid ""
"\n"
"Mandatory arguments to long options are mandatory for short options too.\n"
"\n"
msgstr ""
"\n"
"Les param�tres obligatoires pour les options de formes longues le sont\n"
"aussi pour les options de formes courtes.\n"
"\n"

#: src/main.c:135
#, fuzzy
msgid ""
"Startup:\n"
"  -V,  --version           display the version of Wget and exit.\n"
"  -h,  --help              print this help.\n"
"  -b,  --background        go to background after startup.\n"
"  -e,  --execute=COMMAND   execute a `.wgetrc'-style command.\n"
"\n"
msgstr ""
"D�marrage:\n"
"  -V,  --version               afficher le nom et la version du logiciel\n"
"  -h,  --help                  afficher l'aide-m�moire\n"
"  -b,  --background            travailler � l'arri�re plan apr�s le "
"d�marrage.\n"
"  -e,  --execute=COMMAND       ex�cuter une commande `.wgetrc'.\n"
"\n"

#: src/main.c:141
#, fuzzy
msgid ""
"Logging and input file:\n"
"  -o,  --output-file=FILE     log messages to FILE.\n"
