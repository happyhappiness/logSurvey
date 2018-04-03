 "Продолжение попыток.\n"
 "\n"
 
-#: src/url.c:983
-#, c-format
-msgid "Error (%s): Link %s without a base provided.\n"
-msgstr "Ошибка (%s): Ссылка %s без базового адреса.\n"
-
-#: src/url.c:999
-#, c-format
-msgid "Error (%s): Base %s relative, without referer URL.\n"
-msgstr "Ошибка (%s): Базовый адрес %s относителен, URL не определен.\n"
-
-#: src/url.c:1540
+#: src/url.c:1325
 #, c-format
 msgid "Converting %s... "
 msgstr "Преобразование %s... "
 
-#: src/url.c:1545 src/url.c:1632
+#: src/url.c:1338
+msgid "nothing to do.\n"
+msgstr ""
+
+#: src/url.c:1346 src/url.c:1370
 #, c-format
 msgid "Cannot convert links in %s: %s\n"
 msgstr "Не удается преобразовать ссылки в %s: %s\n"
 
-#: src/url.c:1608
+#: src/url.c:1361
+#, fuzzy, c-format
+msgid "Unable to delete `%s': %s\n"
+msgstr "Ошибка удаления символьной ссылки `%s': %s\n"
+
+#: src/url.c:1558
 #, c-format
 msgid "Cannot back up %s as %s: %s\n"
 msgstr "Не удается сохранить %s под именем %s: %s\n"
 
-#: src/utils.c:72
+#: src/utils.c:94
 #, c-format
 msgid "%s: %s: Not enough memory.\n"
 msgstr "%s: %s: Недостаточно памяти.\n"
 
-#: src/utils.c:204
+#: src/utils.c:392
 msgid "Unknown/unsupported protocol"
 msgstr "Протокол неизвестен или не поддерживается"
 
-#: src/utils.c:207
+#: src/utils.c:395
 msgid "Invalid port specification"
 msgstr "Указание недопустимого порта"
 
-#: src/utils.c:210
+#: src/utils.c:398
 msgid "Invalid host name"
 msgstr "Недопустимое имя машины (hostname)"
 
-#: src/utils.c:431
+#: src/utils.c:619
 #, c-format
 msgid "Failed to unlink symlink `%s': %s\n"
 msgstr "Ошибка удаления символьной ссылки `%s': %s\n"
+
+#~ msgid "%s: Redirection to itself.\n"
+#~ msgstr "%s: Перенаправление на самого себя.\n"
+
+#~ msgid "Error (%s): Link %s without a base provided.\n"
+#~ msgstr "Ошибка (%s): Ссылка %s без базового адреса.\n"
+
+#~ msgid "Error (%s): Base %s relative, without referer URL.\n"
+#~ msgstr "Ошибка (%s): Базовый адрес %s относителен, URL не определен.\n"
