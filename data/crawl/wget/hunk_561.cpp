 "Har allerede gyldig symbolsk link %s -> %s\n"
 "\n"
 
-#: src/ftp.c:1533
+#: src/ftp.c:1788
 #, c-format
 msgid "Creating symlink %s -> %s\n"
 msgstr "Lager symbolsk link %s -> %s\n"
 
-#: src/ftp.c:1543
+#: src/ftp.c:1798
 #, fuzzy, c-format
 msgid "Symlinks not supported, skipping symlink %s.\n"
 msgstr "Symbolske linker ikke st�ttet, ignorerer �%s�.\n"
 
-#: src/ftp.c:1555
+#: src/ftp.c:1810
 #, fuzzy, c-format
 msgid "Skipping directory %s.\n"
 msgstr "Ignorerer katalog �%s�.\n"
 
-#: src/ftp.c:1564
+#: src/ftp.c:1819
 #, c-format
 msgid "%s: unknown/unsupported file type.\n"
 msgstr "%s: filtypen er ukjent/ikke st�ttet.\n"
 
-#: src/ftp.c:1591
+#: src/ftp.c:1856
 #, c-format
 msgid "%s: corrupt time-stamp.\n"
 msgstr "%s: ugyldig tidsstempel.\n"
 
-#: src/ftp.c:1619
+#: src/ftp.c:1878
 #, c-format
 msgid "Will not retrieve dirs since depth is %d (max %d).\n"
 msgstr "Henter ikke kataloger p� dybde %d (max %d).\n"
 
-#: src/ftp.c:1669
+#: src/ftp.c:1928
 #, fuzzy, c-format
 msgid "Not descending to %s as it is excluded/not-included.\n"
 msgstr "Behandler ikke �%s� da det er ekskludert/ikke inkludert.\n"
 
-#: src/ftp.c:1735 src/ftp.c:1749
+#: src/ftp.c:1994 src/ftp.c:2008
 #, fuzzy, c-format
 msgid "Rejecting %s.\n"
 msgstr "Ignorerer �%s�.\n"
 
-#: src/ftp.c:1772
+#: src/ftp.c:2031
 #, c-format
 msgid "Error matching %s against %s: %s\n"
 msgstr ""
 
-#: src/ftp.c:1814
+#: src/ftp.c:2073
 #, fuzzy, c-format
 msgid "No matches on pattern %s.\n"
 msgstr "Ingenting passer med m�nsteret �%s�.\n"
 
-#: src/ftp.c:1880
+#: src/ftp.c:2144
 #, fuzzy, c-format
 msgid "Wrote HTML-ized index to %s [%s].\n"
 msgstr "Skrev HTML-formattert indeks til �%s� [%ld].\n"
 
-#: src/ftp.c:1885
+#: src/ftp.c:2149
 #, fuzzy, c-format
 msgid "Wrote HTML-ized index to %s.\n"
 msgstr "Skrev HTML-formattert indeks til �%s�.\n"
 
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
+#, c-format
+msgid "Error parsing certificate: %s\n"
+msgstr ""
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
 msgstr "Ukjent feil"
 
-#: src/host.c:352
+#: src/host.c:362
 msgid "Temporary failure in name resolution"
 msgstr ""
 
-#: src/host.c:354
+#: src/host.c:364
 msgid "Unknown error"
 msgstr "Ukjent feil"
 
-#: src/host.c:715
+#: src/host.c:737
 #, fuzzy, c-format
 msgid "Resolving %s... "
 msgstr "Fjerner %s.\n"
 
-#: src/host.c:763
+#: src/host.c:789
 msgid "failed: No IPv4/IPv6 addresses for host.\n"
 msgstr ""
 
-#: src/host.c:786
+#: src/host.c:812
 msgid "failed: timed out.\n"
 msgstr ""
 
-#: src/html-url.c:289
+#: src/html-url.c:286
 #, c-format
 msgid "%s: Cannot resolve incomplete link %s.\n"
 msgstr ""
 
-#: src/html-url.c:696
+#: src/html-url.c:762
 #, fuzzy, c-format
 msgid "%s: Invalid URL %s: %s\n"
 msgstr "%s: Ugyldig spesifikasjon �%s�\n"
 
-#: src/http.c:368
+#: src/http.c:377
 #, fuzzy, c-format
 msgid "Failed writing HTTP request: %s.\n"
 msgstr "Feil ved sending av HTTP-foresp�rsel.\n"
 
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
 msgstr "Vil pr�ve � kontakte %s:%hu.\n"
 
-#: src/http.c:1701
+#: src/http.c:1729
 #, c-format
 msgid "Failed reading proxy response: %s\n"
 msgstr ""
 
-#: src/http.c:1721
+#: src/http.c:1750
 #, c-format
 msgid "Proxy tunneling failed: %s"
 msgstr ""
 
-#: src/http.c:1766
+#: src/http.c:1795
 #, c-format
 msgid "%s request sent, awaiting response... "
 msgstr "%s foresp�rsel sendt, mottar topptekster... "
 
-#: src/http.c:1777
+#: src/http.c:1806
 #, fuzzy
 msgid "No data received.\n"
 msgstr "Ingen data mottatt"
 
-#: src/http.c:1784
+#: src/http.c:1813
 #, c-format
 msgid "Read error (%s) in headers.\n"
 msgstr "Lesefeil (%s) i topptekster.\n"
 
-#: src/http.c:1831 src/http.c:2385
-#, fuzzy, c-format
-msgid ""
-"File %s already there; not retrieving.\n"
-"\n"
-msgstr "File �%s� eksisterer allerede, ignoreres.\n"
-
-#: src/http.c:1985
+#: src/http.c:1884
 msgid "Unknown authentication scheme.\n"
 msgstr "Ukjent autorisasjons-protokoll.\n"
 
-#: src/http.c:2016
+#: src/http.c:1918
 msgid "Authorization failed.\n"
 msgstr "Autorisasjon mislyktes\n"
 
-#: src/http.c:2030
+#: src/http.c:1956 src/http.c:2466
+#, fuzzy, c-format
+msgid ""
+"File %s already there; not retrieving.\n"
+"\n"
+msgstr "File �%s� eksisterer allerede, ignoreres.\n"
+
+#: src/http.c:2070
 msgid "Malformed status line"
 msgstr "Feil i statuslinje"
 
-#: src/http.c:2032
+#: src/http.c:2072
 msgid "(no description)"
 msgstr "(ingen beskrivelse)"
 
-#: src/http.c:2098
+#: src/http.c:2149
 #, c-format
 msgid "Location: %s%s\n"
 msgstr "Sted: %s%s\n"
 
-#: src/http.c:2099 src/http.c:2209
+#: src/http.c:2150 src/http.c:2258
 msgid "unspecified"
 msgstr "uspesifisert"
 
-#: src/http.c:2100
+#: src/http.c:2151
 msgid " [following]"
 msgstr " [omdirigert]"
 
-#: src/http.c:2156
+#: src/http.c:2203
 msgid ""
 "\n"
 "    The file is already fully retrieved; nothing to do.\n"
 "\n"
 msgstr ""
 
-#: src/http.c:2189
+#: src/http.c:2238
 msgid "Length: "
 msgstr "Lengde: "
 
-#: src/http.c:2209
+#: src/http.c:2258
 msgid "ignored"
 msgstr "ignoreres"
 
-#: src/http.c:2280
+#: src/http.c:2360
 #, c-format
 msgid "Saving to: %s\n"
 msgstr ""
 
-#: src/http.c:2361
+#: src/http.c:2442
 msgid "Warning: wildcards not supported in HTTP.\n"
 msgstr "Advarsel: jokertegn ikke st�ttet i HTTP.\n"
 
-#: src/http.c:2430
+#: src/http.c:2513
 msgid "Spider mode enabled. Check if remote file exists.\n"
 msgstr ""
 
-#: src/http.c:2515
+#: src/http.c:2598
 #, fuzzy, c-format
 msgid "Cannot write to %s (%s).\n"
 msgstr "Kan ikke skrive til �%s� (%s).\n"
 
-#: src/http.c:2524
+#: src/http.c:2607
 msgid "Unable to establish SSL connection.\n"
 msgstr ""
 
-#: src/http.c:2532
+#: src/http.c:2615
 #, c-format
 msgid "ERROR: Redirection (%d) without location.\n"
 msgstr "FEIL: Omdirigering (%d) uten nytt sted.\n"
 
-#: src/http.c:2578
+#: src/http.c:2663
 msgid "Remote file does not exist -- broken link!!!\n"
 msgstr ""
 
-#: src/http.c:2583
+#: src/http.c:2668
 #, c-format
 msgid "%s ERROR %d: %s.\n"
 msgstr "%s FEIL %d: %s.\n"
 
-#: src/http.c:2600
+#: src/http.c:2685
 msgid "Last-modified header missing -- time-stamps turned off.\n"
 msgstr "Last-modified topptekst mangler -- tidsstempling sl�s av.\n"
 
-#: src/http.c:2608
+#: src/http.c:2693
 msgid "Last-modified header invalid -- time-stamp ignored.\n"
 msgstr "Last-modified topptekst ugyldig -- tidsstempel ignoreres.\n"
 
-#: src/http.c:2638
+#: src/http.c:2723
 #, c-format
 msgid ""
 "Server file no newer than local file %s -- not retrieving.\n"
 "\n"
 msgstr ""
 
-#: src/http.c:2646
+#: src/http.c:2731
 #, fuzzy, c-format
 msgid "The sizes do not match (local %s) -- retrieving.\n"
 msgstr "Filst�rrelsene er forskjellige (local %ld), hentes.\n"
 
-#: src/http.c:2653
+#: src/http.c:2738
 msgid "Remote file is newer, retrieving.\n"
 msgstr "Fil p� tjener er nyere - hentes.\n"
 
-#: src/http.c:2669
+#: src/http.c:2755
 msgid ""
 "Remote file exists and could contain links to other resources -- "
 "retrieving.\n"
 "\n"
 msgstr ""
 
-#: src/http.c:2674
+#: src/http.c:2761
 msgid ""
 "Remote file exists but does not contain any link -- not retrieving.\n"
 "\n"
 msgstr ""
 
-#: src/http.c:2684
+#: src/http.c:2770
 msgid ""
 "Remote file exists and could contain further links,\n"
 "but recursion is disabled -- not retrieving.\n"
 "\n"
 msgstr ""
 
-#: src/http.c:2690
+#: src/http.c:2776
 #, fuzzy
 msgid ""
 "Remote file exists.\n"
 "\n"
 msgstr "Fil p� tjener er nyere - hentes.\n"
 
-#: src/http.c:2743
+#: src/http.c:2785
+#, fuzzy, c-format
+msgid "%s URL:%s %2d %s\n"
+msgstr "%s FEIL %d: %s.\n"
+
+#: src/http.c:2832
+#, c-format
+msgid ""
+"%s (%s) - written to stdout %s[%s/%s]\n"
+"\n"
+msgstr ""
+
+#: src/http.c:2833
 #, fuzzy, c-format
 msgid ""
 "%s (%s) - %s saved [%s/%s]\n"
