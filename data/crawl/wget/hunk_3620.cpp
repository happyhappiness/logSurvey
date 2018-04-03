 msgid "%s: cannot stat %s: %s\n"
 msgstr "%s: ne peut �valuer par `stat' le fichier %s: %s\n"
 
-#: src/recur.c:510
+#: src/recur.c:484
 #, c-format
 msgid "Removing %s since it should be rejected.\n"
 msgstr "Destruction de %s puiqu'il doit �tre rejet�.\n"
 
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
-"          [ escamot� %dK ]"
+msgid "\n          [ skipping %dK ]"
+msgstr "\n          [ escamot� %dK ]"
 
-#: src/retr.c:421
+#: src/retr.c:373
 msgid "Could not find proxy host.\n"
 msgstr "Ne peut rep�rer un h�te proxy.\n"
 
-#: src/retr.c:435
+#: src/retr.c:387
 #, c-format
 msgid "Proxy %s: Must be HTTP.\n"
 msgstr "Proxy %s: doit �tre de type HTTP.\n"
 
-#: src/retr.c:529
-#, fuzzy, c-format
+#: src/retr.c:481
+#, c-format
 msgid "%s: Redirection cycle detected.\n"
-msgstr "%s: redirection vers lui-m�me.\n"
+msgstr "%s: boucle de redirection d�tect�e.\n"
 
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
+msgstr "rien � faire.\n"
 
-#: src/url.c:1353 src/url.c:1377
+#: src/url.c:1350 src/url.c:1374
 #, c-format
 msgid "Cannot convert links in %s: %s\n"
 msgstr "Ne peut convertir les liens dans %s: %s\n"
 
-#: src/url.c:1368
-#, fuzzy, c-format
+#: src/url.c:1365
 msgid "Unable to delete `%s': %s\n"
-msgstr "�chec de `unlink' sur le lien symbolique `%s': %s\n"
+msgstr "�CHEC de destruction de `%s': %s\n"
 
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
 msgstr "%s: %s: m�moire �puis�e.\n"
 
-#: src/utils.c:386
+#: src/utils.c:417
 msgid "Unknown/unsupported protocol"
 msgstr "Protocole inconnu ou non support�"
 
-#: src/utils.c:389
+#: src/utils.c:420
 msgid "Invalid port specification"
 msgstr "Sp�cification du port erron�e"
 
-#: src/utils.c:392
+#: src/utils.c:423
 msgid "Invalid host name"
 msgstr "Nom de l'h�te erron�"
 
-#: src/utils.c:613
+#: src/utils.c:620
 #, c-format
 msgid "Failed to unlink symlink `%s': %s\n"
-msgstr "�chec de `unlink' sur le lien symbolique `%s': %s\n"
+msgstr "�CHEC de `unlink' sur le lien symbolique `%s': %s\n"
+
+#~ msgid "%s: Cannot determine user-id.\n"
+#~ msgstr "%s: ne peut d�terminer le UID de l'usager.\n"
+
+#~ msgid "%s: Warning: uname failed: %s\n"
+#~ msgstr "%s: AVERTISSEMENT: �chec de `uname': %s\n"
+
+#~ msgid "%s: Warning: gethostname failed\n"
+#~ msgstr "%s: AVERTISSEMENT: �chec de la fonction gethostname()\n"
+
+#~ msgid "%s: Warning: cannot determine local IP address.\n"
+#~ msgstr "%s: AVERTISSEMENT: ne peut d�terminer l'adresse IP locale.\n"
+
+#~ msgid "%s: Warning: cannot reverse-lookup local IP address.\n"
+#~ msgstr "%s: AVERTISSEMENT: ne peut rep�rer l'adresse IP locale par requ�te inverse.\n"
+
+#~ msgid "%s: Warning: reverse-lookup of local address did not yield FQDN!\n"
+#~ msgstr "%s: AVERTISSEMENT: requ�te inverse de l'adresse IP locale n'est pas compl�t�e par FQDN!\n"
 
-#, fuzzy
 #~ msgid "%s: Out of memory.\n"
-#~ msgstr "%s: %s: m�moire �puis�e.\n"
+#~ msgstr "%s: m�moire �puis�e.\n"
 
-#~ msgid ""
-#~ "Local file `%s' is more recent, not retrieving.\n"
-#~ "\n"
-#~ msgstr "Fichier local `%s' est plus r�cent, pas de r�cup�ration.\n"
+#~ msgid "%s: Redirection to itself.\n"
+#~ msgstr "%s: redirection vers lui-m�me.\n"
 
 #~ msgid "Error (%s): Link %s without a base provided.\n"
 #~ msgstr "ERREUR (%s): lien %s sans base fournie.\n"
 
 #~ msgid "Error (%s): Base %s relative, without referer URL.\n"
 #~ msgstr "ERREUR (%s): base %s relative, sans URL r�f�rent.\n"
+
+#~ msgid "Local file `%s' is more recent, not retrieving.\n\n"
+#~ msgstr "Fichier local `%s' est plus r�cent, pas de r�cup�ration.\n"
