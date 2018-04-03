	- Added FTP support for PORT if PASV fails, also try the
	  default FTP data port (Henrik Nordstrom).
	- Fixed NULL pointer bug in clientGetHeadersForIMS when a
	  request is cancelled for fails on the client side.
	- Filled in some squid.conf comments (never_direct,
	  always_direct).
	- Added RES_DNSRCH to dnsserver's _res.options when the 
	  -D command line option is given.
	- Fixed repeated Detected DEAD/REVIVED Sibling messages when
	  peer->tcp_up == 0 (Michael O'Reilly).
	- Fixed storeGetNextFile's incorrect "directory does not exist"
	  errors (Michael O'Reilly).
	- Fixed aiops.c race condition (Michael O'Reilly, Stewart
	  Forster).
	- Added 'dns_nameservers' config option to specify non-default
	  DNS nameserver addresses (Maxim Krasnyansky).
	- Added lib/util.c code to show memory map as a tree
	  (Henrik Nordstrom).
	- Added HTTP and ICP median service times to Counters and
	  cachemgr average stats.
	- Changed "-d" command line option to take debugging level
	  as argument.  Debugging equal-to or less-than the argument
	  will be written to stderr.
	- Removed unused urlClean() function from url.c.	
	- Fixed a bug that allow '?' parts of urls to be recorded in
	  store.log.  Logged urls are now "clean".
	- Cache Manager got new Web interface (cachemgr.cgi). New .cgi
	  script forwards basic authentication from browser to squid.
	  Authentication info is encoded within all dynamically generated
	  pages so you do not have to type your password often.
	  Authentication records expire after 3 hours (default) since
	  last use. Cachemgr.cgi now recognizes "action protection" types
	  described below.
	- Added better recognition of available protection for actions
	  in Cache Manager. Actions are classified as "public" (no
	  password needed), "protected" (must specify a valid password),
	  "disabled" (those with a "disable" password in squid.conf), and
	  "hidden" (actions that require a password, but do not have
	  corresponding cachemgr_passwd entry). If you manage to request
	  a hidden, disabled, or unknown action, squid replies with
	  "Invalid URL" message. If a password is needed, and you failed
	  to provide one, squid replies with "Access Denied" message and
	  asks you to authenticate yourself.
	- Added "basic" authentication scheme for the Cache Manager.
	  When a password protected function is accessed, Squid sends an
	  HTTP_UNAUTHORIZED reply allowing the client to authorize itself
	  by specifying "name" and "password" for the specified action.
	  The user name is currently used for logging purposes only.  The
	  password must be an appropriate "cachemgr_passwd" entry from
	  squid.conf. The old interface (appending @password to the url)
	  is still supported but discouraged.  Note: it is not possible
	  to pass authentication information between squid and browser
	  *via a web server*. The server will strip all authentication
	  headers coming from the browser. A similar problem exists for
	  Proxy-Authentication scheme.
	- Added ERR_CACHE_MGR_ACCESS_DENIED page to notify of
	  authentication failures when accessing Cache Manager.
	- Added "-v" (Verbose) and "-H" (extra Headers) options to client.c.
	- Added simple context-based debugging to debug.c. Currently,
	  the context is defined as a constant string. Context reporting
	  is triggered by debug() calls.  Context debugging routines
	  print minimal amount of information sufficient to describe
	  current context. The interface will be enhanced in the future.
	- Replaced _http_reply with HttpReply. HttpReply is a
	  stand-alone object that is responsible for parsing, swapping,
	  and comm_writing of HTTP replies. Moved these functions from
	  various modules into HttpReply module.
	- Added HttpStatusLine, HttpHeader, HttpBody.
	- All HTTP headers are now parsed and stored in a "compiled"
	  form in the HttpHeader object.  This allows for a great
	  flexibility in header processing and builds basis for support
	  of yet unsupported HTTP headers.
	- Added Packer, a memory/store redirector with a printf
	  interface.  Packer allows to comm_write() or swap() an object
	  using a single routine.
	- Added MemBuf, a auto-growing memory buffer with printf
	  capabilities.  MemBuf replaces most of old local buffers for
	  compiling text messages.
	- Added MemPool that maintains a pre-allocated pool of opaque
	  objects.  Used to eliminate memory thrashing when allocating
	  small objects (e.g.  field-names and field-value in http
	  headers).

Changes to squid-1.2.beta15 (Feb 13, 1998):

