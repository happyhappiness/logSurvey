 msgid "%s: cannot stat %s: %s\n"
 msgstr "%s: ne peut évaluer par `stat' le fichier %s: %s\n"
 
-#: src/recur.c:510
+#: src/recur.c:484
 #, c-format
 msgid "Removing %s since it should be rejected.\n"
 msgstr "Destruction de %s puiqu'il doit être rejeté.\n"
 
-#: src/recur.c:684
+#: src/recur.c:679
 msgid "Loading robots.txt; please ignore errors.\n"
 msgstr "Chargement de robots.txt; svp ignorer les erreurs.\n"
 
-#: src/retr.c:229
+#: src/retr.c:227
 #, c-format
-msgid ""
-"\n"
-"          [ skipping %dK ]"
-msgstr ""
-"\n"
-"          [ escamoté %dK ]"
+msgid "\n          [ skipping %dK ]"
+msgstr "\n          [ escamoté %dK ]"
 
-#: src/retr.c:421
+#: src/retr.c:373
 msgid "Could not find proxy host.\n"
 msgstr "Ne peut repérer un hôte proxy.\n"
 
-#: src/retr.c:435
+#: src/retr.c:387
 #, c-format
 msgid "Proxy %s: Must be HTTP.\n"
 msgstr "Proxy %s: doit être de type HTTP.\n"
 
-#: src/retr.c:529
-#, fuzzy, c-format
+#: src/retr.c:481
+#, c-format
 msgid "%s: Redirection cycle detected.\n"
-msgstr "%s: redirection vers lui-même.\n"
+msgstr "%s: boucle de redirection détectée.\n"
 
-#: src/retr.c:623
-msgid ""
-"Giving up.\n"
-"\n"
-msgstr ""
-"Abandon.\n"
-"\n"
+#: src/retr.c:587
+msgid "Giving up.\n\n"
+msgstr "Abandon.\n\n"
 
-#: src/retr.c:623
-msgid ""
-"Retrying.\n"
-"\n"
-msgstr ""
-"Nouvel essai.\n"
-"\n"
+#: src/retr.c:587
+msgid "Retrying.\n\n"
+msgstr "Nouvel essai.\n\n"
 
-#: src/url.c:1332
+#: src/url.c:1329
 #, c-format
 msgid "Converting %s... "
 msgstr "Converstion de %s..."
 
-#: src/url.c:1345
+#: src/url.c:1342
 msgid "nothing to do.\n"
-msgstr ""
+msgstr "rien à faire.\n"
 
-#: src/url.c:1353 src/url.c:1377
+#: src/url.c:1350 src/url.c:1374
 #, c-format
 msgid "Cannot convert links in %s: %s\n"
 msgstr "Ne peut convertir les liens dans %s: %s\n"
 
-#: src/url.c:1368
-#, fuzzy, c-format
+#: src/url.c:1365
 msgid "Unable to delete `%s': %s\n"
-msgstr "Échec de `unlink' sur le lien symbolique `%s': %s\n"
+msgstr "ÉCHEC de destruction de `%s': %s\n"
 
-#: src/url.c:1558
-#, fuzzy, c-format
+#: src/url.c:1555
+#, c-format
 msgid "Cannot back up %s as %s: %s\n"
-msgstr "Ne peut convertir les liens dans %s: %s\n"
+msgstr "Ne peut archiver %s comme %s: %s\n"
 
 #: src/utils.c:94
 #, c-format
 msgid "%s: %s: Not enough memory.\n"
 msgstr "%s: %s: mémoire épuisée.\n"
 
-#: src/utils.c:386
+#: src/utils.c:417
 msgid "Unknown/unsupported protocol"
 msgstr "Protocole inconnu ou non supporté"
 
-#: src/utils.c:389
+#: src/utils.c:420
 msgid "Invalid port specification"
 msgstr "Spécification du port erronée"
 
-#: src/utils.c:392
+#: src/utils.c:423
 msgid "Invalid host name"
 msgstr "Nom de l'hôte erroné"
 
-#: src/utils.c:613
+#: src/utils.c:620
 #, c-format
 msgid "Failed to unlink symlink `%s': %s\n"
-msgstr "Échec de `unlink' sur le lien symbolique `%s': %s\n"
+msgstr "ÉCHEC de `unlink' sur le lien symbolique `%s': %s\n"
+
+#~ msgid "%s: Cannot determine user-id.\n"
+#~ msgstr "%s: ne peut déterminer le UID de l'usager.\n"
+
+#~ msgid "%s: Warning: uname failed: %s\n"
+#~ msgstr "%s: AVERTISSEMENT: échec de `uname': %s\n"
+
+#~ msgid "%s: Warning: gethostname failed\n"
+#~ msgstr "%s: AVERTISSEMENT: échec de la fonction gethostname()\n"
+
+#~ msgid "%s: Warning: cannot determine local IP address.\n"
+#~ msgstr "%s: AVERTISSEMENT: ne peut déterminer l'adresse IP locale.\n"
+
+#~ msgid "%s: Warning: cannot reverse-lookup local IP address.\n"
+#~ msgstr "%s: AVERTISSEMENT: ne peut repérer l'adresse IP locale par requête inverse.\n"
+
+#~ msgid "%s: Warning: reverse-lookup of local address did not yield FQDN!\n"
+#~ msgstr "%s: AVERTISSEMENT: requête inverse de l'adresse IP locale n'est pas complétée par FQDN!\n"
 
-#, fuzzy
 #~ msgid "%s: Out of memory.\n"
-#~ msgstr "%s: %s: mémoire épuisée.\n"
+#~ msgstr "%s: mémoire épuisée.\n"
 
-#~ msgid ""
-#~ "Local file `%s' is more recent, not retrieving.\n"
-#~ "\n"
-#~ msgstr "Fichier local `%s' est plus récent, pas de récupération.\n"
+#~ msgid "%s: Redirection to itself.\n"
+#~ msgstr "%s: redirection vers lui-même.\n"
 
 #~ msgid "Error (%s): Link %s without a base provided.\n"
 #~ msgstr "ERREUR (%s): lien %s sans base fournie.\n"
 
 #~ msgid "Error (%s): Base %s relative, without referer URL.\n"
 #~ msgstr "ERREUR (%s): base %s relative, sans URL référent.\n"
+
+#~ msgid "Local file `%s' is more recent, not retrieving.\n\n"
+#~ msgstr "Fichier local `%s' est plus récent, pas de récupération.\n"
