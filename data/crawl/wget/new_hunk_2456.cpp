#. No need to print this output if the body won't be
#. downloaded at all, or if the original server response is
#. printed.
#: src/http.c:2164
msgid "Length: "
msgstr "Length: "

#: src/http.c:2184
msgid "ignored"
msgstr "ignored"

#: src/http.c:2255
#, fuzzy, c-format
msgid "Saving to: `%s'\n"
msgstr ".`%s' היקית טימשמ\n"

#: src/http.c:2335
msgid "Warning: wildcards not supported in HTTP.\n"
msgstr ".HTTP-ב םיכמתנ םניא (wildcards) הללכה יות :הרהזא\n"

#: src/http.c:2364
msgid "Spider mode enabled. Check if remote file exists.\n"
msgstr ""

#: src/http.c:2450
#, c-format
msgid "Cannot write to `%s' (%s).\n"
msgstr ".`%s' תביתכב (%s) הלקת\n"

#. Another fatal error.
#: src/http.c:2459
msgid "Unable to establish SSL connection.\n"
msgstr ".(SSL) חטבואמ רשק ץורע םיקהל ןתינ אל\n"

#: src/http.c:2467
#, c-format
msgid "ERROR: Redirection (%d) without location.\n"
msgstr ".רתא םש אלל בותינ (%d) יוניש :הלקת\n"

#: src/http.c:2505
msgid "Remote file does not exist -- broken link!!!\n"
msgstr ""

#: src/http.c:2510
#, c-format
msgid "%s ERROR %d: %s.\n"
msgstr "%s ERROR %d: %s.\n"

#: src/http.c:2526
msgid "Last-modified header missing -- time-stamps turned off.\n"
msgstr ".תונימז ויהי אל ןמז תומיתח -- האצמנ אל ןורחא יוניש ןמז תרתוכ\n"

#: src/http.c:2534
msgid "Last-modified header invalid -- time-stamp ignored.\n"
msgstr ".ןמזה תמיתחמ םלעתמ -- היוגש ןורחא יוניש ןמז תרתוכ\n"

#: src/http.c:2558
#, c-format
msgid ""
"Server file no newer than local file `%s' -- not retrieving.\n"
"\n"
msgstr ""
".ךשמיי אל ץבוקה -- `%s' ימוקמ ץבוקמ רתוי ינכדע וניא תרשב ץבוק\n"
"\n"

#: src/http.c:2566
#, fuzzy, c-format
msgid "The sizes do not match (local %s) -- retrieving.\n"
msgstr ".ךשמיי ץבוקה -- (%ld :ימוקמ ץבוק) ההז וניא לדוג\n"

#: src/http.c:2573
msgid "Remote file is newer, retrieving.\n"
msgstr ".ךשמיי ץבוקה ,רתוי ינכדע קחורמ ץבוק\n"

#: src/http.c:2596
#, fuzzy
msgid ""
"Remote file exists and could contain links to other resources -- "
"retrieving.\n"
"\n"
msgstr ".ךשמיי ץבוקה -- `%s' ימוקמ ץבוקמ רתוי ינכדע קחורמ ץבוק\n"

#: src/http.c:2602
#, fuzzy
msgid ""
"Remote file exists but does not contain any link -- not retrieving.\n"
"\n"
msgstr ".ךשמיי אל ץבוקה -- `%s' ימוקמ ץבוקמ רתוי ינכדע וניא קחורמ ץבוק\n"

#: src/http.c:2610
#, fuzzy
msgid ""
"Remote file exists but recursion is disabled -- not retrieving.\n"
"\n"
msgstr ".ךשמיי אל ץבוקה -- `%s' ימוקמ ץבוקמ רתוי ינכדע וניא קחורמ ץבוק\n"

# Come on, are they serious??
#: src/http.c:2652
#, fuzzy, c-format
msgid ""
"%s (%s) - `%s' saved [%s/%s]\n"
"\n"
msgstr ""
"%s (%s) - `%s' saved [%ld/%ld]\n"
"\n"

#: src/http.c:2707
#, fuzzy, c-format
msgid "%s (%s) - Connection closed at byte %s. "
msgstr ".רגסנ רוביחה ,%s-ב (%s) םיתב %ld ירחא הלקת "

#: src/http.c:2722
#, fuzzy, c-format
msgid "%s (%s) - Read error at byte %s (%s)."
msgstr ".%s-ב %s בצקב ולבקתנש םיתב %ld ירחא (%s) האירק תלקת"

#: src/http.c:2731
#, fuzzy, c-format
msgid "%s (%s) - Read error at byte %s/%s (%s). "
msgstr ".%s-ב %s בצקב ולבקתנש םיתב %ld/%ld ירחא (%s) האירק תלקת "

#: src/init.c:371
#, c-format
msgid "%s: WGETRC points to %s, which doesn't exist.\n"
msgstr ""

#: src/init.c:434 src/netrc.c:267
#, c-format
msgid "%s: Cannot read %s (%s).\n"
msgstr ".%s תינכת י\"ע %s ץבוק תחיתפב (%s) הלקת\n"

#: src/init.c:452
#, c-format
msgid "%s: Error in %s at line %d.\n"
msgstr ".%s תינכת רובע היוגש %s ץבוקב %d הרוש\n"

#: src/init.c:458
#, fuzzy, c-format
msgid "%s: Syntax error in %s at line %d.\n"
msgstr ".%s תינכת רובע היוגש %s ץבוקב %d הרוש\n"

# This message is under "ifdef DEBUG", so no need to translate it.
#: src/init.c:463
#, fuzzy, c-format
msgid "%s: Unknown command `%s' in %s at line %d.\n"
msgstr "%s: BUG: unknown command `%s', value `%s'.\n"

#: src/init.c:508
#, c-format
msgid "%s: Warning: Both system and user wgetrc point to `%s'.\n"
msgstr "%s: שמתשמה לש ןהו תכרעמה לש ןה wgetrc ץבוקכ שמשמ `%s' :הרהזא\n"

#: src/init.c:661
#, fuzzy, c-format
msgid "%s: Invalid --execute command `%s'\n"
msgstr ".%s הארוהב `%s' יוגש ךרע\n"

#: src/init.c:706
#, fuzzy, c-format
msgid "%s: %s: Invalid boolean `%s'; use `on' or `off'.\n"
msgstr "%s: דבלב off וא on םיכרע תלבקמ %s הארוה\n"

#: src/init.c:723
#, fuzzy, c-format
msgid "%s: %s: Invalid number `%s'.\n"
msgstr "%s: %s הארוהב `%s' יוגש ךרע\n"

#: src/init.c:954 src/init.c:973
#, fuzzy, c-format
msgid "%s: %s: Invalid byte value `%s'\n"
msgstr "%s: %s הארוהב `%s' יוגש ךרע\n"

#: src/init.c:998
#, fuzzy, c-format
msgid "%s: %s: Invalid time period `%s'\n"
msgstr "%s: %s הארוהב `%s' יוגש ךרע\n"

#: src/init.c:1052 src/init.c:1142 src/init.c:1245 src/init.c:1270
#, fuzzy, c-format
msgid "%s: %s: Invalid value `%s'.\n"
msgstr "%s: %s הארוהב `%s' יוגש ךרע\n"

#: src/init.c:1089
#, fuzzy, c-format
msgid "%s: %s: Invalid header `%s'.\n"
msgstr "%s: %s הארוהב `%s' יוגש ךרע\n"

#: src/init.c:1155
#, fuzzy, c-format
msgid "%s: %s: Invalid progress type `%s'.\n"
msgstr "%s: %s הארוהב `%s' יוגש ךרע\n"

#: src/init.c:1214
#, c-format
msgid ""
"%s: %s: Invalid restriction `%s', use [unix|windows],[lowercase|uppercase],"
"[nocontrol].\n"
msgstr ""

#: src/log.c:783
#, fuzzy, c-format
msgid ""
"\n"
"%s received, redirecting output to `%s'.\n"
msgstr "%s ולבקתה ,`%%s'-ל טלפ תיינפה\n"

#. Eek!  Opening the alternate log file has failed.  Nothing we
#. can do but disable printing completely.
#: src/log.c:793
#, fuzzy, c-format
msgid ""
"\n"
"%s received.\n"
msgstr "טלק ינותנ ולבקתה אל"

#: src/log.c:794
#, c-format
msgid "%s: %s; disabling logging.\n"
msgstr ""

#: src/main.c:353
#, c-format
msgid "Usage: %s [OPTION]... [URL]...\n"
msgstr "%s [ןייפאמ]... [URL]... :שומיש ןפוא\n"

#: src/main.c:365
#, fuzzy
msgid ""
"Mandatory arguments to long options are mandatory for short options too.\n"
"\n"
msgstr ""
"\n"
".םירצק םינייפאמל םג םייחרכה ,םיכורא םינייפאמל םייחרכהה םיטנמוגרא\n"
"\n"

#: src/main.c:367
msgid "Startup:\n"
msgstr ""

#: src/main.c:369
msgid "  -V,  --version           display the version of Wget and exit.\n"
msgstr ""

#: src/main.c:371
msgid "  -h,  --help              print this help.\n"
msgstr ""

#: src/main.c:373
msgid "  -b,  --background        go to background after startup.\n"
msgstr ""

#: src/main.c:375
msgid "  -e,  --execute=COMMAND   execute a `.wgetrc'-style command.\n"
msgstr ""

#: src/main.c:379
msgid "Logging and input file:\n"
msgstr ""

#: src/main.c:381
msgid "  -o,  --output-file=FILE    log messages to FILE.\n"
msgstr ""

#: src/main.c:383
msgid "  -a,  --append-output=FILE  append messages to FILE.\n"
msgstr ""

#: src/main.c:386
msgid "  -d,  --debug               print lots of debugging information.\n"
msgstr ""

#: src/main.c:389
msgid "  -q,  --quiet               quiet (no output).\n"
msgstr ""

#: src/main.c:391
msgid "  -v,  --verbose             be verbose (this is the default).\n"
msgstr ""

#: src/main.c:393
msgid ""
"  -nv, --no-verbose          turn off verboseness, without being quiet.\n"
msgstr ""

#: src/main.c:395
msgid "  -i,  --input-file=FILE     download URLs found in FILE.\n"
msgstr ""

#: src/main.c:397
msgid "  -F,  --force-html          treat input file as HTML.\n"
msgstr ""

#: src/main.c:399
msgid ""
"  -B,  --base=URL            prepends URL to relative links in -F -i file.\n"
msgstr ""

#: src/main.c:403
msgid "Download:\n"
msgstr ""

#: src/main.c:405
msgid ""
"  -t,  --tries=NUMBER            set number of retries to NUMBER (0 "
"unlimits).\n"
msgstr ""

#: src/main.c:407
msgid "       --retry-connrefused       retry even if connection is refused.\n"
msgstr ""

#: src/main.c:409
msgid "  -O,  --output-document=FILE    write documents to FILE.\n"
msgstr ""

#: src/main.c:411
msgid ""
"  -nc, --no-clobber              skip downloads that would download to\n"
"                                 existing files.\n"
msgstr ""

#: src/main.c:414
msgid ""
"  -c,  --continue                resume getting a partially-downloaded "
"file.\n"
msgstr ""

#: src/main.c:416
msgid "       --progress=TYPE           select progress gauge type.\n"
msgstr ""

#: src/main.c:418
msgid ""
"  -N,  --timestamping            don't re-retrieve files unless newer than\n"
"                                 local.\n"
msgstr ""

#: src/main.c:421
msgid "  -S,  --server-response         print server response.\n"
msgstr ""

#: src/main.c:423
msgid "       --spider                  don't download anything.\n"
msgstr ""

#: src/main.c:425
msgid "  -T,  --timeout=SECONDS         set all timeout values to SECONDS.\n"
msgstr ""

#: src/main.c:427
msgid "       --dns-timeout=SECS        set the DNS lookup timeout to SECS.\n"
msgstr ""

#: src/main.c:429
msgid "       --connect-timeout=SECS    set the connect timeout to SECS.\n"
msgstr ""

#: src/main.c:431
msgid "       --read-timeout=SECS       set the read timeout to SECS.\n"
msgstr ""

#: src/main.c:433
msgid "  -w,  --wait=SECONDS            wait SECONDS between retrievals.\n"
msgstr ""

#: src/main.c:435
msgid ""
"       --waitretry=SECONDS       wait 1..SECONDS between retries of a "
"retrieval.\n"
msgstr ""

#: src/main.c:437
msgid ""
"       --random-wait             wait from 0...2*WAIT secs between "
"retrievals.\n"
msgstr ""

#: src/main.c:439
msgid "  -Y,  --proxy                   explicitly turn on proxy.\n"
msgstr ""

#: src/main.c:441
msgid "       --no-proxy                explicitly turn off proxy.\n"
msgstr ""

#: src/main.c:443
msgid "  -Q,  --quota=NUMBER            set retrieval quota to NUMBER.\n"
msgstr ""

#: src/main.c:445
msgid ""
"       --bind-address=ADDRESS    bind to ADDRESS (hostname or IP) on local "
"host.\n"
msgstr ""

#: src/main.c:447
msgid "       --limit-rate=RATE         limit download rate to RATE.\n"
msgstr ""

#: src/main.c:449
msgid "       --no-dns-cache            disable caching DNS lookups.\n"
msgstr ""

#: src/main.c:451
msgid ""
"       --restrict-file-names=OS  restrict chars in file names to ones OS "
"allows.\n"
msgstr ""

#: src/main.c:453
msgid ""
"       --ignore-case             ignore case when matching files/"
"directories.\n"
msgstr ""

#: src/main.c:456
msgid "  -4,  --inet4-only              connect only to IPv4 addresses.\n"
msgstr ""

#: src/main.c:458
msgid "  -6,  --inet6-only              connect only to IPv6 addresses.\n"
msgstr ""

#: src/main.c:460
msgid ""
"       --prefer-family=FAMILY    connect first to addresses of specified "
"family,\n"
"                                 one of IPv6, IPv4, or none.\n"
msgstr ""

#: src/main.c:464
msgid "       --user=USER               set both ftp and http user to USER.\n"
msgstr ""

#: src/main.c:466
msgid ""
"       --password=PASS           set both ftp and http password to PASS.\n"
msgstr ""

#: src/main.c:470
#, fuzzy
msgid "Directories:\n"
msgstr "       היקית"

#: src/main.c:472
msgid "  -nd, --no-directories           don't create directories.\n"
msgstr ""

#: src/main.c:474
msgid "  -x,  --force-directories        force creation of directories.\n"
msgstr ""

#: src/main.c:476
msgid "  -nH, --no-host-directories      don't create host directories.\n"
msgstr ""

#: src/main.c:478
msgid "       --protocol-directories     use protocol name in directories.\n"
msgstr ""

#: src/main.c:480
msgid "  -P,  --directory-prefix=PREFIX  save files to PREFIX/...\n"
msgstr ""

#: src/main.c:482
msgid ""
"       --cut-dirs=NUMBER          ignore NUMBER remote directory "
"components.\n"
msgstr ""

#: src/main.c:486
msgid "HTTP options:\n"
msgstr ""

#: src/main.c:488
msgid "       --http-user=USER        set http user to USER.\n"
msgstr ""

#: src/main.c:490
msgid "       --http-password=PASS    set http password to PASS.\n"
msgstr ""

#: src/main.c:492
msgid "       --no-cache              disallow server-cached data.\n"
msgstr ""

#: src/main.c:494
msgid ""
"  -E,  --html-extension        save HTML documents with `.html' extension.\n"
msgstr ""

#: src/main.c:496
msgid "       --ignore-length         ignore `Content-Length' header field.\n"
msgstr ""

#: src/main.c:498
msgid "       --header=STRING         insert STRING among the headers.\n"
msgstr ""

#: src/main.c:500
msgid "       --max-redirect          maximum redirections allowed per page.\n"
msgstr ""

#: src/main.c:502
msgid "       --proxy-user=USER       set USER as proxy username.\n"
msgstr ""

#: src/main.c:504
msgid "       --proxy-password=PASS   set PASS as proxy password.\n"
msgstr ""

#: src/main.c:506
msgid ""
"       --referer=URL           include `Referer: URL' header in HTTP "
"request.\n"
msgstr ""

#: src/main.c:508
msgid "       --save-headers          save the HTTP headers to file.\n"
msgstr ""

#: src/main.c:510
msgid ""
"  -U,  --user-agent=AGENT      identify as AGENT instead of Wget/VERSION.\n"
msgstr ""

#: src/main.c:512
msgid ""
"       --no-http-keep-alive    disable HTTP keep-alive (persistent "
"connections).\n"
msgstr ""

#: src/main.c:514
msgid "       --no-cookies            don't use cookies.\n"
msgstr ""

#: src/main.c:516
msgid "       --load-cookies=FILE     load cookies from FILE before session.\n"
msgstr ""

#: src/main.c:518
msgid "       --save-cookies=FILE     save cookies to FILE after session.\n"
msgstr ""

#: src/main.c:520
msgid ""
"       --keep-session-cookies  load and save session (non-permanent) "
"cookies.\n"
msgstr ""

#: src/main.c:522
msgid ""
"       --post-data=STRING      use the POST method; send STRING as the "
"data.\n"
msgstr ""

#: src/main.c:524
msgid ""
"       --post-file=FILE        use the POST method; send contents of FILE.\n"
msgstr ""

#: src/main.c:526
msgid ""
"       --no-content-disposition  don't honor Content-Disposition header.\n"
msgstr ""

#: src/main.c:531
msgid "HTTPS (SSL/TLS) options:\n"
msgstr ""

#: src/main.c:533
msgid ""
"       --secure-protocol=PR     choose secure protocol, one of auto, SSLv2,\n"
"                                SSLv3, and TLSv1.\n"
msgstr ""

#: src/main.c:536
msgid ""
"       --no-check-certificate   don't validate the server's certificate.\n"
msgstr ""

#: src/main.c:538
msgid "       --certificate=FILE       client certificate file.\n"
msgstr ""

#: src/main.c:540
msgid "       --certificate-type=TYPE  client certificate type, PEM or DER.\n"
msgstr ""

#: src/main.c:542
msgid "       --private-key=FILE       private key file.\n"
msgstr ""

#: src/main.c:544
msgid "       --private-key-type=TYPE  private key type, PEM or DER.\n"
msgstr ""

#: src/main.c:546
msgid "       --ca-certificate=FILE    file with the bundle of CA's.\n"
msgstr ""

#: src/main.c:548
msgid ""
"       --ca-directory=DIR       directory where hash list of CA's is "
"stored.\n"
msgstr ""

#: src/main.c:550
msgid ""
"       --random-file=FILE       file with random data for seeding the SSL "
"PRNG.\n"
msgstr ""

#: src/main.c:552
msgid ""
"       --egd-file=FILE          file naming the EGD socket with random "
"data.\n"
msgstr ""

#: src/main.c:557
msgid "FTP options:\n"
msgstr ""

#: src/main.c:559
msgid "       --ftp-user=USER         set ftp user to USER.\n"
msgstr ""

#: src/main.c:561
msgid "       --ftp-password=PASS     set ftp password to PASS.\n"
msgstr ""

#: src/main.c:563
msgid "       --no-remove-listing     don't remove `.listing' files.\n"
msgstr ""

#: src/main.c:565
msgid "       --no-glob               turn off FTP file name globbing.\n"
msgstr ""

#: src/main.c:567
msgid "       --no-passive-ftp        disable the \"passive\" transfer mode.\n"
msgstr ""

#: src/main.c:569
msgid ""
"       --retr-symlinks         when recursing, get linked-to files (not "
"dir).\n"
msgstr ""

#: src/main.c:571
msgid "       --preserve-permissions  preserve remote file permissions.\n"
msgstr ""

#: src/main.c:575
msgid "Recursive download:\n"
msgstr ""

#: src/main.c:577
msgid "  -r,  --recursive          specify recursive download.\n"
msgstr ""

#: src/main.c:579
msgid ""
"  -l,  --level=NUMBER       maximum recursion depth (inf or 0 for "
"infinite).\n"
msgstr ""

#: src/main.c:581
msgid ""
"       --delete-after       delete files locally after downloading them.\n"
msgstr ""

#: src/main.c:583
msgid ""
"  -k,  --convert-links      make links in downloaded HTML point to local "
"files.\n"
msgstr ""

#: src/main.c:585
msgid ""
"  -K,  --backup-converted   before converting file X, back up as X.orig.\n"
msgstr ""

#: src/main.c:587
msgid ""
"  -m,  --mirror             shortcut for -N -r -l inf --no-remove-listing.\n"
msgstr ""

#: src/main.c:589
msgid ""
"  -p,  --page-requisites    get all images, etc. needed to display HTML "
"page.\n"
msgstr ""

#: src/main.c:591
msgid ""
"       --strict-comments    turn on strict (SGML) handling of HTML "
"comments.\n"
msgstr ""

#: src/main.c:595
msgid "Recursive accept/reject:\n"
msgstr ""

#: src/main.c:597
msgid ""
"  -A,  --accept=LIST               comma-separated list of accepted "
"extensions.\n"
msgstr ""

#: src/main.c:599
msgid ""
"  -R,  --reject=LIST               comma-separated list of rejected "
"extensions.\n"
msgstr ""

#: src/main.c:601
msgid ""
"  -D,  --domains=LIST              comma-separated list of accepted "
"domains.\n"
msgstr ""

#: src/main.c:603
msgid ""
"       --exclude-domains=LIST      comma-separated list of rejected "
"domains.\n"
msgstr ""

#: src/main.c:605
msgid ""
"       --follow-ftp                follow FTP links from HTML documents.\n"
msgstr ""

#: src/main.c:607
msgid ""
"       --follow-tags=LIST          comma-separated list of followed HTML "
"tags.\n"
msgstr ""

#: src/main.c:609
msgid ""
"       --ignore-tags=LIST          comma-separated list of ignored HTML "
"tags.\n"
msgstr ""

#: src/main.c:611
msgid ""
"  -H,  --span-hosts                go to foreign hosts when recursive.\n"
msgstr ""

#: src/main.c:613
msgid "  -L,  --relative                  follow relative links only.\n"
msgstr ""

#: src/main.c:615
msgid "  -I,  --include-directories=LIST  list of allowed directories.\n"
msgstr ""

#: src/main.c:617
msgid "  -X,  --exclude-directories=LIST  list of excluded directories.\n"
msgstr ""

#: src/main.c:619
msgid ""
"  -np, --no-parent                 don't ascend to the parent directory.\n"
msgstr ""

#: src/main.c:623
msgid "Mail bug reports and suggestions to <bug-wget@gnu.org>.\n"
msgstr "    .<bug-wget@gnu.org> תבותכל רופישל תועצהו (bugs) הלקת יחוויד וחלש\n"

#: src/main.c:628
#, c-format
msgid "GNU Wget %s, a non-interactive network retriever.\n"
msgstr ".ליעפמ תופתתשה אלל תשרהמ םיצבק תכישמ ,%s אסריג GNU Wget תינכת\n"

#: src/main.c:668
msgid "Copyright (C) 2007 Free Software Foundation, Inc.\n"
msgstr ""

#: src/main.c:670
msgid ""
"License GPLv3+: GNU GPL version 3 or later\n"
"<http://www.gnu.org/licenses/gpl.html>.\n"
"This is free software: you are free to change and redistribute it.\n"
"There is NO WARRANTY, to the extent permitted by law.\n"
msgstr ""

#: src/main.c:675
#, fuzzy
msgid ""
"\n"
"Originally written by Hrvoje Niksic <hniksic@xemacs.org>.\n"
msgstr ""
"\n"
".Hrvoje Niksic <hniksic@arsdigita.com> י\"ע רוקמב הבתכנ וז תינכת\n"

#: src/main.c:677
msgid "Currently maintained by Micah Cowan <micah@cowan.name>.\n"
msgstr ""

#. #### Something nicer should be printed here -- similar to the
#. pre-1.5 `--help' page.
#: src/main.c:724 src/main.c:793 src/main.c:890
#, c-format
msgid "Try `%s --help' for more options.\n"
msgstr ".רתוי בר עדימ תגצהל `%s --help' שיקהל הסנ\n"

#: src/main.c:790
#, c-format
msgid "%s: illegal option -- `-n%c'\n"
msgstr "%s: `-n%c' יוגש ןייפאמ\n"

#: src/main.c:845
#, c-format
msgid "Can't be verbose and quiet at the same time.\n"
msgstr ".הז תא הז םירתוס quiet-ו verbose\n"

#: src/main.c:851
#, c-format
msgid "Can't timestamp and not clobber old files at the same time.\n"
msgstr ".הז תא הז םירתוס ןורחא ןוכדע ןמז םושירו םימייק םיצבק לע הרימש\n"

#: src/main.c:859
#, c-format
msgid "Cannot specify both --inet4-only and --inet6-only.\n"
msgstr ""

#: src/main.c:869
#, c-format
msgid "Cannot specify -r, -p or -N if -O is given.\n"
msgstr ""

#: src/main.c:877
#, c-format
msgid "Cannot specify both -k and -O if multiple URLs are given.\n"
msgstr ""

#. No URL specified.
#: src/main.c:885
#, c-format
msgid "%s: missing URL\n"
msgstr "%s: רסח URL\n"

#: src/main.c:1005
#, c-format
msgid "No URLs found in %s.\n"
msgstr ".%s-ב URL ףא אצמנ אל\n"

#: src/main.c:1023
#, fuzzy, c-format
msgid ""
"FINISHED --%s--\n"
"Downloaded: %d files, %s in %s (%s)\n"
msgstr ""
"\n"
"--%s-- העשב םייתסה\n"
"םיתב %s ,םיצבק %d וכשמנ\n"

#: src/main.c:1032
#, fuzzy, c-format
msgid "Download quota of %s EXCEEDED!\n"
msgstr "!(םיתב %s) הכישמ תלבגממ הגירח\n"

#: src/mswindows.c:96
#, c-format
msgid "Continuing in background.\n"
msgstr ".עקרב ךישממ\n"

#: src/mswindows.c:289
#, fuzzy, c-format
msgid "Continuing in background, pid %lu.\n"
msgstr ".עקרב ךישממ\n"

#: src/mswindows.c:291 src/utils.c:326
#, c-format
msgid "Output will be written to `%s'.\n"
msgstr ".`%s'-ל בתכיי טלפ\n"

#: src/mswindows.c:459 src/mswindows.c:466
#, c-format
msgid "%s: Couldn't find usable socket driver.\n"
msgstr "%s: Couldn't find usable socket driver.\n"

#: src/netrc.c:375
#, c-format
msgid "%s: %s:%d: warning: \"%s\" token appears before any machine name\n"
msgstr "%s: %s:%d: בשחמה םש רדגוהש ינפל העיפומ \"%s\" חתפמ תלימ :הרהזא\n"

#: src/netrc.c:406
#, c-format
msgid "%s: %s:%d: unknown token \"%s\"\n"
msgstr "%s: %s:%d: \"%s\" תרכומ-יתלב חתפמ תלימ\n"

#: src/netrc.c:470
#, c-format
msgid "Usage: %s NETRC [HOSTNAME]\n"
msgstr "%s NETRC [חראמ-בשחמ םש]  :שומישה ןפוא\n"

#: src/netrc.c:480
#, c-format
msgid "%s: cannot stat %s: %s\n"
msgstr "%s תינכתב %s ץבוקל השיגב (%s) הלקת\n"

#. Still not random enough, presumably because neither /dev/random
#. nor EGD were available.  Try to seed OpenSSL's PRNG with libc
#. PRNG.  This is cryptographically weak and defeats the purpose
#. of using OpenSSL, which is why it is highly discouraged.
#: src/openssl.c:112
msgid "WARNING: using a weak random seed.\n"
msgstr ""

#: src/openssl.c:172
msgid "Could not seed PRNG; consider using --random-file.\n"
msgstr ""

#. If the user has specified --no-check-cert, we still want to warn
#. him about problems with the server's certificate.
#: src/openssl.c:487
msgid "ERROR"
msgstr ""

#: src/openssl.c:487
msgid "WARNING"
msgstr ""

#: src/openssl.c:496
#, c-format
msgid "%s: No certificate presented by %s.\n"
msgstr ""

#: src/openssl.c:517
#, c-format
msgid "%s: cannot verify %s's certificate, issued by `%s':\n"
msgstr ""

#: src/openssl.c:525
msgid "  Unable to locally verify the issuer's authority.\n"
msgstr ""

#: src/openssl.c:529
msgid "  Self-signed certificate encountered.\n"
msgstr ""

#: src/openssl.c:532
msgid "  Issued certificate not yet valid.\n"
msgstr ""

#: src/openssl.c:535
msgid "  Issued certificate has expired.\n"
msgstr ""

#: src/openssl.c:567
#, c-format
msgid ""
"%s: certificate common name `%s' doesn't match requested host name `%s'.\n"
msgstr ""

#: src/openssl.c:580
#, c-format
msgid "To connect to %s insecurely, use `--no-check-certificate'.\n"
msgstr ""

#. Align the [ skipping ... ] line with the dots.  To do
#. that, insert the number of spaces equal to the number of
#. digits in the skipped amount in K.
#: src/progress.c:238
#, fuzzy, c-format
msgid ""
"\n"
"%*s[ skipping %sK ]"
msgstr ""
"\n"
"          [ %dK לע גלדמ ]"

#: src/progress.c:452
#, fuzzy, c-format
msgid "Invalid dot style specification `%s'; leaving unchanged.\n"
msgstr ".%s הארוהב `%s' יוגש ךרע\n"

#. Translation note: "ETA" is English-centric, but this must
#. be short, ideally 3 chars.  Abbreviate if necessary.
#: src/progress.c:946
#, c-format
msgid "  eta %s"
msgstr ""

#. When the download is done, print the elapsed time.
#. Note to translators: this should not take up more room than
#. available here.  Abbreviate if necessary.
#: src/progress.c:961
msgid "   in "
msgstr ""

#. If no clock was found, it means that clock_getres failed for
#. the realtime clock.
#: src/ptimer.c:160
#, c-format
msgid "Cannot get REALTIME clock frequency: %s\n"
msgstr ""

#: src/recur.c:377
#, c-format
msgid "Removing %s since it should be rejected.\n"
msgstr ".קחמיי ןכ-לעו החדנ %s\n"

#: src/res.c:392
#, fuzzy, c-format
msgid "Cannot open %s: %s"
msgstr "ב (%s: %s) םירושיק תרמה תלקת\n"

#: src/res.c:544
msgid "Loading robots.txt; please ignore errors.\n"
msgstr ".האיגש תועדוהמ םלעתהל אנ ;robots.txt ץבוק ןעוט\n"

#: src/retr.c:651
#, fuzzy, c-format
msgid "Error parsing proxy URL %s: %s.\n"
msgstr "`%s'-ל הביתכב (%s) הלקת\n"

#: src/retr.c:659
#, fuzzy, c-format
msgid "Error in proxy URL %s: Must be HTTP.\n"
msgstr ".HTTP תויהל בייח :%s השרומ תרש\n"

#: src/retr.c:745
#, fuzzy, c-format
msgid "%d redirections exceeded.\n"
msgstr ".%s תינכתב תילגעמ היינפה התלגתה\n"

#: src/retr.c:880
msgid ""
"Giving up.\n"
"\n"
msgstr ""
"!ענכנ ינא\n"
"\n"

#: src/retr.c:880
msgid ""
"Retrying.\n"
"\n"
msgstr ""
".ףסונ ןויסנ\n"
"\n"

#: src/url.c:619
#, fuzzy
msgid "No error"
msgstr "ההוזמ-יתלב הלקת"

#: src/url.c:621
msgid "Unsupported scheme"
msgstr ""

#: src/url.c:623
msgid "Invalid host name"
msgstr "חראמ-בשחמ לש יוגש םש"

#: src/url.c:625
msgid "Bad port number"
msgstr ""

#: src/url.c:627
#, fuzzy
msgid "Invalid user name"
msgstr "חראמ-בשחמ לש יוגש םש"

#: src/url.c:629
msgid "Unterminated IPv6 numeric address"
msgstr ""

#: src/url.c:631
msgid "IPv6 addresses not supported"
msgstr ""

#: src/url.c:633
msgid "Invalid IPv6 numeric address"
msgstr ""

#. parent, no error
#: src/utils.c:324
#, fuzzy, c-format
msgid "Continuing in background, pid %d.\n"
msgstr ".עקרב ךישממ\n"

#: src/utils.c:372
#, c-format
msgid "Failed to unlink symlink `%s': %s\n"
msgstr "`%s' ילובמיס רושיק תקיחמב (%s) הלקת\n"

#: src/xmalloc.c:62
#, c-format
msgid "%s: %s: Failed to allocate %ld bytes; memory exhausted.\n"
msgstr ""

#~ msgid "Error in Set-Cookie, field `%s'"
#~ msgstr "יוגש Set-Cookie תרתוכ לש `%s' הדש"

#~ msgid "Syntax error in Set-Cookie at character `%c'.\n"
#~ msgstr ".`%c' ות תברקב Set-Cookie תרתוכ לש יוגש ריבחת\n"

#~ msgid "Connection to %s:%hu refused.\n"
#~ msgstr ".החדנ %s:%hu-ל תורשקתה ןויסנ\n"

#~ msgid "Will try connecting to %s:%hu.\n"
#~ msgstr ".%s:%hu-ל רשקתהל הסנמ\n"

#~ msgid ""
#~ "\n"
#~ "REST failed; will not truncate `%s'.\n"
#~ msgstr ""
#~ "\n"
#~ ".`%s' לש םדוק ןכות קוחמל יאשר ינניא ;הלשכנ REST תדוקפ\n"

#~ msgid " [%s to go]"
#~ msgstr " [%s דוע ראשנ]"

#~ msgid "Host not found"
#~ msgstr "אצמנ אל חראמ בשחמ"

#~ msgid "Failed to set up an SSL context\n"
#~ msgstr "(SSL) חטבואמ רודיש תביבס תריציב הלקת\n"

#~ msgid "Failed to load certificates from %s\n"
#~ msgstr "%s-מ (certificates) רושיא תויות תניעטב הלקת\n"

#~ msgid "Trying without the specified certificate\n"
#~ msgstr "תשרדנ רושיא תיות אלל ךישמהל ןויסנ\n"

#~ msgid "Failed to get certificate key from %s\n"
#~ msgstr "%s-מ רושיא חתפמ תלבקב הלקת\n"

#~ msgid "End of file while parsing headers.\n"
#~ msgstr ".תורתוכה חותינ ידכ ךות טלק רמג\n"

#~ msgid ""
#~ "\n"
#~ "Continued download failed on this file, which conflicts with `-c'.\n"
#~ "Refusing to truncate existing file `%s'.\n"
#~ "\n"
#~ msgstr ""
#~ "\n"
#~ ",ףקותב `-c' ןייפאמו תויה .הלשכנ הז ץבוק לש ךשמה-תכישמ\n"
#~ ".`%s' םייק ץבוק בתכשל יתורשפאב ןיא\n"
#~ "\n"

#~ msgid " (%s to go)"
#~ msgstr " (%s to go)"

#~ msgid "File `%s' already there, will not retrieve.\n"
#~ msgstr ".ךשמיי אל ןכ-לעו ,םייק רבכ `%s' ץבוק\n"

#~ msgid ""
#~ "%s (%s) - `%s' saved [%ld/%ld])\n"
#~ "\n"
#~ msgstr ""
#~ "%s (%s) - `%s' saved [%ld/%ld]\n"
#~ "\n"

#~ msgid "%s (%s) - Connection closed at byte %ld/%ld. "
#~ msgstr ".רגסנ רוביחה ,%s-ב (%s) םיתב %ld/%ld ירחא הלקת "

#~ msgid "%s: %s: Cannot convert `%s' to an IP address.\n"
#~ msgstr "%s: IP תבותכל הרמהל תנתינ הנניא %s תארוהב `%s'\n"

#~ msgid "%s: %s: Please specify always, on, off, or never.\n"
#~ msgstr "%s: never וא off ,on ,always םיכרע קר תלבקמ %s הארוה\n"

#~ msgid ""
#~ "Startup:\n"
#~ "  -V,  --version           display the version of Wget and exit.\n"
#~ "  -h,  --help              print this help.\n"
#~ "  -b,  --background        go to background after startup.\n"
#~ "  -e,  --execute=COMMAND   execute a `.wgetrc'-style command.\n"
#~ "\n"
#~ msgstr ""
#~ "                                                                     :"
#~ "לוחית\n"
#~ "                           תינכתה תסריג תא גצה  -V,  --version\n"
#~ "                               הז הרזע ךסמ גצה       --help\n"
#~ "                   לוחית רמגב עקרב הדובעל רובע  -b,  --background\n"
#~ "                       wgetrc ןונגסב הדוקפ עצב  -e,  --execute=COMMAND\n"
#~ "\n"

#~ msgid ""
#~ "Logging and input file:\n"
#~ "  -o,  --output-file=FILE     log messages to FILE.\n"
#~ "  -a,  --append-output=FILE   append messages to FILE.\n"
#~ "  -d,  --debug                print debug output.\n"
#~ "  -q,  --quiet                quiet (no output).\n"
#~ "  -v,  --verbose              be verbose (this is the default).\n"
#~ "  -nv, --non-verbose          turn off verboseness, without being quiet.\n"
#~ "  -i,  --input-file=FILE      download URLs found in FILE.\n"
#~ "  -F,  --force-html           treat input file as HTML.\n"
#~ "  -B,  --base=URL             prepends URL to relative links in -F -i "
#~ "file.\n"
#~ "       --sslcertfile=FILE     optional client certificate.\n"
#~ "       --sslcertkey=KEYFILE   optional keyfile for this certificate.\n"
#~ "\n"
#~ msgstr ""
#~ "                                                            :ןמויו טלק "
#~ "יצבק\n"
#~ "                         FILE ץבוקל תועדוה חלש  -o,  --output-file=FILE\n"
#~ "                        FILE ץבוקל תועדוה ףסוה  -a,  --append-"
#~ "output=FILE\n"
#~ "               תואיגש יופינב הרזעל תועדוה ספדה  -d,  --debug\n"
#~ "                       (תועדוה אלל) הטקש הלועפ  -q,  --quiet\n"
#~ "        (לדחמה תרירב יהוז)  ריבכמל תועדוה ספדה  -v,  --verbose\n"
#~ "     הטקש הלועפל רובעת לא ךא ,תועדוה יוביר לטב  -nv, --non-verbose\n"
#~ "               FILE ץבוק ךותמ הכישמל םי-URL חק  -i,  --input-file=FILE\n"
#~ "         HTML טמרופב וניה -i-ב טלק ץבוק יכ חנה  -F,  --force-html\n"
#~ " URL-ל םייסחי םניה -i-ל טנמוגראב םימושרה םיצבק  -B,  --base=URL\n"
#~ "             חוקל בשחמל רושיא ץבוק ןויצ תורשפא       --sslcertfile=FILE\n"
#~ "           הז רושיא רובע חתפמ ץבוק ןויצ תורשפא       --"
#~ "sslcertkey=KEYFILE\n"
#~ "\n"

#~ msgid ""
#~ "Download:\n"
#~ "       --bind-address=ADDRESS   bind to ADDRESS (hostname or IP) on local "
#~ "host.\n"
#~ "  -t,  --tries=NUMBER           set number of retries to NUMBER (0 "
#~ "unlimits).\n"
#~ "  -O   --output-document=FILE   write documents to FILE.\n"
#~ "  -nc, --no-clobber             don't clobber existing files or use .# "
#~ "suffixes.\n"
#~ "  -c,  --continue               resume getting a partially-downloaded "
#~ "file.\n"
#~ "       --dot-style=STYLE        set retrieval display style.\n"
#~ "  -N,  --timestamping           don't re-retrieve files unless newer than "
#~ "local.\n"
#~ "  -S,  --server-response        print server response.\n"
#~ "       --spider                 don't download anything.\n"
#~ "  -T,  --timeout=SECONDS        set the read timeout to SECONDS.\n"
#~ "  -w,  --wait=SECONDS           wait SECONDS between retrievals.\n"
#~ "       --waitretry=SECONDS      wait 1...SECONDS between retries of a "
#~ "retrieval.\n"
#~ "  -Y,  --proxy=on/off           turn proxy on or off.\n"
#~ "  -Q,  --quota=NUMBER           set retrieval quota to NUMBER.\n"
#~ "\n"
#~ msgstr ""
#~ "                                                               :םיצבק "
#~ "תכישמ\n"
#~ " ימוקמ בשחמב (IP וא בשחמ םש) ADDR תבותכל רשקתה       --bind-address=ADDR\n"
#~ "  (הלבגמ ןיא ועמשמ 0) תורשקתה תונויסנ רפסמ עבק  -t,  --tries=NUMBER\n"
#~ "                                FILE-ל טלפ חלש  -O   --output-"
#~ "document=FILE\n"
#~ "םהמ תואסרג המכ רומשת לאו םימייק םיצבק סורהת לא  -nc, --no-clobber\n"
#~ "             תקספה הב הדוקנהמ ץבוק דירוהל ךשמה  -c,  --continue\n"
#~ "                הכישמה תומדקתה תגוצת ןונגס עבק       --dot-style=STYLE\n"
#~ "  םיימוקמ םיצבקמ םינכדועמ םניאש םיצבק ךושמת לא  -N,  --timestamping\n"
#~ "                       תרשהמ םיעיגמה םירסמ גצה  -S,  --server-response\n"
#~ "                                  רבד ךושמת לא       --spider\n"
#~ "                     טלקל הנתמהל יברימ ןמז עבק  -T,  --timeout=SECONDS\n"
#~ "                         תוכישמ ןיב הייהשה עבק  -w,  --wait=SECONDS\n"
#~ "                   תונויסנ ןיב תוינש N דע ןתמה       --waitretry=N\n"
#~ "                     השרומ תרשב שמתשת לא\\שמתשה  -Y,  --proxy=on/off\n"
#~ "(הלבגמ ןיא ועמשמ 0) הכישמל םיתב תומכ תלבגמ עבק  -Q,  --quota=NUMBER\n"
#~ "\n"

#~ msgid ""
#~ "Directories:\n"
#~ "  -nd  --no-directories            don't create directories.\n"
#~ "  -x,  --force-directories         force creation of directories.\n"
#~ "  -nH, --no-host-directories       don't create host directories.\n"
#~ "  -P,  --directory-prefix=PREFIX   save files to PREFIX/...\n"
#~ "       --cut-dirs=NUMBER           ignore NUMBER remote directory "
#~ "components.\n"
#~ "\n"
#~ msgstr ""
#~ "                                                                    :"
#~ "תיקיות\n"
#~ "                         תושדח תויקית רוצית לא  -nd  --no-directories\n"
#~ "                       תושדח תויקית רוצית דימת  -x,  --force-directories\n"
#~ "    םיצבקה ודרוה ונממ רתאה םשב תויקית רוצית לא  -nH, --no-host-"
#~ "directories\n"
#~ "           PFX/... היקית תחת םיצבקה לכ תא רומש  -P,  --directory-"
#~ "prefix=PFX\n"
#~ "            תויקיתה תומשמ םינושאר םיקלח N טמשה       --cut-dirs=N\n"
#~ "\n"

#~ msgid ""
#~ "HTTP options:\n"
#~ "       --http-user=USER      set http user to USER.\n"
#~ "       --http-passwd=PASS    set http password to PASS.\n"
#~ "  -C,  --cache=on/off        (dis)allow server-cached data (normally "
#~ "allowed).\n"
#~ "  -E,  --html-extension      save all text/html documents with .html "
#~ "extension.\n"
#~ "       --ignore-length       ignore `Content-Length' header field.\n"
#~ "       --header=STRING       insert STRING among the headers.\n"
#~ "       --proxy-user=USER     set USER as proxy username.\n"
#~ "       --proxy-passwd=PASS   set PASS as proxy password.\n"
#~ "       --referer=URL         include `Referer: URL' header in HTTP "
#~ "request.\n"
#~ "  -s,  --save-headers        save the HTTP headers to file.\n"
#~ "  -U,  --user-agent=AGENT    identify as AGENT instead of Wget/VERSION.\n"
#~ "       --no-http-keep-alive  disable HTTP keep-alive (persistent "
#~ "connections).\n"
#~ "       --cookies=off         don't use cookies.\n"
#~ "       --load-cookies=FILE   load cookies from FILE before session.\n"
#~ "       --save-cookies=FILE   save cookies to FILE after session.\n"
#~ "\n"
#~ msgstr ""
#~ "                                                              :HTTP "
#~ "ינייפאמ\n"
#~ "                    HTTP שמתשמ לש ומש USER יהי       --http-user=USER\n"
#~ "                 HTTP שמתשמ לש ותמסיס PASS יהי       --http-passwd=PASS\n"
#~ "        תרשב ןומטמב ורמשנש םינותנ השרת לא\\השרה  -C,  --cache=on/off\n"
#~ "                     .html תמויס םיצבקה לכל ןת  -E,  --html-extension\n"
#~ "                 `Content-Length' תרתוכמ םלעתה       --ignore-length\n"
#~ "               תורתוכה ךותב STRING תזורחמ לותש       --header=STRING\n"
#~ "             השרומ תרשב שמתשמה לש ומש USER יהי       --proxy-user=USER\n"
#~ "          השרומ תרשב שמתשמה לש ותמסיס PASS יהי       --proxy-passwd=PASS\n"
#~ "         HTTP תיינפל `Referer: URL' תרתוכ ףסוה       --referer=URL\n"
#~ "                    טלפ יצבקב HTTP תורתוכ רומש  -s,  --save-headers\n"
#~ "   ליגרכ Wget/VERSION םוקמב AGENT תינכתכ ההדזה  -U,  --user-agent=AGENT\n"
#~ "     (דימתמ HTTP רוביח) keep-alive-ב שומיש לטב       --no-http-keep-"
#~ "alive\n"
#~ "                    (cookies) תויגועב שמתשת לא       --cookies=off\n"
#~ "       הדובעה תליחת ינפל FILE ץבוקמ תויגוע ןעט       --load-cookies=FILE\n"
#~ "            הדובעה רמגב FILE ץבוקב תויגוע רומש       --save-cookies=FILE\n"
#~ "\n"

#~ msgid ""
#~ "FTP options:\n"
#~ "  -nr, --dont-remove-listing   don't remove `.listing' files.\n"
#~ "  -g,  --glob=on/off           turn file name globbing on or off.\n"
#~ "       --passive-ftp           use the \"passive\" transfer mode.\n"
#~ "       --retr-symlinks         when recursing, get linked-to files (not "
#~ "dirs).\n"
#~ "\n"
#~ msgstr ""
#~ "                                                               :FTP "
#~ "ינייפאמ\n"
#~ "                          listing יצבק קחמת לא  -nr, --dont-remove-"
#~ "listing\n"
#~ "    םיצבק תומשב הבחרה יותב הכימת ליעפת לא\\לעפה  -g,  --glob=on/off\n"
#~ "             (\"PASV\") תיביספ הרבעה תטישב שמתשה       --passive-ftp\n"
#~ "   םירושיק לש הרטמ יצבק ךושמ ,תיביסרוקר הכישמב       --retr-symlinks\n"
#~ "\n"

#~ msgid ""
#~ "Recursive retrieval:\n"
#~ "  -r,  --recursive          recursive web-suck -- use with care!\n"
#~ "  -l,  --level=NUMBER       maximum recursion depth (inf or 0 for "
#~ "infinite).\n"
#~ "       --delete-after       delete files locally after downloading them.\n"
#~ "  -k,  --convert-links      convert non-relative links to relative.\n"
#~ "  -K,  --backup-converted   before converting file X, back up as X.orig.\n"
#~ "  -m,  --mirror             shortcut option equivalent to -r -N -l inf -"
#~ "nr.\n"
#~ "  -p,  --page-requisites    get all images, etc. needed to display HTML "
#~ "page.\n"
#~ "\n"
#~ msgstr ""
#~ "                                                           :תיביסרוקר "
#~ "הכישמ\n"
#~ "  (!תרהזוה האר !ןכוסמ) -- תיביסרוקר הכישמ רשפא  -r,  --recursive\n"
#~ "לבגומ-יתלב קמועל וא 0 ,היסרוקרל יברימ קמוע עבק  -l,  --level=NUMBER\n"
#~ "            הכישמ רמגב תימוקמ םיצבקה לכ תא קחמ       --delete-after\n"
#~ "                          םייסחיל םירושיק ךופה  -k,  --convert-links\n"
#~ "                הכיפה ינפל יוביגכ ץבוק לכ רומש  -K,  --backup-converted\n"
#~ "       -r -N -l inf -nr םינייפאמה ףוריצל רוציק  -m,  --mirror\n"
#~ "         HTML תגוצתל םישרדנה םיצבקה לכ תא ךושמ  -p,  --page-requisites\n"
#~ "\n"

#~ msgid ""
#~ "Recursive accept/reject:\n"
#~ "  -A,  --accept=LIST                comma-separated list of accepted "
#~ "extensions.\n"
#~ "  -R,  --reject=LIST                comma-separated list of rejected "
#~ "extensions.\n"
#~ "  -D,  --domains=LIST               comma-separated list of accepted "
#~ "domains.\n"
#~ "       --exclude-domains=LIST       comma-separated list of rejected "
#~ "domains.\n"
#~ "       --follow-ftp                 follow FTP links from HTML "
#~ "documents.\n"
#~ "       --follow-tags=LIST           comma-separated list of followed HTML "
#~ "tags.\n"
#~ "  -G,  --ignore-tags=LIST           comma-separated list of ignored HTML "
#~ "tags.\n"
#~ "  -H,  --span-hosts                 go to foreign hosts when recursive.\n"
#~ "  -L,  --relative                   follow relative links only.\n"
#~ "  -I,  --include-directories=LIST   list of allowed directories.\n"
#~ "  -X,  --exclude-directories=LIST   list of excluded directories.\n"
#~ "  -nh, --no-host-lookup             don't DNS-lookup hosts.\n"
#~ "  -np, --no-parent                  don't ascend to the parent "
#~ "directory.\n"
#~ "\n"
#~ msgstr ""
#~ "                                         :תיביסרוקר הכישמ תעב הייחד וא "
#~ "הלבק\n"
#~ "        םיקיספ י\"ע תודרפומ תורתומ תומויס תמישר  -A,  --accept=LIST\n"
#~ "        םיקיספ י\"ע תודרפומ תורוסא תומויס תמישר  -R,  --reject=LIST\n"
#~ "   םיקיספ י\"ע םידרפומ םירתומ םימוחת תומש תמישר  -D,  --domains=LIST\n"
#~ "   םיקיספ י\"ע םידרפומ םירוסא םימוחת תומש תמישר       --exclude-"
#~ "domains=LIS\n"
#~ "                 HTML יפדב FTP ירושיק רחא בוקע       --follow-ftp\n"
#~ " םיקיספ י\"ע םידרפומ בוקעל שי םהירחא HTML תמישר       --follow-tags=LIST\n"
#~ "                      םלעתהל שי םהמ HTML תמישר  -G,  --ignore-tags=LIST\n"
#~ "   םירחא םיבשחמל תשגל ןתינ תיביסרוקר הכישמ תעב  -H,  --span-hosts\n"
#~ "             יסחי םש ילעב םירושיק ירחא קר בוקע  -L,  --relative\n"
#~ "                           תורתומ תויקית תמישר  -I,  --include-"
#~ "directories=L\n"
#~ "                           תורוסא תויקית תמישר  -X,  --exclude-"
#~ "directories=L\n"
#~ "             תשרב םיבשחמ שופיחל DNS-ב שמתשת לא  -nh, --no-host-lookup\n"
#~ "                            בא תייקיתל הלעת לא  -np, --no-parent\n"
#~ "\n"

#~ msgid "%s: debug support not compiled in.\n"
#~ msgstr ".`--debug' ןייפאמב הכימת םע התנבנ אל %s תינכתה\n"

#~ msgid ""
#~ "Copyright (C) 1995, 1996, 1997, 1998, 2000, 2001 Free Software "
#~ "Foundation, Inc.\n"
#~ "This program is distributed in the hope that it will be useful,\n"
#~ "but WITHOUT ANY WARRANTY; without even the implied warranty of\n"
#~ "MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the\n"
#~ "GNU General Public License for more details.\n"
#~ msgstr ""
#~ "Copyright (C) 1995, 1996, 1997, 1998, 2000, 2001 Free Software "
#~ "Foundation, Inc.\n"
#~ "                                 ,תלעות איבת איהש הווקת ךותמ תצפומ וז "
#~ "תינכת\n"
#~ "                             עמתשמב-תוירחא אל וליפא ;תוירחא בתכ לכ אלל "
#~ "םלוא\n"
#~ "                             ,םיטרפל .תמיוסמ תילכת וזיאל המאתה וא תוריחס "
#~ "לש\n"
#~ "                                    .GNU General Public License-ב ונייע "
#~ "אנא\n"

#~ msgid "%s: %s: invalid command\n"
#~ msgstr "%s: %s היוגש הדוקפ\n"

#~ msgid ""
#~ "\n"
#~ "CTRL+Break received, redirecting output to `%s'.\n"
#~ "Execution continued in background.\n"
#~ "You may stop Wget by pressing CTRL+ALT+DELETE.\n"
#~ msgstr ""
#~ "\n"
#~ "       .`%s'-ל טלפ תיינפה ,CTRL+Break ץחלנ\n"
#~ "                        .עקרב ךשמיי עוציבה\n"
#~ ".CTRL+ALT+DELETE תשקה י\"ע Wget רוצעל ןתינ\n"

#~ msgid "Starting WinHelp %s\n"
#~ msgstr ".\"WinHelp %s\" ליעפמ\n"

#~ msgid "Could not find proxy host.\n"
#~ msgstr ".השרומ תרש אצמנ אל\n"

#~ msgid "%s: %s: Not enough memory.\n"
#~ msgstr ".%s תינכת לש %s הרגשב ןורכז קיפסמ ןיא\n"

#~ msgid "Unknown/unsupported protocol"
#~ msgstr "ךמתנ וניא וא רכומ-יתלב לוקוטורפ"

#~ msgid "Invalid port specification"
#~ msgstr "יוגש האיצי ןויצ"
