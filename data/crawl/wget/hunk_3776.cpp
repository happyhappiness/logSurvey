 "Ponawianie pr�by.\n"
 "\n"
 
-#: src/url.c:983
-#, c-format
-msgid "Error (%s): Link %s without a base provided.\n"
-msgstr "B��d (%s): Odno�nik %s podany bez bazy.\n"
-
-#: src/url.c:999
-#, c-format
-msgid "Error (%s): Base %s relative, without referer URL.\n"
-msgstr "B��d (%s): Baza %s jest relatywna, bez odsy�aj�cego URLa.\n"
-
-#: src/url.c:1540
+#: src/url.c:1329
 #, c-format
 msgid "Converting %s... "
 msgstr "Konwertuj� %s... "
 
-#: src/url.c:1545 src/url.c:1632
+#: src/url.c:1342
+msgid "nothing to do.\n"
+msgstr ""
+
+#: src/url.c:1350 src/url.c:1374
 #, c-format
 msgid "Cannot convert links in %s: %s\n"
 msgstr "Nie mo�na skonwertowa� odno�nik�w w %s: %s\n"
 
-#: src/url.c:1608
+#: src/url.c:1365
+#, c-format
+msgid "Unable to delete `%s': %s\n"
+msgstr ""
+
+#: src/url.c:1555
 #, c-format
 msgid "Cannot back up %s as %s: %s\n"
 msgstr "Nie mo�na stworzy� kopii zapasowej %s jako %s: %s\n"
 
-#: src/utils.c:72
+#: src/utils.c:94
 #, c-format
 msgid "%s: %s: Not enough memory.\n"
 msgstr "%s: %s: Nie ma wystarczaj�cej ilo�ci pami�ci.\n"
 
-#: src/utils.c:204
+#: src/utils.c:386
 msgid "Unknown/unsupported protocol"
 msgstr "Nieznany/niewspierany protok�"
 
-#: src/utils.c:207
+#: src/utils.c:389
 msgid "Invalid port specification"
 msgstr "Nieprawid�owa specyfikacja portu"
 
-#: src/utils.c:210
+#: src/utils.c:392
 msgid "Invalid host name"
 msgstr "Nieprawid�owa nazwa hosta"
 
-#: src/utils.c:431
+#: src/utils.c:613
 #, c-format
 msgid "Failed to unlink symlink `%s': %s\n"
 msgstr "Nie uda�o sie usun�� dowi�zania symbolicznego `%s': %s\n"
 
+#~ msgid "%s: Redirection to itself.\n"
+#~ msgstr "%s: Przekierowanie do samego siebie.\n"
+
+#~ msgid "Error (%s): Link %s without a base provided.\n"
+#~ msgstr "B��d (%s): Odno�nik %s podany bez bazy.\n"
+
+#~ msgid "Error (%s): Base %s relative, without referer URL.\n"
+#~ msgstr "B��d (%s): Baza %s jest relatywna, bez odsy�aj�cego URLa.\n"
+
 #~ msgid ""
 #~ "Local file `%s' is more recent, not retrieving.\n"
 #~ "\n"
