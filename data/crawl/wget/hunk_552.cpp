 "Már létezik a(z) %s -> %s helyes szimbolikus link\n"
 "\n"
 
-#: src/ftp.c:1533
+#: src/ftp.c:1788
 #, c-format
 msgid "Creating symlink %s -> %s\n"
 msgstr "Létrehozom a(z) %s -> %s szimbolikus linket\n"
 
-#: src/ftp.c:1543
+#: src/ftp.c:1798
 #, fuzzy, c-format
 msgid "Symlinks not supported, skipping symlink %s.\n"
 msgstr ""
 "A szimbolikus linkek nem támogatottak, a(z) „%s” szimbolikus linket "
 "kihagyom.\n"
 
-#: src/ftp.c:1555
+#: src/ftp.c:1810
 #, fuzzy, c-format
 msgid "Skipping directory %s.\n"
 msgstr "A(z) „%s” könyvtárat kihagyom.\n"
 
-#: src/ftp.c:1564
+#: src/ftp.c:1819
 #, c-format
 msgid "%s: unknown/unsupported file type.\n"
 msgstr "%s: ismeretlen/nem támogatott fájltípus.\n"
 
-#: src/ftp.c:1591
+#: src/ftp.c:1856
 #, c-format
 msgid "%s: corrupt time-stamp.\n"
 msgstr "%s: sérült időpecsét.\n"
 
-#: src/ftp.c:1619
+#: src/ftp.c:1878
 #, c-format
 msgid "Will not retrieve dirs since depth is %d (max %d).\n"
 msgstr "Könyvtárakat nem töltöm le, mivel a mélység %d (max %d).\n"
 
-#: src/ftp.c:1669
+#: src/ftp.c:1928
 #, fuzzy, c-format
 msgid "Not descending to %s as it is excluded/not-included.\n"
 msgstr "Nem lépek be a következőbe: „%s”, mert ki van zárva/nincs kijelölve.\n"
 
-#: src/ftp.c:1735 src/ftp.c:1749
+#: src/ftp.c:1994 src/ftp.c:2008
 #, fuzzy, c-format
 msgid "Rejecting %s.\n"
 msgstr "A következő visszautasítva: „%s”.\n"
 
-#: src/ftp.c:1772
+#: src/ftp.c:2031
 #, c-format
 msgid "Error matching %s against %s: %s\n"
 msgstr "Hiba %s és %s illesztésekor: %s\n"
 
-#: src/ftp.c:1814
+#: src/ftp.c:2073
 #, fuzzy, c-format
 msgid "No matches on pattern %s.\n"
 msgstr "Nincs találat a(z) „%s” mintához .\n"
 
-#: src/ftp.c:1880
+#: src/ftp.c:2144
 #, fuzzy, c-format
 msgid "Wrote HTML-ized index to %s [%s].\n"
 msgstr "A HTML-esített index kiírva a(z) „%s” [%s] fájlba.\n"
 
-#: src/ftp.c:1885
+#: src/ftp.c:2149
 #, fuzzy, c-format
 msgid "Wrote HTML-ized index to %s.\n"
 msgstr "A HTML-esített index kiírva a(z) „%s” fájlba.\n"
 
-#: src/host.c:348
+#: src/gnutls.c:219 src/openssl.c:495
+msgid "ERROR"
+msgstr "HIBA"
+
+#: src/gnutls.c:219 src/openssl.c:495
+msgid "WARNING"
+msgstr "FIGYELMEZTETÉS"
+
+#: src/gnutls.c:225 src/openssl.c:504
+#, c-format
+msgid "%s: No certificate presented by %s.\n"
+msgstr "%s: %s nem mutatott be tanúsítványt.\n"
+
+#: src/gnutls.c:233
+#, fuzzy, c-format
+msgid "%s: The certificate of %s is not trusted.\n"
+msgstr "%s: %s nem mutatott be tanúsítványt.\n"
+
+#: src/gnutls.c:239
+#, c-format
+msgid "%s: The certificate of %s hasn't got a known issuer.\n"
+msgstr ""
+
+#: src/gnutls.c:245
+#, fuzzy, c-format
+msgid "%s: The certificate of %s has been revoked.\n"
+msgstr "  A kibocsátott tanúsítvány lejárt.\n"
+
+#: src/gnutls.c:259
+#, c-format
+msgid "Error initializing X509 certificate: %s\n"
+msgstr ""
+
+#: src/gnutls.c:268
+#, fuzzy
+msgid "No certificate found\n"
+msgstr "%s: %s nem mutatott be tanúsítványt.\n"
+
+#: src/gnutls.c:275
+#, fuzzy, c-format
+msgid "Error parsing certificate: %s\n"
+msgstr "Hiba a proxy URL feldolgozása közben: %s: %s.\n"
+
+#: src/gnutls.c:282
+#, fuzzy
+msgid "The certificate has not yet been activated\n"
+msgstr "  A kibocsátott tanúsítvány még nem érvényes.\n"
+
+#: src/gnutls.c:287
+#, fuzzy
+msgid "The certificate has expired\n"
+msgstr "  A kibocsátott tanúsítvány lejárt.\n"
+
+#: src/gnutls.c:293
+#, fuzzy, c-format
+msgid "The certificate's owner does not match hostname '%s'\n"
+msgstr ""
+"%s: a tanúsítvány „%s” általános neve nem egyezik a kért „%s” gépnévvel.\n"
+
+#: src/host.c:358
 msgid "Unknown host"
 msgstr "Ismeretlen kiszolgáló"
 
-#: src/host.c:352
+#: src/host.c:362
 msgid "Temporary failure in name resolution"
 msgstr "Átmeneti névfeloldási hiba"
 
-#: src/host.c:354
+#: src/host.c:364
 msgid "Unknown error"
 msgstr "Ismeretlen hiba"
 
-#: src/host.c:715
+#: src/host.c:737
 #, c-format
 msgid "Resolving %s... "
 msgstr "%s feloldása... "
 
-#: src/host.c:763
+#: src/host.c:789
 msgid "failed: No IPv4/IPv6 addresses for host.\n"
 msgstr "meghiúsult: nem található IPv4/IPv6 cím a géphez.\n"
 
-#: src/host.c:786
+#: src/host.c:812
 msgid "failed: timed out.\n"
 msgstr "meghiúsult: időtúllépés.\n"
 
-#: src/html-url.c:289
+#: src/html-url.c:286
 #, c-format
 msgid "%s: Cannot resolve incomplete link %s.\n"
 msgstr "%s: nem oldható fel a hiányos %s hivatkozás.\n"
 
-#: src/html-url.c:696
+#: src/html-url.c:762
 #, c-format
 msgid "%s: Invalid URL %s: %s\n"
 msgstr "%s: Érvénytelen URL: %s: %s.\n"
 
-#: src/http.c:368
+#: src/http.c:377
 #, c-format
 msgid "Failed writing HTTP request: %s.\n"
 msgstr "A HTTP kérés írása meghiúsult: %s.\n"
 
-#: src/http.c:745
+#: src/http.c:754
 msgid "No headers, assuming HTTP/0.9"
 msgstr "Nincsenek fejlécek, HTTP/0.9 feltételezése"
 
-#: src/http.c:1430
+#: src/http.c:1456
 msgid "Disabling SSL due to encountered errors.\n"
 msgstr "A tapasztalt hibák miatt az SSL letiltásra kerül.\n"
 
-#: src/http.c:1548
+#: src/http.c:1576
 #, fuzzy, c-format
 msgid "POST data file %s missing: %s\n"
 msgstr "A(z) „%s” POST adatfájl hiányzik: %s\n"
 
-#: src/http.c:1632
+#: src/http.c:1660
 #, c-format
 msgid "Reusing existing connection to %s:%d.\n"
 msgstr "Újrahasználom a kapcsolatot a következőhöz: %s:%d.\n"
 
-#: src/http.c:1701
+#: src/http.c:1729
 #, c-format
 msgid "Failed reading proxy response: %s\n"
 msgstr "A proxy válasz olvasása meghiúsult: %s\n"
 
-#: src/http.c:1721
+#: src/http.c:1750
 #, c-format
 msgid "Proxy tunneling failed: %s"
 msgstr "A proxy alagutazás meghiúsult: %s"
 
-#: src/http.c:1766
+#: src/http.c:1795
 #, c-format
 msgid "%s request sent, awaiting response... "
 msgstr "%s kérés elküldve, várom a választ... "
 
-#: src/http.c:1777
+#: src/http.c:1806
 msgid "No data received.\n"
 msgstr "Nem érkezett adat.\n"
 
-#: src/http.c:1784
+#: src/http.c:1813
 #, c-format
 msgid "Read error (%s) in headers.\n"
 msgstr "Olvasási hiba (%s) a fejlécekben.\n"
 
-#: src/http.c:1831 src/http.c:2385
+#: src/http.c:1884
+msgid "Unknown authentication scheme.\n"
+msgstr "Ismeretlen hitelesítési séma.\n"
+
+#: src/http.c:1918
+msgid "Authorization failed.\n"
+msgstr "A hitelesítés meghiúsult.\n"
+
+#: src/http.c:1956 src/http.c:2466
 #, fuzzy, c-format
 msgid ""
 "File %s already there; not retrieving.\n"
