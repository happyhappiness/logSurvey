 msgid "%s: option requires an argument -- %c\n"
 msgstr "%s: параметру необх╕дний аргумент -- %c\n"
 
-#: src/host.c:374
+#: src/host.c:271
+#, c-format
+msgid "Resolving %s... "
+msgstr "Визначення ╕мен╕ %s... "
+
+#: src/host.c:278
+#, c-format
+msgid "failed: %s.\n"
+msgstr "невдача: %s.\n"
+
+#: src/host.c:348
 msgid "Host not found"
 msgstr "Хост не знайдено"
 
-#: src/host.c:376
+#: src/host.c:350
 msgid "Unknown error"
 msgstr "Нев╕дома помилка"
 
+#: src/html-url.c:336
+#, c-format
+msgid "%s: Cannot resolve incomplete link %s.\n"
+msgstr "%s: Не можу роз╕брати неповне посилання %s.\n"
+
 #. this is fatal
-#: src/http.c:555
+#: src/http.c:573
 msgid "Failed to set up an SSL context\n"
 msgstr "Не вдалося встановити SSL\n"
 
-#: src/http.c:561
+#: src/http.c:579
 #, c-format
 msgid "Failed to load certificates from %s\n"
 msgstr "Не вдалося завантажити сертиф╕кат з %s\n"
 
-#: src/http.c:565 src/http.c:573
+#: src/http.c:583 src/http.c:591
 msgid "Trying without the specified certificate\n"
 msgstr "Пробу╓мо без вказаного сертиф╕кату\n"
 
-#: src/http.c:569
+#: src/http.c:587
 #, c-format
 msgid "Failed to get certificate key from %s\n"
 msgstr "Невдалося отримати ключ-сертиф╕кат з %s\n"
 
-#: src/http.c:663 src/http.c:1593
+#: src/http.c:657 src/http.c:1620
 msgid "Unable to establish SSL connection.\n"
 msgstr "Не можу встановити SSL-з'╓днання.\n"
 
-#: src/http.c:671
+#: src/http.c:666
 #, c-format
 msgid "Reusing connection to %s:%hu.\n"
 msgstr "Повторне використання зв'язку з %s:%hu.\n"
 
-#: src/http.c:861
+#: src/http.c:868
 #, c-format
 msgid "Failed writing HTTP request: %s.\n"
 msgstr "Помилка запису HTTP-запиту: %s.\n"
 
-#: src/http.c:866
+#: src/http.c:873
 #, c-format
 msgid "%s request sent, awaiting response... "
 msgstr "%s-запит над╕слано, оч╕ку╓м в╕дпов╕д╕... "
 
-#: src/http.c:910
+#: src/http.c:917
 msgid "End of file while parsing headers.\n"
 msgstr "К╕нець файлу п╕д час синтаксичного розбору заголовк╕в.\n"
 
-#: src/http.c:920
+#: src/http.c:927
 #, c-format
 msgid "Read error (%s) in headers.\n"
 msgstr "Помилка читання в заголовках (%s).\n"
 
-#: src/http.c:959
+#: src/http.c:962
 msgid "No data received"
 msgstr "Не отримано даних"
 
-#: src/http.c:961
+#: src/http.c:964
 msgid "Malformed status line"
 msgstr "Несформований статусний рядок"
 
-#: src/http.c:966
+#: src/http.c:969
 msgid "(no description)"
 msgstr "(без опису)"
 
-#: src/http.c:1089
+#: src/http.c:1101
 msgid "Authorization failed.\n"
 msgstr "Авторизац╕я невдалася.\n"
 
-#: src/http.c:1096
+#: src/http.c:1108
 msgid "Unknown authentication scheme.\n"
 msgstr "Нев╕дома схема аутентиф╕кац╕╖.\n"
 
-#: src/http.c:1136
+#: src/http.c:1148
 #, c-format
 msgid "Location: %s%s\n"
 msgstr "Адресa: %s%s\n"
 
-#: src/http.c:1137 src/http.c:1269
+#: src/http.c:1149 src/http.c:1282
 msgid "unspecified"
 msgstr "не вказано"
 
-#: src/http.c:1138
+#: src/http.c:1150
 msgid " [following]"
 msgstr " [перех╕д]"
 
-#: src/http.c:1200
-msgid "\n    The file is already fully retrieved; nothing to do.\n\n"
-msgstr "\n    Файл вже повн╕стю завантажено; нема чого робити.\n\n"
+#: src/http.c:1213
+msgid ""
+"\n"
+"    The file is already fully retrieved; nothing to do.\n"
+"\n"
+msgstr ""
+"\n"
+"    Файл вже повн╕стю завантажено; нема чого робити.\n"
+"\n"
 
-#: src/http.c:1216
+#: src/http.c:1229
 #, c-format
 msgid ""
 "\n"
