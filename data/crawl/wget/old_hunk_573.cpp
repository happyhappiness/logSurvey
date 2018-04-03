"Корректная символическая ссылка %s -> %s уже существует.\n"
"\n"

#: src/ftp.c:1533
#, c-format
msgid "Creating symlink %s -> %s\n"
msgstr "Создаётся символическая ссылка %s -> %s\n"

#: src/ftp.c:1543
#, fuzzy, c-format
msgid "Symlinks not supported, skipping symlink %s.\n"
msgstr "Символические ссылки не поддерживаются, ссылка `%s' пропускается.\n"

#: src/ftp.c:1555
#, fuzzy, c-format
msgid "Skipping directory %s.\n"
msgstr "Пропускается каталог `%s'.\n"

#: src/ftp.c:1564
#, c-format
msgid "%s: unknown/unsupported file type.\n"
msgstr "%s: неизвестный/неподдерживаемый тип файла.\n"

#: src/ftp.c:1591
#, c-format
msgid "%s: corrupt time-stamp.\n"
msgstr "%s: повреждена метка даты/времени.\n"

#: src/ftp.c:1619
#, c-format
msgid "Will not retrieve dirs since depth is %d (max %d).\n"
msgstr ""
"Каталоги не будут загружены, т.к. глубина составляет %d (максимум %d).\n"

#: src/ftp.c:1669
#, fuzzy, c-format
msgid "Not descending to %s as it is excluded/not-included.\n"
msgstr "Вход в каталог `%s' не выполняется, т.к. он исключён/не включён.\n"

#: src/ftp.c:1735 src/ftp.c:1749
#, fuzzy, c-format
msgid "Rejecting %s.\n"
msgstr "Отклоняется `%s'.\n"

#: src/ftp.c:1772
#, c-format
msgid "Error matching %s against %s: %s\n"
msgstr "Ошибка сопоставления %s с %s: %s\n"

#: src/ftp.c:1814
#, fuzzy, c-format
msgid "No matches on pattern %s.\n"
msgstr "Нет совпадений с шаблоном `%s'.\n"

#: src/ftp.c:1880
#, fuzzy, c-format
msgid "Wrote HTML-ized index to %s [%s].\n"
msgstr "Индекс в формате HTML записан в файл `%s' [%s].\n"

#: src/ftp.c:1885
#, fuzzy, c-format
msgid "Wrote HTML-ized index to %s.\n"
msgstr "Индекс в формате HTML записан в файл `%s'.\n"

#: src/host.c:348
msgid "Unknown host"
msgstr "Неизвестный хост"

#: src/host.c:352
msgid "Temporary failure in name resolution"
msgstr "Временный сбой при разрешении имени"

#: src/host.c:354
msgid "Unknown error"
msgstr "Неизвестная ошибка"

#: src/host.c:715
#, c-format
msgid "Resolving %s... "
msgstr "Распознаётся %s... "

#: src/host.c:763
msgid "failed: No IPv4/IPv6 addresses for host.\n"
msgstr "сбой: Для хоста нет адресов IPv4/IPv6.\n"

#: src/host.c:786
msgid "failed: timed out.\n"
msgstr "сбой: превышен тайм-аут.\n"

#: src/html-url.c:289
#, c-format
msgid "%s: Cannot resolve incomplete link %s.\n"
msgstr "%s: Невозможно распознать неполную ссылку %s.\n"

#: src/html-url.c:696
#, c-format
msgid "%s: Invalid URL %s: %s\n"
msgstr "%s: Неверный URL %s: %s\n"

#: src/http.c:368
#, c-format
msgid "Failed writing HTTP request: %s.\n"
msgstr "Сбой записи запроса HTTP: %s.\n"

#: src/http.c:745
msgid "No headers, assuming HTTP/0.9"
msgstr "Заголовки отсутствуют, подразумевается HTTP/0.9"

#: src/http.c:1430
msgid "Disabling SSL due to encountered errors.\n"
msgstr "SSL отключается из-за непредвиденных ошибок.\n"

#: src/http.c:1548
#, fuzzy, c-format
msgid "POST data file %s missing: %s\n"
msgstr "Отсутствует файл POST-данных `%s': %s\n"

#: src/http.c:1632
#, c-format
msgid "Reusing existing connection to %s:%d.\n"
msgstr "Повторное использование соединения с %s:%d.\n"

#: src/http.c:1701
#, c-format
msgid "Failed reading proxy response: %s\n"
msgstr "Сбой чтения ответа прокси: %s.\n"

#: src/http.c:1721
#, c-format
msgid "Proxy tunneling failed: %s"
msgstr "Сбой туннелирования прокси: %s"

#: src/http.c:1766
#, c-format
msgid "%s request sent, awaiting response... "
msgstr "Запрос %s послан, ожидается ответ... "

#: src/http.c:1777
msgid "No data received.\n"
msgstr "Не получено никаких данных.\n"

#: src/http.c:1784
#, c-format
msgid "Read error (%s) in headers.\n"
msgstr "Ошибка чтения (%s) в заголовках.\n"

#: src/http.c:1831 src/http.c:2385
#, fuzzy, c-format
msgid ""
"File %s already there; not retrieving.\n"
