    memset(addr, '\0', sizeof(struct in_addr));
}

#if DELAY_POOLS

/* do nothing - free_delay_pool_count is the magic free function.
 * this is why delay_pool_count isn't just marked TYPE: ushort
 */
#define free_delay_pool_class(X)
#define free_delay_pool_access(X)
#define free_delay_pool_rates(X)
#define dump_delay_pool_class(X, Y, Z)
#define dump_delay_pool_access(X, Y, Z)
#define dump_delay_pool_rates(X, Y, Z)

static void
free_delay_pool_count(delayConfig * cfg)
{
    int i;

    if (!cfg->pools)
	return;
    for (i = 0; i < cfg->pools; i++) {
	if (cfg->class[i]) {
	    delayFreeDelayPool(i);
	    safe_free(cfg->rates[i]);
	}
	aclDestroyAccessList(&cfg->access[i]);
    }
    delayFreeDelayData();
    xfree(cfg->class);
    xfree(cfg->rates);
    xfree(cfg->access);
    memset(cfg, 0, sizeof(*cfg));
}

static void
dump_delay_pool_count(StoreEntry * entry, const char *name, delayConfig cfg)
{
    int i;
    LOCAL_ARRAY(char, nom, 32);

    if (!cfg.pools) {
	storeAppendPrintf(entry, "%s 0\n", name);
	return;
    }
    storeAppendPrintf(entry, "%s %d\n", name, cfg.pools);
    for (i = 0; i < cfg.pools; i++) {
	storeAppendPrintf(entry, "delay_class %d %d\n", i + 1, cfg.class[i]);
	snprintf(nom, 32, "delay_access %d", i + 1);
	dump_acl_access(entry, nom, cfg.access[i]);
	if (cfg.class[i] >= 1)
	    storeAppendPrintf(entry, "delay_parameters %d %d/%d", i + 1,
		cfg.rates[i]->aggregate.restore_bps,
		cfg.rates[i]->aggregate.max_bytes);
	if (cfg.class[i] >= 3)
	    storeAppendPrintf(entry, " %d/%d",
		cfg.rates[i]->network.restore_bps,
		cfg.rates[i]->network.max_bytes);
	if (cfg.class[i] >= 2)
	    storeAppendPrintf(entry, " %d/%d",
		cfg.rates[i]->individual.restore_bps,
		cfg.rates[i]->individual.max_bytes);
	if (cfg.class[i] >= 1)
	    storeAppendPrintf(entry, "\n");
    }
}

static void
parse_delay_pool_count(delayConfig * cfg)
{
    if (cfg->pools) {
	debug(3, 0) ("parse_delay_pool_count: multiple delay_pools lines, aborting all previous delay_pools config\n");
	free_delay_pool_count(cfg);
    }
    parse_ushort(&cfg->pools);
    delayInitDelayData(cfg->pools);
    cfg->class = xcalloc(cfg->pools, sizeof(u_char));
    cfg->rates = xcalloc(cfg->pools, sizeof(delaySpecSet *));
    cfg->access = xcalloc(cfg->pools, sizeof(acl_access *));
}

static void
parse_delay_pool_class(delayConfig * cfg)
{
    ushort pool, class;

    parse_ushort(&pool);
    if (pool < 1 || pool > cfg->pools) {
	debug(3, 0) ("parse_delay_pool_class: Ignoring pool %d not in 1 .. %d\n", pool, cfg->pools);
	return;
    }
    parse_ushort(&class);
    if (class < 1 || class > 3) {
	debug(3, 0) ("parse_delay_pool_class: Ignoring pool %d class %d not in 1 .. 3\n", pool, class);
	return;
    }
    pool--;
    if (cfg->class[pool]) {
	delayFreeDelayPool(pool);
	safe_free(cfg->rates[pool]);
    }
    cfg->rates[pool] = xmalloc(class * sizeof(delaySpec));
    cfg->class[pool] = class;
    cfg->rates[pool]->aggregate.restore_bps = cfg->rates[pool]->aggregate.max_bytes = -1;
    if (cfg->class[pool] >= 3)
	cfg->rates[pool]->network.restore_bps = cfg->rates[pool]->network.max_bytes = -1;
    if (cfg->class[pool] >= 2)
	cfg->rates[pool]->individual.restore_bps = cfg->rates[pool]->individual.max_bytes = -1;
    delayCreateDelayPool(pool, class);
}

static void
parse_delay_pool_rates(delayConfig * cfg)
{
    ushort pool, class;
    int i;
    delaySpec *ptr;
    char *token;

    parse_ushort(&pool);
    if (pool < 1 || pool > cfg->pools) {
	debug(3, 0) ("parse_delay_pool_rates: Ignoring pool %d not in 1 .. %d\n", pool, cfg->pools);
	return;
    }
    pool--;
    class = cfg->class[pool];
    if (class == 0) {
	debug(3, 0) ("parse_delay_pool_rates: Ignoring pool %d attempt to set rates with class not set\n", pool + 1);
	return;
    }
    ptr = (delaySpec *) cfg->rates[pool];
    /* read in "class" sets of restore,max pairs */
    while (class--) {
	token = strtok(NULL, "/");
	if (token == NULL)
	    self_destruct();
	if (sscanf(token, "%d", &i) != 1)
	    self_destruct();
	ptr->restore_bps = i;
	GetInteger(i);
	ptr->max_bytes = i;
	ptr++;
    }
    class = cfg->class[pool];
    /* if class is 3, swap around network and individual */
    if (class == 3) {
	delaySpec tmp;

	tmp = cfg->rates[pool]->individual;
	cfg->rates[pool]->individual = cfg->rates[pool]->network;
	cfg->rates[pool]->network = tmp;
    }
    /* initialize the delay pools */
    delayInitDelayPool(pool, class, cfg->rates[pool]);
}

static void
parse_delay_pool_access(delayConfig * cfg)
{
    ushort pool;

    parse_ushort(&pool);
    if (pool < 1 || pool > cfg->pools) {
	debug(3, 0) ("parse_delay_pool_rates: Ignoring pool %d not in 1 .. %d\n", pool, cfg->pools);
	return;
    }
    aclParseAccessLine(&cfg->access[pool - 1]);
}
#endif

static void
dump_http_header(StoreEntry * entry, const char *name, HttpHeaderMask header)
{
