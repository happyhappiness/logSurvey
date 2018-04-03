 msgid "%s: Couldn't find usable socket driver.\n"
 msgstr "%s: Non riesco a trovare un driver utilizzabile per i socket.\n"
 
-#: src/netrc.c:334
+#: src/netrc.c:367
 #, c-format
 msgid "%s: %s:%d: warning: \"%s\" token appears before any machine name\n"
-msgstr "%s: %s:%d: attenzione: il token \"%s\" appare prima di un nome di macchina\n"
+msgstr ""
+"%s: %s:%d: attenzione: il token \"%s\" appare prima di un nome di macchina\n"
 
-#: src/netrc.c:365
+#: src/netrc.c:398
 #, c-format
 msgid "%s: %s:%d: unknown token \"%s\"\n"
 msgstr "%s: %s:%d:  token \"%s\" sconosciuto\n"
 
-#: src/netrc.c:429
+#: src/netrc.c:462
 #, c-format
 msgid "Usage: %s NETRC [HOSTNAME]\n"
 msgstr "Uso: %s NETRC [HOSTNAME]\n"
 
-#: src/netrc.c:439
+#: src/netrc.c:472
 #, c-format
 msgid "%s: cannot stat %s: %s\n"
 msgstr "%s: stat su %s fallita: %s\n"
 
-#: src/recur.c:449 src/retr.c:462
-#, c-format
-msgid "Removing %s.\n"
-msgstr "Rimuovo %s.\n"
-
-#: src/recur.c:450
+#: src/recur.c:506
 #, c-format
 msgid "Removing %s since it should be rejected.\n"
 msgstr "Rimuovo %s poiché deve essere rifiutato.\n"
 
-#: src/recur.c:609
+#: src/recur.c:680
 msgid "Loading robots.txt; please ignore errors.\n"
 msgstr "Carico robots.txt; si ignorino eventuali errori.\n"
 
-#: src/retr.c:193
+#: src/retr.c:217
 #, c-format
-msgid "\n          [ skipping %dK ]"
-msgstr "\n         [ salto %dK ]"
+msgid ""
+"\n"
+"          [ skipping %dK ]"
+msgstr ""
+"\n"
+"         [ salto %dK ]"
 
-#: src/retr.c:344
+#: src/retr.c:399
 msgid "Could not find proxy host.\n"
 msgstr "Non riesco a trovare il proxy host.\n"
 
-#: src/retr.c:355
+#: src/retr.c:413
 #, c-format
 msgid "Proxy %s: Must be HTTP.\n"
 msgstr "Proxy %s: Deve essere HTTP.\n"
 
-#: src/retr.c:398
-#, c-format
-msgid "%s: Redirection to itself.\n"
+#: src/retr.c:507
+#, fuzzy, c-format
+msgid "%s: Redirection cycle detected.\n"
 msgstr "%s: Redirezione su se stesso.\n"
 
-#: src/retr.c:483
-msgid "Giving up.\n\n"
-msgstr "Rinuncio.\n\n"
-
-#: src/retr.c:483
-msgid "Retrying.\n\n"
-msgstr "Ritento.\n\n"
-
-#: src/url.c:940
-#, c-format
-msgid "Error (%s): Link %s without a base provided.\n"
-msgstr "Errore (%s): Link %s fornito senza una base.\n"
+#: src/retr.c:601
+msgid ""
+"Giving up.\n"
+"\n"
+msgstr ""
+"Rinuncio.\n"
+"\n"
 
-#: src/url.c:955
-#, c-format
-msgid "Error (%s): Base %s relative, without referer URL.\n"
-msgstr "Errore (%s): Base %s relativa, senza URL di riferimento\n"
+#: src/retr.c:601
+msgid ""
+"Retrying.\n"
+"\n"
+msgstr ""
+"Ritento.\n"
+"\n"
 
-#: src/url.c:1373
+#: src/url.c:1325
 #, c-format
 msgid "Converting %s... "
 msgstr "Converto %s... "
 
-#: src/url.c:1378 src/url.c:1389
+#: src/url.c:1338
+msgid "nothing to do.\n"
+msgstr ""
+
+#: src/url.c:1346 src/url.c:1370
 #, c-format
 msgid "Cannot convert links in %s: %s\n"
 msgstr "Non riesco a convertire i link in %s: %s\n"
 
-#: src/utils.c:71
+#: src/url.c:1361
+#, fuzzy, c-format
+msgid "Unable to delete `%s': %s\n"
+msgstr "Non riesco a rimuovere il link simbolico `%s': %s\n"
+
+#: src/url.c:1558
+#, fuzzy, c-format
+msgid "Cannot back up %s as %s: %s\n"
+msgstr "Non riesco a convertire i link in %s: %s\n"
+
+#: src/utils.c:94
 #, c-format
 msgid "%s: %s: Not enough memory.\n"
 msgstr "%s: %s: Memoria insufficiente.\n"
 
-#: src/utils.c:203
+#: src/utils.c:392
 msgid "Unknown/unsupported protocol"
 msgstr "Protocollo sconosciuto/non supportato"
 
-#: src/utils.c:206
+#: src/utils.c:395
 msgid "Invalid port specification"
 msgstr "Porta specificata non valida"
 
-#: src/utils.c:209
+#: src/utils.c:398
 msgid "Invalid host name"
 msgstr "Nome host non valido"
 
-#: src/utils.c:430
+#: src/utils.c:619
 #, c-format
 msgid "Failed to unlink symlink `%s': %s\n"
 msgstr "Non riesco a rimuovere il link simbolico `%s': %s\n"
+
+#~ msgid ""
+#~ "Local file `%s' is more recent, not retrieving.\n"
+#~ "\n"
+#~ msgstr ""
+#~ "Il file locale `%s' è più recente, non lo scarico.\n"
+#~ "\n"
+
+#~ msgid "Error (%s): Link %s without a base provided.\n"
+#~ msgstr "Errore (%s): Link %s fornito senza una base.\n"
+
+#~ msgid "Error (%s): Base %s relative, without referer URL.\n"
+#~ msgstr "Errore (%s): Base %s relativa, senza URL di riferimento\n"
