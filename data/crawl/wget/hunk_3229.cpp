 #. No luck.
 #. #### This message SUCKS.  We should see what was the
 #. reason that nothing was retrieved.
-#: src/ftp.c:1608
+#: src/ftp.c:1698
 #, c-format
 msgid "No matches on pattern `%s'.\n"
-msgstr "No hi ha res que s'ajusti al patr� `%s'.\n"
+msgstr "Cap coincid�ncia amb el patr� `%s'.\n"
 
-#: src/ftp.c:1673
+#: src/ftp.c:1764
 #, c-format
 msgid "Wrote HTML-ized index to `%s' [%ld].\n"
-msgstr "S'ha escrit un �ndex amb HTML a `%s' [%ld].\n"
+msgstr "S'ha escrit un �ndex HTMLitzat a `%s' [%ld].\n"
 
-#: src/ftp.c:1678
+#: src/ftp.c:1769
 #, c-format
 msgid "Wrote HTML-ized index to `%s'.\n"
-msgstr "S'ha escrit un �ndex HTML a `%s'.\n"
+msgstr "S'ha escrit un �ndex HTMLitzat a `%s'.\n"
 
-#: src/gen_sslfunc.c:109
+#: src/gen_sslfunc.c:117
 msgid "Could not seed OpenSSL PRNG; disabling SSL.\n"
-msgstr "No es s'ha pogut alimentar el PRNG d'OpenSSL; deshabilitant SSL.\n"
+msgstr "No es s'ha pogut alimentar el PRNG d'OpenSSL; es deshabilita la SSL.\n"
 
-#: src/getopt.c:454
+#: src/getopt.c:675
 #, c-format
 msgid "%s: option `%s' is ambiguous\n"
-msgstr "%s: la opci� `%s' �s ambigua\n"
+msgstr "%s: l'opci� `%s' �s ambigua\n"
 
-#: src/getopt.c:478
+#: src/getopt.c:700
 #, c-format
 msgid "%s: option `--%s' doesn't allow an argument\n"
-msgstr "%s: la opci� `--%s' no permet un argument\n"
+msgstr "%s: l'opci� `--%s' no admet arguments\n"
 
-#: src/getopt.c:483
+#: src/getopt.c:705
 #, c-format
 msgid "%s: option `%c%s' doesn't allow an argument\n"
-msgstr "%s: la opci� `%c%s' no permet un argument\n"
+msgstr "%s: l'opci� `%c%s' no admet arguments\n"
 
-#: src/getopt.c:498
+#: src/getopt.c:723 src/getopt.c:896
 #, c-format
 msgid "%s: option `%s' requires an argument\n"
-msgstr "%s: la opci� `%s' requereix un argument\n"
+msgstr "%s: l'opci� `%s' requereix un argument\n"
 
 #. --option
-#: src/getopt.c:528
+#: src/getopt.c:752
 #, c-format
 msgid "%s: unrecognized option `--%s'\n"
 msgstr "%s: opci� desconeguda `--%s'\n"
 
 #. +option or -option
-#: src/getopt.c:532
+#: src/getopt.c:756
 #, c-format
 msgid "%s: unrecognized option `%c%s'\n"
 msgstr "%s: opci� desconeguda `%c%s'\n"
 
 #. 1003.2 specifies the format of this message.
-#: src/getopt.c:563
+#: src/getopt.c:782
 #, c-format
 msgid "%s: illegal option -- %c\n"
-msgstr "%s: opci� no permesa -- %c\n"
+msgstr "%s: opci� il�legal -- %c\n"
+
+#: src/getopt.c:785
+#, c-format
+msgid "%s: invalid option -- %c\n"
+msgstr "%s: opci� no v�lida -- %c\n"
 
 #. 1003.2 specifies the format of this message.
-#: src/getopt.c:602
+#: src/getopt.c:815 src/getopt.c:945
 #, c-format
 msgid "%s: option requires an argument -- %c\n"
-msgstr "%s: aquesta opci� requereix un argument -- %c\n"
+msgstr "%s: l'opci� requereix un argument -- %c\n"
+
+#: src/getopt.c:862
+#, c-format
+msgid "%s: option `-W %s' is ambiguous\n"
+msgstr "%s: l'opci� `-W %s' �s ambigua\n"
+
+#: src/getopt.c:880
+#, c-format
+msgid "%s: option `-W %s' doesn't allow an argument\n"
+msgstr "%s: l'opci� `-W %s' no admet arguments\n"
 
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
+msgstr "%s: No s'ha pogut resoldre l'enlla� incomplet %s.\n"
 
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
-msgstr "No es pot establir una conexi� SSL.\n"
+msgstr "No s'ha pogut establir la connexi� SSL.\n"
 
-#: src/http.c:666
+#: src/http.c:770
 #, c-format
 msgid "Reusing connection to %s:%hu.\n"
-msgstr "S'est� reutilitzant la conexi� a %s:%hu.\n"
+msgstr "Reutilitzant la connexi� amb %s:%hu.\n"
 
-#: src/http.c:868
+#: src/http.c:1034
 #, c-format
 msgid "Failed writing HTTP request: %s.\n"
-msgstr "Ha fallat al escriure la petici� HTTP: %s.\n"
+msgstr "Error escrivint la petici� HTTP: %s.\n"
 
-#: src/http.c:873
+#: src/http.c:1039
 #, c-format
 msgid "%s request sent, awaiting response... "
-msgstr "%s: Petici� enviada, esperant resposta... "
+msgstr "%s: petici� enviada, esperant resposta... "
 
-#: src/http.c:917
+#: src/http.c:1083
 msgid "End of file while parsing headers.\n"
-msgstr "Fi del arxiu al parsejar les cap�aleres.\n"
+msgstr "Final de fitxer mentre s'analitzaven les cap�aleres.\n"
 
-#: src/http.c:927
+#: src/http.c:1093
 #, c-format
 msgid "Read error (%s) in headers.\n"
-msgstr "Error de lectura (%s) a les cap�aleres.\n"
+msgstr "Error en llegir les cap�aleres (%s).\n"
 
-#: src/http.c:962
+#: src/http.c:1128
 msgid "No data received"
-msgstr "No s'han rebut dades"
+msgstr "No s'ha rebut cap dada"
 
-#: src/http.c:964
+#: src/http.c:1130
 msgid "Malformed status line"
-msgstr "l�nia de estat mal formada"
+msgstr "L�nia d'estat mal formada"
 
-#: src/http.c:969
+#: src/http.c:1135
 msgid "(no description)"
 msgstr "(sense descripci�)"
 
-#: src/http.c:1101
+#: src/http.c:1267
 msgid "Authorization failed.\n"
 msgstr "Autoritzaci� fallida.\n"
 
-#: src/http.c:1108
+#: src/http.c:1274
 msgid "Unknown authentication scheme.\n"
-msgstr "M�tode de autentificaci� desconeguda.\n"
+msgstr "M�tode d'autentificaci� desconegut.\n"
 
-#: src/http.c:1148
+#: src/http.c:1314
 #, c-format
 msgid "Location: %s%s\n"
-msgstr "Localitzaci�: %s%s\n"
+msgstr "Ubicaci�: %s%s\n"
 
-#: src/http.c:1149 src/http.c:1282
+# �s femen�: ubicaci�/mida. eac
+#: src/http.c:1315 src/http.c:1454
 msgid "unspecified"
-msgstr "no especificat"
+msgstr "no especificada"
 
-#: src/http.c:1150
+#: src/http.c:1316
 msgid " [following]"
-msgstr " [el seg�ent]"
+msgstr " [seguint]"
 
-#: src/http.c:1213
-msgid "\n    The file is already fully retrieved; nothing to do.\n\n"
-msgstr "\n    L'arxiu seg�ent est� descarregat totalment; res a fer.\n\n"
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
