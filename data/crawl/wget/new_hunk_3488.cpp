msgid " (%s bytes)"
msgstr " (%s octets)"

#. Second: Login with proper USER/PASS sequence.
#: src/ftp.c:187
#, c-format
msgid "Logging in as %s ... "
msgstr "Session débutant sous %s..."

#: src/ftp.c:196 src/ftp.c:249 src/ftp.c:281 src/ftp.c:330 src/ftp.c:423
#: src/ftp.c:474 src/ftp.c:504 src/ftp.c:568 src/ftp.c:641 src/ftp.c:702
#: src/ftp.c:750
msgid "Error in server response, closing control connection.\n"
msgstr "ERREUR dans la réponse du serveur, fermeture de connexion de contrôle.\n"

#: src/ftp.c:204
msgid "Error in server greeting.\n"
msgstr "ERREUR dans le message de salutation du serveur.\n"

#: src/ftp.c:212 src/ftp.c:339 src/ftp.c:432 src/ftp.c:513 src/ftp.c:578
#: src/ftp.c:651 src/ftp.c:712 src/ftp.c:760
msgid "Write failed, closing control connection.\n"
msgstr "ÉCHEC d'écriture, fermeture de connexion de contrôle.\n"

#: src/ftp.c:219
msgid "The server refuses login.\n"
msgstr "Le serveur refuse l'établissement de session.\n"

#: src/ftp.c:226
msgid "Login incorrect.\n"
msgstr "Établissement de session erroné.\n"

#: src/ftp.c:233
msgid "Logged in!\n"
msgstr "Session établie!\n"

#: src/ftp.c:258
msgid "Server error, can't determine system type.\n"
msgstr "Erreur du serveur, ne peut déterminer le type de système.\n"

#: src/ftp.c:268 src/ftp.c:553 src/ftp.c:625 src/ftp.c:682
msgid "done.    "
msgstr "complété.    "

#: src/ftp.c:318 src/ftp.c:453 src/ftp.c:488 src/ftp.c:733 src/ftp.c:781
#: src/host.c:263
msgid "done.\n"
msgstr "complété.\n"

#: src/ftp.c:347
#, c-format
msgid "Unknown type `%c', closing control connection.\n"
msgstr "Type %c inconnu, fermeture de connexion de contrôle.\n"

#: src/ftp.c:360
msgid "done.  "
msgstr "complété.  "

#: src/ftp.c:366
msgid "==> CWD not needed.\n"
msgstr "==> CWD n'est pas nécessaire.\n"

#: src/ftp.c:439
#, c-format
msgid "No such directory `%s'.\n\n"
msgstr "Répertoire `%s' inexistant.\n\n"

#. do not CWD
#: src/ftp.c:457
msgid "==> CWD not required.\n"
msgstr "==> CWD n'est pas requis.\n"

#: src/ftp.c:520
msgid "Cannot initiate PASV transfer.\n"
msgstr "Ne peut initier le transfert PASV.\n"

#: src/ftp.c:524
msgid "Cannot parse PASV response.\n"
msgstr "Ne peut analyser la réponse PASV.\n"

#: src/ftp.c:545
msgid "couldn't connect to %s:%hu: %s\n"
msgstr "ne peut établir la connexion vers %s:%hu: %s.\n"

#: src/ftp.c:595
#, c-format
msgid "Bind error (%s).\n"
msgstr "ERREUR de `bind' (%s).\n"

#: src/ftp.c:611
msgid "Invalid PORT.\n"
msgstr "Port non valable.\n"

#: src/ftp.c:664
#, c-format
msgid "\nREST failed; will not truncate `%s'.\n"
msgstr "\nÉCHEC REST; aucune troncation de `%s'\n"

#: src/ftp.c:671
msgid "\nREST failed, starting from scratch.\n"
msgstr "\nÉCHEC sur le reste, reprise depuis le début.\n"

#: src/ftp.c:720
#, c-format
msgid "No such file `%s'.\n\n"
msgstr "Fichier `%s' inexistant.\n\n"

#: src/ftp.c:768
#, c-format
msgid "No such file or directory `%s'.\n\n"
msgstr "Fichier ou répertoire `%s' inexistant.\n\n"

#: src/ftp.c:852 src/ftp.c:860
#, c-format
msgid "Length: %s"
msgstr "Longueur: %s"

#: src/ftp.c:854 src/ftp.c:862
#, c-format
msgid " [%s to go]"
msgstr " [%s restant]"

#: src/ftp.c:864
msgid " (unauthoritative)\n"
msgstr " (non autorisée)\n"

#: src/ftp.c:890
#, c-format
msgid "%s: %s, closing control connection.\n"
msgstr "%s: %s, fermeture de connexion de contrôle.\n"

#: src/ftp.c:898
#, c-format
msgid "%s (%s) - Data connection: %s; "
msgstr "%s (%s) - Connexion de tranfert de données: %s; "

#: src/ftp.c:915
msgid "Control connection closed.\n"
msgstr "Connexion de contrôle fermée.\n"

#: src/ftp.c:933
msgid "Data transfer aborted.\n"
msgstr "Transfert des données arrêté.\n"

#: src/ftp.c:997
#, c-format
msgid "File `%s' already there, not retrieving.\n"
msgstr "Fichier `%s' est déjà là, pas de récupération.\n"

#: src/ftp.c:1067 src/http.c:1538
#, c-format
msgid "(try:%2d)"
msgstr "(essai:%2d)"

#: src/ftp.c:1131 src/http.c:1797
#, c-format
msgid "%s (%s) - `%s' saved [%ld]\n\n"
msgstr "%s (%s) - `%s' sauvegardé [%ld]\n\n"

#: src/ftp.c:1173 src/main.c:814 src/recur.c:336 src/retr.c:587
#, c-format
msgid "Removing %s.\n"
msgstr "Destruction de %s.\n"

#: src/ftp.c:1215
#, c-format
msgid "Using `%s' as listing tmp file.\n"
msgstr "Utilisation de `%s' comme fichier temporaire de listage.\n"

#: src/ftp.c:1230
#, c-format
msgid "Removed `%s'.\n"
msgstr "`%s' détruit.\n"

#: src/ftp.c:1265
#, c-format
msgid "Recursion depth %d exceeded max. depth %d.\n"
msgstr "Le niveau %d de récursivité dépasse le niveau maximum %d.\n"
