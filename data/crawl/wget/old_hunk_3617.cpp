#
msgid ""
msgstr ""
"Project-Id-Version: GNU Wget 1.7-dev\n"
"POT-Creation-Date: 2001-02-23 13:23-0800\n"
"PO-Revision-Date: 1999-06-25 11:00 -0500\n"
"Last-Translator: Michel Robitaille <robitail@IRO.UMontreal.CA>\n"
"Language-Team: French <traduc@traduc.org>\n"
"MIME-Version: 1.0\n"
"Content-Type: text/plain; charset=ISO-8859-1\n"
"Content-Transfer-Encoding: 8-bit\n"

#: src/ftp-ls.c:779
msgid "Usupported listing type, trying Unix listing parser.\n"
msgstr ""

#: src/ftp-ls.c:824 src/ftp-ls.c:826
#, c-format
msgid "Index of /%s on %s:%d"
msgstr "Index de /%s sur %s:%d"

#: src/ftp-ls.c:848
msgid "time unknown       "
msgstr "heure inconnue     "

#: src/ftp-ls.c:852
msgid "File        "
msgstr "Fichier     "

#: src/ftp-ls.c:855
msgid "Directory   "
msgstr "Répertoire  "

#: src/ftp-ls.c:858
msgid "Link        "
msgstr "Lien        "

#: src/ftp-ls.c:861
msgid "Not sure    "
msgstr "Incertain   "

#: src/ftp-ls.c:879
#, c-format
msgid " (%s bytes)"
msgstr " (%s octets)"

#. Login to the server:
#. First: Establish the control connection.
#: src/ftp.c:151 src/http.c:618
#, c-format
msgid "Connecting to %s:%hu... "
msgstr "Connexion vers %s:%hu..."

#: src/ftp.c:173 src/ftp.c:517 src/http.c:635
#, c-format
msgid "Connection to %s:%hu refused.\n"
msgstr "Connexion vers %s:%hu refusée.\n"

#. Second: Login with proper USER/PASS sequence.
#: src/ftp.c:194 src/http.c:646
msgid "connected!\n"
msgstr "Connecté!\n"

#: src/ftp.c:195
#, c-format
msgid "Logging in as %s ... "
msgstr "Session débutant sous %s..."

#: src/ftp.c:204 src/ftp.c:257 src/ftp.c:288 src/ftp.c:313 src/ftp.c:407
#: src/ftp.c:459 src/ftp.c:553 src/ftp.c:626 src/ftp.c:674 src/ftp.c:722
msgid "Error in server response, closing control connection.\n"
msgstr ""
"ERREUR dans la réponse du serveur, fermeture de connexion de contrôle.\n"

#: src/ftp.c:212
msgid "Error in server greeting.\n"
msgstr "ERREUR dans le message de salutation du serveur.\n"

#: src/ftp.c:220 src/ftp.c:322 src/ftp.c:416 src/ftp.c:468 src/ftp.c:563
#: src/ftp.c:636 src/ftp.c:684 src/ftp.c:732
msgid "Write failed, closing control connection.\n"
msgstr "ÉCHEC d'écriture, fermeture de connexion de contrôle.\n"

#: src/ftp.c:227
msgid "The server refuses login.\n"
msgstr "Le serveur refuse l'établissement de session.\n"

#: src/ftp.c:234
msgid "Login incorrect.\n"
msgstr "Établissement de session erroné.\n"

#: src/ftp.c:241
msgid "Logged in!\n"
msgstr "Session établie!\n"

#: src/ftp.c:266
msgid "Server error, can't determine system type.\n"
msgstr ""

#: src/ftp.c:276 src/ftp.c:538 src/ftp.c:610 src/ftp.c:654
msgid "done.    "
msgstr "complété.    "

#: src/ftp.c:302 src/ftp.c:437 src/ftp.c:705 src/ftp.c:753 src/url.c:1432
msgid "done.\n"
msgstr "complété.\n"

#: src/ftp.c:330
#, c-format
msgid "Unknown type `%c', closing control connection.\n"
msgstr "Type %c inconnu, fermeture de connexion de contrôle.\n"

#: src/ftp.c:343
msgid "done.  "
msgstr "complété.  "

#: src/ftp.c:349
msgid "==> CWD not needed.\n"
msgstr "==> CWD n'est pas nécessaire.\n"

#: src/ftp.c:423
#, c-format
msgid ""
"No such directory `%s'.\n"
"\n"
msgstr ""
"Répertoire `%s' inexistant.\n"
"\n"

#. do not CWD
#: src/ftp.c:441
msgid "==> CWD not required.\n"
msgstr "==> CWD n'est pas requis.\n"

#: src/ftp.c:475
msgid "Cannot initiate PASV transfer.\n"
msgstr "Ne peut initier le transfert PASV.\n"

#: src/ftp.c:479
msgid "Cannot parse PASV response.\n"
msgstr "Ne peut analyser la réponse PASV.\n"

#: src/ftp.c:493
#, c-format
msgid "Will try connecting to %s:%hu.\n"
msgstr "Tentative de connexion vers %s:%hu.\n"

#: src/ftp.c:580
#, c-format
msgid "Bind error (%s).\n"
msgstr "ERREUR de `bind' (%s).\n"

#: src/ftp.c:596
msgid "Invalid PORT.\n"
msgstr "Port non valable.\n"

#: src/ftp.c:643
msgid ""
"\n"
"REST failed, starting from scratch.\n"
msgstr ""
"\n"
"ÉCHEC sur le reste, reprise depuis le début.\n"

#: src/ftp.c:692
#, c-format
msgid ""
"No such file `%s'.\n"
"\n"
msgstr ""
"Fichier `%s' inexistant.\n"
"\n"

#: src/ftp.c:740
#, c-format
msgid ""
"No such file or directory `%s'.\n"
"\n"
msgstr ""
"Fichier ou répertoire `%s' inexistant.\n"
"\n"

#: src/ftp.c:816 src/ftp.c:823
#, c-format
msgid "Length: %s"
msgstr "Longueur: %s"

#: src/ftp.c:818 src/ftp.c:825
#, c-format
msgid " [%s to go]"
msgstr " [%s restant]"

#: src/ftp.c:827
msgid " (unauthoritative)\n"
msgstr " (non autorisée)\n"

#: src/ftp.c:853
#, c-format
msgid "%s: %s, closing control connection.\n"
msgstr "%s: %s, fermeture de connexion de contrôle.\n"

#: src/ftp.c:861
#, c-format
msgid "%s (%s) - Data connection: %s; "
msgstr "%s (%s) - Connexion de tranfert de données: %s; "

#: src/ftp.c:878
msgid "Control connection closed.\n"
msgstr "Connexion de contrôle fermée.\n"

#: src/ftp.c:896
msgid "Data transfer aborted.\n"
msgstr "Transfert des données arrêté.\n"

#: src/ftp.c:960
#, c-format
msgid "File `%s' already there, not retrieving.\n"
msgstr "Fichier `%s' est déjà là, pas de récupération.\n"

#: src/ftp.c:1021 src/http.c:1394
#, c-format
msgid "(try:%2d)"
msgstr "(essai:%2d)"

#: src/ftp.c:1085 src/http.c:1632
#, c-format
msgid ""
"%s (%s) - `%s' saved [%ld]\n"
"\n"
msgstr ""
"%s (%s) - `%s' sauvegardé [%ld]\n"
"\n"

#: src/ftp.c:1127 src/main.c:789 src/recur.c:509 src/retr.c:602
#, c-format
msgid "Removing %s.\n"
msgstr "Destruction de %s.\n"

#: src/ftp.c:1168
#, c-format
msgid "Using `%s' as listing tmp file.\n"
msgstr "Utilisation de `%s' comme fichier temporaire de listage.\n"

#: src/ftp.c:1180
#, c-format
msgid "Removed `%s'.\n"
msgstr "`%s' détruit.\n"

#: src/ftp.c:1216
#, c-format
msgid "Recursion depth %d exceeded max. depth %d.\n"
msgstr "Le niveau %d de récursivité dépasse le niveau maximum %d.\n"

#. Remote file is older, file sizes can be compared and
#. are both equal.
#: src/ftp.c:1277
#, fuzzy, c-format
msgid "Remote file no newer than local file `%s' -- not retrieving.\n"
msgstr "Fichier éloigné est plus récent, récupération.\n"

#. Remote file is newer or sizes cannot be matched
#: src/ftp.c:1284
#, fuzzy, c-format
msgid ""
"Remote file is newer than local file `%s' -- retrieving.\n"
"\n"
msgstr "Fichier éloigné est plus récent, récupération.\n"

#. Sizes do not match
#: src/ftp.c:1291
#, fuzzy, c-format
msgid ""
"The sizes do not match (local %ld) -- retrieving.\n"
"\n"
msgstr "La taille des fichiers ne concorde pas (local %ld), récupération.\n"

#: src/ftp.c:1308
msgid "Invalid name of the symlink, skipping.\n"
msgstr "Nom erroné d'un lien symbolique, escamoté.\n"

#: src/ftp.c:1325
#, c-format
msgid ""
"Already have correct symlink %s -> %s\n"
"\n"
msgstr ""
"Lien symbolique est déjà correct %s -> %s\n"
"\n"

#: src/ftp.c:1333
#, c-format
msgid "Creating symlink %s -> %s\n"
msgstr "Création du lien symbolique %s -> %s\n"

#: src/ftp.c:1344
#, c-format
msgid "Symlinks not supported, skipping symlink `%s'.\n"
msgstr "Lien symbolique non supporté, escamotage du lien `%s'.\n"

#: src/ftp.c:1356
#, c-format
msgid "Skipping directory `%s'.\n"
msgstr "Répertoire `%s' escamoté.\n"

#: src/ftp.c:1365
#, c-format
msgid "%s: unknown/unsupported file type.\n"
msgstr "%s: type de fichier inconnu ou non supporté.\n"

#: src/ftp.c:1392
#, c-format
msgid "%s: corrupt time-stamp.\n"
msgstr "%s: tampon date-heure corrompu.\n"

#: src/ftp.c:1413
#, c-format
msgid "Will not retrieve dirs since depth is %d (max %d).\n"
msgstr ""
"Les répertoires ne seront pas récupérés, la profondeur %d dépasse le maximum "
"%d.\n"

#: src/ftp.c:1449
#, c-format
msgid "Not descending to `%s' as it is excluded/not-included.\n"
msgstr "%s n'a pas été parcouru puisqu'il est exclu ou non inclu.\n"

#: src/ftp.c:1494
#, c-format
msgid "Rejecting `%s'.\n"
msgstr "Rejet de `%s'.\n"
