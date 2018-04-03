#. that there can be valid reasons for the local host
#. name not to be an FQDN, so I've decided to remove the
#. annoying warning.
#: src/host.c:517
#, c-format
msgid "%s: Warning: reverse-lookup of local address did not yield FQDN!\n"
msgstr ""
"%s: Предупреждение: при обратном преобразовании IP-адреса не получено FQDN!\n"

#: src/host.c:545
msgid "Host not found"
msgstr "Хост не найден"

#: src/host.c:547
msgid "Unknown error"
msgstr "Неизвестная ошибка"

#: src/html.c:615 src/html.c:617
#, c-format
msgid "Index of /%s on %s:%d"
msgstr "Листинг каталога /%s на %s:%d"

#: src/html.c:639
msgid "time unknown       "
msgstr "время неизвестно   "

#: src/html.c:643
msgid "File        "
msgstr "Файл        "

#: src/html.c:646
msgid "Directory   "
msgstr "Каталог     "

#: src/html.c:649
msgid "Link        "
msgstr "Ссылка      "

#: src/html.c:652
msgid "Not sure    "
msgstr "Неизвестно  "

#: src/html.c:670
#, c-format
msgid " (%s bytes)"
msgstr " (%s байт)"

#: src/http.c:508
msgid "Failed writing HTTP request.\n"
msgstr "Ошибка записи запроса HTTP.\n"

#: src/http.c:512
#, c-format
msgid "%s request sent, awaiting response... "
msgstr "Запрос %s послан, ожидание ответа... "

#: src/http.c:551
msgid "End of file while parsing headers.\n"
msgstr "Конец файла во время разбора заголовков.\n"

#: src/http.c:562
#, c-format
msgid "Read error (%s) in headers.\n"
msgstr "Ошибка чтения (%s) в заголовках.\n"

#: src/http.c:602
msgid "No data received"
msgstr "Не получено никаких данных"

#: src/http.c:604
msgid "Malformed status line"
msgstr "Неполная строка статуса"

#: src/http.c:609
msgid "(no description)"
msgstr "(нет описания)"

#. If we have tried it already, then there is not point
#. retrying it.
#: src/http.c:693
msgid "Authorization failed.\n"
msgstr "Авторизация прошла неудачно.\n"

#: src/http.c:700
msgid "Unknown authentication scheme.\n"
msgstr "Неизвестная схема проверки полномочий.\n"

#: src/http.c:783
#, c-format
msgid "Location: %s%s\n"
msgstr "Адрес: %s%s\n"

#: src/http.c:784 src/http.c:809
msgid "unspecified"
msgstr "нет информации"

#: src/http.c:785
msgid " [following]"
msgstr " [переход]"

#. No need to print this output if the body won't be
#. downloaded at all, or if the original server response is
#. printed.
#: src/http.c:799
msgid "Length: "
msgstr "Длина: "

#: src/http.c:804
#, c-format
msgid " (%s to go)"
msgstr " (осталось %s)"

#: src/http.c:809
msgid "ignored"
msgstr "игнорируется"

#: src/http.c:912
msgid "Warning: wildcards not supported in HTTP.\n"
msgstr "Предупреждение: в HTTP шаблоны не поддерживаются.\n"

#. If opt.noclobber is turned on and file already exists, do not
#. retrieve the file
#: src/http.c:933
#, c-format
msgid "File `%s' already there, will not retrieve.\n"
msgstr "Файл `%s' уже существует, получение не производится.\n"

#: src/http.c:1099
#, c-format
msgid "Cannot write to `%s' (%s).\n"
msgstr "Ошибка записи в `%s' (%s).\n"

#: src/http.c:1110
#, c-format
msgid "ERROR: Redirection (%d) without location.\n"
msgstr "ОШИБКА: Перенаправление (%d) без указания адреса.\n"

#: src/http.c:1135
#, c-format
msgid "%s ERROR %d: %s.\n"
msgstr "%s ОШИБКА %d: %s.\n"

#: src/http.c:1148
msgid "Last-modified header missing -- time-stamps turned off.\n"
msgstr "Нет заголовка last-modified -- временные отметки выключены.\n"

#: src/http.c:1156
msgid "Last-modified header invalid -- time-stamp ignored.\n"
msgstr ""
"Заголовок last-modified некорректен -- временные отметки игнорируются.\n"

#: src/http.c:1191
msgid "Remote file is newer, retrieving.\n"
msgstr "Файл новее локального, получение.\n"

#: src/http.c:1226
#, c-format
msgid ""
"%s (%s) - `%s' saved [%ld/%ld]\n"
