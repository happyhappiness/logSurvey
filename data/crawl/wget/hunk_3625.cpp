 msgstr "Неизвестная ошибка"
 
 #. this is fatal
-#: src/http.c:554
+#: src/http.c:555
 msgid "Failed to set up an SSL context\n"
 msgstr "Не удалось установить контекст SSL\n"
 
-#: src/http.c:560
+#: src/http.c:561
 #, c-format
 msgid "Failed to load certificates from %s\n"
 msgstr "Не удалось загрузить сертификаты с %s\n"
 
-#: src/http.c:564 src/http.c:572
+#: src/http.c:565 src/http.c:573
 msgid "Trying without the specified certificate\n"
 msgstr "Попытка продолжить без указанного сертификата\n"
 
-#: src/http.c:568
+#: src/http.c:569
 #, c-format
 msgid "Failed to get certificate key from %s\n"
 msgstr "Не удалось получить ключ сертификата с %s\n"
 
-#: src/http.c:662 src/http.c:1592
+#: src/http.c:663 src/http.c:1593
 msgid "Unable to establish SSL connection.\n"
 msgstr "Не удается установить соединение SSL.\n"
 
-#: src/http.c:670
+#: src/http.c:671
 #, c-format
 msgid "Reusing connection to %s:%hu.\n"
 msgstr "Повторное использование соединения с %s:%hu.\n"
 
-#: src/http.c:860
+#: src/http.c:861
 #, c-format
 msgid "Failed writing HTTP request: %s.\n"
 msgstr "Ошибка записи запроса HTTP: %s.\n"
 
-#: src/http.c:865
+#: src/http.c:866
 #, c-format
 msgid "%s request sent, awaiting response... "
 msgstr "Запрос %s послан, ожидание ответа... "
 
-#: src/http.c:909
+#: src/http.c:910
 msgid "End of file while parsing headers.\n"
 msgstr "Конец файла во время разбора заголовков.\n"
 
-#: src/http.c:919
+#: src/http.c:920
 #, c-format
 msgid "Read error (%s) in headers.\n"
 msgstr "Ошибка чтения (%s) в заголовках.\n"
 
-#: src/http.c:958
+#: src/http.c:959
 msgid "No data received"
 msgstr "Не получено никаких данных"
 
-#: src/http.c:960
+#: src/http.c:961
 msgid "Malformed status line"
 msgstr "Неполная строка статуса"
 
-#: src/http.c:965
+#: src/http.c:966
 msgid "(no description)"
 msgstr "(нет описания)"
 
-#: src/http.c:1088
+#: src/http.c:1089
 msgid "Authorization failed.\n"
 msgstr "Авторизация прошла неудачно.\n"
 
-#: src/http.c:1095
+#: src/http.c:1096
 msgid "Unknown authentication scheme.\n"
 msgstr "Неизвестная схема проверки полномочий.\n"
 
-#: src/http.c:1135
+#: src/http.c:1136
 #, c-format
 msgid "Location: %s%s\n"
 msgstr "Адрес: %s%s\n"
 
-#: src/http.c:1136 src/http.c:1268
+#: src/http.c:1137 src/http.c:1269
 msgid "unspecified"
 msgstr "нет информации"
 
-#: src/http.c:1137
+#: src/http.c:1138
 msgid " [following]"
 msgstr " [переход]"
 
-#: src/http.c:1199
+#: src/http.c:1200
 msgid "\n    The file is already fully retrieved; nothing to do.\n\n"
 msgstr "\n    Файл уже получен полностью; нет действий.\n\n"
 
-#: src/http.c:1215
+#: src/http.c:1216
 #, c-format
 msgid ""
 "\n"
-"The server does not support continued downloads, which conflicts with `-c'.\n"
+"Continued download failed on this file, which conflicts with `-c'.\n"
 "Refusing to truncate existing file `%s'.\n"
 "\n"
 msgstr ""
 "\n"
-"Сервер не поддерживает возобновление при получении файлов, подразумеваемое\n"
-"ключом -c. Существующий файл `%s' не будет усечен.\n"
+"Возобновление при получении данного файла, подразумеваемое ключом -c,\n"
+"не выполнено. Существующий файл `%s' не будет усечен.\n"
 "\n"
 
 #. No need to print this output if the body won't be
 #. downloaded at all, or if the original server response is
 #. printed.
-#: src/http.c:1258
+#: src/http.c:1259
 msgid "Length: "
 msgstr "Длина: "
 
-#: src/http.c:1263
+#: src/http.c:1264
 #, c-format
 msgid " (%s to go)"
 msgstr " (осталось %s)"
 
-#: src/http.c:1268
+#: src/http.c:1269
 msgid "ignored"
 msgstr "игнорируется"
 
-#: src/http.c:1398
+#: src/http.c:1399
 msgid "Warning: wildcards not supported in HTTP.\n"
 msgstr "Предупреждение: в HTTP шаблоны не поддерживаются.\n"
 
 #. If opt.noclobber is turned on and file already exists, do not
 #. retrieve the file
-#: src/http.c:1416
+#: src/http.c:1417
 #, c-format
 msgid "File `%s' already there, will not retrieve.\n"
 msgstr "Файл `%s' уже существует, получение не производится.\n"
 
-#: src/http.c:1584
+#: src/http.c:1585
 #, c-format
 msgid "Cannot write to `%s' (%s).\n"
 msgstr "Ошибка записи в `%s' (%s).\n"
 
-#: src/http.c:1601
+#: src/http.c:1602
 #, c-format
 msgid "ERROR: Redirection (%d) without location.\n"
 msgstr "ОШИБКА: Перенаправление (%d) без указания адреса.\n"
 
-#: src/http.c:1629
+#: src/http.c:1630
 #, c-format
 msgid "%s ERROR %d: %s.\n"
 msgstr "%s ОШИБКА %d: %s.\n"
 
-#: src/http.c:1641
+#: src/http.c:1642
 msgid "Last-modified header missing -- time-stamps turned off.\n"
 msgstr "Нет заголовка last-modified -- временные отметки выключены.\n"
 
-#: src/http.c:1649
+#: src/http.c:1650
 msgid "Last-modified header invalid -- time-stamp ignored.\n"
 msgstr "Заголовок last-modified некорректен -- временные отметки игнорируются.\n"
 
-#: src/http.c:1672
+#: src/http.c:1673
 #, c-format
 msgid "Server file no newer than local file `%s' -- not retrieving.\n\n"
 msgstr "Файл на сервере не новее локального файла `%s' -- пропуск.\n"
 
-#: src/http.c:1679
+#: src/http.c:1680
 #, c-format
 msgid "The sizes do not match (local %ld) -- retrieving.\n"
 msgstr "Размеры файлов не совпадают (локальный размер %ld) -- получение.\n"
 
-#: src/http.c:1683
+#: src/http.c:1684
 msgid "Remote file is newer, retrieving.\n"
 msgstr "Файл новее локального, получение.\n"
 
-#: src/http.c:1727
+#: src/http.c:1728
 #, c-format
 msgid "%s (%s) - `%s' saved [%ld/%ld]\n\n"
 msgstr "%s (%s) - `%s' сохранен [%ld/%ld]\n\n"
 
-#: src/http.c:1773
+#: src/http.c:1774
 #, c-format
 msgid "%s (%s) - Connection closed at byte %ld. "
 msgstr "%s (%s) - Соединение закрыто, позиция %ld. "
 
-#: src/http.c:1781
+#: src/http.c:1782
 #, c-format
 msgid "%s (%s) - `%s' saved [%ld/%ld])\n\n"
 msgstr "%s (%s) - `%s' сохранен [%ld/%ld])\n\n"
 
-#: src/http.c:1800
+#: src/http.c:1801
 #, c-format
 msgid "%s (%s) - Connection closed at byte %ld/%ld. "
 msgstr "%s (%s) - Соединение закрыто, позиция %ld/%ld. "
 
-#: src/http.c:1811
+#: src/http.c:1812
 #, c-format
 msgid "%s (%s) - Read error at byte %ld (%s)."
 msgstr "%s (%s) - Ошибка чтения, позиция %ld (%s)."
 
-#: src/http.c:1819
+#: src/http.c:1820
 #, c-format
 msgid "%s (%s) - Read error at byte %ld/%ld (%s). "
 msgstr "%s (%s) - Ошибка чтения, позиция %ld/%ld (%s). "
 
-#: src/init.c:348 src/netrc.c:267
+#: src/init.c:349 src/netrc.c:267
 #, c-format
 msgid "%s: Cannot read %s (%s).\n"
 msgstr "%s: Ошибка чтения %s (%s).\n"
 
-#: src/init.c:366 src/init.c:372
+#: src/init.c:367 src/init.c:373
 #, c-format
 msgid "%s: Error in %s at line %d.\n"
 msgstr "%s: Ошибка в %s в строке %d.\n"
 
-#: src/init.c:404
+#: src/init.c:405
 #, c-format
 msgid "%s: Warning: Both system and user wgetrc point to `%s'.\n"
 msgstr "%s: Предупреждение: системный и пользовательский wgetrc указывают на `%s'.\n"
 
-#: src/init.c:496
+#: src/init.c:497
 #, c-format
 msgid "%s: BUG: unknown command `%s', value `%s'.\n"
 msgstr "%s: ОШИБКА В ПРОГРАММЕ: неизвестная команда `%s', значение `%s'.\n"
 
-#: src/init.c:528
+#: src/init.c:529
 #, c-format
 msgid "%s: %s: Cannot convert `%s' to an IP address.\n"
 msgstr "%s: %s: Ошибка определения IP-адреса для `%s'.\n"
 
-#: src/init.c:558
+#: src/init.c:559
 #, c-format
 msgid "%s: %s: Please specify on or off.\n"
 msgstr "%s: %s: Пожалуйста, укажите on или off.\n"
 
-#: src/init.c:602
+#: src/init.c:603
 #, c-format
 msgid "%s: %s: Please specify always, on, off, or never.\n"
 msgstr "%s: %s: Пожалуйста, укажите always, on, off или never.\n"
 
-#: src/init.c:621 src/init.c:918 src/init.c:940 src/init.c:1004
+#: src/init.c:622 src/init.c:919 src/init.c:941 src/init.c:1005
 #, c-format
 msgid "%s: %s: Invalid specification `%s'.\n"
 msgstr "%s: %s: Недопустимое описание `%s'.\n"
 
-#: src/init.c:774 src/init.c:796 src/init.c:818 src/init.c:844
+#: src/init.c:775 src/init.c:797 src/init.c:819 src/init.c:845
 #, c-format
 msgid "%s: Invalid specification `%s'\n"
 msgstr "%s: Недопустимое описание `%s'\n"
 
-#: src/main.c:119
+#: src/main.c:120
 #, c-format
 msgid "Usage: %s [OPTION]... [URL]...\n"
 msgstr "Использование: %s [КЛЮЧ]... [URL]...\n"
 
-#: src/main.c:127
+#: src/main.c:128
 #, c-format
 msgid "GNU Wget %s, a non-interactive network retriever.\n"
 msgstr "GNU Wget %s, программа автоматического получения файлов по сети.\n"
 
 #. Had to split this in parts, so the #@@#%# Ultrix compiler and cpp
 #. don't bitch.  Also, it makes translation much easier.
-#: src/main.c:132
+#: src/main.c:133
 msgid "\nMandatory arguments to long options are mandatory for short options too.\n\n"
 msgstr "\nКороткие ключи требуют указания тех же аргументов, что и длинные ключи.\n\n"
 
-#: src/main.c:136
+#: src/main.c:137
 msgid ""
 "Startup:\n"
 "  -V,  --version           display the version of Wget and exit.\n"
