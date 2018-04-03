 "--%s-- העשב םייתסה\n"
 "םיתב %s ,םיצבק %d וכשמנ\n"
 
-#: src/main.c:842
+#: src/main.c:951
 #, c-format
 msgid "Download quota (%s bytes) EXCEEDED!\n"
 msgstr "!(םיתב %s) הכישמ תלבגממ הגירח\n"
 
-#. Please note that the double `%' in `%%s' is intentional, because
-#. redirect_output passes tmp through printf.
-#: src/main.c:876
+#: src/mswindows.c:235
 #, c-format
-msgid "%s received, redirecting output to `%%s'.\n"
-msgstr "%s ולבקתה ,`%%s'-ל טלפ תיינפה\n"
-
-#: src/mswindows.c:89
-#, c-format
-msgid ""
-"\n"
-"CTRL+Break received, redirecting output to `%s'.\n"
-"Execution continued in background.\n"
-"You may stop Wget by pressing CTRL+ALT+DELETE.\n"
-msgstr ""
-"\n"
-"       .`%s'-ל טלפ תיינפה ,CTRL+Break ץחלנ\n"
-"                        .עקרב ךשמיי עוציבה\n"
-".CTRL+ALT+DELETE תשקה י\"ע Wget רוצעל ןתינ\n"
-
-#. parent, no error
-#: src/mswindows.c:106 src/utils.c:458
 msgid "Continuing in background.\n"
 msgstr ".עקרב ךישממ\n"
 
-#: src/mswindows.c:108 src/utils.c:460
+#: src/mswindows.c:427
+#, fuzzy, c-format
+msgid "Continuing in background, pid %lu.\n"
+msgstr ".עקרב ךישממ\n"
+
+#: src/mswindows.c:429 src/utils.c:349
 #, c-format
 msgid "Output will be written to `%s'.\n"
 msgstr ".`%s'-ל בתכיי טלפ\n"
 
-#: src/mswindows.c:188
-#, c-format
-msgid "Starting WinHelp %s\n"
-msgstr ".\"WinHelp %s\" ליעפמ\n"
-
-#: src/mswindows.c:215 src/mswindows.c:222
+#: src/mswindows.c:597 src/mswindows.c:604
 #, c-format
 msgid "%s: Couldn't find usable socket driver.\n"
 msgstr "%s: Couldn't find usable socket driver.\n"
 
-#: src/netrc.c:367
+#: src/netrc.c:385
 #, c-format
 msgid "%s: %s:%d: warning: \"%s\" token appears before any machine name\n"
 msgstr "%s: %s:%d: בשחמה םש רדגוהש ינפל העיפומ \"%s\" חתפמ תלימ :הרהזא\n"
 
-#: src/netrc.c:398
+#: src/netrc.c:416
 #, c-format
 msgid "%s: %s:%d: unknown token \"%s\"\n"
 msgstr "%s: %s:%d: \"%s\" תרכומ-יתלב חתפמ תלימ\n"
 
-#: src/netrc.c:462
+#: src/netrc.c:480
 #, c-format
 msgid "Usage: %s NETRC [HOSTNAME]\n"
 msgstr "%s NETRC [חראמ-בשחמ םש]  :שומישה ןפוא\n"
 
-#: src/netrc.c:472
+#: src/netrc.c:490
 #, c-format
 msgid "%s: cannot stat %s: %s\n"
 msgstr "%s תינכתב %s ץבוקל השיגב (%s) הלקת\n"
 
-#: src/recur.c:484
+#. Align the [ skipping ... ] line with the dots.  To do
+#. that, insert the number of spaces equal to the number of
+#. digits in the skipped amount in K.
+#: src/progress.c:243
+#, fuzzy, c-format
+msgid ""
+"\n"
+"%*s[ skipping %dK ]"
+msgstr ""
+"\n"
+"          [ %dK לע גלדמ ]"
+
+#: src/progress.c:410
+#, fuzzy, c-format
+msgid "Invalid dot style specification `%s'; leaving unchanged.\n"
+msgstr ".%s הארוהב `%s' יוגש ךרע\n"
+
+#: src/recur.c:377
 #, c-format
 msgid "Removing %s since it should be rejected.\n"
 msgstr ".קחמיי ןכ-לעו החדנ %s\n"
 
-#: src/recur.c:679
+#: src/res.c:548
 msgid "Loading robots.txt; please ignore errors.\n"
 msgstr ".האיגש תועדוהמ םלעתהל אנ ;robots.txt ץבוק ןעוט\n"
 
-#: src/retr.c:227
-#, c-format
-msgid "\n          [ skipping %dK ]"
-msgstr "\n          [ %dK לע גלדמ ]"
-
-#: src/retr.c:373
-msgid "Could not find proxy host.\n"
-msgstr ".השרומ תרש אצמנ אל\n"
+#: src/retr.c:638
+#, fuzzy, c-format
+msgid "Error parsing proxy URL %s: %s.\n"
+msgstr "`%s'-ל הביתכב (%s) הלקת\n"
 
-#: src/retr.c:387
-#, c-format
-msgid "Proxy %s: Must be HTTP.\n"
+#: src/retr.c:646
+#, fuzzy, c-format
+msgid "Error in proxy URL %s: Must be HTTP.\n"
 msgstr ".HTTP תויהל בייח :%s השרומ תרש\n"
 
-#: src/retr.c:481
-#, c-format
-msgid "%s: Redirection cycle detected.\n"
+#: src/retr.c:731
+#, fuzzy, c-format
+msgid "%d redirections exceeded.\n"
 msgstr ".%s תינכתב תילגעמ היינפה התלגתה\n"
 
-#: src/retr.c:587
-msgid "Giving up.\n\n"
-msgstr "!ענכנ ינא\n\n"
+#: src/retr.c:856
+msgid ""
+"Giving up.\n"
+"\n"
+msgstr ""
+"!ענכנ ינא\n"
+"\n"
 
-#: src/retr.c:587
-msgid "Retrying.\n\n"
-msgstr ".ףסונ ןויסנ\n\n"
+#: src/retr.c:856
+msgid ""
+"Retrying.\n"
+"\n"
+msgstr ""
+".ףסונ ןויסנ\n"
+"\n"
 
-# Note: the following 5 messages are all written on the same line!
-#: src/url.c:1329
-#, c-format
-msgid "Converting %s... "
-msgstr "%s תרמה"
+#: src/url.c:642
+#, fuzzy
+msgid "No error"
+msgstr "ההוזמ-יתלב הלקת"
 
-#: src/url.c:1342
-msgid "nothing to do.\n"
-msgstr "ב ךרוצ ןיא\n"
+#: src/url.c:644
+msgid "Unsupported scheme"
+msgstr ""
 
-#: src/url.c:1350 src/url.c:1374
-#, c-format
-msgid "Cannot convert links in %s: %s\n"
-msgstr "ב (%s: %s) םירושיק תרמה תלקת\n"
+#: src/url.c:646
+msgid "Empty host"
+msgstr ""
 
-#: src/url.c:1365
-#, c-format
-msgid "Unable to delete `%s': %s\n"
-msgstr "`%s' קוחמל ןויסנב (%s) הלקת\n"
+#: src/url.c:648
+msgid "Bad port number"
+msgstr ""
 
-#: src/url.c:1555
-#, c-format
-msgid "Cannot back up %s as %s: %s\n"
-msgstr "%s-ל יוביגכ %s תביתכב (%s) הלקת\n"
+#: src/url.c:650
+#, fuzzy
+msgid "Invalid user name"
+msgstr "חראמ-בשחמ לש יוגש םש"
 
-#: src/utils.c:94
-#, c-format
-msgid "%s: %s: Not enough memory.\n"
-msgstr ".%s תינכת לש %s הרגשב ןורכז קיפסמ ןיא\n"
+#: src/url.c:652
+msgid "Unterminated IPv6 numeric address"
+msgstr ""
 
-#: src/utils.c:417
-msgid "Unknown/unsupported protocol"
-msgstr "ךמתנ וניא וא רכומ-יתלב לוקוטורפ"
+#: src/url.c:654
+msgid "IPv6 addresses not supported"
+msgstr ""
 
-#: src/utils.c:420
-msgid "Invalid port specification"
-msgstr "יוגש האיצי ןויצ"
+#: src/url.c:656
+msgid "Invalid IPv6 numeric address"
+msgstr ""
 
-#: src/utils.c:423
-msgid "Invalid host name"
-msgstr "חראמ-בשחמ לש יוגש םש"
+#. parent, no error
+#: src/utils.c:347
+#, fuzzy, c-format
+msgid "Continuing in background, pid %d.\n"
+msgstr ".עקרב ךישממ\n"
 
-#: src/utils.c:620
+#: src/utils.c:391
 #, c-format
 msgid "Failed to unlink symlink `%s': %s\n"
 msgstr "`%s' ילובמיס רושיק תקיחמב (%s) הלקת\n"
+
+#: src/xmalloc.c:72
+#, c-format
+msgid "%s: %s: Failed to allocate %ld bytes; memory exhausted.\n"
+msgstr ""
+
+#~ msgid "Syntax error in Set-Cookie at character `%c'.\n"
+#~ msgstr ".`%c' ות תברקב Set-Cookie תרתוכ לש יוגש ריבחת\n"
+
+#~ msgid "Connection to %s:%hu refused.\n"
+#~ msgstr ".החדנ %s:%hu-ל תורשקתה ןויסנ\n"
+
+#~ msgid "Will try connecting to %s:%hu.\n"
+#~ msgstr ".%s:%hu-ל רשקתהל הסנמ\n"
+
+#~ msgid ""
+#~ "\n"
+#~ "REST failed; will not truncate `%s'.\n"
+#~ msgstr ""
+#~ "\n"
+#~ ".`%s' לש םדוק ןכות קוחמל יאשר ינניא ;הלשכנ REST תדוקפ\n"
+
+#~ msgid " [%s to go]"
+#~ msgstr " [%s דוע ראשנ]"
+
+#~ msgid "Host not found"
+#~ msgstr "אצמנ אל חראמ בשחמ"
+
+#~ msgid "End of file while parsing headers.\n"
+#~ msgstr ".תורתוכה חותינ ידכ ךות טלק רמג\n"
+
+#~ msgid ""
+#~ "\n"
+#~ "Continued download failed on this file, which conflicts with `-c'.\n"
+#~ "Refusing to truncate existing file `%s'.\n"
+#~ "\n"
+#~ msgstr ""
+#~ "\n"
+#~ ",ףקותב `-c' ןייפאמו תויה .הלשכנ הז ץבוק לש ךשמה-תכישמ\n"
+#~ ".`%s' םייק ץבוק בתכשל יתורשפאב ןיא\n"
+#~ "\n"
+
+#~ msgid " (%s to go)"
+#~ msgstr " (%s to go)"
+
+# This message is under "ifdef DEBUG", so no need to translate it.
+#~ msgid "%s: BUG: unknown command `%s', value `%s'.\n"
+#~ msgstr "%s: BUG: unknown command `%s', value `%s'.\n"
+
+#~ msgid "%s: %s: Cannot convert `%s' to an IP address.\n"
+#~ msgstr "%s: IP תבותכל הרמהל תנתינ הנניא %s תארוהב `%s'\n"
+
+#~ msgid ""
+#~ "Startup:\n"
+#~ "  -V,  --version           display the version of Wget and exit.\n"
+#~ "  -h,  --help              print this help.\n"
+#~ "  -b,  --background        go to background after startup.\n"
+#~ "  -e,  --execute=COMMAND   execute a `.wgetrc'-style command.\n"
+#~ "\n"
+#~ msgstr ""
+#~ "                                                                     :"
+#~ "לוחית\n"
+#~ "                           תינכתה תסריג תא גצה  -V,  --version\n"
+#~ "                               הז הרזע ךסמ גצה       --help\n"
+#~ "                   לוחית רמגב עקרב הדובעל רובע  -b,  --background\n"
+#~ "                       wgetrc ןונגסב הדוקפ עצב  -e,  --execute=COMMAND\n"
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
+#~ "  -i,  --input-file=FILE      download URLs found in FILE.\n"
+#~ "  -F,  --force-html           treat input file as HTML.\n"
+#~ "  -B,  --base=URL             prepends URL to relative links in -F -i "
+#~ "file.\n"
+#~ "       --sslcertfile=FILE     optional client certificate.\n"
+#~ "       --sslcertkey=KEYFILE   optional keyfile for this certificate.\n"
+#~ "\n"
+#~ msgstr ""
+#~ "                                                            :ןמויו טלק "
+#~ "יצבק\n"
+#~ "                         FILE ץבוקל תועדוה חלש  -o,  --output-file=FILE\n"
+#~ "                        FILE ץבוקל תועדוה ףסוה  -a,  --append-"
+#~ "output=FILE\n"
+#~ "               תואיגש יופינב הרזעל תועדוה ספדה  -d,  --debug\n"
+#~ "                       (תועדוה אלל) הטקש הלועפ  -q,  --quiet\n"
+#~ "        (לדחמה תרירב יהוז)  ריבכמל תועדוה ספדה  -v,  --verbose\n"
+#~ "     הטקש הלועפל רובעת לא ךא ,תועדוה יוביר לטב  -nv, --non-verbose\n"
+#~ "               FILE ץבוק ךותמ הכישמל םי-URL חק  -i,  --input-file=FILE\n"
+#~ "         HTML טמרופב וניה -i-ב טלק ץבוק יכ חנה  -F,  --force-html\n"
+#~ " URL-ל םייסחי םניה -i-ל טנמוגראב םימושרה םיצבק  -B,  --base=URL\n"
+#~ "             חוקל בשחמל רושיא ץבוק ןויצ תורשפא       --sslcertfile=FILE\n"
+#~ "           הז רושיא רובע חתפמ ץבוק ןויצ תורשפא       --"
+#~ "sslcertkey=KEYFILE\n"
+#~ "\n"
+
+#~ msgid ""
+#~ "Download:\n"
+#~ "       --bind-address=ADDRESS   bind to ADDRESS (hostname or IP) on local "
+#~ "host.\n"
+#~ "  -t,  --tries=NUMBER           set number of retries to NUMBER (0 "
+#~ "unlimits).\n"
+#~ "  -O   --output-document=FILE   write documents to FILE.\n"
+#~ "  -nc, --no-clobber             don't clobber existing files or use .# "
+#~ "suffixes.\n"
+#~ "  -c,  --continue               resume getting a partially-downloaded "
+#~ "file.\n"
+#~ "       --dot-style=STYLE        set retrieval display style.\n"
+#~ "  -N,  --timestamping           don't re-retrieve files unless newer than "
+#~ "local.\n"
+#~ "  -S,  --server-response        print server response.\n"
+#~ "       --spider                 don't download anything.\n"
+#~ "  -T,  --timeout=SECONDS        set the read timeout to SECONDS.\n"
+#~ "  -w,  --wait=SECONDS           wait SECONDS between retrievals.\n"
+#~ "       --waitretry=SECONDS      wait 1...SECONDS between retries of a "
+#~ "retrieval.\n"
+#~ "  -Y,  --proxy=on/off           turn proxy on or off.\n"
+#~ "  -Q,  --quota=NUMBER           set retrieval quota to NUMBER.\n"
+#~ "\n"
+#~ msgstr ""
+#~ "                                                               :םיצבק "
+#~ "תכישמ\n"
+#~ " ימוקמ בשחמב (IP וא בשחמ םש) ADDR תבותכל רשקתה       --bind-address=ADDR\n"
+#~ "  (הלבגמ ןיא ועמשמ 0) תורשקתה תונויסנ רפסמ עבק  -t,  --tries=NUMBER\n"
+#~ "                                FILE-ל טלפ חלש  -O   --output-"
+#~ "document=FILE\n"
+#~ "םהמ תואסרג המכ רומשת לאו םימייק םיצבק סורהת לא  -nc, --no-clobber\n"
+#~ "             תקספה הב הדוקנהמ ץבוק דירוהל ךשמה  -c,  --continue\n"
+#~ "                הכישמה תומדקתה תגוצת ןונגס עבק       --dot-style=STYLE\n"
+#~ "  םיימוקמ םיצבקמ םינכדועמ םניאש םיצבק ךושמת לא  -N,  --timestamping\n"
+#~ "                       תרשהמ םיעיגמה םירסמ גצה  -S,  --server-response\n"
+#~ "                                  רבד ךושמת לא       --spider\n"
+#~ "                     טלקל הנתמהל יברימ ןמז עבק  -T,  --timeout=SECONDS\n"
+#~ "                         תוכישמ ןיב הייהשה עבק  -w,  --wait=SECONDS\n"
+#~ "                   תונויסנ ןיב תוינש N דע ןתמה       --waitretry=N\n"
+#~ "                     השרומ תרשב שמתשת לא\\שמתשה  -Y,  --proxy=on/off\n"
+#~ "(הלבגמ ןיא ועמשמ 0) הכישמל םיתב תומכ תלבגמ עבק  -Q,  --quota=NUMBER\n"
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
+#~ "                                                                    :"
+#~ "תיקיות\n"
+#~ "                         תושדח תויקית רוצית לא  -nd  --no-directories\n"
+#~ "                       תושדח תויקית רוצית דימת  -x,  --force-directories\n"
+#~ "    םיצבקה ודרוה ונממ רתאה םשב תויקית רוצית לא  -nH, --no-host-"
+#~ "directories\n"
+#~ "           PFX/... היקית תחת םיצבקה לכ תא רומש  -P,  --directory-"
+#~ "prefix=PFX\n"
+#~ "            תויקיתה תומשמ םינושאר םיקלח N טמשה       --cut-dirs=N\n"
+#~ "\n"
+
+#~ msgid ""
+#~ "HTTP options:\n"
+#~ "       --http-user=USER      set http user to USER.\n"
+#~ "       --http-passwd=PASS    set http password to PASS.\n"
+#~ "  -C,  --cache=on/off        (dis)allow server-cached data (normally "
+#~ "allowed).\n"
+#~ "  -E,  --html-extension      save all text/html documents with .html "
+#~ "extension.\n"
+#~ "       --ignore-length       ignore `Content-Length' header field.\n"
+#~ "       --header=STRING       insert STRING among the headers.\n"
+#~ "       --proxy-user=USER     set USER as proxy username.\n"
+#~ "       --proxy-passwd=PASS   set PASS as proxy password.\n"
+#~ "       --referer=URL         include `Referer: URL' header in HTTP "
+#~ "request.\n"
+#~ "  -s,  --save-headers        save the HTTP headers to file.\n"
+#~ "  -U,  --user-agent=AGENT    identify as AGENT instead of Wget/VERSION.\n"
+#~ "       --no-http-keep-alive  disable HTTP keep-alive (persistent "
+#~ "connections).\n"
+#~ "       --cookies=off         don't use cookies.\n"
+#~ "       --load-cookies=FILE   load cookies from FILE before session.\n"
+#~ "       --save-cookies=FILE   save cookies to FILE after session.\n"
+#~ "\n"
+#~ msgstr ""
+#~ "                                                              :HTTP "
+#~ "ינייפאמ\n"
+#~ "                    HTTP שמתשמ לש ומש USER יהי       --http-user=USER\n"
+#~ "                 HTTP שמתשמ לש ותמסיס PASS יהי       --http-passwd=PASS\n"
+#~ "        תרשב ןומטמב ורמשנש םינותנ השרת לא\\השרה  -C,  --cache=on/off\n"
+#~ "                     .html תמויס םיצבקה לכל ןת  -E,  --html-extension\n"
+#~ "                 `Content-Length' תרתוכמ םלעתה       --ignore-length\n"
+#~ "               תורתוכה ךותב STRING תזורחמ לותש       --header=STRING\n"
+#~ "             השרומ תרשב שמתשמה לש ומש USER יהי       --proxy-user=USER\n"
+#~ "          השרומ תרשב שמתשמה לש ותמסיס PASS יהי       --proxy-passwd=PASS\n"
+#~ "         HTTP תיינפל `Referer: URL' תרתוכ ףסוה       --referer=URL\n"
+#~ "                    טלפ יצבקב HTTP תורתוכ רומש  -s,  --save-headers\n"
+#~ "   ליגרכ Wget/VERSION םוקמב AGENT תינכתכ ההדזה  -U,  --user-agent=AGENT\n"
+#~ "     (דימתמ HTTP רוביח) keep-alive-ב שומיש לטב       --no-http-keep-"
+#~ "alive\n"
+#~ "                    (cookies) תויגועב שמתשת לא       --cookies=off\n"
+#~ "       הדובעה תליחת ינפל FILE ץבוקמ תויגוע ןעט       --load-cookies=FILE\n"
+#~ "            הדובעה רמגב FILE ץבוקב תויגוע רומש       --save-cookies=FILE\n"
+#~ "\n"
+
+#~ msgid ""
+#~ "FTP options:\n"
+#~ "  -nr, --dont-remove-listing   don't remove `.listing' files.\n"
+#~ "  -g,  --glob=on/off           turn file name globbing on or off.\n"
+#~ "       --passive-ftp           use the \"passive\" transfer mode.\n"
+#~ "       --retr-symlinks         when recursing, get linked-to files (not "
+#~ "dirs).\n"
+#~ "\n"
+#~ msgstr ""
+#~ "                                                               :FTP "
+#~ "ינייפאמ\n"
+#~ "                          listing יצבק קחמת לא  -nr, --dont-remove-"
+#~ "listing\n"
+#~ "    םיצבק תומשב הבחרה יותב הכימת ליעפת לא\\לעפה  -g,  --glob=on/off\n"
+#~ "             (\"PASV\") תיביספ הרבעה תטישב שמתשה       --passive-ftp\n"
+#~ "   םירושיק לש הרטמ יצבק ךושמ ,תיביסרוקר הכישמב       --retr-symlinks\n"
+#~ "\n"
+
+#~ msgid ""
+#~ "Recursive retrieval:\n"
+#~ "  -r,  --recursive          recursive web-suck -- use with care!\n"
+#~ "  -l,  --level=NUMBER       maximum recursion depth (inf or 0 for "
+#~ "infinite).\n"
+#~ "       --delete-after       delete files locally after downloading them.\n"
+#~ "  -k,  --convert-links      convert non-relative links to relative.\n"
+#~ "  -K,  --backup-converted   before converting file X, back up as X.orig.\n"
+#~ "  -m,  --mirror             shortcut option equivalent to -r -N -l inf -"
+#~ "nr.\n"
+#~ "  -p,  --page-requisites    get all images, etc. needed to display HTML "
+#~ "page.\n"
+#~ "\n"
+#~ msgstr ""
+#~ "                                                           :תיביסרוקר "
+#~ "הכישמ\n"
+#~ "  (!תרהזוה האר !ןכוסמ) -- תיביסרוקר הכישמ רשפא  -r,  --recursive\n"
+#~ "לבגומ-יתלב קמועל וא 0 ,היסרוקרל יברימ קמוע עבק  -l,  --level=NUMBER\n"
+#~ "            הכישמ רמגב תימוקמ םיצבקה לכ תא קחמ       --delete-after\n"
+#~ "                          םייסחיל םירושיק ךופה  -k,  --convert-links\n"
+#~ "                הכיפה ינפל יוביגכ ץבוק לכ רומש  -K,  --backup-converted\n"
+#~ "       -r -N -l inf -nr םינייפאמה ףוריצל רוציק  -m,  --mirror\n"
+#~ "         HTML תגוצתל םישרדנה םיצבקה לכ תא ךושמ  -p,  --page-requisites\n"
+#~ "\n"
+
+#~ msgid ""
+#~ "Recursive accept/reject:\n"
+#~ "  -A,  --accept=LIST                comma-separated list of accepted "
+#~ "extensions.\n"
+#~ "  -R,  --reject=LIST                comma-separated list of rejected "
+#~ "extensions.\n"
+#~ "  -D,  --domains=LIST               comma-separated list of accepted "
+#~ "domains.\n"
+#~ "       --exclude-domains=LIST       comma-separated list of rejected "
+#~ "domains.\n"
+#~ "       --follow-ftp                 follow FTP links from HTML "
+#~ "documents.\n"
+#~ "       --follow-tags=LIST           comma-separated list of followed HTML "
+#~ "tags.\n"
+#~ "  -G,  --ignore-tags=LIST           comma-separated list of ignored HTML "
+#~ "tags.\n"
+#~ "  -H,  --span-hosts                 go to foreign hosts when recursive.\n"
+#~ "  -L,  --relative                   follow relative links only.\n"
+#~ "  -I,  --include-directories=LIST   list of allowed directories.\n"
+#~ "  -X,  --exclude-directories=LIST   list of excluded directories.\n"
+#~ "  -nh, --no-host-lookup             don't DNS-lookup hosts.\n"
+#~ "  -np, --no-parent                  don't ascend to the parent "
+#~ "directory.\n"
+#~ "\n"
+#~ msgstr ""
+#~ "                                         :תיביסרוקר הכישמ תעב הייחד וא "
+#~ "הלבק\n"
+#~ "        םיקיספ י\"ע תודרפומ תורתומ תומויס תמישר  -A,  --accept=LIST\n"
+#~ "        םיקיספ י\"ע תודרפומ תורוסא תומויס תמישר  -R,  --reject=LIST\n"
+#~ "   םיקיספ י\"ע םידרפומ םירתומ םימוחת תומש תמישר  -D,  --domains=LIST\n"
+#~ "   םיקיספ י\"ע םידרפומ םירוסא םימוחת תומש תמישר       --exclude-"
+#~ "domains=LIS\n"
+#~ "                 HTML יפדב FTP ירושיק רחא בוקע       --follow-ftp\n"
+#~ " םיקיספ י\"ע םידרפומ בוקעל שי םהירחא HTML תמישר       --follow-tags=LIST\n"
+#~ "                      םלעתהל שי םהמ HTML תמישר  -G,  --ignore-tags=LIST\n"
+#~ "   םירחא םיבשחמל תשגל ןתינ תיביסרוקר הכישמ תעב  -H,  --span-hosts\n"
+#~ "             יסחי םש ילעב םירושיק ירחא קר בוקע  -L,  --relative\n"
+#~ "                           תורתומ תויקית תמישר  -I,  --include-"
+#~ "directories=L\n"
+#~ "                           תורוסא תויקית תמישר  -X,  --exclude-"
+#~ "directories=L\n"
+#~ "             תשרב םיבשחמ שופיחל DNS-ב שמתשת לא  -nh, --no-host-lookup\n"
+#~ "                            בא תייקיתל הלעת לא  -np, --no-parent\n"
+#~ "\n"
+
+#~ msgid "%s: debug support not compiled in.\n"
+#~ msgstr ".`--debug' ןייפאמב הכימת םע התנבנ אל %s תינכתה\n"
+
+#~ msgid "%s: %s: invalid command\n"
+#~ msgstr "%s: %s היוגש הדוקפ\n"
+
+#~ msgid ""
+#~ "\n"
+#~ "CTRL+Break received, redirecting output to `%s'.\n"
+#~ "Execution continued in background.\n"
+#~ "You may stop Wget by pressing CTRL+ALT+DELETE.\n"
+#~ msgstr ""
+#~ "\n"
+#~ "       .`%s'-ל טלפ תיינפה ,CTRL+Break ץחלנ\n"
+#~ "                        .עקרב ךשמיי עוציבה\n"
+#~ ".CTRL+ALT+DELETE תשקה י\"ע Wget רוצעל ןתינ\n"
+
+#~ msgid "Starting WinHelp %s\n"
+#~ msgstr ".\"WinHelp %s\" ליעפמ\n"
+
+#~ msgid "Could not find proxy host.\n"
+#~ msgstr ".השרומ תרש אצמנ אל\n"
+
+#~ msgid "%s: %s: Not enough memory.\n"
+#~ msgstr ".%s תינכת לש %s הרגשב ןורכז קיפסמ ןיא\n"
+
+#~ msgid "Unknown/unsupported protocol"
+#~ msgstr "ךמתנ וניא וא רכומ-יתלב לוקוטורפ"
+
+#~ msgid "Invalid port specification"
+#~ msgstr "יוגש האיצי ןויצ"
