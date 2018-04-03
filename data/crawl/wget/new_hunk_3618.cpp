msgid "%s: option requires an argument -- %c\n"
msgstr "%s: l'option requiert le paramètre -- %c\n"

#: src/host.c:374
msgid "Host not found"
msgstr "Hôte non repéré"

#: src/host.c:376
msgid "Unknown error"
msgstr "ERREUR inconnue"

#. this is fatal
#: src/http.c:555
msgid "Failed to set up an SSL context\n"
msgstr "ÉCHEC d'initialisation du contexte SSL\n"

#: src/http.c:561
#, c-format
msgid "Failed to load certificates from %s\n"
msgstr "ÉCHEC de chargement des certificats de %s\n"

#: src/http.c:565 src/http.c:573
msgid "Trying without the specified certificate\n"
msgstr "Essai sans le certificat spécifié\n"

#: src/http.c:569
#, c-format
msgid "Failed to get certificate key from %s\n"
msgstr "ÉCHEC d'obtention de la clé du certificat de %s\n"

#: src/http.c:663 src/http.c:1593
msgid "Unable to establish SSL connection.\n"
msgstr "Incapable d'établir une connexion SSL.\n"

#: src/http.c:671
msgid "Reusing connection to %s:%hu.\n"
msgstr "Réutilisation de la connexion vers %s:%hu.\n"

#: src/http.c:861
msgid "Failed writing HTTP request: %s.\n"
msgstr "ÉCHEC d'écriture de la requête HTTP: %s.\n"

#: src/http.c:866
#, c-format
msgid "%s request sent, awaiting response... "
msgstr "requête %s transmise, en attente de la réponse..."

#: src/http.c:910
msgid "End of file while parsing headers.\n"
msgstr "Fin de fichier lors de l'analyse du l'en-tête.\n"

#: src/http.c:920
#, c-format
msgid "Read error (%s) in headers.\n"
msgstr "ERREUR de lecture (%s) de l'en-tête.\n"

#: src/http.c:959
msgid "No data received"
msgstr "Aucune donnée reçue"

#: src/http.c:961
msgid "Malformed status line"
msgstr "Ligne d'état mal composée"

#: src/http.c:966
msgid "(no description)"
msgstr "(pas de description)"

#: src/http.c:1089
msgid "Authorization failed.\n"
msgstr "ÉCHEC d'autorisation.\n"

#: src/http.c:1096
msgid "Unknown authentication scheme.\n"
msgstr "Schème inconnu d'authentification.\n"

#: src/http.c:1136
#, c-format
msgid "Location: %s%s\n"
msgstr "Location: %s%s\n"

#: src/http.c:1137 src/http.c:1269
msgid "unspecified"
msgstr "non spécifié"

#: src/http.c:1138
msgid " [following]"
msgstr " [suivant]"

#: src/http.c:1200
msgid "\n    The file is already fully retrieved; nothing to do.\n\n"
msgstr "\n    Le fichier a déjà été complètement récupéré; rien à faire.\n\n"

#: src/http.c:1216
#, c-format
msgid ""
"\n"
"Continued download failed on this file, which conflicts with `-c'.\n"
"Refusing to truncate existing file `%s'.\n"
"\n"
msgstr ""
"\n"
"Échec de la poursuite du téléchargement du fichier, en conflit avec `-c'.\n"
"Refus de tronquer le fichier existant `%s'.\n"
"\n"

#. No need to print this output if the body won't be
#. downloaded at all, or if the original server response is
#. printed.
#: src/http.c:1259
msgid "Length: "
msgstr "Longueur: "

#: src/http.c:1264
#, c-format
msgid " (%s to go)"
msgstr " (%s restant)"

#: src/http.c:1269
msgid "ignored"
msgstr "ignoré"

#: src/http.c:1399
msgid "Warning: wildcards not supported in HTTP.\n"
msgstr "AVERTISSEMENT: les métacaractères ne sont pas supportés en HTTP.\n"

#. If opt.noclobber is turned on and file already exists, do not
#. retrieve the file
#: src/http.c:1417
#, c-format
msgid "File `%s' already there, will not retrieve.\n"
msgstr "Fichier `%s' est déjà là, pas de récupération.\n"

#: src/http.c:1585
#, c-format
msgid "Cannot write to `%s' (%s).\n"
msgstr "Ne peut écrire dans `%s' (%s).\n"

#: src/http.c:1602
#, c-format
msgid "ERROR: Redirection (%d) without location.\n"
msgstr "ERREUR: redirection (%d) sans destination.\n"

#: src/http.c:1630
#, c-format
msgid "%s ERROR %d: %s.\n"
msgstr "%s ERREUR %d: %s.\n"

#: src/http.c:1642
msgid "Last-modified header missing -- time-stamps turned off.\n"
msgstr "En-tête manquante de la dernière modification -- tampon date-heure ignoré.\n"

#: src/http.c:1650
msgid "Last-modified header invalid -- time-stamp ignored.\n"
msgstr "En-tête erronée de la dernière modification -- tampon date-heure ignoré.\n"

#: src/http.c:1673
#, c-format
msgid "Server file no newer than local file `%s' -- not retrieving.\n\n"
msgstr "Le fichier du serveur n'est pas plus récent que le fichier local `%s' -- pas de récupération.\n\n"

#: src/http.c:1680
#, c-format
msgid "The sizes do not match (local %ld) -- retrieving.\n"
msgstr "La taille ne concorde pas (local %ld) -- récupération.\n"

#: src/http.c:1684
msgid "Remote file is newer, retrieving.\n"
msgstr "Fichier éloigné est plus récent, récupération.\n"

#: src/http.c:1728
#, c-format
msgid "%s (%s) - `%s' saved [%ld/%ld]\n\n"
msgstr "%s (%s) - `%s' sauvegardé [%ld/%ld]\n\n"

#: src/http.c:1774
#, c-format
msgid "%s (%s) - Connection closed at byte %ld. "
msgstr "%s (%s) - Fermeture de la connexion à l'octet %ld. "

#: src/http.c:1782
#, c-format
msgid "%s (%s) - `%s' saved [%ld/%ld])\n\n"
msgstr "%s (%s) - `%s' sauvegardé [%ld/%ld]\n\n"

#: src/http.c:1801
#, c-format
msgid "%s (%s) - Connection closed at byte %ld/%ld. "
msgstr "%s (%s) - Fermeture de la connexion à l'octet %ld/%ld. "

#: src/http.c:1812
#, c-format
msgid "%s (%s) - Read error at byte %ld (%s)."
msgstr "%s (%s) - ERREUR de lecture à l'octet %ld (%s)."

#: src/http.c:1820
#, c-format
msgid "%s (%s) - Read error at byte %ld/%ld (%s). "
msgstr "%s (%s) - ERREUR de lecture à l'octet %ld/%ld (%s)."

#: src/init.c:349 src/netrc.c:267
#, c-format
msgid "%s: Cannot read %s (%s).\n"
msgstr "%s: ne peut lire %s (%s).\n"

#: src/init.c:367 src/init.c:373
#, c-format
msgid "%s: Error in %s at line %d.\n"
msgstr "%s: ERREUR dans %s à la ligne %d.\n"

#: src/init.c:405
#, c-format
msgid "%s: Warning: Both system and user wgetrc point to `%s'.\n"
msgstr "%s: AVERTISSEMENT wgetrc tant du système que de l'usager pointe vers `%s'.\n"

#: src/init.c:497
#, c-format
msgid "%s: BUG: unknown command `%s', value `%s'.\n"
msgstr "%s: ERREUR: commande inconnue `%s', valeur `%s'.\n"

#: src/init.c:529
#, c-format
msgid "%s: %s: Cannot convert `%s' to an IP address.\n"
msgstr "%s: %s: ne peut convertit `%s' à une adresse IP.\n"

#: src/init.c:559
#, c-format
msgid "%s: %s: Please specify on or off.\n"
msgstr "%s: %s: SVP spécifier `on' ou `off'.\n"

#: src/init.c:603
#, c-format
msgid "%s: %s: Please specify always, on, off, or never.\n"
msgstr "%s: %s: SVP toujours spécifier `on', `off' ou `never'.\n"

#: src/init.c:622 src/init.c:919 src/init.c:941 src/init.c:1005
#, c-format
msgid "%s: %s: Invalid specification `%s'.\n"
msgstr "%s: %s: spécification erronnée `%s'.\n"

#: src/init.c:775 src/init.c:797 src/init.c:819 src/init.c:845
#, c-format
msgid "%s: Invalid specification `%s'\n"
msgstr "%s: spécification erronnée `%s'\n"
