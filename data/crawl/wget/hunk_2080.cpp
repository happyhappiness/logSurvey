 "Lien symbolique d�j� correct %s -> %s\n"
 "\n"
 
-#: src/ftp.c:1493
+#: src/ftp.c:1494
 #, c-format
 msgid "Creating symlink %s -> %s\n"
 msgstr "Cr�ation du lien symbolique %s -> %s\n"
 
-#: src/ftp.c:1503
+#: src/ftp.c:1504
 #, c-format
 msgid "Symlinks not supported, skipping symlink `%s'.\n"
 msgstr "Lien symbolique non support�, escamotage du lien � %s �.\n"
 
-#: src/ftp.c:1515
+#: src/ftp.c:1516
 #, c-format
 msgid "Skipping directory `%s'.\n"
 msgstr "R�pertoire � %s � escamot�.\n"
 
-#: src/ftp.c:1524
+#: src/ftp.c:1525
 #, c-format
 msgid "%s: unknown/unsupported file type.\n"
 msgstr "%s: type de fichier inconnu ou non support�.\n"
 
-#: src/ftp.c:1551
+#: src/ftp.c:1552
 #, c-format
 msgid "%s: corrupt time-stamp.\n"
 msgstr "%s: tampon date-heure corrompu.\n"
 
-#: src/ftp.c:1579
+#: src/ftp.c:1580
 #, c-format
 msgid "Will not retrieve dirs since depth is %d (max %d).\n"
 msgstr ""
 "Les r�pertoires ne seront pas r�cup�r�s, la profondeur %d d�passe le maximum "
 "%d.\n"
 
-#: src/ftp.c:1629
+#: src/ftp.c:1630
 #, c-format
 msgid "Not descending to `%s' as it is excluded/not-included.\n"
 msgstr "%s n'a pas �t� parcouru puisqu'il est exclu ou non inclus.\n"
 
-#: src/ftp.c:1695 src/ftp.c:1709
+#: src/ftp.c:1696 src/ftp.c:1710
 #, c-format
 msgid "Rejecting `%s'.\n"
 msgstr "Rejet de � %s �.\n"
 
-#: src/ftp.c:1757
+#: src/ftp.c:1733
+#, fuzzy, c-format
+msgid "Error matching %s against %s: %s\n"
+msgstr "Ne peut �crire dans � %s �: %s\n"
+
+#: src/ftp.c:1774
 #, c-format
 msgid "No matches on pattern `%s'.\n"
 msgstr "Pas de concordance avec le patron � %s �.\n"
 
-#: src/ftp.c:1823
+#: src/ftp.c:1840
 #, c-format
 msgid "Wrote HTML-ized index to `%s' [%s].\n"
 msgstr "Index HTML-is� �crit dans � %s � [%s].\n"
 
-#: src/ftp.c:1828
+#: src/ftp.c:1845
 #, c-format
 msgid "Wrote HTML-ized index to `%s'.\n"
 msgstr "Index HTML-is� �crit dans � %s �.\n"
 
-#: src/host.c:347
+#: src/host.c:348
 msgid "Unknown host"
 msgstr "H�te inconnu"
 
-#: src/host.c:351
+#: src/host.c:352
 msgid "Temporary failure in name resolution"
 msgstr "?chec temporaire dans la r�solution du nom"
 
-#: src/host.c:353
+#: src/host.c:354
 msgid "Unknown error"
 msgstr "ERREUR inconnue"
 
-#: src/host.c:714
+#: src/host.c:715
 #, c-format
 msgid "Resolving %s... "
 msgstr "R�solution de %s... "
 
-#: src/host.c:761
+#: src/host.c:762
 msgid "failed: No IPv4/IPv6 addresses for host.\n"
 msgstr "�chec: pas d'adresses IPv4/IPv6 pour l'h�te.\n"
 
-#: src/host.c:784
+#: src/host.c:785
 msgid "failed: timed out.\n"
 msgstr "�chec: expiration de la minuterie\n"
 
-#: src/html-url.c:288
+#: src/html-url.c:289
 #, c-format
 msgid "%s: Cannot resolve incomplete link %s.\n"
 msgstr "%s: ne peut r�soudre le lien incomplet %s.\n"
 
-#: src/html-url.c:695
+#: src/html-url.c:696
 #, c-format
 msgid "%s: Invalid URL %s: %s\n"
 msgstr "%s: URL invalide %s: %s\n"
 
-#: src/http.c:367
+#: src/http.c:368
 #, c-format
 msgid "Failed writing HTTP request: %s.\n"
 msgstr "�CHEC d'�criture de la requ�te HTTP: %s.\n"
 
-#: src/http.c:736
+#: src/http.c:737
 msgid "No headers, assuming HTTP/0.9"
 msgstr "Pas d'en-t�te, HTTP/0.9 assum�"
 
-#: src/http.c:1413
+#: src/http.c:1417
 msgid "Disabling SSL due to encountered errors.\n"
 msgstr "D�sactivation SSL en raison des erreurs rencontr�s.\n"
 
-#: src/http.c:1566
+#: src/http.c:1570
 #, c-format
 msgid "POST data file `%s' missing: %s\n"
 msgstr "Fichier de donn�es POST `%s' est manquant: %s\n"
 
-#: src/http.c:1615
+#: src/http.c:1619
 #, c-format
 msgid "Reusing existing connection to %s:%d.\n"
 msgstr "R�utilisation de la connexion existante vers %s:%d.\n"
 
-#: src/http.c:1683
+#: src/http.c:1687
 #, c-format
 msgid "Failed reading proxy response: %s\n"
 msgstr "�CHEC de lecture de la r�ponse proxy: %s.\n"
 
-#: src/http.c:1703
+#: src/http.c:1707
 #, c-format
 msgid "Proxy tunneling failed: %s"
 msgstr "�chec du tunneling proxy: %s"
 
-#: src/http.c:1748
+#: src/http.c:1752
 #, c-format
 msgid "%s request sent, awaiting response... "
 msgstr "requ�te %s transmise, en attente de la r�ponse..."
 
-#: src/http.c:1759
+#: src/http.c:1763
 msgid "No data received.\n"
 msgstr "Aucune donn�e re�ue.\n"
 
-#: src/http.c:1766
+#: src/http.c:1770
 #, c-format
 msgid "Read error (%s) in headers.\n"
 msgstr "ERREUR de lecture (%s) de l'en-t�te.\n"
 
-#: src/http.c:1812
+#: src/http.c:1816 src/http.c:2368
 #, c-format
 msgid ""
 "File `%s' already there; not retrieving.\n"
