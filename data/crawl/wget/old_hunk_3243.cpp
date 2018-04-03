static void
print_help (void)
{
  printf (_("GNU Wget %s, a non-interactive network retriever.\n"),
	  version_string);
  print_usage ();
  /* Had to split this in parts, so the #@@#%# Ultrix compiler and cpp
     don't bitch.  Also, it makes translation much easier.  */
  fputs (_("\
\n\
Mandatory arguments to long options are mandatory for short options too.\n\
\n"), stdout);
  fputs (_("\
Startup:\n\
  -V,  --version           display the version of Wget and exit.\n\
  -h,  --help              print this help.\n\
  -b,  --background        go to background after startup.\n\
  -e,  --execute=COMMAND   execute a `.wgetrc\'-style command.\n\
\n"), stdout);
  fputs (_("\
Logging and input file:\n\
  -o,  --output-file=FILE     log messages to FILE.\n\
  -a,  --append-output=FILE   append messages to FILE.\n\
  -d,  --debug                print debug output.\n\
  -q,  --quiet                quiet (no output).\n\
  -v,  --verbose              be verbose (this is the default).\n\
  -nv, --non-verbose          turn off verboseness, without being quiet.\n\
  -i,  --input-file=FILE      download URLs found in FILE.\n\
  -F,  --force-html           treat input file as HTML.\n\
  -B,  --base=URL             prepends URL to relative links in -F -i file.\n\
\n"),stdout);
  fputs (_("\
Download:\n\
  -t,  --tries=NUMBER           set number of retries to NUMBER (0 unlimits).\n\
       --retry-connrefused      retry even if connection is refused.\n\
  -O   --output-document=FILE   write documents to FILE.\n\
  -nc, --no-clobber             don\'t clobber existing files or use .# suffixes.\n\
  -c,  --continue               resume getting a partially-downloaded file.\n\
       --progress=TYPE          select progress gauge type.\n\
  -N,  --timestamping           don\'t re-retrieve files unless newer than local.\n\
  -S,  --server-response        print server response.\n\
       --spider                 don\'t download anything.\n\
  -T,  --timeout=SECONDS        set all timeout values to SECONDS.\n\
       --dns-timeout=SECS       set the DNS lookup timeout to SECS.\n\
       --connect-timeout=SECS   set the connect timeout to SECS.\n\
       --read-timeout=SECS      set the read timeout to SECS.\n\
  -w,  --wait=SECONDS           wait SECONDS between retrievals.\n\
       --waitretry=SECONDS      wait 1...SECONDS between retries of a retrieval.\n\
       --random-wait            wait from 0...2*WAIT secs between retrievals.\n\
  -Y,  --proxy=on/off           turn proxy on or off.\n\
  -Q,  --quota=NUMBER           set retrieval quota to NUMBER.\n\
       --bind-address=ADDRESS   bind to ADDRESS (hostname or IP) on local host.\n\
       --limit-rate=RATE        limit download rate to RATE.\n\
       --dns-cache=off          disable caching DNS lookups.\n\
       --restrict-file-names=OS restrict chars in file names to ones OS allows.\n\
\n"), stdout);
  fputs (_("\
Directories:\n\
  -nd, --no-directories            don\'t create directories.\n\
  -x,  --force-directories         force creation of directories.\n\
  -nH, --no-host-directories       don\'t create host directories.\n\
  -P,  --directory-prefix=PREFIX   save files to PREFIX/...\n\
       --cut-dirs=NUMBER           ignore NUMBER remote directory components.\n\
\n"), stdout);
  fputs (_("\
HTTP options:\n\
       --http-user=USER      set http user to USER.\n\
       --http-passwd=PASS    set http password to PASS.\n\
  -C,  --cache=on/off        (dis)allow server-cached data (normally allowed).\n\
  -E,  --html-extension      save all text/html documents with .html extension.\n\
       --ignore-length       ignore `Content-Length\' header field.\n\
       --header=STRING       insert STRING among the headers.\n\
       --proxy-user=USER     set USER as proxy username.\n\
       --proxy-passwd=PASS   set PASS as proxy password.\n\
       --referer=URL         include `Referer: URL\' header in HTTP request.\n\
  -s,  --save-headers        save the HTTP headers to file.\n\
  -U,  --user-agent=AGENT    identify as AGENT instead of Wget/VERSION.\n\
       --no-http-keep-alive  disable HTTP keep-alive (persistent connections).\n\
       --cookies=off         don't use cookies.\n\
       --load-cookies=FILE   load cookies from FILE before session.\n\
       --save-cookies=FILE   save cookies to FILE after session.\n\
       --keep-session-cookies  load and save session (non-permanent) cookies.\n\
       --post-data=STRING    use the POST method; send STRING as the data.\n\
       --post-file=FILE      use the POST method; send contents of FILE.\n\
\n"), stdout);
#ifdef HAVE_SSL
  fputs (_("\
HTTPS (SSL) options:\n\
       --sslcertfile=FILE     optional client certificate.\n\
       --sslcertkey=KEYFILE   optional keyfile for this certificate.\n\
       --egd-file=FILE        file name of the EGD socket.\n\
       --sslcadir=DIR         dir where hash list of CA's are stored.\n\
       --sslcafile=FILE       file with bundle of CA's\n\
       --sslcerttype=0/1      Client-Cert type 0=PEM (default) / 1=ASN1 (DER)\n\
       --sslcheckcert=0/1     Check the server cert agenst given CA\n\
       --sslprotocol=0-3      choose SSL protocol; 0=automatic,\n\
                              1=SSLv2 2=SSLv3 3=TLSv1\n\
\n"), stdout);
#endif
  fputs (_("\
FTP options:\n\
  -nr, --dont-remove-listing   don\'t remove `.listing\' files.\n\
  -g,  --glob=on/off           turn file name globbing on or off.\n\
       --passive-ftp           use the \"passive\" transfer mode.\n\
       --retr-symlinks         when recursing, get linked-to files (not dirs).\n\
\n"), stdout);
  fputs (_("\
Recursive retrieval:\n\
  -r,  --recursive             recursive download.\n\
  -l,  --level=NUMBER          maximum recursion depth (inf or 0 for infinite).\n\
       --delete-after          delete files locally after downloading them.\n\
  -k,  --convert-links         convert non-relative links to relative.\n\
  -K,  --backup-converted      before converting file X, back up as X.orig.\n\
  -m,  --mirror                shortcut option equivalent to -r -N -l inf -nr.\n\
  -p,  --page-requisites       get all images, etc. needed to display HTML page.\n\
       --strict-comments       turn on strict (SGML) handling of HTML comments.\n\
       --preserve-permissions  preserve remote file permissions.\n\
\n"), stdout);
  fputs (_("\
Recursive accept/reject:\n\
  -A,  --accept=LIST                comma-separated list of accepted extensions.\n\
  -R,  --reject=LIST                comma-separated list of rejected extensions.\n\
  -D,  --domains=LIST               comma-separated list of accepted domains.\n\
       --exclude-domains=LIST       comma-separated list of rejected domains.\n\
       --follow-ftp                 follow FTP links from HTML documents.\n\
       --follow-tags=LIST           comma-separated list of followed HTML tags.\n\
  -G,  --ignore-tags=LIST           comma-separated list of ignored HTML tags.\n\
  -H,  --span-hosts                 go to foreign hosts when recursive.\n\
  -L,  --relative                   follow relative links only.\n\
  -I,  --include-directories=LIST   list of allowed directories.\n\
  -X,  --exclude-directories=LIST   list of excluded directories.\n\
  -np, --no-parent                  don\'t ascend to the parent directory.\n\
\n"), stdout);
  fputs (_("Mail bug reports and suggestions to <bug-wget@gnu.org>.\n"),
	 stdout);
}

int
