 /* log_quote -- URL-style encoding on MIME headers. */
 
 char *
-log_quote(const char *header)
+log_quote (const char *header)
 {
-    int c;
-    int i;
-    char *buf;
-    char *buf_cursor;
-    if (header == NULL) {
-	buf = xcalloc(1, 1);
-	*buf = '\0';
-	return buf;
+  int c;
+  int i;
+  char *buf;
+  char *buf_cursor;
+  if (header == NULL)
+    {
+      buf = xcalloc (1, 1);
+      *buf = '\0';
+      return buf;
     }
-    buf = xcalloc((strlen(header) * 3) + 1, 1);
-    buf_cursor = buf;
-    /*
-     * We escape: \x00-\x1F"#%;<>?{}|\\\\^~`\[\]\x7F-\xFF 
-     * which is the default escape list for the CPAN Perl5 URI module
-     * modulo the inclusion of space (x40) to make the raw logs a bit
-     * more readable.
-     */
-    while ((c = *(const unsigned char *) header++) != '\0') {
+  buf = xcalloc (1, (strlen (header) * 3) + 1);
+  buf_cursor = buf;
+  /*
+   * We escape: \x00-\x1F"#%;<>?{}|\\\\^~`\[\]\x7F-\xFF 
+   * which is the default escape list for the CPAN Perl5 URI module
+   * modulo the inclusion of space (x40) to make the raw logs a bit
+   * more readable.
+   */
+  while ((c = *(const unsigned char *) header++) != '\0')
+    {
 #if !OLD_LOG_MIME
-	if (c == '\r') {
-	    *buf_cursor++ = '\\';
-	    *buf_cursor++ = 'r';
-	} else if (c == '\n') {
-	    *buf_cursor++ = '\\';
-	    *buf_cursor++ = 'n';
-	} else
+      if (c == '\r')
+	{
+	  *buf_cursor++ = '\\';
+	  *buf_cursor++ = 'r';
+	}
+      else if (c == '\n')
+	{
+	  *buf_cursor++ = '\\';
+	  *buf_cursor++ = 'n';
+	}
+      else
 #endif
-	    if (c <= 0x1F
-		|| c >= 0x7F
+	if (c <= 0x1F
+	    || c >= 0x7F
 #if OLD_LOG_MIME
-		|| c == '"'
-		|| c == '#'
-		|| c == '%'
-		|| c == ';'
-		|| c == '<'
-		|| c == '>'
-		|| c == '?'
-		|| c == '{'
-		|| c == '}'
-		|| c == '|'
-		|| c == '\\'
-		|| c == '^'
-		|| c == '~'
-		|| c == '`'
+	    || c == '"'
+	    || c == '#'
+	    || c == '%'
+	    || c == ';'
+	    || c == '<'
+	    || c == '>'
+	    || c == '?'
+	    || c == '{'
+	    || c == '}'
+	    || c == '|'
+	    || c == '\\'
+	    || c == '^'
+	    || c == '~'
+	    || c == '`'
 #endif
-		|| c == '['
-	    || c == ']') {
-	    *buf_cursor++ = '%';
-	    i = c * 2;
-	    *buf_cursor++ = c2x[i];
-	    *buf_cursor++ = c2x[i + 1];
+	    || c == '['
+	    || c == ']')
+	{
+	  *buf_cursor++ = '%';
+	  i = c * 2;
+	  *buf_cursor++ = c2x[i];
+	  *buf_cursor++ = c2x[i + 1];
 #if !OLD_LOG_MIME
-	} else if (c == '\\') {
-	    *buf_cursor++ = '\\';
-	    *buf_cursor++ = '\\';
+	}
+      else if (c == '\\')
+	{
+	  *buf_cursor++ = '\\';
+	  *buf_cursor++ = '\\';
 #endif
-	} else {
-	    *buf_cursor++ = (char) c;
+	}
+      else
+	{
+	  *buf_cursor++ = (char) c;
 	}
     }
-    *buf_cursor = '\0';
-    return buf;
+  *buf_cursor = '\0';
+  return buf;
 }
 
 static char *
-username_quote(const char *header)
+username_quote (const char *header)
 /* copy of log_quote. Bugs there will be found here */
 {
-    int c;
-    int i;
-    char *buf;
-    char *buf_cursor;
-    if (header == NULL) {
-	buf = xcalloc(1, 1);
-	*buf = '\0';
-	return buf;
+  int c;
+  int i;
+  char *buf;
+  char *buf_cursor;
+  if (header == NULL)
+    {
+      buf = xcalloc (1, 1);
+      *buf = '\0';
+      return buf;
     }
-    buf = xcalloc((strlen(header) * 3) + 1, 1);
-    buf_cursor = buf;
-    /*
-     * We escape: space \x00-\x1F and space (0x40) and \x7F-\xFF
-     * to prevent garbage in the logs. CR and LF are also there just in case. 
-     */
-    while ((c = *(const unsigned char *) header++) != '\0') {
-	if (c == '\r') {
-	    *buf_cursor++ = '\\';
-	    *buf_cursor++ = 'r';
-	} else if (c == '\n') {
-	    *buf_cursor++ = '\\';
-	    *buf_cursor++ = 'n';
-	} else if (c <= 0x1F
-		|| c >= 0x7F
-	    || c == ' ') {
-	    *buf_cursor++ = '%';
-	    i = c * 2;
-	    *buf_cursor++ = c2x[i];
-	    *buf_cursor++ = c2x[i + 1];
-	} else {
-	    *buf_cursor++ = (char) c;
+  buf = xcalloc (1, (strlen (header) * 3) + 1);
+  buf_cursor = buf;
+  /*
+   * We escape: space \x00-\x1F and space (0x40) and \x7F-\xFF
+   * to prevent garbage in the logs. CR and LF are also there just in case. 
+   */
+  while ((c = *(const unsigned char *) header++) != '\0')
+    {
+      if (c == '\r')
+	{
+	  *buf_cursor++ = '\\';
+	  *buf_cursor++ = 'r';
+	}
+      else if (c == '\n')
+	{
+	  *buf_cursor++ = '\\';
+	  *buf_cursor++ = 'n';
+	}
+      else if (c <= 0x1F
+	       || c >= 0x7F
+	       || c == ' ')
+	{
+	  *buf_cursor++ = '%';
+	  i = c * 2;
+	  *buf_cursor++ = c2x[i];
+	  *buf_cursor++ = c2x[i + 1];
+	}
+      else
+	{
+	  *buf_cursor++ = (char) c;
 	}
     }
-    *buf_cursor = '\0';
-    return buf;
+  *buf_cursor = '\0';
+  return buf;
 }
 
 static char *
-accessLogFormatName(const char *name)
+accessLogFormatName (const char *name)
 {
-    if (NULL == name)
-	return NULL;
-    return username_quote(name);
+  if (NULL == name)
+    return NULL;
+  return username_quote (name);
 }
 
 static void
-accessLogSquid(AccessLogEntry * al)
+accessLogSquid (AccessLogEntry * al)
 {
-    const char *client = NULL;
-    char *user = NULL;
-    if (Config.onoff.log_fqdn)
-	client = fqdncache_gethostbyaddr(al->cache.caddr, FQDN_LOOKUP_IF_MISS);
-    if (client == NULL)
-	client = inet_ntoa(al->cache.caddr);
-    user = accessLogFormatName(al->cache.authuser ?
-	al->cache.authuser : al->cache.rfc931);
-    logfilePrintf(logfile, "%9d.%03d %6d %s %s/%03d %d %s %s %s %s%s/%s %s",
-	(int) current_time.tv_sec,
-	(int) current_time.tv_usec / 1000,
-	al->cache.msec,
-	client,
-	log_tags[al->cache.code],
-	al->http.code,
-	al->cache.size,
-	al->private.method_str,
-	al->url,
-	user ? user : dash_str,
-	al->hier.ping.timedout ? "TIMEOUT_" : "",
-	hier_strings[al->hier.code],
-	al->hier.host,
-	al->http.content_type);
-    safe_free(user);
+  const char *client = NULL;
+  char *user = NULL;
+  if (Config.onoff.log_fqdn)
+    client = fqdncache_gethostbyaddr (al->cache.caddr, FQDN_LOOKUP_IF_MISS);
+  if (client == NULL)
+    client = inet_ntoa (al->cache.caddr);
+  user = accessLogFormatName (al->cache.authuser ?
+			      al->cache.authuser : al->cache.rfc931);
+  logfilePrintf (logfile, "%9d.%03d %6d %s %s/%03d %d %s %s %s %s%s/%s %s",
+		 (int) current_time.tv_sec,
+		 (int) current_time.tv_usec / 1000,
+		 al->cache.msec,
+		 client,
+		 log_tags[al->cache.code],
+		 al->http.code,
+		 al->cache.size,
+		 al->private.method_str,
+		 al->url,
+		 user ? user : dash_str,
+		 al->hier.ping.timedout ? "TIMEOUT_" : "",
+		 hier_strings[al->hier.code],
+		 al->hier.host,
+		 al->http.content_type);
+  safe_free (user);
 }
 
 static void
-accessLogCommon(AccessLogEntry * al)
+accessLogCommon (AccessLogEntry * al)
 {
-    const char *client = NULL;
-    char *user1 = NULL, *user2 = NULL;
-    if (Config.onoff.log_fqdn)
-	client = fqdncache_gethostbyaddr(al->cache.caddr, 0);
-    if (client == NULL)
-	client = inet_ntoa(al->cache.caddr);
-    user1 = accessLogFormatName(al->cache.authuser);
-    user2 = accessLogFormatName(al->cache.rfc931);
-    logfilePrintf(logfile, "%s %s %s [%s] \"%s %s HTTP/%d.%d\" %d %d %s:%s",
-	client,
-	user2 ? user2 : dash_str,
-	user1 ? user1 : dash_str,
-	mkhttpdlogtime(&squid_curtime),
-	al->private.method_str,
-	al->url,
-	al->http.version.major, al->http.version.minor,
-	al->http.code,
-	al->cache.size,
-	log_tags[al->cache.code],
-	hier_strings[al->hier.code]);
-    safe_free(user1);
-    safe_free(user2);
+  const char *client = NULL;
+  char *user1 = NULL, *user2 = NULL;
+  if (Config.onoff.log_fqdn)
+    client = fqdncache_gethostbyaddr (al->cache.caddr, 0);
+  if (client == NULL)
+    client = inet_ntoa (al->cache.caddr);
+  user1 = accessLogFormatName (al->cache.authuser);
+  user2 = accessLogFormatName (al->cache.rfc931);
+  logfilePrintf (logfile, "%s %s %s [%s] \"%s %s HTTP/%d.%d\" %d %d %s:%s",
+		 client,
+		 user2 ? user2 : dash_str,
+		 user1 ? user1 : dash_str,
+		 mkhttpdlogtime (&squid_curtime),
+		 al->private.method_str,
+		 al->url,
+		 al->http.version.major, al->http.version.minor,
+		 al->http.code,
+		 al->cache.size,
+		 log_tags[al->cache.code],
+		 hier_strings[al->hier.code]);
+  safe_free (user1);
+  safe_free (user2);
 }
 
 void
-accessLogLog(AccessLogEntry * al)
+accessLogLog (AccessLogEntry * al)
 {
-    if (LogfileStatus != LOG_ENABLE)
-	return;
-    if (al->url == NULL)
-	al->url = dash_str;
-    if (!al->http.content_type || *al->http.content_type == '\0')
-	al->http.content_type = dash_str;
-    if (al->icp.opcode)
-	al->private.method_str = icp_opcode_str[al->icp.opcode];
-    else
-	al->private.method_str = RequestMethodStr[al->http.method];
-    if (al->hier.host[0] == '\0')
-	xstrncpy(al->hier.host, dash_str, SQUIDHOSTNAMELEN);
-
-    if (Config.onoff.common_log)
-	accessLogCommon(al);
-    else
-	accessLogSquid(al);
-    if (Config.onoff.log_mime_hdrs) {
-	char *ereq = log_quote(al->headers.request);
-	char *erep = log_quote(al->headers.reply);
-	logfilePrintf(logfile, " [%s] [%s]\n", ereq, erep);
-	safe_free(ereq);
-	safe_free(erep);
-    } else {
-	logfilePrintf(logfile, "\n");
+  if (LogfileStatus != LOG_ENABLE)
+    return;
+  if (al->url == NULL)
+    al->url = dash_str;
+  if (!al->http.content_type || *al->http.content_type == '\0')
+    al->http.content_type = dash_str;
+  if (al->icp.opcode)
+    al->private.method_str = icp_opcode_str[al->icp.opcode];
+  else
+    al->private.method_str = RequestMethodStr[al->http.method];
+  if (al->hier.host[0] == '\0')
+    xstrncpy (al->hier.host, dash_str, SQUIDHOSTNAMELEN);
+
+  if (Config.onoff.common_log)
+    accessLogCommon (al);
+  else
+    accessLogSquid (al);
+  if (Config.onoff.log_mime_hdrs)
+    {
+      char *ereq = log_quote (al->headers.request);
+      char *erep = log_quote (al->headers.reply);
+      logfilePrintf (logfile, " [%s] [%s]\n", ereq, erep);
+      safe_free (ereq);
+      safe_free (erep);
+    }
+  else
+    {
+      logfilePrintf (logfile, "\n");
     }
-    logfileFlush(logfile);
+  logfileFlush (logfile);
 #if MULTICAST_MISS_STREAM
-    if (al->cache.code != LOG_TCP_MISS)
-	(void) 0;
-    else if (al->http.method != METHOD_GET)
-	(void) 0;
-    else if (mcast_miss_fd < 0)
-	(void) 0;
-    else {
-	unsigned int ibuf[365];
-	size_t isize;
-	xstrncpy((char *) ibuf, al->url, 364 * sizeof(int));
-	isize = ((strlen(al->url) + 8) / 8) * 2;
-	if (isize > 364)
-	    isize = 364;
-	mcast_encode((unsigned int *) ibuf, isize,
-	    (const unsigned int *) Config.mcast_miss.encode_key);
-	comm_udp_sendto(mcast_miss_fd,
-	    &mcast_miss_to, sizeof(mcast_miss_to),
-	    ibuf, isize * sizeof(int));
+  if (al->cache.code != LOG_TCP_MISS)
+    (void) 0;
+  else if (al->http.method != METHOD_GET)
+    (void) 0;
+  else if (mcast_miss_fd < 0)
+    (void) 0;
+  else
+    {
+      unsigned int ibuf[365];
+      size_t isize;
+      xstrncpy ((char *) ibuf, al->url, 364 * sizeof (int));
+      isize = ((strlen (al->url) + 8) / 8) * 2;
+      if (isize > 364)
+	isize = 364;
+      mcast_encode ((unsigned int *) ibuf, isize,
+		    (const unsigned int *) Config.mcast_miss.encode_key);
+      comm_udp_sendto (mcast_miss_fd,
+		       &mcast_miss_to, sizeof (mcast_miss_to),
+		       ibuf, isize * sizeof (int));
     }
 #endif
 }
 
 void
-accessLogRotate(void)
+accessLogRotate (void)
 {
 #if FORW_VIA_DB
-    fvdbClear();
+  fvdbClear ();
 #endif
-    if (NULL == logfile)
-	return;
-    logfileRotate(logfile);
+  if (NULL == logfile)
+    return;
+  logfileRotate (logfile);
 #if HEADERS_LOG
-    logfileRotate(headerslog);
+  logfileRotate (headerslog);
 #endif
 }
 
 void
-accessLogClose(void)
+accessLogClose (void)
 {
-    logfileClose(logfile);
-    logfile = NULL;
+  logfileClose (logfile);
+  logfile = NULL;
 #if HEADERS_LOG
-    logfileClose(headerslog);
-    headerslog = NULL;
+  logfileClose (headerslog);
+  headerslog = NULL;
 #endif
 }
 
 void
-hierarchyNote(HierarchyLogEntry * hl,
-    hier_code code,
-    const char *cache_peer)
+hierarchyNote (HierarchyLogEntry * hl,
+	       hier_code code,
+	       const char *cache_peer)
 {
-    assert(hl != NULL);
-    hl->code = code;
-    xstrncpy(hl->host, cache_peer, SQUIDHOSTNAMELEN);
+  assert (hl != NULL);
+  hl->code = code;
+  xstrncpy (hl->host, cache_peer, SQUIDHOSTNAMELEN);
 }
 
 void
-accessLogInit(void)
+accessLogInit (void)
 {
-    assert(sizeof(log_tags) == (LOG_TYPE_MAX + 1) * sizeof(char *));
-    if (strcasecmp(Config.Log.access, "none") == 0)
-	return;
-    logfile = logfileOpen(Config.Log.access, MAX_URL << 1, 1);
-    LogfileStatus = LOG_ENABLE;
+  assert (sizeof (log_tags) == (LOG_TYPE_MAX + 1) * sizeof (char *));
+  if (strcasecmp (Config.Log.access, "none") == 0)
+    return;
+  logfile = logfileOpen (Config.Log.access, MAX_URL << 1, 1);
+  LogfileStatus = LOG_ENABLE;
 #if HEADERS_LOG
-    headerslog = logfileOpen("/usr/local/squid/logs/headers.log", 512);
-    assert(NULL != headerslog);
+  headerslog = logfileOpen ("/usr/local/squid/logs/headers.log", 512);
+  assert (NULL != headerslog);
 #endif
 #if FORW_VIA_DB
-    fvdbInit();
+  fvdbInit ();
 #endif
 #if MULTICAST_MISS_STREAM
-    if (Config.mcast_miss.addr.s_addr != no_addr.s_addr) {
-	memset(&mcast_miss_to, '\0', sizeof(mcast_miss_to));
-	mcast_miss_to.sin_family = AF_INET;
-	mcast_miss_to.sin_port = htons(Config.mcast_miss.port);
-	mcast_miss_to.sin_addr.s_addr = Config.mcast_miss.addr.s_addr;
-	mcast_miss_fd = comm_open(SOCK_DGRAM,
-	    0,
-	    Config.Addrs.udp_incoming,
-	    Config.mcast_miss.port,
-	    COMM_NONBLOCKING,
-	    "Multicast Miss Stream");
-	if (mcast_miss_fd < 0)
-	    fatal("Cannot open Multicast Miss Stream Socket");
-	debug(46, 1) ("Multicast Miss Stream Socket opened on FD %d\n",
-	    mcast_miss_fd);
-	mcastSetTtl(mcast_miss_fd, Config.mcast_miss.ttl);
-	if (strlen(Config.mcast_miss.encode_key) < 16)
-	    fatal("mcast_encode_key is too short, must be 16 characters");
+  if (Config.mcast_miss.addr.s_addr != no_addr.s_addr)
+    {
+      memset (&mcast_miss_to, '\0', sizeof (mcast_miss_to));
+      mcast_miss_to.sin_family = AF_INET;
+      mcast_miss_to.sin_port = htons (Config.mcast_miss.port);
+      mcast_miss_to.sin_addr.s_addr = Config.mcast_miss.addr.s_addr;
+      mcast_miss_fd = comm_open (SOCK_DGRAM,
+				 0,
+				 Config.Addrs.udp_incoming,
+				 Config.mcast_miss.port,
+				 COMM_NONBLOCKING,
+				 "Multicast Miss Stream");
+      if (mcast_miss_fd < 0)
+	fatal ("Cannot open Multicast Miss Stream Socket");
+      debug (46, 1) ("Multicast Miss Stream Socket opened on FD %d\n",
+		     mcast_miss_fd);
+      mcastSetTtl (mcast_miss_fd, Config.mcast_miss.ttl);
+      if (strlen (Config.mcast_miss.encode_key) < 16)
+	fatal ("mcast_encode_key is too short, must be 16 characters");
     }
 #endif
 }
 
 const char *
-accessLogTime(time_t t)
+accessLogTime (time_t t)
 {
-    struct tm *tm;
-    static char buf[128];
-    static time_t last_t = 0;
-    if (t != last_t) {
-	tm = localtime(&t);
-	strftime(buf, 127, "%Y/%m/%d %H:%M:%S", tm);
-	last_t = t;
+  struct tm *tm;
+  static char buf[128];
+  static time_t last_t = 0;
+  if (t != last_t)
+    {
+      tm = localtime (&t);
+      strftime (buf, 127, "%Y/%m/%d %H:%M:%S", tm);
+      last_t = t;
     }
-    return buf;
+  return buf;
 }
 
 
 #if FORW_VIA_DB
 
 static void
-fvdbInit(void)
+fvdbInit (void)
 {
-    via_table = hash_create((HASHCMP *) strcmp, 977, hash4);
-    forw_table = hash_create((HASHCMP *) strcmp, 977, hash4);
-    cachemgrRegister("via_headers", "Via Request Headers", fvdbDumpVia, 0, 1);
-    cachemgrRegister("forw_headers", "X-Forwarded-For Request Headers",
-	fvdbDumpForw, 0, 1);
+  via_table = hash_create ((HASHCMP *) strcmp, 977, hash4);
+  forw_table = hash_create ((HASHCMP *) strcmp, 977, hash4);
+  cachemgrRegister ("via_headers", "Via Request Headers", fvdbDumpVia, 0, 1);
+  cachemgrRegister ("forw_headers", "X-Forwarded-For Request Headers",
+		    fvdbDumpForw, 0, 1);
 }
 
 static void
-fvdbCount(hash_table * hash, const char *key)
+fvdbCount (hash_table * hash, const char *key)
 {
-    fvdb_entry *fv;
-    if (NULL == hash)
-	return;
-    fv = hash_lookup(hash, key);
-    if (NULL == fv) {
-	fv = xcalloc(1, sizeof(fvdb_entry));
-	fv->hash.key = xstrdup(key);
-	hash_join(hash, &fv->hash);
+  fvdb_entry *fv;
+  if (NULL == hash)
+    return;
+  fv = hash_lookup (hash, key);
+  if (NULL == fv)
+    {
+      fv = xcalloc (1, sizeof (fvdb_entry));
+      fv->hash.key = xstrdup (key);
+      hash_join (hash, &fv->hash);
     }
-    fv->n++;
+  fv->n++;
 }
 
 void
-fvdbCountVia(const char *key)
+fvdbCountVia (const char *key)
 {
-    fvdbCount(via_table, key);
+  fvdbCount (via_table, key);
 }
 
 void
-fvdbCountForw(const char *key)
+fvdbCountForw (const char *key)
 {
-    fvdbCount(forw_table, key);
+  fvdbCount (forw_table, key);
 }
 
 static void
-fvdbDumpTable(StoreEntry * e, hash_table * hash)
+fvdbDumpTable (StoreEntry * e, hash_table * hash)
 {
-    hash_link *h;
-    fvdb_entry *fv;
-    if (hash == NULL)
-	return;
-    hash_first(hash);
-    while ((h = hash_next(hash))) {
-	fv = (fvdb_entry *) h;
-	storeAppendPrintf(e, "%9d %s\n", fv->n, hashKeyStr(&fv->hash));
+  hash_link *h;
+  fvdb_entry *fv;
+  if (hash == NULL)
+    return;
+  hash_first (hash);
+  while ((h = hash_next (hash)))
+    {
+      fv = (fvdb_entry *) h;
+      storeAppendPrintf (e, "%9d %s\n", fv->n, hashKeyStr (&fv->hash));
     }
 }
 
 static void
-fvdbDumpVia(StoreEntry * e)
+fvdbDumpVia (StoreEntry * e)
 {
-    fvdbDumpTable(e, via_table);
+  fvdbDumpTable (e, via_table);
 }
 
 static void
-fvdbDumpForw(StoreEntry * e)
+fvdbDumpForw (StoreEntry * e)
 {
-    fvdbDumpTable(e, forw_table);
+  fvdbDumpTable (e, forw_table);
 }
 
 static
 void
-fvdbFreeEntry(void *data)
+fvdbFreeEntry (void *data)
 {
-    fvdb_entry *fv = data;
-    xfree(fv->hash.key);
-    xfree(fv);
+  fvdb_entry *fv = data;
+  xfree (fv->hash.key);
+  xfree (fv);
 }
 
 static void
-fvdbClear(void)
+fvdbClear (void)
 {
-    hashFreeItems(via_table, fvdbFreeEntry);
-    hashFreeMemory(via_table);
-    via_table = hash_create((HASHCMP *) strcmp, 977, hash4);
-    hashFreeItems(forw_table, fvdbFreeEntry);
-    hashFreeMemory(forw_table);
-    forw_table = hash_create((HASHCMP *) strcmp, 977, hash4);
+  hashFreeItems (via_table, fvdbFreeEntry);
+  hashFreeMemory (via_table);
+  via_table = hash_create ((HASHCMP *) strcmp, 977, hash4);
+  hashFreeItems (forw_table, fvdbFreeEntry);
+  hashFreeMemory (forw_table);
+  forw_table = hash_create ((HASHCMP *) strcmp, 977, hash4);
 }
 
 #endif
