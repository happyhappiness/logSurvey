}

static void
dump_announceto(void)
{
    debug(0,0)("XXX need to fix\n");
}

static void
parse_announceto(void)
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
dump_appenddomain(void)
{
    debug(0,0)("XXX need to fix\n");
}

static void
parse_appenddomain(void)
{
    char *token = strtok(NULL, w_space);

    if (token == NULL)
	self_destruct();
    if (*token != '.')
	self_destruct();
    safe_free(Config.appendDomain);
    Config.appendDomain = xstrdup(token);
}

static void
dump_cacheannounce(void)
{
    debug(0,0)("XXX need to fix\n");
}

static void
parse_cacheannounce(void)
{
    char *token;
    int i;
    GetInteger(i);
    Config.Announce.rate = i * 3600;	/* hours to seconds */
    if (Config.Announce.rate > 0)
	Config.Announce.on = 1;
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
dump_cache_peer(struct cache_peer *p)
{
    debug(0,0)("XXX need to fix\n");
}

static void
parse_cache_peer(struct cache_peer **head)
{
    char *token = NULL;
    struct cache_peer peer;
    struct cache_peer *p;
    int i;
    memset(&peer, '\0', sizeof(struct cache_peer));
    peer.http = CACHE_HTTP_PORT;
    peer.icp = CACHE_ICP_PORT;
    peer.weight = 1;
