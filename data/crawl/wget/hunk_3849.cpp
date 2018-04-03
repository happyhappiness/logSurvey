 "Ponawiam prób?.\n"
 "\n"
 
-#: src/url.c:983
-#, c-format
-msgid "Error (%s): Link %s without a base provided.\n"
-msgstr "B??d (%s): ??cze %s zosta?o dostarczone bez bazy.\n"
-
-#: src/url.c:999
-#, c-format
-msgid "Error (%s): Base %s relative, without referer URL.\n"
-msgstr "B??d (%s): Baza %s jest wzgl?dna, bez odniesienia do URL'a.\n"
-
-#: src/url.c:1540
+#: src/url.c:1325
 #, c-format
 msgid "Converting %s... "
 msgstr "Konwersja %s... "
 
-#: src/url.c:1545 src/url.c:1632
+#: src/url.c:1338
+msgid "nothing to do.\n"
+msgstr ""
+
+#: src/url.c:1346 src/url.c:1370
 #, c-format
 msgid "Cannot convert links in %s: %s\n"
 msgstr "Nie mog? przekonwertowa? ??cza w %s: %s\n"
 
-#: src/url.c:1608
+#: src/url.c:1361
+#, fuzzy, c-format
+msgid "Unable to delete `%s': %s\n"
+msgstr "Od??czenie ??cza symbolicznego `%s' nie powiod?o si?: %s\n"
+
+#: src/url.c:1558
 #, fuzzy, c-format
 msgid "Cannot back up %s as %s: %s\n"
 msgstr "Nie mog? przekonwertowa? ??cza w %s: %s\n"
 
-#: src/utils.c:72
+#: src/utils.c:94
 #, c-format
 msgid "%s: %s: Not enough memory.\n"
 msgstr "%s: %s: Brak pami?ci.\n"
 
-#: src/utils.c:204
+#: src/utils.c:392
 msgid "Unknown/unsupported protocol"
 msgstr "Nieznany/nieobs?ugiwany protokó?"
 
-#: src/utils.c:207
+#: src/utils.c:395
 msgid "Invalid port specification"
 msgstr "Nieprawid?owa specyfikacja portu"
 
-#: src/utils.c:210
+#: src/utils.c:398
 msgid "Invalid host name"
 msgstr "Nieprawid?owa nazwa serwera"
 
-#: src/utils.c:431
+#: src/utils.c:619
 #, c-format
 msgid "Failed to unlink symlink `%s': %s\n"
 msgstr "Od??czenie ??cza symbolicznego `%s' nie powiod?o si?: %s\n"
 
+#~ msgid "%s: Redirection to itself.\n"
+#~ msgstr "%s: Przekierowanie na samego siebie.\n"
+
+#~ msgid "Error (%s): Link %s without a base provided.\n"
+#~ msgstr "B??d (%s): ??cze %s zosta?o dostarczone bez bazy.\n"
+
+#~ msgid "Error (%s): Base %s relative, without referer URL.\n"
+#~ msgstr "B??d (%s): Baza %s jest wzgl?dna, bez odniesienia do URL'a.\n"
+
 #~ msgid ""
 #~ "Local file `%s' is more recent, not retrieving.\n"
 #~ "\n"
