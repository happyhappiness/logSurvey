msgid " (%s bytes)"
msgstr " (%s octets)"

#. Login to the server:
#. First: Establish the control connection.
#: src/ftp.c:150 src/http.c:624
#, c-format
msgid "Connecting to %s:%hu... "
msgstr "Connexion vers %s:%hu..."

#: src/ftp.c:172 src/ftp.c:539 src/http.c:641
#, c-format
msgid "Connection to %s:%hu refused.\n"
msgstr "Connexion vers %s:%hu refus�e.\n"

#. Second: Login with proper USER/PASS sequence.
#: src/ftp.c:193 src/http.c:652
msgid "connected!\n"
msgstr "Connect�!\n"

#: src/ftp.c:194
#, c-format
msgid "Logging in as %s ... "
msgstr "Session d�butant sous %s..."

#: src/ftp.c:203 src/ftp.c:256 src/ftp.c:288 src/ftp.c:336 src/ftp.c:429
#: src/ftp.c:481 src/ftp.c:575 src/ftp.c:648 src/ftp.c:709 src/ftp.c:757
msgid "Error in server response, closing control connection.\n"
msgstr "ERREUR dans la r�ponse du serveur, fermeture de connexion de contr�le.\n"

#: src/ftp.c:211
msgid "Error in server greeting.\n"
msgstr "ERREUR dans le message de salutation du serveur.\n"

#: src/ftp.c:219 src/ftp.c:345 src/ftp.c:438 src/ftp.c:490 src/ftp.c:585
#: src/ftp.c:658 src/ftp.c:719 src/ftp.c:767
msgid "Write failed, closing control connection.\n"
msgstr "�CHEC d'�criture, fermeture de connexion de contr�le.\n"

#: src/ftp.c:226
msgid "The server refuses login.\n"
msgstr "Le serveur refuse l'�tablissement de session.\n"

#: src/ftp.c:233
msgid "Login incorrect.\n"
msgstr "�tablissement de session erron�.\n"

#: src/ftp.c:240
msgid "Logged in!\n"
msgstr "Session �tablie!\n"

#: src/ftp.c:265
msgid "Server error, can't determine system type.\n"
msgstr "Erreur du serveur, ne peut d�terminer le type de syst�me.\n"

#: src/ftp.c:275 src/ftp.c:560 src/ftp.c:632 src/ftp.c:689
msgid "done.    "
msgstr "compl�t�.    "

#: src/ftp.c:325 src/ftp.c:459 src/ftp.c:740 src/ftp.c:788 src/url.c:1429
msgid "done.\n"
msgstr "compl�t�.\n"

#: src/ftp.c:353
#, c-format
msgid "Unknown type `%c', closing control connection.\n"
msgstr "Type %c inconnu, fermeture de connexion de contr�le.\n"

#: src/ftp.c:366
msgid "done.  "
msgstr "compl�t�.  "

#: src/ftp.c:372
msgid "==> CWD not needed.\n"
msgstr "==> CWD n'est pas n�cessaire.\n"

#: src/ftp.c:445
#, c-format
msgid "No such directory `%s'.\n\n"
msgstr "R�pertoire `%s' inexistant.\n\n"

#. do not CWD
#: src/ftp.c:463
msgid "==> CWD not required.\n"
msgstr "==> CWD n'est pas requis.\n"

#: src/ftp.c:497
msgid "Cannot initiate PASV transfer.\n"
msgstr "Ne peut initier le transfert PASV.\n"

#: src/ftp.c:501
msgid "Cannot parse PASV response.\n"
msgstr "Ne peut analyser la r�ponse PASV.\n"

#: src/ftp.c:515
#, c-format
msgid "Will try connecting to %s:%hu.\n"
msgstr "Tentative de connexion vers %s:%hu.\n"

#: src/ftp.c:602
#, c-format
msgid "Bind error (%s).\n"
msgstr "ERREUR de `bind' (%s).\n"

#: src/ftp.c:618
msgid "Invalid PORT.\n"
msgstr "Port non valable.\n"

#: src/ftp.c:671
#, c-format
msgid "\nREST failed; will not truncate `%s'.\n"
msgstr "\n�CHEC REST; aucune troncation de `%s'\n"

#: src/ftp.c:678
msgid "\nREST failed, starting from scratch.\n"
msgstr "\n�CHEC sur le reste, reprise depuis le d�but.\n"

#: src/ftp.c:727
#, c-format
msgid "No such file `%s'.\n\n"
msgstr "Fichier `%s' inexistant.\n\n"

#: src/ftp.c:775
#, c-format
msgid "No such file or directory `%s'.\n\n"
msgstr "Fichier ou r�pertoire `%s' inexistant.\n\n"

#: src/ftp.c:859 src/ftp.c:867
#, c-format
msgid "Length: %s"
msgstr "Longueur: %s"

#: src/ftp.c:861 src/ftp.c:869
#, c-format
msgid " [%s to go]"
msgstr " [%s restant]"

#: src/ftp.c:871
msgid " (unauthoritative)\n"
msgstr " (non autoris�e)\n"

#: src/ftp.c:898
#, c-format
msgid "%s: %s, closing control connection.\n"
msgstr "%s: %s, fermeture de connexion de contr�le.\n"

#: src/ftp.c:906
#, c-format
msgid "%s (%s) - Data connection: %s; "
msgstr "%s (%s) - Connexion de tranfert de donn�es: %s; "

#: src/ftp.c:923
msgid "Control connection closed.\n"
msgstr "Connexion de contr�le ferm�e.\n"

#: src/ftp.c:941
msgid "Data transfer aborted.\n"
msgstr "Transfert des donn�es arr�t�.\n"

#: src/ftp.c:1005
#, c-format
msgid "File `%s' already there, not retrieving.\n"
msgstr "Fichier `%s' est d�j� l�, pas de r�cup�ration.\n"

#: src/ftp.c:1075 src/http.c:1502
#, c-format
msgid "(try:%2d)"
msgstr "(essai:%2d)"

#: src/ftp.c:1139 src/http.c:1753
#, c-format
msgid "%s (%s) - `%s' saved [%ld]\n\n"
msgstr "%s (%s) - `%s' sauvegard� [%ld]\n\n"

#: src/ftp.c:1181 src/main.c:810 src/recur.c:483 src/retr.c:566
#, c-format
msgid "Removing %s.\n"
msgstr "Destruction de %s.\n"

#: src/ftp.c:1221
#, c-format
msgid "Using `%s' as listing tmp file.\n"
msgstr "Utilisation de `%s' comme fichier temporaire de listage.\n"

#: src/ftp.c:1233
#, c-format
msgid "Removed `%s'.\n"
msgstr "`%s' d�truit.\n"

#: src/ftp.c:1269
#, c-format
msgid "Recursion depth %d exceeded max. depth %d.\n"
msgstr "Le niveau %d de r�cursivit� d�passe le niveau maximum %d.\n"
