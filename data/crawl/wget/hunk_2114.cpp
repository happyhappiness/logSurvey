 "Obstaja ¾e pravilna simbolna povezava %s -> %s\n"
 "\n"
 
-#: src/ftp.c:1493
+#: src/ftp.c:1494
 #, c-format
 msgid "Creating symlink %s -> %s\n"
 msgstr "Ustvarjam simbolno povezavo %s -> %s\n"
 
-#: src/ftp.c:1503
+#: src/ftp.c:1504
 #, c-format
 msgid "Symlinks not supported, skipping symlink `%s'.\n"
 msgstr "Povezave niso podprte, preskakujem simbolno povezavo `%s'.\n"
 
-#: src/ftp.c:1515
+#: src/ftp.c:1516
 #, c-format
 msgid "Skipping directory `%s'.\n"
 msgstr "Preskakujem imenik `%s'.\n"
 
-#: src/ftp.c:1524
+#: src/ftp.c:1525
 #, c-format
 msgid "%s: unknown/unsupported file type.\n"
 msgstr "%s: neznana/nepodprta vrsta datoteke.\n"
 
-#: src/ftp.c:1551
+#: src/ftp.c:1552
 #, c-format
 msgid "%s: corrupt time-stamp.\n"
 msgstr "%s: okvarjena oznaèba èasa.\n"
 
-#: src/ftp.c:1579
+#: src/ftp.c:1580
 #, c-format
 msgid "Will not retrieve dirs since depth is %d (max %d).\n"
 msgstr "Ne jemljem imenikov, ker je globina %d (maksimalno %d).\n"
 
-#: src/ftp.c:1629
+#: src/ftp.c:1630
 #, c-format
 msgid "Not descending to `%s' as it is excluded/not-included.\n"
 msgstr "Ne grem v `%s', ker je izkljuèen ali pa ni vkljuèen.\n"
 
-#: src/ftp.c:1695 src/ftp.c:1709
+#: src/ftp.c:1696 src/ftp.c:1710
 #, c-format
 msgid "Rejecting `%s'.\n"
 msgstr "Zavraèam `%s'.\n"
 
-#: src/ftp.c:1757
+#: src/ftp.c:1733
+#, fuzzy, c-format
+msgid "Error matching %s against %s: %s\n"
+msgstr "Napaka pri pisanju v ,%s`: %s\n"
+
+#: src/ftp.c:1774
 #, c-format
 msgid "No matches on pattern `%s'.\n"
 msgstr "Ni zadetkov za vzorec `%s'.\n"
 
-#: src/ftp.c:1823
+#: src/ftp.c:1840
 #, fuzzy, c-format
 msgid "Wrote HTML-ized index to `%s' [%s].\n"
 msgstr "Kazalo v HTML zapisal kot `%s' [%ld].\n"
 
-#: src/ftp.c:1828
+#: src/ftp.c:1845
 #, c-format
 msgid "Wrote HTML-ized index to `%s'.\n"
 msgstr "Kazalo v HTML zapisal kot `%s'.\n"
 
-#: src/host.c:347
+#: src/host.c:348
 #, fuzzy
 msgid "Unknown host"
 msgstr "Neznana napaka"
 
-#: src/host.c:351
+#: src/host.c:352
 msgid "Temporary failure in name resolution"
 msgstr ""
 
-#: src/host.c:353
+#: src/host.c:354
 msgid "Unknown error"
 msgstr "Neznana napaka"
 
-#: src/host.c:714
+#: src/host.c:715
 #, c-format
 msgid "Resolving %s... "
 msgstr "Razre¹uje se %s..."
 
-#: src/host.c:761
+#: src/host.c:762
 msgid "failed: No IPv4/IPv6 addresses for host.\n"
 msgstr ""
 
-#: src/host.c:784
+#: src/host.c:785
 msgid "failed: timed out.\n"
 msgstr "spodletelo: zakasnitev.\n"
 
-#: src/html-url.c:288
+#: src/html-url.c:289
 #, c-format
 msgid "%s: Cannot resolve incomplete link %s.\n"
 msgstr "%s: Ni moè razre¹iti nepopolne povezave %s.\n"
 
-#: src/html-url.c:695
+#: src/html-url.c:696
 #, fuzzy, c-format
 msgid "%s: Invalid URL %s: %s\n"
 msgstr "%s: %s: Neveljavna vrednost '%s'\n"
 
-#: src/http.c:367
+#: src/http.c:368
 #, c-format
 msgid "Failed writing HTTP request: %s.\n"
 msgstr "Napaka pri pisanju zahteve HTTP: %s.\n"
 
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
 msgstr "Znova uporabljam povezavo z %s:%hu.\n"
 
-#: src/http.c:1683
+#: src/http.c:1687
 #, fuzzy, c-format
 msgid "Failed reading proxy response: %s\n"
 msgstr "Napaka pri pisanju zahteve HTTP: %s.\n"
 
-#: src/http.c:1703
+#: src/http.c:1707
 #, c-format
 msgid "Proxy tunneling failed: %s"
 msgstr ""
 
-#: src/http.c:1748
+#: src/http.c:1752
 #, c-format
 msgid "%s request sent, awaiting response... "
 msgstr "%s zahteva poslana, èakam odgovor... "
 
-#: src/http.c:1759
+#: src/http.c:1763
 #, fuzzy
 msgid "No data received.\n"
 msgstr "Brez sprejetih podatkov"
 
-#: src/http.c:1766
+#: src/http.c:1770
 #, c-format
 msgid "Read error (%s) in headers.\n"
 msgstr "Napaka pri branju glave (%s).\n"
 
-#: src/http.c:1812
+#: src/http.c:1816 src/http.c:2368
 #, fuzzy, c-format
 msgid ""
 "File `%s' already there; not retrieving.\n"
 "\n"
 msgstr "Datoteka `%s' ¾e obstaja, ne jemljem.\n"
 
-#: src/http.c:1965
+#: src/http.c:1969
 msgid "Unknown authentication scheme.\n"
 msgstr "Neznata metoda avtentifikacije.\n"
 
-#: src/http.c:1996
+#: src/http.c:2000
 msgid "Authorization failed.\n"
 msgstr "Avtorizacija neuspe¹na.\n"
 
-#: src/http.c:2010
+#: src/http.c:2014
 msgid "Malformed status line"
 msgstr "Zmalièena statusna linija"
 
-#: src/http.c:2012
+#: src/http.c:2016
 msgid "(no description)"
 msgstr "(brez opisa)"
 
-#: src/http.c:2075
+#: src/http.c:2082
 #, c-format
 msgid "Location: %s%s\n"
 msgstr "Polo¾aj: %s%s\n"
 
-#: src/http.c:2076 src/http.c:2183
+#: src/http.c:2083 src/http.c:2193
 msgid "unspecified"
 msgstr "nedoloèen"
 
-#: src/http.c:2077
+#: src/http.c:2084
 msgid " [following]"
 msgstr " [spremljam]"
 
-#: src/http.c:2133
+#: src/http.c:2140
 msgid ""
 "\n"
 "    The file is already fully retrieved; nothing to do.\n"
