 "nebol určený na prechádzanie.\n"
 
 # , c-format
-#: src/ftp.c:1735 src/ftp.c:1749
+#: src/ftp.c:1994 src/ftp.c:2008
 #, fuzzy, c-format
 msgid "Rejecting %s.\n"
 msgstr "Odmietam `%s'.\n"
 
 # , c-format
-#: src/ftp.c:1772
+#: src/ftp.c:2031
 #, c-format
 msgid "Error matching %s against %s: %s\n"
 msgstr "Chyba pri hľadaní zhody %s s %s: %s\n"
 
 # , c-format
-#: src/ftp.c:1814
+#: src/ftp.c:2073
 #, fuzzy, c-format
 msgid "No matches on pattern %s.\n"
 msgstr "Vzoru `%s' nič nezodpovedá.\n"
 
 # , c-format
-#: src/ftp.c:1880
+#: src/ftp.c:2144
 #, fuzzy, c-format
 msgid "Wrote HTML-ized index to %s [%s].\n"
 msgstr "Výpis adresára v HTML formáte bol zapísaný do `%s' [%s].\n"
 
 # , c-format
-#: src/ftp.c:1885
+#: src/ftp.c:2149
 #, fuzzy, c-format
 msgid "Wrote HTML-ized index to %s.\n"
 msgstr "Výpis adresára v HTML formáte bol zapísaný do `%s'.\n"
 
-#: src/host.c:348
+#: src/gnutls.c:219 src/openssl.c:495
+msgid "ERROR"
+msgstr "CHYBA"
+
+#: src/gnutls.c:219 src/openssl.c:495
+msgid "WARNING"
+msgstr "UPOZORNENIE"
+
+#: src/gnutls.c:225 src/openssl.c:504
+#, c-format
+msgid "%s: No certificate presented by %s.\n"
+msgstr "%s: %s neprezentoval certifikát.\n"
+
+#: src/gnutls.c:233
+#, fuzzy, c-format
+msgid "%s: The certificate of %s is not trusted.\n"
+msgstr "%s: %s neprezentoval certifikát.\n"
+
+#: src/gnutls.c:239
+#, c-format
+msgid "%s: The certificate of %s hasn't got a known issuer.\n"
+msgstr ""
+
+#: src/gnutls.c:245
+#, fuzzy, c-format
+msgid "%s: The certificate of %s has been revoked.\n"
+msgstr "  Vydanému certifikátu vypršala platnosť.\n"
+
+#: src/gnutls.c:259
+#, c-format
+msgid "Error initializing X509 certificate: %s\n"
+msgstr ""
+
+#: src/gnutls.c:268
+#, fuzzy
+msgid "No certificate found\n"
+msgstr "%s: %s neprezentoval certifikát.\n"
+
+# , c-format
+#: src/gnutls.c:275
+#, fuzzy, c-format
+msgid "Error parsing certificate: %s\n"
+msgstr "Chyba pri analýze proxy URL %s: %s\n"
+
+#: src/gnutls.c:282
+#, fuzzy
+msgid "The certificate has not yet been activated\n"
+msgstr "  Vydaný certifikát je ešte neplatný.\n"
+
+#: src/gnutls.c:287
+#, fuzzy
+msgid "The certificate has expired\n"
+msgstr "  Vydanému certifikátu vypršala platnosť.\n"
+
+#: src/gnutls.c:293
+#, fuzzy, c-format
+msgid "The certificate's owner does not match hostname '%s'\n"
+msgstr ""
+"%s: bežné meno certifikátu `%s' sa nezhoduje s požadovaným menom hostiteľa `%"
+"s'.\n"
+
+#: src/host.c:358
 msgid "Unknown host"
 msgstr "Neznámy hostiteľ"
 
-#: src/host.c:352
+#: src/host.c:362
 msgid "Temporary failure in name resolution"
 msgstr "Dočasné zlyhanie pri prevode mena"
 
-#: src/host.c:354
+#: src/host.c:364
 msgid "Unknown error"
 msgstr "Neznáma chyba"
 
 # , c-format
-#: src/host.c:715
+#: src/host.c:737
 #, c-format
 msgid "Resolving %s... "
 msgstr "Prevádzam %s na IP adresu... "
 
-#: src/host.c:763
+#: src/host.c:789
 msgid "failed: No IPv4/IPv6 addresses for host.\n"
 msgstr "zlyhalo: Hostiteľ nemá IPv4/IPv6 adresy.\n"
 
-#: src/host.c:786
+#: src/host.c:812
 msgid "failed: timed out.\n"
 msgstr "zlyhalo: časový limit vypršal.\n"
 
-#: src/html-url.c:289
+#: src/html-url.c:286
 #, c-format
 msgid "%s: Cannot resolve incomplete link %s.\n"
 msgstr "%s: Nemôžem rozložiť neúplný odkaz %s.\n"
 
 # , c-format
-#: src/html-url.c:696
+#: src/html-url.c:762
 #, c-format
 msgid "%s: Invalid URL %s: %s\n"
 msgstr "%s: Neplatné URL %s: %s\n"
 
-#: src/http.c:368
+#: src/http.c:377
 #, c-format
 msgid "Failed writing HTTP request: %s.\n"
 msgstr "Požiadavku HTTP nebolo možné odoslať: %s.\n"
 
-#: src/http.c:745
+#: src/http.c:754
 msgid "No headers, assuming HTTP/0.9"
 msgstr "Bez hlavičiek, predpokladám HTTP/0.9"
 
-#: src/http.c:1430
+#: src/http.c:1456
 msgid "Disabling SSL due to encountered errors.\n"
 msgstr "Deaktivujem SSL z dôvodu výskytu chýb.\n"
 
-#: src/http.c:1548
+#: src/http.c:1576
 #, fuzzy, c-format
 msgid "POST data file %s missing: %s\n"
 msgstr "Chýba POST dátový súbor `%s': %s\n"
 
 # , c-format
-#: src/http.c:1632
+#: src/http.c:1660
 #, c-format
 msgid "Reusing existing connection to %s:%d.\n"
 msgstr "Používam existujúce spojenie s %s:%d.\n"
 
-#: src/http.c:1701
+#: src/http.c:1729
 #, c-format
 msgid "Failed reading proxy response: %s\n"
 msgstr "Zlyhalo čítanie odpovede z proxy: %s\n"
 
-#: src/http.c:1721
+#: src/http.c:1750
 #, c-format
 msgid "Proxy tunneling failed: %s"
 msgstr "Tunelovanie proxy zlyhalo: %s"
 
 # , c-format
-#: src/http.c:1766
+#: src/http.c:1795
 #, c-format
 msgid "%s request sent, awaiting response... "
 msgstr "%s požiadavka odoslaná, čakám na odpoveď... "
 
-#: src/http.c:1777
+#: src/http.c:1806
 msgid "No data received.\n"
 msgstr "Neboli prijaté žiadne dáta.\n"
 
 # , c-format
-#: src/http.c:1784
+#: src/http.c:1813
 #, c-format
 msgid "Read error (%s) in headers.\n"
 msgstr "Chyba (%s) pri čítaní hlavičiek.\n"
 
+#: src/http.c:1884
+msgid "Unknown authentication scheme.\n"
+msgstr "Neznámy spôsob autentifikácie.\n"
+
+#: src/http.c:1918
+msgid "Authorization failed.\n"
+msgstr "Autorizácia zlyhala.\n"
+
 # , c-format
-#: src/http.c:1831 src/http.c:2385
+#: src/http.c:1956 src/http.c:2466
 #, fuzzy, c-format
 msgid ""
 "File %s already there; not retrieving.\n"
 "\n"
 msgstr "Súbor `%s' je už tam, nebudem ho prenášať.\n"
 
-#: src/http.c:1985
-msgid "Unknown authentication scheme.\n"
-msgstr "Neznámy spôsob autentifikácie.\n"
-
-#: src/http.c:2016
-msgid "Authorization failed.\n"
-msgstr "Autorizácia zlyhala.\n"
-
-#: src/http.c:2030
+#: src/http.c:2070
 msgid "Malformed status line"
 msgstr "Odpoveď servera má skomolený stavový riadok"
 
-#: src/http.c:2032
+#: src/http.c:2072
 msgid "(no description)"
 msgstr "(bez popisu)"
 
 # , c-format
-#: src/http.c:2098
+#: src/http.c:2149
 #, c-format
 msgid "Location: %s%s\n"
 msgstr "Presmerované na: %s%s\n"
 
-#: src/http.c:2099 src/http.c:2209
+#: src/http.c:2150 src/http.c:2258
 msgid "unspecified"
 msgstr "neudané"
 
-#: src/http.c:2100
+#: src/http.c:2151
 msgid " [following]"
 msgstr " [nasledujem]"
 
-#: src/http.c:2156
+#: src/http.c:2203
 msgid ""
 "\n"
 "    The file is already fully retrieved; nothing to do.\n"
