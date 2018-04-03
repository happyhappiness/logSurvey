 msgid "Failed writing HTTP request: %s.\n"
 msgstr "Сбой записи запроса HTTP: %s.\n"
 
-#: src/http.c:737
+#: src/http.c:745
 msgid "No headers, assuming HTTP/0.9"
 msgstr "Заголовки отсутствуют, подразумевается HTTP/0.9"
 
-#: src/http.c:1417
+#: src/http.c:1430
 msgid "Disabling SSL due to encountered errors.\n"
 msgstr "SSL отключается из-за непредвиденных ошибок.\n"
 
-#: src/http.c:1570
-#, c-format
-msgid "POST data file `%s' missing: %s\n"
+#: src/http.c:1548
+#, fuzzy, c-format
+msgid "POST data file %s missing: %s\n"
 msgstr "Отсутствует файл POST-данных `%s': %s\n"
 
-#: src/http.c:1619
+#: src/http.c:1632
 #, c-format
 msgid "Reusing existing connection to %s:%d.\n"
 msgstr "Повторное использование соединения с %s:%d.\n"
 
-#: src/http.c:1687
+#: src/http.c:1701
 #, c-format
 msgid "Failed reading proxy response: %s\n"
 msgstr "Сбой чтения ответа прокси: %s.\n"
 
-#: src/http.c:1707
+#: src/http.c:1721
 #, c-format
 msgid "Proxy tunneling failed: %s"
 msgstr "Сбой туннелирования прокси: %s"
 
-#: src/http.c:1752
+#: src/http.c:1766
 #, c-format
 msgid "%s request sent, awaiting response... "
 msgstr "Запрос %s послан, ожидается ответ... "
 
-#: src/http.c:1763
+#: src/http.c:1777
 msgid "No data received.\n"
 msgstr "Не получено никаких данных.\n"
 
-#: src/http.c:1770
+#: src/http.c:1784
 #, c-format
 msgid "Read error (%s) in headers.\n"
 msgstr "Ошибка чтения (%s) в заголовках.\n"
 
-#: src/http.c:1816 src/http.c:2368
-#, c-format
+#: src/http.c:1831 src/http.c:2385
+#, fuzzy, c-format
 msgid ""
-"File `%s' already there; not retrieving.\n"
+"File %s already there; not retrieving.\n"
 "\n"
 msgstr ""
 "Файл `%s' уже существует; не загружается.\n"
 "\n"
 
-#: src/http.c:1969
+#: src/http.c:1985
 msgid "Unknown authentication scheme.\n"
 msgstr "Неизвестная схема аутентификации.\n"
 
-#: src/http.c:2000
+#: src/http.c:2016
 msgid "Authorization failed.\n"
 msgstr "Сбой авторизации.\n"
 
-#: src/http.c:2014
+#: src/http.c:2030
 msgid "Malformed status line"
 msgstr "Неполная строка статуса"
 
-#: src/http.c:2016
+#: src/http.c:2032
 msgid "(no description)"
 msgstr "(нет описания)"
 
-#: src/http.c:2082
+#: src/http.c:2098
 #, c-format
 msgid "Location: %s%s\n"
 msgstr "Адрес: %s%s\n"
 
-#: src/http.c:2083 src/http.c:2193
+#: src/http.c:2099 src/http.c:2209
 msgid "unspecified"
 msgstr "нет информации"
 
-#: src/http.c:2084
+#: src/http.c:2100
 msgid " [following]"
 msgstr " [переход]"
 
-#: src/http.c:2140
+#: src/http.c:2156
 msgid ""
 "\n"
 "    The file is already fully retrieved; nothing to do.\n"
