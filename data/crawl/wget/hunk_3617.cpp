 #
 msgid ""
 msgstr ""
-"Project-Id-Version: GNU Wget 1.7-dev\n"
-"POT-Creation-Date: 2001-02-23 13:23-0800\n"
-"PO-Revision-Date: 1999-06-25 11:00 -0500\n"
+"Project-Id-Version: GNU wget 1.7\n"
+"POT-Creation-Date: 2001-06-03 15:27+0200\n"
+"PO-Revision-Date: 2001-06-12 10:00 -0500\n"
 "Last-Translator: Michel Robitaille <robitail@IRO.UMontreal.CA>\n"
 "Language-Team: French <traduc@traduc.org>\n"
 "MIME-Version: 1.0\n"
 "Content-Type: text/plain; charset=ISO-8859-1\n"
 "Content-Transfer-Encoding: 8-bit\n"
 
-#: src/ftp-ls.c:779
-msgid "Usupported listing type, trying Unix listing parser.\n"
-msgstr ""
+#: src/cookies.c:588
+#, c-format
+msgid "Error in Set-Cookie, field `%s'"
+msgstr "Erreur dans Set-Cookie(), champ `%s'"
 
-#: src/ftp-ls.c:824 src/ftp-ls.c:826
+#: src/cookies.c:612
+#, c-format
+msgid "Syntax error in Set-Cookie at character `%c'.\n"
+msgstr "Erreur de syntaxe dans Set-Cookie sur le caractère `%c'.\n"
+
+#: src/cookies.c:620
+msgid "Syntax error in Set-Cookie: premature end of string.\n"
+msgstr "Erreur de syntaxe dans Set-Cookie: fin prématurée de la chaîne\n"
+
+#: src/cookies.c:1352
+msgid "Cannot open cookies file `%s': %s\n"
+msgstr "Ne peut ouvrir le fichier des cookies `%s': %s\n"
+
+#: src/cookies.c:1364
+msgid "Error writing to `%s': %s\n"
+msgstr "Ne peut écrire dans `%s': %s\n"
+
+#: src/cookies.c:1368
+#, c-format
+msgid "Error closing `%s': %s\n"
+msgstr "Erreur de fermeture `%s': %s\n"
+
+#: src/ftp-ls.c:787
+msgid "Unsupported listing type, trying Unix listing parser.\n"
+msgstr "Type d'affichage (listing) non-supporté, essayer le parseur d'affichage à la Unix.\n"
+
+#: src/ftp-ls.c:832 src/ftp-ls.c:834
 #, c-format
 msgid "Index of /%s on %s:%d"
 msgstr "Index de /%s sur %s:%d"
 
-#: src/ftp-ls.c:848
+#: src/ftp-ls.c:856
 msgid "time unknown       "
 msgstr "heure inconnue     "
 
-#: src/ftp-ls.c:852
+#: src/ftp-ls.c:860
 msgid "File        "
 msgstr "Fichier     "
 
-#: src/ftp-ls.c:855
+#: src/ftp-ls.c:863
 msgid "Directory   "
 msgstr "Répertoire  "
 
-#: src/ftp-ls.c:858
+#: src/ftp-ls.c:866
 msgid "Link        "
 msgstr "Lien        "
 
-#: src/ftp-ls.c:861
+#: src/ftp-ls.c:869
 msgid "Not sure    "
 msgstr "Incertain   "
 
-#: src/ftp-ls.c:879
+#: src/ftp-ls.c:887
 #, c-format
 msgid " (%s bytes)"
 msgstr " (%s octets)"
 
 #. Login to the server:
 #. First: Establish the control connection.
-#: src/ftp.c:151 src/http.c:618
+#: src/ftp.c:150 src/http.c:624
 #, c-format
 msgid "Connecting to %s:%hu... "
 msgstr "Connexion vers %s:%hu..."
 
-#: src/ftp.c:173 src/ftp.c:517 src/http.c:635
+#: src/ftp.c:172 src/ftp.c:539 src/http.c:641
 #, c-format
 msgid "Connection to %s:%hu refused.\n"
 msgstr "Connexion vers %s:%hu refusée.\n"
 
 #. Second: Login with proper USER/PASS sequence.
-#: src/ftp.c:194 src/http.c:646
+#: src/ftp.c:193 src/http.c:652
 msgid "connected!\n"
 msgstr "Connecté!\n"
 
-#: src/ftp.c:195
+#: src/ftp.c:194
 #, c-format
 msgid "Logging in as %s ... "
 msgstr "Session débutant sous %s..."
 
-#: src/ftp.c:204 src/ftp.c:257 src/ftp.c:288 src/ftp.c:313 src/ftp.c:407
-#: src/ftp.c:459 src/ftp.c:553 src/ftp.c:626 src/ftp.c:674 src/ftp.c:722
+#: src/ftp.c:203 src/ftp.c:256 src/ftp.c:288 src/ftp.c:336 src/ftp.c:429
+#: src/ftp.c:481 src/ftp.c:575 src/ftp.c:648 src/ftp.c:709 src/ftp.c:757
 msgid "Error in server response, closing control connection.\n"
-msgstr ""
-"ERREUR dans la réponse du serveur, fermeture de connexion de contrôle.\n"
+msgstr "ERREUR dans la réponse du serveur, fermeture de connexion de contrôle.\n"
 
-#: src/ftp.c:212
+#: src/ftp.c:211
 msgid "Error in server greeting.\n"
 msgstr "ERREUR dans le message de salutation du serveur.\n"
 
-#: src/ftp.c:220 src/ftp.c:322 src/ftp.c:416 src/ftp.c:468 src/ftp.c:563
-#: src/ftp.c:636 src/ftp.c:684 src/ftp.c:732
+#: src/ftp.c:219 src/ftp.c:345 src/ftp.c:438 src/ftp.c:490 src/ftp.c:585
+#: src/ftp.c:658 src/ftp.c:719 src/ftp.c:767
 msgid "Write failed, closing control connection.\n"
 msgstr "ÉCHEC d'écriture, fermeture de connexion de contrôle.\n"
 
-#: src/ftp.c:227
+#: src/ftp.c:226
 msgid "The server refuses login.\n"
 msgstr "Le serveur refuse l'établissement de session.\n"
 
-#: src/ftp.c:234
+#: src/ftp.c:233
 msgid "Login incorrect.\n"
 msgstr "Établissement de session erroné.\n"
 
-#: src/ftp.c:241
+#: src/ftp.c:240
 msgid "Logged in!\n"
 msgstr "Session établie!\n"
 
-#: src/ftp.c:266
+#: src/ftp.c:265
 msgid "Server error, can't determine system type.\n"
-msgstr ""
+msgstr "Erreur du serveur, ne peut déterminer le type de système.\n"
 
-#: src/ftp.c:276 src/ftp.c:538 src/ftp.c:610 src/ftp.c:654
+#: src/ftp.c:275 src/ftp.c:560 src/ftp.c:632 src/ftp.c:689
 msgid "done.    "
 msgstr "complété.    "
 
-#: src/ftp.c:302 src/ftp.c:437 src/ftp.c:705 src/ftp.c:753 src/url.c:1432
+#: src/ftp.c:325 src/ftp.c:459 src/ftp.c:740 src/ftp.c:788 src/url.c:1429
 msgid "done.\n"
 msgstr "complété.\n"
 
-#: src/ftp.c:330
+#: src/ftp.c:353
 #, c-format
 msgid "Unknown type `%c', closing control connection.\n"
 msgstr "Type %c inconnu, fermeture de connexion de contrôle.\n"
 
-#: src/ftp.c:343
+#: src/ftp.c:366
 msgid "done.  "
 msgstr "complété.  "
 
-#: src/ftp.c:349
+#: src/ftp.c:372
 msgid "==> CWD not needed.\n"
 msgstr "==> CWD n'est pas nécessaire.\n"
 
-#: src/ftp.c:423
+#: src/ftp.c:445
 #, c-format
-msgid ""
-"No such directory `%s'.\n"
-"\n"
-msgstr ""
-"Répertoire `%s' inexistant.\n"
-"\n"
+msgid "No such directory `%s'.\n\n"
+msgstr "Répertoire `%s' inexistant.\n\n"
 
 #. do not CWD
-#: src/ftp.c:441
+#: src/ftp.c:463
 msgid "==> CWD not required.\n"
 msgstr "==> CWD n'est pas requis.\n"
 
-#: src/ftp.c:475
+#: src/ftp.c:497
 msgid "Cannot initiate PASV transfer.\n"
 msgstr "Ne peut initier le transfert PASV.\n"
 
-#: src/ftp.c:479
+#: src/ftp.c:501
 msgid "Cannot parse PASV response.\n"
 msgstr "Ne peut analyser la réponse PASV.\n"
 
-#: src/ftp.c:493
+#: src/ftp.c:515
 #, c-format
 msgid "Will try connecting to %s:%hu.\n"
 msgstr "Tentative de connexion vers %s:%hu.\n"
 
-#: src/ftp.c:580
+#: src/ftp.c:602
 #, c-format
 msgid "Bind error (%s).\n"
 msgstr "ERREUR de `bind' (%s).\n"
 
-#: src/ftp.c:596
+#: src/ftp.c:618
 msgid "Invalid PORT.\n"
 msgstr "Port non valable.\n"
 
-#: src/ftp.c:643
-msgid ""
-"\n"
-"REST failed, starting from scratch.\n"
-msgstr ""
-"\n"
-"ÉCHEC sur le reste, reprise depuis le début.\n"
+#: src/ftp.c:671
+#, c-format
+msgid "\nREST failed; will not truncate `%s'.\n"
+msgstr "\nÉCHEC REST; aucune troncation de `%s'\n"
+
+#: src/ftp.c:678
+msgid "\nREST failed, starting from scratch.\n"
+msgstr "\nÉCHEC sur le reste, reprise depuis le début.\n"
 
-#: src/ftp.c:692
+#: src/ftp.c:727
 #, c-format
-msgid ""
-"No such file `%s'.\n"
-"\n"
-msgstr ""
-"Fichier `%s' inexistant.\n"
-"\n"
+msgid "No such file `%s'.\n\n"
+msgstr "Fichier `%s' inexistant.\n\n"
 
-#: src/ftp.c:740
+#: src/ftp.c:775
 #, c-format
-msgid ""
-"No such file or directory `%s'.\n"
-"\n"
-msgstr ""
-"Fichier ou répertoire `%s' inexistant.\n"
-"\n"
+msgid "No such file or directory `%s'.\n\n"
+msgstr "Fichier ou répertoire `%s' inexistant.\n\n"
 
-#: src/ftp.c:816 src/ftp.c:823
+#: src/ftp.c:859 src/ftp.c:867
 #, c-format
 msgid "Length: %s"
 msgstr "Longueur: %s"
 
-#: src/ftp.c:818 src/ftp.c:825
+#: src/ftp.c:861 src/ftp.c:869
 #, c-format
 msgid " [%s to go]"
 msgstr " [%s restant]"
 
-#: src/ftp.c:827
+#: src/ftp.c:871
 msgid " (unauthoritative)\n"
 msgstr " (non autorisée)\n"
 
-#: src/ftp.c:853
+#: src/ftp.c:898
 #, c-format
 msgid "%s: %s, closing control connection.\n"
 msgstr "%s: %s, fermeture de connexion de contrôle.\n"
 
-#: src/ftp.c:861
+#: src/ftp.c:906
 #, c-format
 msgid "%s (%s) - Data connection: %s; "
 msgstr "%s (%s) - Connexion de tranfert de données: %s; "
 
-#: src/ftp.c:878
+#: src/ftp.c:923
 msgid "Control connection closed.\n"
 msgstr "Connexion de contrôle fermée.\n"
 
-#: src/ftp.c:896
+#: src/ftp.c:941
 msgid "Data transfer aborted.\n"
 msgstr "Transfert des données arrêté.\n"
 
-#: src/ftp.c:960
+#: src/ftp.c:1005
 #, c-format
 msgid "File `%s' already there, not retrieving.\n"
 msgstr "Fichier `%s' est déjà là, pas de récupération.\n"
 
-#: src/ftp.c:1021 src/http.c:1394
+#: src/ftp.c:1075 src/http.c:1502
 #, c-format
 msgid "(try:%2d)"
 msgstr "(essai:%2d)"
 
-#: src/ftp.c:1085 src/http.c:1632
+#: src/ftp.c:1139 src/http.c:1753
 #, c-format
-msgid ""
-"%s (%s) - `%s' saved [%ld]\n"
-"\n"
-msgstr ""
-"%s (%s) - `%s' sauvegardé [%ld]\n"
-"\n"
+msgid "%s (%s) - `%s' saved [%ld]\n\n"
+msgstr "%s (%s) - `%s' sauvegardé [%ld]\n\n"
 
-#: src/ftp.c:1127 src/main.c:789 src/recur.c:509 src/retr.c:602
+#: src/ftp.c:1181 src/main.c:810 src/recur.c:483 src/retr.c:566
 #, c-format
 msgid "Removing %s.\n"
 msgstr "Destruction de %s.\n"
 
-#: src/ftp.c:1168
+#: src/ftp.c:1221
 #, c-format
 msgid "Using `%s' as listing tmp file.\n"
 msgstr "Utilisation de `%s' comme fichier temporaire de listage.\n"
 
-#: src/ftp.c:1180
+#: src/ftp.c:1233
 #, c-format
 msgid "Removed `%s'.\n"
 msgstr "`%s' détruit.\n"
 
-#: src/ftp.c:1216
+#: src/ftp.c:1269
 #, c-format
 msgid "Recursion depth %d exceeded max. depth %d.\n"
 msgstr "Le niveau %d de récursivité dépasse le niveau maximum %d.\n"
 
 #. Remote file is older, file sizes can be compared and
 #. are both equal.
-#: src/ftp.c:1277
-#, fuzzy, c-format
+#: src/ftp.c:1330
 msgid "Remote file no newer than local file `%s' -- not retrieving.\n"
-msgstr "Fichier éloigné est plus récent, récupération.\n"
+msgstr "Fichier distant n'est pas plus récent que le fichier local `%s' -- pas de récupération.\n"
 
 #. Remote file is newer or sizes cannot be matched
-#: src/ftp.c:1284
-#, fuzzy, c-format
-msgid ""
-"Remote file is newer than local file `%s' -- retrieving.\n"
-"\n"
-msgstr "Fichier éloigné est plus récent, récupération.\n"
+#: src/ftp.c:1337
+msgid "Remote file is newer than local file `%s' -- retrieving.\n\n"
+msgstr "Fichier distant n'est pas plus récent que le fichier local `%s' -- pas de récupération.\n"
 
 #. Sizes do not match
-#: src/ftp.c:1291
-#, fuzzy, c-format
-msgid ""
-"The sizes do not match (local %ld) -- retrieving.\n"
-"\n"
-msgstr "La taille des fichiers ne concorde pas (local %ld), récupération.\n"
+#: src/ftp.c:1344
+msgid "The sizes do not match (local %ld) -- retrieving.\n\n"
+msgstr "La taille ne concorde pas (local %ld) -- récupération.\n\n"
 
-#: src/ftp.c:1308
+#: src/ftp.c:1361
 msgid "Invalid name of the symlink, skipping.\n"
 msgstr "Nom erroné d'un lien symbolique, escamoté.\n"
 
-#: src/ftp.c:1325
+#: src/ftp.c:1378
 #, c-format
-msgid ""
-"Already have correct symlink %s -> %s\n"
-"\n"
-msgstr ""
-"Lien symbolique est déjà correct %s -> %s\n"
-"\n"
+msgid "Already have correct symlink %s -> %s\n\n"
+msgstr "Lien symbolique est déjà correct %s -> %s\n\n"
 
-#: src/ftp.c:1333
+#: src/ftp.c:1386
 #, c-format
 msgid "Creating symlink %s -> %s\n"
 msgstr "Création du lien symbolique %s -> %s\n"
 
-#: src/ftp.c:1344
+#: src/ftp.c:1397
 #, c-format
 msgid "Symlinks not supported, skipping symlink `%s'.\n"
 msgstr "Lien symbolique non supporté, escamotage du lien `%s'.\n"
 
-#: src/ftp.c:1356
+#: src/ftp.c:1409
 #, c-format
 msgid "Skipping directory `%s'.\n"
 msgstr "Répertoire `%s' escamoté.\n"
 
-#: src/ftp.c:1365
+#: src/ftp.c:1418
 #, c-format
 msgid "%s: unknown/unsupported file type.\n"
 msgstr "%s: type de fichier inconnu ou non supporté.\n"
 
-#: src/ftp.c:1392
+#: src/ftp.c:1445
 #, c-format
 msgid "%s: corrupt time-stamp.\n"
 msgstr "%s: tampon date-heure corrompu.\n"
 
-#: src/ftp.c:1413
+#: src/ftp.c:1466
 #, c-format
 msgid "Will not retrieve dirs since depth is %d (max %d).\n"
-msgstr ""
-"Les répertoires ne seront pas récupérés, la profondeur %d dépasse le maximum "
-"%d.\n"
+msgstr "Les répertoires ne seront pas récupérés, la profondeur %d dépasse le maximum %d.\n"
 
-#: src/ftp.c:1449
+#: src/ftp.c:1512
 #, c-format
 msgid "Not descending to `%s' as it is excluded/not-included.\n"
 msgstr "%s n'a pas été parcouru puisqu'il est exclu ou non inclu.\n"
 
-#: src/ftp.c:1494
+#: src/ftp.c:1559
 #, c-format
 msgid "Rejecting `%s'.\n"
 msgstr "Rejet de `%s'.\n"
