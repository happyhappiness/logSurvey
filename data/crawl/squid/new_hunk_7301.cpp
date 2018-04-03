	  asynchronous file operations (Stewart Forster).
	- async_io.c and async_io.h are complete rewrites of the old
	  versions (Stewart Forster).
	- Rewrote all disk file operations of squid to support
	  the idea of callbacks except where not required (Stewart
	  Forster).
	- Background validation of 'tainted' swap log entries (Stewart
	  Forster).
	- Modified storeWriteCleanLog to create the log file using the
	  open/write rather than fopen/printf (Stewart Forster).
	- Added the EINTR error response to handle badly interrupted
	  system calls (Stewart Forster).
	- UDP_HIT_OBJ not supported, removed.
	- Different sized 'cache_dirs' supported.

==============================================================================

Changes to squid-1.1.10 (April 24, 1997):

	- Require 0 <= multicast ttl <= 128.
	- Changed 'unsigned int inaddr_none' to 'struct in_addr no_addr'.
	- Added debug_trap() if unlocking a StoreEntry which still 
	  has registered clients.
	- Added missing storeUnregister() calls.
	- Fixed storeClientListAdd() bug of adding same FD twice.
	- Fixed reconfigure/SIGHUP to wait 'shutdown_lifetime' seconds
	  after receiving signal (Ron Gomes).
	- Added missing commSetSelect() in icpDetectClientClose()
	  (Mark Treacy).
	- Fixed multicast group member counting bug with fake
	  StoreEntry's.
	- Only enable ICP_FLAG_SRC_RTT if the peer is ICP_VERSION_2.
	- Fixed compiling unlinkd in a separate directory (Assar Westerlund).
	- Fixed comm_select_incoming SEGV for poll() version when using
	  udp_{incoming,outgoing}_address  (Mark Treacy).
	- Fixed some SIGHUP related memory problems with redirectors,
	  ipcache, and fqdncache, and peerCountMcastPeers*().
	- Make the unlinkd and pinger programs configurable (Ron Gomes,
	  Neil Murray).
	- Add handshake to unlinkd program (Ron Gomes).
	- Exit if a configured program doesn't exist (Neil Murray).
	- Abort if unlinkd fails to start (Ron Gomes).
	- Added -m option to ftpget for defining default MIME type.
	  (Neil Murray).
	- Optimized comm_select() functions (Mark Treacy).
	- Fixed ipcache_release() to not release locked entries;
	  instead expire them immediately.
	- Fixed up rebuild code to handle swapfile/URL clash
	  cases better.
	- Added safe_inet_addr() to protect from bogus IP addresses
	  (Arjan de Vet).
	- Fixed handling of ssl_proxy and passthrough_proxy when not
	  behind a firewall.


Changes to squid-1.1.9 (March 30, 1997):

	- Fixed aclIpNetworkCompare for USE_SPLAY_TREE; was applying
	  netmask to non-local variable through pointer.  (Ansgar
	  Hockmann).
	- Fixed cachemgr bug incorrectly assigning connect() return
	  value (Nigel Metheringham).
	- Fixed diskHandleWrite bug: not setting write_daemon = PRESENT.
	- Fixed situation where all requests would be handled by
	  "single parent" and other peers would never be queried
	  again.
	- Fixed ftpget bug causing program to continue after printing
	  usage.
	- Changed 'reference_age' to be the maximum for the dynamcially
	  computed value (Mark Treacy).
 	- Added external 'unlinkd' process to unlink swap files.
	- Added more dnsserver status information to cachemgr output.
	- In httpReadReply: extend FD lifetime only after successful
	  read, not every read.
	- In httpBuildRequestHeader: link size of 'ybuf' to MAX_URL.
	- Added routines to count number of members of each multicast
	  peer.
	- Fixed multicast ICP bug causing unnecessary timeouts.
	- Added error messages if setuid/setgid functions fail.
	- Added non-POSIX tempnam.c replacement for NeXTStep (Gerben
	  Wierda).
	- Removed redundant file:// --> ftp:// check (Willy TARREAU).
	- Removed check for reply->code == 200 in icpGetHeadersForIMS().
	- Fixed IP cache bug which caused 'dns_children 0' to break;
	- Deny access to dangerous TCP ports (7, 9, 19).
	- Removed single-line functions: fdstat_biggest_fd(),
	  comm_get_fd_lifetime(), comm_get_fd_timeout().
	- Removed storeCheckExpired() from storeGetSwapSpace() as
	  likely cause of slowing down cache when exceeding the high
	  water mark.
	- Fixed storeCheckExpired() to not always check the
	  LRU expiration age (Mark Treacy).
	- Lowered 'store_objects_per_bucket' to 20 so that
	  storeMaintainSwapSpace() runs frequently enough to 
	  keep up with incoming objects.
	- Fixed FTP to use the Authorization header only when the
	  usernames match.
	- Fixed another continuation-lines-not-starting-with-NNN bug
	  in ftpget.
	- Added 'client_db' config option to disable keeping statistics 
	  for each client address.
	- Added support for using ICMP data stuffed into ICP replies
	  for peer selection algorithm.  Enable with 'query_icmp'
	  in squid.conf.
	- Fixed net_db design bug where _net_db_peer structures pointed
	  to 'peer' structures that get freed and reallocated during a
	  reconfigure.
	- Moved comm.c fd_lifetime[] array into FD_ENTRY structure.
	- Cleaned up storeCopy().  debug_trap on requested offset <
	  e_lowest_offset.
	- Cleaned up fdstat_init() and fdstat_update().
	- Cleaned up ftp_login_parser().

Changes to squid-1.1.8 (March 3, 1997):

	- Fixed neighborsUdpAck() coredump bug for source-ping and
