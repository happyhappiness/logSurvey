"Символьне посилання %s -> %s вже ╕сну╓.\n"
"\n"

#: src/ftp.c:1493
#, c-format
msgid "Creating symlink %s -> %s\n"
msgstr "Створю╓мо символьне посилання %s -> %s\n"

#: src/ftp.c:1503
#, c-format
msgid "Symlinks not supported, skipping symlink `%s'.\n"
msgstr "Символьн╕ посилання не п╕дтримуються, пропуска╓мо `%s'.\n"

#: src/ftp.c:1515
#, c-format
msgid "Skipping directory `%s'.\n"
msgstr "Пропуска╓мо каталог `%s'.\n"

#: src/ftp.c:1524
#, c-format
msgid "%s: unknown/unsupported file type.\n"
msgstr "%s: нев╕домий тип файлу (або не п╕дтриму╓ться).\n"

#: src/ftp.c:1551
#, c-format
msgid "%s: corrupt time-stamp.\n"
msgstr "%s: пошкоджена м╕тка часу.\n"

#: src/ftp.c:1579
#, c-format
msgid "Will not retrieve dirs since depth is %d (max %d).\n"
msgstr "Не завантажу╓мо каталоги оск╕льки глибина вже %d (максимум %d).\n"

#: src/ftp.c:1629
#, c-format
msgid "Not descending to `%s' as it is excluded/not-included.\n"
msgstr "Пропуска╓мо каталог `%s' з╕ списку виключення.\n"

#: src/ftp.c:1695 src/ftp.c:1709
#, c-format
msgid "Rejecting `%s'.\n"
msgstr "Пропуска╓мо `%s'.\n"

#  No luck.
#  #### This message SUCKS.  We should see what was the
#  reason that nothing was retrieved.
#: src/ftp.c:1757
#, c-format
msgid "No matches on pattern `%s'.\n"
msgstr "Нема╓ сп╕впадань з шаблоном `%s'.\n"

#: src/ftp.c:1823
#, fuzzy, c-format
msgid "Wrote HTML-ized index to `%s' [%s].\n"
msgstr "Л╕стинг у HTML-формат╕ записано у файл `%s' [%ld].\n"

#: src/ftp.c:1828
#, c-format
msgid "Wrote HTML-ized index to `%s'.\n"
msgstr "Л╕стинг у HTML-формат╕ записано у файл `%s'.\n"

#: src/host.c:347
#, fuzzy
msgid "Unknown host"
msgstr "Нев╕дома помилка"

#: src/host.c:351
msgid "Temporary failure in name resolution"
msgstr ""

#: src/host.c:353
msgid "Unknown error"
msgstr "Нев╕дома помилка"

#: src/host.c:714
#, c-format
msgid "Resolving %s... "
msgstr "Визначення ╕мен╕ %s... "

#: src/host.c:761
msgid "failed: No IPv4/IPv6 addresses for host.\n"
msgstr ""

#: src/host.c:784
msgid "failed: timed out.\n"
msgstr "невдача: тайм-аут.\n"

#: src/html-url.c:288
#, c-format
msgid "%s: Cannot resolve incomplete link %s.\n"
msgstr "%s: Не можу роз╕брати неповне посилання %s.\n"

#: src/html-url.c:695
#, fuzzy, c-format
msgid "%s: Invalid URL %s: %s\n"
msgstr "%s: %s: нев╕рне значення `%s'.\n"

#: src/http.c:367
#, c-format
msgid "Failed writing HTTP request: %s.\n"
msgstr "Помилка запису HTTP-запиту: %s.\n"

#: src/http.c:736
msgid "No headers, assuming HTTP/0.9"
msgstr ""

#: src/http.c:1413
msgid "Disabling SSL due to encountered errors.\n"
msgstr ""

#: src/http.c:1566
#, c-format
msgid "POST data file `%s' missing: %s\n"
msgstr ""

#: src/http.c:1615
#, fuzzy, c-format
msgid "Reusing existing connection to %s:%d.\n"
msgstr "Повторне використання зв'язку з %s:%hu.\n"

#: src/http.c:1683
#, fuzzy, c-format
msgid "Failed reading proxy response: %s\n"
msgstr "Помилка запису HTTP-запиту: %s.\n"

#: src/http.c:1703
#, c-format
msgid "Proxy tunneling failed: %s"
msgstr ""

#: src/http.c:1748
#, c-format
msgid "%s request sent, awaiting response... "
msgstr "%s-запит над╕слано, оч╕ку╓м в╕дпов╕д╕... "

#: src/http.c:1759
#, fuzzy
msgid "No data received.\n"
msgstr "Не отримано даних"

#: src/http.c:1766
#, c-format
msgid "Read error (%s) in headers.\n"
msgstr "Помилка читання в заголовках (%s).\n"

#: src/http.c:1812
#, fuzzy, c-format
msgid ""
"File `%s' already there; not retrieving.\n"
"\n"
msgstr "Файл `%s' вже ╓ тут, не завантажу╓мо.\n"

#: src/http.c:1965
msgid "Unknown authentication scheme.\n"
msgstr "Нев╕дома схема аутентиф╕кац╕╖.\n"

#: src/http.c:1996
msgid "Authorization failed.\n"
msgstr "Авторизац╕я невдалася.\n"

#: src/http.c:2010
msgid "Malformed status line"
msgstr "Несформований статусний рядок"

#: src/http.c:2012
msgid "(no description)"
msgstr "(без опису)"

#: src/http.c:2075
#, c-format
msgid "Location: %s%s\n"
msgstr "Адресa: %s%s\n"

#: src/http.c:2076 src/http.c:2183
msgid "unspecified"
msgstr "не вказано"

#: src/http.c:2077
msgid " [following]"
msgstr " [перех╕д]"

#: src/http.c:2133
msgid ""
"\n"
"    The file is already fully retrieved; nothing to do.\n"
