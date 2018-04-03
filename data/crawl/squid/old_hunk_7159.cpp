}

static void
parseAnnounceToLine(void)
{
    char *token;
    int i;
    token = strtok(NULL, w_space);
    if (token == NULL)
	self_destruct();
    safe_free(Config.Announce.host);
    Config.Announce.host = xstrdup(token);
    if ((token = strchr(Config.Announce.host, ':'))) {
	*token++ = '\0';
	if (sscanf(token, "%d", &i) != 1)
	    Config.Announce.port = i;
    }
    token = strtok(NULL, w_space);
    if (token == NULL)
	return;
    safe_free(Config.Announce.file);
    Config.Announce.file = xstrdup(token);
}

static void
parseVizHackLine(void)
{
    char *token;
    int i;
    const struct hostent *hp;
    token = strtok(NULL, w_space);
    if (token == NULL)
	self_destruct();
    if (safe_inet_addr(token, &Config.vizHack.addr) == 1)
	(void) 0;
    else if ((hp = gethostbyname(token)))	/* dont use ipcache */
	Config.vizHack.addr = inaddrFromHostent(hp);
    else
	self_destruct();
    if ((token = strtok(NULL, w_space)) == NULL)
	self_destruct();
    if (sscanf(token, "%d", &i) == 1)
	Config.vizHack.port = i;
    Config.vizHack.mcast_ttl = 64;
    if ((token = strtok(NULL, w_space)) == NULL)
	return;
    if (sscanf(token, "%d", &i) == 1)
	Config.vizHack.mcast_ttl = i;
}

static void
parseProxyLine(peer ** E)
{
    char *token;
    char *t;
    peer *e;
    token = strtok(NULL, w_space);
    if (token == NULL)
	self_destruct();
    if (*E) {
	peerDestroy(*E);
	*E = NULL;
    }
    e = xcalloc(1, sizeof(peer));
    if ((t = strchr(token, ':'))) {
	*t++ = '\0';
	e->http_port = atoi(t);
    }
    e->host = xstrdup(token);
    e->tcp_up = 1;
    *E = e;
}

static void
parseIntegerValue(int *iptr)
{
    char *token;
    int i;
    GetInteger(i);
    *iptr = i;
}

static void
parseString(char **sptr)
{
    char *token;
    token = strtok(NULL, w_space);
    if (token == NULL)
	self_destruct();
    *sptr = xstrdup(token);
}

static void
parseErrHtmlLine(void)
{
    char *token;
    if ((token = strtok(NULL, null_string)))
	Config.errHtmlText = xstrdup(token);
}

static void
parseCachemgrPasswd(void)
{
    char *passwd = NULL;
    wordlist *actions = NULL;
    parseString(&passwd);
    parseWordlist(&actions);
    objcachePasswdAdd(&Config.passwd_list, passwd, actions);
    wordlistDestroy(&actions);
}

static void
parseHttpAnonymizer(int *iptr)
{
    char *token;
    token = strtok(NULL, w_space);
    if (token == NULL)
	self_destruct();
    if (!strcasecmp(token, "off"))
	*iptr = ANONYMIZER_NONE;
    else if (!strcasecmp(token, "paranoid"))
	*iptr = ANONYMIZER_PARANOID;
    else
	*iptr = ANONYMIZER_STANDARD;
}

static void
parseCacheDir(void)
{
    char *token;
    char *dir;
    int i;
    int size;
    int l1;
    int l2;
    int readonly = 0;
    if ((token = strtok(NULL, w_space)) == NULL)
	self_destruct();
    dir = token;
    GetInteger(i);
    size = i << 10;		/* Mbytes to kbytes */
    Config.Swap.maxSize += size;
    GetInteger(i);
    l1 = i;
    GetInteger(i);
    l2 = i;
    if ((token = strtok(NULL, w_space)))
	if (!strcasecmp(token, "read-only"))
	    readonly = 1;
    if (configured_once)
	storeReconfigureSwapDisk(dir, size, l1, l2, readonly);
    else
	storeAddSwapDisk(dir, size, l1, l2, readonly);
}

int
parseConfigFile(const char *file_name)
{
    FILE *fp = NULL;
    char *token = NULL;
    LOCAL_ARRAY(char, tmp_line, BUFSIZ);

    configFreeMemory();
    configSetFactoryDefaults();
    aclDestroyAcls();
    aclDestroyDenyInfoList(&Config.denyInfoList);
    aclDestroyAccessList(&Config.accessList.HTTP);
    aclDestroyAccessList(&Config.accessList.ICP);
    aclDestroyAccessList(&Config.accessList.MISS);
    aclDestroyAccessList(&Config.accessList.NeverDirect);
    aclDestroyAccessList(&Config.accessList.AlwaysDirect);
    aclDestroyRegexList(Config.cache_stop_relist);
    Config.cache_stop_relist = NULL;

    if ((fp = fopen(file_name, "r")) == NULL) {
	sprintf(fatal_str, "Unable to open configuration file: %s: %s",
	    file_name, xstrerror());
	fatal(fatal_str);
    }
    cfg_filename = file_name;
    if ((token = strrchr(cfg_filename, '/')))
	cfg_filename = token + 1;
    memset(config_input_line, '\0', BUFSIZ);
    config_lineno = 0;
    while (fgets(config_input_line, BUFSIZ, fp)) {
	config_lineno++;
	if ((token = strchr(config_input_line, '\n')))
	    *token = '\0';
	if (config_input_line[0] == '#')
	    continue;
	if (config_input_line[0] == '\0')
	    continue;
	debug(3, 5) ("Processing: '%s'\n", config_input_line);
	strcpy(tmp_line, config_input_line);
	if ((token = strtok(tmp_line, w_space)) == NULL)
	    continue;

	if (!strcmp(token, "cache_host"))
	    parseCacheHostLine();

	else if (!strcmp(token, "cache_host_domain"))
	    parseHostDomainLine();
	else if (!strcmp(token, "cache_host_acl"))
	    parseHostAclLine();
	else if (!strcmp(token, "neighbor_type_domain"))
	    parseHostDomainTypeLine();

	else if (!strcmp(token, "neighbor_timeout"))
	    parseTimeLine(&Config.neighborTimeout, T_SECOND_STR);
	else if (!strcmp(token, "neighbour_timeout"))	/* alternate spelling */
	    parseTimeLine(&Config.neighborTimeout, T_SECOND_STR);

	else if (!strcmp(token, "cache_dir"))
	    parseCacheDir();

	else if (!strcmp(token, "cache_log"))
	    parsePathname(&Config.Log.log, 0);

	else if (!strcmp(token, "cache_access_log"))
	    parsePathname(&Config.Log.access, 0);

	else if (!strcmp(token, "cache_store_log"))
	    parsePathname(&Config.Log.store, 0);

	else if (!strcmp(token, "cache_swap_log"))
	    parsePathname(&Config.Log.swap, 0);

#if USE_USERAGENT_LOG
	else if (!strcmp(token, "useragent_log"))
	    parsePathname(&Config.Log.useragent, 0);
#endif

	else if (!strcmp(token, "logfile_rotate"))
	    parseIntegerValue(&Config.Log.rotateNumber);

	else if (!strcmp(token, "httpd_accel_with_proxy"))
	    parseOnOff(&Config.Accel.withProxy);

	else if (!strcmp(token, "httpd_accel_uses_host_header"))
	    parseOnOff(&opt_accel_uses_host);

	else if (!strcmp(token, "httpd_accel"))
	    parseHttpdAccelLine();

	else if (!strcmp(token, "cache_effective_user"))
	    parseEffectiveUserLine();

	else if (!strcmp(token, "cache_swap_high"))
	    parseIntegerValue(&Config.Swap.highWaterMark);

	else if (!strcmp(token, "cache_swap_low"))
	    parseIntegerValue(&Config.Swap.lowWaterMark);

	else if (!strcmp(token, "cache_mem_high"))
	    parseIntegerValue(&Config.Mem.highWaterMark);

	else if (!strcmp(token, "cache_mem_low"))
	    parseIntegerValue(&Config.Mem.lowWaterMark);

	else if (!strcmp(token, "cache_mem"))
	    parseMemLine();

	else if (!strcmp(token, "cache_mgr"))
	    parseMgrLine();

	else if (!strcmp(token, "acl"))
	    aclParseAclLine();

	else if (!strcmp(token, "deny_info"))
	    aclParseDenyInfoLine(&Config.denyInfoList);

	else if (!strcmp(token, "http_access"))
	    aclParseAccessLine(&Config.accessList.HTTP);
	else if (!strcmp(token, "icp_access"))
	    aclParseAccessLine(&Config.accessList.ICP);
	else if (!strcmp(token, "miss_access"))
	    aclParseAccessLine(&Config.accessList.MISS);
	else if (!strcmp(token, "never_direct"))
	    aclParseAccessLine(&Config.accessList.NeverDirect);
	else if (!strcmp(token, "always_direct"))
	    aclParseAccessLine(&Config.accessList.AlwaysDirect);

	else if (!strcmp(token, "hierarchy_stoplist"))
	    parseWordlist(&Config.hierarchy_stoplist);

	else if (!strcmp(token, "cache_stoplist"))
	    parseWordlist(&Config.cache_stoplist);
	else if (!strcmp(token, "cache_stoplist_pattern"))
	    aclParseRegexList(&Config.cache_stop_relist, 0);
	else if (!strcmp(token, "cache_stoplist_pattern/i"))
	    aclParseRegexList(&Config.cache_stop_relist, 1);

	else if (!strcmp(token, "refresh_pattern"))
	    parseRefreshPattern(0);
	else if (!strcmp(token, "refresh_pattern/i"))
	    parseRefreshPattern(1);

	else if (!strcmp(token, "quick_abort"))
	    parseQuickAbort();

	else if (!strcmp(token, "negative_ttl"))
	    parseTimeLine(&Config.negativeTtl, T_SECOND_STR);
	else if (!strcmp(token, "negative_dns_ttl"))
	    parseTimeLine(&Config.negativeDnsTtl, T_SECOND_STR);
	else if (!strcmp(token, "positive_dns_ttl"))
	    parseTimeLine(&Config.positiveDnsTtl, T_SECOND_STR);
	else if (!strcmp(token, "read_timeout"))
	    parseTimeLine(&Config.Timeout.read, T_SECOND_STR);
	else if (!strcmp(token, "connect_timeout"))
	    parseTimeLine(&Config.Timeout.connect, T_SECOND_STR);
	else if (!strcmp(token, "defer_timeout"))
	    parseTimeLine(&Config.Timeout.defer, T_SECOND_STR);
	else if (!strcmp(token, "request_timeout"))
	    parseTimeLine(&Config.Timeout.request, T_SECOND_STR);
	else if (!strcmp(token, "client_lifetime"))
	    parseTimeLine(&Config.Timeout.lifetime, T_SECOND_STR);
	else if (!strcmp(token, "shutdown_lifetime"))
	    parseTimeLine(&Config.shutdownLifetime, T_SECOND_STR);
	else if (!strcmp(token, "clean_rate"))
	    parseTimeLine(&Config.cleanRate, T_SECOND_STR);
	else if (!strcmp(token, "reference_age"))
	    parseTimeLine(&Config.referenceAge, T_MINUTE_STR);

	else if (!strcmp(token, "request_size"))
	    parseKilobytes(&Config.maxRequestSize);

	else if (!strcmp(token, "cache_dns_program"))
	    parsePathname(&Config.Program.dnsserver, 1);

	else if (!strcmp(token, "dns_children"))
	    parseIntegerValue(&Config.dnsChildren);
	else if (!strcmp(token, "dns_defnames"))
	    parseOnOff(&Config.Options.res_defnames);

	else if (!strcmp(token, "redirect_program"))
	    parsePathname(&Config.Program.redirect, 1);

	else if (!strcmp(token, "redirect_children"))
	    parseIntegerValue(&Config.redirectChildren);

	else if (!strcmp(token, "pinger_program"))
	    parsePathname(&Config.Program.pinger, 1);

	else if (!strcmp(token, "unlinkd_program"))
	    parsePathname(&Config.Program.unlinkd, 1);

#if USE_PROXY_AUTH
	else if (!strcmp(token, "proxy_auth"))
	    parseProxyAuthLine();
	else if (!strcmp(token, "proxy_auth_ignore"))
	    aclParseRegexList(&Config.proxyAuth.IgnoreDomains, 1);
#endif /* USE_PROXY_AUTH */

	else if (!strcmp(token, "source_ping"))
	    parseOnOff(&Config.sourcePing);

	else if (!strcmp(token, "emulate_httpd_log"))
	    parseOnOff(&Config.commonLogFormat);

	else if (!strcmp(token, "log_mime_hdrs"))
	    parseOnOff(&Config.logMimeHdrs);

	else if (!strcmp(token, "ident_lookup"))
	    parseOnOff(&Config.identLookup);

	else if (!strcmp(token, "append_domain"))
	    parseAppendDomainLine();

	else if (!strcmp(token, "wais_relay"))
	    parseWAISRelayLine();

	else if (!strcmp(token, "mcast_groups"))
	    parseMcastGroupLine();

	else if (!strcmp(token, "tcp_incoming_address"))
	    parseAddressLine(&Config.Addrs.tcp_incoming);

	else if (!strcmp(token, "tcp_outgoing_address"))
	    parseAddressLine(&Config.Addrs.tcp_outgoing);

	else if (!strcmp(token, "udp_incoming_address"))
	    parseAddressLine(&Config.Addrs.udp_incoming);

	else if (!strcmp(token, "udp_outgoing_address"))
	    parseAddressLine(&Config.Addrs.udp_outgoing);

	else if (!strcmp(token, "client_netmask"))
	    parseAddressLine(&Config.Addrs.client_netmask);

	else if (!strcmp(token, "tcp_recv_bufsize"))
	    parseIntegerValue(&Config.tcpRcvBufsz);

	else if (!strcmp(token, "log_fqdn"))
	    parseOnOff(&Config.Log.log_fqdn);

	else if (!strcmp(token, "bind_address"))
	    parseAddressLine(&Config.Addrs.tcp_incoming);

	else if (!strcmp(token, "outbound_address"))
	    parseAddressLine(&Config.Addrs.tcp_outgoing);

	else if (!strcmp(token, "http_port") || !strcmp(token, "ascii_port"))
	    parseHttpPortLine();

	else if (!strcmp(token, "icp_port") || !strcmp(token, "udp_port"))
	    parseIcpPortLine();

	else if (!strcmp(token, "dns_testnames"))
	    parseWordlist(&Config.dns_testname_list);

	else if (!strcmp(token, "single_parent_bypass"))
	    parseOnOff(&Config.singleParentBypass);

	else if (!strcmp(token, "debug_options"))
	    parseDebugOptionsLine();

	else if (!strcmp(token, "pid_filename"))
	    parsePathname(&Config.pidFilename, 0);
	else if (!strcmp(token, "mime_table"))
	    parsePathname(&Config.mimeTablePathname, 1);
	else if (!strcmp(token, "visible_hostname"))
	    parseVisibleHostnameLine();

	else if (!strcmp(token, "ftp_user"))
	    parseString(&Config.Ftp.anon_user);

	else if (!strcmp(token, "cache_announce"))
	    parseCacheAnnounceLine();

	else if (!strcmp(token, "announce_to"))
	    parseAnnounceToLine();

	else if (!strcmp(token, "ssl_proxy"))
	    parseProxyLine(&Config.sslProxy);
	else if (!strcmp(token, "passthrough_proxy"))
	    parseProxyLine(&Config.passProxy);

	else if (!strcmp(token, "err_html_text"))
	    parseErrHtmlLine();

	else if (!strcmp(token, "ipcache_size"))
	    parseIntegerValue(&Config.ipcache.size);
	else if (!strcmp(token, "ipcache_low"))
	    parseIntegerValue(&Config.ipcache.low);
	else if (!strcmp(token, "ipcache_high"))
	    parseIntegerValue(&Config.ipcache.high);

	else if (!strcmp(token, "memory_pools"))
	    parseOnOff(&opt_mem_pools);
	else if (!strcmp(token, "udp_hit_obj"))
	    parseOnOff(&opt_udp_hit_obj);
	else if (!strcmp(token, "udp_hit_obj_size"))
	    parseIntegerValue(&Config.udpMaxHitObjsz);
	else if (!strcmp(token, "forwarded_for"))
	    parseOnOff(&opt_forwarded_for);
	else if (!strcmp(token, "log_icp_queries"))
	    parseOnOff(&Config.Options.log_udp);
	else if (!strcmp(token, "http_anonymizer"))
	    parseHttpAnonymizer(&Config.Options.anonymizer);
	else if (!strcmp(token, "client_db"))
	    parseOnOff(&Config.Options.client_db);
	else if (!strcmp(token, "query_icmp"))
	    parseOnOff(&Config.Options.query_icmp);

	else if (!strcmp(token, "minimum_direct_hops"))
	    parseIntegerValue(&Config.minDirectHops);

	else if (!strcmp(token, "cachemgr_passwd"))
	    parseCachemgrPasswd();

	else if (!strcmp(token, "store_objects_per_bucket"))
	    parseIntegerValue(&Config.Store.objectsPerBucket);
	else if (!strcmp(token, "store_avg_object_size"))
	    parseIntegerValue(&Config.Store.avgObjectSize);
	else if (!strcmp(token, "maximum_object_size"))
	    parseKilobytes(&Config.Store.maxObjectSize);

	else if (!strcmp(token, "viz_hack_addr"))
	    parseVizHackLine();

	else if (!strcmp(token, "netdb_high"))
	    parseIntegerValue(&Config.Netdb.high);
	else if (!strcmp(token, "netdb_low"))
	    parseIntegerValue(&Config.Netdb.low);
	else if (!strcmp(token, "netdb_ping_period"))
	    parseTimeLine(&Config.Netdb.period, T_SECOND_STR);

	/* If unknown, treat as a comment line */
	else {
	    debug(3, 0) ("parseConfigFile: line %d unrecognized: '%s'\n",
		config_lineno,
		config_input_line);
	}
    }

    /* Sanity checks */
    if (Config.Swap.maxSize < (Config.Mem.maxSize >> 10)) {
	printf("WARNING: cache_swap (%d kbytes) is less than cache_mem (%d bytes).\n", Config.Swap.maxSize, Config.Mem.maxSize);
	printf("         This will cause serious problems with your cache!!!\n");
	printf("         Change your configuration file.\n");
	fflush(stdout);		/* print message */
    }
    if (Config.cleanRate < 1)
	Config.cleanRate = 86400 * 365;		/* one year */
    if (Config.Announce.rate < 1) {
	Config.Announce.rate = 86400 * 365;	/* one year */
	Config.Announce.on = 0;
    }
    if (Config.dnsChildren < 0)
	Config.dnsChildren = 0;
    if (Config.dnsChildren < 1) {
	printf("WARNING: dnsservers are disabled!\n");
	printf("WARNING: Cache performance may be very poor\n");
    } else if (Config.dnsChildren > DefaultDnsChildrenMax) {
	printf("WARNING: dns_children was set to a bad value: %d\n",
	    Config.dnsChildren);
	printf("Setting it to the maximum (%d).\n", DefaultDnsChildrenMax);
	Config.dnsChildren = DefaultDnsChildrenMax;
    }
    if (Config.Program.redirect) {
	if (Config.redirectChildren < 1) {
	    Config.redirectChildren = 0;
	    safe_free(Config.Program.redirect);
	} else if (Config.redirectChildren > DefaultRedirectChildrenMax) {
	    printf("WARNING: redirect_children was set to a bad value: %d\n",
		Config.redirectChildren);
	    printf("Setting it to the maximum (%d).\n", DefaultRedirectChildrenMax);
	    Config.redirectChildren = DefaultRedirectChildrenMax;
	}
    }
    fclose(fp);
    configDoConfigure();
    return 0;
}

static char *
safe_xstrdup(const char *p)
{
    return p ? xstrdup(p) : NULL;
}

void
configFreeMemory(void)
{
    safe_free(Config.Wais.relayHost);
    safe_free(Config.Log.log);
    safe_free(Config.Log.access);
    safe_free(Config.Log.store);
    safe_free(Config.Log.swap);
    safe_free(Config.adminEmail);
    safe_free(Config.effectiveUser);
    safe_free(Config.effectiveGroup);
    safe_free(Config.Program.dnsserver);
    safe_free(Config.Program.redirect);
    safe_free(Config.Program.unlinkd);
    safe_free(Config.Program.pinger);
    safe_free(Config.Accel.host);
    safe_free(Config.Accel.prefix);
    safe_free(Config.appendDomain);
    safe_free(Config.debugOptions);
    safe_free(Config.pidFilename);
    safe_free(Config.mimeTablePathname);
    safe_free(Config.visibleHostname);
#if USE_PROXY_AUTH
    safe_free(Config.proxyAuth.File);
    aclDestroyRegexList(Config.proxyAuth.IgnoreDomains);
    Config.proxyAuth.IgnoreDomains = NULL;
#endif /* USE_PROXY_AUTH */
    safe_free(Config.Announce.host);
    safe_free(Config.Announce.file);
    safe_free(Config.errHtmlText);
    safe_free(Config.Ftp.icon_prefix);
    safe_free(Config.Ftp.icon_suffix);
    safe_free(Config.Ftp.anon_user);
    peerDestroy(Config.sslProxy);
    peerDestroy(Config.passProxy);
    wordlistDestroy(&Config.hierarchy_stoplist);
    wordlistDestroy(&Config.mcast_group_list);
    wordlistDestroy(&Config.dns_testname_list);
    wordlistDestroy(&Config.cache_stoplist);
    objcachePasswdDestroy(&Config.passwd_list);
    refreshFreeMemory();
}


static void
configSetFactoryDefaults(void)
{
    memset(&Config, '\0', sizeof(Config));
    Config.Mem.maxSize = DefaultMemMaxSize;
    Config.Mem.highWaterMark = DefaultMemHighWaterMark;
    Config.Mem.lowWaterMark = DefaultMemLowWaterMark;
    Config.Swap.maxSize = DefaultSwapMaxSize;
    Config.Swap.highWaterMark = DefaultSwapHighWaterMark;
    Config.Swap.lowWaterMark = DefaultSwapLowWaterMark;
    Config.Netdb.high = DefaultNetdbHigh;
    Config.Netdb.low = DefaultNetdbLow;
    Config.Netdb.period = DefaultNetdbPeriod;

    Config.Wais.relayHost = safe_xstrdup(DefaultWaisRelayHost);
    Config.Wais.relayPort = DefaultWaisRelayPort;

    Config.referenceAge = DefaultReferenceAge;
    Config.negativeTtl = DefaultNegativeTtl;
    Config.negativeDnsTtl = DefaultNegativeDnsTtl;
    Config.positiveDnsTtl = DefaultPositiveDnsTtl;
    Config.Timeout.read = DefaultReadTimeout;
    Config.Timeout.connect = DefaultConnectTimeout;
    Config.Timeout.defer = DefaultDeferTimeout;
    Config.Timeout.request = DefaultRequestTimeout;
    Config.Timeout.lifetime = DefaultClientLifetime;
    Config.shutdownLifetime = DefaultShutdownLifetime;
    Config.maxRequestSize = DefaultMaxRequestSize;
    Config.cleanRate = DefaultCleanRate;
    Config.dnsChildren = DefaultDnsChildren;
    Config.redirectChildren = DefaultRedirectChildren;
    Config.sourcePing = DefaultSourcePing;
    Config.quickAbort.min = DefaultQuickAbortMin;
    Config.quickAbort.pct = DefaultQuickAbortPct;
    Config.quickAbort.max = DefaultQuickAbortMax;
    Config.commonLogFormat = DefaultCommonLogFormat;
    Config.logMimeHdrs = DefaultLogMimeHdrs;
    Config.identLookup = DefaultIdentLookup;
    Config.debugOptions = safe_xstrdup(DefaultDebugOptions);
    Config.neighborTimeout = DefaultNeighborTimeout;
    Config.stallDelay = DefaultStallDelay;
    Config.singleParentBypass = DefaultSingleParentBypass;
    Config.adminEmail = safe_xstrdup(DefaultAdminEmail);
    Config.effectiveUser = safe_xstrdup(DefaultEffectiveUser);
    Config.effectiveGroup = safe_xstrdup(DefaultEffectiveGroup);
    Config.appendDomain = safe_xstrdup(DefaultAppendDomain);
    Config.errHtmlText = safe_xstrdup(DefaultErrHtmlText);
    Config.Port.n_http = 0;
    Config.Port.icp = DefaultIcpPortNum;
    Config.Log.log_fqdn = DefaultLogLogFqdn;
    Config.Log.log = safe_xstrdup(DefaultCacheLogFile);
    Config.Log.access = safe_xstrdup(DefaultAccessLogFile);
    Config.Log.store = safe_xstrdup(DefaultStoreLogFile);
    Config.Log.swap = safe_xstrdup(DefaultSwapLogFile);
#if USE_USERAGENT_LOG
    Config.Log.useragent = safe_xstrdup(DefaultUseragentLogFile);
#endif
    Config.Log.rotateNumber = DefaultLogRotateNumber;
    Config.Program.dnsserver = safe_xstrdup(DefaultDnsserverProgram);
    Config.Program.redirect = safe_xstrdup(DefaultRedirectProgram);
    Config.Program.pinger = safe_xstrdup(DefaultPingerProgram);
    Config.Program.unlinkd = safe_xstrdup(DefaultUnlinkdProgram);
    Config.Accel.host = safe_xstrdup(DefaultAccelHost);
    Config.Accel.prefix = safe_xstrdup(DefaultAccelPrefix);
    Config.Accel.port = DefaultAccelPort;
    Config.Accel.withProxy = DefaultAccelWithProxy;
    Config.pidFilename = safe_xstrdup(DefaultPidFilename);
    Config.mimeTablePathname = safe_xstrdup(DefaultMimeTable);
    Config.visibleHostname = safe_xstrdup(DefaultVisibleHostname);
#if USE_PROXY_AUTH
    Config.proxyAuth.File = safe_xstrdup(DefaultProxyAuthFile);
/*    Config.proxyAuth.IgnoreDomains = safe_xstrdup(DefaultproxyAuthIgnoreDomains); */
#endif /* USE_PROXY_AUTH */
    Config.Announce.host = safe_xstrdup(DefaultAnnounceHost);
    Config.Announce.port = DefaultAnnouncePort;
    Config.Announce.file = safe_xstrdup(DefaultAnnounceFile);
    Config.Announce.rate = DefaultAnnounceRate;
    Config.Announce.on = 0;
    Config.tcpRcvBufsz = DefaultTcpRcvBufsz;
    Config.udpMaxHitObjsz = DefaultUdpMaxHitObjsz;
    Config.Addrs.tcp_outgoing.s_addr = DefaultTcpOutgoingAddr;
    Config.Addrs.tcp_incoming.s_addr = DefaultTcpIncomingAddr;
    Config.Addrs.udp_outgoing.s_addr = DefaultUdpOutgoingAddr;
    Config.Addrs.udp_incoming.s_addr = DefaultUdpIncomingAddr;
    Config.Addrs.client_netmask.s_addr = DefaultClientNetmask;
    Config.passProxy = DefaultPassProxy;
    Config.sslProxy = DefaultSslProxy;
    Config.ipcache.size = DefaultIpcacheSize;
    Config.ipcache.low = DefaultIpcacheLow;
    Config.ipcache.high = DefaultIpcacheHigh;
    Config.minDirectHops = DefaultMinDirectHops;
    Config.Store.maxObjectSize = DefaultMaxObjectSize;
    Config.Store.avgObjectSize = DefaultAvgObjectSize;
    Config.Store.objectsPerBucket = DefaultObjectsPerBucket;
    Config.Options.log_udp = DefaultOptionsLogUdp;
    Config.Options.res_defnames = DefaultOptionsResDefnames;
    Config.Options.anonymizer = DefaultOptionsAnonymizer;
    Config.Options.enable_purge = DefaultOptionsEnablePurge;
    Config.Options.client_db = DefaultOptionsClientDb;
    Config.Options.query_icmp = DefaultOptionsQueryIcmp;
    Config.Ftp.icon_prefix = safe_xstrdup(DefaultFtpIconPrefix);
    Config.Ftp.icon_suffix = safe_xstrdup(DefaultFtpIconSuffix);
    Config.Ftp.list_width = DefaultFtpListWidth;
    Config.Ftp.list_wrap = DefaultFtpListWrap;
    Config.Ftp.anon_user = safe_xstrdup(DefaultFtpAnonUser);
}

static void
configDoConfigure(void)
{
    httpd_accel_mode = Config.Accel.prefix ? 1 : 0;
    if (Config.errHtmlText == NULL)
	Config.errHtmlText = xstrdup(null_string);
    storeConfigure();
    if (httpd_accel_mode && !strcmp(Config.Accel.host, "virtual"))
	vhost_mode = 1;
    sprintf(ThisCache, "%s:%d (Squid/%s)",
	getMyHostname(),
	(int) Config.Port.http[0],
	SQUID_VERSION);
    if (!Config.udpMaxHitObjsz || Config.udpMaxHitObjsz > SQUID_UDP_SO_SNDBUF)
	Config.udpMaxHitObjsz = SQUID_UDP_SO_SNDBUF;
    if (Config.appendDomain)
	Config.appendDomainLen = strlen(Config.appendDomain);
    else
	Config.appendDomainLen = 0;
    if (Config.Port.n_http == 0)
	Config.Port.http[Config.Port.n_http++] = DefaultHttpPortNum;
}

/* Parse a time specification from the config file.  Store the
 * result in 'iptr', after converting it to 'units' */
static void
parseTimeLine(int *iptr, const char *units)
{
    char *token;
    double d;
    int m;
    int u;
    if ((u = parseTimeUnits(units)) == 0)
	self_destruct();
    if ((token = strtok(NULL, w_space)) == NULL)
	self_destruct();
    d = atof(token);
    m = u;			/* default to 'units' if none specified */
    if ((token = strtok(NULL, w_space)) != NULL) {
	if ((m = parseTimeUnits(token)) == 0)
	    self_destruct();
    }
    *iptr = m * d / u;
}

static int
parseTimeUnits(const char *unit)
{
    if (!strncasecmp(unit, T_SECOND_STR, strlen(T_SECOND_STR)))
	return 1;
    if (!strncasecmp(unit, T_MINUTE_STR, strlen(T_MINUTE_STR)))
	return 60;
    if (!strncasecmp(unit, T_HOUR_STR, strlen(T_HOUR_STR)))
	return 3600;
    if (!strncasecmp(unit, T_DAY_STR, strlen(T_DAY_STR)))
	return 86400;
    if (!strncasecmp(unit, T_WEEK_STR, strlen(T_WEEK_STR)))
	return 86400 * 7;
    if (!strncasecmp(unit, T_FORTNIGHT_STR, strlen(T_FORTNIGHT_STR)))
	return 86400 * 14;
    if (!strncasecmp(unit, T_MONTH_STR, strlen(T_MONTH_STR)))
	return 86400 * 30;
    if (!strncasecmp(unit, T_YEAR_STR, strlen(T_YEAR_STR)))
	return 86400 * 365.2522;
    if (!strncasecmp(unit, T_DECADE_STR, strlen(T_DECADE_STR)))
	return 86400 * 365.2522 * 10;
    debug(3, 1) ("parseTimeUnits: unknown time unit '%s'\n", unit);
    return 0;
}
