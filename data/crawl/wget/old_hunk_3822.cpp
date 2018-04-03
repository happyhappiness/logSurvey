"Content-Type: text/plain; charset=ISO-8859-1\n"
"Content-Transfer-Encoding: 8-bit\n"

#. Login to the server:
#. First: Establish the control connection.
#: src/ftp.c:147 src/http.c:346
#, c-format
msgid "Connecting to %s:%hu... "
msgstr "Connexion vers %s:%hu..."

#: src/ftp.c:169 src/ftp.c:411 src/http.c:363
#, c-format
msgid "Connection to %s:%hu refused.\n"
msgstr "Connexion vers %s:%hu refus�e.\n"

#. Second: Login with proper USER/PASS sequence.
#: src/ftp.c:190 src/http.c:374
msgid "connected!\n"
msgstr "Connect�!\n"

#: src/ftp.c:191
#, c-format
msgid "Logging in as %s ... "
msgstr "Session d�butant sous %s..."

#: src/ftp.c:200 src/ftp.c:253 src/ftp.c:301 src/ftp.c:353 src/ftp.c:447
#: src/ftp.c:520 src/ftp.c:568 src/ftp.c:616
msgid "Error in server response, closing control connection.\n"
msgstr "ERREUR dans la r�ponse du serveur, fermeture de connexion de contr�le.\n"

#: src/ftp.c:208
msgid "Error in server greeting.\n"
msgstr "ERREUR dans le message de salutation du serveur.\n"

#: src/ftp.c:216 src/ftp.c:262 src/ftp.c:310 src/ftp.c:362 src/ftp.c:457
#: src/ftp.c:530 src/ftp.c:578 src/ftp.c:626
msgid "Write failed, closing control connection.\n"
msgstr "�CHEC d'�criture, fermeture de connexion de contr�le.\n"

#: src/ftp.c:223
msgid "The server refuses login.\n"
msgstr "Le serveur refuse l'�tablissement de session.\n"

#: src/ftp.c:230
msgid "Login incorrect.\n"
msgstr "�tablissement de session erron�.\n"

#: src/ftp.c:237
msgid "Logged in!\n"
msgstr "Session �tablie!\n"

#: src/ftp.c:270
#, c-format
msgid "Unknown type `%c', closing control connection.\n"
msgstr "Type %c inconnu, fermeture de connexion de contr�le.\n"

#: src/ftp.c:283
msgid "done.  "
msgstr "compl�t�.  "

#: src/ftp.c:289
msgid "==> CWD not needed.\n"
msgstr "==> CWD n'est pas n�cessaire.\n"

#: src/ftp.c:317
#, c-format
msgid "No such directory `%s'.\n\n"
msgstr "R�pertoire `%s' inexistant.\n\n"

#: src/ftp.c:331 src/ftp.c:599 src/ftp.c:647 src/url.c:1431
msgid "done.\n"
msgstr "compl�t�.\n"

#. do not CWD
#: src/ftp.c:335
msgid "==> CWD not required.\n"
msgstr "==> CWD n'est pas requis.\n"

#: src/ftp.c:369
msgid "Cannot initiate PASV transfer.\n"
msgstr "Ne peut initier le transfert PASV.\n"

#: src/ftp.c:373
msgid "Cannot parse PASV response.\n"
msgstr "Ne peut analyser la r�ponse PASV.\n"

#: src/ftp.c:387
#, c-format
msgid "Will try connecting to %s:%hu.\n"
msgstr "Tentative de connexion vers %s:%hu.\n"

#: src/ftp.c:432 src/ftp.c:504 src/ftp.c:548
msgid "done.    "
msgstr "compl�t�.    "

#: src/ftp.c:474
#, c-format
msgid "Bind error (%s).\n"
msgstr "ERREUR de `bind' (%s).\n"

#: src/ftp.c:490
msgid "Invalid PORT.\n"
msgstr "Port non valable.\n"

#: src/ftp.c:537
msgid "\nREST failed, starting from scratch.\n"
msgstr "\n�CHEC sur le reste, reprise depuis le d�but.\n"

#: src/ftp.c:586
#, c-format
msgid "No such file `%s'.\n\n"
msgstr "Fichier `%s' inexistant.\n\n"

#: src/ftp.c:634
#, c-format
msgid "No such file or directory `%s'.\n\n"
msgstr "Fichier ou r�pertoire `%s' inexistant.\n\n"

#: src/ftp.c:692 src/ftp.c:699
#, c-format
msgid "Length: %s"
msgstr "Longueur: %s"

#: src/ftp.c:694 src/ftp.c:701
#, c-format
msgid " [%s to go]"
msgstr " [%s restant]"

#: src/ftp.c:703
msgid " (unauthoritative)\n"
msgstr " (non autoris�e)\n"

#: src/ftp.c:721
#, c-format
msgid "%s: %s, closing control connection.\n"
msgstr "%s: %s, fermeture de connexion de contr�le.\n"

#: src/ftp.c:729
#, c-format
msgid "%s (%s) - Data connection: %s; "
msgstr "%s (%s) - Connexion de tranfert de donn�es: %s; "

#: src/ftp.c:746
msgid "Control connection closed.\n"
msgstr "Connexion de contr�le ferm�e.\n"

#: src/ftp.c:764
msgid "Data transfer aborted.\n"
msgstr "Transfert des donn�es arr�t�.\n"

#: src/ftp.c:830
#, c-format
msgid "File `%s' already there, not retrieving.\n"
msgstr "Fichier `%s' est d�j� l�, pas de r�cup�ration.\n"

#: src/ftp.c:896 src/http.c:922
#, c-format
msgid "(try:%2d)"
msgstr "(essai:%2d)"

#: src/ftp.c:955 src/http.c:1116
#, c-format
msgid "%s (%s) - `%s' saved [%ld]\n\n"
msgstr "%s (%s) - `%s' sauvegard� [%ld]\n\n"

#: src/ftp.c:1001
#, c-format
msgid "Using `%s' as listing tmp file.\n"
msgstr "Utilisation de `%s' comme fichier temporaire de listage.\n"

#: src/ftp.c:1013
#, c-format
msgid "Removed `%s'.\n"
msgstr "`%s' d�truit.\n"

#: src/ftp.c:1049
#, c-format
msgid "Recursion depth %d exceeded max. depth %d.\n"
msgstr "Le niveau %d de r�cursivit� d�passe le niveau maximum %d.\n"

#: src/ftp.c:1096 src/http.c:1054
#, c-format
msgid "Local file `%s' is more recent, not retrieving.\n\n"
msgstr "Fichier local `%s' est plus r�cent, pas de r�cup�ration.\n"

#: src/ftp.c:1102 src/http.c:1060
#, c-format
msgid "The sizes do not match (local %ld), retrieving.\n"
msgstr "La taille des fichiers ne concorde pas (local %ld), r�cup�ration.\n"

#: src/ftp.c:1119
msgid "Invalid name of the symlink, skipping.\n"
msgstr "Nom erron� d'un lien symbolique, escamot�.\n"

#: src/ftp.c:1136
#, c-format
msgid "Already have correct symlink %s -> %s\n\n"
msgstr "Lien symbolique est d�j� correct %s -> %s\n\n"

#: src/ftp.c:1144
#, c-format
msgid "Creating symlink %s -> %s\n"
msgstr "Cr�ation du lien symbolique %s -> %s\n"

#: src/ftp.c:1155
#, c-format
msgid "Symlinks not supported, skipping symlink `%s'.\n"
msgstr "Lien symbolique non support�, escamotage du lien `%s'.\n"

#: src/ftp.c:1167
#, c-format
msgid "Skipping directory `%s'.\n"
msgstr "R�pertoire `%s' escamot�.\n"

#: src/ftp.c:1176
#, c-format
msgid "%s: unknown/unsupported file type.\n"
msgstr "%s: type de fichier inconnu ou non support�.\n"

#: src/ftp.c:1193
#, c-format
msgid "%s: corrupt time-stamp.\n"
msgstr "%s: tampon date-heure corrompu.\n"

#: src/ftp.c:1213
#, c-format
msgid "Will not retrieve dirs since depth is %d (max %d).\n"
msgstr "Les r�pertoires ne seront pas r�cup�r�s, la profondeur %d d�passe le maximum %d.\n"

#: src/ftp.c:1252
#, c-format
msgid "Not descending to `%s' as it is excluded/not-included.\n"
msgstr "%s n'a pas �t� parcouru puisqu'il est exclu ou non inclu.\n"

#: src/ftp.c:1297
#, c-format
msgid "Rejecting `%s'.\n"
msgstr "Rejet de `%s'.\n"
