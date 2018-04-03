 "Ju� istnieje poprawne dowi�zanie symboliczne %s -> %s\n"
 "\n"
 
-#: src/ftp.c:1533
+#: src/ftp.c:1788
 #, c-format
 msgid "Creating symlink %s -> %s\n"
 msgstr "Tworzenie dowi�zania symbolicznego %s -> %s\n"
 
-#: src/ftp.c:1543
+#: src/ftp.c:1798
 #, fuzzy, c-format
 msgid "Symlinks not supported, skipping symlink %s.\n"
 msgstr ""
 "Dowi�zania symboliczne nie s� obs�ugiwane, pomijanie dowi�zania `%s'.\n"
 
-#: src/ftp.c:1555
+#: src/ftp.c:1810
 #, fuzzy, c-format
 msgid "Skipping directory %s.\n"
 msgstr "Pomijanie katalogu `%s'.\n"
 
-#: src/ftp.c:1564
+#: src/ftp.c:1819
 #, c-format
 msgid "%s: unknown/unsupported file type.\n"
 msgstr "%s: nieznany/nieobs�ugiwany typ pliku.\n"
 
-#: src/ftp.c:1591
+#: src/ftp.c:1856
 #, c-format
 msgid "%s: corrupt time-stamp.\n"
 msgstr "%s: znacznik czasowy uszkodzony.\n"
 
-#: src/ftp.c:1619
+#: src/ftp.c:1878
 #, c-format
 msgid "Will not retrieve dirs since depth is %d (max %d).\n"
 msgstr "Nie b�d� pobierane katalogi, gdy� g��boko�� wynosi %d (maks. %d).\n"
 
-#: src/ftp.c:1669
+#: src/ftp.c:1928
 #, fuzzy, c-format
 msgid "Not descending to %s as it is excluded/not-included.\n"
 msgstr "Bez wchodzenia do `%s', poniewa� jest on wy��czony/nie-w��czony.\n"
 
-#: src/ftp.c:1735 src/ftp.c:1749
+#: src/ftp.c:1994 src/ftp.c:2008
 #, fuzzy, c-format
 msgid "Rejecting %s.\n"
 msgstr "Odrzucanie `%s'.\n"
 
-#: src/ftp.c:1772
+#: src/ftp.c:2031
 #, c-format
 msgid "Error matching %s against %s: %s\n"
 msgstr "B��d podczas dopasowywania %s wzgl�dem %s: %s\n"
 
-#: src/ftp.c:1814
+#: src/ftp.c:2073
 #, fuzzy, c-format
 msgid "No matches on pattern %s.\n"
 msgstr "Brak pasuj�cych do wzorca `%s'.\n"
 
-#: src/ftp.c:1880
+#: src/ftp.c:2144
 #, fuzzy, c-format
 msgid "Wrote HTML-ized index to %s [%s].\n"
 msgstr "Zapisano indeks w postaci HTML-a w `%s' [%s].\n"
 
-#: src/ftp.c:1885
+#: src/ftp.c:2149
 #, fuzzy, c-format
 msgid "Wrote HTML-ized index to %s.\n"
 msgstr "Zapisano indeks w postaci HTML-a w `%s'.\n"
 
-#: src/host.c:348
+#: src/gnutls.c:219 src/openssl.c:495
+msgid "ERROR"
+msgstr "B��D"
+
+#: src/gnutls.c:219 src/openssl.c:495
+msgid "WARNING"
+msgstr "UWAGA"
+
+#: src/gnutls.c:225 src/openssl.c:504
+#, c-format
+msgid "%s: No certificate presented by %s.\n"
+msgstr "%s: �aden certyfikat nie zosta� przedstawiony przez %s.\n"
+
+#: src/gnutls.c:233
+#, fuzzy, c-format
+msgid "%s: The certificate of %s is not trusted.\n"
+msgstr "%s: �aden certyfikat nie zosta� przedstawiony przez %s.\n"
+
+#: src/gnutls.c:239
+#, c-format
+msgid "%s: The certificate of %s hasn't got a known issuer.\n"
+msgstr ""
+
+#: src/gnutls.c:245
+#, fuzzy, c-format
+msgid "%s: The certificate of %s has been revoked.\n"
+msgstr " Wydany certyfikat wygas�.\n"
+
+#: src/gnutls.c:259
+#, c-format
+msgid "Error initializing X509 certificate: %s\n"
+msgstr ""
+
+#: src/gnutls.c:268
+#, fuzzy
+msgid "No certificate found\n"
+msgstr "%s: �aden certyfikat nie zosta� przedstawiony przez %s.\n"
+
+#: src/gnutls.c:275
+#, fuzzy, c-format
+msgid "Error parsing certificate: %s\n"
+msgstr "B��d podczas analizy sk�adni URL-a proxy %s: %s.\n"
+
+#: src/gnutls.c:282
+#, fuzzy
+msgid "The certificate has not yet been activated\n"
+msgstr " Wydany certyfikat nie jest jeszcze wa�ny.\n"
+
+#: src/gnutls.c:287
+#, fuzzy
+msgid "The certificate has expired\n"
+msgstr " Wydany certyfikat wygas�.\n"
+
+#: src/gnutls.c:293
+#, fuzzy, c-format
+msgid "The certificate's owner does not match hostname '%s'\n"
+msgstr ""
+"%s: nazwa w certyfikacie `%s' nie pasuje do ��danej nazwy hosta `%s'.\n"
+
+#: src/host.c:358
 msgid "Unknown host"
 msgstr "Nieznany host"
 
-#: src/host.c:352
+#: src/host.c:362
 msgid "Temporary failure in name resolution"
 msgstr "Tymczasowy b��d w rozwi�zywaniu nazwy"
 
-#: src/host.c:354
+#: src/host.c:364
 msgid "Unknown error"
 msgstr "Nieznany b��d"
 
-#: src/host.c:715
+#: src/host.c:737
 #, c-format
 msgid "Resolving %s... "
 msgstr "Translacja %s... "
 
-#: src/host.c:763
+#: src/host.c:789
 msgid "failed: No IPv4/IPv6 addresses for host.\n"
 msgstr "b��d: brak adresu IPv4/IPv6 dla hosta.\n"
 
-#: src/host.c:786
+#: src/host.c:812
 msgid "failed: timed out.\n"
 msgstr "b��d: przekroczono limit czasu oczekiwania.\n"
 
-#: src/html-url.c:289
+#: src/html-url.c:286
 #, c-format
 msgid "%s: Cannot resolve incomplete link %s.\n"
 msgstr "%s: Nie uda�o si� przeanalizowa� niedoko�czonego ��cza %s.\n"
 
 # c-format
-#: src/html-url.c:696
+#: src/html-url.c:762
 #, c-format
 msgid "%s: Invalid URL %s: %s\n"
 msgstr "%s: Nieprawid�owy URL %s: %s\n"
 
-#: src/http.c:368
+#: src/http.c:377
 #, c-format
 msgid "Failed writing HTTP request: %s.\n"
 msgstr "Nie powiod�o si� wysy�anie ��dania HTTP: %s.\n"
 
-#: src/http.c:745
+#: src/http.c:754
 msgid "No headers, assuming HTTP/0.9"
 msgstr "Brak nag��wk�w, przyj�to HTTP/0.9"
 
-#: src/http.c:1430
+#: src/http.c:1456
 msgid "Disabling SSL due to encountered errors.\n"
 msgstr "Wy��czenie SSL ze wzgl�du na napotkane b��dy\n"
 
-#: src/http.c:1548
+#: src/http.c:1576
 #, fuzzy, c-format
 msgid "POST data file %s missing: %s\n"
 msgstr "Brak pliku danych POST `%s': %s\n"
 
-#: src/http.c:1632
+#: src/http.c:1660
 #, c-format
 msgid "Reusing existing connection to %s:%d.\n"
 msgstr "Ponowne u�ycie po��czenia do %s:%d.\n"
 
-#: src/http.c:1701
+#: src/http.c:1729
 #, c-format
 msgid "Failed reading proxy response: %s\n"
 msgstr "Nie powiod�o si� odczytanie odpowiedzi proxy: %s.\n"
 
-#: src/http.c:1721
+#: src/http.c:1750
 #, c-format
 msgid "Proxy tunneling failed: %s"
 msgstr "Tunelowanie proxy nie powiod�o si�: %s"
 
-#: src/http.c:1766
+#: src/http.c:1795
 #, c-format
 msgid "%s request sent, awaiting response... "
 msgstr "��danie %s wys�ano, oczekiwanie na odpowied�... "
 
-#: src/http.c:1777
+#: src/http.c:1806
 msgid "No data received.\n"
 msgstr "Brak danych w odpowiedzi.\n"
 
-#: src/http.c:1784
+#: src/http.c:1813
 #, c-format
 msgid "Read error (%s) in headers.\n"
 msgstr "B��d odczytu (%s) w nag��wkach.\n"
 
-#: src/http.c:1831 src/http.c:2385
+#: src/http.c:1884
+msgid "Unknown authentication scheme.\n"
+msgstr "Nieznana metoda uwierzytelniania.\n"
+
+#: src/http.c:1918
+msgid "Authorization failed.\n"
+msgstr "Autoryzacja nie powiod�a si�.\n"
+
+#: src/http.c:1956 src/http.c:2466
 #, fuzzy, c-format
 msgid ""
 "File %s already there; not retrieving.\n"
