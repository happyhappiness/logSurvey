 msgstr "%s: Ni moè razre¹iti nepopolne povezave %s.\n"
 
 #: src/html-url.c:696
-#, fuzzy, c-format
+#, c-format
 msgid "%s: Invalid URL %s: %s\n"
-msgstr "%s: %s: Neveljavna vrednost '%s'\n"
+msgstr "%s: Neveljaven URL %s: %s\n"
 
 #: src/http.c:368
 #, c-format
 msgid "Failed writing HTTP request: %s.\n"
 msgstr "Napaka pri pisanju zahteve HTTP: %s.\n"
 
-#: src/http.c:737
+#: src/http.c:745
 msgid "No headers, assuming HTTP/0.9"
-msgstr ""
+msgstr "Ni glav, privzema se HTTP/0.9"
 
-#: src/http.c:1417
+#: src/http.c:1430
 msgid "Disabling SSL due to encountered errors.\n"
-msgstr ""
-
-#: src/http.c:1570
-#, c-format
-msgid "POST data file `%s' missing: %s\n"
-msgstr ""
+msgstr "SSL se onemogoèa zaradi opa¾enih te¾av.\n"
 
-#: src/http.c:1619
+#: src/http.c:1548
 #, fuzzy, c-format
+msgid "POST data file %s missing: %s\n"
+msgstr "Manjka podatkovna datoteka ,%s` za POST: %s\n"
+
+#: src/http.c:1632
+#, c-format
 msgid "Reusing existing connection to %s:%d.\n"
-msgstr "Znova uporabljam povezavo z %s:%hu.\n"
+msgstr "Znova se uporablja povezava z %s:%d.\n"
 
-#: src/http.c:1687
-#, fuzzy, c-format
+#: src/http.c:1701
+#, c-format
 msgid "Failed reading proxy response: %s\n"
-msgstr "Napaka pri pisanju zahteve HTTP: %s.\n"
+msgstr "Napaka pri branju odgovora posrednika: %s\n"
 
-#: src/http.c:1707
+#: src/http.c:1721
 #, c-format
 msgid "Proxy tunneling failed: %s"
-msgstr ""
+msgstr "Posredni¹ko tuneliranje spodletelo: %s"
 
-#: src/http.c:1752
+#: src/http.c:1766
 #, c-format
 msgid "%s request sent, awaiting response... "
 msgstr "%s zahteva poslana, èakam odgovor... "
 
-#: src/http.c:1763
-#, fuzzy
+#: src/http.c:1777
 msgid "No data received.\n"
-msgstr "Brez sprejetih podatkov"
+msgstr "Brez sprejetih podatkov.\n"
 
-#: src/http.c:1770
+#: src/http.c:1784
 #, c-format
 msgid "Read error (%s) in headers.\n"
 msgstr "Napaka pri branju glave (%s).\n"
 
-#: src/http.c:1816 src/http.c:2368
+#: src/http.c:1831 src/http.c:2385
 #, fuzzy, c-format
 msgid ""
-"File `%s' already there; not retrieving.\n"
+"File %s already there; not retrieving.\n"
+"\n"
+msgstr ""
+"Datoteka ,%s` ¾e obstaja, ne jemljem.\n"
 "\n"
-msgstr "Datoteka `%s' ¾e obstaja, ne jemljem.\n"
 
-#: src/http.c:1969
+#: src/http.c:1985
 msgid "Unknown authentication scheme.\n"
-msgstr "Neznata metoda avtentifikacije.\n"
+msgstr "Neznata metoda avtentikacije.\n"
 
-#: src/http.c:2000
+#: src/http.c:2016
 msgid "Authorization failed.\n"
 msgstr "Avtorizacija neuspe¹na.\n"
 
-#: src/http.c:2014
+#: src/http.c:2030
 msgid "Malformed status line"
 msgstr "Zmalièena statusna linija"
 
-#: src/http.c:2016
+#: src/http.c:2032
 msgid "(no description)"
 msgstr "(brez opisa)"
 
-#: src/http.c:2082
+#: src/http.c:2098
 #, c-format
 msgid "Location: %s%s\n"
 msgstr "Polo¾aj: %s%s\n"
 
-#: src/http.c:2083 src/http.c:2193
+#: src/http.c:2099 src/http.c:2209
 msgid "unspecified"
 msgstr "nedoloèen"
 
-#: src/http.c:2084
+#: src/http.c:2100
 msgid " [following]"
 msgstr " [spremljam]"
 
-#: src/http.c:2140
+#: src/http.c:2156
 msgid ""
 "\n"
 "    The file is already fully retrieved; nothing to do.\n"
