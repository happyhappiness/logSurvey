 #. No luck.
 #. #### This message SUCKS.  We should see what was the
 #. reason that nothing was retrieved.
-#: src/ftp.c:1608
+#: src/ftp.c:1753
 #, c-format
 msgid "No matches on pattern `%s'.\n"
 msgstr "Няма съвпадения за пример `%s'.\n"
 
-#: src/ftp.c:1673
-#, c-format
-msgid "Wrote HTML-ized index to `%s' [%ld].\n"
+#: src/ftp.c:1819
+#, fuzzy, c-format
+msgid "Wrote HTML-ized index to `%s' [%s].\n"
 msgstr "Записах HTML-изиран индекс в `%s' [%ld].\n"
 
-#: src/ftp.c:1678
+#: src/ftp.c:1824
 #, c-format
 msgid "Wrote HTML-ized index to `%s'.\n"
 msgstr "Записах HTML-изиран индекс в `%s'.\n"
 
-#: src/gen_sslfunc.c:109
-msgid "Could not seed OpenSSL PRNG; disabling SSL.\n"
-msgstr "Не мога да намеря OpenSSL PRNG; продължавам без SSL.\n"
-
-#: src/getopt.c:454
+#: src/getopt.c:670
 #, c-format
 msgid "%s: option `%s' is ambiguous\n"
 msgstr "%s: опцията `%s' е многозначна\n"
 
-#: src/getopt.c:478
+#: src/getopt.c:695
 #, c-format
 msgid "%s: option `--%s' doesn't allow an argument\n"
 msgstr "%s: опцията `--%s' не позволява аргумент\n"
 
-#: src/getopt.c:483
+#: src/getopt.c:700
 #, c-format
 msgid "%s: option `%c%s' doesn't allow an argument\n"
 msgstr "%s: опцията `%c%s' не позволява аргумент\n"
 
-#: src/getopt.c:498
+#: src/getopt.c:718 src/getopt.c:891
 #, c-format
 msgid "%s: option `%s' requires an argument\n"
 msgstr "%s: опцията `%s' изисква аргумент\n"
 
 #. --option
-#: src/getopt.c:528
+#: src/getopt.c:747
 #, c-format
 msgid "%s: unrecognized option `--%s'\n"
 msgstr "%s: неразпозната опция `--%s'\n"
 
 #. +option or -option
-#: src/getopt.c:532
+#: src/getopt.c:751
 #, c-format
 msgid "%s: unrecognized option `%c%s'\n"
 msgstr "%s: неразпозната опция `%c%s'\n"
 
 #. 1003.2 specifies the format of this message.
-#: src/getopt.c:563
+#: src/getopt.c:777
 #, c-format
 msgid "%s: illegal option -- %c\n"
 msgstr "%s: невалидна опция -- %c\n"
 
+#: src/getopt.c:780
+#, fuzzy, c-format
+msgid "%s: invalid option -- %c\n"
+msgstr "%s: невалидна опция -- %c\n"
+
 #. 1003.2 specifies the format of this message.
-#: src/getopt.c:602
+#: src/getopt.c:810 src/getopt.c:940
 #, c-format
 msgid "%s: option requires an argument -- %c\n"
 msgstr "%s: опцията изисква аргумент -- %c\n"
 
-#: src/host.c:271
-#, c-format
-msgid "Resolving %s... "
-msgstr "Преобразувам %s... "
+#: src/getopt.c:857
+#, fuzzy, c-format
+msgid "%s: option `-W %s' is ambiguous\n"
+msgstr "%s: опцията `%s' е многозначна\n"
 
-#: src/host.c:278
-#, c-format
-msgid "failed: %s.\n"
-msgstr "неуспя: %s.\n"
+#: src/getopt.c:875
+#, fuzzy, c-format
+msgid "%s: option `-W %s' doesn't allow an argument\n"
+msgstr "%s: опцията `--%s' не позволява аргумент\n"
+
+#: src/host.c:347
+#, fuzzy
+msgid "Unknown host"
+msgstr "Непозната грешка"
 
-#: src/host.c:348
-msgid "Host not found"
-msgstr "Хостът не бе открит"
+#. Message modeled after what gai_strerror returns in similar
+#. circumstances.
+#: src/host.c:351
+msgid "Temporary failure in name resolution"
+msgstr ""
 
-#: src/host.c:350
+#: src/host.c:353
 msgid "Unknown error"
 msgstr "Непозната грешка"
 
-#: src/html-url.c:336
+#: src/host.c:714
 #, c-format
-msgid "%s: Cannot resolve incomplete link %s.\n"
-msgstr "%s: Не мога да изасня несъвършенния линк %s.\n"
+msgid "Resolving %s... "
+msgstr "Преобразувам %s... "
+
+#: src/host.c:761
+msgid "failed: No IPv4/IPv6 addresses for host.\n"
+msgstr ""
 
-#. this is fatal
-#: src/http.c:573
-msgid "Failed to set up an SSL context\n"
-msgstr "Неуспех при установяване на SSL контекст\n"
+#: src/host.c:784
+#, fuzzy
+msgid "failed: timed out.\n"
+msgstr "неуспя: %s.\n"
 
-#: src/http.c:579
+#: src/html-url.c:288
 #, c-format
-msgid "Failed to load certificates from %s\n"
-msgstr "Неуспех при зареждане на сертификати от %s\n"
+msgid "%s: Cannot resolve incomplete link %s.\n"
+msgstr "%s: Не мога да изасня несъвършенния линк %s.\n"
 
-#: src/http.c:583 src/http.c:591
-msgid "Trying without the specified certificate\n"
-msgstr "Опитвам без указаният сертификат\n"
+#: src/html-url.c:695
+#, fuzzy, c-format
+msgid "%s: Invalid URL %s: %s\n"
+msgstr "%s: Невалидна спецификация `%s'\n"
 
-#: src/http.c:587
+#: src/http.c:367
 #, c-format
-msgid "Failed to get certificate key from %s\n"
-msgstr "Неуспех при взимане на ключа към сертификата от %s\n"
+msgid "Failed writing HTTP request: %s.\n"
+msgstr "Неуспех при запис на HTTP искане: %s.\n"
 
-#: src/http.c:657 src/http.c:1620
-msgid "Unable to establish SSL connection.\n"
-msgstr "Немога да установя SSL връзка.\n"
+#: src/http.c:736
+msgid "No headers, assuming HTTP/0.9"
+msgstr ""
+
+#: src/http.c:1413
+msgid "Disabling SSL due to encountered errors.\n"
+msgstr ""
 
-#: src/http.c:666
+#: src/http.c:1566
 #, c-format
-msgid "Reusing connection to %s:%hu.\n"
+msgid "POST data file `%s' missing: %s\n"
+msgstr ""
+
+#: src/http.c:1615
+#, fuzzy, c-format
+msgid "Reusing existing connection to %s:%d.\n"
 msgstr "Използване на вече установена връзка към %s:%hu.\n"
 
-#: src/http.c:868
-#, c-format
-msgid "Failed writing HTTP request: %s.\n"
+#: src/http.c:1684
+#, fuzzy, c-format
+msgid "Failed reading proxy response: %s\n"
 msgstr "Неуспех при запис на HTTP искане: %s.\n"
 
-#: src/http.c:873
+#: src/http.c:1704
+#, c-format
+msgid "Proxy tunneling failed: %s"
+msgstr ""
+
+#: src/http.c:1749
 #, c-format
 msgid "%s request sent, awaiting response... "
 msgstr "%s изпратено искане, чакам отговор... "
 
-#: src/http.c:917
-msgid "End of file while parsing headers.\n"
-msgstr "Край на файла (EOF), докато превеждах заглавките.\n"
+#: src/http.c:1760
+#, fuzzy
+msgid "No data received.\n"
+msgstr "Не се получават данни"
 
-#: src/http.c:927
+#: src/http.c:1767
 #, c-format
 msgid "Read error (%s) in headers.\n"
 msgstr "Грешка при четене (%s) в заглавките.\n"
 
-#: src/http.c:962
-msgid "No data received"
-msgstr "Не се получават данни"
+#. If opt.noclobber is turned on and file already exists, do not
+#. retrieve the file
+#: src/http.c:1813
+#, fuzzy, c-format
+msgid ""
+"File `%s' already there; not retrieving.\n"
+"\n"
+msgstr "Файлът `%s' е вече тук, няма да го тегля.\n"
+
+#. If the authentication header is missing or
+#. unrecognized, there's no sense in retrying.
+#: src/http.c:1966
+msgid "Unknown authentication scheme.\n"
+msgstr "Непознат начин на удостоверение.\n"
 
-#: src/http.c:964
+#: src/http.c:1997
+msgid "Authorization failed.\n"
+msgstr "Грешка при удостоверяване.\n"
+
+#: src/http.c:2011
 msgid "Malformed status line"
 msgstr "Деформиран статус"
 
-#: src/http.c:969
+#: src/http.c:2013
 msgid "(no description)"
 msgstr "(без описание)"
 
-#: src/http.c:1101
-msgid "Authorization failed.\n"
-msgstr "Грешка при удостоверяване.\n"
-
-#: src/http.c:1108
-msgid "Unknown authentication scheme.\n"
-msgstr "Непознат начин на удостоверение.\n"
-
-#: src/http.c:1148
+#: src/http.c:2076
 #, c-format
 msgid "Location: %s%s\n"
 msgstr "Адрес: %s%s\n"
 
-#: src/http.c:1149 src/http.c:1282
+#: src/http.c:2077 src/http.c:2184
 msgid "unspecified"
 msgstr "неопределен"
 
-#: src/http.c:1150
+#: src/http.c:2078
 msgid " [following]"
 msgstr " [следва]"
 
-#: src/http.c:1213
+#. If `-c' is in use and the file has been fully downloaded (or
+#. the remote file has shrunk), Wget effectively requests bytes
+#. after the end of file and the server response with 416.
+#: src/http.c:2134
 msgid ""
 "\n"
 "    The file is already fully retrieved; nothing to do.\n"
