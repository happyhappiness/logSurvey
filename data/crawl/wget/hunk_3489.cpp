 msgid "%s: option requires an argument -- %c\n"
 msgstr "%s: l'option requiert le param�tre -- %c\n"
 
-#: src/host.c:374
+#: src/host.c:251
+msgid "Resolving %s... "
+msgstr "R�solution de %s... "
+
+#: src/host.c:258
+#, c-format
+msgid "failed: %s.\n"
+msgstr "�chec: %s.\n"
+
+#: src/host.c:326
 msgid "Host not found"
 msgstr "H�te non rep�r�"
 
-#: src/host.c:376
+#: src/host.c:328
 msgid "Unknown error"
 msgstr "ERREUR inconnue"
 
 #. this is fatal
-#: src/http.c:555
+#: src/http.c:584
 msgid "Failed to set up an SSL context\n"
 msgstr "�CHEC d'initialisation du contexte SSL\n"
 
-#: src/http.c:561
+#: src/http.c:590
 #, c-format
 msgid "Failed to load certificates from %s\n"
 msgstr "�CHEC de chargement des certificats de %s\n"
 
-#: src/http.c:565 src/http.c:573
+#: src/http.c:594 src/http.c:602
 msgid "Trying without the specified certificate\n"
 msgstr "Essai sans le certificat sp�cifi�\n"
 
-#: src/http.c:569
+#: src/http.c:598
 #, c-format
 msgid "Failed to get certificate key from %s\n"
 msgstr "�CHEC d'obtention de la cl� du certificat de %s\n"
 
-#: src/http.c:663 src/http.c:1593
+#: src/http.c:668 src/http.c:1631
 msgid "Unable to establish SSL connection.\n"
 msgstr "Incapable d'�tablir une connexion SSL.\n"
 
-#: src/http.c:671
+#: src/http.c:677
+#, c-format
 msgid "Reusing connection to %s:%hu.\n"
 msgstr "R�utilisation de la connexion vers %s:%hu.\n"
 
-#: src/http.c:861
+#: src/http.c:879
+#, c-format
 msgid "Failed writing HTTP request: %s.\n"
 msgstr "�CHEC d'�criture de la requ�te HTTP: %s.\n"
 
-#: src/http.c:866
+#: src/http.c:884
 #, c-format
 msgid "%s request sent, awaiting response... "
 msgstr "requ�te %s transmise, en attente de la r�ponse..."
 
-#: src/http.c:910
+#: src/http.c:928
 msgid "End of file while parsing headers.\n"
 msgstr "Fin de fichier lors de l'analyse du l'en-t�te.\n"
 
-#: src/http.c:920
+#: src/http.c:938
 #, c-format
 msgid "Read error (%s) in headers.\n"
 msgstr "ERREUR de lecture (%s) de l'en-t�te.\n"
 
-#: src/http.c:959
+#: src/http.c:973
 msgid "No data received"
 msgstr "Aucune donn�e re�ue"
 
-#: src/http.c:961
+#: src/http.c:975
 msgid "Malformed status line"
 msgstr "Ligne d'�tat mal compos�e"
 
-#: src/http.c:966
+#: src/http.c:980
 msgid "(no description)"
 msgstr "(pas de description)"
 
-#: src/http.c:1089
+#: src/http.c:1112
 msgid "Authorization failed.\n"
 msgstr "�CHEC d'autorisation.\n"
 
-#: src/http.c:1096
+#: src/http.c:1119
 msgid "Unknown authentication scheme.\n"
 msgstr "Sch�me inconnu d'authentification.\n"
 
-#: src/http.c:1136
+#: src/http.c:1159
 #, c-format
 msgid "Location: %s%s\n"
 msgstr "Location: %s%s\n"
 
-#: src/http.c:1137 src/http.c:1269
+#: src/http.c:1160 src/http.c:1293
 msgid "unspecified"
 msgstr "non sp�cifi�"
 
-#: src/http.c:1138
+#: src/http.c:1161
 msgid " [following]"
 msgstr " [suivant]"
 
-#: src/http.c:1200
+#: src/http.c:1224
 msgid "\n    The file is already fully retrieved; nothing to do.\n\n"
 msgstr "\n    Le fichier a d�j� �t� compl�tement r�cup�r�; rien � faire.\n\n"
 
-#: src/http.c:1216
+#: src/http.c:1240
 #, c-format
 msgid ""
 "\n"
