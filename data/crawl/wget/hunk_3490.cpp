 "Vous pouvez arrêter l'exécution de `wget' en appuyant CTRL+ALT+DELETE.\n"
 
 #. parent, no error
-#: src/mswindows.c:106 src/utils.c:458
+#: src/mswindows.c:123 src/utils.c:462
 msgid "Continuing in background.\n"
 msgstr "Poursuite à l'arrière plan.\n"
 
-#: src/mswindows.c:108 src/utils.c:460
+#: src/mswindows.c:125 src/utils.c:464
 #, c-format
 msgid "Output will be written to `%s'.\n"
 msgstr "La sortie sera écrite vers `%s'.\n"
 
-#: src/mswindows.c:188
+#: src/mswindows.c:205
 #, c-format
 msgid "Starting WinHelp %s\n"
 msgstr "Démarrage de WinHelp %s\n"
 
-#: src/mswindows.c:215 src/mswindows.c:222
+#: src/mswindows.c:232 src/mswindows.c:239
 #, c-format
 msgid "%s: Couldn't find usable socket driver.\n"
 msgstr "%s: ne repérer un pilote de socket utilisable.\n"
 
-#: src/netrc.c:367
+#: src/netrc.c:365
 #, c-format
 msgid "%s: %s:%d: warning: \"%s\" token appears before any machine name\n"
 msgstr "%s: %s:%d: AVERTISSEMENT: \"%s\" le jeton apparaît avant le nom d'une machine\n"
 
-#: src/netrc.c:398
+#: src/netrc.c:396
 #, c-format
 msgid "%s: %s:%d: unknown token \"%s\"\n"
 msgstr "%s: %s:%d: jeton inconnu \"%s\"\n"
 
-#: src/netrc.c:462
+#: src/netrc.c:460
 #, c-format
 msgid "Usage: %s NETRC [HOSTNAME]\n"
 msgstr "Usage: %s NETRC [HÔTE]\n"
 
-#: src/netrc.c:472
+#: src/netrc.c:470
 #, c-format
 msgid "%s: cannot stat %s: %s\n"
 msgstr "%s: ne peut évaluer par `stat' le fichier %s: %s\n"
 
-#: src/recur.c:484
+#. Align the [ skipping ... ] line with the dots.  To do
+#. that, insert the number of spaces equal to the number of
+#. digits in the skipped amount in K.
+#: src/progress.c:203
+msgid "\n%*s[ skipping %dK ]"
+msgstr "\n%*s[ escamotage %dK ]"
+
+#: src/progress.c:370
+msgid "Invalid dot style specification `%s'; leaving unchanged.\n"
+msgstr "Spécification du style '.' `%s' invalide; demeure inchangé.\n"
+
+#: src/recur.c:337
 #, c-format
 msgid "Removing %s since it should be rejected.\n"
 msgstr "Destruction de %s puiqu'il doit être rejeté.\n"
 
-#: src/recur.c:679
+#: src/recur.c:747
+#, c-format
+msgid "Converted %d files in %.2f seconds.\n"
+msgstr "Conversion des fichier %d en %.2f secondes.\n"
+
+#: src/res.c:541
 msgid "Loading robots.txt; please ignore errors.\n"
 msgstr "Chargement de robots.txt; svp ignorer les erreurs.\n"
 
-#: src/retr.c:227
-#, c-format
-msgid "\n          [ skipping %dK ]"
-msgstr "\n          [ escamoté %dK ]"
-
-#: src/retr.c:373
+#: src/retr.c:363
 msgid "Could not find proxy host.\n"
 msgstr "Ne peut repérer un hôte proxy.\n"
 
-#: src/retr.c:387
-#, c-format
-msgid "Proxy %s: Must be HTTP.\n"
-msgstr "Proxy %s: doit être de type HTTP.\n"
+#: src/retr.c:375
+msgid "Error parsing proxy URL %s: %s.\n"
+msgstr "Erreur d'analyse syntaxique du URL proxy %s: %s\n"
 
-#: src/retr.c:481
+#: src/retr.c:384
+msgid "Error in proxy URL %s: Must be HTTP.\n"
+msgstr "Erreur dans le URL Proxy %s: doit être de type HTTP.\n"
+
+#: src/retr.c:476
+msgid "%d redirections exceeded.\n"
+msgstr "%s: nombre de redirections dépasse la limite permise.\n"
+
+#: src/retr.c:491
 #, c-format
 msgid "%s: Redirection cycle detected.\n"
 msgstr "%s: boucle de redirection détectée.\n"
 
-#: src/retr.c:587
+#: src/retr.c:608
 msgid "Giving up.\n\n"
 msgstr "Abandon.\n\n"
 
-#: src/retr.c:587
+#: src/retr.c:608
 msgid "Retrying.\n\n"
 msgstr "Nouvel essai.\n\n"
 
-#: src/url.c:1329
+#: src/url.c:1725
 #, c-format
 msgid "Converting %s... "
 msgstr "Converstion de %s..."
 
-#: src/url.c:1342
+#: src/url.c:1738
 msgid "nothing to do.\n"
 msgstr "rien à faire.\n"
 
-#: src/url.c:1350 src/url.c:1374
+#: src/url.c:1746 src/url.c:1770
 #, c-format
 msgid "Cannot convert links in %s: %s\n"
 msgstr "Ne peut convertir les liens dans %s: %s\n"
 
-#: src/url.c:1365
+#: src/url.c:1761
+#, c-format
 msgid "Unable to delete `%s': %s\n"
 msgstr "ÉCHEC de destruction de `%s': %s\n"
 
-#: src/url.c:1555
+#: src/url.c:1967
 #, c-format
 msgid "Cannot back up %s as %s: %s\n"
 msgstr "Ne peut archiver %s comme %s: %s\n"
 
-#: src/utils.c:94
+#: src/utils.c:97
 #, c-format
 msgid "%s: %s: Not enough memory.\n"
 msgstr "%s: %s: mémoire épuisée.\n"
 
-#: src/utils.c:417
-msgid "Unknown/unsupported protocol"
-msgstr "Protocole inconnu ou non supporté"
-
-#: src/utils.c:420
-msgid "Invalid port specification"
-msgstr "Spécification du port erronée"
-
-#: src/utils.c:423
-msgid "Invalid host name"
-msgstr "Nom de l'hôte erroné"
-
-#: src/utils.c:620
+#: src/utils.c:634
 #, c-format
 msgid "Failed to unlink symlink `%s': %s\n"
 msgstr "ÉCHEC de `unlink' sur le lien symbolique `%s': %s\n"
 
+#~ msgid "Connection to %s:%hu refused.\n"
+#~ msgstr "Connexion vers %s:%hu refusée.\n"
+
+#~ msgid "Will try connecting to %s:%hu.\n"
+#~ msgstr "Tentative de connexion vers %s:%hu.\n"
+
+#~ msgid "Unknown/unsupported protocol"
+#~ msgstr "Protocole inconnu ou non supporté"
+
+#~ msgid "Invalid port specification"
+#~ msgstr "Spécification du port erronée"
+
+#~ msgid "Invalid host name"
+#~ msgstr "Nom de l'hôte erroné"
+
 #~ msgid "%s: Cannot determine user-id.\n"
 #~ msgstr "%s: ne peut déterminer le UID de l'usager.\n"
 
