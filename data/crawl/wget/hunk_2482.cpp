 #. No luck.
 #. #### This message SUCKS.  We should see what was the
 #. reason that nothing was retrieved.
-#: src/ftp.c:1698
+#: src/ftp.c:1753
 #, c-format
 msgid "No matches on pattern `%s'.\n"
 msgstr "Nu s-au gãsit potriviri pentru tiparul `%s'.\n"
 
-#: src/ftp.c:1764
-#, c-format
-msgid "Wrote HTML-ized index to `%s' [%ld].\n"
+#: src/ftp.c:1819
+#, fuzzy, c-format
+msgid "Wrote HTML-ized index to `%s' [%s].\n"
 msgstr "S-a scris indexul HTML în `%s' [%ld].\n"
 
-#: src/ftp.c:1769
+#: src/ftp.c:1824
 #, c-format
 msgid "Wrote HTML-ized index to `%s'.\n"
 msgstr "S-a scris indexul HTML în `%s'\n"
 
-#: src/gen_sslfunc.c:117
-msgid "Could not seed OpenSSL PRNG; disabling SSL.\n"
-msgstr "Nu s-a selectat OpenSSL PRNG; dezactivare SSL.\n"
-
-#: src/getopt.c:675
+#: src/getopt.c:670
 #, c-format
 msgid "%s: option `%s' is ambiguous\n"
 msgstr "%s: opþiunea `%s' este ambiguã\n"
 
-#: src/getopt.c:700
+#: src/getopt.c:695
 #, c-format
 msgid "%s: option `--%s' doesn't allow an argument\n"
 msgstr "%s: opþiunea `--%s' nu permite un parametru\n"
 
-#: src/getopt.c:705
+#: src/getopt.c:700
 #, c-format
 msgid "%s: option `%c%s' doesn't allow an argument\n"
 msgstr "%s: opþiunea `%c%s' nu permite un parametru\n"
 
-#: src/getopt.c:723 src/getopt.c:896
+#: src/getopt.c:718 src/getopt.c:891
 #, c-format
 msgid "%s: option `%s' requires an argument\n"
 msgstr "%s: opþiunea `%s' necesitã un parametru\n"
 
 #. --option
-#: src/getopt.c:752
+#: src/getopt.c:747
 #, c-format
 msgid "%s: unrecognized option `--%s'\n"
 msgstr "%s: opþiune nerecunoscutã `--%s'\n"
 
 #. +option or -option
-#: src/getopt.c:756
+#: src/getopt.c:751
 #, c-format
 msgid "%s: unrecognized option `%c%s'\n"
 msgstr "%s: opþiune nerecunoscutã `%c%s'\n"
 
 #. 1003.2 specifies the format of this message.
-#: src/getopt.c:782
+#: src/getopt.c:777
 #, c-format
 msgid "%s: illegal option -- %c\n"
 msgstr "%s: opþiune ilegalã -- %c\n"
 
-#: src/getopt.c:785
+#: src/getopt.c:780
 #, c-format
 msgid "%s: invalid option -- %c\n"
 msgstr "%s: opþiune invalidã -- %c\n"
 
 #. 1003.2 specifies the format of this message.
-#: src/getopt.c:815 src/getopt.c:945
+#: src/getopt.c:810 src/getopt.c:940
 #, c-format
 msgid "%s: option requires an argument -- %c\n"
 msgstr "%s: opþiunea necesitã un parametru -- %c\n"
 
-#: src/getopt.c:862
+#: src/getopt.c:857
 #, c-format
 msgid "%s: option `-W %s' is ambiguous\n"
 msgstr "%s: opþiunea `W %s' este ambiguã\n"
 
-#: src/getopt.c:880
+#: src/getopt.c:875
 #, c-format
 msgid "%s: option `-W %s' doesn't allow an argument\n"
 msgstr "%s: opþiunea `-W %s' nu permite parametri\n"
 
-#: src/host.c:636
+#: src/host.c:347
+#, fuzzy
+msgid "Unknown host"
+msgstr "Eroare necunoscutã"
+
+#. Message modeled after what gai_strerror returns in similar
+#. circumstances.
+#: src/host.c:351
+msgid "Temporary failure in name resolution"
+msgstr ""
+
+#: src/host.c:353
+msgid "Unknown error"
+msgstr "Eroare necunoscutã"
+
+#: src/host.c:714
 #, c-format
 msgid "Resolving %s... "
 msgstr "Rezolvare %s... "
 
-#: src/host.c:656 src/host.c:672
-#, c-format
-msgid "failed: %s.\n"
-msgstr "eºuare: %s.\n"
+#: src/host.c:761
+msgid "failed: No IPv4/IPv6 addresses for host.\n"
+msgstr ""
 
-#: src/host.c:674
+#: src/host.c:784
 msgid "failed: timed out.\n"
 msgstr "eºuare: .expirat(ã)\n"
 
-#: src/host.c:762
-msgid "Host not found"
-msgstr "Host negãsit"
-
-#: src/host.c:764
-msgid "Unknown error"
-msgstr "Eroare necunoscutã"
-
-#: src/html-url.c:293
+#: src/html-url.c:288
 #, c-format
 msgid "%s: Cannot resolve incomplete link %s.\n"
 msgstr "%s: Nu s-a rezolvat linkul incomplet %s.\n"
 
-#. this is fatal
-#: src/http.c:674
-msgid "Failed to set up an SSL context\n"
-msgstr "S-a eºuat în setarea contextului SSL\n"
+#: src/html-url.c:695
+#, fuzzy, c-format
+msgid "%s: Invalid URL %s: %s\n"
+msgstr "%s: %s: Valoare invalidã `%s'.\n"
 
-#: src/http.c:680
+#: src/http.c:367
 #, c-format
-msgid "Failed to load certificates from %s\n"
-msgstr "S-a eºuat în încãrcarea certificatelor din %s\n"
-
-#: src/http.c:684 src/http.c:692
-msgid "Trying without the specified certificate\n"
-msgstr "Se încearcã fãrã certificatele specificate\n"
+msgid "Failed writing HTTP request: %s.\n"
+msgstr "Scriere cerere HTTP eºuatã: %s.\n"
 
-#: src/http.c:688
-#, c-format
-msgid "Failed to get certificate key from %s\n"
-msgstr "Nu s-a putut primi codul(key) certificatului de la %s\n"
+#: src/http.c:736
+msgid "No headers, assuming HTTP/0.9"
+msgstr ""
 
-#: src/http.c:761 src/http.c:1809
-msgid "Unable to establish SSL connection.\n"
-msgstr "Nu s-a putut stabili o conexiune SSL.\n"
+#: src/http.c:1413
+msgid "Disabling SSL due to encountered errors.\n"
+msgstr ""
 
-#: src/http.c:770
+#: src/http.c:1566
 #, c-format
-msgid "Reusing connection to %s:%hu.\n"
+msgid "POST data file `%s' missing: %s\n"
+msgstr ""
+
+#: src/http.c:1615
+#, fuzzy, c-format
+msgid "Reusing existing connection to %s:%d.\n"
 msgstr "Reutilizare conexiune cãtre %s:%hu.\n"
 
-#: src/http.c:1034
-#, c-format
-msgid "Failed writing HTTP request: %s.\n"
+#: src/http.c:1684
+#, fuzzy, c-format
+msgid "Failed reading proxy response: %s\n"
 msgstr "Scriere cerere HTTP eºuatã: %s.\n"
 
-#: src/http.c:1039
+#: src/http.c:1704
+#, c-format
+msgid "Proxy tunneling failed: %s"
+msgstr ""
+
+#: src/http.c:1749
 #, c-format
 msgid "%s request sent, awaiting response... "
 msgstr "Cerere %s trimisã, se aºteaptã rãspuns... "
 
-#: src/http.c:1083
-msgid "End of file while parsing headers.\n"
-msgstr "Sfârºit fiºier la analiza headerelor.\n"
+#: src/http.c:1760
+#, fuzzy
+msgid "No data received.\n"
+msgstr "Nici o datã recepþionatã"
 
-#: src/http.c:1093
+#: src/http.c:1767
 #, c-format
 msgid "Read error (%s) in headers.\n"
 msgstr "Eroare de citire (%s) în headere.\n"
 
-#: src/http.c:1128
-msgid "No data received"
-msgstr "Nici o datã recepþionatã"
+#. If opt.noclobber is turned on and file already exists, do not
+#. retrieve the file
+#: src/http.c:1813
+#, fuzzy, c-format
+msgid ""
+"File `%s' already there; not retrieving.\n"
+"\n"
+msgstr "Fiºierul `%s' existã deja, nu se mai aduce.\n"
+
+#. If the authentication header is missing or
+#. unrecognized, there's no sense in retrying.
+#: src/http.c:1966
+msgid "Unknown authentication scheme.\n"
+msgstr "Schemã autentificare necunoscutã.\n"
+
+#: src/http.c:1997
+msgid "Authorization failed.\n"
+msgstr "Autorizare eºuatã.\n"
 
-#: src/http.c:1130
+#: src/http.c:2011
 msgid "Malformed status line"
 msgstr "Linie de stare malformatã"
 
-#: src/http.c:1135
+#: src/http.c:2013
 msgid "(no description)"
 msgstr "(fãrã descriere)"
 
-#: src/http.c:1267
-msgid "Authorization failed.\n"
-msgstr "Autorizare eºuatã.\n"
-
-#: src/http.c:1274
-msgid "Unknown authentication scheme.\n"
-msgstr "Schemã autentificare necunoscutã.\n"
-
-#: src/http.c:1314
+#: src/http.c:2076
 #, c-format
 msgid "Location: %s%s\n"
 msgstr "Locaþie: %s%s\n"
 
-#: src/http.c:1315 src/http.c:1454
+#: src/http.c:2077 src/http.c:2184
 msgid "unspecified"
 msgstr "nespecificat(ã)"
 
-#: src/http.c:1316
+#: src/http.c:2078
 msgid " [following]"
 msgstr " [urmeazã]"
 
-#: src/http.c:1383
+#. If `-c' is in use and the file has been fully downloaded (or
+#. the remote file has shrunk), Wget effectively requests bytes
+#. after the end of file and the server response with 416.
+#: src/http.c:2134
 msgid ""
 "\n"
 "    The file is already fully retrieved; nothing to do.\n"
