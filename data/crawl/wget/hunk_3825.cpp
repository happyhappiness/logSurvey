 msgid "%s: Couldn't find usable socket driver.\n"
 msgstr "%s: ne repérer un pilote de socket utilisable.\n"
 
-#: src/netrc.c:334
+#: src/netrc.c:367
 #, c-format
 msgid "%s: %s:%d: warning: \"%s\" token appears before any machine name\n"
-msgstr "%s: %s:%d: AVERTISSEMENT: \"%s\" le jeton apparaît avant le nom d'une machine\n"
+msgstr ""
+"%s: %s:%d: AVERTISSEMENT: \"%s\" le jeton apparaît avant le nom d'une "
+"machine\n"
 
-#: src/netrc.c:365
+#: src/netrc.c:398
 #, c-format
 msgid "%s: %s:%d: unknown token \"%s\"\n"
 msgstr "%s: %s:%d: jeton inconnu \"%s\"\n"
 
-#: src/netrc.c:429
+#: src/netrc.c:462
 #, c-format
 msgid "Usage: %s NETRC [HOSTNAME]\n"
 msgstr "Usage: %s NETRC [HÔTE]\n"
 
-#: src/netrc.c:439
+#: src/netrc.c:472
 #, c-format
 msgid "%s: cannot stat %s: %s\n"
 msgstr "%s: ne peut évaluer par `stat' le fichier %s: %s\n"
 
-#: src/recur.c:449 src/retr.c:462
-#, c-format
-msgid "Removing %s.\n"
-msgstr "Destruction de %s.\n"
-
-#: src/recur.c:450
+#: src/recur.c:506
 #, c-format
 msgid "Removing %s since it should be rejected.\n"
 msgstr "Destruction de %s puiqu'il doit être rejeté.\n"
 
-#: src/recur.c:609
+#: src/recur.c:680
 msgid "Loading robots.txt; please ignore errors.\n"
 msgstr "Chargement de robots.txt; svp ignorer les erreurs.\n"
 
-#: src/retr.c:193
+#: src/retr.c:217
 #, c-format
-msgid "\n          [ skipping %dK ]"
-msgstr "\n          [ escamoté %dK ]"
+msgid ""
+"\n"
+"          [ skipping %dK ]"
+msgstr ""
+"\n"
+"          [ escamoté %dK ]"
 
-#: src/retr.c:344
+#: src/retr.c:399
 msgid "Could not find proxy host.\n"
 msgstr "Ne peut repérer un hôte proxy.\n"
 
-#: src/retr.c:355
+#: src/retr.c:413
 #, c-format
 msgid "Proxy %s: Must be HTTP.\n"
 msgstr "Proxy %s: doit être de type HTTP.\n"
 
-#: src/retr.c:398
-#, c-format
-msgid "%s: Redirection to itself.\n"
+#: src/retr.c:507
+#, fuzzy, c-format
+msgid "%s: Redirection cycle detected.\n"
 msgstr "%s: redirection vers lui-même.\n"
 
-#: src/retr.c:483
-msgid "Giving up.\n\n"
-msgstr "Abandon.\n\n"
-
-#: src/retr.c:483
-msgid "Retrying.\n\n"
-msgstr "Nouvel essai.\n\n"
-
-#: src/url.c:940
-#, c-format
-msgid "Error (%s): Link %s without a base provided.\n"
-msgstr "ERREUR (%s): lien %s sans base fournie.\n"
+#: src/retr.c:601
+msgid ""
+"Giving up.\n"
+"\n"
+msgstr ""
+"Abandon.\n"
+"\n"
 
-#: src/url.c:955
-#, c-format
-msgid "Error (%s): Base %s relative, without referer URL.\n"
-msgstr "ERREUR (%s): base %s relative, sans URL référent.\n"
+#: src/retr.c:601
+msgid ""
+"Retrying.\n"
+"\n"
+msgstr ""
+"Nouvel essai.\n"
+"\n"
 
-#: src/url.c:1373
+#: src/url.c:1325
 #, c-format
 msgid "Converting %s... "
 msgstr "Converstion de %s..."
 
-#: src/url.c:1378 src/url.c:1389
+#: src/url.c:1338
+msgid "nothing to do.\n"
+msgstr ""
+
+#: src/url.c:1346 src/url.c:1370
 #, c-format
 msgid "Cannot convert links in %s: %s\n"
 msgstr "Ne peut convertir les liens dans %s: %s\n"
 
-#: src/utils.c:71
+#: src/url.c:1361
+#, fuzzy, c-format
+msgid "Unable to delete `%s': %s\n"
+msgstr "Échec de `unlink' sur le lien symbolique `%s': %s\n"
+
+#: src/url.c:1558
+#, fuzzy, c-format
+msgid "Cannot back up %s as %s: %s\n"
+msgstr "Ne peut convertir les liens dans %s: %s\n"
+
+#: src/utils.c:94
 #, c-format
 msgid "%s: %s: Not enough memory.\n"
 msgstr "%s: %s: mémoire épuisée.\n"
 
-#: src/utils.c:203
+#: src/utils.c:392
 msgid "Unknown/unsupported protocol"
 msgstr "Protocole inconnu ou non supporté"
 
-#: src/utils.c:206
+#: src/utils.c:395
 msgid "Invalid port specification"
 msgstr "Spécification du port erronée"
 
-#: src/utils.c:209
+#: src/utils.c:398
 msgid "Invalid host name"
 msgstr "Nom de l'hôte erroné"
 
-#: src/utils.c:430
+#: src/utils.c:619
 #, c-format
 msgid "Failed to unlink symlink `%s': %s\n"
 msgstr "Échec de `unlink' sur le lien symbolique `%s': %s\n"
+
+#~ msgid ""
+#~ "Local file `%s' is more recent, not retrieving.\n"
+#~ "\n"
+#~ msgstr "Fichier local `%s' est plus récent, pas de récupération.\n"
+
+#~ msgid "Error (%s): Link %s without a base provided.\n"
+#~ msgstr "ERREUR (%s): lien %s sans base fournie.\n"
+
+#~ msgid "Error (%s): Base %s relative, without referer URL.\n"
+#~ msgstr "ERREUR (%s): base %s relative, sans URL référent.\n"
