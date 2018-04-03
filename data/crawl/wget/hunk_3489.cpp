 msgid "%s: option requires an argument -- %c\n"
 msgstr "%s: l'option requiert le paramètre -- %c\n"
 
-#: src/host.c:374
+#: src/host.c:251
+msgid "Resolving %s... "
+msgstr "Résolution de %s... "
+
+#: src/host.c:258
+#, c-format
+msgid "failed: %s.\n"
+msgstr "échec: %s.\n"
+
+#: src/host.c:326
 msgid "Host not found"
 msgstr "Hôte non repéré"
 
-#: src/host.c:376
+#: src/host.c:328
 msgid "Unknown error"
 msgstr "ERREUR inconnue"
 
 #. this is fatal
-#: src/http.c:555
+#: src/http.c:584
 msgid "Failed to set up an SSL context\n"
 msgstr "ÉCHEC d'initialisation du contexte SSL\n"
 
-#: src/http.c:561
+#: src/http.c:590
 #, c-format
 msgid "Failed to load certificates from %s\n"
 msgstr "ÉCHEC de chargement des certificats de %s\n"
 
-#: src/http.c:565 src/http.c:573
+#: src/http.c:594 src/http.c:602
 msgid "Trying without the specified certificate\n"
 msgstr "Essai sans le certificat spécifié\n"
 
-#: src/http.c:569
+#: src/http.c:598
 #, c-format
 msgid "Failed to get certificate key from %s\n"
 msgstr "ÉCHEC d'obtention de la clé du certificat de %s\n"
 
-#: src/http.c:663 src/http.c:1593
+#: src/http.c:668 src/http.c:1631
 msgid "Unable to establish SSL connection.\n"
 msgstr "Incapable d'établir une connexion SSL.\n"
 
-#: src/http.c:671
+#: src/http.c:677
+#, c-format
 msgid "Reusing connection to %s:%hu.\n"
 msgstr "Réutilisation de la connexion vers %s:%hu.\n"
 
-#: src/http.c:861
+#: src/http.c:879
+#, c-format
 msgid "Failed writing HTTP request: %s.\n"
 msgstr "ÉCHEC d'écriture de la requête HTTP: %s.\n"
 
-#: src/http.c:866
+#: src/http.c:884
 #, c-format
 msgid "%s request sent, awaiting response... "
 msgstr "requête %s transmise, en attente de la réponse..."
 
-#: src/http.c:910
+#: src/http.c:928
 msgid "End of file while parsing headers.\n"
 msgstr "Fin de fichier lors de l'analyse du l'en-tête.\n"
 
-#: src/http.c:920
+#: src/http.c:938
 #, c-format
 msgid "Read error (%s) in headers.\n"
 msgstr "ERREUR de lecture (%s) de l'en-tête.\n"
 
-#: src/http.c:959
+#: src/http.c:973
 msgid "No data received"
 msgstr "Aucune donnée reçue"
 
-#: src/http.c:961
+#: src/http.c:975
 msgid "Malformed status line"
 msgstr "Ligne d'état mal composée"
 
-#: src/http.c:966
+#: src/http.c:980
 msgid "(no description)"
 msgstr "(pas de description)"
 
-#: src/http.c:1089
+#: src/http.c:1112
 msgid "Authorization failed.\n"
 msgstr "ÉCHEC d'autorisation.\n"
 
-#: src/http.c:1096
+#: src/http.c:1119
 msgid "Unknown authentication scheme.\n"
 msgstr "Schème inconnu d'authentification.\n"
 
-#: src/http.c:1136
+#: src/http.c:1159
 #, c-format
 msgid "Location: %s%s\n"
 msgstr "Location: %s%s\n"
 
-#: src/http.c:1137 src/http.c:1269
+#: src/http.c:1160 src/http.c:1293
 msgid "unspecified"
 msgstr "non spécifié"
 
-#: src/http.c:1138
+#: src/http.c:1161
 msgid " [following]"
 msgstr " [suivant]"
 
-#: src/http.c:1200
+#: src/http.c:1224
 msgid "\n    The file is already fully retrieved; nothing to do.\n\n"
 msgstr "\n    Le fichier a déjà été complètement récupéré; rien à faire.\n\n"
 
-#: src/http.c:1216
+#: src/http.c:1240
 #, c-format
 msgid ""
 "\n"
