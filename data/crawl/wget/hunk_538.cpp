 "Dagoeneko baduka link simboliko zuzena %s -> %s\n"
 "\n"
 
-#: src/ftp.c:1533
+#: src/ftp.c:1788
 #, c-format
 msgid "Creating symlink %s -> %s\n"
 msgstr "Link sinbolikoa sortzen %s -> %s\n"
 
-#: src/ftp.c:1543
+#: src/ftp.c:1798
 #, fuzzy, c-format
 msgid "Symlinks not supported, skipping symlink %s.\n"
 msgstr "Link sinbolikoak ez daude onartuak, `%s' link sinbolikoa baztetzen.\n"
 
-#: src/ftp.c:1555
+#: src/ftp.c:1810
 #, fuzzy, c-format
 msgid "Skipping directory %s.\n"
 msgstr "Direktorioa utzitzen `%s'.\n"
 
-#: src/ftp.c:1564
+#: src/ftp.c:1819
 #, c-format
 msgid "%s: unknown/unsupported file type.\n"
 msgstr "%s: ezagun/euskarririk gabeko fitxategi mota.\n"
 
-#: src/ftp.c:1591
+#: src/ftp.c:1856
 #, c-format
 msgid "%s: corrupt time-stamp.\n"
 msgstr "%s: ordu zigilu okerra.\n"
 
-#: src/ftp.c:1619
+#: src/ftp.c:1878
 #, c-format
 msgid "Will not retrieve dirs since depth is %d (max %d).\n"
 msgstr "Ez dira direktorio gehiago jasoko, sakonera %d-koa delako (mas %d).\n"
 
-#: src/ftp.c:1669
+#: src/ftp.c:1928
 #, fuzzy, c-format
 msgid "Not descending to %s as it is excluded/not-included.\n"
 msgstr "Ez jaisten `%s'ra, ez baitago sartua edo exkluditua dago.\n"
 
-#: src/ftp.c:1735 src/ftp.c:1749
+#: src/ftp.c:1994 src/ftp.c:2008
 #, fuzzy, c-format
 msgid "Rejecting %s.\n"
 msgstr "`%s' ez onartzen.\n"
 
-#: src/ftp.c:1772
+#: src/ftp.c:2031
 #, fuzzy, c-format
 msgid "Error matching %s against %s: %s\n"
 msgstr "Errorea `%s' idazterakoan: %s\n"
 
-#: src/ftp.c:1814
+#: src/ftp.c:2073
 #, fuzzy, c-format
 msgid "No matches on pattern %s.\n"
 msgstr "`%s' ereduarekin ez du lotzen.\n"
 
-#: src/ftp.c:1880
+#: src/ftp.c:2144
 #, fuzzy, c-format
 msgid "Wrote HTML-ized index to %s [%s].\n"
 msgstr "Idatzia HTMLizatutako index-a `%s'-en [%ld].\n"
 
-#: src/ftp.c:1885
+#: src/ftp.c:2149
 #, fuzzy, c-format
 msgid "Wrote HTML-ized index to %s.\n"
 msgstr "Idatzia HTMLzatutako index-a '%s'-en.\n"
 
-#: src/host.c:348
+#: src/gnutls.c:219 src/openssl.c:495
+msgid "ERROR"
+msgstr ""
+
+#: src/gnutls.c:219 src/openssl.c:495
+msgid "WARNING"
+msgstr ""
+
+#: src/gnutls.c:225 src/openssl.c:504
+#, c-format
+msgid "%s: No certificate presented by %s.\n"
+msgstr ""
+
+#: src/gnutls.c:233
+#, c-format
+msgid "%s: The certificate of %s is not trusted.\n"
+msgstr ""
+
+#: src/gnutls.c:239
+#, c-format
+msgid "%s: The certificate of %s hasn't got a known issuer.\n"
+msgstr ""
+
+#: src/gnutls.c:245
+#, c-format
+msgid "%s: The certificate of %s has been revoked.\n"
+msgstr ""
+
+#: src/gnutls.c:259
+#, c-format
+msgid "Error initializing X509 certificate: %s\n"
+msgstr ""
+
+#: src/gnutls.c:268
+msgid "No certificate found\n"
+msgstr ""
+
+#: src/gnutls.c:275
+#, fuzzy, c-format
+msgid "Error parsing certificate: %s\n"
+msgstr "Proxy URLa parseatzen errorea %s: %s.\n"
+
+#: src/gnutls.c:282
+msgid "The certificate has not yet been activated\n"
+msgstr ""
+
+#: src/gnutls.c:287
+msgid "The certificate has expired\n"
+msgstr ""
+
+#: src/gnutls.c:293
+#, c-format
+msgid "The certificate's owner does not match hostname '%s'\n"
+msgstr ""
+
+#: src/host.c:358
 #, fuzzy
 msgid "Unknown host"
 msgstr "Errore ezezaguna"
 
-#: src/host.c:352
+#: src/host.c:362
 msgid "Temporary failure in name resolution"
 msgstr ""
 
-#: src/host.c:354
+#: src/host.c:364
 msgid "Unknown error"
 msgstr "Errore ezezaguna"
 
-#: src/host.c:715
+#: src/host.c:737
 #, c-format
 msgid "Resolving %s... "
 msgstr "%s ebazten... "
 
-#: src/host.c:763
+#: src/host.c:789
 msgid "failed: No IPv4/IPv6 addresses for host.\n"
 msgstr ""
 
-#: src/host.c:786
+#: src/host.c:812
 msgid "failed: timed out.\n"
 msgstr "huts·egin·da: denboraz kanpo.\n"
 
-#: src/html-url.c:289
+#: src/html-url.c:286
 #, c-format
 msgid "%s: Cannot resolve incomplete link %s.\n"
 msgstr "%s: Ezin da osatu gabeko linka ebatzi %s.\n"
 
-#: src/html-url.c:696
+#: src/html-url.c:762
 #, fuzzy, c-format
 msgid "%s: Invalid URL %s: %s\n"
 msgstr "%s: %s: Baliogabeko balioa `%s'.\n"
 
-#: src/http.c:368
+#: src/http.c:377
 #, c-format
 msgid "Failed writing HTTP request: %s.\n"
 msgstr "Huts egin da HTTP eskaera idazterakoan: %s.\n"
 
-#: src/http.c:745
+#: src/http.c:754
 msgid "No headers, assuming HTTP/0.9"
 msgstr ""
 
-#: src/http.c:1430
+#: src/http.c:1456
 msgid "Disabling SSL due to encountered errors.\n"
 msgstr ""
 
-#: src/http.c:1548
+#: src/http.c:1576
 #, c-format
 msgid "POST data file %s missing: %s\n"
 msgstr ""
 
-#: src/http.c:1632
+#: src/http.c:1660
 #, fuzzy, c-format
 msgid "Reusing existing connection to %s:%d.\n"
 msgstr "Konexioa berrerabiltzen %srentzat: %hu.\n"
 
-#: src/http.c:1701
+#: src/http.c:1729
 #, fuzzy, c-format
 msgid "Failed reading proxy response: %s\n"
 msgstr "Huts egin da HTTP eskaera idazterakoan: %s.\n"
 
-#: src/http.c:1721
+#: src/http.c:1750
 #, c-format
 msgid "Proxy tunneling failed: %s"
 msgstr ""
 
-#: src/http.c:1766
+#: src/http.c:1795
 #, c-format
 msgid "%s request sent, awaiting response... "
 msgstr "%s eskaera bidalia, erantzunaren zain... "
 
-#: src/http.c:1777
+#: src/http.c:1806
 #, fuzzy
 msgid "No data received.\n"
 msgstr "Ez da daturik jaso"
 
-#: src/http.c:1784
+#: src/http.c:1813
 #, c-format
 msgid "Read error (%s) in headers.\n"
 msgstr "Irakurketa errorea (%s) goiburukoetan.\n"
 
-#: src/http.c:1831 src/http.c:2385
-#, fuzzy, c-format
-msgid ""
-"File %s already there; not retrieving.\n"
-"\n"
-msgstr "`%s' fitxategia dagoeneko badago, ez da jasoko.\n"
-
-#: src/http.c:1985
+#: src/http.c:1884
 msgid "Unknown authentication scheme.\n"
 msgstr "Autentifikazio eskema ezezaguna.\n"
 
-#: src/http.c:2016
+#: src/http.c:1918
 msgid "Authorization failed.\n"
 msgstr "Autorizazitzen huts egin da.\n"
 
-#: src/http.c:2030
+#: src/http.c:1956 src/http.c:2466
+#, fuzzy, c-format
+msgid ""
+"File %s already there; not retrieving.\n"
+"\n"
+msgstr "`%s' fitxategia dagoeneko badago, ez da jasoko.\n"
+
+#: src/http.c:2070
 msgid "Malformed status line"
 msgstr "Gaizki eratutako egoera lerroa"
 
-#: src/http.c:2032
+#: src/http.c:2072
 msgid "(no description)"
 msgstr "(deskripziorik gabe)"
 
-#: src/http.c:2098
+#: src/http.c:2149
 #, c-format
 msgid "Location: %s%s\n"
 msgstr "Kokapena: %s%s\n"
 
-#: src/http.c:2099 src/http.c:2209
+#: src/http.c:2150 src/http.c:2258
 msgid "unspecified"
 msgstr "zehaztugabea"
 
-#: src/http.c:2100
+#: src/http.c:2151
 msgid " [following]"
 msgstr " [hurrengoa]"
 
-#: src/http.c:2156
+#: src/http.c:2203
 msgid ""
 "\n"
 "    The file is already fully retrieved; nothing to do.\n"
