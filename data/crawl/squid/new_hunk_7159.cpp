}

static void
dump_cachedir(void)
{
    debug(0,0)("XXX need to fix\n");
}

static void
parse_cachedir(void)
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

static void
dump_cachehost(void)
{
    debug(0,0)("XXX need to fix\n");
}

static void
parse_cachehost(void)
{
    char *type = NULL;
    char *hostname = NULL;
    char *token = NULL;
    u_short http_port = CACHE_HTTP_PORT;
    u_short icp_port = CACHE_ICP_PORT;
    int options = 0;
    int weight = 1;
    int mcast_ttl = 0;
    int i;

    if (!(hostname = strtok(NULL, w_space)))
	self_destruct();
    if (!(type = strtok(NULL, w_space)))
	self_destruct();

    GetInteger(i);
    http_port = (u_short) i;
    GetInteger(i);
    icp_port = (u_short) i;
    while ((token = strtok(NULL, w_space))) {
	if (!strcasecmp(token, "proxy-only")) {
	    options |= NEIGHBOR_PROXY_ONLY;
	} else if (!strcasecmp(token, "no-query")) {
	    options |= NEIGHBOR_NO_QUERY;
	} else if (!strcasecmp(token, "multicast-responder")) {
	    options |= NEIGHBOR_MCAST_RESPONDER;
	} else if (!strncasecmp(token, "weight=", 7)) {
	    weight = atoi(token + 7);
	} else if (!strncasecmp(token, "ttl=", 4)) {
	    mcast_ttl = atoi(token + 4);
	    if (mcast_ttl < 0)
		mcast_ttl = 0;
	    if (mcast_ttl > 128)
		mcast_ttl = 128;
	} else if (!strncasecmp(token, "default", 7)) {
	    options |= NEIGHBOR_DEFAULT_PARENT;
	} else if (!strncasecmp(token, "round-robin", 11)) {
	    options |= NEIGHBOR_ROUNDROBIN;
	} else {
	    debug(3, 0) ("parseCacheHostLine: token='%s'\n", token);
	    self_destruct();
	}
    }
    if (weight < 1)
	weight = 1;
    neighborAdd(hostname, type, http_port, icp_port, options,
	weight, mcast_ttl);
}

static void
dump_cachemgrpasswd(void)
{
    debug(0,0)("XXX need to fix\n");
}

static void
parse_cachemgrpasswd(void)
{
    char *passwd = NULL;
    wordlist *actions = NULL;
    parse_string(&passwd);
    parse_wordlist(&actions);
    objcachePasswdAdd(&Config.passwd_list, passwd, actions);
    wordlistDestroy(&actions);
}

static void
dump_denyinfo(struct _acl_deny_info_list *var)
{
    debug(0,0)("XXX need to fix\n");
}

static void
parse_denyinfo(struct _acl_deny_info_list **var)
{
    aclParseDenyInfoLine(var);
}

static void
dump_effectiveuser(void)
{
    debug(0,0)("XXX need to fix\n");
}

static void
parse_effectiveuser(void)
{
    char *token;
    token = strtok(NULL, w_space);
    if (token == NULL)
	self_destruct();
    safe_free(Config.effectiveUser);
    safe_free(Config.effectiveGroup);
    Config.effectiveUser = xstrdup(token);
    token = strtok(NULL, w_space);
    if (token == NULL)
	return;			/* group is optional */
    Config.effectiveGroup = xstrdup(token);
}

static void
dump_errhtml(void)
{
    debug(0,0)("XXX need to fix\n");
}

static void
parse_errhtml(void)
{
    char *token;
    if ((token = strtok(NULL, null_string)))
	Config.errHtmlText = xstrdup(token);
}

static void
dump_hostacl(void)
{
    debug(0,0)("XXX need to fix\n");
}

static void
parse_hostacl(void)
{
    char *host = NULL;
    char *aclname = NULL;
    if (!(host = strtok(NULL, w_space)))
	self_destruct();
    while ((aclname = strtok(NULL, list_sep)))
	neighborAddAcl(host, aclname);
}

static void
dump_hostdomain(void)
{
    debug(0,0)("XXX need to fix\n");
}

static void
parse_hostdomain(void)
{
    char *host = NULL;
    char *domain = NULL;
    if (!(host = strtok(NULL, w_space)))
	self_destruct();
    while ((domain = strtok(NULL, list_sep)))
	neighborAddDomainPing(host, domain);
}

static void
dump_hostdomaintype(void)
{
    debug(0,0)("XXX need to fix\n");
}

static void
parse_hostdomaintype(void)
{
    char *host = NULL;
    char *type = NULL;
    char *domain = NULL;
    if (!(host = strtok(NULL, w_space)))
	self_destruct();
    if (!(type = strtok(NULL, w_space)))
	self_destruct();
    while ((domain = strtok(NULL, list_sep)))
	neighborAddDomainType(host, domain, type);
}

static void
dump_httpanonymizer(int var)
{
    switch (var) {
    case ANONYMIZER_NONE:
	printf("off");
	break;
    case ANONYMIZER_STANDARD:
	printf("paranoid");
	break;
    case ANONYMIZER_PARANOID:
	printf("standard");
	break;
    }
}

static void
parse_httpanonymizer(int *var)
{
    char *token;
    token = strtok(NULL, w_space);
    if (token == NULL)
	self_destruct();
    if (!strcasecmp(token, "off"))
	*var = ANONYMIZER_NONE;
    else if (!strcasecmp(token, "paranoid"))
	*var = ANONYMIZER_PARANOID;
    else
	*var = ANONYMIZER_STANDARD;
}

static void
dump_httpdaccel(void)
{
    debug(0,0)("XXX need to fix\n");
}

static void
parse_httpdaccel(void)
{
    char *token;
    LOCAL_ARRAY(char, buf, BUFSIZ);
    int i;
    token = strtok(NULL, w_space);
    if (token == NULL)
	self_destruct();
    safe_free(Config.Accel.host);
    Config.Accel.host = xstrdup(token);
    GetInteger(i);
    Config.Accel.port = i;
    safe_free(Config.Accel.prefix);
    sprintf(buf, "http://%s:%d", Config.Accel.host, Config.Accel.port);
    Config.Accel.prefix = xstrdup(buf);
    httpd_accel_mode = 1;
}

static void
dump_ushortlist(ushortlist *u)
{
    while (u) {
	printf("%d ", (int) u->i);
	u = u->next;
    }
}

static void
parse_ushortlist(ushortlist ** P)
{
    char *token;
    int i;
    ushortlist *u;
    ushortlist **U;
    while ((token = strtok(NULL, w_space))) {
	if (sscanf(token, "%d", &i) != 1)
	    self_destruct();
	if (i < 0)
	    i = 0;
	u = xcalloc(1, sizeof(ushortlist));
	u->i = (u_short) i;
	for (U = P; *U; U = &(*U)->next);
	*U = u;
    }
}

static void
dump_int(int var)
{
    printf("%d", var);
}

static void
parse_int(int *var)
{
    char *token;
    int i;

    GetInteger(i);
    *var = i;
}

static void
dump_onoff(int var)
{
    printf(var ? "on" : "off");
}

static void
parse_onoff(int *var)
{
    char *token = strtok(NULL, w_space);

    if (token == NULL)
	self_destruct();
    if (!strcasecmp(token, "on") || !strcasecmp(token, "enable"))
	*var = 1;
    else
	*var = 0;
}

static void
dump_pathname_check(char path[])
{
    printf("%s", path);
}

static void
parse_pathname_check(char *path[])
{
    struct stat sb;

    parse_string(path);

    if (stat(*path, &sb) < 0) {
	debug(50, 1) ("parse_pathname_check: %s: %s\n", *path, xstrerror());
	self_destruct();
    }
}

static void
dump_proxy(peer * E)
{
    debug(0,0)("XXX need to fix\n");
}

static void
parse_proxy(peer ** E)
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

#if USE_PROXY_AUTH
static void
dump_proxyauth(void)
{
    debug(0,0)("XXX need to fix\n");
}

static void
parse_proxyauth(void)
{
    char *token;
    token = strtok(NULL, w_space);
    if (token == NULL)
	self_destruct();
    safe_free(Config.proxyAuth.File);
    aclDestroyRegexList(Config.proxyAuth.IgnoreDomains);
    Config.proxyAuth.IgnoreDomains = NULL;
    Config.proxyAuth.File = xstrdup(token);
    aclParseRegexList(&Config.proxyAuth.IgnoreDomains, 1);
}
#endif /* USE_PROXY_AUTH */

static void
dump_quickabort(void)
{
    debug(0,0)("XXX need to fix\n");
}

static void
parse_quickabort(void)
{
    char *token;
    int i;
    token = strtok(NULL, w_space);
    if (!strcasecmp(token, "on")) {
	Config.quickAbort.min = 10 << 10;	/* 10k */
	Config.quickAbort.pct = 64;	/* 50% */
	Config.quickAbort.max = 100 << 10;	/* 100k */
    } else if (!strcasecmp(token, "off")) {
	Config.quickAbort.min = -1;
	Config.quickAbort.pct = 0;
	Config.quickAbort.max = 0;
    } else {
	if (sscanf(token, "%d", &i) != 1)
	    self_destruct();
	Config.quickAbort.min = i * 1024;
	GetInteger(i);
	Config.quickAbort.pct = i * 128 / 100;	/* 128 is full scale */
	GetInteger(i);
	Config.quickAbort.max = i * 1024;
    }
}

static void
dump_refreshpattern(void)
{
    debug(0,0)("XXX need to fix\n");
}

static void
parse_refreshpattern(void)
{
    parseRefreshPattern(0);
}

static void
dump_refreshpattern_icase(void)
{
    debug(0,0)("XXX need to fix\n");
}

static void
parse_refreshpattern_icase(void)
{
    parseRefreshPattern(1);
}

static void
dump_regexlist(relist * var)
{
    debug(0,0)("XXX need to fix\n");
}

static void
parse_regexlist(relist ** var)
{
    aclParseRegexList(var, 0);
}

static void
dump_regexlist_icase(relist * var)
{
    debug(0,0)("XXX need to fix\n");
}

static void
parse_regexlist_icase(relist ** var)
{
    aclParseRegexList(var, 1);
}

static void
dump_string(char var[])
{
    printf("%s", var);
}

static void
parse_string(char *var[])
{
    char *token = strtok(NULL, w_space);

    safe_free(*var);
    if (token == NULL)
	self_destruct();
    *var = xstrdup(token);
}

static void
dump_string_optional(const char *var)
{
    printf("%s", var);
}

static void
parse_string_optional(char *volatile *var)
{
    char *token = strtok(NULL, null_string);

    safe_free(*var);
    if (token == NULL) {
	*var = NULL;
	return;
    }
    *var = xstrdup(token);
}

static void
dump_time_min(int var)
{
    printf("%d", var / 60);
}

static void
parse_time_min(int *var)
{
    parseTimeLine(var, T_MINUTE_STR);
}

static void
dump_time_sec(int var)
{
    printf("%d", var);
}

static void
parse_time_sec(int *var)
{
    parseTimeLine(var, T_SECOND_STR);
}

static void
dump_ushort(u_short var)
{
    printf("%d", var);
}

static void
parse_ushort(u_short * var)
{
    char *token;
    int i;

    GetInteger(i);
    if (i < 0)
	i = 0;
    *var = (u_short) i;
}

static void
dump_vizhack(void)
{
    debug(0,0)("XXX need to fix\n");
}

static void
parse_vizhack(void)
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
dump_waisrelay(void)
{
    debug(0,0)("XXX need to fix\n");
}

static void
parse_waisrelay(void)
{
    char *token;
    int i;
    token = strtok(NULL, w_space);
    if (token == NULL)
	self_destruct();
    safe_free(Config.Wais.relayHost);
    Config.Wais.relayHost = xstrdup(token);
    GetInteger(i);
    Config.Wais.relayPort = (u_short) i;
}

static void
dump_wordlist(wordlist * list)
{
    printf("{");
    while (list != NULL) {
	printf("%s ", list->key);
	list = list->next;
    }
    printf("}");
}

static void
parse_wordlist(wordlist ** list)
{
    char *token;

    while ((token = strtok(NULL, w_space)))
	wordlistAdd(list, token);
}

static void
parse_proxyauth(void)
{
	fatal("not implemented");
}

static void
dump_proxyauth(void)
{
	fatal("not implemented");
}

#include "cf_parser.c"
