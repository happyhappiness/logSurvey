 "--%s-- ���� ������\n"
 "���� %s ,����� %d �����\n"
 
-#: src/main.c:842
+#: src/main.c:951
 #, c-format
 msgid "Download quota (%s bytes) EXCEEDED!\n"
 msgstr "!(���� %s) ����� ������ �����\n"
 
-#. Please note that the double `%' in `%%s' is intentional, because
-#. redirect_output passes tmp through printf.
-#: src/main.c:876
+#: src/mswindows.c:235
 #, c-format
-msgid "%s received, redirecting output to `%%s'.\n"
-msgstr "%s ������ ,`%%s'-� ��� ������\n"
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
-"       .`%s'-� ��� ������ ,CTRL+Break ����\n"
-"                        .���� ����� ������\n"
-".CTRL+ALT+DELETE ���� �\"� Wget ����� ����\n"
-
-#. parent, no error
-#: src/mswindows.c:106 src/utils.c:458
 msgid "Continuing in background.\n"
 msgstr ".���� �����\n"
 
-#: src/mswindows.c:108 src/utils.c:460
+#: src/mswindows.c:427
+#, fuzzy, c-format
+msgid "Continuing in background, pid %lu.\n"
+msgstr ".���� �����\n"
+
+#: src/mswindows.c:429 src/utils.c:349
 #, c-format
 msgid "Output will be written to `%s'.\n"
 msgstr ".`%s'-� ����� ���\n"
 
-#: src/mswindows.c:188
-#, c-format
-msgid "Starting WinHelp %s\n"
-msgstr ".\"WinHelp %s\" �����\n"
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
 msgstr "%s: %s:%d: ����� �� ������ ���� ������ \"%s\" ���� ���� :�����\n"
 
-#: src/netrc.c:398
+#: src/netrc.c:416
 #, c-format
 msgid "%s: %s:%d: unknown token \"%s\"\n"
 msgstr "%s: %s:%d: \"%s\" �����-���� ���� ����\n"
 
-#: src/netrc.c:462
+#: src/netrc.c:480
 #, c-format
 msgid "Usage: %s NETRC [HOSTNAME]\n"
 msgstr "%s NETRC [����-���� ��]  :������ ����\n"
 
-#: src/netrc.c:472
+#: src/netrc.c:490
 #, c-format
 msgid "%s: cannot stat %s: %s\n"
 msgstr "%s ������ %s ����� ����� (%s) ����\n"
 
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
+"          [ %dK �� ���� ]"
+
+#: src/progress.c:410
+#, fuzzy, c-format
+msgid "Invalid dot style specification `%s'; leaving unchanged.\n"
+msgstr ".%s ������ `%s' ���� ���\n"
+
+#: src/recur.c:377
 #, c-format
 msgid "Removing %s since it should be rejected.\n"
 msgstr ".����� ��-��� ���� %s\n"
 
-#: src/recur.c:679
+#: src/res.c:548
 msgid "Loading robots.txt; please ignore errors.\n"
 msgstr ".����� ������� ������ �� ;robots.txt ���� ����\n"
 
-#: src/retr.c:227
-#, c-format
-msgid "\n          [ skipping %dK ]"
-msgstr "\n          [ %dK �� ���� ]"
-
-#: src/retr.c:373
-msgid "Could not find proxy host.\n"
-msgstr ".����� ��� ���� ��\n"
+#: src/retr.c:638
+#, fuzzy, c-format
+msgid "Error parsing proxy URL %s: %s.\n"
+msgstr "`%s'-� ������ (%s) ����\n"
 
-#: src/retr.c:387
-#, c-format
-msgid "Proxy %s: Must be HTTP.\n"
+#: src/retr.c:646
+#, fuzzy, c-format
+msgid "Error in proxy URL %s: Must be HTTP.\n"
 msgstr ".HTTP ����� ���� :%s ����� ���\n"
 
-#: src/retr.c:481
-#, c-format
-msgid "%s: Redirection cycle detected.\n"
+#: src/retr.c:731
+#, fuzzy, c-format
+msgid "%d redirections exceeded.\n"
 msgstr ".%s ������ ������ ������ ������\n"
 
-#: src/retr.c:587
-msgid "Giving up.\n\n"
-msgstr "!���� ���\n\n"
+#: src/retr.c:856
+msgid ""
+"Giving up.\n"
+"\n"
+msgstr ""
+"!���� ���\n"
+"\n"
 
-#: src/retr.c:587
-msgid "Retrying.\n\n"
-msgstr ".���� �����\n\n"
+#: src/retr.c:856
+msgid ""
+"Retrying.\n"
+"\n"
+msgstr ""
+".���� �����\n"
+"\n"
 
-# Note: the following 5 messages are all written on the same line!
-#: src/url.c:1329
-#, c-format
-msgid "Converting %s... "
-msgstr "%s ����"
+#: src/url.c:642
+#, fuzzy
+msgid "No error"
+msgstr "�����-���� ����"
 
-#: src/url.c:1342
-msgid "nothing to do.\n"
-msgstr "� ���� ���\n"
+#: src/url.c:644
+msgid "Unsupported scheme"
+msgstr ""
 
-#: src/url.c:1350 src/url.c:1374
-#, c-format
-msgid "Cannot convert links in %s: %s\n"
-msgstr "� (%s: %s) ������� ���� ����\n"
+#: src/url.c:646
+msgid "Empty host"
+msgstr ""
 
-#: src/url.c:1365
-#, c-format
-msgid "Unable to delete `%s': %s\n"
-msgstr "`%s' ����� ������ (%s) ����\n"
+#: src/url.c:648
+msgid "Bad port number"
+msgstr ""
 
-#: src/url.c:1555
-#, c-format
-msgid "Cannot back up %s as %s: %s\n"
-msgstr "%s-� ������ %s ������ (%s) ����\n"
+#: src/url.c:650
+#, fuzzy
+msgid "Invalid user name"
+msgstr "����-���� �� ���� ��"
 
-#: src/utils.c:94
-#, c-format
-msgid "%s: %s: Not enough memory.\n"
-msgstr ".%s ����� �� %s ����� ����� ����� ���\n"
+#: src/url.c:652
+msgid "Unterminated IPv6 numeric address"
+msgstr ""
 
-#: src/utils.c:417
-msgid "Unknown/unsupported protocol"
-msgstr "���� ���� �� ����-���� ��������"
+#: src/url.c:654
+msgid "IPv6 addresses not supported"
+msgstr ""
 
-#: src/utils.c:420
-msgid "Invalid port specification"
-msgstr "���� ����� ����"
+#: src/url.c:656
+msgid "Invalid IPv6 numeric address"
+msgstr ""
 
-#: src/utils.c:423
-msgid "Invalid host name"
-msgstr "����-���� �� ���� ��"
+#. parent, no error
+#: src/utils.c:347
+#, fuzzy, c-format
+msgid "Continuing in background, pid %d.\n"
+msgstr ".���� �����\n"
 
-#: src/utils.c:620
+#: src/utils.c:391
 #, c-format
 msgid "Failed to unlink symlink `%s': %s\n"
 msgstr "`%s' ������� ����� ������ (%s) ����\n"
+
+#: src/xmalloc.c:72
+#, c-format
+msgid "%s: %s: Failed to allocate %ld bytes; memory exhausted.\n"
+msgstr ""
+
+#~ msgid "Syntax error in Set-Cookie at character `%c'.\n"
+#~ msgstr ".`%c' �� ����� Set-Cookie ����� �� ���� �����\n"
+
+#~ msgid "Connection to %s:%hu refused.\n"
+#~ msgstr ".���� %s:%hu-� ������� �����\n"
+
+#~ msgid "Will try connecting to %s:%hu.\n"
+#~ msgstr ".%s:%hu-� ������ ����\n"
+
+#~ msgid ""
+#~ "\n"
+#~ "REST failed; will not truncate `%s'.\n"
+#~ msgstr ""
+#~ "\n"
+#~ ".`%s' �� ���� ���� ����� ���� ����� ;����� REST �����\n"
+
+#~ msgid " [%s to go]"
+#~ msgstr " [%s ��� ����]"
+
+#~ msgid "Host not found"
+#~ msgstr "���� �� ���� ����"
+
+#~ msgid "End of file while parsing headers.\n"
+#~ msgstr ".������� ����� ��� ��� ��� ���\n"
+
+#~ msgid ""
+#~ "\n"
+#~ "Continued download failed on this file, which conflicts with `-c'.\n"
+#~ "Refusing to truncate existing file `%s'.\n"
+#~ "\n"
+#~ msgstr ""
+#~ "\n"
+#~ ",����� `-c' ������� ���� .����� �� ���� �� ����-�����\n"
+#~ ".`%s' ���� ���� ����� �������� ���\n"
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
+#~ msgstr "%s: IP ������ ����� ����� ����� %s ������ `%s'\n"
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
+#~ "�����\n"
+#~ "                           ������ ����� �� ���  -V,  --version\n"
+#~ "                               �� ���� ��� ���       --help\n"
+#~ "                   ����� ���� ���� ������ ����  -b,  --background\n"
+#~ "                       wgetrc ������ ����� ���  -e,  --execute=COMMAND\n"
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
+#~ "                                                            :����� ��� "
+#~ "����\n"
+#~ "                         FILE ����� ������ ���  -o,  --output-file=FILE\n"
+#~ "                        FILE ����� ������ ����  -a,  --append-"
+#~ "output=FILE\n"
+#~ "               ������ ������ ����� ������ ����  -d,  --debug\n"
+#~ "                       (������ ���) ���� �����  -q,  --quiet\n"
+#~ "        (����� ����� ����)  ������ ������ ����  -v,  --verbose\n"
+#~ "     ���� ������ ����� �� �� ,������ ����� ���  -nv, --non-verbose\n"
+#~ "               FILE ���� ���� ������ ��-URL ��  -i,  --input-file=FILE\n"
+#~ "         HTML ������ ���� -i-� ��� ���� �� ���  -F,  --force-html\n"
+#~ " URL-� ������ ���� -i-� �������� ������� �����  -B,  --base=URL\n"
+#~ "             ���� ����� ����� ���� ���� ������       --sslcertfile=FILE\n"
+#~ "           �� ����� ���� ���� ���� ���� ������       --"
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
+#~ "                                                               :����� "
+#~ "�����\n"
+#~ " ����� ����� (IP �� ���� ��) ADDR ������ �����       --bind-address=ADDR\n"
+#~ "  (����� ��� ����� 0) ������� ������� ���� ���  -t,  --tries=NUMBER\n"
+#~ "                                FILE-� ��� ���  -O   --output-"
+#~ "document=FILE\n"
+#~ "��� ������ ��� ����� ��� ������ ����� ����� ��  -nc, --no-clobber\n"
+#~ "             ����� �� ������� ���� ������ ����  -c,  --continue\n"
+#~ "                ������ ������� ����� ����� ���       --dot-style=STYLE\n"
+#~ "  ������� ������ �������� ����� ����� ����� ��  -N,  --timestamping\n"
+#~ "                       ����� ������� ����� ���  -S,  --server-response\n"
+#~ "                                  ��� ����� ��       --spider\n"
+#~ "                     ���� ������ ����� ��� ���  -T,  --timeout=SECONDS\n"
+#~ "                         ������ ��� ������ ���  -w,  --wait=SECONDS\n"
+#~ "                   ������� ��� ����� N �� ����       --waitretry=N\n"
+#~ "                     ����� ���� ����� ��\\�����  -Y,  --proxy=on/off\n"
+#~ "(����� ��� ����� 0) ������ ���� ���� ����� ���  -Q,  --quota=NUMBER\n"
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
+#~ "������\n"
+#~ "                         ����� ������ ����� ��  -nd  --no-directories\n"
+#~ "                       ����� ������ ����� ����  -x,  --force-directories\n"
+#~ "    ������ ����� ���� ���� ��� ������ ����� ��  -nH, --no-host-"
+#~ "directories\n"
+#~ "           PFX/... ����� ��� ������ �� �� ����  -P,  --directory-"
+#~ "prefix=PFX\n"
+#~ "            ������� ����� ������� ����� N ����       --cut-dirs=N\n"
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
+#~ "�������\n"
+#~ "                    HTTP ����� �� ��� USER ���       --http-user=USER\n"
+#~ "                 HTTP ����� �� ������ PASS ���       --http-passwd=PASS\n"
+#~ "        ���� ������ ������ ������ ���� ��\\����  -C,  --cache=on/off\n"
+#~ "                     .html ����� ������ ��� ��  -E,  --html-extension\n"
+#~ "                 `Content-Length' ������ �����       --ignore-length\n"
+#~ "               ������� ���� STRING ������ ����       --header=STRING\n"
+#~ "             ����� ���� ������ �� ��� USER ���       --proxy-user=USER\n"
+#~ "          ����� ���� ������ �� ������ PASS ���       --proxy-passwd=PASS\n"
+#~ "         HTTP ������ `Referer: URL' ����� ����       --referer=URL\n"
+#~ "                    ��� ����� HTTP ������ ����  -s,  --save-headers\n"
+#~ "   ����� Wget/VERSION ����� AGENT ������ �����  -U,  --user-agent=AGENT\n"
+#~ "     (����� HTTP �����) keep-alive-� ����� ���       --no-http-keep-"
+#~ "alive\n"
+#~ "                    (cookies) ������� ����� ��       --cookies=off\n"
+#~ "       ������ ����� ���� FILE ����� ������ ���       --load-cookies=FILE\n"
+#~ "            ������ ���� FILE ����� ������ ����       --save-cookies=FILE\n"
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
+#~ "�������\n"
+#~ "                          listing ���� ���� ��  -nr, --dont-remove-"
+#~ "listing\n"
+#~ "    ����� ����� ����� ���� ����� ����� ��\\����  -g,  --glob=on/off\n"
+#~ "             (\"PASV\") ������ ����� ����� �����       --passive-ftp\n"
+#~ "   ������� �� ���� ���� ���� ,��������� ������       --retr-symlinks\n"
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
+#~ "                                                           :��������� "
+#~ "�����\n"
+#~ "  (!������ ��� !�����) -- ��������� ����� ����  -r,  --recursive\n"
+#~ "�����-���� ����� �� 0 ,�������� ����� ���� ���  -l,  --level=NUMBER\n"
+#~ "            ����� ���� ������ ������ �� �� ���       --delete-after\n"
+#~ "                          ������� ������� ����  -k,  --convert-links\n"
+#~ "                ����� ���� ������ ���� �� ����  -K,  --backup-converted\n"
+#~ "       -r -N -l inf -nr ��������� ������ �����  -m,  --mirror\n"
+#~ "         HTML ������ ������� ������ �� �� ����  -p,  --page-requisites\n"
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
+#~ "                                         :��������� ����� ��� ����� �� "
+#~ "����\n"
+#~ "        ������ �\"� ������� ������ ������ �����  -A,  --accept=LIST\n"
+#~ "        ������ �\"� ������� ������ ������ �����  -R,  --reject=LIST\n"
+#~ "   ������ �\"� ������� ������ ������ ���� �����  -D,  --domains=LIST\n"
+#~ "   ������ �\"� ������� ������ ������ ���� �����       --exclude-"
+#~ "domains=LIS\n"
+#~ "                 HTML ���� FTP ������ ��� ����       --follow-ftp\n"
+#~ " ������ �\"� ������� ����� �� ������ HTML �����       --follow-tags=LIST\n"
+#~ "                      ������ �� ��� HTML �����  -G,  --ignore-tags=LIST\n"
+#~ "   ����� ������� ���� ���� ��������� ����� ���  -H,  --span-hosts\n"
+#~ "             ���� �� ���� ������� ���� �� ����  -L,  --relative\n"
+#~ "                           ������ ������ �����  -I,  --include-"
+#~ "directories=L\n"
+#~ "                           ������ ������ �����  -X,  --exclude-"
+#~ "directories=L\n"
+#~ "             ���� ������ ������ DNS-� ����� ��  -nh, --no-host-lookup\n"
+#~ "                            �� ������� ���� ��  -np, --no-parent\n"
+#~ "\n"
+
+#~ msgid "%s: debug support not compiled in.\n"
+#~ msgstr ".`--debug' ������� ����� �� ����� �� %s ������\n"
+
+#~ msgid "%s: %s: invalid command\n"
+#~ msgstr "%s: %s ����� �����\n"
+
+#~ msgid ""
+#~ "\n"
+#~ "CTRL+Break received, redirecting output to `%s'.\n"
+#~ "Execution continued in background.\n"
+#~ "You may stop Wget by pressing CTRL+ALT+DELETE.\n"
+#~ msgstr ""
+#~ "\n"
+#~ "       .`%s'-� ��� ������ ,CTRL+Break ����\n"
+#~ "                        .���� ����� ������\n"
+#~ ".CTRL+ALT+DELETE ���� �\"� Wget ����� ����\n"
+
+#~ msgid "Starting WinHelp %s\n"
+#~ msgstr ".\"WinHelp %s\" �����\n"
+
+#~ msgid "Could not find proxy host.\n"
+#~ msgstr ".����� ��� ���� ��\n"
+
+#~ msgid "%s: %s: Not enough memory.\n"
+#~ msgstr ".%s ����� �� %s ����� ����� ����� ���\n"
+
+#~ msgid "Unknown/unsupported protocol"
+#~ msgstr "���� ���� �� ����-���� ��������"
+
+#~ msgid "Invalid port specification"
+#~ msgstr "���� ����� ����"
