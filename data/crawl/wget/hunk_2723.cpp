 msgid "No headers, assuming HTTP/0.9"
 msgstr "Pas d'en-tête, HTTP/0.9 assumé"
 
-#: src/http.c:1198
+#: src/http.c:1204
 msgid "Disabling SSL due to encountered errors.\n"
 msgstr "Désactivation SSL en raison des erreurs rencontrés.\n"
 
-#: src/http.c:1417
+#: src/http.c:1374
 #, c-format
-msgid "Reusing existing connection to %s:%d.\n"
-msgstr "Réutilisation de la connexion existante vers %s:%d.\n"
+msgid "POST data file `%s' missing: %s\n"
+msgstr "Fichier de données POST `%s' est manquant: %s\n"
 
-#: src/http.c:1479
+#: src/http.c:1423
 #, c-format
-msgid "Failed writing to proxy: %s.\n"
-msgstr "ÉCHEC d'écriture vers le proxy: %s.\n"
+msgid "Reusing existing connection to %s:%d.\n"
+msgstr "Réutilisation de la connexion existante vers %s:%d.\n"
 
-#: src/http.c:1488
+#: src/http.c:1492
 #, c-format
 msgid "Failed reading proxy response: %s\n"
 msgstr "ÉCHEC de lecture de la réponse proxy: %s.\n"
 
-#: src/http.c:1508
+#: src/http.c:1512
 #, c-format
 msgid "Proxy tunneling failed: %s"
 msgstr "Échec du tunneling proxy: %s"
 
-#: src/http.c:1555
+#: src/http.c:1557
 #, c-format
 msgid "%s request sent, awaiting response... "
 msgstr "requête %s transmise, en attente de la réponse..."
 
-#: src/http.c:1566
+#: src/http.c:1568
 msgid "No data received.\n"
 msgstr "Aucune donnée reçue.\n"
 
-#: src/http.c:1573
+#: src/http.c:1575
 #, c-format
 msgid "Read error (%s) in headers.\n"
 msgstr "ERREUR de lecture (%s) de l'en-tête.\n"
 
 #. If the authentication header is missing or
 #. unrecognized, there's no sense in retrying.
-#: src/http.c:1658
+#: src/http.c:1660
 msgid "Unknown authentication scheme.\n"
 msgstr "Schème d'authentification inconnu.\n"
 
-#: src/http.c:1682
+#: src/http.c:1684
 msgid "Authorization failed.\n"
 msgstr "ÉCHEC d'autorisation.\n"
 
-#: src/http.c:1696
+#: src/http.c:1698
 msgid "Malformed status line"
 msgstr "Ligne d'état mal composée"
 
-#: src/http.c:1698
+#: src/http.c:1700
 msgid "(no description)"
 msgstr "(pas de description)"
 
-#: src/http.c:1769
+#: src/http.c:1763
 #, c-format
 msgid "Location: %s%s\n"
 msgstr "Emplacement: %s%s\n"
 
-#: src/http.c:1770 src/http.c:1867
+#: src/http.c:1764 src/http.c:1871
 msgid "unspecified"
 msgstr "non spécifié"
 
-#: src/http.c:1771
+#: src/http.c:1765
 msgid " [following]"
 msgstr " [suivant]"
 
 #. If `-c' is in use and the file has been fully downloaded (or
 #. the remote file has shrunk), Wget effectively requests bytes
 #. after the end of file and the server response with 416.
-#: src/http.c:1817
+#: src/http.c:1821
 msgid ""
 "\n"
 "    The file is already fully retrieved; nothing to do.\n"
