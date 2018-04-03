"Већ имам исправну везу %s -> %s\n"
"\n"

#: src/ftp.c:1533
#, c-format
msgid "Creating symlink %s -> %s\n"
msgstr "Правим везу %s -> %s\n"

#: src/ftp.c:1543
#, fuzzy, c-format
msgid "Symlinks not supported, skipping symlink %s.\n"
msgstr "Симболичке везе нису подржане, прескачем везу „%s‟.\n"

#: src/ftp.c:1555
#, fuzzy, c-format
msgid "Skipping directory %s.\n"
msgstr "Прескачем директоријум „%s‟.\n"

#: src/ftp.c:1564
#, c-format
msgid "%s: unknown/unsupported file type.\n"
msgstr "%s: тип датотеке је непознат или није подржан.\n"

#: src/ftp.c:1591
#, c-format
msgid "%s: corrupt time-stamp.\n"
msgstr "%s: неисправно време.\n"

#: src/ftp.c:1619
#, c-format
msgid "Will not retrieve dirs since depth is %d (max %d).\n"
msgstr "Нећу преузети директоријуме пошто је дубина %d (највише %d).\n"

#: src/ftp.c:1669
#, fuzzy, c-format
msgid "Not descending to %s as it is excluded/not-included.\n"
msgstr "Не спуштам се у „%s‟ пошто је занемарен.\n"

#: src/ftp.c:1735 src/ftp.c:1749
#, fuzzy, c-format
msgid "Rejecting %s.\n"
msgstr "Одбијам „%s‟.\n"

#: src/ftp.c:1772
#, fuzzy, c-format
msgid "Error matching %s against %s: %s\n"
msgstr "Грешка при упису у „%s‟: %s\n"

#: src/ftp.c:1814
#, fuzzy, c-format
msgid "No matches on pattern %s.\n"
msgstr "Ниједна датотека не одговара шаблону „%s‟.\n"

#: src/ftp.c:1880
#, fuzzy, c-format
msgid "Wrote HTML-ized index to %s [%s].\n"
msgstr "Списак је пребачен у HTML и записан у „%s‟ [%ld].\n"

#: src/ftp.c:1885
#, fuzzy, c-format
msgid "Wrote HTML-ized index to %s.\n"
msgstr "Списак је пребачен у HTML и записан у „%s‟.\n"

#: src/host.c:348
#, fuzzy
msgid "Unknown host"
msgstr "Непозната грешка"

#: src/host.c:352
msgid "Temporary failure in name resolution"
msgstr ""

#: src/host.c:354
msgid "Unknown error"
msgstr "Непозната грешка"

#: src/host.c:715
#, c-format
msgid "Resolving %s... "
msgstr "Тражим %s... "

#: src/host.c:763
msgid "failed: No IPv4/IPv6 addresses for host.\n"
msgstr ""

#: src/host.c:786
msgid "failed: timed out.\n"
msgstr "није успело: време је истекло.\n"

#: src/html-url.c:289
#, c-format
msgid "%s: Cannot resolve incomplete link %s.\n"
msgstr "%s: Не може се утврдити шта значи непотпуна веза %s.\n"

#: src/html-url.c:696
#, fuzzy, c-format
msgid "%s: Invalid URL %s: %s\n"
msgstr "%s: %s: Неисправна вредност `%s'.\n"

#: src/http.c:368
#, c-format
msgid "Failed writing HTTP request: %s.\n"
msgstr "HTTP захтев није успео: %s.\n"

#: src/http.c:745
msgid "No headers, assuming HTTP/0.9"
msgstr ""

#: src/http.c:1430
msgid "Disabling SSL due to encountered errors.\n"
msgstr ""

#: src/http.c:1548
#, c-format
msgid "POST data file %s missing: %s\n"
msgstr ""

#: src/http.c:1632
#, fuzzy, c-format
msgid "Reusing existing connection to %s:%d.\n"
msgstr "Поново користим везу са %s:%hu.\n"

#: src/http.c:1701
#, fuzzy, c-format
msgid "Failed reading proxy response: %s\n"
msgstr "HTTP захтев није успео: %s.\n"

#: src/http.c:1721
#, c-format
msgid "Proxy tunneling failed: %s"
msgstr ""

#: src/http.c:1766
#, c-format
msgid "%s request sent, awaiting response... "
msgstr "%s захтев је послат, чека се одговор... "

#: src/http.c:1777
#, fuzzy
msgid "No data received.\n"
msgstr "Подаци нису примљени"

#: src/http.c:1784
#, c-format
msgid "Read error (%s) in headers.\n"
msgstr "Грешка у читању (%s) у заглављима.\n"

#: src/http.c:1831 src/http.c:2385
#, fuzzy, c-format
msgid ""
"File %s already there; not retrieving.\n"
"\n"
msgstr "Датотека „%s‟ већ постоји, не преузимам поново.\n"

#: src/http.c:1985
msgid "Unknown authentication scheme.\n"
msgstr "Начин пријаве није познат.\n"

#: src/http.c:2016
msgid "Authorization failed.\n"
msgstr "Пријава није успела.\n"

#: src/http.c:2030
msgid "Malformed status line"
msgstr "Неисправна статусна линија"

#: src/http.c:2032
msgid "(no description)"
msgstr "(нема описа)"

#: src/http.c:2098
#, c-format
msgid "Location: %s%s\n"
msgstr "Место: %s%s\n"

#: src/http.c:2099 src/http.c:2209
msgid "unspecified"
msgstr "није наведено"

#: src/http.c:2100
msgid " [following]"
msgstr " [пратим]"

#: src/http.c:2156
msgid ""
"\n"
"    The file is already fully retrieved; nothing to do.\n"
