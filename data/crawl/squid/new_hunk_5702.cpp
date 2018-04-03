	  the TOS precedence bits and/or the source IP from a set of
	  available IPs based upon some ACLs, generally to map different
	  users to different outgoing links and traffic profiles.
	- Added 'max-conn' option to 'cache_peer'
	- Added SSL gatewaying support, allowing Squid to act as a SSL server
	  in accelerator setups.
	- Countless other small things and fixes
	
Changes to Squid-2.4.STABLE2 (Aug 24, 2001):

	- Expanded configure's GCC opimization disabling check to
	  include GCC 2.95.3
	- avoid negative served_date in storeTimestampsSet().
	- Made 'diskd' pathnames more configurable
	- Make sure squid parent dies if child is killed with
	  KILL signal
	- Changed diskd offset args to off_t instead of int
	- Fixed bugs #102, #101, #205: various problems with useragent
	  log files
	- Fixed bug #116: Large Age: values still cause problems
	- Fixed bug #119: Floating point exception in
	  storeDirUpdateSwapSize()
	- Fixed bug #114: usernames not logged with
	  authenticate_ip_ttl_is_strict
	- Fixed bug #115: squid eating up ressources (eventAdd args)
	- Fixed bug #125: garbage HTCP requests cause assertion
	- Fixed bug #134: 'virtual port' support ignores
	  httpd_accel_port, causes a loop in httpd_accel mode
	- Fixed bug #135: assertion failed: logfile.c:135: "lf->offset
	  <= lf->bufsz"
	- Fixed bug #137: Ranges on misses are over-done
	- Fixed bug #160: referer_log doesn't seem to work
	- Fixed bug #162: some memory leaks (SNMP, delay_pools,
	  comm_dns_incoming histogram)
	- Fixed bug #165: "Store Mem Buffer" leaks badly
	- Fixed bug #172: Ident Based ACLs fail when applied to
	  cache_peer_access
	- Fixed bug #177: LinuxPPC 2000 segfault bug due to varargs abuse
	- Fixed bug #182: 'config' cachemgr option dumps core with
	  null storage
	- Fixed bug #185: storeDiskdDirParseQ[12]() use wrong number
	  of args in debug/printf
	- Fixed bug #187: bugs in lib/base64.c
	- Fixed bug #184: storeDiskdShmGet() assertion; changed
	  diskd to use bitmap instead of linked list
	- Fixed bug #194: Compilation fails on index() on some
	  non-BSD plaforms
	- Fixed bug #197: refreshIsCachable() incorrectly checks
	  entry->mem_obj->reply
	- Fixed bug #215: NULL pointer access for proxy requests
	  in accel-only mode

Changes to Squid-2.4.STABLE1 (Mar 20, 2001):

	- Fixed a bug in and cleaned up class 2/3 delay pools
	  incrementing.
	- Fixed a coredump bug when using external dnsservers that
	  become overloaded.
	- Fixed some NULL pointer bugs for NULL storage system
	  when reconfiguring.
	- Fixed a bug with useragent logging that caused Squid to
	  think the logfile never got opened.
	- Fixed a compiling bug with --disable-unlinkd.
	- Changed src/squid.h to always use O_NONBLOCK on Solaris
	  if it is defined.
	- Fixed a bug with signed/unsigned bitfield flag variables
	  that caused problems on Solaris.
	- Fixed a bug in clientBuildReplyHeader() that could add
	  an Age: header with a negative value, causing an assertion
	  later.
	- Fixed an SNMP reporting bug.   cacheCurrentResFileDescrCnt
	  was returning the number of FDs in use, rather than
	  the number of reserved FDs.
	- Added the 'pipeline_prefetch' configuration option.
	- cache_dir syntax changed to use options instead of many
	  arguments. This means that the max_objsize argument now
	  is an optional option, and that the syntax for how to
	  specify the diskd magics is slightly differen.
	- Various fixes for CYGWIN
	- Upgraded MSNT auth module to version 2.0.
	- Fixed potential problems with HTML by making sure all
	  HTML output is properly encoded.
	- Fixed a memory initialization problem with resource records in
	  lib/rfc1035.c.
	- Rewrote date parsing in lib/rfc1123.c and made it a little
	  more lenient.
	- Added Cache-control: max-stale support.
	- Fixed 'range_offset_limit' again.  The problem this time
	  is that client_side.c wouldn't set the we_dont_do_ranges
	  flag for normal cache misses.  It was only being set for
	  requests that might have been hits, but we decided to
	  change to a miss.
	- Added the Authenticate-Info and Proxy-Authenticate-Info
	  headers from RFC 2617.
	- HTTP header lines longer than 64K could cause an assertion.
	  Now they get ignored.
	- Fixed an IP address scanning bug that caused "123.foo.com"
	  to be interpreted as an IP address.
	- Converted many structure allocations to use mem pools.
	- Changed proxy authentication to strip leading whitespace
	  from usernames after decoding.
	- Prevented NULL pointer access in aclMatchAcl().  Some
	  ACL types require checklist->request_t, but it won't be
	  available in some cases (like snmp_access).  Warn the
	  admin that the ACL can't be checked and that we're denying
	  it.
	- Allow zero-size disk caches.
	- The actual filesystem blocksize is now used to account
	  for space overheads when calculating on-disk cache size.
	- Made the maximum memory cache object size configurable.
	- Added 'minimum_direct_rtt' configuration option.
	- Added 'ie_refresh' configuration option, which is a hack
	  to turn IMS requests into no-cache requests.
	- Added Linux netfilter support for intercepted connections.
	- Fixed a bug with clientAccessCheck() that allowed proxy
	  requests in accel mode.
	- Fixed a bug with 301/302 replies from redirectors.  Now
	  we force them to be cache misses.
	- Accommodated changes to the IP-Filter ioctl() interface
	  for intercepted connections.
	- Fixed handling of client lifetime timeouts.
	- Fixed a buffer overflow bug with internal DNS replies
	  by truncating received packets to 512 bytes, as per
	  RFC 1035.
	- Added "forward.log" support, but its work in progress.
	- Rewrote much of the IP and FQDN cache implementation.
	  This change gets rid of pending hits.
	- Changed peerWouldBePinged() to return false if our 
	  ICP/HTCP port is zero (i.e. disabled).
	- Changed src/net_db.c to use src/logfile.c routines,
	  rather than stdio, because of solaris stdio filedescriptor
	  limits.
	- Made netdbReloadState() more robust in case of corrupted
	  data.
	- Rewrote some freshness/staleness functions in src/refresh.c,
	  partially inspired to support cache-control max-stale.
	- Fixed status code logging for SSL/CONNECT requests.
	- Added a hack to subtract cache digest network traffic
	  from statistics so that byte hit ratio stays positive
	  and more closely reflects what people expect it to be.
	- Fixed a bug with storeCheckTooSmall() that caused
	  internal icons and cache digests to always be released.
	- Added statfs(2) support for displaying actual filesystem
	  usage in the cache manager 'storedir' output.
	- Changed status reporting for storage rebuilding.  Now it
	  prints percentage complete instead of number of entries
	  parsed.
	- Use mkstemp() rather than problem-prone tempnam().
	- Changed urlParse() to condense multiple dots in hostnames.
	- Major rewrite of async-io (src/fs/aufs) to make it behave
	  a bit more sane with substantially less overhead.  Some
	  tuning work still remains to make it perform optimal.
	  See the start of store_asyncufs.h for all the knobs.
	- Fixed storage FS modules to use individual swap space 
	  high/low values rather than the global ones.
	- Fixed storage FS bugs with calling file_map_bit_reset()
	  before checking the bit value.  Calling with an invalid
	  value caused memory corruption in random places.
	- Prevent NULL pointer access in store_repl_lru.c for
	  entries that exist in the hash but not the LRU list.

Changes to Squid-2.4.DEVEL4 ():

	- Added --enable-auth-modules=... configure option