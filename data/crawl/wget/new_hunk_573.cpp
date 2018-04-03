"Корректная символическая ссылка %s -> %s уже существует.\n"
"\n"

#: src/ftp.c:1788
#, c-format
msgid "Creating symlink %s -> %s\n"
msgstr "Создаётся символическая ссылка %s -> %s\n"

#: src/ftp.c:1798
#, fuzzy, c-format
msgid "Symlinks not supported, skipping symlink %s.\n"
msgstr "Символические ссылки не поддерживаются, ссылка `%s' пропускается.\n"

#: src/ftp.c:1810
#, fuzzy, c-format
msgid "Skipping directory %s.\n"
msgstr "Пропускается каталог `%s'.\n"

#: src/ftp.c:1819
#, c-format
msgid "%s: unknown/unsupported file type.\n"
msgstr "%s: неизвестный/неподдерживаемый тип файла.\n"

#: src/ftp.c:1856
#, c-format
msgid "%s: corrupt time-stamp.\n"
msgstr "%s: повреждена метка даты/времени.\n"

#: src/ftp.c:1878
#, c-format
msgid "Will not retrieve dirs since depth is %d (max %d).\n"
msgstr ""
"Каталоги не будут загружены, т.к. глубина составляет %d (максимум %d).\n"

#: src/ftp.c:1928
#, fuzzy, c-format
msgid "Not descending to %s as it is excluded/not-included.\n"
msgstr "Вход в каталог `%s' не выполняется, т.к. он исключён/не включён.\n"

#: src/ftp.c:1994 src/ftp.c:2008
#, fuzzy, c-format
msgid "Rejecting %s.\n"
msgstr "Отклоняется `%s'.\n"

#: src/ftp.c:2031
#, c-format
msgid "Error matching %s against %s: %s\n"
msgstr "Ошибка сопоставления %s с %s: %s\n"

#: src/ftp.c:2073
#, fuzzy, c-format
msgid "No matches on pattern %s.\n"
msgstr "Нет совпадений с шаблоном `%s'.\n"

#: src/ftp.c:2144
#, fuzzy, c-format
msgid "Wrote HTML-ized index to %s [%s].\n"
msgstr "Индекс в формате HTML записан в файл `%s' [%s].\n"

#: src/ftp.c:2149
#, fuzzy, c-format
msgid "Wrote HTML-ized index to %s.\n"
msgstr "Индекс в формате HTML записан в файл `%s'.\n"

#: src/gnutls.c:219 src/openssl.c:495
msgid "ERROR"
msgstr "ОШИБКА"

#: src/gnutls.c:219 src/openssl.c:495
msgid "WARNING"
msgstr "ПРЕДУПРЕЖДЕНИЕ"

#: src/gnutls.c:225 src/openssl.c:504
#, c-format
msgid "%s: No certificate presented by %s.\n"
msgstr "%s: Нет сертификата, представленного %s.\n"

#: src/gnutls.c:233
#, fuzzy, c-format
msgid "%s: The certificate of %s is not trusted.\n"
msgstr "%s: Нет сертификата, представленного %s.\n"

#: src/gnutls.c:239
#, c-format
msgid "%s: The certificate of %s hasn't got a known issuer.\n"
msgstr ""

#: src/gnutls.c:245
#, fuzzy, c-format
msgid "%s: The certificate of %s has been revoked.\n"
msgstr "  Для запрошенного сертификата истёк срок действия.\n"

#: src/gnutls.c:259
#, c-format
msgid "Error initializing X509 certificate: %s\n"
msgstr ""

#: src/gnutls.c:268
#, fuzzy
msgid "No certificate found\n"
msgstr "%s: Нет сертификата, представленного %s.\n"

#: src/gnutls.c:275
#, fuzzy, c-format
msgid "Error parsing certificate: %s\n"
msgstr "Ошибка разбора URL прокси %s: %s\n"

#: src/gnutls.c:282
#, fuzzy
msgid "The certificate has not yet been activated\n"
msgstr "  Запрошенный сертификат ещё недействителен.\n"

#: src/gnutls.c:287
#, fuzzy
msgid "The certificate has expired\n"
msgstr "  Для запрошенного сертификата истёк срок действия.\n"

#: src/gnutls.c:293
#, fuzzy, c-format
msgid "The certificate's owner does not match hostname '%s'\n"
msgstr ""
"%s: Общее название сертификата `%s' не совпадает с именем запрошенного хоста "
"`%s'.\n"

#: src/host.c:358
msgid "Unknown host"
msgstr "Неизвестный хост"

#: src/host.c:362
msgid "Temporary failure in name resolution"
msgstr "Временный сбой при разрешении имени"

#: src/host.c:364
msgid "Unknown error"
msgstr "Неизвестная ошибка"

#: src/host.c:737
#, c-format
msgid "Resolving %s... "
msgstr "Распознаётся %s... "

#: src/host.c:789
msgid "failed: No IPv4/IPv6 addresses for host.\n"
msgstr "сбой: Для хоста нет адресов IPv4/IPv6.\n"

#: src/host.c:812
msgid "failed: timed out.\n"
msgstr "сбой: превышен тайм-аут.\n"

#: src/html-url.c:286
#, c-format
msgid "%s: Cannot resolve incomplete link %s.\n"
msgstr "%s: Невозможно распознать неполную ссылку %s.\n"

#: src/html-url.c:762
#, c-format
msgid "%s: Invalid URL %s: %s\n"
msgstr "%s: Неверный URL %s: %s\n"

#: src/http.c:377
#, c-format
msgid "Failed writing HTTP request: %s.\n"
msgstr "Сбой записи запроса HTTP: %s.\n"

#: src/http.c:754
msgid "No headers, assuming HTTP/0.9"
msgstr "Заголовки отсутствуют, подразумевается HTTP/0.9"

#: src/http.c:1456
msgid "Disabling SSL due to encountered errors.\n"
msgstr "SSL отключается из-за непредвиденных ошибок.\n"

#: src/http.c:1576
#, fuzzy, c-format
msgid "POST data file %s missing: %s\n"
msgstr "Отсутствует файл POST-данных `%s': %s\n"

#: src/http.c:1660
#, c-format
msgid "Reusing existing connection to %s:%d.\n"
msgstr "Повторное использование соединения с %s:%d.\n"

#: src/http.c:1729
#, c-format
msgid "Failed reading proxy response: %s\n"
msgstr "Сбой чтения ответа прокси: %s.\n"

#: src/http.c:1750
#, c-format
msgid "Proxy tunneling failed: %s"
msgstr "Сбой туннелирования прокси: %s"

#: src/http.c:1795
#, c-format
msgid "%s request sent, awaiting response... "
msgstr "Запрос %s послан, ожидается ответ... "

#: src/http.c:1806
msgid "No data received.\n"
msgstr "Не получено никаких данных.\n"

#: src/http.c:1813
#, c-format
msgid "Read error (%s) in headers.\n"
msgstr "Ошибка чтения (%s) в заголовках.\n"

#: src/http.c:1884
msgid "Unknown authentication scheme.\n"
msgstr "Неизвестная схема аутентификации.\n"

#: src/http.c:1918
msgid "Authorization failed.\n"
msgstr "Сбой авторизации.\n"

#: src/http.c:1956 src/http.c:2466
#, fuzzy, c-format
msgid ""
"File %s already there; not retrieving.\n"
