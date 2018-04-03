 #. that there can be valid reasons for the local host
 #. name not to be an FQDN, so I've decided to remove the
 #. annoying warning.
-#: src/host.c:517
+#: src/host.c:473
 #, c-format
 msgid "%s: Warning: reverse-lookup of local address did not yield FQDN!\n"
 msgstr ""
 "%s: Предупреждение: при обратном преобразовании IP-адреса не получено FQDN!\n"
 
-#: src/host.c:545
+#: src/host.c:501
 msgid "Host not found"
 msgstr "Хост не найден"
 
-#: src/host.c:547
+#: src/host.c:503
 msgid "Unknown error"
 msgstr "Неизвестная ошибка"
 
-#: src/html.c:615 src/html.c:617
-#, c-format
-msgid "Index of /%s on %s:%d"
-msgstr "Листинг каталога /%s на %s:%d"
-
-#: src/html.c:639
-msgid "time unknown       "
-msgstr "время неизвестно   "
-
-#: src/html.c:643
-msgid "File        "
-msgstr "Файл        "
-
-#: src/html.c:646
-msgid "Directory   "
-msgstr "Каталог     "
-
-#: src/html.c:649
-msgid "Link        "
-msgstr "Ссылка      "
-
-#: src/html.c:652
-msgid "Not sure    "
-msgstr "Неизвестно  "
+#: src/http.c:621 src/http.c:1433
+msgid "Unable to establish SSL connection.\n"
+msgstr ""
 
-#: src/html.c:670
-#, c-format
-msgid " (%s bytes)"
-msgstr " (%s байт)"
+#: src/http.c:629
+#, fuzzy, c-format
+msgid "Reusing connection to %s:%hu.\n"
+msgstr "Попытки соединения с %s:%hu будут продолжены.\n"
 
-#: src/http.c:508
-msgid "Failed writing HTTP request.\n"
+#: src/http.c:805
+#, fuzzy, c-format
+msgid "Failed writing HTTP request: %s.\n"
 msgstr "Ошибка записи запроса HTTP.\n"
 
-#: src/http.c:512
+#: src/http.c:810
 #, c-format
 msgid "%s request sent, awaiting response... "
 msgstr "Запрос %s послан, ожидание ответа... "
 
-#: src/http.c:551
+#: src/http.c:854
 msgid "End of file while parsing headers.\n"
 msgstr "Конец файла во время разбора заголовков.\n"
 
-#: src/http.c:562
+#: src/http.c:865
 #, c-format
 msgid "Read error (%s) in headers.\n"
 msgstr "Ошибка чтения (%s) в заголовках.\n"
 
-#: src/http.c:602
+#: src/http.c:905
 msgid "No data received"
 msgstr "Не получено никаких данных"
 
-#: src/http.c:604
+#: src/http.c:907
 msgid "Malformed status line"
 msgstr "Неполная строка статуса"
 
-#: src/http.c:609
+#: src/http.c:912
 msgid "(no description)"
 msgstr "(нет описания)"
 
-#. If we have tried it already, then there is not point
-#. retrying it.
-#: src/http.c:693
+#: src/http.c:1030
 msgid "Authorization failed.\n"
 msgstr "Авторизация прошла неудачно.\n"
 
-#: src/http.c:700
+#: src/http.c:1037
 msgid "Unknown authentication scheme.\n"
 msgstr "Неизвестная схема проверки полномочий.\n"
 
-#: src/http.c:783
+#: src/http.c:1127
 #, c-format
 msgid "Location: %s%s\n"
 msgstr "Адрес: %s%s\n"
 
-#: src/http.c:784 src/http.c:809
+#: src/http.c:1128 src/http.c:1153
 msgid "unspecified"
 msgstr "нет информации"
 
-#: src/http.c:785
+#: src/http.c:1129
 msgid " [following]"
 msgstr " [переход]"
 
 #. No need to print this output if the body won't be
 #. downloaded at all, or if the original server response is
 #. printed.
-#: src/http.c:799
+#: src/http.c:1143
 msgid "Length: "
 msgstr "Длина: "
 
-#: src/http.c:804
+#: src/http.c:1148
 #, c-format
 msgid " (%s to go)"
 msgstr " (осталось %s)"
 
-#: src/http.c:809
+#: src/http.c:1153
 msgid "ignored"
 msgstr "игнорируется"
 
-#: src/http.c:912
+#: src/http.c:1254
 msgid "Warning: wildcards not supported in HTTP.\n"
 msgstr "Предупреждение: в HTTP шаблоны не поддерживаются.\n"
 
 #. If opt.noclobber is turned on and file already exists, do not
 #. retrieve the file
-#: src/http.c:933
+#: src/http.c:1275
 #, c-format
 msgid "File `%s' already there, will not retrieve.\n"
 msgstr "Файл `%s' уже существует, получение не производится.\n"
 
-#: src/http.c:1099
+#: src/http.c:1425
 #, c-format
 msgid "Cannot write to `%s' (%s).\n"
 msgstr "Ошибка записи в `%s' (%s).\n"
 
-#: src/http.c:1110
+#: src/http.c:1443
 #, c-format
 msgid "ERROR: Redirection (%d) without location.\n"
 msgstr "ОШИБКА: Перенаправление (%d) без указания адреса.\n"
 
-#: src/http.c:1135
+#: src/http.c:1468
 #, c-format
 msgid "%s ERROR %d: %s.\n"
 msgstr "%s ОШИБКА %d: %s.\n"
 
-#: src/http.c:1148
+#: src/http.c:1481
 msgid "Last-modified header missing -- time-stamps turned off.\n"
 msgstr "Нет заголовка last-modified -- временные отметки выключены.\n"
 
-#: src/http.c:1156
+#: src/http.c:1489
 msgid "Last-modified header invalid -- time-stamp ignored.\n"
 msgstr ""
 "Заголовок last-modified некорректен -- временные отметки игнорируются.\n"
 
-#: src/http.c:1191
+#: src/http.c:1524
 msgid "Remote file is newer, retrieving.\n"
 msgstr "Файл новее локального, получение.\n"
 
-#: src/http.c:1226
+#: src/http.c:1559
 #, c-format
 msgid ""
 "%s (%s) - `%s' saved [%ld/%ld]\n"
