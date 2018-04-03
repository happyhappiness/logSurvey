 static void
 print_help (void)
 {
+  /* We split the help text this way to ease translation of individual
+     entries.  */
+  static const char *help[] = {
+    "\n",
+    N_("\
+Mandatory arguments to long options are mandatory for short options too.\n\n"),
+    N_("\
+Startup:\n"),
+    N_("\
+  -V,  --version           display the version of Wget and exit.\n"),
+    N_("\
+  -h,  --help              print this help.\n"),
+    N_("\
+  -b,  --background        go to background after startup.\n"),
+    N_("\
+  -e,  --execute=COMMAND   execute a `.wgetrc'-style command.\n"),
+    "\n",
+
+    N_("\
+Logging and input file:\n"),
+    N_("\
+  -o,  --output-file=FILE    log messages to FILE.\n"),
+    N_("\
+  -a,  --append-output=FILE  append messages to FILE.\n"),
+#ifdef ENABLE_DEBUG
+    N_("\
+  -d,  --debug               print lots of debugging information.\n"),
+#endif
+    N_("\
+  -q,  --quiet               quiet (no output).\n"),
+    N_("\
+  -v,  --verbose             be verbose (this is the default).\n"),
+    N_("\
+  -nv, --non-verbose         turn off verboseness, without being quiet.\n"),
+    N_("\
+  -i,  --input-file=FILE     download URLs found in FILE.\n"),
+    N_("\
+  -F,  --force-html          treat input file as HTML.\n"),
+    N_("\
+  -B,  --base=URL            prepends URL to relative links in -F -i file.\n"),
+    "\n",
+
+    N_("\
+Download:\n"),
+    N_("\
+  -t,  --tries=NUMBER            set number of retries to NUMBER (0 unlimits).\n"),
+    N_("\
+       --retry-connrefused       retry even if connection is refused.\n"),
+    N_("\
+  -O   --output-document=FILE    write documents to FILE.\n"),
+    N_("\
+  -nc, --no-clobber              skip downloads that would download to\n\
+                                 existing files.\n"),
+    N_("\
+  -c,  --continue                resume getting a partially-downloaded file.\n"),
+    N_("\
+       --progress=TYPE           select progress gauge type.\n"),
+    N_("\
+  -N,  --timestamping            don't re-retrieve files unless newer than\n\
+                                 local.\n"),
+    N_("\
+  -S,  --server-response         print server response.\n"),
+    N_("\
+       --spider                  don't download anything.\n"),
+    N_("\
+  -T,  --timeout=SECONDS         set all timeout values to SECONDS.\n"),
+    N_("\
+       --dns-timeout=SECS        set the DNS lookup timeout to SECS.\n"),
+    N_("\
+       --connect-timeout=SECS    set the connect timeout to SECS.\n"),
+    N_("\
+       --read-timeout=SECS       set the read timeout to SECS.\n"),
+    N_("\
+  -w,  --wait=SECONDS            wait SECONDS between retrievals.\n"),
+    N_("\
+       --waitretry=SECONDS       wait 1..SECONDS between retries of a retrieval.\n"),
+    N_("\
+       --random-wait             wait from 0...2*WAIT secs between retrievals.\n"),
+    N_("\
+  -Y,  --proxy=on/off            turn proxy on or off.\n"),
+    N_("\
+  -Q,  --quota=NUMBER            set retrieval quota to NUMBER.\n"),
+    N_("\
+       --bind-address=ADDRESS    bind to ADDRESS (hostname or IP) on local host.\n"),
+    N_("\
+       --limit-rate=RATE         limit download rate to RATE.\n"),
+    N_("\
+       --dns-cache=off           disable caching DNS lookups.\n"),
+    N_("\
+       --restrict-file-names=OS  restrict chars in file names to ones OS allows.\n"),
+    "\n",
+
+    N_("\
+Directories:\n"),
+    N_("\
+  -nd, --no-directories           don't create directories.\n"),
+    N_("\
+  -x,  --force-directories        force creation of directories.\n"),
+    N_("\
+  -nH, --no-host-directories      don't create host directories.\n"),
+    N_("\
+  -P,  --directory-prefix=PREFIX  save files to PREFIX/...\n"),
+    N_("\
+       --cut-dirs=NUMBER          ignore NUMBER remote directory components.\n"),
+    "\n",
+
+    N_("\
+HTTP options:\n"),
+    N_("\
+       --http-user=USER        set http user to USER.\n"),
+    N_("\
+       --http-passwd=PASS      set http password to PASS.\n"),
+    N_("\
+  -C,  --no-cache              disallow server-cached data.\n"),
+    N_("\
+  -E,  --html-extension        save HTML documents with `.html' extension.\n"),
+    N_("\
+       --ignore-length         ignore `Content-Length' header field.\n"),
+    N_("\
+       --header=STRING         insert STRING among the headers.\n"),
+    N_("\
+       --proxy-user=USER       set USER as proxy username.\n"),
+    N_("\
+       --proxy-passwd=PASS     set PASS as proxy password.\n"),
+    N_("\
+       --referer=URL           include `Referer: URL' header in HTTP request.\n"),
+    N_("\
+  -s,  --save-headers          save the HTTP headers to file.\n"),
+    N_("\
+  -U,  --user-agent=AGENT      identify as AGENT instead of Wget/VERSION.\n"),
+    N_("\
+       --no-http-keep-alive    disable HTTP keep-alive (persistent connections).\n"),
+    N_("\
+       --cookies=off           don't use cookies.\n"),
+    N_("\
+       --load-cookies=FILE     load cookies from FILE before session.\n"),
+    N_("\
+       --save-cookies=FILE     save cookies to FILE after session.\n"),
+    N_("\
+       --keep-session-cookies  load and save session (non-permanent) cookies.\n"),
+    N_("\
+       --post-data=STRING      use the POST method; send STRING as the data.\n"),
+    N_("\
+       --post-file=FILE        use the POST method; send contents of FILE.\n"),
+    "\n",
+
+#ifdef HAVE_SSL
+    N_("\
+HTTPS (SSL) options:\n"),
+    N_("\
+       --sslcertfile=FILE    optional client certificate.\n"),
+    N_("\
+       --sslcertkey=KEYFILE  optional keyfile for this certificate.\n"),
+    N_("\
+       --egd-file=FILE       file name of the EGD socket.\n"),
+    N_("\
+       --sslcadir=DIR        dir where hash list of CA's are stored.\n"),
+    N_("\
+       --sslcafile=FILE      file with bundle of CA's\n"),
+    N_("\
+       --sslcerttype=0/1     Client-Cert type 0=PEM (default) / 1=ASN1 (DER)\n"),
+    N_("\
+       --sslcheckcert=0/1    Check the server cert agenst given CA\n"),
+    N_("\
+       --sslprotocol=0-3     choose SSL protocol; 0=automatic,\n"),
+    N_("\
+                             1=SSLv2 2=SSLv3 3=TLSv1\n"),
+    "\n",
+#endif /* HAVE_SSL */
+
+    N_("\
+FTP options:\n"),
+    N_("\
+  -nr, --no-remove-listing  don't remove `.listing' files.\n"),
+    N_("\
+  -g,  --glob=on/off        turn file name globbing on or off.\n"),
+    N_("\
+       --passive-ftp        use the \"passive\" transfer mode.\n"),
+    N_("\
+       --retr-symlinks      when recursing, get linked-to files (not dir).\n"),
+    N_("\
+       --preserve-permissions  preserve remote file permissions.\n"),
+    "\n",
+
+    N_("\
+Recursive retrieval:\n"),
+    N_("\
+  -r,  --recursive             recursive download.\n"),
+    N_("\
+  -l,  --level=NUMBER          maximum recursion depth (inf or 0 for infinite).\n"),
+    N_("\
+       --delete-after          delete files locally after downloading them.\n"),
+    N_("\
+  -k,  --convert-links         convert non-relative links to relative.\n"),
+    N_("\
+  -K,  --backup-converted      before converting file X, back up as X.orig.\n"),
+    N_("\
+  -m,  --mirror                shortcut option equivalent to -r -N -l inf -nr.\n"),
+    N_("\
+  -p,  --page-requisites       get all images, etc. needed to display HTML page.\n"),
+    N_("\
+       --strict-comments       turn on strict (SGML) handling of HTML comments.\n"),
+    "\n",
+
+    N_("\
+Recursive accept/reject:\n"),
+    N_("\
+  -A,  --accept=LIST               comma-separated list of accepted extensions.\n"),
+    N_("\
+  -R,  --reject=LIST               comma-separated list of rejected extensions.\n"),
+    N_("\
+  -D,  --domains=LIST              comma-separated list of accepted domains.\n"),
+    N_("\
+       --exclude-domains=LIST      comma-separated list of rejected domains.\n"),
+    N_("\
+       --follow-ftp                follow FTP links from HTML documents.\n"),
+    N_("\
+       --follow-tags=LIST          comma-separated list of followed HTML tags.\n"),
+    N_("\
+  -G,  --ignore-tags=LIST          comma-separated list of ignored HTML tags.\n"),
+    N_("\
+  -H,  --span-hosts                go to foreign hosts when recursive.\n"),
+    N_("\
+  -L,  --relative                  follow relative links only.\n"),
+    N_("\
+  -I,  --include-directories=LIST  list of allowed directories.\n"),
+    N_("\
+  -X,  --exclude-directories=LIST  list of excluded directories.\n"),
+    N_("\
+  -np, --no-parent                 don't ascend to the parent directory.\n"),
+    "\n",
+
+    N_("Mail bug reports and suggestions to <bug-wget@gnu.org>.\n")
+  };
+
+  int i;
+
   printf (_("GNU Wget %s, a non-interactive network retriever.\n"),
 	  version_string);
   print_usage ();
-  /* Had to split this in parts, so the #@@#%# Ultrix compiler and cpp
-     don't bitch.  Also, it makes translation much easier.  */
-  fputs (_("\
-\n\
-Mandatory arguments to long options are mandatory for short options too.\n\
-\n"), stdout);
-  fputs (_("\
-Startup:\n\
-  -V,  --version           display the version of Wget and exit.\n\
-  -h,  --help              print this help.\n\
-  -b,  --background        go to background after startup.\n\
-  -e,  --execute=COMMAND   execute a `.wgetrc\'-style command.\n\
-\n"), stdout);
-  fputs (_("\
-Logging and input file:\n\
-  -o,  --output-file=FILE     log messages to FILE.\n\
-  -a,  --append-output=FILE   append messages to FILE.\n\
-  -d,  --debug                print debug output.\n\
-  -q,  --quiet                quiet (no output).\n\
-  -v,  --verbose              be verbose (this is the default).\n\
-  -nv, --non-verbose          turn off verboseness, without being quiet.\n\
-  -i,  --input-file=FILE      download URLs found in FILE.\n\
-  -F,  --force-html           treat input file as HTML.\n\
-  -B,  --base=URL             prepends URL to relative links in -F -i file.\n\
-\n"),stdout);
-  fputs (_("\
-Download:\n\
-  -t,  --tries=NUMBER           set number of retries to NUMBER (0 unlimits).\n\
-       --retry-connrefused      retry even if connection is refused.\n\
-  -O   --output-document=FILE   write documents to FILE.\n\
-  -nc, --no-clobber             don\'t clobber existing files or use .# suffixes.\n\
-  -c,  --continue               resume getting a partially-downloaded file.\n\
-       --progress=TYPE          select progress gauge type.\n\
-  -N,  --timestamping           don\'t re-retrieve files unless newer than local.\n\
-  -S,  --server-response        print server response.\n\
-       --spider                 don\'t download anything.\n\
-  -T,  --timeout=SECONDS        set all timeout values to SECONDS.\n\
-       --dns-timeout=SECS       set the DNS lookup timeout to SECS.\n\
-       --connect-timeout=SECS   set the connect timeout to SECS.\n\
-       --read-timeout=SECS      set the read timeout to SECS.\n\
-  -w,  --wait=SECONDS           wait SECONDS between retrievals.\n\
-       --waitretry=SECONDS      wait 1...SECONDS between retries of a retrieval.\n\
-       --random-wait            wait from 0...2*WAIT secs between retrievals.\n\
-  -Y,  --proxy=on/off           turn proxy on or off.\n\
-  -Q,  --quota=NUMBER           set retrieval quota to NUMBER.\n\
-       --bind-address=ADDRESS   bind to ADDRESS (hostname or IP) on local host.\n\
-       --limit-rate=RATE        limit download rate to RATE.\n\
-       --dns-cache=off          disable caching DNS lookups.\n\
-       --restrict-file-names=OS restrict chars in file names to ones OS allows.\n\
-\n"), stdout);
-  fputs (_("\
-Directories:\n\
-  -nd, --no-directories            don\'t create directories.\n\
-  -x,  --force-directories         force creation of directories.\n\
-  -nH, --no-host-directories       don\'t create host directories.\n\
-  -P,  --directory-prefix=PREFIX   save files to PREFIX/...\n\
-       --cut-dirs=NUMBER           ignore NUMBER remote directory components.\n\
-\n"), stdout);
-  fputs (_("\
-HTTP options:\n\
-       --http-user=USER      set http user to USER.\n\
-       --http-passwd=PASS    set http password to PASS.\n\
-  -C,  --cache=on/off        (dis)allow server-cached data (normally allowed).\n\
-  -E,  --html-extension      save all text/html documents with .html extension.\n\
-       --ignore-length       ignore `Content-Length\' header field.\n\
-       --header=STRING       insert STRING among the headers.\n\
-       --proxy-user=USER     set USER as proxy username.\n\
-       --proxy-passwd=PASS   set PASS as proxy password.\n\
-       --referer=URL         include `Referer: URL\' header in HTTP request.\n\
-  -s,  --save-headers        save the HTTP headers to file.\n\
-  -U,  --user-agent=AGENT    identify as AGENT instead of Wget/VERSION.\n\
-       --no-http-keep-alive  disable HTTP keep-alive (persistent connections).\n\
-       --cookies=off         don't use cookies.\n\
-       --load-cookies=FILE   load cookies from FILE before session.\n\
-       --save-cookies=FILE   save cookies to FILE after session.\n\
-       --keep-session-cookies  load and save session (non-permanent) cookies.\n\
-       --post-data=STRING    use the POST method; send STRING as the data.\n\
-       --post-file=FILE      use the POST method; send contents of FILE.\n\
-\n"), stdout);
-#ifdef HAVE_SSL
-  fputs (_("\
-HTTPS (SSL) options:\n\
-       --sslcertfile=FILE     optional client certificate.\n\
-       --sslcertkey=KEYFILE   optional keyfile for this certificate.\n\
-       --egd-file=FILE        file name of the EGD socket.\n\
-       --sslcadir=DIR         dir where hash list of CA's are stored.\n\
-       --sslcafile=FILE       file with bundle of CA's\n\
-       --sslcerttype=0/1      Client-Cert type 0=PEM (default) / 1=ASN1 (DER)\n\
-       --sslcheckcert=0/1     Check the server cert agenst given CA\n\
-       --sslprotocol=0-3      choose SSL protocol; 0=automatic,\n\
-                              1=SSLv2 2=SSLv3 3=TLSv1\n\
-\n"), stdout);
+
+  for (i = 0; i < countof (help); i++)
+    fputs (_(help[i]), stdout);
+
+#ifdef WINDOWS
+  ws_help (exec_name);
 #endif
+  exit (0);
+}
+
+static void
+print_version (void)
+{
+  printf ("GNU Wget %s\n\n", version_string);
   fputs (_("\
-FTP options:\n\
-  -nr, --dont-remove-listing   don\'t remove `.listing\' files.\n\
-  -g,  --glob=on/off           turn file name globbing on or off.\n\
-       --passive-ftp           use the \"passive\" transfer mode.\n\
-       --retr-symlinks         when recursing, get linked-to files (not dirs).\n\
-\n"), stdout);
-  fputs (_("\
-Recursive retrieval:\n\
-  -r,  --recursive             recursive download.\n\
-  -l,  --level=NUMBER          maximum recursion depth (inf or 0 for infinite).\n\
-       --delete-after          delete files locally after downloading them.\n\
-  -k,  --convert-links         convert non-relative links to relative.\n\
-  -K,  --backup-converted      before converting file X, back up as X.orig.\n\
-  -m,  --mirror                shortcut option equivalent to -r -N -l inf -nr.\n\
-  -p,  --page-requisites       get all images, etc. needed to display HTML page.\n\
-       --strict-comments       turn on strict (SGML) handling of HTML comments.\n\
-       --preserve-permissions  preserve remote file permissions.\n\
-\n"), stdout);
+Copyright (C) 2003 Free Software Foundation, Inc.\n"), stdout);
   fputs (_("\
-Recursive accept/reject:\n\
-  -A,  --accept=LIST                comma-separated list of accepted extensions.\n\
-  -R,  --reject=LIST                comma-separated list of rejected extensions.\n\
-  -D,  --domains=LIST               comma-separated list of accepted domains.\n\
-       --exclude-domains=LIST       comma-separated list of rejected domains.\n\
-       --follow-ftp                 follow FTP links from HTML documents.\n\
-       --follow-tags=LIST           comma-separated list of followed HTML tags.\n\
-  -G,  --ignore-tags=LIST           comma-separated list of ignored HTML tags.\n\
-  -H,  --span-hosts                 go to foreign hosts when recursive.\n\
-  -L,  --relative                   follow relative links only.\n\
-  -I,  --include-directories=LIST   list of allowed directories.\n\
-  -X,  --exclude-directories=LIST   list of excluded directories.\n\
-  -np, --no-parent                  don\'t ascend to the parent directory.\n\
-\n"), stdout);
-  fputs (_("Mail bug reports and suggestions to <bug-wget@gnu.org>.\n"),
+This program is distributed in the hope that it will be useful,\n\
+but WITHOUT ANY WARRANTY; without even the implied warranty of\n\
+MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the\n\
+GNU General Public License for more details.\n"), stdout);
+  fputs (_("\nOriginally written by Hrvoje Niksic <hniksic@xemacs.org>.\n"),
 	 stdout);
+  exit (0);
 }
 
 int
