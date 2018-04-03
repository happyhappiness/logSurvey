#. No luck.
#. #### This message SUCKS.  We should see what was the
#. reason that nothing was retrieved.
#: src/ftp.c:1819
#, c-format
msgid "No matches on pattern `%s'.\n"
msgstr "Ingenting passer med mønstret '%s'.\n"

#: src/ftp.c:1885
#, fuzzy, c-format
msgid "Wrote HTML-ized index to `%s' [%s].\n"
msgstr "Skrev HTML-formateret indeks til '%s' [%ld].\n"

#: src/ftp.c:1890
#, c-format
msgid "Wrote HTML-ized index to `%s'.\n"
msgstr "Skrev HTML-formateret indeks til '%s'.\n"

#. Still not enough randomness, most likely because neither
#. /dev/random nor EGD were available.  Resort to a simple and
#. stupid method -- seed OpenSSL's PRNG with libc PRNG.  This is
#. cryptographically weak, but people who care about strong
#. cryptography should install /dev/random (default on Linux) or
#. specify their own source of randomness anyway.
#: src/gen_sslfunc.c:109
msgid "Warning: using a weak random seed.\n"
msgstr ""

#: src/gen_sslfunc.c:166
msgid "Could not seed OpenSSL PRNG; disabling SSL.\n"
msgstr "Kunne ikke påbegynde OpenSSL PRNG; deaktiverer SSL.\n"

#: src/gen_sslfunc.c:223
msgid "Warning: validation of server certificate not possible!\n"
msgstr ""

#: src/getopt.c:675
#, c-format
msgid "%s: option `%s' is ambiguous\n"
msgstr "%s: flaget '%s' er flertydig\n"

#: src/getopt.c:700
#, c-format
msgid "%s: option `--%s' doesn't allow an argument\n"
msgstr "%s: flaget '--%s' tillader ikke argumenter\n"

#: src/getopt.c:705
#, c-format
msgid "%s: option `%c%s' doesn't allow an argument\n"
msgstr "%s: flaget '%c%s' tillader ikke argumenter\n"

#: src/getopt.c:723 src/getopt.c:896
#, c-format
msgid "%s: option `%s' requires an argument\n"
msgstr "%s: flaget '%s' kræver et argument\n"

#. --option
#: src/getopt.c:752
#, c-format
msgid "%s: unrecognized option `--%s'\n"
msgstr "%s: ukendt flag '--%s'\n"

#. +option or -option
#: src/getopt.c:756
#, c-format
msgid "%s: unrecognized option `%c%s'\n"
msgstr "%s: ukendt flag '%c%s'\n"

#. 1003.2 specifies the format of this message.
#: src/getopt.c:782
#, c-format
msgid "%s: illegal option -- %c\n"
msgstr "%s: ugyldigt flag -- %c\n"

#: src/getopt.c:785
#, fuzzy, c-format
msgid "%s: invalid option -- %c\n"
msgstr "%s: ugyldigt flag -- %c\n"

#. 1003.2 specifies the format of this message.
#: src/getopt.c:815 src/getopt.c:945
#, c-format
msgid "%s: option requires an argument -- %c\n"
msgstr "%s: flaget kræver et argument -- %c\n"

#: src/getopt.c:862
#, fuzzy, c-format
msgid "%s: option `-W %s' is ambiguous\n"
msgstr "%s: flaget '%s' er flertydig\n"

#: src/getopt.c:880
#, fuzzy, c-format
msgid "%s: option `-W %s' doesn't allow an argument\n"
msgstr "%s: flaget '--%s' tillader ikke argumenter\n"

#: src/host.c:368
#, fuzzy
msgid "Unknown host"
msgstr "Ukendt fejl"

#. Message modeled after what gai_strerror returns in similar
#. circumstances.
#: src/host.c:372
msgid "Temporary failure in name resolution"
msgstr ""

#: src/host.c:374
msgid "Unknown error"
msgstr "Ukendt fejl"

#: src/host.c:748
#, c-format
msgid "Resolving %s... "
msgstr "Løser %s..."

#: src/host.c:792 src/host.c:839
#, c-format
msgid "failed: %s.\n"
msgstr "mislykkedes: %s.\n"

#: src/host.c:801
msgid "failed: No IPv4/IPv6 addresses for host.\n"
msgstr ""

#: src/host.c:842
#, fuzzy
msgid "failed: timed out.\n"
msgstr "mislykkedes: %s.\n"

#: src/html-url.c:297
#, c-format
msgid "%s: Cannot resolve incomplete link %s.\n"
msgstr "%s: kan ikke løse ukomplet lænke %s.\n"

#: src/http.c:349 src/http.c:1504
#, c-format
msgid "Failed writing HTTP request: %s.\n"
msgstr "Fejl ved skrivning af HTTP-forespørgsel: %s.\n"

#: src/http.c:663
msgid "No headers, assuming HTTP/0.9"
msgstr ""

#. this is fatal
#: src/http.c:1151
msgid "Failed to set up an SSL context\n"
msgstr "Kunne ikke opsætte et SSL-miljø\n"

#: src/http.c:1156
#, c-format
msgid "Failed to load certificates from %s\n"
msgstr "Kunne ikke indlæse certifikater fra %s\n"

#: src/http.c:1159 src/http.c:1166
msgid "Trying without the specified certificate\n"
msgstr "Prøver uden det angivne certifikat\n"

#: src/http.c:1163
#, c-format
msgid "Failed to get certificate key from %s\n"
msgstr "Kunne ikke få certifikatnøgle fra %s\n"

#: src/http.c:1382
#, fuzzy, c-format
msgid "Reusing existing connection to %s:%d.\n"
msgstr "Genbruger forbindelse til %s:%hu.\n"

#: src/http.c:1434
#, fuzzy, c-format
msgid "Failed writing to proxy: %s.\n"
msgstr "Fejl ved skrivning af HTTP-forespørgsel: %s.\n"

#: src/http.c:1443
#, fuzzy, c-format
msgid "Failed reading proxy response: %s\n"
msgstr "Fejl ved skrivning af HTTP-forespørgsel: %s.\n"

#: src/http.c:1463
#, c-format
msgid "Proxy tunneling failed: %s"
msgstr ""

#: src/http.c:1510
#, c-format
msgid "%s request sent, awaiting response... "
msgstr "%s forespørgsel sendt, afventer svar... "

#: src/http.c:1521
#, fuzzy
msgid "No data received.\n"
msgstr "Ingen data modtaget"

#: src/http.c:1528
#, c-format
msgid "Read error (%s) in headers.\n"
msgstr "Læsefejl (%s) i toptekster.\n"

#. If we have tried it already, then there is not point
#. retrying it.
#: src/http.c:1595
msgid "Authorization failed.\n"
msgstr "Autorisation mislykkedes\n"

#: src/http.c:1609
msgid "Unknown authentication scheme.\n"
msgstr "Ukendt autorisations-protokol.\n"

#: src/http.c:1634
msgid "Malformed status line"
msgstr "Forkert udformet statuslinje"

#: src/http.c:1636
msgid "(no description)"
msgstr "(ingen beskrivelse)"

#: src/http.c:1700
#, c-format
msgid "Location: %s%s\n"
msgstr "Sted: %s%s\n"

#: src/http.c:1701 src/http.c:1801
msgid "unspecified"
msgstr "uspecificeret"

#: src/http.c:1702
msgid " [following]"
msgstr " [omdirigeret]"

#. If `-c' is in use and the file has been fully downloaded (or
#. the remote file has shrunk), Wget effectively requests bytes
#. after the end of file and the server response with 416.
#: src/http.c:1751
msgid ""
"\n"
"    The file is already fully retrieved; nothing to do.\n"
"\n"
msgstr ""
"\n"
"    Filen er allerede fuldt overført; ingen handling nødvendig.\n"
"\n"

#. No need to print this output if the body won't be
#. downloaded at all, or if the original server response is
#. printed.
#: src/http.c:1781
msgid "Length: "
msgstr "Længde: "

#: src/http.c:1801
msgid "ignored"
msgstr "ignoreret"

#: src/http.c:1943
msgid "Warning: wildcards not supported in HTTP.\n"
msgstr "Advarsel: jokertegn ikke understøttet i HTTP.\n"

#. If opt.noclobber is turned on and file already exists, do not
#. retrieve the file
#: src/http.c:1978
#, c-format
msgid "File `%s' already there, will not retrieve.\n"
msgstr "Filen '%s' hentes ikke, fordi den allerede eksisterer.\n"

#: src/http.c:2165
#, c-format
msgid "Cannot write to `%s' (%s).\n"
msgstr "Kan ikke skrive til '%s' (%s).\n"

#: src/http.c:2174
msgid "Unable to establish SSL connection.\n"
msgstr "Kunne ikke etablere SSL-forbindelse.\n"

#: src/http.c:2184
#, c-format
msgid "ERROR: Redirection (%d) without location.\n"
msgstr "FEJL: Omdirigering (%d) uden nyt sted.\n"

#: src/http.c:2216
#, c-format
msgid "%s ERROR %d: %s.\n"
msgstr "%s FEJL %d: %s.\n"

#: src/http.c:2229
msgid "Last-modified header missing -- time-stamps turned off.\n"
msgstr "Last-modified toptekst mangler -- tidsstempling slås fra.\n"

#: src/http.c:2237
msgid "Last-modified header invalid -- time-stamp ignored.\n"
msgstr "Last-modified toptekst ugyldig -- tidsstempel ignoreret.\n"

#: src/http.c:2260
#, c-format
msgid ""
"Server file no newer than local file `%s' -- not retrieving.\n"
"\n"
msgstr ""
"Serverfil ikke nyere end lokal fil '%s' - hentes ikke.\n"
"\n"

#: src/http.c:2268
#, fuzzy, c-format
msgid "The sizes do not match (local %s) -- retrieving.\n"
msgstr "Størrelserne er forskellige (lokal %ld) - hentes.\n"

#: src/http.c:2273
msgid "Remote file is newer, retrieving.\n"
msgstr "Fil på server er nyere - hentes.\n"

#: src/http.c:2315
#, fuzzy, c-format
msgid ""
"%s (%s) - `%s' saved [%s/%s]\n"
"\n"
msgstr ""
"%s (%s) - '%s' gemt [%ld/%ld]\n"
"\n"

#: src/http.c:2372
#, fuzzy, c-format
msgid "%s (%s) - Connection closed at byte %s. "
msgstr "%s (%s) - Forbindelse lukket ved byte %ld. "

#: src/http.c:2381
#, fuzzy, c-format
msgid ""
"%s (%s) - `%s' saved [%s/%s])\n"
"\n"
msgstr ""
"%s (%s) - '%s' gemt [%ld/%ld]\n"
"\n"

#: src/http.c:2407
#, fuzzy, c-format
msgid "%s (%s) - Connection closed at byte %s/%s. "
msgstr "%s (%s) - Forbindelse lukket ved byte %ld/%ld. "

#: src/http.c:2421
#, fuzzy, c-format
msgid "%s (%s) - Read error at byte %s (%s)."
msgstr "%s (%s) - Læsefejl ved byte %ld (%s)."

#: src/http.c:2431
#, fuzzy, c-format
msgid "%s (%s) - Read error at byte %s/%s (%s). "
msgstr "%s (%s) - Læsefejl ved byte %ld/%ld (%s)."

#: src/init.c:342
#, c-format
msgid "%s: WGETRC points to %s, which doesn't exist.\n"
msgstr ""

#: src/init.c:395 src/netrc.c:277
#, c-format
msgid "%s: Cannot read %s (%s).\n"
msgstr "%s: Kan ikke læse %s (%s).\n"

#: src/init.c:413 src/init.c:419
#, c-format
msgid "%s: Error in %s at line %d.\n"
msgstr "%s: Fejl i %s på linje %d.\n"

#: src/init.c:451
#, c-format
msgid "%s: Warning: Both system and user wgetrc point to `%s'.\n"
msgstr "%s: Advarsel: Både systemets og brugerens wgetrc peger på '%s'.\n"

#: src/init.c:595
#, fuzzy, c-format
msgid "%s: Invalid --execute command `%s'\n"
msgstr "%s: Ugyldig specifikation '%s'\n"

#: src/init.c:631
#, fuzzy, c-format
msgid "%s: %s: Invalid boolean `%s', use `on' or `off'.\n"
msgstr "%s: %s: Venligst angiv 'on' eller 'off'.\n"

#: src/init.c:674
#, fuzzy, c-format
msgid "%s: %s: Invalid boolean `%s', use always, on, off, or never.\n"
msgstr "%s: %s: Venligst angiv 'always', 'on' 'off', eller 'never'.\n"

#: src/init.c:693
#, fuzzy, c-format
msgid "%s: %s: Invalid number `%s'.\n"
msgstr "%s: %s: Ugyldig specifikation '%s'\n"

#: src/init.c:926 src/init.c:945
#, fuzzy, c-format
msgid "%s: %s: Invalid byte value `%s'\n"
msgstr "%s: %s: Ugyldig fremskridtstype '%s'\n"

#: src/init.c:970
#, fuzzy, c-format
msgid "%s: %s: Invalid time period `%s'\n"
msgstr "%s: %s: Ugyldig specifikation '%s'\n"

#: src/init.c:1037
#, fuzzy, c-format
msgid "%s: %s: Invalid header `%s'.\n"
msgstr "%s: %s: Ugyldig specifikation '%s'\n"

#: src/init.c:1083
#, c-format
msgid "%s: %s: Invalid progress type `%s'.\n"
msgstr "%s: %s: Ugyldig fremskridtstype '%s'\n"

#: src/init.c:1134
#, fuzzy, c-format
msgid "%s: %s: Invalid restriction `%s', use `unix' or `windows'.\n"
msgstr "%s: %s: Ugyldig specifikation '%s'\n"

#: src/init.c:1175
#, fuzzy, c-format
msgid "%s: %s: Invalid value `%s'.\n"
msgstr "%s: %s: Ugyldig specifikation '%s'\n"

#: src/log.c:777
#, c-format
msgid ""
"\n"
"%s received, redirecting output to `%s'.\n"
msgstr ""
"\n"
"%s modtaget, omdirigerer udskrifter til '%s'.\n"

#. Eek!  Opening the alternate log file has failed.  Nothing we
#. can do but disable printing completely.
#: src/log.c:787
#, fuzzy, c-format
msgid ""
"\n"
"%s received.\n"
msgstr "Ingen data modtaget"

#: src/log.c:788
#, c-format
msgid "%s: %s; disabling logging.\n"
msgstr "%s: %s; deaktiverer logning.\n"

#: src/main.c:363
#, c-format
msgid "Usage: %s [OPTION]... [URL]...\n"
msgstr "Brug: %s [FLAG]... [URL]...\n"

#: src/main.c:375
#, fuzzy
msgid ""
"Mandatory arguments to long options are mandatory for short options too.\n"
"\n"
msgstr ""
"\n"
"Obligatoriske argumenter til lange flag er obligatoriske også \n"
"for korte.\n"
"\n"

#: src/main.c:377
msgid "Startup:\n"
msgstr ""

#: src/main.c:379
msgid "  -V,  --version           display the version of Wget and exit.\n"
msgstr ""

#: src/main.c:381
msgid "  -h,  --help              print this help.\n"
msgstr ""

#: src/main.c:383
msgid "  -b,  --background        go to background after startup.\n"
msgstr ""

#: src/main.c:385
msgid "  -e,  --execute=COMMAND   execute a `.wgetrc'-style command.\n"
msgstr ""

#: src/main.c:389
msgid "Logging and input file:\n"
msgstr ""

#: src/main.c:391
msgid "  -o,  --output-file=FILE    log messages to FILE.\n"
msgstr ""

#: src/main.c:393
msgid "  -a,  --append-output=FILE  append messages to FILE.\n"
msgstr ""

#: src/main.c:396
msgid "  -d,  --debug               print lots of debugging information.\n"
msgstr ""

#: src/main.c:399
msgid "  -q,  --quiet               quiet (no output).\n"
msgstr ""

#: src/main.c:401
msgid "  -v,  --verbose             be verbose (this is the default).\n"
msgstr ""

#: src/main.c:403
msgid ""
"  -nv, --no-verbose          turn off verboseness, without being quiet.\n"
msgstr ""

#: src/main.c:405
msgid "  -i,  --input-file=FILE     download URLs found in FILE.\n"
msgstr ""

#: src/main.c:407
msgid "  -F,  --force-html          treat input file as HTML.\n"
msgstr ""

#: src/main.c:409
msgid ""
"  -B,  --base=URL            prepends URL to relative links in -F -i file.\n"
msgstr ""

#: src/main.c:413
msgid "Download:\n"
msgstr ""

#: src/main.c:415
msgid ""
"  -t,  --tries=NUMBER            set number of retries to NUMBER (0 "
"unlimits).\n"
msgstr ""

#: src/main.c:417
msgid "       --retry-connrefused       retry even if connection is refused.\n"
msgstr ""

#: src/main.c:419
msgid "  -O,  --output-document=FILE    write documents to FILE.\n"
msgstr ""

#: src/main.c:421
msgid ""
"  -nc, --no-clobber              skip downloads that would download to\n"
"                                 existing files.\n"
msgstr ""

#: src/main.c:424
msgid ""
"  -c,  --continue                resume getting a partially-downloaded "
"file.\n"
msgstr ""

#: src/main.c:426
msgid "       --progress=TYPE           select progress gauge type.\n"
msgstr ""

#: src/main.c:428
msgid ""
"  -N,  --timestamping            don't re-retrieve files unless newer than\n"
"                                 local.\n"
msgstr ""

#: src/main.c:431
msgid "  -S,  --server-response         print server response.\n"
msgstr ""

#: src/main.c:433
msgid "       --spider                  don't download anything.\n"
msgstr ""

#: src/main.c:435
msgid "  -T,  --timeout=SECONDS         set all timeout values to SECONDS.\n"
msgstr ""

#: src/main.c:437
msgid "       --dns-timeout=SECS        set the DNS lookup timeout to SECS.\n"
msgstr ""

#: src/main.c:439
msgid "       --connect-timeout=SECS    set the connect timeout to SECS.\n"
msgstr ""

#: src/main.c:441
msgid "       --read-timeout=SECS       set the read timeout to SECS.\n"
msgstr ""

#: src/main.c:443
msgid "  -w,  --wait=SECONDS            wait SECONDS between retrievals.\n"
msgstr ""

#: src/main.c:445
msgid ""
"       --waitretry=SECONDS       wait 1..SECONDS between retries of a "
"retrieval.\n"
msgstr ""

#: src/main.c:447
msgid ""
"       --random-wait             wait from 0...2*WAIT secs between "
"retrievals.\n"
msgstr ""

#: src/main.c:449
msgid "  -Y,  --proxy                   explicitly turn on proxy.\n"
msgstr ""

#: src/main.c:451
msgid "       --no-proxy                explicitly turn off proxy.\n"
msgstr ""

#: src/main.c:453
msgid "  -Q,  --quota=NUMBER            set retrieval quota to NUMBER.\n"
msgstr ""

#: src/main.c:455
msgid ""
"       --bind-address=ADDRESS    bind to ADDRESS (hostname or IP) on local "
"host.\n"
msgstr ""

#: src/main.c:457
msgid "       --limit-rate=RATE         limit download rate to RATE.\n"
msgstr ""

#: src/main.c:459
msgid "       --no-dns-cache            disable caching DNS lookups.\n"
msgstr ""

#: src/main.c:461
msgid ""
"       --restrict-file-names=OS  restrict chars in file names to ones OS "
"allows.\n"
msgstr ""

#: src/main.c:464
msgid "  -4,  --inet4-only              connect only to IPv4 addresses.\n"
msgstr ""

#: src/main.c:466
msgid "  -6,  --inet6-only              connect only to IPv6 addresses.\n"
msgstr ""

#: src/main.c:471
#, fuzzy
msgid "Directories:\n"
msgstr "Katalog     "

#: src/main.c:473
msgid "  -nd, --no-directories           don't create directories.\n"
msgstr ""

#: src/main.c:475
msgid "  -x,  --force-directories        force creation of directories.\n"
msgstr ""

#: src/main.c:477
msgid "  -nH, --no-host-directories      don't create host directories.\n"
msgstr ""

#: src/main.c:479
msgid "       --protocol-directories     use protocol name in directories.\n"
msgstr ""

#: src/main.c:481
msgid "  -P,  --directory-prefix=PREFIX  save files to PREFIX/...\n"
msgstr ""

#: src/main.c:483
msgid ""
"       --cut-dirs=NUMBER          ignore NUMBER remote directory "
"components.\n"
msgstr ""

#: src/main.c:487
msgid "HTTP options:\n"
msgstr ""

#: src/main.c:489
msgid "       --http-user=USER        set http user to USER.\n"
msgstr ""

#: src/main.c:491
msgid "       --http-passwd=PASS      set http password to PASS.\n"
msgstr ""

#: src/main.c:493
msgid "       --no-cache              disallow server-cached data.\n"
msgstr ""

#: src/main.c:495
msgid ""
"  -E,  --html-extension        save HTML documents with `.html' extension.\n"
msgstr ""

#: src/main.c:497
msgid "       --ignore-length         ignore `Content-Length' header field.\n"
msgstr ""

#: src/main.c:499
msgid "       --header=STRING         insert STRING among the headers.\n"
msgstr ""

#: src/main.c:501
msgid "       --proxy-user=USER       set USER as proxy username.\n"
msgstr ""

#: src/main.c:503
msgid "       --proxy-passwd=PASS     set PASS as proxy password.\n"
msgstr ""

#: src/main.c:505
msgid ""
"       --referer=URL           include `Referer: URL' header in HTTP "
"request.\n"
msgstr ""

#: src/main.c:507
msgid "       --save-headers          save the HTTP headers to file.\n"
msgstr ""

#: src/main.c:509
msgid ""
"  -U,  --user-agent=AGENT      identify as AGENT instead of Wget/VERSION.\n"
msgstr ""

#: src/main.c:511
msgid ""
"       --no-http-keep-alive    disable HTTP keep-alive (persistent "
"connections).\n"
msgstr ""

#: src/main.c:513
msgid "       --no-cookies            don't use cookies.\n"
msgstr ""

#: src/main.c:515
msgid "       --load-cookies=FILE     load cookies from FILE before session.\n"
msgstr ""

#: src/main.c:517
msgid "       --save-cookies=FILE     save cookies to FILE after session.\n"
msgstr ""

#: src/main.c:519
msgid ""
"       --keep-session-cookies  load and save session (non-permanent) "
"cookies.\n"
msgstr ""

#: src/main.c:521
msgid ""
"       --post-data=STRING      use the POST method; send STRING as the "
"data.\n"
msgstr ""

#: src/main.c:523
msgid ""
"       --post-file=FILE        use the POST method; send contents of FILE.\n"
msgstr ""

#: src/main.c:528
msgid "HTTPS (SSL) options:\n"
msgstr ""

#: src/main.c:530
msgid "       --sslcertfile=FILE    optional client certificate.\n"
msgstr ""

#: src/main.c:532
msgid "       --sslcertkey=KEYFILE  optional keyfile for this certificate.\n"
msgstr ""

#: src/main.c:534
msgid "       --sslcadir=DIR        dir where hash list of CA's are stored.\n"
msgstr ""

#: src/main.c:536
msgid "       --sslcafile=FILE      file with bundle of CA's.\n"
msgstr ""

#: src/main.c:538
msgid ""
"       --sslcerttype=0/1     Client-Cert type 0=PEM (default) / 1=ASN1 "
"(DER).\n"
msgstr ""

#: src/main.c:540
msgid "       --sslcheckcert=0/1    Check the server cert against given CA.\n"
msgstr ""

#: src/main.c:542
msgid ""
"       --sslprotocol=0-3     choose SSL protocol; 0=automatic,\n"
"                             1=SSLv2 2=SSLv3 3=TLSv1.\n"
msgstr ""

#: src/main.c:545
msgid "       --egd-file=FILE       file name of the EGD socket.\n"
msgstr ""

#: src/main.c:550
msgid "FTP options:\n"
msgstr ""

#: src/main.c:552
msgid "       --no-remove-listing     don't remove `.listing' files.\n"
msgstr ""

#: src/main.c:554
msgid "       --no-glob               turn off FTP file name globbing.\n"
msgstr ""

#: src/main.c:556
msgid "       --no-passive-ftp        disable the \"passive\" transfer mode.\n"
msgstr ""

#: src/main.c:558
msgid ""
"       --retr-symlinks         when recursing, get linked-to files (not "
"dir).\n"
msgstr ""

#: src/main.c:560
msgid "       --preserve-permissions  preserve remote file permissions.\n"
msgstr ""

#: src/main.c:564
msgid "Recursive download:\n"
msgstr ""

#: src/main.c:566
msgid "  -r,  --recursive          specify recursive download.\n"
msgstr ""

#: src/main.c:568
msgid ""
"  -l,  --level=NUMBER       maximum recursion depth (inf or 0 for "
"infinite).\n"
msgstr ""

#: src/main.c:570
msgid ""
"       --delete-after       delete files locally after downloading them.\n"
msgstr ""

#: src/main.c:572
msgid ""
"  -k,  --convert-links      make links in downloaded HTML point to local "
"files.\n"
msgstr ""

#: src/main.c:574
msgid ""
"  -K,  --backup-converted   before converting file X, back up as X.orig.\n"
msgstr ""

#: src/main.c:576
msgid ""
"  -m,  --mirror             shortcut option equivalent to -r -N -l inf -nr.\n"
msgstr ""

#: src/main.c:578
msgid ""
"  -p,  --page-requisites    get all images, etc. needed to display HTML "
"page.\n"
msgstr ""

#: src/main.c:580
msgid ""
"       --strict-comments    turn on strict (SGML) handling of HTML "
"comments.\n"
msgstr ""

#: src/main.c:584
msgid "Recursive accept/reject:\n"
msgstr ""

#: src/main.c:586
msgid ""
"  -A,  --accept=LIST               comma-separated list of accepted "
"extensions.\n"
msgstr ""

#: src/main.c:588
msgid ""
"  -R,  --reject=LIST               comma-separated list of rejected "
"extensions.\n"
msgstr ""

#: src/main.c:590
msgid ""
"  -D,  --domains=LIST              comma-separated list of accepted "
"domains.\n"
msgstr ""

#: src/main.c:592
msgid ""
"       --exclude-domains=LIST      comma-separated list of rejected "
"domains.\n"
msgstr ""

#: src/main.c:594
msgid ""
"       --follow-ftp                follow FTP links from HTML documents.\n"
msgstr ""

#: src/main.c:596
msgid ""
"       --follow-tags=LIST          comma-separated list of followed HTML "
"tags.\n"
msgstr ""

#: src/main.c:598
msgid ""
"       --ignore-tags=LIST          comma-separated list of ignored HTML "
"tags.\n"
msgstr ""

#: src/main.c:600
msgid ""
"  -H,  --span-hosts                go to foreign hosts when recursive.\n"
msgstr ""

#: src/main.c:602
msgid "  -L,  --relative                  follow relative links only.\n"
msgstr ""

#: src/main.c:604
msgid "  -I,  --include-directories=LIST  list of allowed directories.\n"
msgstr ""

#: src/main.c:606
msgid "  -X,  --exclude-directories=LIST  list of excluded directories.\n"
msgstr ""

#: src/main.c:608
msgid ""
"  -np, --no-parent                 don't ascend to the parent directory.\n"
msgstr ""

#: src/main.c:612
msgid "Mail bug reports and suggestions to <bug-wget@gnu.org>.\n"
msgstr "Rapportér fejl og send forslag til <bug-wget@gnu.org>.\n"

#: src/main.c:617
#, c-format
msgid "GNU Wget %s, a non-interactive network retriever.\n"
msgstr "GNU Wget %s, en ikke-interaktiv informationsagent.\n"

#: src/main.c:631
#, fuzzy
msgid "Copyright (C) 2005 Free Software Foundation, Inc.\n"
msgstr ""
"Ophavsret © 1995, 1996, 1997, 1998, 2000, 2001 Free Software Foundation, "
"Inc.\n"

#: src/main.c:633
msgid ""
"This program is distributed in the hope that it will be useful,\n"
"but WITHOUT ANY WARRANTY; without even the implied warranty of\n"
"MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the\n"
"GNU General Public License for more details.\n"
msgstr ""
"Dette program distribueres i håb om at det bliver fundet nyttigt,\n"
"men UDEN NOGEN GARANTIER; ikke engang for SALGBARHED eller\n"
"EGNETHED TIL NOGEN SPECIEL OPGAVE.\n"
"Se 'GNU General Public License' for detaljer.\n"

#: src/main.c:638
#, fuzzy
msgid ""
"\n"
"Originally written by Hrvoje Niksic <hniksic@xemacs.org>.\n"
msgstr ""
"\n"
"Oprindeligt skrevet af Hrvoje Niksic <hniksic@arsdigita.com>.\n"

#. #### Something nicer should be printed here -- similar to the
#. pre-1.5 `--help' page.
#: src/main.c:684 src/main.c:753 src/main.c:832
#, c-format
msgid "Try `%s --help' for more options.\n"
msgstr "Prøv '%s --help' for flere flag.\n"

#: src/main.c:750
#, c-format
msgid "%s: illegal option -- `-n%c'\n"
msgstr "%s: ugyldigt flag -- '-n%c'\n"

#: src/main.c:803
#, c-format
msgid "Can't be verbose and quiet at the same time.\n"
msgstr "Kan ikke være udførlig og stille på samme tid.\n"

#: src/main.c:809
#, c-format
msgid "Can't timestamp and not clobber old files at the same time.\n"
msgstr ""
"Kan ikke tidsstemple og lade være at berøre eksisterende filer på samme "
"tid.\n"

#: src/main.c:817
#, c-format
msgid "Cannot specify both --inet4-only and --inet6-only.\n"
msgstr ""

#. No URL specified.
#: src/main.c:827
#, c-format
msgid "%s: missing URL\n"
msgstr "%s: URL mangler.\n"

#: src/main.c:936
#, c-format
msgid "No URLs found in %s.\n"
msgstr "Fandt ingen URLer i %s.\n"

#: src/main.c:945
#, c-format
msgid ""
"\n"
