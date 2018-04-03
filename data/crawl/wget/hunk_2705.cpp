 #. No luck.
 #. #### This message SUCKS.  We should see what was the
 #. reason that nothing was retrieved.
-#: src/ftp.c:1775
+#: src/ftp.c:1608
 #, c-format
 msgid "No matches on pattern `%s'.\n"
 msgstr "Ingenting passer med mønstret '%s'.\n"
 
-#: src/ftp.c:1841
-#, fuzzy, c-format
-msgid "Wrote HTML-ized index to `%s' [%s].\n"
+#: src/ftp.c:1673
+#, c-format
+msgid "Wrote HTML-ized index to `%s' [%ld].\n"
 msgstr "Skrev HTML-formateret indeks til '%s' [%ld].\n"
 
-#: src/ftp.c:1846
+#: src/ftp.c:1678
 #, c-format
 msgid "Wrote HTML-ized index to `%s'.\n"
 msgstr "Skrev HTML-formateret indeks til '%s'.\n"
 
-#: src/getopt.c:675
+#: src/gen_sslfunc.c:109
+msgid "Could not seed OpenSSL PRNG; disabling SSL.\n"
+msgstr "Kunne ikke påbegynde OpenSSL PRNG; deaktiverer SSL.\n"
+
+#: src/getopt.c:454
 #, c-format
 msgid "%s: option `%s' is ambiguous\n"
 msgstr "%s: flaget '%s' er flertydig\n"
 
-#: src/getopt.c:700
+#: src/getopt.c:478
 #, c-format
 msgid "%s: option `--%s' doesn't allow an argument\n"
 msgstr "%s: flaget '--%s' tillader ikke argumenter\n"
 
-#: src/getopt.c:705
+#: src/getopt.c:483
 #, c-format
 msgid "%s: option `%c%s' doesn't allow an argument\n"
 msgstr "%s: flaget '%c%s' tillader ikke argumenter\n"
 
-#: src/getopt.c:723 src/getopt.c:896
+#: src/getopt.c:498
 #, c-format
 msgid "%s: option `%s' requires an argument\n"
 msgstr "%s: flaget '%s' kræver et argument\n"
 
 #. --option
-#: src/getopt.c:752
+#: src/getopt.c:528
 #, c-format
 msgid "%s: unrecognized option `--%s'\n"
 msgstr "%s: ukendt flag '--%s'\n"
 
 #. +option or -option
-#: src/getopt.c:756
+#: src/getopt.c:532
 #, c-format
 msgid "%s: unrecognized option `%c%s'\n"
 msgstr "%s: ukendt flag '%c%s'\n"
 
 #. 1003.2 specifies the format of this message.
-#: src/getopt.c:782
+#: src/getopt.c:563
 #, c-format
 msgid "%s: illegal option -- %c\n"
 msgstr "%s: ugyldigt flag -- %c\n"
 
-#: src/getopt.c:785
-#, fuzzy, c-format
-msgid "%s: invalid option -- %c\n"
-msgstr "%s: ugyldigt flag -- %c\n"
-
 #. 1003.2 specifies the format of this message.
-#: src/getopt.c:815 src/getopt.c:945
+#: src/getopt.c:602
 #, c-format
 msgid "%s: option requires an argument -- %c\n"
 msgstr "%s: flaget kræver et argument -- %c\n"
 
-#: src/getopt.c:862
-#, fuzzy, c-format
-msgid "%s: option `-W %s' is ambiguous\n"
-msgstr "%s: flaget '%s' er flertydig\n"
-
-#: src/getopt.c:880
-#, fuzzy, c-format
-msgid "%s: option `-W %s' doesn't allow an argument\n"
-msgstr "%s: flaget '--%s' tillader ikke argumenter\n"
-
-#: src/host.c:371
-#, fuzzy
-msgid "Unknown host"
-msgstr "Ukendt fejl"
-
-#. Message modeled after what gai_strerror returns in similar
-#. circumstances.
-#: src/host.c:375
-msgid "Temporary failure in name resolution"
-msgstr ""
-
-#: src/host.c:377
-msgid "Unknown error"
-msgstr "Ukendt fejl"
-
-#: src/host.c:756
+#: src/host.c:271
 #, c-format
 msgid "Resolving %s... "
 msgstr "Løser %s..."
 
-#: src/host.c:800 src/host.c:829
+#: src/host.c:278
 #, c-format
 msgid "failed: %s.\n"
 msgstr "mislykkedes: %s.\n"
 
-#: src/host.c:809
-msgid "failed: No IPv4/IPv6 addresses for host.\n"
-msgstr ""
+#: src/host.c:348
+msgid "Host not found"
+msgstr "Vært ikke fundet"
 
-#: src/host.c:832
-#, fuzzy
-msgid "failed: timed out.\n"
-msgstr "mislykkedes: %s.\n"
+#: src/host.c:350
+msgid "Unknown error"
+msgstr "Ukendt fejl"
 
-#: src/html-url.c:298
+#: src/html-url.c:336
 #, c-format
 msgid "%s: Cannot resolve incomplete link %s.\n"
 msgstr "%s: kan ikke løse ukomplet lænke %s.\n"
 
-#: src/http.c:373 src/http.c:1549
-#, c-format
-msgid "Failed writing HTTP request: %s.\n"
-msgstr "Fejl ved skrivning af HTTP-forespørgsel: %s.\n"
+#. this is fatal
+#: src/http.c:573
+msgid "Failed to set up an SSL context\n"
+msgstr "Kunne ikke opsætte et SSL-miljø\n"
 
-#: src/http.c:687
-msgid "No headers, assuming HTTP/0.9"
-msgstr ""
+#: src/http.c:579
+#, c-format
+msgid "Failed to load certificates from %s\n"
+msgstr "Kunne ikke indlæse certifikater fra %s\n"
 
-#: src/http.c:1198
-msgid "Disabling SSL due to encountered errors.\n"
-msgstr ""
+#: src/http.c:583 src/http.c:591
+msgid "Trying without the specified certificate\n"
+msgstr "Prøver uden det angivne certifikat\n"
 
-#: src/http.c:1417
-#, fuzzy, c-format
-msgid "Reusing existing connection to %s:%d.\n"
-msgstr "Genbruger forbindelse til %s:%hu.\n"
+#: src/http.c:587
+#, c-format
+msgid "Failed to get certificate key from %s\n"
+msgstr "Kunne ikke få certifikatnøgle fra %s\n"
 
-#: src/http.c:1479
-#, fuzzy, c-format
-msgid "Failed writing to proxy: %s.\n"
-msgstr "Fejl ved skrivning af HTTP-forespørgsel: %s.\n"
+#: src/http.c:657 src/http.c:1620
+msgid "Unable to establish SSL connection.\n"
+msgstr "Kunne ikke etablere SSL-forbindelse.\n"
 
-#: src/http.c:1488
-#, fuzzy, c-format
-msgid "Failed reading proxy response: %s\n"
-msgstr "Fejl ved skrivning af HTTP-forespørgsel: %s.\n"
+#: src/http.c:666
+#, c-format
+msgid "Reusing connection to %s:%hu.\n"
+msgstr "Genbruger forbindelse til %s:%hu.\n"
 
-#: src/http.c:1508
+#: src/http.c:868
 #, c-format
-msgid "Proxy tunneling failed: %s"
-msgstr ""
+msgid "Failed writing HTTP request: %s.\n"
+msgstr "Fejl ved skrivning af HTTP-forespørgsel: %s.\n"
 
-#: src/http.c:1555
+#: src/http.c:873
 #, c-format
 msgid "%s request sent, awaiting response... "
 msgstr "%s forespørgsel sendt, afventer svar... "
 
-#: src/http.c:1566
-#, fuzzy
-msgid "No data received.\n"
-msgstr "Ingen data modtaget"
+#: src/http.c:917
+msgid "End of file while parsing headers.\n"
+msgstr "Filafslutning fundet ved læsning af toptekster.\n"
 
-#: src/http.c:1573
+#: src/http.c:927
 #, c-format
 msgid "Read error (%s) in headers.\n"
 msgstr "Læsefejl (%s) i toptekster.\n"
 
-#. If the authentication header is missing or
-#. unrecognized, there's no sense in retrying.
-#: src/http.c:1658
-msgid "Unknown authentication scheme.\n"
-msgstr "Ukendt autorisations-protokol.\n"
-
-#: src/http.c:1682
-msgid "Authorization failed.\n"
-msgstr "Autorisation mislykkedes\n"
+#: src/http.c:962
+msgid "No data received"
+msgstr "Ingen data modtaget"
 
-#: src/http.c:1696
+#: src/http.c:964
 msgid "Malformed status line"
 msgstr "Forkert udformet statuslinje"
 
-#: src/http.c:1698
+#: src/http.c:969
 msgid "(no description)"
 msgstr "(ingen beskrivelse)"
 
-#: src/http.c:1769
+#: src/http.c:1101
+msgid "Authorization failed.\n"
+msgstr "Autorisation mislykkedes\n"
+
+#: src/http.c:1108
+msgid "Unknown authentication scheme.\n"
+msgstr "Ukendt autorisations-protokol.\n"
+
+#: src/http.c:1148
 #, c-format
 msgid "Location: %s%s\n"
 msgstr "Sted: %s%s\n"
 
-#: src/http.c:1770 src/http.c:1867
+#: src/http.c:1149 src/http.c:1282
 msgid "unspecified"
 msgstr "uspecificeret"
 
-#: src/http.c:1771
+#: src/http.c:1150
 msgid " [following]"
 msgstr " [omdirigeret]"
 
-#. If `-c' is in use and the file has been fully downloaded (or
-#. the remote file has shrunk), Wget effectively requests bytes
-#. after the end of file and the server response with 416.
-#: src/http.c:1817
+#: src/http.c:1213
+msgid "\n    The file is already fully retrieved; nothing to do.\n\n"
+msgstr "\n    Filen er allerede fuldt overført; ingen handling nødvendig.\n\n"
+
+#: src/http.c:1229
+#, c-format
 msgid ""
 "\n"
-"    The file is already fully retrieved; nothing to do.\n"
+"Continued download failed on this file, which conflicts with `-c'.\n"
+"Refusing to truncate existing file `%s'.\n"
 "\n"
 msgstr ""
 "\n"
-"    Filen er allerede fuldt overført; ingen handling nødvendig.\n"
+"Fortsat hentning mislykkedes for denne fil, hvilket er i modsætning til '-c'.\n"
+"Nægter at afkorte eksisterende fil '%s'.\n"
 "\n"
 
 #. No need to print this output if the body won't be
 #. downloaded at all, or if the original server response is
 #. printed.
-#: src/http.c:1847
+#: src/http.c:1272
 msgid "Length: "
 msgstr "Længde: "
 
-#: src/http.c:1867
+#: src/http.c:1277
+#, c-format
+msgid " (%s to go)"
+msgstr " (%s tilbage)"
+
+#: src/http.c:1282
 msgid "ignored"
 msgstr "ignoreret"
 
-#: src/http.c:2007
+#: src/http.c:1413
 msgid "Warning: wildcards not supported in HTTP.\n"
 msgstr "Advarsel: jokertegn ikke understøttet i HTTP.\n"
 
 #. If opt.noclobber is turned on and file already exists, do not
 #. retrieve the file
-#: src/http.c:2042
+#: src/http.c:1443
 #, c-format
 msgid "File `%s' already there, will not retrieve.\n"
 msgstr "Filen '%s' hentes ikke, fordi den allerede eksisterer.\n"
 
-#: src/http.c:2232
+#: src/http.c:1611
 #, c-format
 msgid "Cannot write to `%s' (%s).\n"
 msgstr "Kan ikke skrive til '%s' (%s).\n"
 
-#. Another fatal error.
-#: src/http.c:2239
-msgid "Unable to establish SSL connection.\n"
-msgstr "Kunne ikke etablere SSL-forbindelse.\n"
-
-#: src/http.c:2248
+#: src/http.c:1630
 #, c-format
 msgid "ERROR: Redirection (%d) without location.\n"
 msgstr "FEJL: Omdirigering (%d) uden nyt sted.\n"
 
-#: src/http.c:2278
+#: src/http.c:1662
 #, c-format
 msgid "%s ERROR %d: %s.\n"
 msgstr "%s FEJL %d: %s.\n"
 
-#: src/http.c:2291
+#: src/http.c:1675
 msgid "Last-modified header missing -- time-stamps turned off.\n"
 msgstr "Last-modified toptekst mangler -- tidsstempling slås fra.\n"
 
-#: src/http.c:2299
+#: src/http.c:1683
 msgid "Last-modified header invalid -- time-stamp ignored.\n"
 msgstr "Last-modified toptekst ugyldig -- tidsstempel ignoreret.\n"
 
-#: src/http.c:2322
+#: src/http.c:1706
 #, c-format
-msgid ""
-"Server file no newer than local file `%s' -- not retrieving.\n"
-"\n"
-msgstr ""
-"Serverfil ikke nyere end lokal fil '%s' - hentes ikke.\n"
-"\n"
+msgid "Server file no newer than local file `%s' -- not retrieving.\n\n"
+msgstr "Serverfil ikke nyere end lokal fil '%s' - hentes ikke.\n\n"
 
-#: src/http.c:2330
-#, fuzzy, c-format
-msgid "The sizes do not match (local %s) -- retrieving.\n"
+#: src/http.c:1714
+#, c-format
+msgid "The sizes do not match (local %ld) -- retrieving.\n"
 msgstr "Størrelserne er forskellige (lokal %ld) - hentes.\n"
 
-#: src/http.c:2335
+#: src/http.c:1718
 msgid "Remote file is newer, retrieving.\n"
 msgstr "Fil på server er nyere - hentes.\n"
 
-#: src/http.c:2377
-#, fuzzy, c-format
-msgid ""
-"%s (%s) - `%s' saved [%s/%s]\n"
-"\n"
-msgstr ""
-"%s (%s) - '%s' gemt [%ld/%ld]\n"
-"\n"
+#: src/http.c:1759
+#, c-format
+msgid "%s (%s) - `%s' saved [%ld/%ld]\n\n"
+msgstr "%s (%s) - '%s' gemt [%ld/%ld]\n\n"
 
-#: src/http.c:2434
-#, fuzzy, c-format
-msgid "%s (%s) - Connection closed at byte %s. "
+#: src/http.c:1809
+#, c-format
+msgid "%s (%s) - Connection closed at byte %ld. "
 msgstr "%s (%s) - Forbindelse lukket ved byte %ld. "
 
-#: src/http.c:2443
-#, fuzzy, c-format
-msgid ""
-"%s (%s) - `%s' saved [%s/%s])\n"
-"\n"
-msgstr ""
-"%s (%s) - '%s' gemt [%ld/%ld]\n"
-"\n"
+#: src/http.c:1818
+#, c-format
+msgid "%s (%s) - `%s' saved [%ld/%ld])\n\n"
+msgstr "%s (%s) - '%s' gemt [%ld/%ld]\n\n"
 
-#: src/http.c:2469
-#, fuzzy, c-format
-msgid "%s (%s) - Connection closed at byte %s/%s. "
+#: src/http.c:1839
+#, c-format
+msgid "%s (%s) - Connection closed at byte %ld/%ld. "
 msgstr "%s (%s) - Forbindelse lukket ved byte %ld/%ld. "
 
-#: src/http.c:2483
-#, fuzzy, c-format
-msgid "%s (%s) - Read error at byte %s (%s)."
+#: src/http.c:1851
+#, c-format
+msgid "%s (%s) - Read error at byte %ld (%s)."
 msgstr "%s (%s) - Læsefejl ved byte %ld (%s)."
 
-#: src/http.c:2493
-#, fuzzy, c-format
-msgid "%s (%s) - Read error at byte %s/%s (%s). "
-msgstr "%s (%s) - Læsefejl ved byte %ld/%ld (%s)."
-
-#: src/init.c:369
+#: src/http.c:1860
 #, c-format
-msgid "%s: WGETRC points to %s, which doesn't exist.\n"
-msgstr ""
+msgid "%s (%s) - Read error at byte %ld/%ld (%s). "
+msgstr "%s (%s) - Læsefejl ved byte %ld/%ld (%s)."
 
-#: src/init.c:433 src/netrc.c:277
+#: src/init.c:355 src/netrc.c:265
 #, c-format
 msgid "%s: Cannot read %s (%s).\n"
 msgstr "%s: Kan ikke læse %s (%s).\n"
 
-#: src/init.c:451
+#: src/init.c:373 src/init.c:379
 #, c-format
 msgid "%s: Error in %s at line %d.\n"
 msgstr "%s: Fejl i %s på linje %d.\n"
 
-#: src/init.c:457
-#, fuzzy, c-format
-msgid "%s: Syntax error in %s at line %d.\n"
-msgstr "%s: Fejl i %s på linje %d.\n"
-
-#: src/init.c:462
-#, fuzzy, c-format
-msgid "%s: Unknown command `%s' in %s at line %d.\n"
-msgstr "%s: FEJL: Ukendt kommando '%s', værdi '%s'.\n"
-
-#: src/init.c:507
+#: src/init.c:411
 #, c-format
 msgid "%s: Warning: Both system and user wgetrc point to `%s'.\n"
 msgstr "%s: Advarsel: Både systemets og brugerens wgetrc peger på '%s'.\n"
 
-#: src/init.c:661
-#, fuzzy, c-format
-msgid "%s: Invalid --execute command `%s'\n"
-msgstr "%s: Ugyldig specifikation '%s'\n"
+#: src/init.c:503
+#, c-format
+msgid "%s: BUG: unknown command `%s', value `%s'.\n"
+msgstr "%s: FEJL: Ukendt kommando '%s', værdi '%s'.\n"
+
+#: src/init.c:537
+#, c-format
+msgid "%s: %s: Cannot convert `%s' to an IP address.\n"
+msgstr "%s: %s: Kan ikke omforme '%s' til en IP-adresse.\n"
 
-#: src/init.c:707
-#, fuzzy, c-format
-msgid "%s: %s: Invalid boolean `%s', use `on' or `off'.\n"
+#: src/init.c:570
+#, c-format
+msgid "%s: %s: Please specify on or off.\n"
 msgstr "%s: %s: Venligst angiv 'on' eller 'off'.\n"
 
-#: src/init.c:750
-#, fuzzy, c-format
-msgid "%s: %s: Invalid boolean `%s', use always, on, off, or never.\n"
+#: src/init.c:614
+#, c-format
+msgid "%s: %s: Please specify always, on, off, or never.\n"
 msgstr "%s: %s: Venligst angiv 'always', 'on' 'off', eller 'never'.\n"
 
-#: src/init.c:767
-#, fuzzy, c-format
-msgid "%s: %s: Invalid number `%s'.\n"
-msgstr "%s: %s: Ugyldig specifikation '%s'\n"
-
-#: src/init.c:998 src/init.c:1017
-#, fuzzy, c-format
-msgid "%s: %s: Invalid byte value `%s'\n"
-msgstr "%s: %s: Ugyldig fremskridtstype '%s'\n"
-
-#: src/init.c:1042
-#, fuzzy, c-format
-msgid "%s: %s: Invalid time period `%s'\n"
-msgstr "%s: %s: Ugyldig specifikation '%s'\n"
-
-#: src/init.c:1096 src/init.c:1186 src/init.c:1281 src/init.c:1306
-#, fuzzy, c-format
-msgid "%s: %s: Invalid value `%s'.\n"
+#: src/init.c:633 src/init.c:900 src/init.c:981
+#, c-format
+msgid "%s: %s: Invalid specification `%s'.\n"
 msgstr "%s: %s: Ugyldig specifikation '%s'\n"
 
-#: src/init.c:1133
-#, fuzzy, c-format
-msgid "%s: %s: Invalid header `%s'.\n"
-msgstr "%s: %s: Ugyldig specifikation '%s'\n"
+#: src/init.c:789 src/init.c:811 src/init.c:833 src/init.c:859
+#, c-format
+msgid "%s: Invalid specification `%s'\n"
+msgstr "%s: Ugyldig specifikation '%s'\n"
 
-#: src/init.c:1198
+#: src/init.c:949
 #, c-format
 msgid "%s: %s: Invalid progress type `%s'.\n"
 msgstr "%s: %s: Ugyldig fremskridtstype '%s'\n"
 
-#: src/init.c:1249
-#, fuzzy, c-format
-msgid "%s: %s: Invalid restriction `%s', use `unix' or `windows'.\n"
-msgstr "%s: %s: Ugyldig specifikation '%s'\n"
-
-#: src/log.c:806
+#: src/log.c:641
 #, c-format
-msgid ""
-"\n"
-"%s received, redirecting output to `%s'.\n"
-msgstr ""
-"\n"
-"%s modtaget, omdirigerer udskrifter til '%s'.\n"
+msgid "\n%s received, redirecting output to `%s'.\n"
+msgstr "\n%s modtaget, omdirigerer udskrifter til '%s'.\n"
 
 #. Eek!  Opening the alternate log file has failed.  Nothing we
 #. can do but disable printing completely.
-#: src/log.c:816
-#, fuzzy, c-format
-msgid ""
-"\n"
-"%s received.\n"
-msgstr "Ingen data modtaget"
-
-#: src/log.c:817
+#: src/log.c:648
 #, c-format
 msgid "%s: %s; disabling logging.\n"
 msgstr "%s: %s; deaktiverer logning.\n"
 
-#: src/main.c:375
+#: src/main.c:116
 #, c-format
 msgid "Usage: %s [OPTION]... [URL]...\n"
 msgstr "Brug: %s [FLAG]... [URL]...\n"
 
-#: src/main.c:387
-#, fuzzy
-msgid ""
-"Mandatory arguments to long options are mandatory for short options too.\n"
-"\n"
+#: src/main.c:124
+#, c-format
+msgid "GNU Wget %s, a non-interactive network retriever.\n"
+msgstr "GNU Wget %s, en ikke-interaktiv informationsagent.\n"
+
+#. Had to split this in parts, so the #@@#%# Ultrix compiler and cpp
+#. don't bitch.  Also, it makes translation much easier.
+#: src/main.c:129
+msgid "\nMandatory arguments to long options are mandatory for short options too.\n\n"
 msgstr ""
 "\n"
 "Obligatoriske argumenter til lange flag er obligatoriske også \n"
 "for korte.\n"
 "\n"
 
-#: src/main.c:389
-msgid "Startup:\n"
+#: src/main.c:133
+msgid ""
+"Startup:\n"
+"  -V,  --version           display the version of Wget and exit.\n"
+"  -h,  --help              print this help.\n"
+"  -b,  --background        go to background after startup.\n"
+"  -e,  --execute=COMMAND   execute a `.wgetrc'-style command.\n"
+"\n"
 msgstr ""
+"Opstart:\n"
+"  -V,  --version           vis Wget's versionsnummer og afslut.\n"
+"  -h,  --help              udskriv denne hjælpetekst.\n"
+"  -b,  --background        kør i baggrunden efter opstart.\n"
+"  -e,  --execute=KOMMANDO  udfør en '.wgetrc'-kommando.\n"
+"\n"
 
-#: src/main.c:391
-msgid "  -V,  --version           display the version of Wget and exit.\n"
+#: src/main.c:140
+msgid ""
+"Logging and input file:\n"
+"  -o,  --output-file=FILE     log messages to FILE.\n"
+"  -a,  --append-output=FILE   append messages to FILE.\n"
+"  -d,  --debug                print debug output.\n"
+"  -q,  --quiet                quiet (no output).\n"
+"  -v,  --verbose              be verbose (this is the default).\n"
+"  -nv, --non-verbose          turn off verboseness, without being quiet.\n"
+"  -i,  --input-file=FILE      download URLs found in FILE.\n"
+"  -F,  --force-html           treat input file as HTML.\n"
+"  -B,  --base=URL             prepends URL to relative links in -F -i file.\n"
+"       --sslcertfile=FILE     optional client certificate.\n"
+"       --sslcertkey=KEYFILE   optional keyfile for this certificate.\n"
+"       --egd-file=FILE        file name of the EGD socket.\n"
+"\n"
 msgstr ""
+"Logning og indlæsning:\n"
+"  -o,  --output-file=FIL      log beskeder til FIL.\n"
+"  -a,  --append-output=FIL    tilføj beskeder til slutningen af FIL.\n"
+"  -d,  --debug                skriv fejlsøgningsinformation.\n"
+"  -q,  --quiet                stille (ingen udskrifter).\n"
+"  -v,  --verbose              vær udførlig (standard).\n"
+"  -nv, --non-verbose          mindre udførlig, men ikke stille.\n"
+"  -i,  --input-file=FIL       hent URLer fundet i FIL.\n"
+"  -F,  --force-html           behandl inddatafil som HTML.\n"
+"  -B,  --base=URL             foranstiller URL til relative lænker i -F -i fil.\n"
+"       --sslcertfile=FIL      valgbart klient-certifikat.\n"
+"       --sslcertkey=NØGLEFIL  valgbar nøglefil for dette certifikat.\n"
+"       --egd-file=FIL         filnavn for EGD-soklen.\n"
+"\n"
 
-#: src/main.c:393
-msgid "  -h,  --help              print this help.\n"
+#: src/main.c:155
+msgid ""
+"Download:\n"
+"       --bind-address=ADDRESS   bind to ADDRESS (hostname or IP) on local host.\n"
+"  -t,  --tries=NUMBER           set number of retries to NUMBER (0 unlimits).\n"
+"  -O   --output-document=FILE   write documents to FILE.\n"
+"  -nc, --no-clobber             don't clobber existing files or use .# suffixes.\n"
+"  -c,  --continue               resume getting a partially-downloaded file.\n"
+"       --progress=TYPE          select progress gauge type.\n"
+"  -N,  --timestamping           don't re-retrieve files unless newer than local.\n"
+"  -S,  --server-response        print server response.\n"
+"       --spider                 don't download anything.\n"
+"  -T,  --timeout=SECONDS        set the read timeout to SECONDS.\n"
+"  -w,  --wait=SECONDS           wait SECONDS between retrievals.\n"
+"       --waitretry=SECONDS      wait 1...SECONDS between retries of a retrieval.\n"
+"       --random-wait            wait from 0...2*WAIT secs between retrievals.\n"
+"  -Y,  --proxy=on/off           turn proxy on or off.\n"
+"  -Q,  --quota=NUMBER           set retrieval quota to NUMBER.\n"
+"       --limit-rate=RATE        limit download rate to RATE.\n"
+"\n"
 msgstr ""
+"Hentning:\n"
+"       --bind-address=ADRESSE   bind til ADRESSE (værtsnavn eller IP) på lokal vært.\n"
+"  -t,  --tries=ANTAL            maksimalt antal forsøg (0 for uendelig).\n"
+"  -O   --output-document=FIL    skriv dokumenter til FIL.\n"
+"  -nc, --no-clobber             berør ikke eksisterende filer, eller brug .#-endelser.\n"
+"  -c,  --continue               fortsæt hentning af en eksisterende fil.\n"
+"       --progress=TYPE          vælg type af fremskridtsvisning.\n"
+"  -N,  --timestamping           hent ikke filer igen som er ældre end eksisterende.\n"
+"  -S,  --server-response        vis svar fra serveren.\n"
+"       --spider                 hent ikke filer.\n"
+"  -T,  --timeout=SEKUNDER       sæt ventetid ved læsning til SEKUNDER.\n"
+"  -w,  --wait=SEKUNDER          sæt ventetid mellem filer til SEKUNDER.\n"
+"       --waitretry=SEKUNDER\twait 1...SEKUNDER mellem forsøg på gentagelse af en hentning.\n"
+"       --random-wait            vent fra 0...2*WAIT sekunder mellem modtagelse.\n"
+"  -Y,  --proxy=on/off           slå brug af proxy til eller fra.\n"
+"  -Q,  --quota=ANTAL            sæt hente-kvote til ANTAL.\n"
+"       --limit-rate=RATE        begræns hentingshastighed til RATE.\n"
+"\n"
 
-#: src/main.c:395
-msgid "  -b,  --background        go to background after startup.\n"
+#: src/main.c:174
+msgid ""
+"Directories:\n"
+"  -nd  --no-directories            don't create directories.\n"
+"  -x,  --force-directories         force creation of directories.\n"
+"  -nH, --no-host-directories       don't create host directories.\n"
+"  -P,  --directory-prefix=PREFIX   save files to PREFIX/...\n"
+"       --cut-dirs=NUMBER           ignore NUMBER remote directory components.\n"
+"\n"
 msgstr ""
+"Kataloger:\n"
+"  -nd  --no-directories             lav ikke kataloger.\n"
+"  -x,  --force-directories          lav kataloger.\n"
+"  -nH, --no-host-directories        lav ikke ovenstående kataloger.\n"
+"  -P,  --directory-prefix=PRÆFIKS   skriv filer til PRÆFIKS/...\n"
+"       --cut-dirs=ANTAL             ignorér ANTAL komponenter af serverens\n"
+"                                    katalognavn.\n"
+"\n"
 
-#: src/main.c:397
-msgid "  -e,  --execute=COMMAND   execute a `.wgetrc'-style command.\n"
+#: src/main.c:182
+msgid ""
+"HTTP options:\n"
+"       --http-user=USER      set http user to USER.\n"
+"       --http-passwd=PASS    set http password to PASS.\n"
+"  -C,  --cache=on/off        (dis)allow server-cached data (normally allowed).\n"
+"  -E,  --html-extension      save all text/html documents with .html extension.\n"
+"       --ignore-length       ignore `Content-Length' header field.\n"
+"       --header=STRING       insert STRING among the headers.\n"
+"       --proxy-user=USER     set USER as proxy username.\n"
+"       --proxy-passwd=PASS   set PASS as proxy password.\n"
+"       --referer=URL         include `Referer: URL' header in HTTP request.\n"
+"  -s,  --save-headers        save the HTTP headers to file.\n"
+"  -U,  --user-agent=AGENT    identify as AGENT instead of Wget/VERSION.\n"
+"       --no-http-keep-alive  disable HTTP keep-alive (persistent connections).\n"
+"       --cookies=off         don't use cookies.\n"
+"       --load-cookies=FILE   load cookies from FILE before session.\n"
+"       --save-cookies=FILE   save cookies to FILE after session.\n"
+"\n"
 msgstr ""
+"HTTP-flag:\n"
+"       --http-user=BRUGER      sæt HTTP-bruger til BRUGER.\n"
+"       --http-passwd=PASSORD   sæt HTTP-adgangskode til PASSORD.\n"
+"  -C,  --cache=on/off          tillad (ikke) brug af mellemlager på server.\n"
+"  -E,  --html-extension        gem alle tekst/html dokumenter med .html filkode.\n"
+"       --ignore-length         ignorer 'Content-Length' felt i toptekst.\n"
+"       --header=TEKST          sæt TEKST ind som en toptekst.\n"
+"       --proxy-user=BRUGER     sæt proxy-bruger til BRUGER.\n"
+"       --proxy-passwd=PASSORD  sæt proxy-adgangskode til PASSORD.\n"
+"       --referer=URL           brug `Referer: URL' kommando i HTTP-forespørgsel.\n"
+"  -s,  --save-headers          skriv HTTP-toptekster til fil.\n"
+"  -U,  --user-agent=AGENT      identificer som AGENT i stedet for \n"
+"                               'Wget/VERSION'.\n"
+"       --no-http-keep-alive    deaktivér HTTP keep-alive (overlevende forbindelser).\n"
+"       --cookies=off           brug ikke infokager.\n"
+"       --load-cookies=FILE     indlæs infokager fra FIL før session.\n"
+"       --save-cookies=FILE     gem infokager i FIL efter session.\n"
+"\n"
 
-#: src/main.c:401
-msgid "Logging and input file:\n"
+#: src/main.c:200
+msgid ""
+"FTP options:\n"
+"  -nr, --dont-remove-listing   don't remove `.listing' files.\n"
+"  -g,  --glob=on/off           turn file name globbing on or off.\n"
+"       --passive-ftp           use the \"passive\" transfer mode.\n"
+"       --retr-symlinks         when recursing, get linked-to files (not dirs).\n"
+"\n"
 msgstr ""
+"FTP-flag:\n"
+"  -nr, --dont-remove-listing   fjern ikke `.listing' filer.\n"
+"  -g,  --glob=on/off           tolk (ikke) brug af jokertegn i filnavn.\n"
+"       --passive-ftp           brug passiv overførselsmetode.\n"
+"       --retr-symlinks         hent filer (ikke kataloger) der er lænket til, ved rekursiv brug.\n"
+"\n"
 
-#: src/main.c:403
-msgid "  -o,  --output-file=FILE    log messages to FILE.\n"
+#: src/main.c:207
+msgid ""
+"Recursive retrieval:\n"
+"  -r,  --recursive          recursive web-suck -- use with care!\n"
+"  -l,  --level=NUMBER       maximum recursion depth (inf or 0 for infinite).\n"
+"       --delete-after       delete files locally after downloading them.\n"
+"  -k,  --convert-links      convert non-relative links to relative.\n"
+"  -K,  --backup-converted   before converting file X, back up as X.orig.\n"
+"  -m,  --mirror             shortcut option equivalent to -r -N -l inf -nr.\n"
+"  -p,  --page-requisites    get all images, etc. needed to display HTML page.\n"
+"\n"
 msgstr ""
+"Rekursiv nedlasting:\n"
+"  -r,  --recursive             tillad rekursiv nedlasting -- brug med omtanke!\n"
+"  -l,  --level=ANTAL           maksimalt antal rekursionsniveauer (0=uendelig).\n"
+"       --delete-after          slet hentede filer.\n"
+"  -k,  --convert-links         konverter absolutte lænker til relative.\n"
+"  -K,  --backup-converted      før fil X konverteres, sikkerhedskopiér som X.orig.\n"
+"  -m,  --mirror                sæt passende flag for spejling af servere.\n"
+"  -p,  --page-requisites       hent alle billeder osv. der er nødvendige for at vise HTML siden.\n"
+"\n"
 
-#: src/main.c:405
-msgid "  -a,  --append-output=FILE  append messages to FILE.\n"
+#: src/main.c:217
+msgid ""
+"Recursive accept/reject:\n"
+"  -A,  --accept=LIST                comma-separated list of accepted extensions.\n"
+"  -R,  --reject=LIST                comma-separated list of rejected extensions.\n"
+"  -D,  --domains=LIST               comma-separated list of accepted domains.\n"
+"       --exclude-domains=LIST       comma-separated list of rejected domains.\n"
+"       --follow-ftp                 follow FTP links from HTML documents.\n"
+"       --follow-tags=LIST           comma-separated list of followed HTML tags.\n"
+"  -G,  --ignore-tags=LIST           comma-separated list of ignored HTML tags.\n"
+"  -H,  --span-hosts                 go to foreign hosts when recursive.\n"
+"  -L,  --relative                   follow relative links only.\n"
+"  -I,  --include-directories=LIST   list of allowed directories.\n"
+"  -X,  --exclude-directories=LIST   list of excluded directories.\n"
+"  -np, --no-parent                  don't ascend to the parent directory.\n"
+"\n"
 msgstr ""
+"Hvad er tilladt ved rekursion:\n"
+"  -A,  --accept=LISTE               liste med tilladte filtyper.\n"
+"  -R,  --reject=LISTE               liste med ikke-tilladte filtyper.\n"
+"  -D,  --domains=LISTE              liste med tilladte domæner.\n"
+"       --exclude-domains=LISTE      liste med ikke-tilladte domæner.\n"
+"       --follow-ftp                 følg FTP-lænker fra HTML-dokumenter.\n"
+"       --follow-tags=LIST           komma-separeret liste af fulgte HTML-mærker.\n"
+"  -G,  --ignore-tags=LIST           komma-separeret liste af ignorerede HTML-mærker.\n"
+"  -H,  --span-hosts                 følg lænker til andre værter.\n"
+"  -L,  --relative                   følg kun relative lænker.\n"
+"  -I,  --include-directories=LISTE  liste med tilladte katalognavne.\n"
+"  -X,  --exclude-directories=LISTE  liste med ikke-tilladte katalognavne.\n"
+"  -np, --no-parent                  følg ikke lænke til ovenliggende katalog.\n"
+"\n"
 
-#: src/main.c:408
-msgid "  -d,  --debug               print lots of debugging information.\n"
-msgstr ""
+#: src/main.c:232
+msgid "Mail bug reports and suggestions to <bug-wget@gnu.org>.\n"
+msgstr "Rapportér fejl og send forslag til <bug-wget@gnu.org>.\n"
 
-#: src/main.c:411
-msgid "  -q,  --quiet               quiet (no output).\n"
-msgstr ""
+#: src/main.c:420
+#, c-format
+msgid "%s: debug support not compiled in.\n"
+msgstr "%s: understøttelse for fejlsøgning ikke inkluderet ved oversættelse.\n"
 
-#: src/main.c:413
-msgid "  -v,  --verbose             be verbose (this is the default).\n"
-msgstr ""
+#: src/main.c:472
+msgid "Copyright (C) 1995, 1996, 1997, 1998, 2000, 2001 Free Software Foundation, Inc.\n"
+msgstr "Ophavsret © 1995, 1996, 1997, 1998, 2000, 2001 Free Software Foundation, Inc.\n"
 
-#: src/main.c:415
+#: src/main.c:474
 msgid ""
-"  -nv, --no-verbose          turn off verboseness, without being quiet.\n"
-msgstr ""
-
-#: src/main.c:417
-msgid "  -i,  --input-file=FILE     download URLs found in FILE.\n"
+"This program is distributed in the hope that it will be useful,\n"
+"but WITHOUT ANY WARRANTY; without even the implied warranty of\n"
+"MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the\n"
+"GNU General Public License for more details.\n"
 msgstr ""
+"Dette program distribueres i håb om at det bliver fundet nyttigt,\n"
+"men UDEN NOGEN GARANTIER; ikke engang for SALGBARHED eller\n"
+"EGNETHED TIL NOGEN SPECIEL OPGAVE.\n"
+"Se 'GNU General Public License' for detaljer.\n"
 
-#: src/main.c:419
-msgid "  -F,  --force-html          treat input file as HTML.\n"
-msgstr ""
+#: src/main.c:479
+msgid "\nOriginally written by Hrvoje Niksic <hniksic@arsdigita.com>.\n"
+msgstr "\nOprindeligt skrevet af Hrvoje Niksic <hniksic@arsdigita.com>.\n"
 
-#: src/main.c:421
-msgid ""
-"  -B,  --base=URL            prepends URL to relative links in -F -i file.\n"
-msgstr ""
+#: src/main.c:578
+#, c-format
+msgid "%s: %s: invalid command\n"
+msgstr "%s: %s: ugyldig kommando\n"
 
-#: src/main.c:425
-msgid "Download:\n"
-msgstr ""
-
-#: src/main.c:427
-msgid ""
-"  -t,  --tries=NUMBER            set number of retries to NUMBER (0 "
-"unlimits).\n"
-msgstr ""
-
-#: src/main.c:429
-msgid "       --retry-connrefused       retry even if connection is refused.\n"
-msgstr ""
-
-#: src/main.c:431
-msgid "  -O,  --output-document=FILE    write documents to FILE.\n"
-msgstr ""
-
-#: src/main.c:433
-msgid ""
-"  -nc, --no-clobber              skip downloads that would download to\n"
-"                                 existing files.\n"
-msgstr ""
-
-#: src/main.c:436
-msgid ""
-"  -c,  --continue                resume getting a partially-downloaded "
-"file.\n"
-msgstr ""
-
-#: src/main.c:438
-msgid "       --progress=TYPE           select progress gauge type.\n"
-msgstr ""
-
-#: src/main.c:440
-msgid ""
-"  -N,  --timestamping            don't re-retrieve files unless newer than\n"
-"                                 local.\n"
-msgstr ""
-
-#: src/main.c:443
-msgid "  -S,  --server-response         print server response.\n"
-msgstr ""
-
-#: src/main.c:445
-msgid "       --spider                  don't download anything.\n"
-msgstr ""
-
-#: src/main.c:447
-msgid "  -T,  --timeout=SECONDS         set all timeout values to SECONDS.\n"
-msgstr ""
-
-#: src/main.c:449
-msgid "       --dns-timeout=SECS        set the DNS lookup timeout to SECS.\n"
-msgstr ""
-
-#: src/main.c:451
-msgid "       --connect-timeout=SECS    set the connect timeout to SECS.\n"
-msgstr ""
-
-#: src/main.c:453
-msgid "       --read-timeout=SECS       set the read timeout to SECS.\n"
-msgstr ""
-
-#: src/main.c:455
-msgid "  -w,  --wait=SECONDS            wait SECONDS between retrievals.\n"
-msgstr ""
-
-#: src/main.c:457
-msgid ""
-"       --waitretry=SECONDS       wait 1..SECONDS between retries of a "
-"retrieval.\n"
-msgstr ""
-
-#: src/main.c:459
-msgid ""
-"       --random-wait             wait from 0...2*WAIT secs between "
-"retrievals.\n"
-msgstr ""
-
-#: src/main.c:461
-msgid "  -Y,  --proxy                   explicitly turn on proxy.\n"
-msgstr ""
-
-#: src/main.c:463
-msgid "       --no-proxy                explicitly turn off proxy.\n"
-msgstr ""
-
-#: src/main.c:465
-msgid "  -Q,  --quota=NUMBER            set retrieval quota to NUMBER.\n"
-msgstr ""
-
-#: src/main.c:467
-msgid ""
-"       --bind-address=ADDRESS    bind to ADDRESS (hostname or IP) on local "
-"host.\n"
-msgstr ""
-
-#: src/main.c:469
-msgid "       --limit-rate=RATE         limit download rate to RATE.\n"
-msgstr ""
-
-#: src/main.c:471
-msgid "       --no-dns-cache            disable caching DNS lookups.\n"
-msgstr ""
-
-#: src/main.c:473
-msgid ""
-"       --restrict-file-names=OS  restrict chars in file names to ones OS "
-"allows.\n"
-msgstr ""
-
-#: src/main.c:476
-msgid "  -4,  --inet4-only              connect only to IPv4 addresses.\n"
-msgstr ""
-
-#: src/main.c:478
-msgid "  -6,  --inet6-only              connect only to IPv6 addresses.\n"
-msgstr ""
-
-#: src/main.c:480
-msgid ""
-"       --prefer-family=FAMILY    connect first to addresses of specified "
-"family,\n"
-"                                 one of IPv6, IPv4, or none.\n"
-msgstr ""
-
-#: src/main.c:484
-msgid "       --user=USER               set both ftp and http user to USER.\n"
-msgstr ""
-
-#: src/main.c:486
-msgid ""
-"       --password=PASS           set both ftp and http password to PASS.\n"
-msgstr ""
-
-#: src/main.c:490
-#, fuzzy
-msgid "Directories:\n"
-msgstr "Katalog     "
-
-#: src/main.c:492
-msgid "  -nd, --no-directories           don't create directories.\n"
-msgstr ""
-
-#: src/main.c:494
-msgid "  -x,  --force-directories        force creation of directories.\n"
-msgstr ""
-
-#: src/main.c:496
-msgid "  -nH, --no-host-directories      don't create host directories.\n"
-msgstr ""
-
-#: src/main.c:498
-msgid "       --protocol-directories     use protocol name in directories.\n"
-msgstr ""
-
-#: src/main.c:500
-msgid "  -P,  --directory-prefix=PREFIX  save files to PREFIX/...\n"
-msgstr ""
-
-#: src/main.c:502
-msgid ""
-"       --cut-dirs=NUMBER          ignore NUMBER remote directory "
-"components.\n"
-msgstr ""
-
-#: src/main.c:506
-msgid "HTTP options:\n"
-msgstr ""
-
-#: src/main.c:508
-msgid "       --http-user=USER        set http user to USER.\n"
-msgstr ""
-
-#: src/main.c:510
-msgid "       --http-password=PASS    set http password to PASS.\n"
-msgstr ""
-
-#: src/main.c:512
-msgid "       --no-cache              disallow server-cached data.\n"
-msgstr ""
-
-#: src/main.c:514
-msgid ""
-"  -E,  --html-extension        save HTML documents with `.html' extension.\n"
-msgstr ""
-
-#: src/main.c:516
-msgid "       --ignore-length         ignore `Content-Length' header field.\n"
-msgstr ""
-
-#: src/main.c:518
-msgid "       --header=STRING         insert STRING among the headers.\n"
-msgstr ""
-
-#: src/main.c:520
-msgid "       --proxy-user=USER       set USER as proxy username.\n"
-msgstr ""
-
-#: src/main.c:522
-msgid "       --proxy-password=PASS   set PASS as proxy password.\n"
-msgstr ""
-
-#: src/main.c:524
-msgid ""
-"       --referer=URL           include `Referer: URL' header in HTTP "
-"request.\n"
-msgstr ""
-
-#: src/main.c:526
-msgid "       --save-headers          save the HTTP headers to file.\n"
-msgstr ""
-
-#: src/main.c:528
-msgid ""
-"  -U,  --user-agent=AGENT      identify as AGENT instead of Wget/VERSION.\n"
-msgstr ""
-
-#: src/main.c:530
-msgid ""
-"       --no-http-keep-alive    disable HTTP keep-alive (persistent "
-"connections).\n"
-msgstr ""
-
-#: src/main.c:532
-msgid "       --no-cookies            don't use cookies.\n"
-msgstr ""
-
-#: src/main.c:534
-msgid "       --load-cookies=FILE     load cookies from FILE before session.\n"
-msgstr ""
-
-#: src/main.c:536
-msgid "       --save-cookies=FILE     save cookies to FILE after session.\n"
-msgstr ""
-
-#: src/main.c:538
-msgid ""
-"       --keep-session-cookies  load and save session (non-permanent) "
-"cookies.\n"
-msgstr ""
-
-#: src/main.c:540
-msgid ""
-"       --post-data=STRING      use the POST method; send STRING as the "
-"data.\n"
-msgstr ""
-
-#: src/main.c:542
-msgid ""
-"       --post-file=FILE        use the POST method; send contents of FILE.\n"
-msgstr ""
-
-#: src/main.c:547
-msgid "HTTPS (SSL/TLS) options:\n"
-msgstr ""
-
-#: src/main.c:549
-msgid ""
-"       --secure-protocol=PR     choose secure protocol, one of auto, SSLv2,\n"
-"                                SSLv3, and TLSv1.\n"
-msgstr ""
-
-#: src/main.c:552
-msgid ""
-"       --no-check-certificate   don't validate the server's certificate.\n"
-msgstr ""
-
-#: src/main.c:554
-msgid "       --certificate=FILE       client certificate file.\n"
-msgstr ""
-
-#: src/main.c:556
-msgid "       --certificate-type=TYPE  client certificate type, PEM or DER.\n"
-msgstr ""
-
-#: src/main.c:558
-msgid "       --private-key=FILE       private key file.\n"
-msgstr ""
-
-#: src/main.c:560
-msgid "       --private-key-type=TYPE  private key type, PEM or DER.\n"
-msgstr ""
-
-#: src/main.c:562
-msgid "       --ca-certificate=FILE    file with the bundle of CA's.\n"
-msgstr ""
-
-#: src/main.c:564
-msgid ""
-"       --ca-directory=DIR       directory where hash list of CA's is "
-"stored.\n"
-msgstr ""
-
-#: src/main.c:566
-msgid ""
-"       --random-file=FILE       file with random data for seeding the SSL "
-"PRNG.\n"
-msgstr ""
-
-#: src/main.c:568
-msgid ""
-"       --egd-file=FILE          file naming the EGD socket with random "
-"data.\n"
-msgstr ""
-
-#: src/main.c:573
-msgid "FTP options:\n"
-msgstr ""
-
-#: src/main.c:575
-msgid "       --ftp-user=USER         set ftp user to USER.\n"
-msgstr ""
-
-#: src/main.c:577
-msgid "       --ftp-password=PASS     set ftp password to PASS.\n"
-msgstr ""
-
-#: src/main.c:579
-msgid "       --no-remove-listing     don't remove `.listing' files.\n"
-msgstr ""
-
-#: src/main.c:581
-msgid "       --no-glob               turn off FTP file name globbing.\n"
-msgstr ""
-
-#: src/main.c:583
-msgid "       --no-passive-ftp        disable the \"passive\" transfer mode.\n"
-msgstr ""
-
-#: src/main.c:585
-msgid ""
-"       --retr-symlinks         when recursing, get linked-to files (not "
-"dir).\n"
-msgstr ""
-
-#: src/main.c:587
-msgid "       --preserve-permissions  preserve remote file permissions.\n"
-msgstr ""
-
-#: src/main.c:591
-msgid "Recursive download:\n"
-msgstr ""
-
-#: src/main.c:593
-msgid "  -r,  --recursive          specify recursive download.\n"
-msgstr ""
-
-#: src/main.c:595
-msgid ""
-"  -l,  --level=NUMBER       maximum recursion depth (inf or 0 for "
-"infinite).\n"
-msgstr ""
-
-#: src/main.c:597
-msgid ""
-"       --delete-after       delete files locally after downloading them.\n"
-msgstr ""
-
-#: src/main.c:599
-msgid ""
-"  -k,  --convert-links      make links in downloaded HTML point to local "
-"files.\n"
-msgstr ""
-
-#: src/main.c:601
-msgid ""
-"  -K,  --backup-converted   before converting file X, back up as X.orig.\n"
-msgstr ""
-
-#: src/main.c:603
-msgid ""
-"  -m,  --mirror             shortcut option equivalent to -r -N -l inf -nr.\n"
-msgstr ""
-
-#: src/main.c:605
-msgid ""
-"  -p,  --page-requisites    get all images, etc. needed to display HTML "
-"page.\n"
-msgstr ""
-
-#: src/main.c:607
-msgid ""
-"       --strict-comments    turn on strict (SGML) handling of HTML "
-"comments.\n"
-msgstr ""
-
-#: src/main.c:611
-msgid "Recursive accept/reject:\n"
-msgstr ""
-
-#: src/main.c:613
-msgid ""
-"  -A,  --accept=LIST               comma-separated list of accepted "
-"extensions.\n"
-msgstr ""
-
-#: src/main.c:615
-msgid ""
-"  -R,  --reject=LIST               comma-separated list of rejected "
-"extensions.\n"
-msgstr ""
-
-#: src/main.c:617
-msgid ""
-"  -D,  --domains=LIST              comma-separated list of accepted "
-"domains.\n"
-msgstr ""
-
-#: src/main.c:619
-msgid ""
-"       --exclude-domains=LIST      comma-separated list of rejected "
-"domains.\n"
-msgstr ""
-
-#: src/main.c:621
-msgid ""
-"       --follow-ftp                follow FTP links from HTML documents.\n"
-msgstr ""
-
-#: src/main.c:623
-msgid ""
-"       --follow-tags=LIST          comma-separated list of followed HTML "
-"tags.\n"
-msgstr ""
-
-#: src/main.c:625
-msgid ""
-"       --ignore-tags=LIST          comma-separated list of ignored HTML "
-"tags.\n"
-msgstr ""
-
-#: src/main.c:627
-msgid ""
-"  -H,  --span-hosts                go to foreign hosts when recursive.\n"
-msgstr ""
-
-#: src/main.c:629
-msgid "  -L,  --relative                  follow relative links only.\n"
-msgstr ""
-
-#: src/main.c:631
-msgid "  -I,  --include-directories=LIST  list of allowed directories.\n"
-msgstr ""
-
-#: src/main.c:633
-msgid "  -X,  --exclude-directories=LIST  list of excluded directories.\n"
-msgstr ""
-
-#: src/main.c:635
-msgid ""
-"  -np, --no-parent                 don't ascend to the parent directory.\n"
-msgstr ""
-
-#: src/main.c:639
-msgid "Mail bug reports and suggestions to <bug-wget@gnu.org>.\n"
-msgstr "Rapportér fejl og send forslag til <bug-wget@gnu.org>.\n"
-
-#: src/main.c:644
-#, c-format
-msgid "GNU Wget %s, a non-interactive network retriever.\n"
-msgstr "GNU Wget %s, en ikke-interaktiv informationsagent.\n"
-
-#: src/main.c:658
-#, fuzzy
-msgid "Copyright (C) 2005 Free Software Foundation, Inc.\n"
-msgstr ""
-"Ophavsret © 1995, 1996, 1997, 1998, 2000, 2001 Free Software Foundation, "
-"Inc.\n"
-
-#: src/main.c:660
-msgid ""
-"This program is distributed in the hope that it will be useful,\n"
-"but WITHOUT ANY WARRANTY; without even the implied warranty of\n"
-"MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the\n"
-"GNU General Public License for more details.\n"
-msgstr ""
-"Dette program distribueres i håb om at det bliver fundet nyttigt,\n"
-"men UDEN NOGEN GARANTIER; ikke engang for SALGBARHED eller\n"
-"EGNETHED TIL NOGEN SPECIEL OPGAVE.\n"
-"Se 'GNU General Public License' for detaljer.\n"
-
-#: src/main.c:665
-#, fuzzy
-msgid ""
-"\n"
-"Originally written by Hrvoje Niksic <hniksic@xemacs.org>.\n"
-msgstr ""
-"\n"
-"Oprindeligt skrevet af Hrvoje Niksic <hniksic@arsdigita.com>.\n"
+#: src/main.c:631
+#, c-format
+msgid "%s: illegal option -- `-n%c'\n"
+msgstr "%s: ugyldigt flag -- '-n%c'\n"
 
 #. #### Something nicer should be printed here -- similar to the
 #. pre-1.5 `--help' page.
-#: src/main.c:711 src/main.c:780 src/main.c:859
+#: src/main.c:634 src/main.c:676 src/main.c:722
 #, c-format
 msgid "Try `%s --help' for more options.\n"
 msgstr "Prøv '%s --help' for flere flag.\n"
 
-#: src/main.c:777
-#, c-format
-msgid "%s: illegal option -- `-n%c'\n"
-msgstr "%s: ugyldigt flag -- '-n%c'\n"
-
-#: src/main.c:830
-#, c-format
+#: src/main.c:702
 msgid "Can't be verbose and quiet at the same time.\n"
 msgstr "Kan ikke være udførlig og stille på samme tid.\n"
 
-#: src/main.c:836
-#, c-format
+#: src/main.c:708
 msgid "Can't timestamp and not clobber old files at the same time.\n"
-msgstr ""
-"Kan ikke tidsstemple og lade være at berøre eksisterende filer på samme "
-"tid.\n"
-
-#: src/main.c:844
-#, c-format
-msgid "Cannot specify both --inet4-only and --inet6-only.\n"
-msgstr ""
+msgstr "Kan ikke tidsstemple og lade være at berøre eksisterende filer på samme tid.\n"
 
 #. No URL specified.
-#: src/main.c:854
+#: src/main.c:717
 #, c-format
 msgid "%s: missing URL\n"
 msgstr "%s: URL mangler.\n"
 
-#: src/main.c:963
+#: src/main.c:834
 #, c-format
 msgid "No URLs found in %s.\n"
 msgstr "Fandt ingen URLer i %s.\n"
 
-#: src/main.c:972
+#: src/main.c:843
 #, c-format
 msgid ""
 "\n"
