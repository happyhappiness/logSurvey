}

static void
dump_cachedir(struct _cacheSwap swap)
{
    debug(0,0)("XXX need to fix\n");
}

static void
parse_cachedir(struct _cacheSwap *swap)
{
    char *token;
    char *path;
    int i;
    int size;
    int l1;
    int l2;
    int readonly = 0;
    SwapDir *tmp = NULL;
    if ((path = strtok(NULL, w_space)) == NULL)
	self_destruct();
    if (strlen(path) > (SQUID_MAXPATHLEN - 32))
	fatal_dump("cache_dir pathname is too long");
    GetInteger(i);
    size = i << 10;		/* Mbytes to kbytes */
    GetInteger(i);
    l1 = i;
    GetInteger(i);
    l2 = i;
    if ((token = strtok(NULL, w_space)))
	if (!strcasecmp(token, "read-only"))
	    readonly = 1;
    for (i = 0; i < swap->n_configured; i++) {
	tmp = swap->swapDirs+i;
	if (!strcmp(path, tmp->path)) {
	    /* just reconfigure it */
            tmp->max_size = size;
            tmp->read_only = readonly;
	    return;
	}
    }
    if (swap->swapDirs == NULL) {
	swap->n_allocated = 4;
	swap->swapDirs = xcalloc(swap->n_allocated, sizeof(SwapDir));
    }
    if (swap->n_allocated == swap->n_configured) {
	swap->n_allocated <<= 1;
	tmp = xcalloc(swap->n_allocated, sizeof(SwapDir));
	xmemcpy(tmp, swap->swapDirs, swap->n_configured * sizeof(SwapDir));
	xfree(swap->swapDirs);
	swap->swapDirs = tmp;
    }
    debug(20, 1) ("Creating Swap Dir #%d in %s\n", swap->n_configured + 1, path);
    tmp = swap->swapDirs + swap->n_configured;
    tmp->path = xstrdup(path);
    tmp->max_size = size;
    tmp->l1 = l1;
    tmp->l2 = l2;
    tmp->read_only = readonly;
    tmp->map = file_map_create(MAX_FILES_PER_DIR);
    tmp->swaplog_fd = -1;
}

static void
free_cachedir(struct _cacheSwap *swap)
{
	assert(0);
}

static void
dump_cache_peer(cache_peer *p)
{
    debug(0,0)("XXX need to fix\n");
}

static void
parse_cache_peer(cache_peer **head)
{
    char *token = NULL;
    cache_peer peer;
    cache_peer *p;
    int i;
    memset(&peer, '\0', sizeof(cache_peer));
    peer.http = CACHE_HTTP_PORT;
    peer.icp = CACHE_ICP_PORT;
    peer.weight = 1;
