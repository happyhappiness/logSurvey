#
msgid ""
msgstr ""
"Project-Id-Version: GNU wget 1.7\n"
"POT-Creation-Date: 2001-06-03 15:27+0200\n"
"PO-Revision-Date: 2001-06-12 10:00 -0500\n"
"Last-Translator: Michel Robitaille <robitail@IRO.UMontreal.CA>\n"
"Language-Team: French <traduc@traduc.org>\n"
"MIME-Version: 1.0\n"
"Content-Type: text/plain; charset=ISO-8859-1\n"
"Content-Transfer-Encoding: 8-bit\n"

#: src/cookies.c:588
#, c-format
msgid "Error in Set-Cookie, field `%s'"
msgstr "Erreur dans Set-Cookie(), champ `%s'"

#: src/cookies.c:612
#, c-format
msgid "Syntax error in Set-Cookie at character `%c'.\n"
msgstr "Erreur de syntaxe dans Set-Cookie sur le caractère `%c'.\n"

#: src/cookies.c:620
msgid "Syntax error in Set-Cookie: premature end of string.\n"
msgstr "Erreur de syntaxe dans Set-Cookie: fin prématurée de la chaîne\n"

#: src/cookies.c:1352
msgid "Cannot open cookies file `%s': %s\n"
msgstr "Ne peut ouvrir le fichier des cookies `%s': %s\n"

#: src/cookies.c:1364
msgid "Error writing to `%s': %s\n"
msgstr "Ne peut écrire dans `%s': %s\n"

#: src/cookies.c:1368
#, c-format
msgid "Error closing `%s': %s\n"
msgstr "Erreur de fermeture `%s': %s\n"

#: src/ftp-ls.c:787
msgid "Unsupported listing type, trying Unix listing parser.\n"
msgstr "Type d'affichage (listing) non-supporté, essayer le parseur d'affichage à la Unix.\n"

#: src/ftp-ls.c:832 src/ftp-ls.c:834
#, c-format
msgid "Index of /%s on %s:%d"
msgstr "Index de /%s sur %s:%d"

#: src/ftp-ls.c:856
msgid "time unknown       "
msgstr "heure inconnue     "

#: src/ftp-ls.c:860
msgid "File        "
msgstr "Fichier     "

#: src/ftp-ls.c:863
msgid "Directory   "
msgstr "Répertoire  "

#: src/ftp-ls.c:866
msgid "Link        "
msgstr "Lien        "

#: src/ftp-ls.c:869
msgid "Not sure    "
msgstr "Incertain   "

#: src/ftp-ls.c:887
#, c-format
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
msgstr "Connexion vers %s:%hu refusée.\n"

#. Second: Login with proper USER/PASS sequence.
#: src/ftp.c:193 src/http.c:652
msgid "connected!\n"
msgstr "Connecté!\n"

#: src/ftp.c:194
#, c-format
msgid "Logging in as %s ... "
msgstr "Session débutant sous %s..."

#: src/ftp.c:203 src/ftp.c:256 src/ftp.c:288 src/ftp.c:336 src/ftp.c:429
#: src/ftp.c:481 src/ftp.c:575 src/ftp.c:648 src/ftp.c:709 src/ftp.c:757
msgid "Error in server response, closing control connection.\n"
msgstr "ERREUR dans la réponse du serveur, fermeture de connexion de contrôle.\n"

#: src/ftp.c:211
msgid "Error in server greeting.\n"
msgstr "ERREUR dans le message de salutation du serveur.\n"

#: src/ftp.c:219 src/ftp.c:345 src/ftp.c:438 src/ftp.c:490 src/ftp.c:585
#: src/ftp.c:658 src/ftp.c:719 src/ftp.c:767
msgid "Write failed, closing control connection.\n"
msgstr "ÉCHEC d'écriture, fermeture de connexion de contrôle.\n"

#: src/ftp.c:226
msgid "The server refuses login.\n"
msgstr "Le serveur refuse l'établissement de session.\n"

#: src/ftp.c:233
msgid "Login incorrect.\n"
msgstr "Établissement de session erroné.\n"

#: src/ftp.c:240
msgid "Logged in!\n"
msgstr "Session établie!\n"

#: src/ftp.c:265
msgid "Server error, can't determine system type.\n"
msgstr "Erreur du serveur, ne peut déterminer le type de système.\n"

#: src/ftp.c:275 src/ftp.c:560 src/ftp.c:632 src/ftp.c:689
msgid "done.    "
msgstr "complété.    "

#: src/ftp.c:325 src/ftp.c:459 src/ftp.c:740 src/ftp.c:788 src/url.c:1429
msgid "done.\n"
msgstr "complété.\n"

#: src/ftp.c:353
#, c-format
msgid "Unknown type `%c', closing control connection.\n"
msgstr "Type %c inconnu, fermeture de connexion de contrôle.\n"

#: src/ftp.c:366
msgid "done.  "
msgstr "complété.  "

#: src/ftp.c:372
msgid "==> CWD not needed.\n"
msgstr "==> CWD n'est pas nécessaire.\n"

#: src/ftp.c:445
#, c-format
msgid "No such directory `%s'.\n\n"
msgstr "Répertoire `%s' inexistant.\n\n"

#. do not CWD
#: src/ftp.c:463
msgid "==> CWD not required.\n"
msgstr "==> CWD n'est pas requis.\n"

#: src/ftp.c:497
msgid "Cannot initiate PASV transfer.\n"
msgstr "Ne peut initier le transfert PASV.\n"

#: src/ftp.c:501
msgid "Cannot parse PASV response.\n"
msgstr "Ne peut analyser la réponse PASV.\n"

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
msgstr "\nÉCHEC REST; aucune troncation de `%s'\n"

#: src/ftp.c:678
msgid "\nREST failed, starting from scratch.\n"
msgstr "\nÉCHEC sur le reste, reprise depuis le début.\n"

#: src/ftp.c:727
#, c-format
msgid "No such file `%s'.\n\n"
msgstr "Fichier `%s' inexistant.\n\n"

#: src/ftp.c:775
#, c-format
msgid "No such file or directory `%s'.\n\n"
msgstr "Fichier ou répertoire `%s' inexistant.\n\n"

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
msgstr " (non autorisée)\n"

#: src/ftp.c:898
#, c-format
msgid "%s: %s, closing control connection.\n"
msgstr "%s: %s, fermeture de connexion de contrôle.\n"

#: src/ftp.c:906
#, c-format
msgid "%s (%s) - Data connection: %s; "
msgstr "%s (%s) - Connexion de tranfert de données: %s; "

#: src/ftp.c:923
msgid "Control connection closed.\n"
msgstr "Connexion de contrôle fermée.\n"

#: src/ftp.c:941
msgid "Data transfer aborted.\n"
msgstr "Transfert des données arrêté.\n"

#: src/ftp.c:1005
#, c-format
msgid "File `%s' already there, not retrieving.\n"
msgstr "Fichier `%s' est déjà là, pas de récupération.\n"

#: src/ftp.c:1075 src/http.c:1502
#, c-format
msgid "(try:%2d)"
msgstr "(essai:%2d)"

#: src/ftp.c:1139 src/http.c:1753
#, c-format
msgid "%s (%s) - `%s' saved [%ld]\n\n"
msgstr "%s (%s) - `%s' sauvegardé [%ld]\n\n"

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
msgstr "`%s' détruit.\n"

#: src/ftp.c:1269
#, c-format
msgid "Recursion depth %d exceeded max. depth %d.\n"
msgstr "Le niveau %d de récursivité dépasse le niveau maximum %d.\n"

#. Remote file is older, file sizes can be compared and
#. are both equal.
#: src/ftp.c:1330
msgid "Remote file no newer than local file `%s' -- not retrieving.\n"
msgstr "Fichier distant n'est pas plus récent que le fichier local `%s' -- pas de récupération.\n"

#. Remote file is newer or sizes cannot be matched
#: src/ftp.c:1337
msgid "Remote file is newer than local file `%s' -- retrieving.\n\n"
msgstr "Fichier distant n'est pas plus récent que le fichier local `%s' -- pas de récupération.\n"

#. Sizes do not match
#: src/ftp.c:1344
msgid "The sizes do not match (local %ld) -- retrieving.\n\n"
msgstr "La taille ne concorde pas (local %ld) -- récupération.\n\n"

#: src/ftp.c:1361
msgid "Invalid name of the symlink, skipping.\n"
msgstr "Nom erroné d'un lien symbolique, escamoté.\n"

#: src/ftp.c:1378
#, c-format
msgid "Already have correct symlink %s -> %s\n\n"
msgstr "Lien symbolique est déjà correct %s -> %s\n\n"

#: src/ftp.c:1386
#, c-format
msgid "Creating symlink %s -> %s\n"
msgstr "Création du lien symbolique %s -> %s\n"

#: src/ftp.c:1397
#, c-format
msgid "Symlinks not supported, skipping symlink `%s'.\n"
msgstr "Lien symbolique non supporté, escamotage du lien `%s'.\n"

#: src/ftp.c:1409
#, c-format
msgid "Skipping directory `%s'.\n"
msgstr "Répertoire `%s' escamoté.\n"

#: src/ftp.c:1418
#, c-format
msgid "%s: unknown/unsupported file type.\n"
msgstr "%s: type de fichier inconnu ou non supporté.\n"

#: src/ftp.c:1445
#, c-format
msgid "%s: corrupt time-stamp.\n"
msgstr "%s: tampon date-heure corrompu.\n"

#: src/ftp.c:1466
#, c-format
msgid "Will not retrieve dirs since depth is %d (max %d).\n"
msgstr "Les répertoires ne seront pas récupérés, la profondeur %d dépasse le maximum %d.\n"

#: src/ftp.c:1512
#, c-format
msgid "Not descending to `%s' as it is excluded/not-included.\n"
msgstr "%s n'a pas été parcouru puisqu'il est exclu ou non inclu.\n"

#: src/ftp.c:1559
#, c-format
msgid "Rejecting `%s'.\n"
msgstr "Rejet de `%s'.\n"
