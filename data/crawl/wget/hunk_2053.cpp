 "Символичната връзка е вече поправена %s -> %s.\n"
 "\n"
 
-#: src/ftp.c:1493
+#: src/ftp.c:1494
 #, c-format
 msgid "Creating symlink %s -> %s\n"
 msgstr "Създавам символична връзка %s -> %s\n"
 
-#: src/ftp.c:1503
+#: src/ftp.c:1504
 #, c-format
 msgid "Symlinks not supported, skipping symlink `%s'.\n"
 msgstr "Символичните връзки не са поддържат, пропускам `%s'.\n"
 
-#: src/ftp.c:1515
+#: src/ftp.c:1516
 #, c-format
 msgid "Skipping directory `%s'.\n"
 msgstr "Пропускам директория `%s'.\n"
 
-#: src/ftp.c:1524
+#: src/ftp.c:1525
 #, c-format
 msgid "%s: unknown/unsupported file type.\n"
 msgstr "%s: неизвестен/неподдържан вид файл.\n"
 
-#: src/ftp.c:1551
+#: src/ftp.c:1552
 #, c-format
 msgid "%s: corrupt time-stamp.\n"
 msgstr "%s: недостоверен времеви печат.\n"
 
-#: src/ftp.c:1579
+#: src/ftp.c:1580
 #, c-format
 msgid "Will not retrieve dirs since depth is %d (max %d).\n"
 msgstr "Няма да тегля директории, защото дълбочината е %d (максимум %d).\n"
 
-#: src/ftp.c:1629
+#: src/ftp.c:1630
 #, c-format
 msgid "Not descending to `%s' as it is excluded/not-included.\n"
 msgstr "Не влизам в `%s', тъй като тя е изключенa/не е включенa.\n"
 
-#: src/ftp.c:1695 src/ftp.c:1709
+#: src/ftp.c:1696 src/ftp.c:1710
 #, c-format
 msgid "Rejecting `%s'.\n"
 msgstr "Отказвам `%s'.\n"
 
-#: src/ftp.c:1757
+#: src/ftp.c:1733
+#, fuzzy, c-format
+msgid "Error matching %s against %s: %s\n"
+msgstr "Грешка при запис на `%s': %s\n"
+
+#: src/ftp.c:1774
 #, c-format
 msgid "No matches on pattern `%s'.\n"
 msgstr "Няма съвпадения за пример `%s'.\n"
 
-#: src/ftp.c:1823
+#: src/ftp.c:1840
 #, fuzzy, c-format
 msgid "Wrote HTML-ized index to `%s' [%s].\n"
 msgstr "Записах HTML-изиран индекс в `%s' [%ld].\n"
 
-#: src/ftp.c:1828
+#: src/ftp.c:1845
 #, c-format
 msgid "Wrote HTML-ized index to `%s'.\n"
 msgstr "Записах HTML-изиран индекс в `%s'.\n"
 
-#: src/host.c:347
+#: src/host.c:348
 #, fuzzy
 msgid "Unknown host"
 msgstr "Непозната грешка"
 
-#: src/host.c:351
+#: src/host.c:352
 msgid "Temporary failure in name resolution"
 msgstr ""
 
-#: src/host.c:353
+#: src/host.c:354
 msgid "Unknown error"
 msgstr "Непозната грешка"
 
-#: src/host.c:714
+#: src/host.c:715
 #, c-format
 msgid "Resolving %s... "
 msgstr "Преобразувам %s... "
 
-#: src/host.c:761
+#: src/host.c:762
 msgid "failed: No IPv4/IPv6 addresses for host.\n"
 msgstr ""
 
-#: src/host.c:784
+#: src/host.c:785
 #, fuzzy
 msgid "failed: timed out.\n"
 msgstr "неуспя: %s.\n"
 
-#: src/html-url.c:288
+#: src/html-url.c:289
 #, c-format
 msgid "%s: Cannot resolve incomplete link %s.\n"
 msgstr "%s: Не мога да изасня несъвършенния линк %s.\n"
 
-#: src/html-url.c:695
+#: src/html-url.c:696
 #, fuzzy, c-format
 msgid "%s: Invalid URL %s: %s\n"
 msgstr "%s: Невалидна спецификация `%s'\n"
 
-#: src/http.c:367
+#: src/http.c:368
 #, c-format
 msgid "Failed writing HTTP request: %s.\n"
 msgstr "Неуспех при запис на HTTP искане: %s.\n"
 
-#: src/http.c:736
+#: src/http.c:737
 msgid "No headers, assuming HTTP/0.9"
 msgstr ""
 
-#: src/http.c:1413
+#: src/http.c:1417
 msgid "Disabling SSL due to encountered errors.\n"
 msgstr ""
 
-#: src/http.c:1566
+#: src/http.c:1570
 #, c-format
 msgid "POST data file `%s' missing: %s\n"
 msgstr ""
 
-#: src/http.c:1615
+#: src/http.c:1619
 #, fuzzy, c-format
 msgid "Reusing existing connection to %s:%d.\n"
 msgstr "Използване на вече установена връзка към %s:%hu.\n"
 
-#: src/http.c:1683
+#: src/http.c:1687
 #, fuzzy, c-format
 msgid "Failed reading proxy response: %s\n"
 msgstr "Неуспех при запис на HTTP искане: %s.\n"
 
-#: src/http.c:1703
+#: src/http.c:1707
 #, c-format
 msgid "Proxy tunneling failed: %s"
 msgstr ""
 
-#: src/http.c:1748
+#: src/http.c:1752
 #, c-format
 msgid "%s request sent, awaiting response... "
 msgstr "%s изпратено искане, чакам отговор... "
 
-#: src/http.c:1759
+#: src/http.c:1763
 #, fuzzy
 msgid "No data received.\n"
 msgstr "Не се получават данни"
 
-#: src/http.c:1766
+#: src/http.c:1770
 #, c-format
 msgid "Read error (%s) in headers.\n"
 msgstr "Грешка при четене (%s) в заглавките.\n"
 
-#: src/http.c:1812
+#: src/http.c:1816 src/http.c:2368
 #, fuzzy, c-format
 msgid ""
 "File `%s' already there; not retrieving.\n"
 "\n"
 msgstr "Файлът `%s' е вече тук, няма да го тегля.\n"
 
-#: src/http.c:1965
+#: src/http.c:1969
 msgid "Unknown authentication scheme.\n"
 msgstr "Непознат начин на удостоверение.\n"
 
-#: src/http.c:1996
+#: src/http.c:2000
 msgid "Authorization failed.\n"
 msgstr "Грешка при удостоверяване.\n"
 
-#: src/http.c:2010
+#: src/http.c:2014
 msgid "Malformed status line"
 msgstr "Деформиран статус"
 
-#: src/http.c:2012
+#: src/http.c:2016
 msgid "(no description)"
 msgstr "(без описание)"
 
-#: src/http.c:2075
+#: src/http.c:2082
 #, c-format
 msgid "Location: %s%s\n"
 msgstr "Адрес: %s%s\n"
 
-#: src/http.c:2076 src/http.c:2183
+#: src/http.c:2083 src/http.c:2193
 msgid "unspecified"
 msgstr "неопределен"
 
-#: src/http.c:2077
+#: src/http.c:2084
 msgid " [following]"
 msgstr " [следва]"
 
-#: src/http.c:2133
+#: src/http.c:2140
 msgid ""
 "\n"
 "    The file is already fully retrieved; nothing to do.\n"
