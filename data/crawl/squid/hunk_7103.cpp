 
 ==============================================================================
 
+Changes to squid-1.1.14 (July 11, 1997):
+
+	- Another try at log_url crap.  Added icpState->log_url
+	  member.  Set mem_obj->log_url in new_MemObject() which
+	  means passing more args to storeCreateEntry().  Also added
+	  urlClean() which calls urlParse(); needed for ICP logging.
+	- Clean URLs will be truncated at '?' if present.
+	- Give fd_note() the clean URL.
+
+Changes to squid-1.1.13 (July 9, 1997):
+
+	- Fixed storeLog() coredump on mem->log_url.
+	- Fixed string bounds bug if a redirector returns a short
+	  hostname which require appending 'append_domain' (David
+	  Lamkin).
+	- Added 'fake_user_agent' to configuration because HTTP
+	  anonymizing strips the User-Agent which some servers require.
+
+Changes to squid-1.1.12 (July 5, 1997):
+
+	- Fixed dnsserver buffer overflow bug and other problems related
+	  to long, bogus domain names.
+	- Fixed occasional incorrect ERR_DNS_FAIL errors caused when
+	  an IP cache entry gets released about the same time an
+	  ICP query timeout occurs.
+	- Fixed setrlimit() bugs seen on DUNIX 4.0; rl.rlim_max == 0.
+	- Only strip 'Proxy-authorization' header when USE_PROXY_AUTH
+	  is defined and proxy_auth is configured (Ron Gomes).
+	- Added missing calls to reset socket timeouts for SSL
+	  and passthrough requests.
+	- Fixed "Available number of file descriptors" value in
+	  cachemgr info output.
+	- Fixed coredump in proxyAuthenticate() if password file
+	  has an entry with only a user name (Jordan Hrycaj).
+	- Security patch for usernames and passwords in URLs.
+	  + ftpget would insert a BASE URL including the username and
+	    password for directory listings IF the original request did
+	    NOT include the the trailing slash.  This could be disabled
+	    with a command line option, but is enabled by default.  Now
+	    its #ifdefd out.
+	  + Usernames and passwords could be logged to access.log and
+	    store.log.  Now a new element,
+	    StoreEntry->MemObject->log_url, holds a copy of the requested
+	    URL without the name and password.  This isn't 100% fixed yet
+	    because log_url gets generated when the StoreEntry gets
+	    created.  If the StoreEntry never gets created, then the URL
+	    with name and password will get logged.  Also, the name and
+	    password are not stripped from ICP requests.  Also, this
+	    changes store.log.  Previously we logged StoreEntry->key
+	    which would look different than the URL for private entries,
+	    but now we'll always log the URL.
+	  + Finally, we now set REQ_AUTH for any request that includes a
+	    name or password.  This prevents the request from being
+	    cached (!) and prevents it from being sent to neighbor
+	    caches.  In other words, its treated just as if an
+	    Authorization request header were present.
+	- Fixed Byte-Range handling so that valid, whole objects
+	  are not released.
+
+Changes to squid-1.1.11 (June 14, 1997):
+
+	- Clean up NeXTStep compiler warnings (Karsten Heinze, Ed Knowles).
+	- Don't forward 'Proxy-Authorization' headers (Chris Pascoe).
+	- Fixed up Host: header parsing (Henrik Nordstrom).
+	- Changed DefaultObjectsPerBucket to 20 in cache_cf.c.
+	- Fixed parsePathname() bug for magic word "none".
+	- Fixed ipcache_release to rename entries which get stuck with locks.
+	- Fixed "eventDelete(peerCheckConnect, e);" bug when the DNS lookup
+	  is pending.
+	- Add sys/types.h to lib/safe_inet_addr.c for NeXTSTEP (Timo
+	  Hennerich).
+	- Fixed cur_len decrement bug in diskHandleRead()
+	  (Michael O'Reilly).
+	- Added contrib/rredir.pl from Peter Eisenhauer.
+	- Always forward requests with 'Byte-Range' headers (Ron Gomes).
+	- Fixed StoreEntry client offset bug which could trigger a
+	  fatal_dump().
+	- Fixed noticing that dnsservers have shut down during restart.
+	- Added contrib/nextstep installer package from Gerben Wierda.
+	- Modified storeDirClean() to remove swap files where the
+	  number is being used, but the file is in the wrong directory.
+	- Allow PURGE method on all protocols.
+	- Added 'icp_hit_stale' option.
+	- Fixed proxy auth refresh bug (Chris Pascoe).
+	- Don't check for other filename extensions if an FTP URL
+	  ends with .txt (Ed Knowles).
+	- Relocated ERR_NO_CLIENT_BIG_OBJ check to eliminate incorrect
+	  (but harmless) error message.
+
 Changes to squid-1.1.10 (April 24, 1997):
 
 	- Require 0 <= multicast ttl <= 128.
