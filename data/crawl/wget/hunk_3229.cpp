 #. No luck.
 #. #### This message SUCKS.  We should see what was the
 #. reason that nothing was retrieved.
-#: src/ftp.c:1608
+#: src/ftp.c:1698
 #, c-format
 msgid "No matches on pattern `%s'.\n"
-msgstr "No hi ha res que s'ajusti al patró `%s'.\n"
+msgstr "Cap coincidència amb el patró `%s'.\n"
 
-#: src/ftp.c:1673
+#: src/ftp.c:1764
 #, c-format
 msgid "Wrote HTML-ized index to `%s' [%ld].\n"
-msgstr "S'ha escrit un índex amb HTML a `%s' [%ld].\n"
+msgstr "S'ha escrit un índex HTMLitzat a `%s' [%ld].\n"
 
-#: src/ftp.c:1678
+#: src/ftp.c:1769
 #, c-format
 msgid "Wrote HTML-ized index to `%s'.\n"
-msgstr "S'ha escrit un índex HTML a `%s'.\n"
+msgstr "S'ha escrit un índex HTMLitzat a `%s'.\n"
 
-#: src/gen_sslfunc.c:109
+#: src/gen_sslfunc.c:117
 msgid "Could not seed OpenSSL PRNG; disabling SSL.\n"
-msgstr "No es s'ha pogut alimentar el PRNG d'OpenSSL; deshabilitant SSL.\n"
+msgstr "No es s'ha pogut alimentar el PRNG d'OpenSSL; es deshabilita la SSL.\n"
 
-#: src/getopt.c:454
+#: src/getopt.c:675
 #, c-format
 msgid "%s: option `%s' is ambiguous\n"
-msgstr "%s: la opció `%s' és ambigua\n"
+msgstr "%s: l'opció `%s' és ambigua\n"
 
-#: src/getopt.c:478
+#: src/getopt.c:700
 #, c-format
 msgid "%s: option `--%s' doesn't allow an argument\n"
-msgstr "%s: la opció `--%s' no permet un argument\n"
+msgstr "%s: l'opció `--%s' no admet arguments\n"
 
-#: src/getopt.c:483
+#: src/getopt.c:705
 #, c-format
 msgid "%s: option `%c%s' doesn't allow an argument\n"
-msgstr "%s: la opció `%c%s' no permet un argument\n"
+msgstr "%s: l'opció `%c%s' no admet arguments\n"
 
-#: src/getopt.c:498
+#: src/getopt.c:723 src/getopt.c:896
 #, c-format
 msgid "%s: option `%s' requires an argument\n"
-msgstr "%s: la opció `%s' requereix un argument\n"
+msgstr "%s: l'opció `%s' requereix un argument\n"
 
 #. --option
-#: src/getopt.c:528
+#: src/getopt.c:752
 #, c-format
 msgid "%s: unrecognized option `--%s'\n"
 msgstr "%s: opció desconeguda `--%s'\n"
 
 #. +option or -option
-#: src/getopt.c:532
+#: src/getopt.c:756
 #, c-format
 msgid "%s: unrecognized option `%c%s'\n"
 msgstr "%s: opció desconeguda `%c%s'\n"
 
 #. 1003.2 specifies the format of this message.
-#: src/getopt.c:563
+#: src/getopt.c:782
 #, c-format
 msgid "%s: illegal option -- %c\n"
-msgstr "%s: opció no permesa -- %c\n"
+msgstr "%s: opció il·legal -- %c\n"
+
+#: src/getopt.c:785
+#, c-format
+msgid "%s: invalid option -- %c\n"
+msgstr "%s: opció no vàlida -- %c\n"
 
 #. 1003.2 specifies the format of this message.
-#: src/getopt.c:602
+#: src/getopt.c:815 src/getopt.c:945
 #, c-format
 msgid "%s: option requires an argument -- %c\n"
-msgstr "%s: aquesta opció requereix un argument -- %c\n"
+msgstr "%s: l'opció requereix un argument -- %c\n"
+
+#: src/getopt.c:862
+#, c-format
+msgid "%s: option `-W %s' is ambiguous\n"
+msgstr "%s: l'opció `-W %s' és ambigua\n"
+
+#: src/getopt.c:880
+#, c-format
+msgid "%s: option `-W %s' doesn't allow an argument\n"
+msgstr "%s: l'opció `-W %s' no admet arguments\n"
 
-#: src/host.c:268
+#: src/host.c:636
 #, c-format
 msgid "Resolving %s... "
 msgstr "Resolent %s... "
 
-#: src/host.c:275
+#: src/host.c:656 src/host.c:672
 #, c-format
 msgid "failed: %s.\n"
-msgstr "Fallat: %s.\n"
+msgstr "error: %s.\n"
 
-#: src/host.c:345
+#: src/host.c:674
+msgid "failed: timed out.\n"
+msgstr "error: temps esgotat.\n"
+
+#: src/host.c:762
 msgid "Host not found"
-msgstr "Oste no trobat"
+msgstr "No s'ha trobat el host"
 
-#: src/host.c:347
+#: src/host.c:764
 msgid "Unknown error"
-msgstr "Error desconegut"
+msgstr "Error no identificat"
+
+#: src/html-url.c:293
+#, c-format
+msgid "%s: Cannot resolve incomplete link %s.\n"
+msgstr "%s: No s'ha pogut resoldre l'enllaç incomplet %s.\n"
 
 #. this is fatal
-#: src/http.c:573
+#: src/http.c:674
 msgid "Failed to set up an SSL context\n"
-msgstr "S'ha fallat al intentar fixar un context SSL\n"
+msgstr "No s'ha pogut establir un context SSL\n"
 
-#: src/http.c:579
+#: src/http.c:680
 #, c-format
 msgid "Failed to load certificates from %s\n"
-msgstr "S'ha fallat al intentar carregar els certificats des de %s\n"
+msgstr "No s'han pogut carregar els certificats de %s\n"
 
-#: src/http.c:583 src/http.c:591
+#: src/http.c:684 src/http.c:692
 msgid "Trying without the specified certificate\n"
-msgstr "Probant sense el certificat especificat\n"
+msgstr "S'intenta sense el certificat especificat\n"
 
-#: src/http.c:587
+#: src/http.c:688
 #, c-format
 msgid "Failed to get certificate key from %s\n"
-msgstr "S'ha fallat al intentar conseguir la clau del certificat des de %s\n"
+msgstr "No s'ha pogut obtenir la clau del certificat de %s\n"
 
-#: src/http.c:657 src/http.c:1620
+#: src/http.c:761 src/http.c:1809
 msgid "Unable to establish SSL connection.\n"
-msgstr "No es pot establir una conexió SSL.\n"
+msgstr "No s'ha pogut establir la connexió SSL.\n"
 
-#: src/http.c:666
+#: src/http.c:770
 #, c-format
 msgid "Reusing connection to %s:%hu.\n"
-msgstr "S'està reutilitzant la conexió a %s:%hu.\n"
+msgstr "Reutilitzant la connexió amb %s:%hu.\n"
 
-#: src/http.c:868
+#: src/http.c:1034
 #, c-format
 msgid "Failed writing HTTP request: %s.\n"
-msgstr "Ha fallat al escriure la petició HTTP: %s.\n"
+msgstr "Error escrivint la petició HTTP: %s.\n"
 
-#: src/http.c:873
+#: src/http.c:1039
 #, c-format
 msgid "%s request sent, awaiting response... "
-msgstr "%s: Petició enviada, esperant resposta... "
+msgstr "%s: petició enviada, esperant resposta... "
 
-#: src/http.c:917
+#: src/http.c:1083
 msgid "End of file while parsing headers.\n"
-msgstr "Fi del arxiu al parsejar les capçaleres.\n"
+msgstr "Final de fitxer mentre s'analitzaven les capçaleres.\n"
 
-#: src/http.c:927
+#: src/http.c:1093
 #, c-format
 msgid "Read error (%s) in headers.\n"
-msgstr "Error de lectura (%s) a les capçaleres.\n"
+msgstr "Error en llegir les capçaleres (%s).\n"
 
-#: src/http.c:962
+#: src/http.c:1128
 msgid "No data received"
-msgstr "No s'han rebut dades"
+msgstr "No s'ha rebut cap dada"
 
-#: src/http.c:964
+#: src/http.c:1130
 msgid "Malformed status line"
-msgstr "línia de estat mal formada"
+msgstr "Línia d'estat mal formada"
 
-#: src/http.c:969
+#: src/http.c:1135
 msgid "(no description)"
 msgstr "(sense descripció)"
 
-#: src/http.c:1101
+#: src/http.c:1267
 msgid "Authorization failed.\n"
 msgstr "Autorització fallida.\n"
 
-#: src/http.c:1108
+#: src/http.c:1274
 msgid "Unknown authentication scheme.\n"
-msgstr "Métode de autentificació desconeguda.\n"
+msgstr "Mètode d'autentificació desconegut.\n"
 
-#: src/http.c:1148
+#: src/http.c:1314
 #, c-format
 msgid "Location: %s%s\n"
-msgstr "Localització: %s%s\n"
+msgstr "Ubicació: %s%s\n"
 
-#: src/http.c:1149 src/http.c:1282
+# és femení: ubicació/mida. eac
+#: src/http.c:1315 src/http.c:1454
 msgid "unspecified"
-msgstr "no especificat"
+msgstr "no especificada"
 
-#: src/http.c:1150
+#: src/http.c:1316
 msgid " [following]"
-msgstr " [el següent]"
+msgstr " [seguint]"
 
-#: src/http.c:1213
-msgid "\n    The file is already fully retrieved; nothing to do.\n\n"
-msgstr "\n    L'arxiu següent està descarregat totalment; res a fer.\n\n"
+#: src/http.c:1383
+msgid ""
+"\n"
+"    The file is already fully retrieved; nothing to do.\n"
+"\n"
+msgstr ""
+"\n"
+"    El fitxer ja s'ha descarregat totalment; res a fer.\n"
+"\n"
 
-#: src/http.c:1229
-#, c-format
+#: src/http.c:1401
+#, fuzzy, c-format
 msgid ""
 "\n"
 "Continued download failed on this file, which conflicts with `-c'.\n"
