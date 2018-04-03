 "nebo\n"
 "nebyl zadán k procházení.\n"
 
-#: src/ftp.c:1695 src/ftp.c:1709
+#: src/ftp.c:1696 src/ftp.c:1710
 #, c-format
 msgid "Rejecting `%s'.\n"
 msgstr "Soubor „%s“ se nemá stahovat.\n"
 
-#: src/ftp.c:1757
+#: src/ftp.c:1733
+#, fuzzy, c-format
+msgid "Error matching %s against %s: %s\n"
+msgstr "Při zápisu do „%s“ nastala chyba: %s.\n"
+
+#: src/ftp.c:1774
 #, c-format
 msgid "No matches on pattern `%s'.\n"
 msgstr "Vzorku „%s“ nic neodpovídá.\n"
 
-#: src/ftp.c:1823
+#: src/ftp.c:1840
 #, c-format
 msgid "Wrote HTML-ized index to `%s' [%s].\n"
 msgstr "Výpis adresáře v HTML formátu byl zapsán do „%s“ [%s].\n"
 
-#: src/ftp.c:1828
+#: src/ftp.c:1845
 #, c-format
 msgid "Wrote HTML-ized index to `%s'.\n"
 msgstr "Výpis adresáře v HTML formátu byl zapsán do „%s“.\n"
 
-#: src/host.c:347
+#: src/host.c:348
 msgid "Unknown host"
 msgstr "Neznámé jméno počítače"
 
-#: src/host.c:351
+#: src/host.c:352
 msgid "Temporary failure in name resolution"
 msgstr "Dočasná chyba při překladu jména"
 
-#: src/host.c:353
+#: src/host.c:354
 msgid "Unknown error"
 msgstr "Neznámá chyba"
 
-#: src/host.c:714
+#: src/host.c:715
 #, c-format
 msgid "Resolving %s... "
-msgstr "Překlad %s… "
+msgstr "Překládám %s… "
 
-#: src/host.c:761
+#: src/host.c:762
 msgid "failed: No IPv4/IPv6 addresses for host.\n"
 msgstr "selhal: Pro dané jméno neexistuje žádná IPv4/IPv6 adresa.\n"
 
-#: src/host.c:784
+#: src/host.c:785
 msgid "failed: timed out.\n"
 msgstr "selhal: vypršel časový limit.\n"
 
-#: src/html-url.c:288
+#: src/html-url.c:289
 #, c-format
 msgid "%s: Cannot resolve incomplete link %s.\n"
 msgstr "%s: Neúplný odkaz %s nelze vyhodnotit.\n"
 
-#: src/html-url.c:695
+#: src/html-url.c:696
 #, c-format
 msgid "%s: Invalid URL %s: %s\n"
 msgstr "%s: Neplatné URL %s: %s\n"
 
-#: src/http.c:367
+#: src/http.c:368
 #, c-format
 msgid "Failed writing HTTP request: %s.\n"
 msgstr "Nebylo možné odeslat HTTP požadavek: %s.\n"
 
-#: src/http.c:736
+#: src/http.c:737
 msgid "No headers, assuming HTTP/0.9"
 msgstr "Chybí hlavičky, předpokládám HTTP/0.9"
 
-#: src/http.c:1413
+#: src/http.c:1417
 msgid "Disabling SSL due to encountered errors.\n"
 msgstr "Vypínám SSL kvůli chybám, které se vyskytly.\n"
 
-#: src/http.c:1566
+#: src/http.c:1570
 #, c-format
 msgid "POST data file `%s' missing: %s\n"
 msgstr "Soubor „%s“ s daty pro POST chybí: %s\n"
 
-#: src/http.c:1615
+#: src/http.c:1619
 #, c-format
 msgid "Reusing existing connection to %s:%d.\n"
 msgstr "Využívám existující spojení s %s:%d.\n"
 
-#: src/http.c:1683
+#: src/http.c:1687
 #, c-format
 msgid "Failed reading proxy response: %s\n"
 msgstr "Chyba při čtení odpovědi od proxy: %s\n"
 
-#: src/http.c:1703
+#: src/http.c:1707
 #, c-format
 msgid "Proxy tunneling failed: %s"
 msgstr "Tunelování zkrz proxy se nezdařilo: %s"
 
-#: src/http.c:1748
+#: src/http.c:1752
 #, c-format
 msgid "%s request sent, awaiting response... "
 msgstr "%s požadavek odeslán, program čeká na odpověď… "
 
-#: src/http.c:1759
+#: src/http.c:1763
 msgid "No data received.\n"
 msgstr "Nepřišla žádná data.\n"
 
-#: src/http.c:1766
+#: src/http.c:1770
 #, c-format
 msgid "Read error (%s) in headers.\n"
 msgstr "Chyba (%s) při čtení hlaviček.\n"
 
-#: src/http.c:1812
+#: src/http.c:1816 src/http.c:2368
 #, c-format
 msgid ""
 "File `%s' already there; not retrieving.\n"
