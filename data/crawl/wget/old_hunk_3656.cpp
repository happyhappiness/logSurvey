msgid "%s: option requires an argument -- %c\n"
msgstr "%s: ключ требует указания аргумента -- %c\n"

#: src/host.c:394
#, c-format
msgid "%s: Cannot determine user-id.\n"
msgstr "%s: Не удается определить идентификатор пользователя.\n"

#: src/host.c:406
#, c-format
msgid "%s: Warning: uname failed: %s\n"
msgstr "%s: Предупреждение: неудачный вызов uname: %s\n"

#: src/host.c:418
#, c-format
msgid "%s: Warning: gethostname failed\n"
msgstr "%s: Предупреждение: неудачный вызов gethostname\n"

#: src/host.c:446
#, c-format
msgid "%s: Warning: cannot determine local IP address.\n"
msgstr "%s: Предупреждение: ошибка определения локального IP-адреса.\n"

#: src/host.c:460
#, c-format
msgid "%s: Warning: cannot reverse-lookup local IP address.\n"
msgstr ""
"%s: Предупреждение: ошибка обратного преобразования локального IP-адреса.\n"

#. This gets ticked pretty often.  Karl Berry reports
#. that there can be valid reasons for the local host
#. name not to be an FQDN, so I've decided to remove the
#. annoying warning.
#: src/host.c:473
#, c-format
msgid "%s: Warning: reverse-lookup of local address did not yield FQDN!\n"
msgstr ""
"%s: Предупреждение: при обратном преобразовании IP-адреса не получено FQDN!\n"

#: src/host.c:501
msgid "Host not found"
msgstr "Хост не найден"

#: src/host.c:503
msgid "Unknown error"
msgstr "Неизвестная ошибка"

#. this is fatal
#: src/http.c:549
msgid "Failed to set up an SSL context\n"
msgstr ""

#: src/http.c:555
#, c-format
msgid "Failed to load certificates from %s\n"
msgstr ""

#: src/http.c:559 src/http.c:567
msgid "Trying without the specified certificate\n"
msgstr ""

#: src/http.c:563
#, c-format
msgid "Failed to get certificate key from %s\n"
msgstr ""

#: src/http.c:657 src/http.c:1470
msgid "Unable to establish SSL connection.\n"
msgstr ""

#: src/http.c:665
#, fuzzy, c-format
msgid "Reusing connection to %s:%hu.\n"
msgstr "Попытки соединения с %s:%hu будут продолжены.\n"

#: src/http.c:841
#, fuzzy, c-format
msgid "Failed writing HTTP request: %s.\n"
msgstr "Ошибка записи запроса HTTP.\n"

#: src/http.c:846
#, c-format
msgid "%s request sent, awaiting response... "
msgstr "Запрос %s послан, ожидание ответа... "

#: src/http.c:890
msgid "End of file while parsing headers.\n"
msgstr "Конец файла во время разбора заголовков.\n"

#: src/http.c:901
#, c-format
msgid "Read error (%s) in headers.\n"
msgstr "Ошибка чтения (%s) в заголовках.\n"

#: src/http.c:941
msgid "No data received"
msgstr "Не получено никаких данных"

#: src/http.c:943
msgid "Malformed status line"
msgstr "Неполная строка статуса"

#: src/http.c:948
msgid "(no description)"
msgstr "(нет описания)"

#: src/http.c:1066
msgid "Authorization failed.\n"
msgstr "Авторизация прошла неудачно.\n"

#: src/http.c:1073
msgid "Unknown authentication scheme.\n"
msgstr "Неизвестная схема проверки полномочий.\n"

#: src/http.c:1163
#, c-format
msgid "Location: %s%s\n"
msgstr "Адрес: %s%s\n"

#: src/http.c:1164 src/http.c:1189
msgid "unspecified"
msgstr "нет информации"

#: src/http.c:1165
msgid " [following]"
msgstr " [переход]"

#. No need to print this output if the body won't be
#. downloaded at all, or if the original server response is
#. printed.
#: src/http.c:1179
msgid "Length: "
msgstr "Длина: "

#: src/http.c:1184
#, c-format
msgid " (%s to go)"
msgstr " (осталось %s)"

#: src/http.c:1189
msgid "ignored"
msgstr "игнорируется"

#: src/http.c:1290
msgid "Warning: wildcards not supported in HTTP.\n"
msgstr "Предупреждение: в HTTP шаблоны не поддерживаются.\n"

#. If opt.noclobber is turned on and file already exists, do not
#. retrieve the file
#: src/http.c:1311
#, c-format
msgid "File `%s' already there, will not retrieve.\n"
msgstr "Файл `%s' уже существует, получение не производится.\n"

#: src/http.c:1462
#, c-format
msgid "Cannot write to `%s' (%s).\n"
msgstr "Ошибка записи в `%s' (%s).\n"

#: src/http.c:1480
#, c-format
msgid "ERROR: Redirection (%d) without location.\n"
msgstr "ОШИБКА: Перенаправление (%d) без указания адреса.\n"

#: src/http.c:1505
#, c-format
msgid "%s ERROR %d: %s.\n"
msgstr "%s ОШИБКА %d: %s.\n"

#: src/http.c:1518
msgid "Last-modified header missing -- time-stamps turned off.\n"
msgstr "Нет заголовка last-modified -- временные отметки выключены.\n"

#: src/http.c:1526
msgid "Last-modified header invalid -- time-stamp ignored.\n"
msgstr ""
"Заголовок last-modified некорректен -- временные отметки игнорируются.\n"

#: src/http.c:1549
#, c-format
msgid ""
"Server file no newer than local file `%s' -- not retrieving.\n"
"\n"
msgstr "Файл на сервере не новее локального файла `%s' -- пропуск.\n"

#: src/http.c:1557
#, c-format
msgid "The sizes do not match (local %ld) -- retrieving.\n"
msgstr "Размеры файлов не совпадают (локальный размер %ld) -- получение.\n"

#: src/http.c:1561
msgid "Remote file is newer, retrieving.\n"
msgstr "Файл новее локального, получение.\n"

#: src/http.c:1606
#, c-format
msgid ""
"%s (%s) - `%s' saved [%ld/%ld]\n"
"\n"
msgstr ""
"%s (%s) - `%s' сохранен [%ld/%ld]\n"
"\n"

#: src/http.c:1654
#, c-format
msgid "%s (%s) - Connection closed at byte %ld. "
msgstr "%s (%s) - Соединение закрыто, позиция %ld. "

#: src/http.c:1662
#, c-format
msgid ""
"%s (%s) - `%s' saved [%ld/%ld])\n"
"\n"
msgstr ""
"%s (%s) - `%s' сохранен [%ld/%ld])\n"
"\n"

#: src/http.c:1682
#, c-format
msgid "%s (%s) - Connection closed at byte %ld/%ld. "
msgstr "%s (%s) - Соединение закрыто, позиция %ld/%ld. "

#: src/http.c:1693
#, c-format
msgid "%s (%s) - Read error at byte %ld (%s)."
msgstr "%s (%s) - Ошибка чтения, позиция %ld (%s)."

#: src/http.c:1701
#, c-format
msgid "%s (%s) - Read error at byte %ld/%ld (%s). "
msgstr "%s (%s) - Ошибка чтения, позиция %ld/%ld (%s). "

#: src/init.c:336 src/netrc.c:261
#, c-format
msgid "%s: Cannot read %s (%s).\n"
msgstr "%s: Ошибка чтения %s (%s).\n"

#: src/init.c:354 src/init.c:360
#, c-format
msgid "%s: Error in %s at line %d.\n"
msgstr "%s: Ошибка в %s в строке %d.\n"

#: src/init.c:391
#, c-format
msgid "%s: Warning: Both system and user wgetrc point to `%s'.\n"
msgstr ""
"%s: Предупреждение: системный и пользовательский wgetrc указывают на `%s'.\n"

#: src/init.c:483
#, c-format
msgid "%s: BUG: unknown command `%s', value `%s'.\n"
msgstr "%s: ОШИБКА В ПРОГРАММЕ: неизвестная команда `%s', значение `%s'.\n"

#: src/init.c:504
#, c-format
msgid "%s: %s: Cannot convert `%s' to an IP address.\n"
msgstr "%s: %s: Ошибка определения IP-адреса для `%s'.\n"

#: src/init.c:532
#, c-format
msgid "%s: %s: Please specify on or off.\n"
msgstr "%s: %s: Пожалуйста, укажите on или off.\n"

#: src/init.c:576
#, c-format
msgid "%s: %s: Please specify always, on, off, or never.\n"
msgstr "%s: %s: Пожалуйста, укажите always, on, off или never.\n"

#: src/init.c:595 src/init.c:852 src/init.c:874 src/init.c:938
#, c-format
msgid "%s: %s: Invalid specification `%s'.\n"
msgstr "%s: %s: Недопустимое описание `%s'.\n"

#: src/init.c:708 src/init.c:730 src/init.c:752 src/init.c:778
#, c-format
msgid "%s: Invalid specification `%s'\n"
msgstr "%s: Недопустимое описание `%s'\n"

#: src/main.c:120
#, c-format
msgid "Usage: %s [OPTION]... [URL]...\n"
msgstr "Использование: %s [КЛЮЧ]... [URL]...\n"

#: src/main.c:128
#, c-format
msgid "GNU Wget %s, a non-interactive network retriever.\n"
msgstr "GNU Wget %s, программа автоматического получения файлов по сети.\n"

#. Had to split this in parts, so the #@@#%# Ultrix compiler and cpp
#. don't bitch.  Also, it makes translation much easier.
#: src/main.c:133
msgid ""
"\n"
"Mandatory arguments to long options are mandatory for short options too.\n"
"\n"
msgstr ""
"\n"
"Короткие ключи требуют указания тех же аргументов, что и длинные ключи.\n"
"\n"

#: src/main.c:136
msgid ""
