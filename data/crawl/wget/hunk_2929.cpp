 #. No luck.
 #. #### This message SUCKS.  We should see what was the
 #. reason that nothing was retrieved.
-#: src/ftp.c:1608
+#: src/ftp.c:1819
 #, c-format
 msgid "No matches on pattern `%s'.\n"
 msgstr "Ingenting passer med m�nstret '%s'.\n"
 
-#: src/ftp.c:1673
-#, c-format
-msgid "Wrote HTML-ized index to `%s' [%ld].\n"
+#: src/ftp.c:1885
+#, fuzzy, c-format
+msgid "Wrote HTML-ized index to `%s' [%s].\n"
 msgstr "Skrev HTML-formateret indeks til '%s' [%ld].\n"
 
-#: src/ftp.c:1678
+#: src/ftp.c:1890
 #, c-format
 msgid "Wrote HTML-ized index to `%s'.\n"
 msgstr "Skrev HTML-formateret indeks til '%s'.\n"
 
+#. Still not enough randomness, most likely because neither
+#. /dev/random nor EGD were available.  Resort to a simple and
+#. stupid method -- seed OpenSSL's PRNG with libc PRNG.  This is
+#. cryptographically weak, but people who care about strong
+#. cryptography should install /dev/random (default on Linux) or
+#. specify their own source of randomness anyway.
 #: src/gen_sslfunc.c:109
+msgid "Warning: using a weak random seed.\n"
+msgstr ""
+
+#: src/gen_sslfunc.c:166
 msgid "Could not seed OpenSSL PRNG; disabling SSL.\n"
 msgstr "Kunne ikke p�begynde OpenSSL PRNG; deaktiverer SSL.\n"
 
-#: src/getopt.c:454
+#: src/gen_sslfunc.c:223
+msgid "Warning: validation of server certificate not possible!\n"
+msgstr ""
+
+#: src/getopt.c:675
 #, c-format
 msgid "%s: option `%s' is ambiguous\n"
 msgstr "%s: flaget '%s' er flertydig\n"
 
-#: src/getopt.c:478
+#: src/getopt.c:700
 #, c-format
 msgid "%s: option `--%s' doesn't allow an argument\n"
 msgstr "%s: flaget '--%s' tillader ikke argumenter\n"
 
-#: src/getopt.c:483
+#: src/getopt.c:705
 #, c-format
 msgid "%s: option `%c%s' doesn't allow an argument\n"
 msgstr "%s: flaget '%c%s' tillader ikke argumenter\n"
 
-#: src/getopt.c:498
+#: src/getopt.c:723 src/getopt.c:896
 #, c-format
 msgid "%s: option `%s' requires an argument\n"
 msgstr "%s: flaget '%s' kr�ver et argument\n"
 
 #. --option
-#: src/getopt.c:528
+#: src/getopt.c:752
 #, c-format
 msgid "%s: unrecognized option `--%s'\n"
 msgstr "%s: ukendt flag '--%s'\n"
 
 #. +option or -option
-#: src/getopt.c:532
+#: src/getopt.c:756
 #, c-format
 msgid "%s: unrecognized option `%c%s'\n"
 msgstr "%s: ukendt flag '%c%s'\n"
 
 #. 1003.2 specifies the format of this message.
-#: src/getopt.c:563
+#: src/getopt.c:782
 #, c-format
 msgid "%s: illegal option -- %c\n"
 msgstr "%s: ugyldigt flag -- %c\n"
 
+#: src/getopt.c:785
+#, fuzzy, c-format
+msgid "%s: invalid option -- %c\n"
+msgstr "%s: ugyldigt flag -- %c\n"
+
 #. 1003.2 specifies the format of this message.
-#: src/getopt.c:602
+#: src/getopt.c:815 src/getopt.c:945
 #, c-format
 msgid "%s: option requires an argument -- %c\n"
 msgstr "%s: flaget kr�ver et argument -- %c\n"
 
-#: src/host.c:271
+#: src/getopt.c:862
+#, fuzzy, c-format
+msgid "%s: option `-W %s' is ambiguous\n"
+msgstr "%s: flaget '%s' er flertydig\n"
+
+#: src/getopt.c:880
+#, fuzzy, c-format
+msgid "%s: option `-W %s' doesn't allow an argument\n"
+msgstr "%s: flaget '--%s' tillader ikke argumenter\n"
+
+#: src/host.c:368
+#, fuzzy
+msgid "Unknown host"
+msgstr "Ukendt fejl"
+
+#. Message modeled after what gai_strerror returns in similar
+#. circumstances.
+#: src/host.c:372
+msgid "Temporary failure in name resolution"
+msgstr ""
+
+#: src/host.c:374
+msgid "Unknown error"
+msgstr "Ukendt fejl"
+
+#: src/host.c:748
 #, c-format
 msgid "Resolving %s... "
 msgstr "L�ser %s..."
 
-#: src/host.c:278
+#: src/host.c:792 src/host.c:839
 #, c-format
 msgid "failed: %s.\n"
 msgstr "mislykkedes: %s.\n"
 
-#: src/host.c:348
-msgid "Host not found"
-msgstr "V�rt ikke fundet"
+#: src/host.c:801
+msgid "failed: No IPv4/IPv6 addresses for host.\n"
+msgstr ""
 
-#: src/host.c:350
-msgid "Unknown error"
-msgstr "Ukendt fejl"
+#: src/host.c:842
+#, fuzzy
+msgid "failed: timed out.\n"
+msgstr "mislykkedes: %s.\n"
 
-#: src/html-url.c:336
+#: src/html-url.c:297
 #, c-format
 msgid "%s: Cannot resolve incomplete link %s.\n"
 msgstr "%s: kan ikke l�se ukomplet l�nke %s.\n"
 
+#: src/http.c:349 src/http.c:1504
+#, c-format
+msgid "Failed writing HTTP request: %s.\n"
+msgstr "Fejl ved skrivning af HTTP-foresp�rgsel: %s.\n"
+
+#: src/http.c:663
+msgid "No headers, assuming HTTP/0.9"
+msgstr ""
+
 #. this is fatal
-#: src/http.c:573
+#: src/http.c:1151
 msgid "Failed to set up an SSL context\n"
 msgstr "Kunne ikke ops�tte et SSL-milj�\n"
 
-#: src/http.c:579
+#: src/http.c:1156
 #, c-format
 msgid "Failed to load certificates from %s\n"
 msgstr "Kunne ikke indl�se certifikater fra %s\n"
 
-#: src/http.c:583 src/http.c:591
+#: src/http.c:1159 src/http.c:1166
 msgid "Trying without the specified certificate\n"
 msgstr "Pr�ver uden det angivne certifikat\n"
 
-#: src/http.c:587
+#: src/http.c:1163
 #, c-format
 msgid "Failed to get certificate key from %s\n"
 msgstr "Kunne ikke f� certifikatn�gle fra %s\n"
 
-#: src/http.c:657 src/http.c:1620
-msgid "Unable to establish SSL connection.\n"
-msgstr "Kunne ikke etablere SSL-forbindelse.\n"
-
-#: src/http.c:666
-#, c-format
-msgid "Reusing connection to %s:%hu.\n"
+#: src/http.c:1382
+#, fuzzy, c-format
+msgid "Reusing existing connection to %s:%d.\n"
 msgstr "Genbruger forbindelse til %s:%hu.\n"
 
-#: src/http.c:868
-#, c-format
-msgid "Failed writing HTTP request: %s.\n"
+#: src/http.c:1434
+#, fuzzy, c-format
+msgid "Failed writing to proxy: %s.\n"
+msgstr "Fejl ved skrivning af HTTP-foresp�rgsel: %s.\n"
+
+#: src/http.c:1443
+#, fuzzy, c-format
+msgid "Failed reading proxy response: %s\n"
 msgstr "Fejl ved skrivning af HTTP-foresp�rgsel: %s.\n"
 
-#: src/http.c:873
+#: src/http.c:1463
+#, c-format
+msgid "Proxy tunneling failed: %s"
+msgstr ""
+
+#: src/http.c:1510
 #, c-format
 msgid "%s request sent, awaiting response... "
 msgstr "%s foresp�rgsel sendt, afventer svar... "
 
-#: src/http.c:917
-msgid "End of file while parsing headers.\n"
-msgstr "Filafslutning fundet ved l�sning af toptekster.\n"
+#: src/http.c:1521
+#, fuzzy
+msgid "No data received.\n"
+msgstr "Ingen data modtaget"
 
-#: src/http.c:927
+#: src/http.c:1528
 #, c-format
 msgid "Read error (%s) in headers.\n"
 msgstr "L�sefejl (%s) i toptekster.\n"
 
-#: src/http.c:962
-msgid "No data received"
-msgstr "Ingen data modtaget"
+#. If we have tried it already, then there is not point
+#. retrying it.
+#: src/http.c:1595
+msgid "Authorization failed.\n"
+msgstr "Autorisation mislykkedes\n"
+
+#: src/http.c:1609
+msgid "Unknown authentication scheme.\n"
+msgstr "Ukendt autorisations-protokol.\n"
 
-#: src/http.c:964
+#: src/http.c:1634
 msgid "Malformed status line"
 msgstr "Forkert udformet statuslinje"
 
-#: src/http.c:969
+#: src/http.c:1636
 msgid "(no description)"
 msgstr "(ingen beskrivelse)"
 
-#: src/http.c:1101
-msgid "Authorization failed.\n"
-msgstr "Autorisation mislykkedes\n"
-
-#: src/http.c:1108
-msgid "Unknown authentication scheme.\n"
-msgstr "Ukendt autorisations-protokol.\n"
-
-#: src/http.c:1148
+#: src/http.c:1700
 #, c-format
 msgid "Location: %s%s\n"
 msgstr "Sted: %s%s\n"
 
-#: src/http.c:1149 src/http.c:1282
+#: src/http.c:1701 src/http.c:1801
 msgid "unspecified"
 msgstr "uspecificeret"
 
-#: src/http.c:1150
+#: src/http.c:1702
 msgid " [following]"
 msgstr " [omdirigeret]"
 
-#: src/http.c:1213
-msgid "\n    The file is already fully retrieved; nothing to do.\n\n"
-msgstr "\n    Filen er allerede fuldt overf�rt; ingen handling n�dvendig.\n\n"
-
-#: src/http.c:1229
-#, c-format
+#. If `-c' is in use and the file has been fully downloaded (or
+#. the remote file has shrunk), Wget effectively requests bytes
+#. after the end of file and the server response with 416.
+#: src/http.c:1751
 msgid ""
 "\n"
-"Continued download failed on this file, which conflicts with `-c'.\n"
-"Refusing to truncate existing file `%s'.\n"
+"    The file is already fully retrieved; nothing to do.\n"
 "\n"
 msgstr ""
 "\n"
-"Fortsat hentning mislykkedes for denne fil, hvilket er i mods�tning til '-c'.\n"
-"N�gter at afkorte eksisterende fil '%s'.\n"
+"    Filen er allerede fuldt overf�rt; ingen handling n�dvendig.\n"
 "\n"
 
 #. No need to print this output if the body won't be
 #. downloaded at all, or if the original server response is
 #. printed.
-#: src/http.c:1272
+#: src/http.c:1781
 msgid "Length: "
 msgstr "L�ngde: "
 
-#: src/http.c:1277
-#, c-format
-msgid " (%s to go)"
-msgstr " (%s tilbage)"
-
-#: src/http.c:1282
+#: src/http.c:1801
 msgid "ignored"
 msgstr "ignoreret"
 
-#: src/http.c:1413
+#: src/http.c:1943
 msgid "Warning: wildcards not supported in HTTP.\n"
 msgstr "Advarsel: jokertegn ikke underst�ttet i HTTP.\n"
 
 #. If opt.noclobber is turned on and file already exists, do not
 #. retrieve the file
-#: src/http.c:1443
+#: src/http.c:1978
 #, c-format
 msgid "File `%s' already there, will not retrieve.\n"
 msgstr "Filen '%s' hentes ikke, fordi den allerede eksisterer.\n"
 
-#: src/http.c:1611
+#: src/http.c:2165
 #, c-format
 msgid "Cannot write to `%s' (%s).\n"
 msgstr "Kan ikke skrive til '%s' (%s).\n"
 
-#: src/http.c:1630
+#: src/http.c:2174
+msgid "Unable to establish SSL connection.\n"
+msgstr "Kunne ikke etablere SSL-forbindelse.\n"
+
+#: src/http.c:2184
 #, c-format
 msgid "ERROR: Redirection (%d) without location.\n"
 msgstr "FEJL: Omdirigering (%d) uden nyt sted.\n"
 
-#: src/http.c:1662
+#: src/http.c:2216
 #, c-format
 msgid "%s ERROR %d: %s.\n"
 msgstr "%s FEJL %d: %s.\n"
 
-#: src/http.c:1675
+#: src/http.c:2229
 msgid "Last-modified header missing -- time-stamps turned off.\n"
 msgstr "Last-modified toptekst mangler -- tidsstempling sl�s fra.\n"
 
-#: src/http.c:1683
+#: src/http.c:2237
 msgid "Last-modified header invalid -- time-stamp ignored.\n"
 msgstr "Last-modified toptekst ugyldig -- tidsstempel ignoreret.\n"
 
-#: src/http.c:1706
+#: src/http.c:2260
 #, c-format
-msgid "Server file no newer than local file `%s' -- not retrieving.\n\n"
-msgstr "Serverfil ikke nyere end lokal fil '%s' - hentes ikke.\n\n"
+msgid ""
+"Server file no newer than local file `%s' -- not retrieving.\n"
+"\n"
+msgstr ""
+"Serverfil ikke nyere end lokal fil '%s' - hentes ikke.\n"
+"\n"
 
-#: src/http.c:1714
-#, c-format
-msgid "The sizes do not match (local %ld) -- retrieving.\n"
+#: src/http.c:2268
+#, fuzzy, c-format
+msgid "The sizes do not match (local %s) -- retrieving.\n"
 msgstr "St�rrelserne er forskellige (lokal %ld) - hentes.\n"
 
-#: src/http.c:1718
+#: src/http.c:2273
 msgid "Remote file is newer, retrieving.\n"
 msgstr "Fil p� server er nyere - hentes.\n"
 
-#: src/http.c:1759
-#, c-format
-msgid "%s (%s) - `%s' saved [%ld/%ld]\n\n"
-msgstr "%s (%s) - '%s' gemt [%ld/%ld]\n\n"
+#: src/http.c:2315
+#, fuzzy, c-format
+msgid ""
+"%s (%s) - `%s' saved [%s/%s]\n"
+"\n"
+msgstr ""
+"%s (%s) - '%s' gemt [%ld/%ld]\n"
+"\n"
 
-#: src/http.c:1809
-#, c-format
-msgid "%s (%s) - Connection closed at byte %ld. "
+#: src/http.c:2372
+#, fuzzy, c-format
+msgid "%s (%s) - Connection closed at byte %s. "
 msgstr "%s (%s) - Forbindelse lukket ved byte %ld. "
 
-#: src/http.c:1818
-#, c-format
-msgid "%s (%s) - `%s' saved [%ld/%ld])\n\n"
-msgstr "%s (%s) - '%s' gemt [%ld/%ld]\n\n"
+#: src/http.c:2381
+#, fuzzy, c-format
+msgid ""
+"%s (%s) - `%s' saved [%s/%s])\n"
+"\n"
+msgstr ""
+"%s (%s) - '%s' gemt [%ld/%ld]\n"
+"\n"
 
-#: src/http.c:1839
-#, c-format
-msgid "%s (%s) - Connection closed at byte %ld/%ld. "
+#: src/http.c:2407
+#, fuzzy, c-format
+msgid "%s (%s) - Connection closed at byte %s/%s. "
 msgstr "%s (%s) - Forbindelse lukket ved byte %ld/%ld. "
 
-#: src/http.c:1851
-#, c-format
-msgid "%s (%s) - Read error at byte %ld (%s)."
+#: src/http.c:2421
+#, fuzzy, c-format
+msgid "%s (%s) - Read error at byte %s (%s)."
 msgstr "%s (%s) - L�sefejl ved byte %ld (%s)."
 
-#: src/http.c:1860
-#, c-format
-msgid "%s (%s) - Read error at byte %ld/%ld (%s). "
+#: src/http.c:2431
+#, fuzzy, c-format
+msgid "%s (%s) - Read error at byte %s/%s (%s). "
 msgstr "%s (%s) - L�sefejl ved byte %ld/%ld (%s)."
 
-#: src/init.c:355 src/netrc.c:265
+#: src/init.c:342
+#, c-format
+msgid "%s: WGETRC points to %s, which doesn't exist.\n"
+msgstr ""
+
+#: src/init.c:395 src/netrc.c:277
 #, c-format
 msgid "%s: Cannot read %s (%s).\n"
 msgstr "%s: Kan ikke l�se %s (%s).\n"
 
-#: src/init.c:373 src/init.c:379
+#: src/init.c:413 src/init.c:419
 #, c-format
 msgid "%s: Error in %s at line %d.\n"
 msgstr "%s: Fejl i %s p� linje %d.\n"
 
-#: src/init.c:411
+#: src/init.c:451
 #, c-format
 msgid "%s: Warning: Both system and user wgetrc point to `%s'.\n"
 msgstr "%s: Advarsel: B�de systemets og brugerens wgetrc peger p� '%s'.\n"
 
-#: src/init.c:503
-#, c-format
-msgid "%s: BUG: unknown command `%s', value `%s'.\n"
-msgstr "%s: FEJL: Ukendt kommando '%s', v�rdi '%s'.\n"
-
-#: src/init.c:537
-#, c-format
-msgid "%s: %s: Cannot convert `%s' to an IP address.\n"
-msgstr "%s: %s: Kan ikke omforme '%s' til en IP-adresse.\n"
+#: src/init.c:595
+#, fuzzy, c-format
+msgid "%s: Invalid --execute command `%s'\n"
+msgstr "%s: Ugyldig specifikation '%s'\n"
 
-#: src/init.c:570
-#, c-format
-msgid "%s: %s: Please specify on or off.\n"
+#: src/init.c:631
+#, fuzzy, c-format
+msgid "%s: %s: Invalid boolean `%s', use `on' or `off'.\n"
 msgstr "%s: %s: Venligst angiv 'on' eller 'off'.\n"
 
-#: src/init.c:614
-#, c-format
-msgid "%s: %s: Please specify always, on, off, or never.\n"
+#: src/init.c:674
+#, fuzzy, c-format
+msgid "%s: %s: Invalid boolean `%s', use always, on, off, or never.\n"
 msgstr "%s: %s: Venligst angiv 'always', 'on' 'off', eller 'never'.\n"
 
-#: src/init.c:633 src/init.c:900 src/init.c:981
-#, c-format
-msgid "%s: %s: Invalid specification `%s'.\n"
+#: src/init.c:693
+#, fuzzy, c-format
+msgid "%s: %s: Invalid number `%s'.\n"
 msgstr "%s: %s: Ugyldig specifikation '%s'\n"
 
-#: src/init.c:789 src/init.c:811 src/init.c:833 src/init.c:859
-#, c-format
-msgid "%s: Invalid specification `%s'\n"
-msgstr "%s: Ugyldig specifikation '%s'\n"
+#: src/init.c:926 src/init.c:945
+#, fuzzy, c-format
+msgid "%s: %s: Invalid byte value `%s'\n"
+msgstr "%s: %s: Ugyldig fremskridtstype '%s'\n"
 
-#: src/init.c:949
+#: src/init.c:970
+#, fuzzy, c-format
+msgid "%s: %s: Invalid time period `%s'\n"
+msgstr "%s: %s: Ugyldig specifikation '%s'\n"
+
+#: src/init.c:1037
+#, fuzzy, c-format
+msgid "%s: %s: Invalid header `%s'.\n"
+msgstr "%s: %s: Ugyldig specifikation '%s'\n"
+
+#: src/init.c:1083
 #, c-format
 msgid "%s: %s: Invalid progress type `%s'.\n"
 msgstr "%s: %s: Ugyldig fremskridtstype '%s'\n"
 
-#: src/log.c:641
+#: src/init.c:1134
+#, fuzzy, c-format
+msgid "%s: %s: Invalid restriction `%s', use `unix' or `windows'.\n"
+msgstr "%s: %s: Ugyldig specifikation '%s'\n"
+
+#: src/init.c:1175
+#, fuzzy, c-format
+msgid "%s: %s: Invalid value `%s'.\n"
+msgstr "%s: %s: Ugyldig specifikation '%s'\n"
+
+#: src/log.c:777
 #, c-format
-msgid "\n%s received, redirecting output to `%s'.\n"
-msgstr "\n%s modtaget, omdirigerer udskrifter til '%s'.\n"
+msgid ""
+"\n"
+"%s received, redirecting output to `%s'.\n"
+msgstr ""
+"\n"
+"%s modtaget, omdirigerer udskrifter til '%s'.\n"
 
 #. Eek!  Opening the alternate log file has failed.  Nothing we
 #. can do but disable printing completely.
-#: src/log.c:648
+#: src/log.c:787
+#, fuzzy, c-format
+msgid ""
+"\n"
+"%s received.\n"
+msgstr "Ingen data modtaget"
+
+#: src/log.c:788
 #, c-format
 msgid "%s: %s; disabling logging.\n"
 msgstr "%s: %s; deaktiverer logning.\n"
 
-#: src/main.c:116
+#: src/main.c:363
 #, c-format
 msgid "Usage: %s [OPTION]... [URL]...\n"
 msgstr "Brug: %s [FLAG]... [URL]...\n"
 
-#: src/main.c:124
-#, c-format
-msgid "GNU Wget %s, a non-interactive network retriever.\n"
-msgstr "GNU Wget %s, en ikke-interaktiv informationsagent.\n"
-
-#. Had to split this in parts, so the #@@#%# Ultrix compiler and cpp
-#. don't bitch.  Also, it makes translation much easier.
-#: src/main.c:129
-msgid "\nMandatory arguments to long options are mandatory for short options too.\n\n"
+#: src/main.c:375
+#, fuzzy
+msgid ""
+"Mandatory arguments to long options are mandatory for short options too.\n"
+"\n"
 msgstr ""
 "\n"
 "Obligatoriske argumenter til lange flag er obligatoriske ogs� \n"
 "for korte.\n"
 "\n"
 
-#: src/main.c:133
-msgid ""
-"Startup:\n"
-"  -V,  --version           display the version of Wget and exit.\n"
-"  -h,  --help              print this help.\n"
-"  -b,  --background        go to background after startup.\n"
-"  -e,  --execute=COMMAND   execute a `.wgetrc'-style command.\n"
-"\n"
+#: src/main.c:377
+msgid "Startup:\n"
 msgstr ""
-"Opstart:\n"
-"  -V,  --version           vis Wget's versionsnummer og afslut.\n"
-"  -h,  --help              udskriv denne hj�lpetekst.\n"
-"  -b,  --background        k�r i baggrunden efter opstart.\n"
-"  -e,  --execute=KOMMANDO  udf�r en '.wgetrc'-kommando.\n"
-"\n"
 
-#: src/main.c:140
-msgid ""
-"Logging and input file:\n"
-"  -o,  --output-file=FILE     log messages to FILE.\n"
-"  -a,  --append-output=FILE   append messages to FILE.\n"
-"  -d,  --debug                print debug output.\n"
-"  -q,  --quiet                quiet (no output).\n"
-"  -v,  --verbose              be verbose (this is the default).\n"
-"  -nv, --non-verbose          turn off verboseness, without being quiet.\n"
-"  -i,  --input-file=FILE      download URLs found in FILE.\n"
-"  -F,  --force-html           treat input file as HTML.\n"
-"  -B,  --base=URL             prepends URL to relative links in -F -i file.\n"
-"       --sslcertfile=FILE     optional client certificate.\n"
-"       --sslcertkey=KEYFILE   optional keyfile for this certificate.\n"
-"       --egd-file=FILE        file name of the EGD socket.\n"
-"\n"
+#: src/main.c:379
+msgid "  -V,  --version           display the version of Wget and exit.\n"
 msgstr ""
-"Logning og indl�sning:\n"
-"  -o,  --output-file=FIL      log beskeder til FIL.\n"
-"  -a,  --append-output=FIL    tilf�j beskeder til slutningen af FIL.\n"
-"  -d,  --debug                skriv fejls�gningsinformation.\n"
-"  -q,  --quiet                stille (ingen udskrifter).\n"
-"  -v,  --verbose              v�r udf�rlig (standard).\n"
-"  -nv, --non-verbose          mindre udf�rlig, men ikke stille.\n"
-"  -i,  --input-file=FIL       hent URLer fundet i FIL.\n"
-"  -F,  --force-html           behandl inddatafil som HTML.\n"
-"  -B,  --base=URL             foranstiller URL til relative l�nker i -F -i fil.\n"
-"       --sslcertfile=FIL      valgbart klient-certifikat.\n"
-"       --sslcertkey=N�GLEFIL  valgbar n�glefil for dette certifikat.\n"
-"       --egd-file=FIL         filnavn for EGD-soklen.\n"
-"\n"
 
-#: src/main.c:155
-msgid ""
-"Download:\n"
-"       --bind-address=ADDRESS   bind to ADDRESS (hostname or IP) on local host.\n"
-"  -t,  --tries=NUMBER           set number of retries to NUMBER (0 unlimits).\n"
-"  -O   --output-document=FILE   write documents to FILE.\n"
-"  -nc, --no-clobber             don't clobber existing files or use .# suffixes.\n"
-"  -c,  --continue               resume getting a partially-downloaded file.\n"
-"       --progress=TYPE          select progress gauge type.\n"
-"  -N,  --timestamping           don't re-retrieve files unless newer than local.\n"
-"  -S,  --server-response        print server response.\n"
-"       --spider                 don't download anything.\n"
-"  -T,  --timeout=SECONDS        set the read timeout to SECONDS.\n"
-"  -w,  --wait=SECONDS           wait SECONDS between retrievals.\n"
-"       --waitretry=SECONDS      wait 1...SECONDS between retries of a retrieval.\n"
-"       --random-wait            wait from 0...2*WAIT secs between retrievals.\n"
-"  -Y,  --proxy=on/off           turn proxy on or off.\n"
-"  -Q,  --quota=NUMBER           set retrieval quota to NUMBER.\n"
-"       --limit-rate=RATE        limit download rate to RATE.\n"
-"\n"
+#: src/main.c:381
+msgid "  -h,  --help              print this help.\n"
 msgstr ""
-"Hentning:\n"
-"       --bind-address=ADRESSE   bind til ADRESSE (v�rtsnavn eller IP) p� lokal v�rt.\n"
-"  -t,  --tries=ANTAL            maksimalt antal fors�g (0 for uendelig).\n"
-"  -O   --output-document=FIL    skriv dokumenter til FIL.\n"
-"  -nc, --no-clobber             ber�r ikke eksisterende filer, eller brug .#-endelser.\n"
-"  -c,  --continue               forts�t hentning af en eksisterende fil.\n"
-"       --progress=TYPE          v�lg type af fremskridtsvisning.\n"
-"  -N,  --timestamping           hent ikke filer igen som er �ldre end eksisterende.\n"
-"  -S,  --server-response        vis svar fra serveren.\n"
-"       --spider                 hent ikke filer.\n"
-"  -T,  --timeout=SEKUNDER       s�t ventetid ved l�sning til SEKUNDER.\n"
-"  -w,  --wait=SEKUNDER          s�t ventetid mellem filer til SEKUNDER.\n"
-"       --waitretry=SEKUNDER\twait 1...SEKUNDER mellem fors�g p� gentagelse af en hentning.\n"
-"       --random-wait            vent fra 0...2*WAIT sekunder mellem modtagelse.\n"
-"  -Y,  --proxy=on/off           sl� brug af proxy til eller fra.\n"
-"  -Q,  --quota=ANTAL            s�t hente-kvote til ANTAL.\n"
-"       --limit-rate=RATE        begr�ns hentingshastighed til RATE.\n"
-"\n"
 
-#: src/main.c:174
-msgid ""
-"Directories:\n"
-"  -nd  --no-directories            don't create directories.\n"
-"  -x,  --force-directories         force creation of directories.\n"
-"  -nH, --no-host-directories       don't create host directories.\n"
-"  -P,  --directory-prefix=PREFIX   save files to PREFIX/...\n"
-"       --cut-dirs=NUMBER           ignore NUMBER remote directory components.\n"
-"\n"
+#: src/main.c:383
+msgid "  -b,  --background        go to background after startup.\n"
 msgstr ""
-"Kataloger:\n"
-"  -nd  --no-directories             lav ikke kataloger.\n"
-"  -x,  --force-directories          lav kataloger.\n"
-"  -nH, --no-host-directories        lav ikke ovenst�ende kataloger.\n"
-"  -P,  --directory-prefix=PR�FIKS   skriv filer til PR�FIKS/...\n"
-"       --cut-dirs=ANTAL             ignor�r ANTAL komponenter af serverens\n"
-"                                    katalognavn.\n"
-"\n"
 
-#: src/main.c:182
-msgid ""
-"HTTP options:\n"
-"       --http-user=USER      set http user to USER.\n"
-"       --http-passwd=PASS    set http password to PASS.\n"
-"  -C,  --cache=on/off        (dis)allow server-cached data (normally allowed).\n"
-"  -E,  --html-extension      save all text/html documents with .html extension.\n"
-"       --ignore-length       ignore `Content-Length' header field.\n"
-"       --header=STRING       insert STRING among the headers.\n"
-"       --proxy-user=USER     set USER as proxy username.\n"
-"       --proxy-passwd=PASS   set PASS as proxy password.\n"
-"       --referer=URL         include `Referer: URL' header in HTTP request.\n"
-"  -s,  --save-headers        save the HTTP headers to file.\n"
-"  -U,  --user-agent=AGENT    identify as AGENT instead of Wget/VERSION.\n"
-"       --no-http-keep-alive  disable HTTP keep-alive (persistent connections).\n"
-"       --cookies=off         don't use cookies.\n"
-"       --load-cookies=FILE   load cookies from FILE before session.\n"
-"       --save-cookies=FILE   save cookies to FILE after session.\n"
-"\n"
+#: src/main.c:385
+msgid "  -e,  --execute=COMMAND   execute a `.wgetrc'-style command.\n"
 msgstr ""
-"HTTP-flag:\n"
-"       --http-user=BRUGER      s�t HTTP-bruger til BRUGER.\n"
-"       --http-passwd=PASSORD   s�t HTTP-adgangskode til PASSORD.\n"
-"  -C,  --cache=on/off          tillad (ikke) brug af mellemlager p� server.\n"
-"  -E,  --html-extension        gem alle tekst/html dokumenter med .html filkode.\n"
-"       --ignore-length         ignorer 'Content-Length' felt i toptekst.\n"
-"       --header=TEKST          s�t TEKST ind som en toptekst.\n"
-"       --proxy-user=BRUGER     s�t proxy-bruger til BRUGER.\n"
-"       --proxy-passwd=PASSORD  s�t proxy-adgangskode til PASSORD.\n"
-"       --referer=URL           brug `Referer: URL' kommando i HTTP-foresp�rgsel.\n"
-"  -s,  --save-headers          skriv HTTP-toptekster til fil.\n"
-"  -U,  --user-agent=AGENT      identificer som AGENT i stedet for \n"
-"                               'Wget/VERSION'.\n"
-"       --no-http-keep-alive    deaktiv�r HTTP keep-alive (overlevende forbindelser).\n"
-"       --cookies=off           brug ikke infokager.\n"
-"       --load-cookies=FILE     indl�s infokager fra FIL f�r session.\n"
-"       --save-cookies=FILE     gem infokager i FIL efter session.\n"
-"\n"
 
-#: src/main.c:200
-msgid ""
-"FTP options:\n"
-"  -nr, --dont-remove-listing   don't remove `.listing' files.\n"
-"  -g,  --glob=on/off           turn file name globbing on or off.\n"
-"       --passive-ftp           use the \"passive\" transfer mode.\n"
-"       --retr-symlinks         when recursing, get linked-to files (not dirs).\n"
-"\n"
+#: src/main.c:389
+msgid "Logging and input file:\n"
 msgstr ""
-"FTP-flag:\n"
-"  -nr, --dont-remove-listing   fjern ikke `.listing' filer.\n"
-"  -g,  --glob=on/off           tolk (ikke) brug af jokertegn i filnavn.\n"
-"       --passive-ftp           brug passiv overf�rselsmetode.\n"
-"       --retr-symlinks         hent filer (ikke kataloger) der er l�nket til, ved rekursiv brug.\n"
-"\n"
 
-#: src/main.c:207
-msgid ""
-"Recursive retrieval:\n"
-"  -r,  --recursive          recursive web-suck -- use with care!\n"
-"  -l,  --level=NUMBER       maximum recursion depth (inf or 0 for infinite).\n"
-"       --delete-after       delete files locally after downloading them.\n"
-"  -k,  --convert-links      convert non-relative links to relative.\n"
-"  -K,  --backup-converted   before converting file X, back up as X.orig.\n"
-"  -m,  --mirror             shortcut option equivalent to -r -N -l inf -nr.\n"
-"  -p,  --page-requisites    get all images, etc. needed to display HTML page.\n"
-"\n"
+#: src/main.c:391
+msgid "  -o,  --output-file=FILE    log messages to FILE.\n"
 msgstr ""
-"Rekursiv nedlasting:\n"
-"  -r,  --recursive             tillad rekursiv nedlasting -- brug med omtanke!\n"
-"  -l,  --level=ANTAL           maksimalt antal rekursionsniveauer (0=uendelig).\n"
-"       --delete-after          slet hentede filer.\n"
-"  -k,  --convert-links         konverter absolutte l�nker til relative.\n"
-"  -K,  --backup-converted      f�r fil X konverteres, sikkerhedskopi�r som X.orig.\n"
-"  -m,  --mirror                s�t passende flag for spejling af servere.\n"
-"  -p,  --page-requisites       hent alle billeder osv. der er n�dvendige for at vise HTML siden.\n"
-"\n"
 
-#: src/main.c:217
-msgid ""
-"Recursive accept/reject:\n"
-"  -A,  --accept=LIST                comma-separated list of accepted extensions.\n"
-"  -R,  --reject=LIST                comma-separated list of rejected extensions.\n"
-"  -D,  --domains=LIST               comma-separated list of accepted domains.\n"
-"       --exclude-domains=LIST       comma-separated list of rejected domains.\n"
-"       --follow-ftp                 follow FTP links from HTML documents.\n"
-"       --follow-tags=LIST           comma-separated list of followed HTML tags.\n"
-"  -G,  --ignore-tags=LIST           comma-separated list of ignored HTML tags.\n"
-"  -H,  --span-hosts                 go to foreign hosts when recursive.\n"
-"  -L,  --relative                   follow relative links only.\n"
-"  -I,  --include-directories=LIST   list of allowed directories.\n"
-"  -X,  --exclude-directories=LIST   list of excluded directories.\n"
-"  -np, --no-parent                  don't ascend to the parent directory.\n"
-"\n"
+#: src/main.c:393
+msgid "  -a,  --append-output=FILE  append messages to FILE.\n"
 msgstr ""
-"Hvad er tilladt ved rekursion:\n"
-"  -A,  --accept=LISTE               liste med tilladte filtyper.\n"
-"  -R,  --reject=LISTE               liste med ikke-tilladte filtyper.\n"
-"  -D,  --domains=LISTE              liste med tilladte dom�ner.\n"
-"       --exclude-domains=LISTE      liste med ikke-tilladte dom�ner.\n"
-"       --follow-ftp                 f�lg FTP-l�nker fra HTML-dokumenter.\n"
-"       --follow-tags=LIST           komma-separeret liste af fulgte HTML-m�rker.\n"
-"  -G,  --ignore-tags=LIST           komma-separeret liste af ignorerede HTML-m�rker.\n"
-"  -H,  --span-hosts                 f�lg l�nker til andre v�rter.\n"
-"  -L,  --relative                   f�lg kun relative l�nker.\n"
-"  -I,  --include-directories=LISTE  liste med tilladte katalognavne.\n"
-"  -X,  --exclude-directories=LISTE  liste med ikke-tilladte katalognavne.\n"
-"  -np, --no-parent                  f�lg ikke l�nke til ovenliggende katalog.\n"
-"\n"
 
-#: src/main.c:232
-msgid "Mail bug reports and suggestions to <bug-wget@gnu.org>.\n"
-msgstr "Rapport�r fejl og send forslag til <bug-wget@gnu.org>.\n"
+#: src/main.c:396
+msgid "  -d,  --debug               print lots of debugging information.\n"
+msgstr ""
 
-#: src/main.c:420
-#, c-format
-msgid "%s: debug support not compiled in.\n"
-msgstr "%s: underst�ttelse for fejls�gning ikke inkluderet ved overs�ttelse.\n"
+#: src/main.c:399
+msgid "  -q,  --quiet               quiet (no output).\n"
+msgstr ""
 
-#: src/main.c:472
-msgid "Copyright (C) 1995, 1996, 1997, 1998, 2000, 2001 Free Software Foundation, Inc.\n"
-msgstr "Ophavsret � 1995, 1996, 1997, 1998, 2000, 2001 Free Software Foundation, Inc.\n"
+#: src/main.c:401
+msgid "  -v,  --verbose             be verbose (this is the default).\n"
+msgstr ""
 
-#: src/main.c:474
+#: src/main.c:403
 msgid ""
-"This program is distributed in the hope that it will be useful,\n"
-"but WITHOUT ANY WARRANTY; without even the implied warranty of\n"
-"MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the\n"
-"GNU General Public License for more details.\n"
+"  -nv, --no-verbose          turn off verboseness, without being quiet.\n"
 msgstr ""
-"Dette program distribueres i h�b om at det bliver fundet nyttigt,\n"
-"men UDEN NOGEN GARANTIER; ikke engang for SALGBARHED eller\n"
-"EGNETHED TIL NOGEN SPECIEL OPGAVE.\n"
-"Se 'GNU General Public License' for detaljer.\n"
 
-#: src/main.c:479
-msgid "\nOriginally written by Hrvoje Niksic <hniksic@arsdigita.com>.\n"
-msgstr "\nOprindeligt skrevet af Hrvoje Niksic <hniksic@arsdigita.com>.\n"
+#: src/main.c:405
+msgid "  -i,  --input-file=FILE     download URLs found in FILE.\n"
+msgstr ""
 
-#: src/main.c:578
-#, c-format
-msgid "%s: %s: invalid command\n"
-msgstr "%s: %s: ugyldig kommando\n"
+#: src/main.c:407
+msgid "  -F,  --force-html          treat input file as HTML.\n"
+msgstr ""
 
-#: src/main.c:631
-#, c-format
-msgid "%s: illegal option -- `-n%c'\n"
-msgstr "%s: ugyldigt flag -- '-n%c'\n"
+#: src/main.c:409
+msgid ""
+"  -B,  --base=URL            prepends URL to relative links in -F -i file.\n"
+msgstr ""
+
+#: src/main.c:413
+msgid "Download:\n"
+msgstr ""
+
+#: src/main.c:415
+msgid ""
+"  -t,  --tries=NUMBER            set number of retries to NUMBER (0 "
+"unlimits).\n"
+msgstr ""
+
+#: src/main.c:417
+msgid "       --retry-connrefused       retry even if connection is refused.\n"
+msgstr ""
+
+#: src/main.c:419
+msgid "  -O,  --output-document=FILE    write documents to FILE.\n"
+msgstr ""
+
+#: src/main.c:421
+msgid ""
+"  -nc, --no-clobber              skip downloads that would download to\n"
+"                                 existing files.\n"
+msgstr ""
+
+#: src/main.c:424
+msgid ""
+"  -c,  --continue                resume getting a partially-downloaded "
+"file.\n"
+msgstr ""
+
+#: src/main.c:426
+msgid "       --progress=TYPE           select progress gauge type.\n"
+msgstr ""
+
+#: src/main.c:428
+msgid ""
+"  -N,  --timestamping            don't re-retrieve files unless newer than\n"
+"                                 local.\n"
+msgstr ""
+
+#: src/main.c:431
+msgid "  -S,  --server-response         print server response.\n"
+msgstr ""
+
+#: src/main.c:433
+msgid "       --spider                  don't download anything.\n"
+msgstr ""
+
+#: src/main.c:435
+msgid "  -T,  --timeout=SECONDS         set all timeout values to SECONDS.\n"
+msgstr ""
+
+#: src/main.c:437
+msgid "       --dns-timeout=SECS        set the DNS lookup timeout to SECS.\n"
+msgstr ""
+
+#: src/main.c:439
+msgid "       --connect-timeout=SECS    set the connect timeout to SECS.\n"
+msgstr ""
+
+#: src/main.c:441
+msgid "       --read-timeout=SECS       set the read timeout to SECS.\n"
+msgstr ""
+
+#: src/main.c:443
+msgid "  -w,  --wait=SECONDS            wait SECONDS between retrievals.\n"
+msgstr ""
+
+#: src/main.c:445
+msgid ""
+"       --waitretry=SECONDS       wait 1..SECONDS between retries of a "
+"retrieval.\n"
+msgstr ""
+
+#: src/main.c:447
+msgid ""
+"       --random-wait             wait from 0...2*WAIT secs between "
+"retrievals.\n"
+msgstr ""
+
+#: src/main.c:449
+msgid "  -Y,  --proxy                   explicitly turn on proxy.\n"
+msgstr ""
+
+#: src/main.c:451
+msgid "       --no-proxy                explicitly turn off proxy.\n"
+msgstr ""
+
+#: src/main.c:453
+msgid "  -Q,  --quota=NUMBER            set retrieval quota to NUMBER.\n"
+msgstr ""
+
+#: src/main.c:455
+msgid ""
+"       --bind-address=ADDRESS    bind to ADDRESS (hostname or IP) on local "
+"host.\n"
+msgstr ""
+
+#: src/main.c:457
+msgid "       --limit-rate=RATE         limit download rate to RATE.\n"
+msgstr ""
+
+#: src/main.c:459
+msgid "       --no-dns-cache            disable caching DNS lookups.\n"
+msgstr ""
+
+#: src/main.c:461
+msgid ""
+"       --restrict-file-names=OS  restrict chars in file names to ones OS "
+"allows.\n"
+msgstr ""
+
+#: src/main.c:464
+msgid "  -4,  --inet4-only              connect only to IPv4 addresses.\n"
+msgstr ""
+
+#: src/main.c:466
+msgid "  -6,  --inet6-only              connect only to IPv6 addresses.\n"
+msgstr ""
+
+#: src/main.c:471
+#, fuzzy
+msgid "Directories:\n"
+msgstr "Katalog     "
+
+#: src/main.c:473
+msgid "  -nd, --no-directories           don't create directories.\n"
+msgstr ""
+
+#: src/main.c:475
+msgid "  -x,  --force-directories        force creation of directories.\n"
+msgstr ""
+
+#: src/main.c:477
+msgid "  -nH, --no-host-directories      don't create host directories.\n"
+msgstr ""
+
+#: src/main.c:479
+msgid "       --protocol-directories     use protocol name in directories.\n"
+msgstr ""
+
+#: src/main.c:481
+msgid "  -P,  --directory-prefix=PREFIX  save files to PREFIX/...\n"
+msgstr ""
+
+#: src/main.c:483
+msgid ""
+"       --cut-dirs=NUMBER          ignore NUMBER remote directory "
+"components.\n"
+msgstr ""
+
+#: src/main.c:487
+msgid "HTTP options:\n"
+msgstr ""
+
+#: src/main.c:489
+msgid "       --http-user=USER        set http user to USER.\n"
+msgstr ""
+
+#: src/main.c:491
+msgid "       --http-passwd=PASS      set http password to PASS.\n"
+msgstr ""
+
+#: src/main.c:493
+msgid "       --no-cache              disallow server-cached data.\n"
+msgstr ""
+
+#: src/main.c:495
+msgid ""
+"  -E,  --html-extension        save HTML documents with `.html' extension.\n"
+msgstr ""
+
+#: src/main.c:497
+msgid "       --ignore-length         ignore `Content-Length' header field.\n"
+msgstr ""
+
+#: src/main.c:499
+msgid "       --header=STRING         insert STRING among the headers.\n"
+msgstr ""
+
+#: src/main.c:501
+msgid "       --proxy-user=USER       set USER as proxy username.\n"
+msgstr ""
+
+#: src/main.c:503
+msgid "       --proxy-passwd=PASS     set PASS as proxy password.\n"
+msgstr ""
+
+#: src/main.c:505
+msgid ""
+"       --referer=URL           include `Referer: URL' header in HTTP "
+"request.\n"
+msgstr ""
+
+#: src/main.c:507
+msgid "       --save-headers          save the HTTP headers to file.\n"
+msgstr ""
+
+#: src/main.c:509
+msgid ""
+"  -U,  --user-agent=AGENT      identify as AGENT instead of Wget/VERSION.\n"
+msgstr ""
+
+#: src/main.c:511
+msgid ""
+"       --no-http-keep-alive    disable HTTP keep-alive (persistent "
+"connections).\n"
+msgstr ""
+
+#: src/main.c:513
+msgid "       --no-cookies            don't use cookies.\n"
+msgstr ""
+
+#: src/main.c:515
+msgid "       --load-cookies=FILE     load cookies from FILE before session.\n"
+msgstr ""
+
+#: src/main.c:517
+msgid "       --save-cookies=FILE     save cookies to FILE after session.\n"
+msgstr ""
+
+#: src/main.c:519
+msgid ""
+"       --keep-session-cookies  load and save session (non-permanent) "
+"cookies.\n"
+msgstr ""
+
+#: src/main.c:521
+msgid ""
+"       --post-data=STRING      use the POST method; send STRING as the "
+"data.\n"
+msgstr ""
+
+#: src/main.c:523
+msgid ""
+"       --post-file=FILE        use the POST method; send contents of FILE.\n"
+msgstr ""
+
+#: src/main.c:528
+msgid "HTTPS (SSL) options:\n"
+msgstr ""
+
+#: src/main.c:530
+msgid "       --sslcertfile=FILE    optional client certificate.\n"
+msgstr ""
+
+#: src/main.c:532
+msgid "       --sslcertkey=KEYFILE  optional keyfile for this certificate.\n"
+msgstr ""
+
+#: src/main.c:534
+msgid "       --sslcadir=DIR        dir where hash list of CA's are stored.\n"
+msgstr ""
+
+#: src/main.c:536
+msgid "       --sslcafile=FILE      file with bundle of CA's.\n"
+msgstr ""
+
+#: src/main.c:538
+msgid ""
+"       --sslcerttype=0/1     Client-Cert type 0=PEM (default) / 1=ASN1 "
+"(DER).\n"
+msgstr ""
+
+#: src/main.c:540
+msgid "       --sslcheckcert=0/1    Check the server cert against given CA.\n"
+msgstr ""
+
+#: src/main.c:542
+msgid ""
+"       --sslprotocol=0-3     choose SSL protocol; 0=automatic,\n"
+"                             1=SSLv2 2=SSLv3 3=TLSv1.\n"
+msgstr ""
+
+#: src/main.c:545
+msgid "       --egd-file=FILE       file name of the EGD socket.\n"
+msgstr ""
+
+#: src/main.c:550
+msgid "FTP options:\n"
+msgstr ""
+
+#: src/main.c:552
+msgid "       --no-remove-listing     don't remove `.listing' files.\n"
+msgstr ""
+
+#: src/main.c:554
+msgid "       --no-glob               turn off FTP file name globbing.\n"
+msgstr ""
+
+#: src/main.c:556
+msgid "       --no-passive-ftp        disable the \"passive\" transfer mode.\n"
+msgstr ""
+
+#: src/main.c:558
+msgid ""
+"       --retr-symlinks         when recursing, get linked-to files (not "
+"dir).\n"
+msgstr ""
+
+#: src/main.c:560
+msgid "       --preserve-permissions  preserve remote file permissions.\n"
+msgstr ""
+
+#: src/main.c:564
+msgid "Recursive download:\n"
+msgstr ""
+
+#: src/main.c:566
+msgid "  -r,  --recursive          specify recursive download.\n"
+msgstr ""
+
+#: src/main.c:568
+msgid ""
+"  -l,  --level=NUMBER       maximum recursion depth (inf or 0 for "
+"infinite).\n"
+msgstr ""
+
+#: src/main.c:570
+msgid ""
+"       --delete-after       delete files locally after downloading them.\n"
+msgstr ""
+
+#: src/main.c:572
+msgid ""
+"  -k,  --convert-links      make links in downloaded HTML point to local "
+"files.\n"
+msgstr ""
+
+#: src/main.c:574
+msgid ""
+"  -K,  --backup-converted   before converting file X, back up as X.orig.\n"
+msgstr ""
+
+#: src/main.c:576
+msgid ""
+"  -m,  --mirror             shortcut option equivalent to -r -N -l inf -nr.\n"
+msgstr ""
+
+#: src/main.c:578
+msgid ""
+"  -p,  --page-requisites    get all images, etc. needed to display HTML "
+"page.\n"
+msgstr ""
+
+#: src/main.c:580
+msgid ""
+"       --strict-comments    turn on strict (SGML) handling of HTML "
+"comments.\n"
+msgstr ""
+
+#: src/main.c:584
+msgid "Recursive accept/reject:\n"
+msgstr ""
+
+#: src/main.c:586
+msgid ""
+"  -A,  --accept=LIST               comma-separated list of accepted "
+"extensions.\n"
+msgstr ""
+
+#: src/main.c:588
+msgid ""
+"  -R,  --reject=LIST               comma-separated list of rejected "
+"extensions.\n"
+msgstr ""
+
+#: src/main.c:590
+msgid ""
+"  -D,  --domains=LIST              comma-separated list of accepted "
+"domains.\n"
+msgstr ""
+
+#: src/main.c:592
+msgid ""
+"       --exclude-domains=LIST      comma-separated list of rejected "
+"domains.\n"
+msgstr ""
+
+#: src/main.c:594
+msgid ""
+"       --follow-ftp                follow FTP links from HTML documents.\n"
+msgstr ""
+
+#: src/main.c:596
+msgid ""
+"       --follow-tags=LIST          comma-separated list of followed HTML "
+"tags.\n"
+msgstr ""
+
+#: src/main.c:598
+msgid ""
+"       --ignore-tags=LIST          comma-separated list of ignored HTML "
+"tags.\n"
+msgstr ""
+
+#: src/main.c:600
+msgid ""
+"  -H,  --span-hosts                go to foreign hosts when recursive.\n"
+msgstr ""
+
+#: src/main.c:602
+msgid "  -L,  --relative                  follow relative links only.\n"
+msgstr ""
+
+#: src/main.c:604
+msgid "  -I,  --include-directories=LIST  list of allowed directories.\n"
+msgstr ""
+
+#: src/main.c:606
+msgid "  -X,  --exclude-directories=LIST  list of excluded directories.\n"
+msgstr ""
+
+#: src/main.c:608
+msgid ""
+"  -np, --no-parent                 don't ascend to the parent directory.\n"
+msgstr ""
+
+#: src/main.c:612
+msgid "Mail bug reports and suggestions to <bug-wget@gnu.org>.\n"
+msgstr "Rapport�r fejl og send forslag til <bug-wget@gnu.org>.\n"
+
+#: src/main.c:617
+#, c-format
+msgid "GNU Wget %s, a non-interactive network retriever.\n"
+msgstr "GNU Wget %s, en ikke-interaktiv informationsagent.\n"
+
+#: src/main.c:631
+#, fuzzy
+msgid "Copyright (C) 2005 Free Software Foundation, Inc.\n"
+msgstr ""
+"Ophavsret � 1995, 1996, 1997, 1998, 2000, 2001 Free Software Foundation, "
+"Inc.\n"
+
+#: src/main.c:633
+msgid ""
+"This program is distributed in the hope that it will be useful,\n"
+"but WITHOUT ANY WARRANTY; without even the implied warranty of\n"
+"MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the\n"
+"GNU General Public License for more details.\n"
+msgstr ""
+"Dette program distribueres i h�b om at det bliver fundet nyttigt,\n"
+"men UDEN NOGEN GARANTIER; ikke engang for SALGBARHED eller\n"
+"EGNETHED TIL NOGEN SPECIEL OPGAVE.\n"
+"Se 'GNU General Public License' for detaljer.\n"
+
+#: src/main.c:638
+#, fuzzy
+msgid ""
+"\n"
+"Originally written by Hrvoje Niksic <hniksic@xemacs.org>.\n"
+msgstr ""
+"\n"
+"Oprindeligt skrevet af Hrvoje Niksic <hniksic@arsdigita.com>.\n"
 
 #. #### Something nicer should be printed here -- similar to the
 #. pre-1.5 `--help' page.
-#: src/main.c:634 src/main.c:676 src/main.c:722
+#: src/main.c:684 src/main.c:753 src/main.c:832
 #, c-format
 msgid "Try `%s --help' for more options.\n"
 msgstr "Pr�v '%s --help' for flere flag.\n"
 
-#: src/main.c:702
+#: src/main.c:750
+#, c-format
+msgid "%s: illegal option -- `-n%c'\n"
+msgstr "%s: ugyldigt flag -- '-n%c'\n"
+
+#: src/main.c:803
+#, c-format
 msgid "Can't be verbose and quiet at the same time.\n"
 msgstr "Kan ikke v�re udf�rlig og stille p� samme tid.\n"
 
-#: src/main.c:708
+#: src/main.c:809
+#, c-format
 msgid "Can't timestamp and not clobber old files at the same time.\n"
-msgstr "Kan ikke tidsstemple og lade v�re at ber�re eksisterende filer p� samme tid.\n"
+msgstr ""
+"Kan ikke tidsstemple og lade v�re at ber�re eksisterende filer p� samme "
+"tid.\n"
+
+#: src/main.c:817
+#, c-format
+msgid "Cannot specify both --inet4-only and --inet6-only.\n"
+msgstr ""
 
 #. No URL specified.
-#: src/main.c:717
+#: src/main.c:827
 #, c-format
 msgid "%s: missing URL\n"
 msgstr "%s: URL mangler.\n"
 
-#: src/main.c:834
+#: src/main.c:936
 #, c-format
 msgid "No URLs found in %s.\n"
 msgstr "Fandt ingen URLer i %s.\n"
 
-#: src/main.c:843
+#: src/main.c:945
 #, c-format
 msgid ""
 "\n"