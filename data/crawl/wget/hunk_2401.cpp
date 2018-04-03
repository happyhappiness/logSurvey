 #. No luck.
 #. #### This message SUCKS.  We should see what was the
 #. reason that nothing was retrieved.
-#: src/ftp.c:1344
+#: src/ftp.c:1753
 #, c-format
 msgid "No matches on pattern `%s'.\n"
 msgstr "Ingenting passer med mønsteret «%s».\n"
 
-#: src/ftp.c:1404
-#, c-format
-msgid "Wrote HTML-ized index to `%s' [%ld].\n"
+#: src/ftp.c:1819
+#, fuzzy, c-format
+msgid "Wrote HTML-ized index to `%s' [%s].\n"
 msgstr "Skrev HTML-formattert indeks til «%s» [%ld].\n"
 
-#: src/ftp.c:1409
+#: src/ftp.c:1824
 #, c-format
 msgid "Wrote HTML-ized index to `%s'.\n"
 msgstr "Skrev HTML-formattert indeks til «%s».\n"
 
-#: src/getopt.c:454
+#: src/getopt.c:670
 #, c-format
 msgid "%s: option `%s' is ambiguous\n"
 msgstr "%s: flagget «%s» er tvetydig\n"
 
-#: src/getopt.c:478
+#: src/getopt.c:695
 #, c-format
 msgid "%s: option `--%s' doesn't allow an argument\n"
 msgstr "%s: flagget «--%s» tillater ikke argumenter\n"
 
-#: src/getopt.c:483
+#: src/getopt.c:700
 #, c-format
 msgid "%s: option `%c%s' doesn't allow an argument\n"
 msgstr "%s: flagget «%c%s» tillater ikke argumenter\n"
 
-#: src/getopt.c:498
+#: src/getopt.c:718 src/getopt.c:891
 #, c-format
 msgid "%s: option `%s' requires an argument\n"
 msgstr "%s: flagget «%s» krever et argument\n"
 
 #. --option
-#: src/getopt.c:528
+#: src/getopt.c:747
 #, c-format
 msgid "%s: unrecognized option `--%s'\n"
 msgstr "%s: ukjent flagg «--%s»\n"
 
 #. +option or -option
-#: src/getopt.c:532
+#: src/getopt.c:751
 #, c-format
 msgid "%s: unrecognized option `%c%s'\n"
 msgstr "%s: ukjent flagg «%c%s»\n"
 
 #. 1003.2 specifies the format of this message.
-#: src/getopt.c:563
+#: src/getopt.c:777
 #, c-format
 msgid "%s: illegal option -- %c\n"
 msgstr "%s: ugyldig flagg -- %c\n"
 
+#: src/getopt.c:780
+#, fuzzy, c-format
+msgid "%s: invalid option -- %c\n"
+msgstr "%s: ugyldig flagg -- %c\n"
+
 #. 1003.2 specifies the format of this message.
-#: src/getopt.c:602
+#: src/getopt.c:810 src/getopt.c:940
 #, c-format
 msgid "%s: option requires an argument -- %c\n"
 msgstr "%s: flagget krever et argument -- %c\n"
 
-#: src/host.c:432
-#, c-format
-msgid "%s: Cannot determine user-id.\n"
-msgstr "%s: Fant ikke bruker-ID.\n"
+#: src/getopt.c:857
+#, fuzzy, c-format
+msgid "%s: option `-W %s' is ambiguous\n"
+msgstr "%s: flagget «%s» er tvetydig\n"
 
-#: src/host.c:444
-#, c-format
-msgid "%s: Warning: uname failed: %s\n"
-msgstr "%s: Advarsel: feil fra «uname»:  %s\n"
+#: src/getopt.c:875
+#, fuzzy, c-format
+msgid "%s: option `-W %s' doesn't allow an argument\n"
+msgstr "%s: flagget «--%s» tillater ikke argumenter\n"
 
-#: src/host.c:456
-#, c-format
-msgid "%s: Warning: gethostname failed\n"
-msgstr "%s: Advarsel: feil fra «gethostname»\n"
+#: src/host.c:347
+#, fuzzy
+msgid "Unknown host"
+msgstr "Ukjent feil"
 
-#: src/host.c:484
-#, c-format
-msgid "%s: Warning: cannot determine local IP address.\n"
-msgstr "%s: Advarsel: fant ikke lokal IP-adresse.\n"
+#. Message modeled after what gai_strerror returns in similar
+#. circumstances.
+#: src/host.c:351
+msgid "Temporary failure in name resolution"
+msgstr ""
 
-#: src/host.c:498
-#, c-format
-msgid "%s: Warning: cannot reverse-lookup local IP address.\n"
-msgstr "%s: Advarsel: feil fra tilbake-oppslag for lokal IP-adresse.\n"
+#: src/host.c:353
+msgid "Unknown error"
+msgstr "Ukjent feil"
 
-#. This gets ticked pretty often.  Karl Berry reports
-#. that there can be valid reasons for the local host
-#. name not to be an FQDN, so I've decided to remove the
-#. annoying warning.
-#: src/host.c:511
-#, c-format
-msgid "%s: Warning: reverse-lookup of local address did not yield FQDN!\n"
-msgstr "%s: Advarsel: fikk ikke FQDN fra tilbake-oppslag for lokal IP-adresse!\n"
+#: src/host.c:714
+#, fuzzy, c-format
+msgid "Resolving %s... "
+msgstr "Fjerner %s.\n"
 
-#: src/host.c:539
-msgid "Host not found"
-msgstr "Tjener ikke funnet"
+#: src/host.c:761
+msgid "failed: No IPv4/IPv6 addresses for host.\n"
+msgstr ""
 
-#: src/host.c:541
-msgid "Unknown error"
-msgstr "Ukjent feil"
+#: src/host.c:784
+msgid "failed: timed out.\n"
+msgstr ""
 
-#: src/html.c:439 src/html.c:441
+#: src/html-url.c:288
 #, c-format
-msgid "Index of /%s on %s:%d"
-msgstr "Indeks for /%s på %s:%d"
+msgid "%s: Cannot resolve incomplete link %s.\n"
+msgstr ""
 
-#: src/html.c:463
-msgid "time unknown       "
-msgstr "ukjent tid         "
+#: src/html-url.c:695
+#, fuzzy, c-format
+msgid "%s: Invalid URL %s: %s\n"
+msgstr "%s: Ugyldig spesifikasjon «%s»\n"
 
-#: src/html.c:467
-msgid "File        "
-msgstr "Fil         "
+#: src/http.c:367
+#, fuzzy, c-format
+msgid "Failed writing HTTP request: %s.\n"
+msgstr "Feil ved sending av HTTP-forespørsel.\n"
 
-#: src/html.c:470
-msgid "Directory   "
-msgstr "Katalog     "
+#: src/http.c:736
+msgid "No headers, assuming HTTP/0.9"
+msgstr ""
 
-#: src/html.c:473
-msgid "Link        "
-msgstr "Link        "
+#: src/http.c:1413
+msgid "Disabling SSL due to encountered errors.\n"
+msgstr ""
 
-#: src/html.c:476
-msgid "Not sure    "
-msgstr "Usikker     "
+#: src/http.c:1566
+#, c-format
+msgid "POST data file `%s' missing: %s\n"
+msgstr ""
+
+#: src/http.c:1615
+#, fuzzy, c-format
+msgid "Reusing existing connection to %s:%d.\n"
+msgstr "Vil prøve å kontakte %s:%hu.\n"
 
-#: src/html.c:494
+#: src/http.c:1684
 #, c-format
-msgid " (%s bytes)"
-msgstr " (%s bytes)"
+msgid "Failed reading proxy response: %s\n"
+msgstr ""
 
-#: src/http.c:492
-msgid "Failed writing HTTP request.\n"
-msgstr "Feil ved sending av HTTP-forespørsel.\n"
+#: src/http.c:1704
+#, c-format
+msgid "Proxy tunneling failed: %s"
+msgstr ""
 
-#: src/http.c:497
+#: src/http.c:1749
 #, c-format
 msgid "%s request sent, awaiting response... "
 msgstr "%s forespørsel sendt, mottar topptekster... "
 
-#: src/http.c:536
-msgid "End of file while parsing headers.\n"
-msgstr "Filslutt funnet ved lesing av topptekster.\n"
+#: src/http.c:1760
+#, fuzzy
+msgid "No data received.\n"
+msgstr "Ingen data mottatt"
 
-#: src/http.c:547
+#: src/http.c:1767
 #, c-format
 msgid "Read error (%s) in headers.\n"
 msgstr "Lesefeil (%s) i topptekster.\n"
 
-#: src/http.c:587
-msgid "No data received"
-msgstr "Ingen data mottatt"
+#. If opt.noclobber is turned on and file already exists, do not
+#. retrieve the file
+#: src/http.c:1813
+#, fuzzy, c-format
+msgid ""
+"File `%s' already there; not retrieving.\n"
+"\n"
+msgstr "File «%s» eksisterer allerede, ignoreres.\n"
+
+#. If the authentication header is missing or
+#. unrecognized, there's no sense in retrying.
+#: src/http.c:1966
+msgid "Unknown authentication scheme.\n"
+msgstr "Ukjent autorisasjons-protokoll.\n"
 
-#: src/http.c:589
+#: src/http.c:1997
+msgid "Authorization failed.\n"
+msgstr "Autorisasjon mislyktes\n"
+
+#: src/http.c:2011
 msgid "Malformed status line"
 msgstr "Feil i statuslinje"
 
-#: src/http.c:594
+#: src/http.c:2013
 msgid "(no description)"
 msgstr "(ingen beskrivelse)"
 
-#. If we have tried it already, then there is not point
-#. retrying it.
-#: src/http.c:678
-msgid "Authorization failed.\n"
-msgstr "Autorisasjon mislyktes\n"
-
-#: src/http.c:685
-msgid "Unknown authentication scheme.\n"
-msgstr "Ukjent autorisasjons-protokoll.\n"
-
-#: src/http.c:748
+#: src/http.c:2076
 #, c-format
 msgid "Location: %s%s\n"
 msgstr "Sted: %s%s\n"
 
-#: src/http.c:749 src/http.c:774
+#: src/http.c:2077 src/http.c:2184
 msgid "unspecified"
 msgstr "uspesifisert"
 
-#: src/http.c:750
+#: src/http.c:2078
 msgid " [following]"
 msgstr " [omdirigert]"
 
+#. If `-c' is in use and the file has been fully downloaded (or
+#. the remote file has shrunk), Wget effectively requests bytes
+#. after the end of file and the server response with 416.
+#: src/http.c:2134
+msgid ""
+"\n"
+"    The file is already fully retrieved; nothing to do.\n"
+"\n"
+msgstr ""
+
 #. No need to print this output if the body won't be
 #. downloaded at all, or if the original server response is
 #. printed.
-#: src/http.c:764
+#: src/http.c:2164
 msgid "Length: "
 msgstr "Lengde: "
 
-#: src/http.c:769
-#, c-format
-msgid " (%s to go)"
-msgstr " (%s igjen)"
-
-#: src/http.c:774
+#: src/http.c:2184
 msgid "ignored"
 msgstr "ignoreres"
 
-#: src/http.c:857
+#: src/http.c:2255
+#, fuzzy, c-format
+msgid "Saving to: `%s'\n"
+msgstr "Ignorerer katalog «%s».\n"
+
+#: src/http.c:2335
 msgid "Warning: wildcards not supported in HTTP.\n"
 msgstr "Advarsel: jokertegn ikke støttet i HTTP.\n"
 
-#. If opt.noclobber is turned on and file already exists, do not
-#. retrieve the file
-#: src/http.c:872
-#, c-format
-msgid "File `%s' already there, will not retrieve.\n"
-msgstr "Filen «%s» hentes ikke, fordi den allerede eksisterer.\n"
+#: src/http.c:2364
+msgid "Spider mode enabled. Check if remote file exists.\n"
+msgstr ""
 
-#: src/http.c:978
+#: src/http.c:2450
 #, c-format
 msgid "Cannot write to `%s' (%s).\n"
 msgstr "Kan ikke skrive til «%s» (%s).\n"
 
-#: src/http.c:988
+#. Another fatal error.
+#: src/http.c:2459
+msgid "Unable to establish SSL connection.\n"
+msgstr ""
+
+#: src/http.c:2467
 #, c-format
 msgid "ERROR: Redirection (%d) without location.\n"
 msgstr "FEIL: Omdirigering (%d) uten nytt sted.\n"
 
-#: src/http.c:1011
+#: src/http.c:2505
+msgid "Remote file does not exist -- broken link!!!\n"
+msgstr ""
+
+#: src/http.c:2510
 #, c-format
 msgid "%s ERROR %d: %s.\n"
 msgstr "%s FEIL %d: %s.\n"
 
-#: src/http.c:1023
+#: src/http.c:2526
 msgid "Last-modified header missing -- time-stamps turned off.\n"
 msgstr "Last-modified topptekst mangler -- tidsstempling slås av.\n"
 
-#: src/http.c:1031
+#: src/http.c:2534
 msgid "Last-modified header invalid -- time-stamp ignored.\n"
 msgstr "Last-modified topptekst ugyldig -- tidsstempel ignoreres.\n"
 
-#: src/http.c:1064
+#: src/http.c:2558
+#, c-format
+msgid ""
+"Server file no newer than local file `%s' -- not retrieving.\n"
+"\n"
+msgstr ""
+
+#: src/http.c:2566
+#, fuzzy, c-format
+msgid "The sizes do not match (local %s) -- retrieving.\n"
+msgstr "Filstørrelsene er forskjellige (local %ld), hentes.\n"
+
+#: src/http.c:2573
 msgid "Remote file is newer, retrieving.\n"
 msgstr "Fil på tjener er nyere - hentes.\n"
 
-#: src/http.c:1098
-#, c-format
-msgid "%s (%s) - `%s' saved [%ld/%ld]\n\n"
-msgstr "%s (%s) - «%s» lagret [%ld/%ld]\n\n"
+#: src/http.c:2596
+msgid ""
+"Remote file exists and could contain links to other resources -- "
+"retrieving.\n"
+"\n"
+msgstr ""
 
-#: src/http.c:1130
-#, c-format
-msgid "%s (%s) - Connection closed at byte %ld. "
-msgstr "%s (%s) - Forbindelse brutt ved byte %ld. "
+#: src/http.c:2602
+msgid ""
+"Remote file exists but does not contain any link -- not retrieving.\n"
+"\n"
+msgstr ""
 
-#: src/http.c:1138
-#, c-format
-msgid "%s (%s) - `%s' saved [%ld/%ld])\n\n"
-msgstr "%s (%s) - «%s» lagret [%ld/%ld]\n\n"
+#: src/http.c:2610
+#, fuzzy
+msgid ""
+"Remote file exists but recursion is disabled -- not retrieving.\n"
+"\n"
+msgstr "Fil på tjener er nyere - hentes.\n"
 
-#: src/http.c:1150
-#, c-format
-msgid "%s (%s) - Connection closed at byte %ld/%ld. "
-msgstr "%s (%s) - Forbindelse brutt ved byte %ld/%ld. "
+#: src/http.c:2652
+#, fuzzy, c-format
+msgid ""
+"%s (%s) - `%s' saved [%s/%s]\n"
+"\n"
+msgstr ""
+"%s (%s) - «%s» lagret [%ld/%ld]\n"
+"\n"
 
-#: src/http.c:1161
-#, c-format
-msgid "%s (%s) - Read error at byte %ld (%s)."
+#: src/http.c:2707
+#, fuzzy, c-format
+msgid "%s (%s) - Connection closed at byte %s. "
+msgstr "%s (%s) - Forbindelse brutt ved byte %ld. "
+
+#: src/http.c:2722
+#, fuzzy, c-format
+msgid "%s (%s) - Read error at byte %s (%s)."
 msgstr "%s (%s) - Lesefeil ved byte %ld (%s)."
 
-#: src/http.c:1169
-#, c-format
-msgid "%s (%s) - Read error at byte %ld/%ld (%s). "
+#: src/http.c:2731
+#, fuzzy, c-format
+msgid "%s (%s) - Read error at byte %s/%s (%s). "
 msgstr "%s (%s) - Lesefeil ved byte %ld/%ld (%s)."
 
-#: src/init.c:312 src/netrc.c:250
+#: src/init.c:370
+#, c-format
+msgid "%s: WGETRC points to %s, which doesn't exist.\n"
+msgstr ""
+
+#: src/init.c:433 src/netrc.c:267
 #, c-format
 msgid "%s: Cannot read %s (%s).\n"
 msgstr "%s: Kan ikke lese %s (%s).\n"
 
-#: src/init.c:333 src/init.c:339
+#: src/init.c:451
 #, c-format
 msgid "%s: Error in %s at line %d.\n"
 msgstr "%s: Feil i %s på linje %d.\n"
 
-#: src/init.c:370
+#: src/init.c:457
+#, fuzzy, c-format
+msgid "%s: Syntax error in %s at line %d.\n"
+msgstr "%s: Feil i %s på linje %d.\n"
+
+#: src/init.c:462
+#, fuzzy, c-format
+msgid "%s: Unknown command `%s' in %s at line %d.\n"
+msgstr "%s: Ukjent kommando «%s», verdi «%s».\n"
+
+#: src/init.c:507
 #, c-format
 msgid "%s: Warning: Both system and user wgetrc point to `%s'.\n"
 msgstr "%s: Advarsel: Både systemets og brukerens wgetrc peker til «%s».\n"
 
-#: src/init.c:458
-#, c-format
-msgid "%s: BUG: unknown command `%s', value `%s'.\n"
-msgstr "%s: Ukjent kommando «%s», verdi «%s».\n"
+#: src/init.c:660
+#, fuzzy, c-format
+msgid "%s: Invalid --execute command `%s'\n"
+msgstr "%s: Ugyldig spesifikasjon «%s»\n"
 
-#: src/init.c:485
-#, c-format
-msgid "%s: %s: Please specify on or off.\n"
+#: src/init.c:705
+#, fuzzy, c-format
+msgid "%s: %s: Invalid boolean `%s'; use `on' or `off'.\n"
 msgstr "%s: %s: Vennligst spesifiser «on» eller «off».\n"
 
-#: src/init.c:503 src/init.c:760 src/init.c:782 src/init.c:855
-#, c-format
-msgid "%s: %s: Invalid specification `%s'.\n"
+#: src/init.c:722
+#, fuzzy, c-format
+msgid "%s: %s: Invalid number `%s'.\n"
+msgstr "%s: %s: Ugyldig spesifikasjon «%s»\n"
+
+#: src/init.c:953 src/init.c:972
+#, fuzzy, c-format
+msgid "%s: %s: Invalid byte value `%s'\n"
 msgstr "%s: %s: Ugyldig spesifikasjon «%s»\n"
 
-#: src/init.c:616 src/init.c:638 src/init.c:660 src/init.c:686
+#: src/init.c:997
+#, fuzzy, c-format
+msgid "%s: %s: Invalid time period `%s'\n"
+msgstr "%s: %s: Ugyldig spesifikasjon «%s»\n"
+
+#: src/init.c:1051 src/init.c:1141 src/init.c:1244 src/init.c:1269
+#, fuzzy, c-format
+msgid "%s: %s: Invalid value `%s'.\n"
+msgstr "%s: %s: Ugyldig spesifikasjon «%s»\n"
+
+#: src/init.c:1088
+#, fuzzy, c-format
+msgid "%s: %s: Invalid header `%s'.\n"
+msgstr "%s: %s: Ugyldig spesifikasjon «%s»\n"
+
+#: src/init.c:1154
+#, fuzzy, c-format
+msgid "%s: %s: Invalid progress type `%s'.\n"
+msgstr "%s: %s: Ugyldig spesifikasjon «%s»\n"
+
+#: src/init.c:1213
 #, c-format
-msgid "%s: Invalid specification `%s'\n"
-msgstr "%s: Ugyldig spesifikasjon «%s»\n"
+msgid ""
+"%s: %s: Invalid restriction `%s', use [unix|windows],[lowercase|uppercase],"
+"[nocontrol].\n"
+msgstr ""
+
+#: src/log.c:783
+#, fuzzy, c-format
+msgid ""
+"\n"
+"%s received, redirecting output to `%s'.\n"
+msgstr "%s mottatt, omdirigerer utskrifter til «%%s».\n"
+
+#. Eek!  Opening the alternate log file has failed.  Nothing we
+#. can do but disable printing completely.
+#: src/log.c:793
+#, fuzzy, c-format
+msgid ""
+"\n"
+"%s received.\n"
+msgstr "Ingen data mottatt"
 
-#: src/main.c:101
+#: src/log.c:794
 #, c-format
-msgid "Usage: %s [OPTION]... [URL]...\n"
-msgstr "Bruk: %s [FLAGG]... [URL]...\n"
+msgid "%s: %s; disabling logging.\n"
+msgstr ""
 
-#: src/main.c:109
+#: src/main.c:353
 #, c-format
-msgid "GNU Wget %s, a non-interactive network retriever.\n"
-msgstr "GNU Wget %s, en ikke-interaktiv informasjonsagent.\n"
+msgid "Usage: %s [OPTION]... [URL]...\n"
+msgstr "Bruk: %s [FLAGG]... [URL]...\n"
 
-#. Had to split this in parts, so the #@@#%# Ultrix compiler and cpp
-#. don't bitch.  Also, it makes translation much easier.
-#: src/main.c:114
-msgid "\nMandatory arguments to long options are mandatory for short options too.\n\n"
+#: src/main.c:365
+#, fuzzy
+msgid ""
+"Mandatory arguments to long options are mandatory for short options too.\n"
+"\n"
 msgstr ""
 "\n"
 "Obligatoriske argumenter til lange flagg er obligatoriske også \n"
 "for korte.\n"
 "\n"
 
-#: src/main.c:117
-msgid ""
-"Startup:\n"
-"  -V,  --version           display the version of Wget and exit.\n"
-"  -h,  --help              print this help.\n"
-"  -b,  --background        go to background after startup.\n"
-"  -e,  --execute=COMMAND   execute a `.wgetrc' command.\n"
-"\n"
-msgstr ""
-"Oppstart:\n"
-"  -V,  --version           viser Wget's versjonsnummer og avslutter.\n"
-"  -h,  --help              skriver ut denne hjelpeteksten.\n"
-"  -b,  --background        kjører i bakgrunnen etter oppstart.\n"
-"  -e,  --execute=KOMMANDO  utfør en «.wgetrc»-kommando.\n"
-"\n"
-
-#: src/main.c:123
-msgid ""
-"Logging and input file:\n"
-"  -o,  --output-file=FILE     log messages to FILE.\n"
-"  -a,  --append-output=FILE   append messages to FILE.\n"
-"  -d,  --debug                print debug output.\n"
-"  -q,  --quiet                quiet (no output).\n"
-"  -v,  --verbose              be verbose (this is the default).\n"
-"  -nv, --non-verbose          turn off verboseness, without being quiet.\n"
-"  -i,  --input-file=FILE      read URL-s from file.\n"
-"  -F,  --force-html           treat input file as HTML.\n"
-"\n"
-msgstr ""
-"Utskrifter og innlesing:\n"
-"  -o,  --output-file=FIL      skriv meldinger til ny FIL.\n"
-"  -a,  --append-output=FIL    skriv meldinger på slutten av FIL.\n"
-"  -d,  --debug                skriv avlusingsinformasjon.\n"
-"  -q,  --quiet                stille (ingen utskrifter).\n"
-"  -v,  --verbose              vær utførlig (standard).\n"
-"  -nv, --non-verbose          mindre utførlig, men ikke stille.\n"
-"  -i,  --input-file=FIL       les URLer fra FIL.\n"
-"  -F,  --force-html           les inn filer som HTML.\n"
-"\n"
-
-#: src/main.c:133
-msgid ""
-"Download:\n"
-"  -t,  --tries=NUMBER           set number of retries to NUMBER (0 unlimits).\n"
-"  -O   --output-document=FILE   write documents to FILE.\n"
-"  -nc, --no-clobber             don't clobber existing files.\n"
-"  -c,  --continue               restart getting an existing file.\n"
-"       --dot-style=STYLE        set retrieval display style.\n"
-"  -N,  --timestamping           don't retrieve files if older than local.\n"
-"  -S,  --server-response        print server response.\n"
-"       --spider                 don't download anything.\n"
-"  -T,  --timeout=SECONDS        set the read timeout to SECONDS.\n"
-"  -w,  --wait=SECONDS           wait SECONDS between retrievals.\n"
-"  -Y,  --proxy=on/off           turn proxy on or off.\n"
-"  -Q,  --quota=NUMBER           set retrieval quota to NUMBER.\n"
-"\n"
-msgstr ""
-"Nedlasting:\n"
-"  -t,  --tries=ANTALL           maksimalt antall forsøk (0 for uendelig).\n"
-"  -O   --output-document=FIL    skriv nedlastede filer til FIL.\n"
-"  -nc, --no-clobber             ikke berør eksisterende filer.\n"
-"  -c,  --continue               fortsett nedlasting av en eksisterende fil.\n"
-"       --dot-style=TYPE         velg format for nedlastings-status.\n"
-"  -N,  --timestamping           ikke hent filer som er eldre enn eksisterende.\n"
-"  -S,  --server-response        vis svar fra tjeneren.\n"
-"       --spider                 ikke hent filer.\n"
-"  -T,  --timeout=SEKUNDER       sett ventetid ved lesing til SEKUNDER.\n"
-"  -w,  --wait=SEKUNDER          sett ventetid mellom filer til SEKUNDER.\n"
-"  -Y,  --proxy=on/off           sett bruk av proxy på eller av.\n"
-"  -Q,  --quota=ANTALL           sett nedlastingskvote til ANTALL.\n"
-"\n"
-
-#: src/main.c:147
-msgid ""
-"Directories:\n"
-"  -nd  --no-directories            don't create directories.\n"
-"  -x,  --force-directories         force creation of directories.\n"
-"  -nH, --no-host-directories       don't create host directories.\n"
-"  -P,  --directory-prefix=PREFIX   save files to PREFIX/...\n"
-"       --cut-dirs=NUMBER           ignore NUMBER remote directory components.\n"
-"\n"
-msgstr ""
-"Kataloger:\n"
-"  -nd  --no-directories             ikke lag kataloger.\n"
-"  -x,  --force-directories          lag kataloger.\n"
-"  -nH, --no-host-directories        ikke lag ovenstående kataloger.\n"
-"  -P,  --directory-prefix=PREFIKS   skriv filer til PREFIKS/...\n"
-"       --cut-dirs=ANTALL            ignorer ANTALL komponenter av tjenerens\n"
-"                                    katalognavn.\n"
-"\n"
-
-#: src/main.c:154
-msgid ""
-"HTTP options:\n"
-"       --http-user=USER      set http user to USER.\n"
-"       --http-passwd=PASS    set http password to PASS.\n"
-"  -C,  --cache=on/off        (dis)allow server-cached data (normally allowed).\n"
-"       --ignore-length       ignore `Content-Length' header field.\n"
-"       --header=STRING       insert STRING among the headers.\n"
-"       --proxy-user=USER     set USER as proxy username.\n"
-"       --proxy-passwd=PASS   set PASS as proxy password.\n"
-"  -s,  --save-headers        save the HTTP headers to file.\n"
-"  -U,  --user-agent=AGENT    identify as AGENT instead of Wget/VERSION.\n"
-"\n"
-msgstr ""
-"HTTP-flagg:\n"
-"       --http-user=BRUKER      sett HTTP-bruker til BRUKER.\n"
-"       --http-passwd=PASSORD   sett HTTP-passord til PASSORD.\n"
-"  -C,  --cache=on/off          (ikke) tillat bruk av hurtiglager på tjener.\n"
-"       --ignore-length         ignorer «Content-Length» felt i topptekst.\n"
-"       --header=TEKST          sett TEKST inn som en topptekst.\n"
-"       --proxy-user=BRUKER     sett proxy-bruker til BRUKER.\n"
-"       --proxy-passwd=PASSORD  sett proxy-passord til PASSORD.\n"
-"  -s,  --save-headers          skriv HTTP-topptekster til fil.\n"
-"  -U,  --user-agent=AGENT      identifiser som AGENT i stedet for \n"
-"                               «Wget/VERSJON».\n"
-"\n"
-
-#: src/main.c:165
-msgid ""
-"FTP options:\n"
-"       --retr-symlinks   retrieve FTP symbolic links.\n"
-"  -g,  --glob=on/off     turn file name globbing on or off.\n"
-"       --passive-ftp     use the \"passive\" transfer mode.\n"
-"\n"
-msgstr ""
-"FTP-flagg:\n"
-"       --retr-symlinks   hent symbolske linker via FTP.\n"
-"  -g,  --glob=on/off     (ikke) tolk bruk av jokertegn i filnavn.\n"
-"       --passive-ftp     bruk passiv overføringsmodus.\n"
-"\n"
-
-#: src/main.c:170
-msgid ""
-"Recursive retrieval:\n"
-"  -r,  --recursive             recursive web-suck -- use with care!.\n"
-"  -l,  --level=NUMBER          maximum recursion depth (0 to unlimit).\n"
-"       --delete-after          delete downloaded files.\n"
-"  -k,  --convert-links         convert non-relative links to relative.\n"
-"  -m,  --mirror                turn on options suitable for mirroring.\n"
-"  -nr, --dont-remove-listing   don't remove `.listing' files.\n"
-"\n"
-msgstr ""
-"Rekursiv nedlasting:\n"
-"  -r,  --recursive             tillat rekursiv nedlasting -- bruk med omtanke!\n"
-"  -l,  --level=ANTALL          maksimalt antall rekursjonsnivåer (0=uendelig).\n"
-"       --delete-after          slett nedlastede filer.\n"
-"  -k,  --convert-links         konverter absolutte linker til relative.\n"
-"  -m,  --mirror                sett passende flagg for speiling av tjenere.\n"
-"  -nr, --dont-remove-listing   ikke slett «.listing»-filer.\n"
-"\n"
-
-#: src/main.c:178
-msgid ""
-"Recursive accept/reject:\n"
-"  -A,  --accept=LIST                list of accepted extensions.\n"
-"  -R,  --reject=LIST                list of rejected extensions.\n"
-"  -D,  --domains=LIST               list of accepted domains.\n"
-"       --exclude-domains=LIST       comma-separated list of rejected domains.\n"
-"  -L,  --relative                   follow relative links only.\n"
-"       --follow-ftp                 follow FTP links from HTML documents.\n"
-"  -H,  --span-hosts                 go to foreign hosts when recursive.\n"
-"  -I,  --include-directories=LIST   list of allowed directories.\n"
-"  -X,  --exclude-directories=LIST   list of excluded directories.\n"
-"  -nh, --no-host-lookup             don't DNS-lookup hosts.\n"
-"  -np, --no-parent                  don't ascend to the parent directory.\n"
-"\n"
-msgstr ""
-"Hva er tillatt ved rekursjon:\n"
-"  -A,  --accept=LISTE               liste med tillatte filtyper.\n"
-"  -R,  --reject=LISTE               liste med ikke tillatte filtyper.\n"
-"  -D,  --domains=LISTE              liste med tillatte domener.\n"
-"       --exclude-domains=LISTE      liste med ikke tillatte domener.\n"
-"  -L,  --relative                   følg kun relative linker.\n"
-"       --follow-ftp                 følg FTP-linker fra HTML-dokumenter.\n"
-"  -H,  --span-hosts                 følg linker til andre tjenere.\n"
-"  -I,  --include-directories=LISTE  liste med tillatte katalognavn.\n"
-"  -X,  --exclude-directories=LISTE  liste med ikke tillatte katalognavn.\n"
-"  -nh, --no-host-lookup             ikke let etter tjenernavn via DNS.\n"
-"  -np, --no-parent                  ikke følg linker til ovenstående katalog.\n"
-"\n"
-
-#: src/main.c:191
-msgid "Mail bug reports and suggestions to <bug-wget@gnu.org>.\n"
-msgstr "Rapportér feil og send forslag til <bug-wget@gnu.org>.\n"
+#: src/main.c:367
+msgid "Startup:\n"
+msgstr ""
 
-#: src/main.c:347
-#, c-format
-msgid "%s: debug support not compiled in.\n"
-msgstr "%s: støtte for avlusing ikke inkludert ved kompilering.\n"
+#: src/main.c:369
+msgid "  -V,  --version           display the version of Wget and exit.\n"
+msgstr ""
+
+#: src/main.c:371
+msgid "  -h,  --help              print this help.\n"
+msgstr ""
+
+#: src/main.c:373
+msgid "  -b,  --background        go to background after startup.\n"
+msgstr ""
+
+#: src/main.c:375
+msgid "  -e,  --execute=COMMAND   execute a `.wgetrc'-style command.\n"
+msgstr ""
+
+#: src/main.c:379
+msgid "Logging and input file:\n"
+msgstr ""
+
+#: src/main.c:381
+msgid "  -o,  --output-file=FILE    log messages to FILE.\n"
+msgstr ""
+
+#: src/main.c:383
+msgid "  -a,  --append-output=FILE  append messages to FILE.\n"
+msgstr ""
+
+#: src/main.c:386
+msgid "  -d,  --debug               print lots of debugging information.\n"
+msgstr ""
+
+#: src/main.c:389
+msgid "  -q,  --quiet               quiet (no output).\n"
+msgstr ""
+
+#: src/main.c:391
+msgid "  -v,  --verbose             be verbose (this is the default).\n"
+msgstr ""
+
+#: src/main.c:393
+msgid ""
+"  -nv, --no-verbose          turn off verboseness, without being quiet.\n"
+msgstr ""
 
 #: src/main.c:395
+msgid "  -i,  --input-file=FILE     download URLs found in FILE.\n"
+msgstr ""
+
+#: src/main.c:397
+msgid "  -F,  --force-html          treat input file as HTML.\n"
+msgstr ""
+
+#: src/main.c:399
 msgid ""
-"Copyright (C) 1995, 1996, 1997, 1998 Free Software Foundation, Inc.\n"
-"This program is distributed in the hope that it will be useful,\n"
-"but WITHOUT ANY WARRANTY; without even the implied warranty of\n"
-"MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the\n"
-"GNU General Public License for more details.\n"
+"  -B,  --base=URL            prepends URL to relative links in -F -i file.\n"
 msgstr ""
-"Copyright (C) 1995, 1996, 1997, 1998 Free Software Foundation, Inc.\n"
-"Dette programmet distribueres i håp om at det blir funnet nyttig,\n"
-"men UTEN NOEN GARANTIER; ikke en gang for SALGBARHET eller\n"
-"EGNETHET TIL NOEN SPESIELL OPPGAVE.\n"
-"Se «GNU General Public License» for detaljer.\n"
 
-#: src/main.c:401
-msgid "\nWritten by Hrvoje Niksic <hniksic@srce.hr>.\n"
-msgstr "\nSkrevet av Hrvoje Niksic <hniksic@srce.hr>.\n"
+#: src/main.c:403
+msgid "Download:\n"
+msgstr ""
 
-#: src/main.c:465
-#, c-format
-msgid "%s: %s: invalid command\n"
-msgstr "%s: %s: ugyldig kommando\n"
+#: src/main.c:405
+msgid ""
+"  -t,  --tries=NUMBER            set number of retries to NUMBER (0 "
+"unlimits).\n"
+msgstr ""
+
+#: src/main.c:407
+msgid "       --retry-connrefused       retry even if connection is refused.\n"
+msgstr ""
+
+#: src/main.c:409
+msgid "  -O,  --output-document=FILE    write documents to FILE.\n"
+msgstr ""
+
+#: src/main.c:411
+msgid ""
+"  -nc, --no-clobber              skip downloads that would download to\n"
+"                                 existing files.\n"
+msgstr ""
+
+#: src/main.c:414
+msgid ""
+"  -c,  --continue                resume getting a partially-downloaded "
+"file.\n"
+msgstr ""
+
+#: src/main.c:416
+msgid "       --progress=TYPE           select progress gauge type.\n"
+msgstr ""
+
+#: src/main.c:418
+msgid ""
+"  -N,  --timestamping            don't re-retrieve files unless newer than\n"
+"                                 local.\n"
+msgstr ""
+
+#: src/main.c:421
+msgid "  -S,  --server-response         print server response.\n"
+msgstr ""
+
+#: src/main.c:423
+msgid "       --spider                  don't download anything.\n"
+msgstr ""
+
+#: src/main.c:425
+msgid "  -T,  --timeout=SECONDS         set all timeout values to SECONDS.\n"
+msgstr ""
+
+#: src/main.c:427
+msgid "       --dns-timeout=SECS        set the DNS lookup timeout to SECS.\n"
+msgstr ""
+
+#: src/main.c:429
+msgid "       --connect-timeout=SECS    set the connect timeout to SECS.\n"
+msgstr ""
+
+#: src/main.c:431
+msgid "       --read-timeout=SECS       set the read timeout to SECS.\n"
+msgstr ""
+
+#: src/main.c:433
+msgid "  -w,  --wait=SECONDS            wait SECONDS between retrievals.\n"
+msgstr ""
+
+#: src/main.c:435
+msgid ""
+"       --waitretry=SECONDS       wait 1..SECONDS between retries of a "
+"retrieval.\n"
+msgstr ""
+
+#: src/main.c:437
+msgid ""
+"       --random-wait             wait from 0...2*WAIT secs between "
+"retrievals.\n"
+msgstr ""
+
+#: src/main.c:439
+msgid "  -Y,  --proxy                   explicitly turn on proxy.\n"
+msgstr ""
+
+#: src/main.c:441
+msgid "       --no-proxy                explicitly turn off proxy.\n"
+msgstr ""
+
+#: src/main.c:443
+msgid "  -Q,  --quota=NUMBER            set retrieval quota to NUMBER.\n"
+msgstr ""
+
+#: src/main.c:445
+msgid ""
+"       --bind-address=ADDRESS    bind to ADDRESS (hostname or IP) on local "
+"host.\n"
+msgstr ""
+
+#: src/main.c:447
+msgid "       --limit-rate=RATE         limit download rate to RATE.\n"
+msgstr ""
+
+#: src/main.c:449
+msgid "       --no-dns-cache            disable caching DNS lookups.\n"
+msgstr ""
+
+#: src/main.c:451
+msgid ""
+"       --restrict-file-names=OS  restrict chars in file names to ones OS "
+"allows.\n"
+msgstr ""
+
+#: src/main.c:453
+msgid ""
+"       --ignore-case             ignore case when matching files/"
+"directories.\n"
+msgstr ""
+
+#: src/main.c:456
+msgid "  -4,  --inet4-only              connect only to IPv4 addresses.\n"
+msgstr ""
+
+#: src/main.c:458
+msgid "  -6,  --inet6-only              connect only to IPv6 addresses.\n"
+msgstr ""
+
+#: src/main.c:460
+msgid ""
+"       --prefer-family=FAMILY    connect first to addresses of specified "
+"family,\n"
+"                                 one of IPv6, IPv4, or none.\n"
+msgstr ""
+
+#: src/main.c:464
+msgid "       --user=USER               set both ftp and http user to USER.\n"
+msgstr ""
+
+#: src/main.c:466
+msgid ""
+"       --password=PASS           set both ftp and http password to PASS.\n"
+msgstr ""
+
+#: src/main.c:470
+#, fuzzy
+msgid "Directories:\n"
+msgstr "Katalog     "
+
+#: src/main.c:472
+msgid "  -nd, --no-directories           don't create directories.\n"
+msgstr ""
+
+#: src/main.c:474
+msgid "  -x,  --force-directories        force creation of directories.\n"
+msgstr ""
+
+#: src/main.c:476
+msgid "  -nH, --no-host-directories      don't create host directories.\n"
+msgstr ""
+
+#: src/main.c:478
+msgid "       --protocol-directories     use protocol name in directories.\n"
+msgstr ""
+
+#: src/main.c:480
+msgid "  -P,  --directory-prefix=PREFIX  save files to PREFIX/...\n"
+msgstr ""
+
+#: src/main.c:482
+msgid ""
+"       --cut-dirs=NUMBER          ignore NUMBER remote directory "
+"components.\n"
+msgstr ""
+
+#: src/main.c:486
+msgid "HTTP options:\n"
+msgstr ""
+
+#: src/main.c:488
+msgid "       --http-user=USER        set http user to USER.\n"
+msgstr ""
+
+#: src/main.c:490
+msgid "       --http-password=PASS    set http password to PASS.\n"
+msgstr ""
+
+#: src/main.c:492
+msgid "       --no-cache              disallow server-cached data.\n"
+msgstr ""
+
+#: src/main.c:494
+msgid ""
+"  -E,  --html-extension        save HTML documents with `.html' extension.\n"
+msgstr ""
+
+#: src/main.c:496
+msgid "       --ignore-length         ignore `Content-Length' header field.\n"
+msgstr ""
+
+#: src/main.c:498
+msgid "       --header=STRING         insert STRING among the headers.\n"
+msgstr ""
 
-#: src/main.c:515
+#: src/main.c:500
+msgid "       --max-redirect          maximum redirections allowed per page.\n"
+msgstr ""
+
+#: src/main.c:502
+msgid "       --proxy-user=USER       set USER as proxy username.\n"
+msgstr ""
+
+#: src/main.c:504
+msgid "       --proxy-password=PASS   set PASS as proxy password.\n"
+msgstr ""
+
+#: src/main.c:506
+msgid ""
+"       --referer=URL           include `Referer: URL' header in HTTP "
+"request.\n"
+msgstr ""
+
+#: src/main.c:508
+msgid "       --save-headers          save the HTTP headers to file.\n"
+msgstr ""
+
+#: src/main.c:510
+msgid ""
+"  -U,  --user-agent=AGENT      identify as AGENT instead of Wget/VERSION.\n"
+msgstr ""
+
+#: src/main.c:512
+msgid ""
+"       --no-http-keep-alive    disable HTTP keep-alive (persistent "
+"connections).\n"
+msgstr ""
+
+#: src/main.c:514
+msgid "       --no-cookies            don't use cookies.\n"
+msgstr ""
+
+#: src/main.c:516
+msgid "       --load-cookies=FILE     load cookies from FILE before session.\n"
+msgstr ""
+
+#: src/main.c:518
+msgid "       --save-cookies=FILE     save cookies to FILE after session.\n"
+msgstr ""
+
+#: src/main.c:520
+msgid ""
+"       --keep-session-cookies  load and save session (non-permanent) "
+"cookies.\n"
+msgstr ""
+
+#: src/main.c:522
+msgid ""
+"       --post-data=STRING      use the POST method; send STRING as the "
+"data.\n"
+msgstr ""
+
+#: src/main.c:524
+msgid ""
+"       --post-file=FILE        use the POST method; send contents of FILE.\n"
+msgstr ""
+
+#: src/main.c:526
+msgid ""
+"       --no-content-disposition  don't honor Content-Disposition header.\n"
+msgstr ""
+
+#: src/main.c:531
+msgid "HTTPS (SSL/TLS) options:\n"
+msgstr ""
+
+#: src/main.c:533
+msgid ""
+"       --secure-protocol=PR     choose secure protocol, one of auto, SSLv2,\n"
+"                                SSLv3, and TLSv1.\n"
+msgstr ""
+
+#: src/main.c:536
+msgid ""
+"       --no-check-certificate   don't validate the server's certificate.\n"
+msgstr ""
+
+#: src/main.c:538
+msgid "       --certificate=FILE       client certificate file.\n"
+msgstr ""
+
+#: src/main.c:540
+msgid "       --certificate-type=TYPE  client certificate type, PEM or DER.\n"
+msgstr ""
+
+#: src/main.c:542
+msgid "       --private-key=FILE       private key file.\n"
+msgstr ""
+
+#: src/main.c:544
+msgid "       --private-key-type=TYPE  private key type, PEM or DER.\n"
+msgstr ""
+
+#: src/main.c:546
+msgid "       --ca-certificate=FILE    file with the bundle of CA's.\n"
+msgstr ""
+
+#: src/main.c:548
+msgid ""
+"       --ca-directory=DIR       directory where hash list of CA's is "
+"stored.\n"
+msgstr ""
+
+#: src/main.c:550
+msgid ""
+"       --random-file=FILE       file with random data for seeding the SSL "
+"PRNG.\n"
+msgstr ""
+
+#: src/main.c:552
+msgid ""
+"       --egd-file=FILE          file naming the EGD socket with random "
+"data.\n"
+msgstr ""
+
+#: src/main.c:557
+msgid "FTP options:\n"
+msgstr ""
+
+#: src/main.c:559
+msgid "       --ftp-user=USER         set ftp user to USER.\n"
+msgstr ""
+
+#: src/main.c:561
+msgid "       --ftp-password=PASS     set ftp password to PASS.\n"
+msgstr ""
+
+#: src/main.c:563
+msgid "       --no-remove-listing     don't remove `.listing' files.\n"
+msgstr ""
+
+#: src/main.c:565
+msgid "       --no-glob               turn off FTP file name globbing.\n"
+msgstr ""
+
+#: src/main.c:567
+msgid "       --no-passive-ftp        disable the \"passive\" transfer mode.\n"
+msgstr ""
+
+#: src/main.c:569
+msgid ""
+"       --retr-symlinks         when recursing, get linked-to files (not "
+"dir).\n"
+msgstr ""
+
+#: src/main.c:571
+msgid "       --preserve-permissions  preserve remote file permissions.\n"
+msgstr ""
+
+#: src/main.c:575
+msgid "Recursive download:\n"
+msgstr ""
+
+#: src/main.c:577
+msgid "  -r,  --recursive          specify recursive download.\n"
+msgstr ""
+
+#: src/main.c:579
+msgid ""
+"  -l,  --level=NUMBER       maximum recursion depth (inf or 0 for "
+"infinite).\n"
+msgstr ""
+
+#: src/main.c:581
+msgid ""
+"       --delete-after       delete files locally after downloading them.\n"
+msgstr ""
+
+#: src/main.c:583
+msgid ""
+"  -k,  --convert-links      make links in downloaded HTML point to local "
+"files.\n"
+msgstr ""
+
+#: src/main.c:585
+msgid ""
+"  -K,  --backup-converted   before converting file X, back up as X.orig.\n"
+msgstr ""
+
+#: src/main.c:587
+msgid ""
+"  -m,  --mirror             shortcut for -N -r -l inf --no-remove-listing.\n"
+msgstr ""
+
+#: src/main.c:589
+msgid ""
+"  -p,  --page-requisites    get all images, etc. needed to display HTML "
+"page.\n"
+msgstr ""
+
+#: src/main.c:591
+msgid ""
+"       --strict-comments    turn on strict (SGML) handling of HTML "
+"comments.\n"
+msgstr ""
+
+#: src/main.c:595
+msgid "Recursive accept/reject:\n"
+msgstr ""
+
+#: src/main.c:597
+msgid ""
+"  -A,  --accept=LIST               comma-separated list of accepted "
+"extensions.\n"
+msgstr ""
+
+#: src/main.c:599
+msgid ""
+"  -R,  --reject=LIST               comma-separated list of rejected "
+"extensions.\n"
+msgstr ""
+
+#: src/main.c:601
+msgid ""
+"  -D,  --domains=LIST              comma-separated list of accepted "
+"domains.\n"
+msgstr ""
+
+#: src/main.c:603
+msgid ""
+"       --exclude-domains=LIST      comma-separated list of rejected "
+"domains.\n"
+msgstr ""
+
+#: src/main.c:605
+msgid ""
+"       --follow-ftp                follow FTP links from HTML documents.\n"
+msgstr ""
+
+#: src/main.c:607
+msgid ""
+"       --follow-tags=LIST          comma-separated list of followed HTML "
+"tags.\n"
+msgstr ""
+
+#: src/main.c:609
+msgid ""
+"       --ignore-tags=LIST          comma-separated list of ignored HTML "
+"tags.\n"
+msgstr ""
+
+#: src/main.c:611
+msgid ""
+"  -H,  --span-hosts                go to foreign hosts when recursive.\n"
+msgstr ""
+
+#: src/main.c:613
+msgid "  -L,  --relative                  follow relative links only.\n"
+msgstr ""
+
+#: src/main.c:615
+msgid "  -I,  --include-directories=LIST  list of allowed directories.\n"
+msgstr ""
+
+#: src/main.c:617
+msgid "  -X,  --exclude-directories=LIST  list of excluded directories.\n"
+msgstr ""
+
+#: src/main.c:619
+msgid ""
+"  -np, --no-parent                 don't ascend to the parent directory.\n"
+msgstr ""
+
+#: src/main.c:623
+msgid "Mail bug reports and suggestions to <bug-wget@gnu.org>.\n"
+msgstr "Rapportér feil og send forslag til <bug-wget@gnu.org>.\n"
+
+#: src/main.c:628
 #, c-format
-msgid "%s: illegal option -- `-n%c'\n"
-msgstr "%s: ugyldig flagg -- «-n%c»\n"
+msgid "GNU Wget %s, a non-interactive network retriever.\n"
+msgstr "GNU Wget %s, en ikke-interaktiv informasjonsagent.\n"
+
+#: src/main.c:668
+msgid "Copyright (C) 2007 Free Software Foundation, Inc.\n"
+msgstr ""
+
+#: src/main.c:670
+msgid ""
+"License GPLv3+: GNU GPL version 3 or later\n"
+"<http://www.gnu.org/licenses/gpl.html>.\n"
+"This is free software: you are free to change and redistribute it.\n"
+"There is NO WARRANTY, to the extent permitted by law.\n"
+msgstr ""
+
+#: src/main.c:675
+#, fuzzy
+msgid ""
+"\n"
+"Originally written by Hrvoje Niksic <hniksic@xemacs.org>.\n"
+msgstr ""
+"\n"
+"Skrevet av Hrvoje Niksic <hniksic@srce.hr>.\n"
+
+#: src/main.c:677
+msgid "Currently maintained by Micah Cowan <micah@cowan.name>.\n"
+msgstr ""
 
 #. #### Something nicer should be printed here -- similar to the
 #. pre-1.5 `--help' page.
-#: src/main.c:518 src/main.c:560 src/main.c:591
+#: src/main.c:724 src/main.c:793 src/main.c:890
 #, c-format
 msgid "Try `%s --help' for more options.\n"
 msgstr "Prøv «%s --help» for flere flagg.\n"
 
-#: src/main.c:571
+#: src/main.c:790
+#, c-format
+msgid "%s: illegal option -- `-n%c'\n"
+msgstr "%s: ugyldig flagg -- «-n%c»\n"
+
+#: src/main.c:845
+#, c-format
 msgid "Can't be verbose and quiet at the same time.\n"
 msgstr "Kan ikke være utførlig og stille på samme tid.\n"
 
-#: src/main.c:577
+#: src/main.c:851
+#, c-format
 msgid "Can't timestamp and not clobber old files at the same time.\n"
-msgstr "Kan ikke tidsstemple og la være å berøre eksisterende filer på samme tid.\n"
+msgstr ""
+"Kan ikke tidsstemple og la være å berøre eksisterende filer på samme tid.\n"
+
+#: src/main.c:859
+#, c-format
+msgid "Cannot specify both --inet4-only and --inet6-only.\n"
+msgstr ""
+
+#: src/main.c:869
+#, c-format
+msgid "Cannot specify -r, -p or -N if -O is given.\n"
+msgstr ""
+
+#: src/main.c:877
+#, c-format
+msgid "Cannot specify both -k and -O if multiple URLs are given.\n"
+msgstr ""
 
 #. No URL specified.
-#: src/main.c:586
+#: src/main.c:885
 #, c-format
 msgid "%s: missing URL\n"
 msgstr "%s: URL mangler.\n"
 
-#: src/main.c:674
+#: src/main.c:1005
 #, c-format
 msgid "No URLs found in %s.\n"
 msgstr "Fant ingen URLer i %s.\n"
 
-#: src/main.c:683
-#, c-format
+#: src/main.c:1023
+#, fuzzy, c-format
 msgid ""
-"\n"
 "FINISHED --%s--\n"
-"Downloaded: %s bytes in %d files\n"
+"Downloaded: %d files, %s in %s (%s)\n"
 msgstr ""
 "\n"
 "FERDIG --%s--\n"
 "Lastet ned %s bytes i %d filer\n"
 
-#: src/main.c:688
-#, c-format
-msgid "Download quota (%s bytes) EXCEEDED!\n"
+#: src/main.c:1032
+#, fuzzy, c-format
+msgid "Download quota of %s EXCEEDED!\n"
 msgstr "Nedlastingskvote (%s bytes) overskredet!\n"
 
-#. Please note that the double `%' in `%%s' is intentional, because
-#. redirect_output passes tmp through printf.
-#: src/main.c:715
-msgid "%s received, redirecting output to `%%s'.\n"
-msgstr "%s mottatt, omdirigerer utskrifter til «%%s».\n"
-
-#: src/mswindows.c:118
+#: src/mswindows.c:96
 #, c-format
-msgid ""
-"\n"
-"CTRL+Break received, redirecting output to `%s'.\n"
-"Execution continued in background.\n"
-"You may stop Wget by pressing CTRL+ALT+DELETE.\n"
-msgstr ""
-"\n"
-"CTRL+Break mottatt, omdirigerer utskrifter til `%s'.\n"
-"Kjøring fortsetter i bakgrunnen.\n"
-"Du kan stoppe Wget ved å trykke CTRL+ALT+DELETE.\n"
-"\n"
-
-#. parent, no error
-#: src/mswindows.c:135 src/utils.c:268
 msgid "Continuing in background.\n"
 msgstr "Fortsetter i bakgrunnen.\n"
 
-#: src/mswindows.c:137 src/utils.c:270
+#: src/mswindows.c:289
+#, fuzzy, c-format
+msgid "Continuing in background, pid %lu.\n"
+msgstr "Fortsetter i bakgrunnen.\n"
+
+#: src/mswindows.c:291 src/utils.c:326
 #, c-format
 msgid "Output will be written to `%s'.\n"
 msgstr "Utskrifter vil bli skrevet til «%s».\n"
 
-#: src/mswindows.c:227
-#, c-format
-msgid "Starting WinHelp %s\n"
-msgstr "Starter WinHelp %s\n"
-
-#: src/mswindows.c:254 src/mswindows.c:262
+#: src/mswindows.c:459 src/mswindows.c:466
 #, c-format
 msgid "%s: Couldn't find usable socket driver.\n"
 msgstr "%s: Fant ingen brukbar socket-driver.\n"
 
-#: src/netrc.c:334
+#: src/netrc.c:375
 #, c-format
 msgid "%s: %s:%d: warning: \"%s\" token appears before any machine name\n"
 msgstr "%s: %s:%d: Advarsel: symbolet «%s» funnet før tjener-navn\n"
 
-#: src/netrc.c:365
+#: src/netrc.c:406
 #, c-format
 msgid "%s: %s:%d: unknown token \"%s\"\n"
 msgstr "%s: %s:%d: ukjent symbol «%s»\n"
 
-#: src/netrc.c:429
+#: src/netrc.c:470
 #, c-format
 msgid "Usage: %s NETRC [HOSTNAME]\n"
 msgstr "Bruk: %s NETRC [TJENERNAVN]\n"
 
-#: src/netrc.c:439
+#: src/netrc.c:480
 #, c-format
 msgid "%s: cannot stat %s: %s\n"
 msgstr "%s: «stat» feilet for %s: %s\n"
 
-#: src/recur.c:449 src/retr.c:462
+#. Still not random enough, presumably because neither /dev/random
+#. nor EGD were available.  Try to seed OpenSSL's PRNG with libc
+#. PRNG.  This is cryptographically weak and defeats the purpose
+#. of using OpenSSL, which is why it is highly discouraged.
+#: src/openssl.c:112
+msgid "WARNING: using a weak random seed.\n"
+msgstr ""
+
+#: src/openssl.c:172
+msgid "Could not seed PRNG; consider using --random-file.\n"
+msgstr ""
+
+#. If the user has specified --no-check-cert, we still want to warn
+#. him about problems with the server's certificate.
+#: src/openssl.c:487
+msgid "ERROR"
+msgstr ""
+
+#: src/openssl.c:487
+msgid "WARNING"
+msgstr ""
+
+#: src/openssl.c:496
 #, c-format
-msgid "Removing %s.\n"
-msgstr "Fjerner %s.\n"
+msgid "%s: No certificate presented by %s.\n"
+msgstr ""
+
+#: src/openssl.c:517
+#, c-format
+msgid "%s: cannot verify %s's certificate, issued by `%s':\n"
+msgstr ""
+
+#: src/openssl.c:525
+msgid "  Unable to locally verify the issuer's authority.\n"
+msgstr ""
+
+#: src/openssl.c:529
+msgid "  Self-signed certificate encountered.\n"
+msgstr ""
+
+#: src/openssl.c:532
+msgid "  Issued certificate not yet valid.\n"
+msgstr ""
+
+#: src/openssl.c:535
+msgid "  Issued certificate has expired.\n"
+msgstr ""
+
+#: src/openssl.c:567
+#, c-format
+msgid ""
+"%s: certificate common name `%s' doesn't match requested host name `%s'.\n"
+msgstr ""
+
+#: src/openssl.c:580
+#, c-format
+msgid "To connect to %s insecurely, use `--no-check-certificate'.\n"
+msgstr ""
+
+#. Align the [ skipping ... ] line with the dots.  To do
+#. that, insert the number of spaces equal to the number of
+#. digits in the skipped amount in K.
+#: src/progress.c:238
+#, fuzzy, c-format
+msgid ""
+"\n"
+"%*s[ skipping %sK ]"
+msgstr ""
+"\n"
+"          [ hopper over %dK ]"
+
+#: src/progress.c:452
+#, fuzzy, c-format
+msgid "Invalid dot style specification `%s'; leaving unchanged.\n"
+msgstr "%s: Ugyldig spesifikasjon «%s»\n"
+
+#. Translation note: "ETA" is English-centric, but this must
+#. be short, ideally 3 chars.  Abbreviate if necessary.
+#: src/progress.c:946
+#, c-format
+msgid "  eta %s"
+msgstr ""
 
-#: src/recur.c:450
+#. When the download is done, print the elapsed time.
+#. Note to translators: this should not take up more room than
+#. available here.  Abbreviate if necessary.
+#: src/progress.c:961
+msgid "   in "
+msgstr ""
+
+#. If no clock was found, it means that clock_getres failed for
+#. the realtime clock.
+#: src/ptimer.c:160
+#, c-format
+msgid "Cannot get REALTIME clock frequency: %s\n"
+msgstr ""
+
+#: src/recur.c:377
 #, c-format
 msgid "Removing %s since it should be rejected.\n"
 msgstr "Fjerner %s fordi den skal forkastes.\n"
 
-#: src/recur.c:609
+#: src/res.c:392
+#, fuzzy, c-format
+msgid "Cannot open %s: %s"
+msgstr "Kan ikke konvertere linker i %s: %s\n"
+
+#: src/res.c:544
 msgid "Loading robots.txt; please ignore errors.\n"
 msgstr "Henter robots.txt; ignorer eventuelle feilmeldinger.\n"
 
-#: src/retr.c:193
+#: src/retr.c:651
 #, c-format
-msgid "\n          [ skipping %dK ]"
-msgstr "\n          [ hopper over %dK ]"
-
-#: src/retr.c:344
-msgid "Could not find proxy host.\n"
-msgstr "Fant ikke proxy-tjener.\n"
+msgid "Error parsing proxy URL %s: %s.\n"
+msgstr ""
 
-#: src/retr.c:355
-#, c-format
-msgid "Proxy %s: Must be HTTP.\n"
+#: src/retr.c:659
+#, fuzzy, c-format
+msgid "Error in proxy URL %s: Must be HTTP.\n"
 msgstr "Proxy %s: Må støtte HTTP.\n"
 
-#: src/retr.c:398
-#, c-format
-msgid "%s: Redirection to itself.\n"
+#: src/retr.c:745
+#, fuzzy, c-format
+msgid "%d redirections exceeded.\n"
 msgstr "%s: Omdirigerer til seg selv.\n"
 
-#: src/retr.c:483
-msgid "Giving up.\n\n"
-msgstr "Gir opp.\n\n"
-
-#: src/retr.c:483
-msgid "Retrying.\n\n"
-msgstr "Prøver igjen.\n\n"
+#: src/retr.c:880
+msgid ""
+"Giving up.\n"
+"\n"
+msgstr ""
+"Gir opp.\n"
+"\n"
 
-#: src/url.c:940
-#, c-format
-msgid "Error (%s): Link %s without a base provided.\n"
-msgstr "Feil (%s): Link %s gitt uten utgangspunkt.\n"
+#: src/retr.c:880
+msgid ""
+"Retrying.\n"
+"\n"
+msgstr ""
+"Prøver igjen.\n"
+"\n"
 
-#: src/url.c:955
-#, c-format
-msgid "Error (%s): Base %s relative, without referer URL.\n"
-msgstr "Feil (%s): Utgangspunktet %s er relativt, ukjent URL som referent.\n"
+#: src/spider.c:137
+msgid ""
+"Found no broken links.\n"
+"\n"
+msgstr ""
 
-#: src/url.c:1373
+#: src/spider.c:144
 #, c-format
-msgid "Converting %s... "
-msgstr "Konverterer %s... "
+msgid ""
+"Found %d broken link.\n"
+"\n"
+msgid_plural ""
+"Found %d broken links.\n"
+"\n"
+msgstr[0] ""
+msgstr[1] ""
 
-#: src/url.c:1378 src/url.c:1389
+#: src/spider.c:154
 #, c-format
-msgid "Cannot convert links in %s: %s\n"
-msgstr "Kan ikke konvertere linker i %s: %s\n"
+msgid "%s referred by:\n"
+msgstr ""
 
-#: src/utils.c:71
+#: src/spider.c:159
 #, c-format
-msgid "%s: %s: Not enough memory.\n"
-msgstr "%s: %s: Ikke nok minne.\n"
+msgid "    %s\n"
+msgstr ""
 
-#: src/utils.c:203
-msgid "Unknown/unsupported protocol"
-msgstr "Protokollen er ukjent/ikke støttet"
+#: src/url.c:619
+#, fuzzy
+msgid "No error"
+msgstr "Ukjent feil"
 
-#: src/utils.c:206
-msgid "Invalid port specification"
-msgstr "Port-spesifikasjonen er ugyldig"
+#: src/url.c:621
+msgid "Unsupported scheme"
+msgstr ""
 
-#: src/utils.c:209
+#: src/url.c:623
 msgid "Invalid host name"
 msgstr "Tjenernavnet er ugyldig"
 
-#: src/utils.c:430
+#: src/url.c:625
+msgid "Bad port number"
+msgstr ""
+
+#: src/url.c:627
+#, fuzzy
+msgid "Invalid user name"
+msgstr "Tjenernavnet er ugyldig"
+
+#: src/url.c:629
+msgid "Unterminated IPv6 numeric address"
+msgstr ""
+
+#: src/url.c:631
+msgid "IPv6 addresses not supported"
+msgstr ""
+
+#: src/url.c:633
+msgid "Invalid IPv6 numeric address"
+msgstr ""
+
+#. parent, no error
+#: src/utils.c:324
+#, fuzzy, c-format
+msgid "Continuing in background, pid %d.\n"
+msgstr "Fortsetter i bakgrunnen.\n"
+
+#: src/utils.c:372
 #, c-format
 msgid "Failed to unlink symlink `%s': %s\n"
 msgstr "Kan ikke slette den symbolske linken «%s»: %s\n"
+
+#: src/xmalloc.c:62
+#, c-format
+msgid "%s: %s: Failed to allocate %ld bytes; memory exhausted.\n"
+msgstr ""
+
+#~ msgid "Connection to %s:%hu refused.\n"
+#~ msgstr "Kontakt med %s:%hu nektet.\n"
+
+#~ msgid " [%s to go]"
+#~ msgstr " [%s igjen]"
+
+#~ msgid ""
+#~ "Local file `%s' is more recent, not retrieving.\n"
+#~ "\n"
+#~ msgstr ""
+#~ "Lokal fil «%s» er samme/nyere, ignoreres.\n"
+#~ "\n"
+
+#~ msgid "%s: Cannot determine user-id.\n"
+#~ msgstr "%s: Fant ikke bruker-ID.\n"
+
+#~ msgid "%s: Warning: uname failed: %s\n"
+#~ msgstr "%s: Advarsel: feil fra «uname»:  %s\n"
+
+#~ msgid "%s: Warning: gethostname failed\n"
+#~ msgstr "%s: Advarsel: feil fra «gethostname»\n"
+
+#~ msgid "%s: Warning: cannot determine local IP address.\n"
+#~ msgstr "%s: Advarsel: fant ikke lokal IP-adresse.\n"
+
+#~ msgid "%s: Warning: cannot reverse-lookup local IP address.\n"
+#~ msgstr "%s: Advarsel: feil fra tilbake-oppslag for lokal IP-adresse.\n"
+
+#~ msgid "%s: Warning: reverse-lookup of local address did not yield FQDN!\n"
+#~ msgstr ""
+#~ "%s: Advarsel: fikk ikke FQDN fra tilbake-oppslag for lokal IP-adresse!\n"
+
+#~ msgid "Host not found"
+#~ msgstr "Tjener ikke funnet"
+
+#~ msgid "End of file while parsing headers.\n"
+#~ msgstr "Filslutt funnet ved lesing av topptekster.\n"
+
+#~ msgid " (%s to go)"
+#~ msgstr " (%s igjen)"
+
+#~ msgid "File `%s' already there, will not retrieve.\n"
+#~ msgstr "Filen «%s» hentes ikke, fordi den allerede eksisterer.\n"
+
+#~ msgid ""
+#~ "%s (%s) - `%s' saved [%ld/%ld])\n"
+#~ "\n"
+#~ msgstr ""
+#~ "%s (%s) - «%s» lagret [%ld/%ld]\n"
+#~ "\n"
+
+#~ msgid "%s (%s) - Connection closed at byte %ld/%ld. "
+#~ msgstr "%s (%s) - Forbindelse brutt ved byte %ld/%ld. "
+
+#~ msgid ""
+#~ "Startup:\n"
+#~ "  -V,  --version           display the version of Wget and exit.\n"
+#~ "  -h,  --help              print this help.\n"
+#~ "  -b,  --background        go to background after startup.\n"
+#~ "  -e,  --execute=COMMAND   execute a `.wgetrc' command.\n"
+#~ "\n"
+#~ msgstr ""
+#~ "Oppstart:\n"
+#~ "  -V,  --version           viser Wget's versjonsnummer og avslutter.\n"
+#~ "  -h,  --help              skriver ut denne hjelpeteksten.\n"
+#~ "  -b,  --background        kjører i bakgrunnen etter oppstart.\n"
+#~ "  -e,  --execute=KOMMANDO  utfør en «.wgetrc»-kommando.\n"
+#~ "\n"
+
+#~ msgid ""
+#~ "Logging and input file:\n"
+#~ "  -o,  --output-file=FILE     log messages to FILE.\n"
+#~ "  -a,  --append-output=FILE   append messages to FILE.\n"
+#~ "  -d,  --debug                print debug output.\n"
+#~ "  -q,  --quiet                quiet (no output).\n"
+#~ "  -v,  --verbose              be verbose (this is the default).\n"
+#~ "  -nv, --non-verbose          turn off verboseness, without being quiet.\n"
+#~ "  -i,  --input-file=FILE      read URL-s from file.\n"
+#~ "  -F,  --force-html           treat input file as HTML.\n"
+#~ "\n"
+#~ msgstr ""
+#~ "Utskrifter og innlesing:\n"
+#~ "  -o,  --output-file=FIL      skriv meldinger til ny FIL.\n"
+#~ "  -a,  --append-output=FIL    skriv meldinger på slutten av FIL.\n"
+#~ "  -d,  --debug                skriv avlusingsinformasjon.\n"
+#~ "  -q,  --quiet                stille (ingen utskrifter).\n"
+#~ "  -v,  --verbose              vær utførlig (standard).\n"
+#~ "  -nv, --non-verbose          mindre utførlig, men ikke stille.\n"
+#~ "  -i,  --input-file=FIL       les URLer fra FIL.\n"
+#~ "  -F,  --force-html           les inn filer som HTML.\n"
+#~ "\n"
+
+#~ msgid ""
+#~ "Download:\n"
+#~ "  -t,  --tries=NUMBER           set number of retries to NUMBER (0 "
+#~ "unlimits).\n"
+#~ "  -O   --output-document=FILE   write documents to FILE.\n"
+#~ "  -nc, --no-clobber             don't clobber existing files.\n"
+#~ "  -c,  --continue               restart getting an existing file.\n"
+#~ "       --dot-style=STYLE        set retrieval display style.\n"
+#~ "  -N,  --timestamping           don't retrieve files if older than "
+#~ "local.\n"
+#~ "  -S,  --server-response        print server response.\n"
+#~ "       --spider                 don't download anything.\n"
+#~ "  -T,  --timeout=SECONDS        set the read timeout to SECONDS.\n"
+#~ "  -w,  --wait=SECONDS           wait SECONDS between retrievals.\n"
+#~ "  -Y,  --proxy=on/off           turn proxy on or off.\n"
+#~ "  -Q,  --quota=NUMBER           set retrieval quota to NUMBER.\n"
+#~ "\n"
+#~ msgstr ""
+#~ "Nedlasting:\n"
+#~ "  -t,  --tries=ANTALL           maksimalt antall forsøk (0 for "
+#~ "uendelig).\n"
+#~ "  -O   --output-document=FIL    skriv nedlastede filer til FIL.\n"
+#~ "  -nc, --no-clobber             ikke berør eksisterende filer.\n"
+#~ "  -c,  --continue               fortsett nedlasting av en eksisterende "
+#~ "fil.\n"
+#~ "       --dot-style=TYPE         velg format for nedlastings-status.\n"
+#~ "  -N,  --timestamping           ikke hent filer som er eldre enn "
+#~ "eksisterende.\n"
+#~ "  -S,  --server-response        vis svar fra tjeneren.\n"
+#~ "       --spider                 ikke hent filer.\n"
+#~ "  -T,  --timeout=SEKUNDER       sett ventetid ved lesing til SEKUNDER.\n"
+#~ "  -w,  --wait=SEKUNDER          sett ventetid mellom filer til SEKUNDER.\n"
+#~ "  -Y,  --proxy=on/off           sett bruk av proxy på eller av.\n"
+#~ "  -Q,  --quota=ANTALL           sett nedlastingskvote til ANTALL.\n"
+#~ "\n"
+
+#~ msgid ""
+#~ "Directories:\n"
+#~ "  -nd  --no-directories            don't create directories.\n"
+#~ "  -x,  --force-directories         force creation of directories.\n"
+#~ "  -nH, --no-host-directories       don't create host directories.\n"
+#~ "  -P,  --directory-prefix=PREFIX   save files to PREFIX/...\n"
+#~ "       --cut-dirs=NUMBER           ignore NUMBER remote directory "
+#~ "components.\n"
+#~ "\n"
+#~ msgstr ""
+#~ "Kataloger:\n"
+#~ "  -nd  --no-directories             ikke lag kataloger.\n"
+#~ "  -x,  --force-directories          lag kataloger.\n"
+#~ "  -nH, --no-host-directories        ikke lag ovenstående kataloger.\n"
+#~ "  -P,  --directory-prefix=PREFIKS   skriv filer til PREFIKS/...\n"
+#~ "       --cut-dirs=ANTALL            ignorer ANTALL komponenter av "
+#~ "tjenerens\n"
+#~ "                                    katalognavn.\n"
+#~ "\n"
+
+#~ msgid ""
+#~ "HTTP options:\n"
+#~ "       --http-user=USER      set http user to USER.\n"
+#~ "       --http-passwd=PASS    set http password to PASS.\n"
+#~ "  -C,  --cache=on/off        (dis)allow server-cached data (normally "
+#~ "allowed).\n"
+#~ "       --ignore-length       ignore `Content-Length' header field.\n"
+#~ "       --header=STRING       insert STRING among the headers.\n"
+#~ "       --proxy-user=USER     set USER as proxy username.\n"
+#~ "       --proxy-passwd=PASS   set PASS as proxy password.\n"
+#~ "  -s,  --save-headers        save the HTTP headers to file.\n"
+#~ "  -U,  --user-agent=AGENT    identify as AGENT instead of Wget/VERSION.\n"
+#~ "\n"
+#~ msgstr ""
+#~ "HTTP-flagg:\n"
+#~ "       --http-user=BRUKER      sett HTTP-bruker til BRUKER.\n"
+#~ "       --http-passwd=PASSORD   sett HTTP-passord til PASSORD.\n"
+#~ "  -C,  --cache=on/off          (ikke) tillat bruk av hurtiglager på "
+#~ "tjener.\n"
+#~ "       --ignore-length         ignorer «Content-Length» felt i "
+#~ "topptekst.\n"
+#~ "       --header=TEKST          sett TEKST inn som en topptekst.\n"
+#~ "       --proxy-user=BRUKER     sett proxy-bruker til BRUKER.\n"
+#~ "       --proxy-passwd=PASSORD  sett proxy-passord til PASSORD.\n"
+#~ "  -s,  --save-headers          skriv HTTP-topptekster til fil.\n"
+#~ "  -U,  --user-agent=AGENT      identifiser som AGENT i stedet for \n"
+#~ "                               «Wget/VERSJON».\n"
+#~ "\n"
+
+#~ msgid ""
+#~ "FTP options:\n"
+#~ "       --retr-symlinks   retrieve FTP symbolic links.\n"
+#~ "  -g,  --glob=on/off     turn file name globbing on or off.\n"
+#~ "       --passive-ftp     use the \"passive\" transfer mode.\n"
+#~ "\n"
+#~ msgstr ""
+#~ "FTP-flagg:\n"
+#~ "       --retr-symlinks   hent symbolske linker via FTP.\n"
+#~ "  -g,  --glob=on/off     (ikke) tolk bruk av jokertegn i filnavn.\n"
+#~ "       --passive-ftp     bruk passiv overføringsmodus.\n"
+#~ "\n"
+
+#~ msgid ""
+#~ "Recursive retrieval:\n"
+#~ "  -r,  --recursive             recursive web-suck -- use with care!.\n"
+#~ "  -l,  --level=NUMBER          maximum recursion depth (0 to unlimit).\n"
+#~ "       --delete-after          delete downloaded files.\n"
+#~ "  -k,  --convert-links         convert non-relative links to relative.\n"
+#~ "  -m,  --mirror                turn on options suitable for mirroring.\n"
+#~ "  -nr, --dont-remove-listing   don't remove `.listing' files.\n"
+#~ "\n"
+#~ msgstr ""
+#~ "Rekursiv nedlasting:\n"
+#~ "  -r,  --recursive             tillat rekursiv nedlasting -- bruk med "
+#~ "omtanke!\n"
+#~ "  -l,  --level=ANTALL          maksimalt antall rekursjonsnivåer "
+#~ "(0=uendelig).\n"
+#~ "       --delete-after          slett nedlastede filer.\n"
+#~ "  -k,  --convert-links         konverter absolutte linker til relative.\n"
+#~ "  -m,  --mirror                sett passende flagg for speiling av "
+#~ "tjenere.\n"
+#~ "  -nr, --dont-remove-listing   ikke slett «.listing»-filer.\n"
+#~ "\n"
+
+#~ msgid ""
+#~ "Recursive accept/reject:\n"
+#~ "  -A,  --accept=LIST                list of accepted extensions.\n"
+#~ "  -R,  --reject=LIST                list of rejected extensions.\n"
+#~ "  -D,  --domains=LIST               list of accepted domains.\n"
+#~ "       --exclude-domains=LIST       comma-separated list of rejected "
+#~ "domains.\n"
+#~ "  -L,  --relative                   follow relative links only.\n"
+#~ "       --follow-ftp                 follow FTP links from HTML "
+#~ "documents.\n"
+#~ "  -H,  --span-hosts                 go to foreign hosts when recursive.\n"
+#~ "  -I,  --include-directories=LIST   list of allowed directories.\n"
+#~ "  -X,  --exclude-directories=LIST   list of excluded directories.\n"
+#~ "  -nh, --no-host-lookup             don't DNS-lookup hosts.\n"
+#~ "  -np, --no-parent                  don't ascend to the parent "
+#~ "directory.\n"
+#~ "\n"
+#~ msgstr ""
+#~ "Hva er tillatt ved rekursjon:\n"
+#~ "  -A,  --accept=LISTE               liste med tillatte filtyper.\n"
+#~ "  -R,  --reject=LISTE               liste med ikke tillatte filtyper.\n"
+#~ "  -D,  --domains=LISTE              liste med tillatte domener.\n"
+#~ "       --exclude-domains=LISTE      liste med ikke tillatte domener.\n"
+#~ "  -L,  --relative                   følg kun relative linker.\n"
+#~ "       --follow-ftp                 følg FTP-linker fra HTML-dokumenter.\n"
+#~ "  -H,  --span-hosts                 følg linker til andre tjenere.\n"
+#~ "  -I,  --include-directories=LISTE  liste med tillatte katalognavn.\n"
+#~ "  -X,  --exclude-directories=LISTE  liste med ikke tillatte katalognavn.\n"
+#~ "  -nh, --no-host-lookup             ikke let etter tjenernavn via DNS.\n"
+#~ "  -np, --no-parent                  ikke følg linker til ovenstående "
+#~ "katalog.\n"
+#~ "\n"
+
+#~ msgid "%s: debug support not compiled in.\n"
+#~ msgstr "%s: støtte for avlusing ikke inkludert ved kompilering.\n"
+
+#~ msgid ""
+#~ "Copyright (C) 1995, 1996, 1997, 1998 Free Software Foundation, Inc.\n"
+#~ "This program is distributed in the hope that it will be useful,\n"
+#~ "but WITHOUT ANY WARRANTY; without even the implied warranty of\n"
+#~ "MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the\n"
+#~ "GNU General Public License for more details.\n"
+#~ msgstr ""
+#~ "Copyright (C) 1995, 1996, 1997, 1998 Free Software Foundation, Inc.\n"
+#~ "Dette programmet distribueres i håp om at det blir funnet nyttig,\n"
+#~ "men UTEN NOEN GARANTIER; ikke en gang for SALGBARHET eller\n"
+#~ "EGNETHET TIL NOEN SPESIELL OPPGAVE.\n"
+#~ "Se «GNU General Public License» for detaljer.\n"
+
+#~ msgid "%s: %s: invalid command\n"
+#~ msgstr "%s: %s: ugyldig kommando\n"
+
+#~ msgid ""
+#~ "\n"
+#~ "CTRL+Break received, redirecting output to `%s'.\n"
+#~ "Execution continued in background.\n"
+#~ "You may stop Wget by pressing CTRL+ALT+DELETE.\n"
+#~ msgstr ""
+#~ "\n"
+#~ "CTRL+Break mottatt, omdirigerer utskrifter til `%s'.\n"
+#~ "Kjøring fortsetter i bakgrunnen.\n"
+#~ "Du kan stoppe Wget ved å trykke CTRL+ALT+DELETE.\n"
+#~ "\n"
+
+#~ msgid "Starting WinHelp %s\n"
+#~ msgstr "Starter WinHelp %s\n"
+
+#~ msgid "Could not find proxy host.\n"
+#~ msgstr "Fant ikke proxy-tjener.\n"
+
+#~ msgid "Error (%s): Link %s without a base provided.\n"
+#~ msgstr "Feil (%s): Link %s gitt uten utgangspunkt.\n"
+
+#~ msgid "Error (%s): Base %s relative, without referer URL.\n"
+#~ msgstr ""
+#~ "Feil (%s): Utgangspunktet %s er relativt, ukjent URL som referent.\n"
+
+#~ msgid "%s: %s: Not enough memory.\n"
+#~ msgstr "%s: %s: Ikke nok minne.\n"
+
+#~ msgid "Unknown/unsupported protocol"
+#~ msgstr "Protokollen er ukjent/ikke støttet"
+
+#~ msgid "Invalid port specification"
+#~ msgstr "Port-spesifikasjonen er ugyldig"
