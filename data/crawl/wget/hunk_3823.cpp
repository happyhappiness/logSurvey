 msgid "%s: option requires an argument -- %c\n"
 msgstr "%s: l'option requiert le paramètre -- %c\n"
 
-#: src/host.c:432
+#: src/host.c:394
 #, c-format
 msgid "%s: Cannot determine user-id.\n"
 msgstr "%s: ne peut déterminer le UID de l'usager.\n"
 
-#: src/host.c:444
+#: src/host.c:406
 #, c-format
 msgid "%s: Warning: uname failed: %s\n"
 msgstr "%s: AVERTISSEMENT: échec de `uname': %s\n"
 
-#: src/host.c:456
+#: src/host.c:418
 #, c-format
 msgid "%s: Warning: gethostname failed\n"
 msgstr "%s: AVERTISSEMENT: échec de la fonction gethostname()\n"
 
-#: src/host.c:484
+#: src/host.c:446
 #, c-format
 msgid "%s: Warning: cannot determine local IP address.\n"
 msgstr "%s: AVERTISSEMENT: ne peut déterminer l'adresse IP locale.\n"
 
-#: src/host.c:498
+#: src/host.c:460
 #, c-format
 msgid "%s: Warning: cannot reverse-lookup local IP address.\n"
-msgstr "%s: AVERTISSEMENT: ne peut repérer l'adresse IP locale par requête inverse.\n"
+msgstr ""
+"%s: AVERTISSEMENT: ne peut repérer l'adresse IP locale par requête inverse.\n"
 
 #. This gets ticked pretty often.  Karl Berry reports
 #. that there can be valid reasons for the local host
 #. name not to be an FQDN, so I've decided to remove the
 #. annoying warning.
-#: src/host.c:511
+#: src/host.c:473
 #, c-format
 msgid "%s: Warning: reverse-lookup of local address did not yield FQDN!\n"
-msgstr "%s: AVERTISSEMENT: requête inverse de l'adresse IP locale n'est pas complétée par FQDN!\n"
+msgstr ""
+"%s: AVERTISSEMENT: requête inverse de l'adresse IP locale n'est pas "
+"complétée par FQDN!\n"
 
-#: src/host.c:539
+#: src/host.c:501
 msgid "Host not found"
 msgstr "Hôte non repéré"
 
-#: src/host.c:541
+#: src/host.c:503
 msgid "Unknown error"
 msgstr "ERREUR inconnue"
 
-#: src/html.c:439 src/html.c:441
-#, c-format
-msgid "Index of /%s on %s:%d"
-msgstr "Index de /%s sur %s:%d"
-
-#: src/html.c:463
-msgid "time unknown       "
-msgstr "heure inconnue     "
-
-#: src/html.c:467
-msgid "File        "
-msgstr "Fichier     "
-
-#: src/html.c:470
-msgid "Directory   "
-msgstr "Répertoire  "
-
-#: src/html.c:473
-msgid "Link        "
-msgstr "Lien        "
-
-#: src/html.c:476
-msgid "Not sure    "
-msgstr "Incertain   "
+#: src/http.c:621 src/http.c:1433
+msgid "Unable to establish SSL connection.\n"
+msgstr ""
 
-#: src/html.c:494
-#, c-format
-msgid " (%s bytes)"
-msgstr " (%s octets)"
+#: src/http.c:629
+#, fuzzy, c-format
+msgid "Reusing connection to %s:%hu.\n"
+msgstr "Tentative de connexion vers %s:%hu.\n"
 
-#: src/http.c:492
-msgid "Failed writing HTTP request.\n"
+#: src/http.c:805
+#, fuzzy, c-format
+msgid "Failed writing HTTP request: %s.\n"
 msgstr "Échec d'écriture de la requête HTTP.\n"
 
-#: src/http.c:497
+#: src/http.c:810
 #, c-format
 msgid "%s request sent, awaiting response... "
 msgstr "requête %s transmise, en attente de la réponse..."
 
-#: src/http.c:536
+#: src/http.c:854
 msgid "End of file while parsing headers.\n"
 msgstr "Fin de fichier lors de l'analyse du l'en-tête.\n"
 
-#: src/http.c:547
+#: src/http.c:865
 #, c-format
 msgid "Read error (%s) in headers.\n"
 msgstr "ERREUR de lecture (%s) de l'en-tête.\n"
 
-#: src/http.c:587
+#: src/http.c:905
 msgid "No data received"
 msgstr "Aucune donnée reçue"
 
-#: src/http.c:589
+#: src/http.c:907
 msgid "Malformed status line"
 msgstr "Ligne d'état mal composée"
 
-#: src/http.c:594
+#: src/http.c:912
 msgid "(no description)"
 msgstr "(pas de description)"
 
-#. If we have tried it already, then there is not point
-#. retrying it.
-#: src/http.c:678
+#: src/http.c:1030
 msgid "Authorization failed.\n"
 msgstr "Échec d'autorisation.\n"
 
-#: src/http.c:685
+#: src/http.c:1037
 msgid "Unknown authentication scheme.\n"
 msgstr "Schème inconnu d'authentification.\n"
 
-#: src/http.c:748
+#: src/http.c:1127
 #, c-format
 msgid "Location: %s%s\n"
 msgstr "Location: %s%s\n"
 
-#: src/http.c:749 src/http.c:774
+#: src/http.c:1128 src/http.c:1153
 msgid "unspecified"
 msgstr "non spécifié"
 
-#: src/http.c:750
+#: src/http.c:1129
 msgid " [following]"
 msgstr " [suivant]"
 
 #. No need to print this output if the body won't be
 #. downloaded at all, or if the original server response is
 #. printed.
-#: src/http.c:764
+#: src/http.c:1143
 msgid "Length: "
 msgstr "Longueur: "
 
-#: src/http.c:769
+#: src/http.c:1148
 #, c-format
 msgid " (%s to go)"
 msgstr " (%s restant)"
 
-#: src/http.c:774
+#: src/http.c:1153
 msgid "ignored"
 msgstr "ignoré"
 
-#: src/http.c:857
+#: src/http.c:1254
 msgid "Warning: wildcards not supported in HTTP.\n"
 msgstr "AVERTISSEMENT: les métacaractères ne sont pas supportés en HTTP.\n"
 
 #. If opt.noclobber is turned on and file already exists, do not
 #. retrieve the file
-#: src/http.c:872
+#: src/http.c:1275
 #, c-format
 msgid "File `%s' already there, will not retrieve.\n"
 msgstr "Fichier `%s' est déjà là, pas de récupération.\n"
 
-#: src/http.c:978
+#: src/http.c:1425
 #, c-format
 msgid "Cannot write to `%s' (%s).\n"
 msgstr "Ne peut écrire dans `%s' (%s).\n"
 
-#: src/http.c:988
+#: src/http.c:1443
 #, c-format
 msgid "ERROR: Redirection (%d) without location.\n"
 msgstr "ERREUR: redirection (%d) sans destination.\n"
 
-#: src/http.c:1011
+#: src/http.c:1468
 #, c-format
 msgid "%s ERROR %d: %s.\n"
 msgstr "%s ERREUR %d: %s.\n"
 
-#: src/http.c:1023
+#: src/http.c:1481
 msgid "Last-modified header missing -- time-stamps turned off.\n"
-msgstr "En-tête manquante de la dernière modification -- tampon date-heure ignoré.\n"
+msgstr ""
+"En-tête manquante de la dernière modification -- tampon date-heure ignoré.\n"
 
-#: src/http.c:1031
+#: src/http.c:1489
 msgid "Last-modified header invalid -- time-stamp ignored.\n"
-msgstr "En-tête erronée de la dernière modification -- tampon date-heure ignoré.\n"
+msgstr ""
+"En-tête erronée de la dernière modification -- tampon date-heure ignoré.\n"
 
-#: src/http.c:1064
+#: src/http.c:1524
 msgid "Remote file is newer, retrieving.\n"
 msgstr "Fichier éloigné est plus récent, récupération.\n"
 
-#: src/http.c:1098
+#: src/http.c:1559
 #, c-format
-msgid "%s (%s) - `%s' saved [%ld/%ld]\n\n"
-msgstr "%s (%s) - `%s' sauvegardé [%ld/%ld]\n\n"
+msgid ""
+"%s (%s) - `%s' saved [%ld/%ld]\n"
+"\n"
+msgstr ""
+"%s (%s) - `%s' sauvegardé [%ld/%ld]\n"
+"\n"
 
-#: src/http.c:1130
+#: src/http.c:1607
 #, c-format
 msgid "%s (%s) - Connection closed at byte %ld. "
 msgstr "%s (%s) - Fermeture de la connexion à l'octet %ld. "
 
-#: src/http.c:1138
+#: src/http.c:1615
 #, c-format
-msgid "%s (%s) - `%s' saved [%ld/%ld])\n\n"
-msgstr "%s (%s) - `%s' sauvegardé [%ld/%ld]\n\n"
+msgid ""
+"%s (%s) - `%s' saved [%ld/%ld])\n"
+"\n"
+msgstr ""
+"%s (%s) - `%s' sauvegardé [%ld/%ld]\n"
+"\n"
 
-#: src/http.c:1150
+#: src/http.c:1635
 #, c-format
 msgid "%s (%s) - Connection closed at byte %ld/%ld. "
 msgstr "%s (%s) - Fermeture de la connexion à l'octet %ld/%ld. "
 
-#: src/http.c:1161
+#: src/http.c:1646
 #, c-format
 msgid "%s (%s) - Read error at byte %ld (%s)."
 msgstr "%s (%s) - ERREUR de lecture à l'octet %ld (%s)."
 
-#: src/http.c:1169
+#: src/http.c:1654
 #, c-format
 msgid "%s (%s) - Read error at byte %ld/%ld (%s). "
 msgstr "%s (%s) - ERREUR de lecture à l'octet %ld/%ld (%s)."
 
-#: src/init.c:312 src/netrc.c:250
+#: src/init.c:332 src/netrc.c:261
 #, c-format
 msgid "%s: Cannot read %s (%s).\n"
 msgstr "%s: ne peut lire %s (%s).\n"
 
-#: src/init.c:333 src/init.c:339
+#: src/init.c:350 src/init.c:356
 #, c-format
 msgid "%s: Error in %s at line %d.\n"
 msgstr "%s: ERREUR dans %s à la ligne %d.\n"
 
-#: src/init.c:370
+#: src/init.c:387
 #, c-format
 msgid "%s: Warning: Both system and user wgetrc point to `%s'.\n"
-msgstr "%s: AVERTISSEMENT wgetrc tant du système que de l'usager pointe vers `%s'.\n"
+msgstr ""
+"%s: AVERTISSEMENT wgetrc tant du système que de l'usager pointe vers `%s'.\n"
 
-#: src/init.c:458
+#: src/init.c:479
 #, c-format
 msgid "%s: BUG: unknown command `%s', value `%s'.\n"
 msgstr "%s: ERREUR: commande inconnue `%s', valeur `%s'.\n"
 
-#: src/init.c:485
+#: src/init.c:501
+#, fuzzy, c-format
+msgid "%s: Out of memory.\n"
+msgstr "%s: %s: mémoire épuisée.\n"
+
+#: src/init.c:507
+#, fuzzy, c-format
+msgid "%s: %s: Cannot convert `%s' to an IP address.\n"
+msgstr ""
+"%s: AVERTISSEMENT: ne peut repérer l'adresse IP locale par requête inverse.\n"
+
+#: src/init.c:535
 #, c-format
 msgid "%s: %s: Please specify on or off.\n"
 msgstr "%s: %s: SVP spécifier `on' ou `off'.\n"
 
-#: src/init.c:503 src/init.c:760 src/init.c:782 src/init.c:855
+#: src/init.c:579
+#, fuzzy, c-format
+msgid "%s: %s: Please specify always, on, off, or never.\n"
+msgstr "%s: %s: SVP spécifier `on' ou `off'.\n"
+
+#: src/init.c:598 src/init.c:855 src/init.c:877 src/init.c:941
 #, c-format
 msgid "%s: %s: Invalid specification `%s'.\n"
 msgstr "%s: %s: spécification erronnée `%s'.\n"
 
-#: src/init.c:616 src/init.c:638 src/init.c:660 src/init.c:686
+#: src/init.c:711 src/init.c:733 src/init.c:755 src/init.c:781
 #, c-format
 msgid "%s: Invalid specification `%s'\n"
 msgstr "%s: spécification erronnée `%s'\n"
 
-#: src/main.c:101
+#: src/main.c:119
 #, c-format
 msgid "Usage: %s [OPTION]... [URL]...\n"
 msgstr "Usage: %s [OPTION]... [URL]...\n"
 
-#: src/main.c:109
+#: src/main.c:127
 #, c-format
 msgid "GNU Wget %s, a non-interactive network retriever.\n"
 msgstr "GNU Wget %s, un récupérateur réseau non intéractif.\n"
 
 #. Had to split this in parts, so the #@@#%# Ultrix compiler and cpp
 #. don't bitch.  Also, it makes translation much easier.
-#: src/main.c:114
-msgid "\nMandatory arguments to long options are mandatory for short options too.\n\n"
+#: src/main.c:132
+msgid ""
+"\n"
+"Mandatory arguments to long options are mandatory for short options too.\n"
+"\n"
 msgstr ""
 "\n"
 "Les paramètres obligatoires pour les options de formes longues le sont\n"
 "aussi pour les options de formes courtes.\n"
 "\n"
 
-#: src/main.c:117
+#: src/main.c:135
+#, fuzzy
 msgid ""
 "Startup:\n"
 "  -V,  --version           display the version of Wget and exit.\n"
 "  -h,  --help              print this help.\n"
 "  -b,  --background        go to background after startup.\n"
-"  -e,  --execute=COMMAND   execute a `.wgetrc' command.\n"
+"  -e,  --execute=COMMAND   execute a `.wgetrc'-style command.\n"
 "\n"
 msgstr ""
 "Démarrage:\n"
 "  -V,  --version               afficher le nom et la version du logiciel\n"
 "  -h,  --help                  afficher l'aide-mémoire\n"
-"  -b,  --background            travailler à l'arrière plan après le démarrage.\n"
+"  -b,  --background            travailler à l'arrière plan après le "
+"démarrage.\n"
 "  -e,  --execute=COMMAND       exécuter une commande `.wgetrc'.\n"
 "\n"
 
-#: src/main.c:123
+#: src/main.c:141
+#, fuzzy
 msgid ""
 "Logging and input file:\n"
 "  -o,  --output-file=FILE     log messages to FILE.\n"
