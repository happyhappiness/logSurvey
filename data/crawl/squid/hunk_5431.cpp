 #define dump_delay_pool_rates(X, Y, Z)
 
 static void
-free_delay_pool_count(delayConfig * cfg)
+free_delay_pool_count(DelayConfig * cfg)
 {
-    int i;
-
-    if (!cfg->pools)
-	return;
-    for (i = 0; i < cfg->pools; i++) {
-	if (cfg->delay_class[i]) {
-	    delayFreeDelayPool(i);
-	    safe_free(cfg->rates[i]);
-	}
-	aclDestroyAccessList(&cfg->access[i]);
-    }
-    delayFreeDelayData(cfg->pools);
-    xfree(cfg->delay_class);
-    xfree(cfg->rates);
-    xfree(cfg->access);
-    memset(cfg, 0, sizeof(*cfg));
+    cfg->freePoolCount();
 }
 
 static void
-dump_delay_pool_count(StoreEntry * entry, const char *name, delayConfig cfg)
+dump_delay_pool_count(StoreEntry * entry, const char *name, DelayConfig &cfg)
 {
-    int i;
-    LOCAL_ARRAY(char, nom, 32);
-
-    if (!cfg.pools) {
-	storeAppendPrintf(entry, "%s 0\n", name);
-	return;
-    }
-    storeAppendPrintf(entry, "%s %d\n", name, cfg.pools);
-    for (i = 0; i < cfg.pools; i++) {
-	storeAppendPrintf(entry, "delay_class %d %d\n", i + 1, cfg.delay_class[i]);
-	snprintf(nom, 32, "delay_access %d", i + 1);
-	dump_acl_access(entry, nom, cfg.access[i]);
-	if (cfg.delay_class[i] >= 1)
-	    storeAppendPrintf(entry, "delay_parameters %d %d/%d", i + 1,
-		cfg.rates[i]->aggregate.restore_bps,
-		cfg.rates[i]->aggregate.max_bytes);
-	if (cfg.delay_class[i] >= 3)
-	    storeAppendPrintf(entry, " %d/%d",
-		cfg.rates[i]->network.restore_bps,
-		cfg.rates[i]->network.max_bytes);
-	if (cfg.delay_class[i] >= 2)
-	    storeAppendPrintf(entry, " %d/%d",
-		cfg.rates[i]->individual.restore_bps,
-		cfg.rates[i]->individual.max_bytes);
-	if (cfg.delay_class[i] >= 1)
-	    storeAppendPrintf(entry, "\n");
-    }
+    cfg.dumpPoolCount (entry, name);
 }
 
 static void
-parse_delay_pool_count(delayConfig * cfg)
+parse_delay_pool_count(DelayConfig * cfg)
 {
-    if (cfg->pools) {
-	debug(3, 0) ("parse_delay_pool_count: multiple delay_pools lines, aborting all previous delay_pools config\n");
-	free_delay_pool_count(cfg);
-    }
-    parse_ushort(&cfg->pools);
-    if (cfg->pools) {
-	delayInitDelayData(cfg->pools);
-	cfg->delay_class = (unsigned char *)xcalloc(cfg->pools, sizeof(unsigned char));
-	cfg->rates = (delaySpecSet **)xcalloc(cfg->pools, sizeof(delaySpecSet *));
-	cfg->access = (acl_access **)xcalloc(cfg->pools, sizeof(acl_access *));
-    }
+    cfg->parsePoolCount();
 }
 
 static void
-parse_delay_pool_class(delayConfig * cfg)
+parse_delay_pool_class(DelayConfig * cfg)
 {
-    ushort pool, delay_class;
-
-    parse_ushort(&pool);
-    if (pool < 1 || pool > cfg->pools) {
-	debug(3, 0) ("parse_delay_pool_class: Ignoring pool %d not in 1 .. %d\n", pool, cfg->pools);
-	return;
-    }
-    parse_ushort(&delay_class);
-    if (delay_class < 1 || delay_class > 3) {
-	debug(3, 0) ("parse_delay_pool_class: Ignoring pool %d class %d not in 1 .. 3\n", pool, delay_class);
-	return;
-    }
-    pool--;
-    if (cfg->delay_class[pool]) {
-	delayFreeDelayPool(pool);
-	safe_free(cfg->rates[pool]);
-    }
-    /* Allocates a "delaySpecSet" just as large as needed for the class */
-    cfg->rates[pool] = (delaySpecSet *)xmalloc(delay_class * sizeof(delaySpec));
-    cfg->delay_class[pool] = delay_class;
-    cfg->rates[pool]->aggregate.restore_bps = cfg->rates[pool]->aggregate.max_bytes = -1;
-    if (cfg->delay_class[pool] >= 3)
-	cfg->rates[pool]->network.restore_bps = cfg->rates[pool]->network.max_bytes = -1;
-    if (cfg->delay_class[pool] >= 2)
-	cfg->rates[pool]->individual.restore_bps = cfg->rates[pool]->individual.max_bytes = -1;
-    delayCreateDelayPool(pool, delay_class);
+    cfg->parsePoolClass();
 }
 
 static void
-parse_delay_pool_rates(delayConfig * cfg)
+parse_delay_pool_rates(DelayConfig * cfg)
 {
-    ushort pool, delay_class;
-    int i;
-    delaySpec *ptr;
-    char *token;
-
-    parse_ushort(&pool);
-    if (pool < 1 || pool > cfg->pools) {
-	debug(3, 0) ("parse_delay_pool_rates: Ignoring pool %d not in 1 .. %d\n", pool, cfg->pools);
-	return;
-    }
-    pool--;
-    delay_class = cfg->delay_class[pool];
-    if (delay_class == 0) {
-	debug(3, 0) ("parse_delay_pool_rates: Ignoring pool %d attempt to set rates with class not set\n", pool + 1);
-	return;
-    }
-    ptr = (delaySpec *) cfg->rates[pool];
-    /* read in "class" sets of restore,max pairs */
-    while (delay_class--) {
-	token = strtok(NULL, "/");
-	if (token == NULL)
-	    self_destruct();
-	if (sscanf(token, "%d", &i) != 1)
-	    self_destruct();
-	ptr->restore_bps = i;
-	i = GetInteger();
-	ptr->max_bytes = i;
-	ptr++;
-    }
-    delay_class = cfg->delay_class[pool];
-    /* if class is 3, swap around network and individual */
-    if (delay_class == 3) {
-	delaySpec tmp;
-
-	tmp = cfg->rates[pool]->individual;
-	cfg->rates[pool]->individual = cfg->rates[pool]->network;
-	cfg->rates[pool]->network = tmp;
-    }
-    /* initialize the delay pools */
-    delayInitDelayPool(pool, delay_class, cfg->rates[pool]);
+    cfg->parsePoolRates();
 }
 
 static void
-parse_delay_pool_access(delayConfig * cfg)
+parse_delay_pool_access(DelayConfig * cfg)
 {
-    ushort pool;
-
-    parse_ushort(&pool);
-    if (pool < 1 || pool > cfg->pools) {
-	debug(3, 0) ("parse_delay_pool_rates: Ignoring pool %d not in 1 .. %d\n", pool, cfg->pools);
-	return;
-    }
-    aclParseAccessLine(&cfg->access[pool - 1]);
+    cfg->parsePoolAccess();
 }
 #endif
 
