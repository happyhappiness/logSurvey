msgid "Unknown error"
msgstr "Неизвестная ошибка"

#: src/http.c:625 src/http.c:1437
msgid "Unable to establish SSL connection.\n"
msgstr ""

#: src/http.c:633
#, fuzzy, c-format
msgid "Reusing connection to %s:%hu.\n"
msgstr "Попытки соединения с %s:%hu будут продолжены.\n"

#: src/http.c:809
#, fuzzy, c-format
msgid "Failed writing HTTP request: %s.\n"
msgstr "Ошибка записи запроса HTTP.\n"

#: src/http.c:814
#, c-format
msgid "%s request sent, awaiting response... "
msgstr "Запрос %s послан, ожидание ответа... "

#: src/http.c:858
msgid "End of file while parsing headers.\n"
msgstr "Конец файла во время разбора заголовков.\n"

#: src/http.c:869
#, c-format
msgid "Read error (%s) in headers.\n"
msgstr "Ошибка чтения (%s) в заголовках.\n"

#: src/http.c:909
msgid "No data received"
msgstr "Не получено никаких данных"

#: src/http.c:911
msgid "Malformed status line"
msgstr "Неполная строка статуса"

#: src/http.c:916
msgid "(no description)"
msgstr "(нет описания)"

#: src/http.c:1034
msgid "Authorization failed.\n"
msgstr "Авторизация прошла неудачно.\n"

#: src/http.c:1041
msgid "Unknown authentication scheme.\n"
msgstr "Неизвестная схема проверки полномочий.\n"

#: src/http.c:1131
#, c-format
msgid "Location: %s%s\n"
msgstr "Адрес: %s%s\n"

#: src/http.c:1132 src/http.c:1157
msgid "unspecified"
msgstr "нет информации"

#: src/http.c:1133
msgid " [following]"
msgstr " [переход]"

#. No need to print this output if the body won't be
#. downloaded at all, or if the original server response is
#. printed.
#: src/http.c:1147
msgid "Length: "
msgstr "Длина: "

#: src/http.c:1152
#, c-format
msgid " (%s to go)"
msgstr " (осталось %s)"

#: src/http.c:1157
msgid "ignored"
msgstr "игнорируется"

#: src/http.c:1258
msgid "Warning: wildcards not supported in HTTP.\n"
msgstr "Предупреждение: в HTTP шаблоны не поддерживаются.\n"

#. If opt.noclobber is turned on and file already exists, do not
#. retrieve the file
#: src/http.c:1279
#, c-format
msgid "File `%s' already there, will not retrieve.\n"
msgstr "Файл `%s' уже существует, получение не производится.\n"

#: src/http.c:1429
#, c-format
msgid "Cannot write to `%s' (%s).\n"
msgstr "Ошибка записи в `%s' (%s).\n"

#: src/http.c:1447
#, c-format
msgid "ERROR: Redirection (%d) without location.\n"
msgstr "ОШИБКА: Перенаправление (%d) без указания адреса.\n"

#: src/http.c:1472
#, c-format
msgid "%s ERROR %d: %s.\n"
msgstr "%s ОШИБКА %d: %s.\n"

#: src/http.c:1485
msgid "Last-modified header missing -- time-stamps turned off.\n"
msgstr "Нет заголовка last-modified -- временные отметки выключены.\n"

#: src/http.c:1493
msgid "Last-modified header invalid -- time-stamp ignored.\n"
msgstr ""
"Заголовок last-modified некорректен -- временные отметки игнорируются.\n"

#: src/http.c:1528
msgid "Remote file is newer, retrieving.\n"
msgstr "Файл новее локального, получение.\n"

#: src/http.c:1573
#, c-format
msgid ""
"%s (%s) - `%s' saved [%ld/%ld]\n"
