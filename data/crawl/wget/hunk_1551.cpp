 msgid "Invalid IPv6 numeric address"
 msgstr "Кепскі адрас IPv6"
 
-#. parent, no error
-#: src/utils.c:328
+#: src/utils.c:104
 #, c-format
-msgid "Continuing in background, pid %d.\n"
-msgstr "Праца працягваецца ў тле, pid %d.\n"
+msgid "%s: %s: Failed to allocate enough memory; memory exhausted.\n"
+msgstr ""
 
-#: src/utils.c:376
+#: src/utils.c:110
 #, c-format
-msgid "Failed to unlink symlink `%s': %s\n"
-msgstr "Немагчыма выдаліць спасылку \"%s\": %s\n"
+msgid "%s: %s: Failed to allocate %ld bytes; memory exhausted.\n"
+msgstr ""
 
-#: src/xmalloc.c:63
+#: src/utils.c:242
 #, c-format
-msgid "%s: %s: Failed to allocate %ld bytes; memory exhausted.\n"
+msgid "%s: aprintf: text buffer is too big (%ld bytes), aborting.\n"
 msgstr ""
 
+#: src/utils.c:375
+#, c-format
+msgid "Continuing in background, pid %d.\n"
+msgstr "Праца працягваецца ў тле, pid %d.\n"
+
+#: src/utils.c:423
+#, fuzzy, c-format
+msgid "Failed to unlink symlink %s: %s\n"
+msgstr "Немагчыма выдаліць спасылку \"%s\": %s\n"
+
 #~ msgid "Error in Set-Cookie, field `%s'"
 #~ msgstr "Памылка ў Set-Cookie, поле \"%s\""
 
