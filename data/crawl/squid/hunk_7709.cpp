-
 Changes to squid-1.1.alpha2:
 
 	- Added Support for RFC931/ident
 
-==============================================================================
+Changes to squid-1.0.1 (July 8, 1996):
+
+	- Fixed ftpget server looping on socket EOF condition.
+	- Fixed SA_RESETHAND undefined bug.
+	- Fixed half-hour timezone offset bug.
+	- Fixed parse_rfc850() to return -1 instead of 0 upon error.
+	- Added patch for Motorola systems from Tony Lorimer.
+	- Added support for HTTP PUT method.
+	- Added check for <netinet/tcp.h> for HP-UX.
+	- Added GNU General Public License.
+	- Changed ttlSet() to use Date field if Last-Modified is absent.
+	- Changed http.c to not save objects from neighbors which do
+	  not have Date, Last-Modified, or Expires values.
+	- Changed some large local character arrays to static.
+
+Changes to squid-1.0.0 (July 1, 1996):
+
+	- Fixed beta17 "fd_lifetime" typo bug
+	- Added 'firewall_ip_list' to configuration options
+	- Set resolver options to disable searching default domains
+	  and parent domains.
+	- Added blocking-rebuild -F option.
+	- Fixed storeMaintainSwapSpace to be called every 10 seconds.
+	- Fixed ICP_HIT_OBJ bug causing objects to get stuck in VM.
+	- Fixed matching the ends of domain names (e.g. bar.com no 
+	  longer matches foobar.com).
+	- Fixed checking return code from fprintf() while writing the
+	  clean swap log.
+	- Fixed fatal_dump from storeSwapoutHandle running out of disk
+	  space.
+	- Added disabling of a neighbor cache if 95% of replies are
+	  UDP_DENIED.
+	- Added accounting for misc memory/data structures
+	- Added 'no-query' option for 'cache_host' config line
+	- Added error reporting to SSL requests.
+	- Fixed SSL bug, client abort was not closing the server
+	  side connection.
+	- Fixed checking hierarchy_stoplist bug.
+	- Fixed ipcache error messages by giving each entry its
+	  own string.
+	- Use sigaction() instead of signal() if available.
+	- Fixed ipcache bug causing some lookups to get stuck in
+	  PENDING state if all dnsservers are busy.
+	- Fixed domain name matching bug when using '.com' instead of
+	  'com'.
+	- Fixed close_handler coredump bug in comm.c.
+	- Removed unnecessary DNS lookup of hostnames in WAIS URLs.
+
+Changes to squid-1.0.beta17 (June 12, 1996):
+
+	- Fixed another ipcache coredump problem where an entry could
+	  be released between writing to and reading from dnsserver.
+	- Fixed store.c bug of purging aborted objects.
+	- Cleaned up checkLifetimes() function to make it simpler.
+	- Added visible_hostname support to ftpget.
+	- Fixed null edge dereferencing bug for UDP_HIT_OBJ.
+
+Changes to squid-1.0.beta16 (June 10, 1996):
+
+	- Fixed two coredump-causing bugs in ipcache_unregister().
+	- Changed 'close_handler' to a linked list.
+	- Changed freeing of protodispatch_data structures to use
+	  new close_handler (attached to client FD).
+	- Fixed URL handling to accomodate browswers which do not handle
+	  relative URL parsing.
+
+Changes to squid-1.0.beta15 (June 9, 1996):
+
+	- Fixed storeSwapoutHandle coredump bug
+	- Fixed DNS lookup failure of neighbor hosts after a few hours
+	  of operation
+	- Changed memcpy() to memmove() for overlapping memory copies
+	- Changed store rebuidling to unlink the log-last-clean file
+	  in case of a crash during rebuild
+	- Added forwarding loop detection
+	- Changed all memcpy to use xmemcpy which is memmove, bcopy, or
+	  memcpy.
+	- Fixed coredump bug from partial dnsserver reads, manifest on
+	  FreeBSD and NetBSD.
+
+Changes to squid-1.0.beta14 (June 7, 1996):
+
+	- Fixed coredump bug in icp.c when generating ``Not Modified''
+	  replies.
+	- Fixed SSL bug which assumed the requested host name would
+	  already be in the IP cache.
+	- Fixed names of generated HTTP reply headers.
+
+Changes to squid-1.0.beta13 (June 7, 1996):
+
+	- Fixed coredump bug where StoreEntry key was free'd too soon.
+	- Fixed UDP_HIT_OBJ bug: cancel the hierarchy timeout and set
+	  the ping_status to DONE for UDP_HIT_OBJ replies.
+
+Changes to squid-1.0.beta12 (June 6, 1996):
+
+	- Fixed problem when using udp_outgoing_addr where no ICP
+	  packets would be recieved because they were getting sent
+	  to the "outgoing" instead of the "incoming" socket.
+	- Fixed objects hanging around in cache after a keychange.
+	- Added ability to restrict neighbor caches with ACLs.
+	  ('cache_host_acl').
+	- Fixed ssl FD mismatch bug.
+	- Fixed INADDR_NONE bug on 64bit systems.
+	- Fixed store rebuilding bug; temporary log file was not being
+	  truncated.
+	- Made all external processes communicate with TCP sockets
+	  (no more Unix domain sockets).
+	- Semi-major rewrite of ipcache implementation.
+	- Fixed a couple memory bugs found by purify.
+	- Fixed sending large (>8192 bytes) HTTP requests.
+	- Added "lazy" server IP address ACL checks (type 'dst').
+	- Changed handling of IMS requests.  Now will return "304
+	  Not Modified" if the requested object is in the cache
+	  and not expired.
+
+Changes to squid-1.0.beta11 (June 1, 1996):
+
+	- Fixed serious memory leak of MemObject->reply structures.
+
+
+Changes to squid-1.0.beta10 (May 31, 1996):
+
+	- Fixed bug when request arrives in fragmented IP packets.
+	- Fixed ACL bug which denied cache manager access while in
+ 	  httpd_accel mode.
+	- Changed ftpget to "fail nicely" for sites which do not allow
+	  PORT requests (if compiled with PASVONLY).
+	- Fixed Unix domain socket off-by-one bug in ftpget.
+	- Fixed lingering sockets after shutdown by SIGTERM.
+	- Added dnsserver use histogram to ipcache stats.
+	- Changed domain ACL's to match only the end of the hostname, not
+	  just anywhere in the string.
+	- Fixed setuid bugs when pid_filename was not defined
+	- Fixed zero-sized object getting stuck in VM.
+	- Configure checks for working UNIX domain stream sockets
+	- Rotate cache.log before the others
+	- SIGUSR2 now toggles between full and normal debugging
+	- Close and restart ftpget server during logfile rotation
+	- Added memory pools for request_t and MemObject data structures.
+	- Added new address binding options for more control
+
+Changes to squid-1.0.beta9 (May 23, 1996):
+
+	- Fixed storeToString() coredump bug on 'swap_buf'
+	- Added back the CIDR notation functionality to decoding IP
+	  address ACLs.
+	- Fixed ftpget listing parsing coredump bug.
+	- Fixed neighborsUdpAck() coredump for late-arriving ICP replies.
+
+Changes to squid-1.0.beta8 (May 22, 1996):
+
+	- More friendly CFLAGS and LDFLAGS for configure
+	- ACL_ALLWEEK bugfix
+	- Added missing increment of UDP connection counter.
+	- Changed ftpget select to check for EWOULDBLOCK/EAGAIN
+	  (workaround for broken Solaris select(2)).
+	- Fixed MALLINFO calls for Linux
+	- Fixed strerror() problems on SunOS 4.1.x
+	- Fixed DefaultAnnounceRate; set to zero by defult.
+	- Changed all port variables to u_short.
+	- Created AF_UNIX versions of comm_open(), comm_connect().
+	- Changed ftpget server to use UNIX domain socket.
+	- Removed RESET_SIGNAL_HANDLER check--always reset the signal
+	  handler.
+	- Added instrumentation of basic IPCache stats.
+	- Fixed calculation of neighbor average RTT.
+	- Added 'outbound_addr_list' to config
+	- Change getFirstParent() to getFirstUpParent().
+	- Changed ftpget to use an additional pipe() for crash detection
+	- Added ICP_OP_DENIED message type
+	- Added patches for Nextstep port from Luke Howard
+	  <lukeh@vurt.schnet.edu.au>
+	- Added a lifetime to HTTP server connections being deferred.
+	- Added IP address ranges in 'src' ACLs
+	- Added FQDN's in 'src' ACLs
+	- Fixed request structure free-memory-read/coredump bug.
+	- Changed icp.c to select on client socket to detect aborts.
+	- Better compliance with HTTP/1.1 *DRAFT* regarding which reply
+	  codes can be cached.
+	- Added 'hierarchy_stoplist' configuration option.
+	- Changed mallopt option M_MXFAST to 512 bytes.
+	- Added -Y option to only return UDP_HIT or UDP_DENIED during
+	  store reload.
+	- Added UDP_HIT_OBJ type.  Just like a UDP_HIT, but object data
+	  is returned in the UDP packet if it will fit; saves a TCP
+	  connection.  Not compiled in by default, add -DUDP_HIT_WITH_OBJ
+	  to src/Makefile DEFINES.
+
+Changes to squid-1.0.beta7:
+
+	- Fixed comm_udp_sendto continuous loop bug
+	- Fixed URLs-with-colon-but-no-port-number bug
+	- Fixed sending ICP queries for HEAD requests
+	- Changed 'server_list' output.  Added RTT, Fetches, Hits, Misses,
+	  and percents.
+	- Fixed setuid bug causing some logs to be owned by root.
+	- Fixed virtual host mode (-V option)
+	- Added read(2) instrumentation for HTTP and FTP.
+	- Changed neighbor initialization to continue if DNS lookup fails.
+	- Lint cleanup
+
+Changes to squid-1.0.beta6:
+
+	- Fixed null error message coredump in ftpget.
+	- Added -m Method option to `client'.
+	- Fixed ftpget server bug with missing trailing slash.
+	- Removed 'connect_ports' from config, use general ACLs instead.
+	- Changed requested listen queue length to 1/4 of getMaxFD().
+	- Rewrote SSL/CONNECT handlers.  Now doesn't use a StoreEntry.
+	- Fixed some aborted objects getting stuck in VM bug.
+	- Fixed ftpget PASV reply sscanf to work for VMS ftpd.
+	- Changed FTP URL parsing to use urlParse().
+	- Changed ftpget to skip RETR command if URLs ends with '/'.
+	- Changed ftpget to display README at the bottom if there are other
+	  server messages.
+	- Changed ftpget to not reopen a new data connection
+  	  if one is already open.
+	- Fixed handling of FTP URLs with spaces (and other unsafe characters)
+	- Changed ftpget to only generate BASE HREF if the FTP URL does
+	  not end with '/'.
+
+Changes to squid-1.0.beta5:
+
+	- Fixed cachemgr to send 'HTTP/1.0' on request so it works
+	  with beta4 fixes to icp.c.
+
+Changes to squid-1.0.beta4:
+
+	- Added a handler to restart the ftpget server.
+	- Fixed access checks for ICP by parsing the requested URL.
+	- Added "magic marker" to ftpget-generated errors so they can
+	  be negative-cached.
+	- Added a small run-time check to configure to see if signal
+	  handlers should be restarted after invocation (ala SYSV).
+	- Determine Maximum filedescriptors in configure and change
+	  FD_SETSIZE if needed.
+	- Changed read stall algorithm for HTTP.  No don't wait until
+	  the object is in DELETE_BEHIND mode to stall the server read
+	  and wait for the client to catch up.  Also changed from 4k to
+	  16k read buffer.
+	- Fixed HTTP request parsing to check for blank line at the
+	  end of all requests.  Symptoms were "connection reset"
+	  messages.
+
+Changes to squid-1.0.beta3:
+
+	- Added ftpget '-C minport:maxport' option
+	- Fixed PROTO_MAX fencepost bug in stat_init().
+	- Fixed Fixed CheckQuickAbort() coredump.
+	- Fixed disabling store.log and hierarchy.log when set to "none"
+	- Fixed numerous problems related to setuid().
+	- Fixed 'check_cache.pl' to use new swaplog format (without "FILE").
+	- Fixed ACL coredumps when checking NULL words.
+	- Changed pid_filename to be written and unlinked as root.
+	- Added "-i seconds" option to 'client' for testing IMS GET.
+	- Fixed a bug where an IMS request caused the valid object to
+	  get ejected from the cache.
+	- Fixed continual DEAD_PARENT/REVIVE bug
+	- Fixed ERR_INVALID_URL bug for URLs with a password field.
+	- Added to Release-Notes info about converting 'cache/log' and
+	  difference between stoplists and ttl_pattern.
+
+Changes to squid-1.0.beta2:
+
+	- Fixed /bin/csh "$#argv" leftover in RunCache.
+	- Fixed ACL day-of-week bitmask bug.
+	- Fixed missing checks for WAIS in some places.
+	- Fixed chdir(swappath(0)) bug; do chdir() after storeInit().
+	- Changed enumerated structure members to be defined outside
+	  of the structure itself (for AIX).
+	- Changed ftpget to fork before reading the request and make
+	  sure the entire request is read.
 
 Changes to squid-1.0.beta1 (Apr 19, 1996) from Harvest cached-1.4.pl3:
 
