msgid "%s: option `-W %s' doesn't allow an argument\n"
msgstr "%s: избор `-W %s' не захтева аргумент\n"

#: src/host.c:368
#, fuzzy
msgid "Unknown host"
msgstr "Непозната грешка"

#. Message modeled after what gai_strerror returns in similar
#. circumstances.
#: src/host.c:372
msgid "Temporary failure in name resolution"
msgstr ""

#: src/host.c:374
msgid "Unknown error"
msgstr "Непозната грешка"

#: src/host.c:748
#, c-format
msgid "Resolving %s... "
msgstr "Тражим %s... "

#: src/host.c:792 src/host.c:839
#, c-format
msgid "failed: %s.\n"
msgstr "није успело: %s.\n"

#: src/host.c:801
msgid "failed: No IPv4/IPv6 addresses for host.\n"
msgstr ""

#: src/host.c:842
msgid "failed: timed out.\n"
msgstr "није успело: време је истекло.\n"

#: src/html-url.c:297
#, c-format
msgid "%s: Cannot resolve incomplete link %s.\n"
msgstr "%s: Не може се утврдити шта значи непотпуна веза %s.\n"

#: src/http.c:349 src/http.c:1504
#, c-format
msgid "Failed writing HTTP request: %s.\n"
msgstr "HTTP захтев није успео: %s.\n"

#: src/http.c:663
msgid "No headers, assuming HTTP/0.9"
msgstr ""

#. this is fatal
#: src/http.c:1151
msgid "Failed to set up an SSL context\n"
msgstr "Нисам успео да подесим SSL контекст\n"

#: src/http.c:1156
#, c-format
msgid "Failed to load certificates from %s\n"
msgstr "Није успело учитавање сертификата из %s\n"

#: src/http.c:1159 src/http.c:1166
msgid "Trying without the specified certificate\n"
msgstr "Покушавам приступ без потребног сертификата\n"

#: src/http.c:1163
#, c-format
msgid "Failed to get certificate key from %s\n"
msgstr "Не могу да преузмем кључ сертификата са %s\n"

#: src/http.c:1382
#, fuzzy, c-format
msgid "Reusing existing connection to %s:%d.\n"
msgstr "Поново користим везу са %s:%hu.\n"

#: src/http.c:1434
#, fuzzy, c-format
msgid "Failed writing to proxy: %s.\n"
msgstr "HTTP захтев није успео: %s.\n"

#: src/http.c:1443
#, fuzzy, c-format
msgid "Failed reading proxy response: %s\n"
msgstr "HTTP захтев није успео: %s.\n"

#: src/http.c:1463
#, c-format
msgid "Proxy tunneling failed: %s"
msgstr ""

#: src/http.c:1510
#, c-format
msgid "%s request sent, awaiting response... "
msgstr "%s захтев је послат, чека се одговор... "

#: src/http.c:1521
#, fuzzy
msgid "No data received.\n"
msgstr "Подаци нису примљени"

#: src/http.c:1528
#, c-format
msgid "Read error (%s) in headers.\n"
msgstr "Грешка у читању (%s) у заглављима.\n"

#. If we have tried it already, then there is not point
#. retrying it.
#: src/http.c:1595
msgid "Authorization failed.\n"
msgstr "Пријава није успела.\n"

#: src/http.c:1609
msgid "Unknown authentication scheme.\n"
msgstr "Начин пријаве није познат.\n"

#: src/http.c:1634
msgid "Malformed status line"
msgstr "Неисправна статусна линија"

#: src/http.c:1636
msgid "(no description)"
msgstr "(нема описа)"

#: src/http.c:1700
#, c-format
msgid "Location: %s%s\n"
msgstr "Место: %s%s\n"

#: src/http.c:1701 src/http.c:1801
msgid "unspecified"
msgstr "није наведено"

#: src/http.c:1702
msgid " [following]"
msgstr " [пратим]"

#. If `-c' is in use and the file has been fully downloaded (or
#. the remote file has shrunk), Wget effectively requests bytes
#. after the end of file and the server response with 416.
#: src/http.c:1751
msgid ""
"\n"
"    The file is already fully retrieved; nothing to do.\n"
