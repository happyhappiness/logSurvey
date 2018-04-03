msgid "%s: option `-W %s' doesn't allow an argument\n"
msgstr "%s: опция `-W %s' не разрешает использовать аргумент\n"

#: src/host.c:368
#, fuzzy
msgid "Unknown host"
msgstr "Неизвестная ошибка"

#. Message modeled after what gai_strerror returns in similar
#. circumstances.
#: src/host.c:372
msgid "Temporary failure in name resolution"
msgstr ""

#: src/host.c:374
msgid "Unknown error"
msgstr "Неизвестная ошибка"

#: src/host.c:748
#, c-format
msgid "Resolving %s... "
msgstr "Распознается %s... "

#: src/host.c:792 src/host.c:839
#, c-format
msgid "failed: %s.\n"
msgstr "сбой: %s.\n"

#: src/host.c:801
msgid "failed: No IPv4/IPv6 addresses for host.\n"
msgstr ""

#: src/host.c:842
msgid "failed: timed out.\n"
msgstr "сбой: превышен тайм-аут.\n"

#: src/html-url.c:297
#, c-format
msgid "%s: Cannot resolve incomplete link %s.\n"
msgstr "%s: Невозможно распознать неполную ссылку %s.\n"

#: src/http.c:349 src/http.c:1504
#, c-format
msgid "Failed writing HTTP request: %s.\n"
msgstr "Сбой записи запроса HTTP: %s.\n"

#: src/http.c:663
msgid "No headers, assuming HTTP/0.9"
msgstr ""

#. this is fatal
#: src/http.c:1151
msgid "Failed to set up an SSL context\n"
msgstr "Сбой установки контекста SSL\n"

#: src/http.c:1156
#, c-format
msgid "Failed to load certificates from %s\n"
msgstr "Сбой загрузки сертификатов из %s\n"

#: src/http.c:1159 src/http.c:1166
msgid "Trying without the specified certificate\n"
msgstr "Выполняется попытка без указанного сертификата\n"

#: src/http.c:1163
#, c-format
msgid "Failed to get certificate key from %s\n"
msgstr "Сбой получения ключа сертификата из %s\n"

#: src/http.c:1382
#, fuzzy, c-format
msgid "Reusing existing connection to %s:%d.\n"
msgstr "Повторное использование соединения с %s:%hu.\n"

#: src/http.c:1434
#, fuzzy, c-format
msgid "Failed writing to proxy: %s.\n"
msgstr "Сбой записи запроса HTTP: %s.\n"

#: src/http.c:1443
#, fuzzy, c-format
msgid "Failed reading proxy response: %s\n"
msgstr "Сбой записи запроса HTTP: %s.\n"

#: src/http.c:1463
#, c-format
msgid "Proxy tunneling failed: %s"
msgstr ""

#: src/http.c:1510
#, c-format
msgid "%s request sent, awaiting response... "
msgstr "Запрос %s послан, ожидается ответ... "

#: src/http.c:1521
#, fuzzy
msgid "No data received.\n"
msgstr "Не получено никаких данных"

#: src/http.c:1528
#, c-format
msgid "Read error (%s) in headers.\n"
msgstr "Ошибка чтения (%s) в заголовках.\n"

#. If we have tried it already, then there is not point
#. retrying it.
#: src/http.c:1595
msgid "Authorization failed.\n"
msgstr "Сбой авторизации.\n"

#: src/http.c:1609
msgid "Unknown authentication scheme.\n"
msgstr "Неизвестная схема аутентификации.\n"

#: src/http.c:1634
msgid "Malformed status line"
msgstr "Неполная строка статуса"

#: src/http.c:1636
msgid "(no description)"
msgstr "(нет описания)"

#: src/http.c:1700
#, c-format
msgid "Location: %s%s\n"
msgstr "Адрес: %s%s\n"

#: src/http.c:1701 src/http.c:1801
msgid "unspecified"
msgstr "нет информации"

#: src/http.c:1702
msgid " [following]"
msgstr " [переход]"

#. If `-c' is in use and the file has been fully downloaded (or
#. the remote file has shrunk), Wget effectively requests bytes
#. after the end of file and the server response with 416.
#: src/http.c:1751
msgid ""
"\n"
"    The file is already fully retrieved; nothing to do.\n"
