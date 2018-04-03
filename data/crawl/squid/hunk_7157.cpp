     safe_free(pattern);
 }
 
-static void
-parseQuickAbort(void)
+int
+parseConfigFile(const char *file_name)
 {
-    char *token;
-    int i;
-    token = strtok(NULL, w_space);
-    if (!strcasecmp(token, "on")) {
-	Config.quickAbort.min = 10 << 10;	/* 10k */
-	Config.quickAbort.pct = 64;	/* 50% */
-	Config.quickAbort.max = 100 << 10;	/* 100k */
-    } else if (!strcasecmp(token, "off")) {
-	Config.quickAbort.min = -1;
-	Config.quickAbort.pct = 0;
-	Config.quickAbort.max = 0;
-    } else {
-	if (sscanf(token, "%d", &i) != 1)
-	    self_destruct();
-	Config.quickAbort.min = i * 1024;
-	GetInteger(i);
-	Config.quickAbort.pct = i * 128 / 100;	/* 128 is full scale */
-	GetInteger(i);
-	Config.quickAbort.max = i * 1024;
+    FILE *fp = NULL;
+    char *token = NULL;
+    LOCAL_ARRAY(char, tmp_line, BUFSIZ);
+
+    configFreeMemory();
+    configSetFactoryDefaults();
+    aclDestroyAcls();
+    aclDestroyDenyInfoList(&Config.denyInfoList);
+    aclDestroyAccessList(&Config.accessList.HTTP);
+    aclDestroyAccessList(&Config.accessList.ICP);
+    aclDestroyAccessList(&Config.accessList.MISS);
+    aclDestroyAccessList(&Config.accessList.NeverDirect);
+    aclDestroyAccessList(&Config.accessList.AlwaysDirect);
+    aclDestroyRegexList(Config.cache_stop_relist);
+    Config.cache_stop_relist = NULL;
+
+    if ((fp = fopen(file_name, "r")) == NULL) {
+	sprintf(fatal_str, "Unable to open configuration file: %s: %s",
+	    file_name, xstrerror());
+	fatal(fatal_str);
+    }
+    cfg_filename = file_name;
+    if ((token = strrchr(cfg_filename, '/')))
+	cfg_filename = token + 1;
+    memset(config_input_line, '\0', BUFSIZ);
+    config_lineno = 0;
+    while (fgets(config_input_line, BUFSIZ, fp)) {
+	config_lineno++;
+	if ((token = strchr(config_input_line, '\n')))
+	    *token = '\0';
+	if (config_input_line[0] == '#')
+	    continue;
+	if (config_input_line[0] == '\0')
+	    continue;
+	debug(3, 5) ("Processing: '%s'\n", config_input_line);
+	strcpy(tmp_line, config_input_line);
+	if (!parse_line(tmp_line)) {
+	    debug(3, 0) ("parseConfigFile: line %d unrecognized: '%s'\n",
+		config_lineno,
+		config_input_line);
+	}
+    }
+
+    /* Scale values */
+    Config.maxRequestSize <<= 10;	/* 1k */
+    Config.Store.maxObjectSize <<= 10;	/* 1k */
+    Config.Mem.maxSize <<= 10;	/* 1m */
+
+    /* Sanity checks */
+    if (Config.Swap.maxSize < (Config.Mem.maxSize >> 10)) {
+	printf("WARNING: cache_swap (%d kbytes) is less than cache_mem (%d bytes).\n", Config.Swap.maxSize, Config.Mem.maxSize);
+	printf("         This will cause serious problems with your cache!!!\n");
+	printf("         Change your configuration file.\n");
+	fflush(stdout);		/* print message */
+    }
+    if (Config.cleanRate < 1)
+	Config.cleanRate = 86400 * 365;		/* one year */
+    if (Config.Announce.rate < 1) {
+	Config.Announce.rate = 86400 * 365;	/* one year */
+	Config.Announce.on = 0;
+    }
+    if (Config.dnsChildren < 0)
+	Config.dnsChildren = 0;
+    if (Config.dnsChildren < 1) {
+	printf("WARNING: dnsservers are disabled!\n");
+	printf("WARNING: Cache performance may be very poor\n");
+    } else if (Config.dnsChildren > DefaultDnsChildrenMax) {
+	printf("WARNING: dns_children was set to a bad value: %d\n",
+	    Config.dnsChildren);
+	printf("Setting it to the maximum (%d).\n", DefaultDnsChildrenMax);
+	Config.dnsChildren = DefaultDnsChildrenMax;
+    }
+    if (Config.Program.redirect) {
+	if (Config.redirectChildren < 1) {
+	    Config.redirectChildren = 0;
+	    safe_free(Config.Program.redirect);
+	} else if (Config.redirectChildren > DefaultRedirectChildrenMax) {
+	    printf("WARNING: redirect_children was set to a bad value: %d\n",
+		Config.redirectChildren);
+	    printf("Setting it to the maximum (%d).\n", DefaultRedirectChildrenMax);
+	    Config.redirectChildren = DefaultRedirectChildrenMax;
+	}
     }
+    fclose(fp);
+    configDoConfigure();
+    dump_all();
+    return 0;
 }
 
-static void
-parseKilobytes(int *val)
+static char *
+safe_xstrdup(const char *p)
 {
-    char *token;
-    int i;
-    GetInteger(i);
-    *val = i * 1024;
+    return p ? xstrdup(p) : NULL;
 }
 
-static void
-parseMgrLine(void)
+void
+configFreeMemory(void)
 {
-    char *token;
-    token = strtok(NULL, w_space);
-    if (token == NULL)
-	self_destruct();
+    safe_free(Config.Wais.relayHost);
+    safe_free(Config.Log.log);
+    safe_free(Config.Log.access);
+    safe_free(Config.Log.store);
+    safe_free(Config.Log.swap);
     safe_free(Config.adminEmail);
-    Config.adminEmail = xstrdup(token);
-}
-
+    safe_free(Config.effectiveUser);
+    safe_free(Config.effectiveGroup);
+    safe_free(Config.Program.dnsserver);
+    safe_free(Config.Program.redirect);
+    safe_free(Config.Program.unlinkd);
+    safe_free(Config.Program.pinger);
+    safe_free(Config.Accel.host);
+    safe_free(Config.Accel.prefix);
+    safe_free(Config.appendDomain);
+    safe_free(Config.debugOptions);
+    safe_free(Config.pidFilename);
+    safe_free(Config.mimeTablePathname);
+    safe_free(Config.visibleHostname);
 #if USE_PROXY_AUTH
-static void
-parseProxyAuthLine(void)
-{
-    char *token;
-    token = strtok(NULL, w_space);
-    if (token == NULL)
-	self_destruct();
     safe_free(Config.proxyAuth.File);
     aclDestroyRegexList(Config.proxyAuth.IgnoreDomains);
     Config.proxyAuth.IgnoreDomains = NULL;
-    Config.proxyAuth.File = xstrdup(token);
-    aclParseRegexList(&Config.proxyAuth.IgnoreDomains, 1);
-}
 #endif /* USE_PROXY_AUTH */
+    safe_free(Config.Announce.host);
+    safe_free(Config.Announce.file);
+    safe_free(Config.errHtmlText);
+    safe_free(Config.Ftp.icon_prefix);
+    safe_free(Config.Ftp.icon_suffix);
+    safe_free(Config.Ftp.anon_user);
+    peerDestroy(Config.sslProxy);
+    peerDestroy(Config.passProxy);
+    wordlistDestroy(&Config.hierarchy_stoplist);
+    wordlistDestroy(&Config.mcast_group_list);
+    wordlistDestroy(&Config.dns_testname_list);
+    wordlistDestroy(&Config.cache_stoplist);
+    objcachePasswdDestroy(&Config.passwd_list);
+    refreshFreeMemory();
+}
+
 
 static void
-parseHttpdAccelLine(void)
+configSetFactoryDefaults(void)
 {
-    char *token;
-    LOCAL_ARRAY(char, buf, BUFSIZ);
-    int i;
-    token = strtok(NULL, w_space);
-    if (token == NULL)
-	self_destruct();
-    safe_free(Config.Accel.host);
-    Config.Accel.host = xstrdup(token);
-    GetInteger(i);
-    Config.Accel.port = i;
-    safe_free(Config.Accel.prefix);
-    sprintf(buf, "http://%s:%d", Config.Accel.host, Config.Accel.port);
-    Config.Accel.prefix = xstrdup(buf);
-    httpd_accel_mode = 1;
+    memset(&Config, '\0', sizeof(Config));
+    Config.Mem.maxSize = DefaultMemMaxSize;
+    Config.Mem.highWaterMark = DefaultMemHighWaterMark;
+    Config.Mem.lowWaterMark = DefaultMemLowWaterMark;
+    Config.Swap.maxSize = DefaultSwapMaxSize;
+    Config.Swap.highWaterMark = DefaultSwapHighWaterMark;
+    Config.Swap.lowWaterMark = DefaultSwapLowWaterMark;
+    Config.Netdb.high = DefaultNetdbHigh;
+    Config.Netdb.low = DefaultNetdbLow;
+    Config.Netdb.period = DefaultNetdbPeriod;
+
+    Config.Wais.relayHost = safe_xstrdup(DefaultWaisRelayHost);
+    Config.Wais.relayPort = DefaultWaisRelayPort;
+
+    Config.referenceAge = DefaultReferenceAge;
+    Config.negativeTtl = DefaultNegativeTtl;
+    Config.negativeDnsTtl = DefaultNegativeDnsTtl;
+    Config.positiveDnsTtl = DefaultPositiveDnsTtl;
+    Config.Timeout.read = DefaultReadTimeout;
+    Config.Timeout.connect = DefaultConnectTimeout;
+    Config.Timeout.defer = DefaultDeferTimeout;
+    Config.Timeout.request = DefaultRequestTimeout;
+    Config.Timeout.lifetime = DefaultClientLifetime;
+    Config.shutdownLifetime = DefaultShutdownLifetime;
+    Config.maxRequestSize = DefaultMaxRequestSize;
+    Config.cleanRate = DefaultCleanRate;
+    Config.dnsChildren = DefaultDnsChildren;
+    Config.redirectChildren = DefaultRedirectChildren;
+    Config.sourcePing = DefaultSourcePing;
+    Config.quickAbort.min = DefaultQuickAbortMin;
+    Config.quickAbort.pct = DefaultQuickAbortPct;
+    Config.quickAbort.max = DefaultQuickAbortMax;
+    Config.commonLogFormat = DefaultCommonLogFormat;
+    Config.logMimeHdrs = DefaultLogMimeHdrs;
+    Config.identLookup = DefaultIdentLookup;
+    Config.debugOptions = safe_xstrdup(DefaultDebugOptions);
+    Config.neighborTimeout = DefaultNeighborTimeout;
+    Config.stallDelay = DefaultStallDelay;
+    Config.singleParentBypass = DefaultSingleParentBypass;
+    Config.adminEmail = safe_xstrdup(DefaultAdminEmail);
+    Config.effectiveUser = safe_xstrdup(DefaultEffectiveUser);
+    Config.effectiveGroup = safe_xstrdup(DefaultEffectiveGroup);
+    Config.appendDomain = safe_xstrdup(DefaultAppendDomain);
+    Config.errHtmlText = safe_xstrdup(DefaultErrHtmlText);
+    Config.Port.icp = DefaultIcpPortNum;
+    Config.Log.log_fqdn = DefaultLogLogFqdn;
+    Config.Log.log = safe_xstrdup(DefaultCacheLogFile);
+    Config.Log.access = safe_xstrdup(DefaultAccessLogFile);
+    Config.Log.store = safe_xstrdup(DefaultStoreLogFile);
+    Config.Log.swap = safe_xstrdup(DefaultSwapLogFile);
+#if USE_USERAGENT_LOG
+    Config.Log.useragent = safe_xstrdup(DefaultUseragentLogFile);
+#endif
+    Config.Log.rotateNumber = DefaultLogRotateNumber;
+    Config.Program.dnsserver = safe_xstrdup(DefaultDnsserverProgram);
+    Config.Program.redirect = safe_xstrdup(DefaultRedirectProgram);
+    Config.Program.pinger = safe_xstrdup(DefaultPingerProgram);
+    Config.Program.unlinkd = safe_xstrdup(DefaultUnlinkdProgram);
+    Config.Accel.host = safe_xstrdup(DefaultAccelHost);
+    Config.Accel.prefix = safe_xstrdup(DefaultAccelPrefix);
+    Config.Accel.port = DefaultAccelPort;
+    Config.Accel.withProxy = DefaultAccelWithProxy;
+    Config.pidFilename = safe_xstrdup(DefaultPidFilename);
+    Config.mimeTablePathname = safe_xstrdup(DefaultMimeTable);
+    Config.visibleHostname = safe_xstrdup(DefaultVisibleHostname);
+#if USE_PROXY_AUTH
+    Config.proxyAuth.File = safe_xstrdup(DefaultProxyAuthFile);
+/*    Config.proxyAuth.IgnoreDomains = safe_xstrdup(DefaultproxyAuthIgnoreDomains); */
+#endif /* USE_PROXY_AUTH */
+    Config.Announce.host = safe_xstrdup(DefaultAnnounceHost);
+    Config.Announce.port = DefaultAnnouncePort;
+    Config.Announce.file = safe_xstrdup(DefaultAnnounceFile);
+    Config.Announce.rate = DefaultAnnounceRate;
+    Config.Announce.on = 0;
+    Config.tcpRcvBufsz = DefaultTcpRcvBufsz;
+    Config.udpMaxHitObjsz = DefaultUdpMaxHitObjsz;
+    Config.Addrs.tcp_outgoing.s_addr = DefaultTcpOutgoingAddr;
+    Config.Addrs.tcp_incoming.s_addr = DefaultTcpIncomingAddr;
+    Config.Addrs.udp_outgoing.s_addr = DefaultUdpOutgoingAddr;
+    Config.Addrs.udp_incoming.s_addr = DefaultUdpIncomingAddr;
+    Config.Addrs.client_netmask.s_addr = DefaultClientNetmask;
+    Config.passProxy = DefaultPassProxy;
+    Config.sslProxy = DefaultSslProxy;
+    Config.ipcache.size = DefaultIpcacheSize;
+    Config.ipcache.low = DefaultIpcacheLow;
+    Config.ipcache.high = DefaultIpcacheHigh;
+    Config.minDirectHops = DefaultMinDirectHops;
+    Config.Store.maxObjectSize = DefaultMaxObjectSize;
+    Config.Store.avgObjectSize = DefaultAvgObjectSize;
+    Config.Store.objectsPerBucket = DefaultObjectsPerBucket;
+    Config.Options.log_udp = DefaultOptionsLogUdp;
+    Config.Options.res_defnames = DefaultOptionsResDefnames;
+    Config.Options.anonymizer = DefaultOptionsAnonymizer;
+    Config.Options.enable_purge = DefaultOptionsEnablePurge;
+    Config.Options.client_db = DefaultOptionsClientDb;
+    Config.Options.query_icmp = DefaultOptionsQueryIcmp;
+    Config.Ftp.icon_prefix = safe_xstrdup(DefaultFtpIconPrefix);
+    Config.Ftp.icon_suffix = safe_xstrdup(DefaultFtpIconSuffix);
+    Config.Ftp.list_width = DefaultFtpListWidth;
+    Config.Ftp.list_wrap = DefaultFtpListWrap;
+    Config.Ftp.anon_user = safe_xstrdup(DefaultFtpAnonUser);
 }
 
 static void
-parseEffectiveUserLine(void)
+configDoConfigure(void)
 {
-    char *token;
-    token = strtok(NULL, w_space);
-    if (token == NULL)
-	self_destruct();
-    safe_free(Config.effectiveUser);
-    safe_free(Config.effectiveGroup);
-    Config.effectiveUser = xstrdup(token);
-    token = strtok(NULL, w_space);
-    if (token == NULL)
-	return;			/* group is optional */
-    Config.effectiveGroup = xstrdup(token);
+    httpd_accel_mode = Config.Accel.prefix ? 1 : 0;
+    if (Config.errHtmlText == NULL)
+	Config.errHtmlText = xstrdup(null_string);
+    storeConfigure();
+    if (httpd_accel_mode && !strcmp(Config.Accel.host, "virtual"))
+	vhost_mode = 1;
+    if (Config.Port.http == NULL)
+	fatal("No http_port specified!");
+    sprintf(ThisCache, "%s:%d (Squid/%s)",
+	getMyHostname(),
+	(int) Config.Port.http->i,
+	SQUID_VERSION);
+    if (!Config.udpMaxHitObjsz || Config.udpMaxHitObjsz > SQUID_UDP_SO_SNDBUF)
+	Config.udpMaxHitObjsz = SQUID_UDP_SO_SNDBUF;
+    if (Config.appendDomain)
+	Config.appendDomainLen = strlen(Config.appendDomain);
+    else
+	Config.appendDomainLen = 0;
 }
 
+/* Parse a time specification from the config file.  Store the
+ * result in 'iptr', after converting it to 'units' */
 static void
-parsePathname(char **path, int fatal)
+parseTimeLine(int *iptr, const char *units)
 {
     char *token;
-    struct stat sb;
-    token = strtok(NULL, w_space);
-    if (token == NULL)
+    double d;
+    int m;
+    int u;
+    if ((u = parseTimeUnits(units)) == 0)
 	self_destruct();
-    safe_free(*path);
-    *path = xstrdup(token);
-    if (fatal && stat(token, &sb) < 0) {
-	debug(50, 1) ("parsePathname: %s: %s\n", token, xstrerror());
+    if ((token = strtok(NULL, w_space)) == NULL)
 	self_destruct();
+    d = atof(token);
+    m = u;			/* default to 'units' if none specified */
+    if ((token = strtok(NULL, w_space)) != NULL) {
+	if ((m = parseTimeUnits(token)) == 0)
+	    self_destruct();
     }
+    *iptr = m * d / u;
 }
 
+static int
+parseTimeUnits(const char *unit)
+{
+    if (!strncasecmp(unit, T_SECOND_STR, strlen(T_SECOND_STR)))
+	return 1;
+    if (!strncasecmp(unit, T_MINUTE_STR, strlen(T_MINUTE_STR)))
+	return 60;
+    if (!strncasecmp(unit, T_HOUR_STR, strlen(T_HOUR_STR)))
+	return 3600;
+    if (!strncasecmp(unit, T_DAY_STR, strlen(T_DAY_STR)))
+	return 86400;
+    if (!strncasecmp(unit, T_WEEK_STR, strlen(T_WEEK_STR)))
+	return 86400 * 7;
+    if (!strncasecmp(unit, T_FORTNIGHT_STR, strlen(T_FORTNIGHT_STR)))
+	return 86400 * 14;
+    if (!strncasecmp(unit, T_MONTH_STR, strlen(T_MONTH_STR)))
+	return 86400 * 30;
+    if (!strncasecmp(unit, T_YEAR_STR, strlen(T_YEAR_STR)))
+	return 86400 * 365.2522;
+    if (!strncasecmp(unit, T_DECADE_STR, strlen(T_DECADE_STR)))
+	return 86400 * 365.2522 * 10;
+    debug(3, 1) ("parseTimeUnits: unknown time unit '%s'\n", unit);
+    return 0;
+}
+
+/*****************************************************************************
+ * Max
+ *****************************************************************************/
+
 static void
-parseOnOff(int *var)
+dump_acl(void)
 {
-    char *token;
-    token = strtok(NULL, w_space);
-    if (token == NULL)
-	self_destruct();
-    if (!strcasecmp(token, "on") || !strcasecmp(token, "enable"))
-	*var = 1;
-    else
-	*var = 0;
+    debug(0,0)("XXX need to fix\n");
 }
 
 static void
-parseWAISRelayLine(void)
+parse_acl(void)
 {
-    char *token;
-    int i;
-    token = strtok(NULL, w_space);
-    if (token == NULL)
-	self_destruct();
-    safe_free(Config.Wais.relayHost);
-    Config.Wais.relayHost = xstrdup(token);
-    GetInteger(i);
-    Config.Wais.relayPort = (u_short) i;
+    aclParseAclLine();
 }
 
 static void
-parseWordlist(wordlist ** list)
+dump_acl_access(struct _acl_access *head)
 {
-    char *token;
-    while ((token = strtok(NULL, w_space)))
-	wordlistAdd(list, token);
+    debug(0,0)("XXX need to fix\n");
 }
 
 static void
-parseAppendDomainLine(void)
+parse_acl_access(struct _acl_access **head)
 {
-    char *token;
-    token = strtok(NULL, w_space);
-    if (token == NULL)
-	self_destruct();
-    if (*token != '.')
-	self_destruct();
-    safe_free(Config.appendDomain);
-    Config.appendDomain = xstrdup(token);
+    aclParseAccessLine(head);
 }
 
 static void
-parseAddressLine(struct in_addr *addr)
+dump_address(struct in_addr addr)
+{
+    printf("%s", inet_ntoa(addr));
+}
+
+static void
+parse_address(struct in_addr *addr)
 {
-    char *token;
     const struct hostent *hp;
-    token = strtok(NULL, w_space);
+    char *token = strtok(NULL, w_space);
+
     if (token == NULL)
 	self_destruct();
     if (safe_inet_addr(token, addr) == 1)
