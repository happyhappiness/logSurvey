msgid "%s: option requires an argument -- %c\n"
msgstr "%s: l'option requiert le param�tre -- %c\n"

#: src/host.c:432
#, c-format
msgid "%s: Cannot determine user-id.\n"
msgstr "%s: ne peut d�terminer le UID de l'usager.\n"

#: src/host.c:444
#, c-format
msgid "%s: Warning: uname failed: %s\n"
msgstr "%s: AVERTISSEMENT: �chec de `uname': %s\n"

#: src/host.c:456
#, c-format
msgid "%s: Warning: gethostname failed\n"
msgstr "%s: AVERTISSEMENT: �chec de la fonction gethostname()\n"

#: src/host.c:484
#, c-format
msgid "%s: Warning: cannot determine local IP address.\n"
msgstr "%s: AVERTISSEMENT: ne peut d�terminer l'adresse IP locale.\n"

#: src/host.c:498
#, c-format
msgid "%s: Warning: cannot reverse-lookup local IP address.\n"
msgstr "%s: AVERTISSEMENT: ne peut rep�rer l'adresse IP locale par requ�te inverse.\n"

#. This gets ticked pretty often.  Karl Berry reports
#. that there can be valid reasons for the local host
#. name not to be an FQDN, so I've decided to remove the
#. annoying warning.
#: src/host.c:511
#, c-format
msgid "%s: Warning: reverse-lookup of local address did not yield FQDN!\n"
msgstr "%s: AVERTISSEMENT: requ�te inverse de l'adresse IP locale n'est pas compl�t�e par FQDN!\n"

#: src/host.c:539
msgid "Host not found"
msgstr "H�te non rep�r�"

#: src/host.c:541
msgid "Unknown error"
msgstr "ERREUR inconnue"

#: src/html.c:439 src/html.c:441
#, c-format
msgid "Index of /%s on %s:%d"
msgstr "Index de /%s sur %s:%d"

#: src/html.c:463
msgid "time unknown       "
msgstr "heure inconnue     "

#: src/html.c:467
msgid "File        "
msgstr "Fichier     "

#: src/html.c:470
msgid "Directory   "
msgstr "R�pertoire  "

#: src/html.c:473
msgid "Link        "
msgstr "Lien        "

#: src/html.c:476
msgid "Not sure    "
msgstr "Incertain   "

#: src/html.c:494
#, c-format
msgid " (%s bytes)"
msgstr " (%s octets)"

#: src/http.c:492
msgid "Failed writing HTTP request.\n"
msgstr "�chec d'�criture de la requ�te HTTP.\n"

#: src/http.c:497
#, c-format
msgid "%s request sent, awaiting response... "
msgstr "requ�te %s transmise, en attente de la r�ponse..."

#: src/http.c:536
msgid "End of file while parsing headers.\n"
msgstr "Fin de fichier lors de l'analyse du l'en-t�te.\n"

#: src/http.c:547
#, c-format
msgid "Read error (%s) in headers.\n"
msgstr "ERREUR de lecture (%s) de l'en-t�te.\n"

#: src/http.c:587
msgid "No data received"
msgstr "Aucune donn�e re�ue"

#: src/http.c:589
msgid "Malformed status line"
msgstr "Ligne d'�tat mal compos�e"

#: src/http.c:594
msgid "(no description)"
msgstr "(pas de description)"

#. If we have tried it already, then there is not point
#. retrying it.
#: src/http.c:678
msgid "Authorization failed.\n"
msgstr "�chec d'autorisation.\n"

#: src/http.c:685
msgid "Unknown authentication scheme.\n"
msgstr "Sch�me inconnu d'authentification.\n"

#: src/http.c:748
#, c-format
msgid "Location: %s%s\n"
msgstr "Location: %s%s\n"

#: src/http.c:749 src/http.c:774
msgid "unspecified"
msgstr "non sp�cifi�"

#: src/http.c:750
msgid " [following]"
msgstr " [suivant]"

#. No need to print this output if the body won't be
#. downloaded at all, or if the original server response is
#. printed.
#: src/http.c:764
msgid "Length: "
msgstr "Longueur: "

#: src/http.c:769
#, c-format
msgid " (%s to go)"
msgstr " (%s restant)"

#: src/http.c:774
msgid "ignored"
msgstr "ignor�"

#: src/http.c:857
msgid "Warning: wildcards not supported in HTTP.\n"
msgstr "AVERTISSEMENT: les m�tacaract�res ne sont pas support�s en HTTP.\n"

#. If opt.noclobber is turned on and file already exists, do not
#. retrieve the file
#: src/http.c:872
#, c-format
msgid "File `%s' already there, will not retrieve.\n"
msgstr "Fichier `%s' est d�j� l�, pas de r�cup�ration.\n"

#: src/http.c:978
#, c-format
msgid "Cannot write to `%s' (%s).\n"
msgstr "Ne peut �crire dans `%s' (%s).\n"

#: src/http.c:988
#, c-format
msgid "ERROR: Redirection (%d) without location.\n"
msgstr "ERREUR: redirection (%d) sans destination.\n"

#: src/http.c:1011
#, c-format
msgid "%s ERROR %d: %s.\n"
msgstr "%s ERREUR %d: %s.\n"

#: src/http.c:1023
msgid "Last-modified header missing -- time-stamps turned off.\n"
msgstr "En-t�te manquante de la derni�re modification -- tampon date-heure ignor�.\n"

#: src/http.c:1031
msgid "Last-modified header invalid -- time-stamp ignored.\n"
msgstr "En-t�te erron�e de la derni�re modification -- tampon date-heure ignor�.\n"

#: src/http.c:1064
msgid "Remote file is newer, retrieving.\n"
msgstr "Fichier �loign� est plus r�cent, r�cup�ration.\n"

#: src/http.c:1098
#, c-format
msgid "%s (%s) - `%s' saved [%ld/%ld]\n\n"
msgstr "%s (%s) - `%s' sauvegard� [%ld/%ld]\n\n"

#: src/http.c:1130
#, c-format
msgid "%s (%s) - Connection closed at byte %ld. "
msgstr "%s (%s) - Fermeture de la connexion � l'octet %ld. "

#: src/http.c:1138
#, c-format
msgid "%s (%s) - `%s' saved [%ld/%ld])\n\n"
msgstr "%s (%s) - `%s' sauvegard� [%ld/%ld]\n\n"

#: src/http.c:1150
#, c-format
msgid "%s (%s) - Connection closed at byte %ld/%ld. "
msgstr "%s (%s) - Fermeture de la connexion � l'octet %ld/%ld. "

#: src/http.c:1161
#, c-format
msgid "%s (%s) - Read error at byte %ld (%s)."
msgstr "%s (%s) - ERREUR de lecture � l'octet %ld (%s)."

#: src/http.c:1169
#, c-format
msgid "%s (%s) - Read error at byte %ld/%ld (%s). "
msgstr "%s (%s) - ERREUR de lecture � l'octet %ld/%ld (%s)."

#: src/init.c:312 src/netrc.c:250
#, c-format
msgid "%s: Cannot read %s (%s).\n"
msgstr "%s: ne peut lire %s (%s).\n"

#: src/init.c:333 src/init.c:339
#, c-format
msgid "%s: Error in %s at line %d.\n"
msgstr "%s: ERREUR dans %s � la ligne %d.\n"

#: src/init.c:370
#, c-format
msgid "%s: Warning: Both system and user wgetrc point to `%s'.\n"
msgstr "%s: AVERTISSEMENT wgetrc tant du syst�me que de l'usager pointe vers `%s'.\n"

#: src/init.c:458
#, c-format
msgid "%s: BUG: unknown command `%s', value `%s'.\n"
msgstr "%s: ERREUR: commande inconnue `%s', valeur `%s'.\n"

#: src/init.c:485
#, c-format
msgid "%s: %s: Please specify on or off.\n"
msgstr "%s: %s: SVP sp�cifier `on' ou `off'.\n"

#: src/init.c:503 src/init.c:760 src/init.c:782 src/init.c:855
#, c-format
msgid "%s: %s: Invalid specification `%s'.\n"
msgstr "%s: %s: sp�cification erronn�e `%s'.\n"

#: src/init.c:616 src/init.c:638 src/init.c:660 src/init.c:686
#, c-format
msgid "%s: Invalid specification `%s'\n"
msgstr "%s: sp�cification erronn�e `%s'\n"

#: src/main.c:101
#, c-format
msgid "Usage: %s [OPTION]... [URL]...\n"
msgstr "Usage: %s [OPTION]... [URL]...\n"

#: src/main.c:109
#, c-format
msgid "GNU Wget %s, a non-interactive network retriever.\n"
msgstr "GNU Wget %s, un r�cup�rateur r�seau non int�ractif.\n"

#. Had to split this in parts, so the #@@#%# Ultrix compiler and cpp
#. don't bitch.  Also, it makes translation much easier.
#: src/main.c:114
msgid "\nMandatory arguments to long options are mandatory for short options too.\n\n"
msgstr ""
"\n"
"Les param�tres obligatoires pour les options de formes longues le sont\n"
"aussi pour les options de formes courtes.\n"
"\n"

#: src/main.c:117
msgid ""
"Startup:\n"
"  -V,  --version           display the version of Wget and exit.\n"
"  -h,  --help              print this help.\n"
"  -b,  --background        go to background after startup.\n"
"  -e,  --execute=COMMAND   execute a `.wgetrc' command.\n"
"\n"
msgstr ""
"D�marrage:\n"
"  -V,  --version               afficher le nom et la version du logiciel\n"
"  -h,  --help                  afficher l'aide-m�moire\n"
"  -b,  --background            travailler � l'arri�re plan apr�s le d�marrage.\n"
"  -e,  --execute=COMMAND       ex�cuter une commande `.wgetrc'.\n"
"\n"

#: src/main.c:123
msgid ""
"Logging and input file:\n"
"  -o,  --output-file=FILE     log messages to FILE.\n"
