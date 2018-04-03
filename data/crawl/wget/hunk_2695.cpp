 #. No luck.
 #. #### This message SUCKS.  We should see what was the
 #. reason that nothing was retrieved.
-#: src/ftp.c:1775
+#: src/ftp.c:1608
 #, c-format
 msgid "No matches on pattern `%s'.\n"
 msgstr "Няма съвпадения за пример `%s'.\n"
 
-#: src/ftp.c:1841
-#, fuzzy, c-format
-msgid "Wrote HTML-ized index to `%s' [%s].\n"
+#: src/ftp.c:1673
+#, c-format
+msgid "Wrote HTML-ized index to `%s' [%ld].\n"
 msgstr "Записах HTML-изиран индекс в `%s' [%ld].\n"
 
-#: src/ftp.c:1846
+#: src/ftp.c:1678
 #, c-format
 msgid "Wrote HTML-ized index to `%s'.\n"
 msgstr "Записах HTML-изиран индекс в `%s'.\n"
 
-#: src/getopt.c:675
+#: src/gen_sslfunc.c:109
+msgid "Could not seed OpenSSL PRNG; disabling SSL.\n"
+msgstr "Не мога да намеря OpenSSL PRNG; продължавам без SSL.\n"
+
+#: src/getopt.c:454
 #, c-format
 msgid "%s: option `%s' is ambiguous\n"
 msgstr "%s: опцията `%s' е многозначна\n"
 
-#: src/getopt.c:700
+#: src/getopt.c:478
 #, c-format
 msgid "%s: option `--%s' doesn't allow an argument\n"
 msgstr "%s: опцията `--%s' не позволява аргумент\n"
 
-#: src/getopt.c:705
+#: src/getopt.c:483
 #, c-format
 msgid "%s: option `%c%s' doesn't allow an argument\n"
 msgstr "%s: опцията `%c%s' не позволява аргумент\n"
 
-#: src/getopt.c:723 src/getopt.c:896
+#: src/getopt.c:498
 #, c-format
 msgid "%s: option `%s' requires an argument\n"
 msgstr "%s: опцията `%s' изисква аргумент\n"
 
 #. --option
-#: src/getopt.c:752
+#: src/getopt.c:528
 #, c-format
 msgid "%s: unrecognized option `--%s'\n"
 msgstr "%s: неразпозната опция `--%s'\n"
 
 #. +option or -option
-#: src/getopt.c:756
+#: src/getopt.c:532
 #, c-format
 msgid "%s: unrecognized option `%c%s'\n"
 msgstr "%s: неразпозната опция `%c%s'\n"
 
 #. 1003.2 specifies the format of this message.
-#: src/getopt.c:782
+#: src/getopt.c:563
 #, c-format
 msgid "%s: illegal option -- %c\n"
 msgstr "%s: невалидна опция -- %c\n"
 
-#: src/getopt.c:785
-#, fuzzy, c-format
-msgid "%s: invalid option -- %c\n"
-msgstr "%s: невалидна опция -- %c\n"
-
 #. 1003.2 specifies the format of this message.
-#: src/getopt.c:815 src/getopt.c:945
+#: src/getopt.c:602
 #, c-format
 msgid "%s: option requires an argument -- %c\n"
 msgstr "%s: опцията изисква аргумент -- %c\n"
 
-#: src/getopt.c:862
-#, fuzzy, c-format
-msgid "%s: option `-W %s' is ambiguous\n"
-msgstr "%s: опцията `%s' е многозначна\n"
-
-#: src/getopt.c:880
-#, fuzzy, c-format
-msgid "%s: option `-W %s' doesn't allow an argument\n"
-msgstr "%s: опцията `--%s' не позволява аргумент\n"
-
-#: src/host.c:371
-#, fuzzy
-msgid "Unknown host"
-msgstr "Непозната грешка"
-
-#. Message modeled after what gai_strerror returns in similar
-#. circumstances.
-#: src/host.c:375
-msgid "Temporary failure in name resolution"
-msgstr ""
-
-#: src/host.c:377
-msgid "Unknown error"
-msgstr "Непозната грешка"
-
-#: src/host.c:756
+#: src/host.c:271
 #, c-format
 msgid "Resolving %s... "
 msgstr "Преобразувам %s... "
 
-#: src/host.c:800 src/host.c:829
+#: src/host.c:278
 #, c-format
 msgid "failed: %s.\n"
 msgstr "неуспя: %s.\n"
 
-#: src/host.c:809
-msgid "failed: No IPv4/IPv6 addresses for host.\n"
-msgstr ""
+#: src/host.c:348
+msgid "Host not found"
+msgstr "Хостът не бе открит"
 
-#: src/host.c:832
-#, fuzzy
-msgid "failed: timed out.\n"
-msgstr "неуспя: %s.\n"
+#: src/host.c:350
+msgid "Unknown error"
+msgstr "Непозната грешка"
 
-#: src/html-url.c:298
+#: src/html-url.c:336
 #, c-format
 msgid "%s: Cannot resolve incomplete link %s.\n"
 msgstr "%s: Не мога да изасня несъвършенния линк %s.\n"
 
-#: src/http.c:373 src/http.c:1549
-#, c-format
-msgid "Failed writing HTTP request: %s.\n"
-msgstr "Неуспех при запис на HTTP искане: %s.\n"
+#. this is fatal
+#: src/http.c:573
+msgid "Failed to set up an SSL context\n"
+msgstr "Неуспех при установяване на SSL контекст\n"
 
-#: src/http.c:687
-msgid "No headers, assuming HTTP/0.9"
-msgstr ""
+#: src/http.c:579
+#, c-format
+msgid "Failed to load certificates from %s\n"
+msgstr "Неуспех при зареждане на сертификати от %s\n"
 
-#: src/http.c:1198
-msgid "Disabling SSL due to encountered errors.\n"
-msgstr ""
+#: src/http.c:583 src/http.c:591
+msgid "Trying without the specified certificate\n"
+msgstr "Опитвам без указаният сертификат\n"
 
-#: src/http.c:1417
-#, fuzzy, c-format
-msgid "Reusing existing connection to %s:%d.\n"
-msgstr "Използване на вече установена връзка към %s:%hu.\n"
+#: src/http.c:587
+#, c-format
+msgid "Failed to get certificate key from %s\n"
+msgstr "Неуспех при взимане на ключа към сертификата от %s\n"
 
-#: src/http.c:1479
-#, fuzzy, c-format
-msgid "Failed writing to proxy: %s.\n"
-msgstr "Неуспех при запис на HTTP искане: %s.\n"
+#: src/http.c:657 src/http.c:1620
+msgid "Unable to establish SSL connection.\n"
+msgstr "Немога да установя SSL връзка.\n"
 
-#: src/http.c:1488
-#, fuzzy, c-format
-msgid "Failed reading proxy response: %s\n"
-msgstr "Неуспех при запис на HTTP искане: %s.\n"
+#: src/http.c:666
+#, c-format
+msgid "Reusing connection to %s:%hu.\n"
+msgstr "Използване на вече установена връзка към %s:%hu.\n"
 
-#: src/http.c:1508
+#: src/http.c:868
 #, c-format
-msgid "Proxy tunneling failed: %s"
-msgstr ""
+msgid "Failed writing HTTP request: %s.\n"
+msgstr "Неуспех при запис на HTTP искане: %s.\n"
 
-#: src/http.c:1555
+#: src/http.c:873
 #, c-format
 msgid "%s request sent, awaiting response... "
 msgstr "%s изпратено искане, чакам отговор... "
 
-#: src/http.c:1566
-#, fuzzy
-msgid "No data received.\n"
-msgstr "Не се получават данни"
+#: src/http.c:917
+msgid "End of file while parsing headers.\n"
+msgstr "Край на файла (EOF), докато превеждах заглавките.\n"
 
-#: src/http.c:1573
+#: src/http.c:927
 #, c-format
 msgid "Read error (%s) in headers.\n"
 msgstr "Грешка при четене (%s) в заглавките.\n"
 
-#. If the authentication header is missing or
-#. unrecognized, there's no sense in retrying.
-#: src/http.c:1658
-msgid "Unknown authentication scheme.\n"
-msgstr "Непознат начин на удостоверение.\n"
-
-#: src/http.c:1682
-msgid "Authorization failed.\n"
-msgstr "Грешка при удостоверяване.\n"
+#: src/http.c:962
+msgid "No data received"
+msgstr "Не се получават данни"
 
-#: src/http.c:1696
+#: src/http.c:964
 msgid "Malformed status line"
 msgstr "Деформиран статус"
 
-#: src/http.c:1698
+#: src/http.c:969
 msgid "(no description)"
 msgstr "(без описание)"
 
-#: src/http.c:1769
+#: src/http.c:1101
+msgid "Authorization failed.\n"
+msgstr "Грешка при удостоверяване.\n"
+
+#: src/http.c:1108
+msgid "Unknown authentication scheme.\n"
+msgstr "Непознат начин на удостоверение.\n"
+
+#: src/http.c:1148
 #, c-format
 msgid "Location: %s%s\n"
 msgstr "Адрес: %s%s\n"
 
-#: src/http.c:1770 src/http.c:1867
+#: src/http.c:1149 src/http.c:1282
 msgid "unspecified"
 msgstr "неопределен"
 
-#: src/http.c:1771
+#: src/http.c:1150
 msgid " [following]"
 msgstr " [следва]"
 
-#. If `-c' is in use and the file has been fully downloaded (or
-#. the remote file has shrunk), Wget effectively requests bytes
-#. after the end of file and the server response with 416.
-#: src/http.c:1817
+#: src/http.c:1213
 msgid ""
 "\n"
 "    The file is already fully retrieved; nothing to do.\n"
