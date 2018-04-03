 msgid "Failed writing HTTP request: %s.\n"
 msgstr "Feil ved sending av HTTP-forespørsel.\n"
 
-#: src/http.c:737
+#: src/http.c:745
 msgid "No headers, assuming HTTP/0.9"
 msgstr ""
 
-#: src/http.c:1417
+#: src/http.c:1430
 msgid "Disabling SSL due to encountered errors.\n"
 msgstr ""
 
-#: src/http.c:1570
+#: src/http.c:1548
 #, c-format
-msgid "POST data file `%s' missing: %s\n"
+msgid "POST data file %s missing: %s\n"
 msgstr ""
 
-#: src/http.c:1619
+#: src/http.c:1632
 #, fuzzy, c-format
 msgid "Reusing existing connection to %s:%d.\n"
 msgstr "Vil prøve å kontakte %s:%hu.\n"
 
-#: src/http.c:1687
+#: src/http.c:1701
 #, c-format
 msgid "Failed reading proxy response: %s\n"
 msgstr ""
 
-#: src/http.c:1707
+#: src/http.c:1721
 #, c-format
 msgid "Proxy tunneling failed: %s"
 msgstr ""
 
-#: src/http.c:1752
+#: src/http.c:1766
 #, c-format
 msgid "%s request sent, awaiting response... "
 msgstr "%s forespørsel sendt, mottar topptekster... "
 
-#: src/http.c:1763
+#: src/http.c:1777
 #, fuzzy
 msgid "No data received.\n"
 msgstr "Ingen data mottatt"
 
-#: src/http.c:1770
+#: src/http.c:1784
 #, c-format
 msgid "Read error (%s) in headers.\n"
 msgstr "Lesefeil (%s) i topptekster.\n"
 
-#: src/http.c:1816 src/http.c:2368
+#: src/http.c:1831 src/http.c:2385
 #, fuzzy, c-format
 msgid ""
-"File `%s' already there; not retrieving.\n"
+"File %s already there; not retrieving.\n"
 "\n"
 msgstr "File «%s» eksisterer allerede, ignoreres.\n"
 
-#: src/http.c:1969
+#: src/http.c:1985
 msgid "Unknown authentication scheme.\n"
 msgstr "Ukjent autorisasjons-protokoll.\n"
 
-#: src/http.c:2000
+#: src/http.c:2016
 msgid "Authorization failed.\n"
 msgstr "Autorisasjon mislyktes\n"
 
-#: src/http.c:2014
+#: src/http.c:2030
 msgid "Malformed status line"
 msgstr "Feil i statuslinje"
 
-#: src/http.c:2016
+#: src/http.c:2032
 msgid "(no description)"
 msgstr "(ingen beskrivelse)"
 
-#: src/http.c:2082
+#: src/http.c:2098
 #, c-format
 msgid "Location: %s%s\n"
 msgstr "Sted: %s%s\n"
 
-#: src/http.c:2083 src/http.c:2193
+#: src/http.c:2099 src/http.c:2209
 msgid "unspecified"
 msgstr "uspesifisert"
 
-#: src/http.c:2084
+#: src/http.c:2100
 msgid " [following]"
 msgstr " [omdirigert]"
 
-#: src/http.c:2140
+#: src/http.c:2156
 msgid ""
 "\n"
 "    The file is already fully retrieved; nothing to do.\n"
 "\n"
 msgstr ""
 
-#: src/http.c:2173
+#: src/http.c:2189
 msgid "Length: "
 msgstr "Lengde: "
 
-#: src/http.c:2193
+#: src/http.c:2209
 msgid "ignored"
 msgstr "ignoreres"
 
-#: src/http.c:2264
-#, fuzzy, c-format
-msgid "Saving to: `%s'\n"
-msgstr "Ignorerer katalog «%s».\n"
+#: src/http.c:2280
+#, c-format
+msgid "Saving to: %s\n"
+msgstr ""
 
-#: src/http.c:2345
+#: src/http.c:2361
 msgid "Warning: wildcards not supported in HTTP.\n"
 msgstr "Advarsel: jokertegn ikke støttet i HTTP.\n"
 
-#: src/http.c:2412
+#: src/http.c:2430
 msgid "Spider mode enabled. Check if remote file exists.\n"
 msgstr ""
 
-#: src/http.c:2497
-#, c-format
-msgid "Cannot write to `%s' (%s).\n"
+#: src/http.c:2515
+#, fuzzy, c-format
+msgid "Cannot write to %s (%s).\n"
 msgstr "Kan ikke skrive til «%s» (%s).\n"
 
-#: src/http.c:2506
+#: src/http.c:2524
 msgid "Unable to establish SSL connection.\n"
 msgstr ""
 
-#: src/http.c:2514
+#: src/http.c:2532
 #, c-format
 msgid "ERROR: Redirection (%d) without location.\n"
 msgstr "FEIL: Omdirigering (%d) uten nytt sted.\n"
 
-#: src/http.c:2560
+#: src/http.c:2578
 msgid "Remote file does not exist -- broken link!!!\n"
 msgstr ""
 
-#: src/http.c:2565
+#: src/http.c:2583
 #, c-format
 msgid "%s ERROR %d: %s.\n"
 msgstr "%s FEIL %d: %s.\n"
 
-#: src/http.c:2581
+#: src/http.c:2600
 msgid "Last-modified header missing -- time-stamps turned off.\n"
 msgstr "Last-modified topptekst mangler -- tidsstempling slås av.\n"
 
-#: src/http.c:2589
+#: src/http.c:2608
 msgid "Last-modified header invalid -- time-stamp ignored.\n"
 msgstr "Last-modified topptekst ugyldig -- tidsstempel ignoreres.\n"
 
-#: src/http.c:2619
+#: src/http.c:2638
 #, c-format
 msgid ""
-"Server file no newer than local file `%s' -- not retrieving.\n"
+"Server file no newer than local file %s -- not retrieving.\n"
 "\n"
 msgstr ""
 
-#: src/http.c:2627
+#: src/http.c:2646
 #, fuzzy, c-format
 msgid "The sizes do not match (local %s) -- retrieving.\n"
 msgstr "Filstørrelsene er forskjellige (local %ld), hentes.\n"
 
-#: src/http.c:2634
+#: src/http.c:2653
 msgid "Remote file is newer, retrieving.\n"
 msgstr "Fil på tjener er nyere - hentes.\n"
 
-#: src/http.c:2650
+#: src/http.c:2669
 msgid ""
 "Remote file exists and could contain links to other resources -- "
 "retrieving.\n"
 "\n"
 msgstr ""
 
-#: src/http.c:2655
+#: src/http.c:2674
 msgid ""
 "Remote file exists but does not contain any link -- not retrieving.\n"
 "\n"
 msgstr ""
 
-#: src/http.c:2663
+#: src/http.c:2684
+msgid ""
+"Remote file exists and could contain further links,\n"
+"but recursion is disabled -- not retrieving.\n"
+"\n"
+msgstr ""
+
+#: src/http.c:2690
 #, fuzzy
 msgid ""
-"Remote file exists but recursion is disabled -- not retrieving.\n"
+"Remote file exists.\n"
 "\n"
 msgstr "Fil på tjener er nyere - hentes.\n"
 
-#: src/http.c:2715
+#: src/http.c:2743
 #, fuzzy, c-format
 msgid ""
-"%s (%s) - `%s' saved [%s/%s]\n"
+"%s (%s) - %s saved [%s/%s]\n"
 "\n"
 msgstr ""
 "%s (%s) - «%s» lagret [%ld/%ld]\n"
 "\n"
 
-#: src/http.c:2770
+#: src/http.c:2798
 #, fuzzy, c-format
 msgid "%s (%s) - Connection closed at byte %s. "
 msgstr "%s (%s) - Forbindelse brutt ved byte %ld. "
 
-#: src/http.c:2785
+#: src/http.c:2813
 #, fuzzy, c-format
 msgid "%s (%s) - Read error at byte %s (%s)."
 msgstr "%s (%s) - Lesefeil ved byte %ld (%s)."
 
-#: src/http.c:2794
+#: src/http.c:2822
 #, fuzzy, c-format
 msgid "%s (%s) - Read error at byte %s/%s (%s). "
 msgstr "%s (%s) - Lesefeil ved byte %ld/%ld (%s)."
 
-#: src/init.c:387
+#: src/init.c:391
 #, c-format
 msgid "%s: WGETRC points to %s, which doesn't exist.\n"
 msgstr ""
 
-#: src/init.c:450 src/netrc.c:265
+#: src/init.c:454 src/netrc.c:265
 #, c-format
 msgid "%s: Cannot read %s (%s).\n"
 msgstr "%s: Kan ikke lese %s (%s).\n"
 
-#: src/init.c:468
+#: src/init.c:472
 #, c-format
 msgid "%s: Error in %s at line %d.\n"
 msgstr "%s: Feil i %s på linje %d.\n"
 
-#: src/init.c:474
+#: src/init.c:478
 #, fuzzy, c-format
 msgid "%s: Syntax error in %s at line %d.\n"
 msgstr "%s: Feil i %s på linje %d.\n"
 
-#: src/init.c:479
+#: src/init.c:483
 #, fuzzy, c-format
-msgid "%s: Unknown command `%s' in %s at line %d.\n"
+msgid "%s: Unknown command %s in %s at line %d.\n"
 msgstr "%s: Ukjent kommando «%s», verdi «%s».\n"
 
-#: src/init.c:524
-#, c-format
-msgid "%s: Warning: Both system and user wgetrc point to `%s'.\n"
+#: src/init.c:528
+#, fuzzy, c-format
+msgid "%s: Warning: Both system and user wgetrc point to %s.\n"
 msgstr "%s: Advarsel: Både systemets og brukerens wgetrc peker til «%s».\n"
 
-#: src/init.c:677
+#: src/init.c:681
 #, fuzzy, c-format
-msgid "%s: Invalid --execute command `%s'\n"
-msgstr "%s: Ugyldig spesifikasjon «%s»\n"
+msgid "%s: Invalid --execute command %s\n"
+msgstr "%s: %s: ugyldig kommando\n"
 
-#: src/init.c:722
+#: src/init.c:726
 #, fuzzy, c-format
-msgid "%s: %s: Invalid boolean `%s'; use `on' or `off'.\n"
+msgid "%s: %s: Invalid boolean %s; use `on' or `off'.\n"
 msgstr "%s: %s: Vennligst spesifiser «on» eller «off».\n"
 
-#: src/init.c:739
+#: src/init.c:743
 #, fuzzy, c-format
-msgid "%s: %s: Invalid number `%s'.\n"
+msgid "%s: %s: Invalid number %s.\n"
 msgstr "%s: %s: Ugyldig spesifikasjon «%s»\n"
 
-#: src/init.c:970 src/init.c:989
+#: src/init.c:974 src/init.c:993
 #, fuzzy, c-format
-msgid "%s: %s: Invalid byte value `%s'\n"
+msgid "%s: %s: Invalid byte value %s\n"
 msgstr "%s: %s: Ugyldig spesifikasjon «%s»\n"
 
-#: src/init.c:1014
+#: src/init.c:1018
 #, fuzzy, c-format
-msgid "%s: %s: Invalid time period `%s'\n"
+msgid "%s: %s: Invalid time period %s\n"
 msgstr "%s: %s: Ugyldig spesifikasjon «%s»\n"
 
-#: src/init.c:1068 src/init.c:1158 src/init.c:1261 src/init.c:1286
+#: src/init.c:1072 src/init.c:1162 src/init.c:1265 src/init.c:1290
 #, fuzzy, c-format
-msgid "%s: %s: Invalid value `%s'.\n"
+msgid "%s: %s: Invalid value %s.\n"
 msgstr "%s: %s: Ugyldig spesifikasjon «%s»\n"
 
-#: src/init.c:1105
+#: src/init.c:1109
 #, fuzzy, c-format
-msgid "%s: %s: Invalid header `%s'.\n"
+msgid "%s: %s: Invalid header %s.\n"
 msgstr "%s: %s: Ugyldig spesifikasjon «%s»\n"
 
-#: src/init.c:1171
+#: src/init.c:1175
 #, fuzzy, c-format
-msgid "%s: %s: Invalid progress type `%s'.\n"
+msgid "%s: %s: Invalid progress type %s.\n"
 msgstr "%s: %s: Ugyldig spesifikasjon «%s»\n"
 
-#: src/init.c:1230
+#: src/init.c:1234
 #, c-format
 msgid ""
-"%s: %s: Invalid restriction `%s', use [unix|windows],[lowercase|uppercase],"
+"%s: %s: Invalid restriction %s, use [unix|windows],[lowercase|uppercase],"
 "[nocontrol].\n"
 msgstr ""
 
