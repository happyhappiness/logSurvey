 "Rinuncio.\n"
 "\n"
 
-#: src/retr.c:623
+#: src/retr.c:617
 msgid ""
 "Retrying.\n"
 "\n"
 msgstr ""
-"Ritento.\n"
+"Altro tentativo in corso.\n"
 "\n"
 
-#: src/url.c:1332
-#, c-format
-msgid "Converting %s... "
-msgstr "Converto %s... "
+#: src/url.c:621
+msgid "No error"
+msgstr "Nessun errore"
 
-#: src/url.c:1345
-msgid "nothing to do.\n"
-msgstr ""
+#: src/url.c:623
+msgid "Unsupported scheme"
+msgstr "Schema non supportato"
 
-#: src/url.c:1353 src/url.c:1377
-#, c-format
-msgid "Cannot convert links in %s: %s\n"
-msgstr "Non riesco a convertire i link in %s: %s\n"
-
-#: src/url.c:1368
-#, fuzzy, c-format
-msgid "Unable to delete `%s': %s\n"
-msgstr "Non riesco a rimuovere il link simbolico `%s': %s\n"
+#: src/url.c:625
+msgid "Empty host"
+msgstr "Host vuoto"
 
-#: src/url.c:1558
-#, fuzzy, c-format
-msgid "Cannot back up %s as %s: %s\n"
-msgstr "Non riesco a convertire i link in %s: %s\n"
+#: src/url.c:627
+msgid "Bad port number"
+msgstr "Numero di porta non valido"
 
-#: src/utils.c:94
-#, c-format
-msgid "%s: %s: Not enough memory.\n"
-msgstr "%s: %s: Memoria insufficiente.\n"
+#: src/url.c:629
+msgid "Invalid user name"
+msgstr "Nome utente non valido"
 
-#: src/utils.c:386
-msgid "Unknown/unsupported protocol"
-msgstr "Protocollo sconosciuto/non supportato"
+#: src/url.c:631
+msgid "Unterminated IPv6 numeric address"
+msgstr "Indirizzo numerico IPv6 non terminato"
 
-#: src/utils.c:389
-msgid "Invalid port specification"
-msgstr "Porta specificata non valida"
+#: src/url.c:633
+msgid "IPv6 addresses not supported"
+msgstr "Indirizzo IPv6 non supportato"
 
-#: src/utils.c:392
-msgid "Invalid host name"
-msgstr "Nome host non valido"
+#: src/url.c:635
+msgid "Invalid IPv6 numeric address"
+msgstr "Indirizzo numerico IPv6 non valido"
 
-#: src/utils.c:613
+#: src/utils.c:120
 #, c-format
-msgid "Failed to unlink symlink `%s': %s\n"
-msgstr "Non riesco a rimuovere il link simbolico `%s': %s\n"
-
-#, fuzzy
-#~ msgid "%s: Out of memory.\n"
-#~ msgstr "%s: %s: Memoria insufficiente.\n"
-
-#~ msgid ""
-#~ "Local file `%s' is more recent, not retrieving.\n"
-#~ "\n"
-#~ msgstr ""
-#~ "Il file locale `%s' è più recente, non lo scarico.\n"
-#~ "\n"
+msgid "%s: %s: Not enough memory.\n"
+msgstr "%s: %s: memoria insufficiente.\n"
 
-#~ msgid "Error (%s): Link %s without a base provided.\n"
-#~ msgstr "Errore (%s): Link %s fornito senza una base.\n"
+#. parent, no error
+#: src/utils.c:485
+#, c-format
+msgid "Continuing in background, pid %d.\n"
+msgstr "Continuo in background, pid %d.\n"
 
-#~ msgid "Error (%s): Base %s relative, without referer URL.\n"
-#~ msgstr "Errore (%s): Base %s relativa, senza URL di riferimento\n"
+#: src/utils.c:529
+#, c-format
+msgid "Failed to unlink symlink `%s': %s\n"
+msgstr "Rimozione del link simbolico \"%s\" non riuscita: %s\n"
