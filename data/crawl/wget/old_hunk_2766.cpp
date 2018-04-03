msgstr "%s: параметру необх╕дний аргумент -- %c\n"

#: src/getopt.c:862
#, fuzzy, c-format
msgid "%s: option `-W %s' is ambiguous\n"
msgstr "%s: неоднозначний параметр `%s'\n"

#: src/getopt.c:880
#, fuzzy, c-format
msgid "%s: option `-W %s' doesn't allow an argument\n"
msgstr "%s: параметр `--%s' не може мати аргументу\n"

#: src/host.c:371
#, fuzzy
msgid "Unknown host"
msgstr "Нев╕дома помилка"

#. Message modeled after what gai_strerror returns in similar
#. circumstances.
#: src/host.c:375
msgid "Temporary failure in name resolution"
msgstr ""

#: src/host.c:377
msgid "Unknown error"
msgstr "Нев╕дома помилка"

#: src/host.c:756
#, c-format
msgid "Resolving %s... "
msgstr "Визначення ╕мен╕ %s... "

#: src/host.c:800 src/host.c:829
#, c-format
msgid "failed: %s.\n"
msgstr "невдача: %s.\n"

#: src/host.c:809
msgid "failed: No IPv4/IPv6 addresses for host.\n"
msgstr ""

#: src/host.c:832
#, fuzzy
msgid "failed: timed out.\n"
msgstr "невдача: %s.\n"

#: src/html-url.c:298
#, c-format
msgid "%s: Cannot resolve incomplete link %s.\n"
msgstr "%s: Не можу роз╕брати неповне посилання %s.\n"

#: src/http.c:373 src/http.c:1549
#, c-format
msgid "Failed writing HTTP request: %s.\n"
msgstr "Помилка запису HTTP-запиту: %s.\n"

#: src/http.c:687
msgid "No headers, assuming HTTP/0.9"
msgstr ""

#: src/http.c:1198
msgid "Disabling SSL due to encountered errors.\n"
msgstr ""

#: src/http.c:1417
#, fuzzy, c-format
msgid "Reusing existing connection to %s:%d.\n"
msgstr "Повторне використання зв'язку з %s:%hu.\n"

#: src/http.c:1479
#, fuzzy, c-format
msgid "Failed writing to proxy: %s.\n"
msgstr "Помилка запису HTTP-запиту: %s.\n"

#: src/http.c:1488
#, fuzzy, c-format
msgid "Failed reading proxy response: %s\n"
msgstr "Помилка запису HTTP-запиту: %s.\n"

#: src/http.c:1508
#, c-format
msgid "Proxy tunneling failed: %s"
msgstr ""

#: src/http.c:1555
#, c-format
msgid "%s request sent, awaiting response... "
msgstr "%s-запит над╕слано, оч╕ку╓м в╕дпов╕д╕... "

#: src/http.c:1566
#, fuzzy
msgid "No data received.\n"
msgstr "Не отримано даних"

#: src/http.c:1573
#, c-format
msgid "Read error (%s) in headers.\n"
msgstr "Помилка читання в заголовках (%s).\n"

#. If the authentication header is missing or
#. unrecognized, there's no sense in retrying.
#: src/http.c:1658
msgid "Unknown authentication scheme.\n"
msgstr "Нев╕дома схема аутентиф╕кац╕╖.\n"

#: src/http.c:1682
msgid "Authorization failed.\n"
msgstr "Авторизац╕я невдалася.\n"

#: src/http.c:1696
msgid "Malformed status line"
msgstr "Несформований статусний рядок"

#: src/http.c:1698
msgid "(no description)"
msgstr "(без опису)"

#: src/http.c:1769
#, c-format
msgid "Location: %s%s\n"
msgstr "Адресa: %s%s\n"

#: src/http.c:1770 src/http.c:1867
msgid "unspecified"
msgstr "не вказано"

#: src/http.c:1771
msgid " [following]"
msgstr " [перех╕д]"

#. If `-c' is in use and the file has been fully downloaded (or
#. the remote file has shrunk), Wget effectively requests bytes
#. after the end of file and the server response with 416.
#: src/http.c:1817
msgid ""
"\n"
"    The file is already fully retrieved; nothing to do.\n"
