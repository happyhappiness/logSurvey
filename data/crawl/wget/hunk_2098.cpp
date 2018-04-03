 "Har allerede gyldig symbolsk link %s -> %s\n"
 "\n"
 
-#: src/ftp.c:1493
+#: src/ftp.c:1494
 #, c-format
 msgid "Creating symlink %s -> %s\n"
 msgstr "Lager symbolsk link %s -> %s\n"
 
-#: src/ftp.c:1503
+#: src/ftp.c:1504
 #, c-format
 msgid "Symlinks not supported, skipping symlink `%s'.\n"
 msgstr "Symbolske linker ikke støttet, ignorerer «%s».\n"
 
-#: src/ftp.c:1515
+#: src/ftp.c:1516
 #, c-format
 msgid "Skipping directory `%s'.\n"
 msgstr "Ignorerer katalog «%s».\n"
 
-#: src/ftp.c:1524
+#: src/ftp.c:1525
 #, c-format
 msgid "%s: unknown/unsupported file type.\n"
 msgstr "%s: filtypen er ukjent/ikke støttet.\n"
 
-#: src/ftp.c:1551
+#: src/ftp.c:1552
 #, c-format
 msgid "%s: corrupt time-stamp.\n"
 msgstr "%s: ugyldig tidsstempel.\n"
 
-#: src/ftp.c:1579
+#: src/ftp.c:1580
 #, c-format
 msgid "Will not retrieve dirs since depth is %d (max %d).\n"
 msgstr "Henter ikke kataloger på dybde %d (max %d).\n"
 
-#: src/ftp.c:1629
+#: src/ftp.c:1630
 #, c-format
 msgid "Not descending to `%s' as it is excluded/not-included.\n"
 msgstr "Behandler ikke «%s» da det er ekskludert/ikke inkludert.\n"
 
-#: src/ftp.c:1695 src/ftp.c:1709
+#: src/ftp.c:1696 src/ftp.c:1710
 #, c-format
 msgid "Rejecting `%s'.\n"
 msgstr "Ignorerer «%s».\n"
 
-#: src/ftp.c:1757
+#: src/ftp.c:1733
+#, c-format
+msgid "Error matching %s against %s: %s\n"
+msgstr ""
+
+#: src/ftp.c:1774
 #, c-format
 msgid "No matches on pattern `%s'.\n"
 msgstr "Ingenting passer med mønsteret «%s».\n"
 
-#: src/ftp.c:1823
+#: src/ftp.c:1840
 #, fuzzy, c-format
 msgid "Wrote HTML-ized index to `%s' [%s].\n"
 msgstr "Skrev HTML-formattert indeks til «%s» [%ld].\n"
 
-#: src/ftp.c:1828
+#: src/ftp.c:1845
 #, c-format
 msgid "Wrote HTML-ized index to `%s'.\n"
 msgstr "Skrev HTML-formattert indeks til «%s».\n"
 
-#: src/host.c:347
+#: src/host.c:348
 #, fuzzy
 msgid "Unknown host"
 msgstr "Ukjent feil"
 
-#: src/host.c:351
+#: src/host.c:352
 msgid "Temporary failure in name resolution"
 msgstr ""
 
-#: src/host.c:353
+#: src/host.c:354
 msgid "Unknown error"
 msgstr "Ukjent feil"
 
-#: src/host.c:714
+#: src/host.c:715
 #, fuzzy, c-format
 msgid "Resolving %s... "
 msgstr "Fjerner %s.\n"
 
-#: src/host.c:761
+#: src/host.c:762
 msgid "failed: No IPv4/IPv6 addresses for host.\n"
 msgstr ""
 
-#: src/host.c:784
+#: src/host.c:785
 msgid "failed: timed out.\n"
 msgstr ""
 
-#: src/html-url.c:288
+#: src/html-url.c:289
 #, c-format
 msgid "%s: Cannot resolve incomplete link %s.\n"
 msgstr ""
 
-#: src/html-url.c:695
+#: src/html-url.c:696
 #, fuzzy, c-format
 msgid "%s: Invalid URL %s: %s\n"
 msgstr "%s: Ugyldig spesifikasjon «%s»\n"
 
-#: src/http.c:367
+#: src/http.c:368
 #, fuzzy, c-format
 msgid "Failed writing HTTP request: %s.\n"
 msgstr "Feil ved sending av HTTP-forespørsel.\n"
 
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
 msgstr "Vil prøve å kontakte %s:%hu.\n"
 
-#: src/http.c:1683
+#: src/http.c:1687
 #, c-format
 msgid "Failed reading proxy response: %s\n"
 msgstr ""
 
-#: src/http.c:1703
+#: src/http.c:1707
 #, c-format
 msgid "Proxy tunneling failed: %s"
 msgstr ""
 
-#: src/http.c:1748
+#: src/http.c:1752
 #, c-format
 msgid "%s request sent, awaiting response... "
 msgstr "%s forespørsel sendt, mottar topptekster... "
 
-#: src/http.c:1759
+#: src/http.c:1763
 #, fuzzy
 msgid "No data received.\n"
 msgstr "Ingen data mottatt"
 
-#: src/http.c:1766
+#: src/http.c:1770
 #, c-format
 msgid "Read error (%s) in headers.\n"
 msgstr "Lesefeil (%s) i topptekster.\n"
 
-#: src/http.c:1812
+#: src/http.c:1816 src/http.c:2368
 #, fuzzy, c-format
 msgid ""
 "File `%s' already there; not retrieving.\n"
 "\n"
 msgstr "File «%s» eksisterer allerede, ignoreres.\n"
 
-#: src/http.c:1965
+#: src/http.c:1969
 msgid "Unknown authentication scheme.\n"
 msgstr "Ukjent autorisasjons-protokoll.\n"
 
-#: src/http.c:1996
+#: src/http.c:2000
 msgid "Authorization failed.\n"
 msgstr "Autorisasjon mislyktes\n"
 
-#: src/http.c:2010
+#: src/http.c:2014
 msgid "Malformed status line"
 msgstr "Feil i statuslinje"
 
-#: src/http.c:2012
+#: src/http.c:2016
 msgid "(no description)"
 msgstr "(ingen beskrivelse)"
 
-#: src/http.c:2075
+#: src/http.c:2082
 #, c-format
 msgid "Location: %s%s\n"
 msgstr "Sted: %s%s\n"
 
-#: src/http.c:2076 src/http.c:2183
+#: src/http.c:2083 src/http.c:2193
 msgid "unspecified"
 msgstr "uspesifisert"
 
-#: src/http.c:2077
+#: src/http.c:2084
 msgid " [following]"
 msgstr " [omdirigert]"
 
-#: src/http.c:2133
+#: src/http.c:2140
 msgid ""
 "\n"
 "    The file is already fully retrieved; nothing to do.\n"
 "\n"
 msgstr ""
 
-#: src/http.c:2163
+#: src/http.c:2173
 msgid "Length: "
 msgstr "Lengde: "
 
-#: src/http.c:2183
+#: src/http.c:2193
 msgid "ignored"
 msgstr "ignoreres"
 
-#: src/http.c:2254
+#: src/http.c:2264
 #, fuzzy, c-format
 msgid "Saving to: `%s'\n"
 msgstr "Ignorerer katalog «%s».\n"
 
-#: src/http.c:2335
+#: src/http.c:2345
 msgid "Warning: wildcards not supported in HTTP.\n"
 msgstr "Advarsel: jokertegn ikke støttet i HTTP.\n"
 
-#: src/http.c:2382
+#: src/http.c:2412
 msgid "Spider mode enabled. Check if remote file exists.\n"
 msgstr ""
 
-#: src/http.c:2467
+#: src/http.c:2497
 #, c-format
 msgid "Cannot write to `%s' (%s).\n"
 msgstr "Kan ikke skrive til «%s» (%s).\n"
 
-#: src/http.c:2476
+#: src/http.c:2506
 msgid "Unable to establish SSL connection.\n"
 msgstr ""
 
-#: src/http.c:2484
+#: src/http.c:2514
 #, c-format
 msgid "ERROR: Redirection (%d) without location.\n"
 msgstr "FEIL: Omdirigering (%d) uten nytt sted.\n"
 
-#: src/http.c:2530
+#: src/http.c:2560
 msgid "Remote file does not exist -- broken link!!!\n"
 msgstr ""
 
-#: src/http.c:2535
+#: src/http.c:2565
 #, c-format
 msgid "%s ERROR %d: %s.\n"
 msgstr "%s FEIL %d: %s.\n"
 
-#: src/http.c:2551
+#: src/http.c:2581
 msgid "Last-modified header missing -- time-stamps turned off.\n"
 msgstr "Last-modified topptekst mangler -- tidsstempling slås av.\n"
 
-#: src/http.c:2559
+#: src/http.c:2589
 msgid "Last-modified header invalid -- time-stamp ignored.\n"
 msgstr "Last-modified topptekst ugyldig -- tidsstempel ignoreres.\n"
 
-#: src/http.c:2589
+#: src/http.c:2619
 #, c-format
 msgid ""
 "Server file no newer than local file `%s' -- not retrieving.\n"
 "\n"
 msgstr ""
 
-#: src/http.c:2597
+#: src/http.c:2627
 #, fuzzy, c-format
 msgid "The sizes do not match (local %s) -- retrieving.\n"
 msgstr "Filstørrelsene er forskjellige (local %ld), hentes.\n"
 
-#: src/http.c:2604
+#: src/http.c:2634
 msgid "Remote file is newer, retrieving.\n"
 msgstr "Fil på tjener er nyere - hentes.\n"
 
-#: src/http.c:2620
+#: src/http.c:2650
 msgid ""
 "Remote file exists and could contain links to other resources -- "
 "retrieving.\n"
 "\n"
 msgstr ""
 
-#: src/http.c:2625
+#: src/http.c:2655
 msgid ""
 "Remote file exists but does not contain any link -- not retrieving.\n"
 "\n"
 msgstr ""
 
-#: src/http.c:2633
+#: src/http.c:2663
 #, fuzzy
 msgid ""
 "Remote file exists but recursion is disabled -- not retrieving.\n"
 "\n"
 msgstr "Fil på tjener er nyere - hentes.\n"
 
-#: src/http.c:2685
+#: src/http.c:2715
 #, fuzzy, c-format
 msgid ""
 "%s (%s) - `%s' saved [%s/%s]\n"
