 #if DELAY_POOLS
 #include "squid.h"
 
-struct _delayData {
-    int class1_aggregate;
-    int class2_aggregate;
-    /* 254 entries + 1 terminator byte */
-    unsigned char class2_individual_map[255];
-    /* 254 entries */
-    int class2_individual[254];
-    int class3_aggregate;
+struct _class1DelayPool {
+    int aggregate;
+};
+
+struct _class2DelayPool {
+    int aggregate;
+    /* OK: -1 is terminator.  individual[255] is always host 255. */
     /* 255 entries + 1 terminator byte */
-    unsigned char class3_network_map[256];
-    /* 255 entries */
-    int class3_network[255];
-    /* 255 sets of (254 entries + 1 terminator byte) */
-    unsigned char class3_individual_map[255][255];
-    /* largest entry = (254<<8)+253 = 65277 */
-    int class3_individual[65278];
+    unsigned char individual_map[256];
+    unsigned char individual_255_used;
+    /* 256 entries */
+    int individual[256];
 };
 
-static struct _delayData delay_data;
-static OBJH delayPoolStats;
+struct _class3DelayPool {
+    int aggregate;
+    /* OK: -1 is terminator.  network[255] is always host 255. */
+    /* 255 entries + 1 terminator byte */
+    unsigned char network_map[256];
+    unsigned char network_255_used;
+    /* 256 entries */
+    int network[256];
+    /* 256 sets of (255 entries + 1 terminator byte) */
+    unsigned char individual_map[256][256];
+    /* Pack this into one bit per net */
+    unsigned char individual_255_used[32];
+    /* largest entry = (255<<8)+255 = 65535 */
+    int individual[65536];
+};
+
+typedef struct _class1DelayPool class1DelayPool;
+typedef struct _class2DelayPool class2DelayPool;
+typedef struct _class3DelayPool class3DelayPool;
+
+union _delayPool {
+    class1DelayPool *class1;
+    class2DelayPool *class2;
+    class3DelayPool *class3;
+};
+
+typedef union _delayPool delayPool;
+
+static delayPool *delay_data = NULL;
+static fd_set delay_no_delay;
 static time_t delay_pools_last_update = 0;
-static delay_id delayId(unsigned char class, int position);
 
-static delay_id
-delayId(unsigned char class, int position)
+static OBJH delayPoolStats;
+
+void
+delayPoolsInit(void)
 {
-    assert(class <= 3);
-    return (class << 16) | (position & 0xFFFF);
+    delay_pools_last_update = getCurrentTime();
+    FD_ZERO(&delay_no_delay);
+    cachemgrRegister("delay", "Delay Pool Levels", delayPoolStats, 0, 1);
+}
+
+void
+delayInitDelayData(unsigned short pools)
+{
+    if (pools) {
+	delay_data = xcalloc(pools, sizeof(delayPool));
+	eventAdd("delayPoolsUpdate", delayPoolsUpdate, NULL, 1.0, 1);
+    }
+}
+
+void
+delayFreeDelayData()
+{
+    safe_free(delay_data);
+}
+
+void
+delayCreateDelayPool(unsigned short pool, u_char class)
+{
+    switch (class) {
+    case 1:
+	delay_data[pool].class1 = xmalloc(sizeof(class1DelayPool));
+	break;
+    case 2:
+	delay_data[pool].class2 = xmalloc(sizeof(class2DelayPool));
+	break;
+    case 3:
+	delay_data[pool].class3 = xmalloc(sizeof(class3DelayPool));
+	break;
+    default:
+	assert(0);
+    }
+}
+
+void
+delayInitDelayPool(unsigned short pool, u_char class, delaySpecSet * rates)
+{
+    /* delaySetSpec may be pointer to partial structure so MUST pass by
+     * reference.
+     */
+    switch (class) {
+    case 1:
+	delay_data[pool].class1->aggregate = (rates->aggregate.max_bytes *
+	    Config.Delay.initial) / 100;
+	break;
+    case 2:
+	delay_data[pool].class2->aggregate = (rates->aggregate.max_bytes *
+	    Config.Delay.initial) / 100;
+	delay_data[pool].class2->individual_map[0] = 255;
+	delay_data[pool].class2->individual_255_used = 0;
+	break;
+    case 3:
+	delay_data[pool].class3->aggregate = (rates->aggregate.max_bytes *
+	    Config.Delay.initial) / 100;
+	delay_data[pool].class3->network_map[0] = 255;
+	delay_data[pool].class3->network_255_used = 0;
+	memset(&delay_data[pool].class3->individual_255_used, '\0',
+	    sizeof(delay_data[pool].class3->individual_255_used));
+	break;
+    default:
+	assert(0);
+    }
+}
+
+void
+delayFreeDelayPool(unsigned short pool)
+{
+    /* this is a union - and all free() cares about is the pointer location */
+    safe_free(delay_data[pool].class1);
+}
+
+void
+delaySetNoDelay(int fd)
+{
+    FD_SET(fd, &delay_no_delay);
+}
+
+void
+delayClearNoDelay(int fd)
+{
+    FD_CLR(fd, &delay_no_delay);
 }
 
 int
-delayClient(clientHttpRequest * http)
+delayIsNoDelay(int fd)
+{
+    return FD_ISSET(fd, &delay_no_delay);
+}
+
+static delay_id
+delayId(unsigned short pool, unsigned short position)
+{
+    return (pool << 16) | position;
+}
+
+delay_id
+delayClient(request_t *r)
 {
     aclCheck_t ch;
     int i;
     int j;
     unsigned int host;
-    unsigned char net;
-    unsigned char class = 0;
-    int position = 0;
-    request_t *r = http->request;
+    unsigned short pool, position;
+    unsigned char class, net;
 
     memset(&ch, '\0', sizeof(ch));
-    ch.src_addr = http->conn->peer.sin_addr;
+    ch.src_addr = r->client_addr;
+    ch.my_addr = r->my_addr;
     ch.request = r;
-    if (aclCheckFast(Config.Delay.class1.access, &ch)) {
-	class = 1;
-	r->delay_id = delayId(class, position);
-	return 1;
+    for (pool = 0; pool < Config.Delay.pools; pool++) {
+	if (aclCheckFast(Config.Delay.access[pool], &ch))
+	    break;
     }
-    if (aclCheckFast(Config.Delay.class2.access, &ch)) {
-	class = 2;
+    if (pool == Config.Delay.pools)
+	return delayId(0, 0);
+    class = Config.Delay.class[pool];
+    if (class == 0)
+	return delayId(0, 0);
+    if (class == 1)
+	return delayId(pool + 1, 0);
+    if (class == 2) {
 	host = ntohl(ch.src_addr.s_addr) & 0xff;
-	if (host == 255 || !host) {
-	    debug(77, 0) ("ARGH: Delay requested for host %s\n", inet_ntoa(ch.src_addr));
-	    class = 0;
-	    r->delay_id = delayId(class, position);
-	    return 0;
+	if (host == 255) {
+	    if (!delay_data[pool].class2->individual_255_used) {
+		delay_data[pool].class2->individual_255_used = 1;
+		delay_data[pool].class2->individual[255] =
+		    (Config.Delay.rates[pool]->individual.max_bytes *
+		    Config.Delay.initial) / 100;
+	    }
+	    return delayId(pool + 1, 255);
 	}
 	for (i = 0;; i++) {
-	    if (delay_data.class2_individual_map[i] == host)
+	    if (delay_data[pool].class2->individual_map[i] == host)
 		break;
-	    if (delay_data.class2_individual_map[i] == 255) {
-		delay_data.class2_individual_map[i] = host;
-		delay_data.class2_individual_map[i + 1] = 255;
-		delay_data.class2_individual[i] = Config.Delay.class2.individual.restore_bps;
+	    if (delay_data[pool].class2->individual_map[i] == 255) {
+		delay_data[pool].class2->individual_map[i] = host;
+		delay_data[pool].class2->individual_map[i + 1] = 255;
+		delay_data[pool].class2->individual[i] =
+		    (Config.Delay.rates[pool]->individual.max_bytes *
+		    Config.Delay.initial) / 100;
 		break;
 	    }
 	}
-	position = i;
-	r->delay_id = delayId(class, position);
-	return 1;
+	return delayId(pool + 1, i);
     }
-    if (aclCheckFast(Config.Delay.class3.access, &ch)) {
-	class = 3;
-	host = ntohl(ch.src_addr.s_addr) & 0xffff;
-	net = host >> 8;
-	host &= 0xff;
-	if (host == 255 || !host || net == 255) {
-	    debug(77, 0) ("ARGH: Delay requested for host %s\n", inet_ntoa(ch.src_addr));
-	    class = 0;
-	    r->delay_id = delayId(class, position);
-	    return 0;
+    /* class == 3 */
+    host = ntohl(ch.src_addr.s_addr) & 0xffff;
+    net = host >> 8;
+    host &= 0xff;
+    if (net == 255) {
+	i = 255;
+	if (!delay_data[pool].class3->network_255_used) {
+	    delay_data[pool].class3->network_255_used = 1;
+	    delay_data[pool].class3->network[255] =
+		(Config.Delay.rates[pool]->network.max_bytes *
+		Config.Delay.initial) / 100;
 	}
+    } else {
 	for (i = 0;; i++) {
-	    if (delay_data.class3_network_map[i] == net)
+	    if (delay_data[pool].class3->network_map[i] == net)
 		break;
-	    if (delay_data.class3_network_map[i] == 255) {
-		delay_data.class3_network_map[i] = net;
-		delay_data.class3_individual_map[i][0] = 255;
-		delay_data.class3_network_map[i + 1] = 255;
-		delay_data.class3_network[i] = Config.Delay.class3.network.restore_bps;
+	    if (delay_data[pool].class3->network_map[i] == 255) {
+		delay_data[pool].class3->network_map[i] = net;
+		delay_data[pool].class3->individual_map[i][0] = 255;
+		delay_data[pool].class3->network_map[i + 1] = 255;
+		delay_data[pool].class3->network[i] =
+		    (Config.Delay.rates[pool]->network.max_bytes *
+		    Config.Delay.initial) / 100;
 		break;
 	    }
 	}
-	position = i << 8;
-	for (j = 0;; j++) {
-	    if (delay_data.class3_individual_map[i][j] == host) {
-		position |= j;
-		break;
-	    }
-	    if (delay_data.class3_individual_map[i][j] == 255) {
-		delay_data.class3_individual_map[i][j] = host;
-		delay_data.class3_individual_map[i][j + 1] = 255;
-		delay_data.class3_individual[position |= j] =
-		    Config.Delay.class3.individual.restore_bps;
-		break;
-	    }
+    }
+    position = i << 8;
+    if (host == 255) {
+	position |= 255;
+	if (!(delay_data[pool].class3->individual_255_used[i / 8] & (1 << (i % 8)))) {
+	    delay_data[pool].class3->individual_255_used[i / 8] |= (1 << (i % 8));
+	    delay_data[pool].class3->individual[position] =
+		(Config.Delay.rates[pool]->individual.max_bytes *
+		Config.Delay.initial) / 100;
 	}
-	r->delay_id = delayId(class, position);
-	return 1;
+	return delayId(pool + 1, position);
     }
-    class = 0;
-    r->delay_id = delayId(class, position);
-    return 0;
+    for (j = 0;; j++) {
+	if (delay_data[pool].class3->individual_map[i][j] == host) {
+	    position |= j;
+	    break;
+	}
+	if (delay_data[pool].class3->individual_map[i][j] == 255) {
+	    delay_data[pool].class3->individual_map[i][j] = host;
+	    delay_data[pool].class3->individual_map[i][j + 1] = 255;
+	    delay_data[pool].class3->individual[position |= j] =
+		(Config.Delay.rates[pool]->individual.max_bytes *
+		Config.Delay.initial) / 100;
+	    break;
+	}
+    }
+    return delayId(pool + 1, position);
 }
 
+static void
+delayUpdateClass1(class1DelayPool * class1, delaySpecSet * rates, int incr)
+{
+    /* delaySetSpec may be pointer to partial structure so MUST pass by
+     * reference.
+     */
+    if (rates->aggregate.restore_bps != -1 &&
+	(class1->aggregate += rates->aggregate.restore_bps * incr) >
+	rates->aggregate.max_bytes)
+	class1->aggregate = rates->aggregate.max_bytes;
+}
 
-void
-delayPoolsUpdate(void *unused)
+static void
+delayUpdateClass2(class2DelayPool * class2, delaySpecSet * rates, int incr)
 {
-    int incr = squid_curtime - delay_pools_last_update;
-    int i;
-    int j;
-    int mpos;
-    int individual_restore_bytes;
-    int network_restore_bytes;
-    eventAdd("delayPoolsUpdate", delayPoolsUpdate, NULL, 1.0, 1);
-    if (incr < 1)
+    int restore_bytes;
+    unsigned char i;
+    /* delaySetSpec may be pointer to partial structure so MUST pass by
+     * reference.
+     */
+    if (rates->aggregate.restore_bps != -1 &&
+	(class2->aggregate += rates->aggregate.restore_bps * incr) >
+	rates->aggregate.max_bytes)
+	class2->aggregate = rates->aggregate.max_bytes;
+    if ((restore_bytes = rates->individual.restore_bps) == -1)
 	return;
-    delay_pools_last_update = squid_curtime;
-    /* Increment 3 aggregate pools */
-    if (Config.Delay.class1.aggregate.restore_bps != -1 &&
-	(delay_data.class1_aggregate +=
-	    Config.Delay.class1.aggregate.restore_bps * incr) >
-	Config.Delay.class1.aggregate.max_bytes)
-	delay_data.class1_aggregate = Config.Delay.class1.aggregate.max_bytes;
-    if (Config.Delay.class2.aggregate.restore_bps != -1 &&
-	(delay_data.class2_aggregate +=
-	    Config.Delay.class2.aggregate.restore_bps * incr) >
-	Config.Delay.class2.aggregate.max_bytes)
-	delay_data.class2_aggregate = Config.Delay.class2.aggregate.max_bytes;
-    if (Config.Delay.class3.aggregate.restore_bps != -1 &&
-	(delay_data.class3_aggregate +=
-	    Config.Delay.class3.aggregate.restore_bps * incr) >
-	Config.Delay.class3.aggregate.max_bytes)
-	delay_data.class3_aggregate = Config.Delay.class3.aggregate.max_bytes;
-    /* Increment class 2 individual pools */
-    if ((individual_restore_bytes = Config.Delay.class2.individual.restore_bps) != -1) {
-	individual_restore_bytes *= incr;
-	for (i = 0;; i++) {
-	    if (delay_data.class2_individual_map[i] == 255)
-		break;
-	    if (delay_data.class2_individual[i] == Config.Delay.class2.individual.max_bytes)
-		continue;
-	    if ((delay_data.class2_individual[i] += individual_restore_bytes) >
-		Config.Delay.class2.individual.max_bytes)
-		delay_data.class2_individual[i] = Config.Delay.class2.individual.max_bytes;
-	}
-    }
-    /* Increment class 3 individual and network pools */
-    if ((network_restore_bytes = Config.Delay.class3.network.restore_bps) != -1 ||
-	(individual_restore_bytes = Config.Delay.class3.individual.restore_bps) != -1) {
-	individual_restore_bytes *= incr;
-	network_restore_bytes *= incr;
-	for (i = 0;; i++) {
-	    if (delay_data.class3_network_map[i] == 255)
-		break;
-	    if (individual_restore_bytes != -incr) {
-		for (j = 0, mpos = (i << 8);; j++, mpos++) {
-		    if (delay_data.class3_individual_map[i][j] == 255)
-			break;
-		    if (delay_data.class3_individual[mpos] == Config.Delay.class3.individual.max_bytes)
-			continue;
-		    if ((delay_data.class3_individual[mpos] += individual_restore_bytes) >
-			Config.Delay.class3.individual.max_bytes)
-			delay_data.class3_individual[mpos] = Config.Delay.class3.individual.max_bytes;
-		}
-	    }
-	    if (network_restore_bytes == -incr ||
-		delay_data.class3_network[i] == Config.Delay.class3.network.max_bytes)
-		continue;
-	    if ((delay_data.class3_network[i] += network_restore_bytes) >
-		Config.Delay.class3.network.max_bytes)
-		delay_data.class3_network[i] = Config.Delay.class3.network.max_bytes;
-	}
+    restore_bytes *= incr;
+    if (class2->individual_255_used)
+	i = 255;
+    else
+	i = 0;
+    for (;;) {
+	if (i != 255 && class2->individual_map[i] == 255)
+	    return;
+	if (class2->individual[i] != rates->individual.max_bytes &&
+	    (class2->individual[i] += restore_bytes) > rates->individual.max_bytes)
+	    class2->individual[i] = rates->individual.max_bytes;
+	if (++i == 255)
+	    return;
     }
 }
 
-
 static void
-delayPoolStats(StoreEntry * sentry)
+delayUpdateClass3(class3DelayPool * class3, delaySpecSet * rates, int incr)
 {
-    int i;
-    int j;
-    storeAppendPrintf(sentry, "Class 1 Delay Pool Statistics:\n");
-    if (Config.Delay.class1.aggregate.restore_bps != -1) {
-	storeAppendPrintf(sentry, "\n\tAggregate:\n");
-	storeAppendPrintf(sentry, "\t\tMax: %d\n",
-	    Config.Delay.class1.aggregate.max_bytes);
-	storeAppendPrintf(sentry, "\t\tRate: %d\n",
-	    Config.Delay.class1.aggregate.restore_bps);
-	storeAppendPrintf(sentry, "\t\tCurrent: %d\n",
-	    delay_data.class1_aggregate);
-    } else {
-	storeAppendPrintf(sentry, "\n\tAggregate:\n\tDisabled.\n");
-    }
-    storeAppendPrintf(sentry, "\nClass 2 Delay Pool Statistics:\n");
-    if (Config.Delay.class2.aggregate.restore_bps != -1) {
-	storeAppendPrintf(sentry, "\n\tAggregate:\n");
-	storeAppendPrintf(sentry, "\t\tMax: %d\n",
-	    Config.Delay.class2.aggregate.max_bytes);
-	storeAppendPrintf(sentry, "\t\tRate: %d\n",
-	    Config.Delay.class2.aggregate.restore_bps);
-	storeAppendPrintf(sentry, "\t\tCurrent: %d\n",
-	    delay_data.class2_aggregate);
-    } else {
-	storeAppendPrintf(sentry, "\n\tAggregate:\n\tDisabled.\n");
-    }
-    if (Config.Delay.class2.individual.restore_bps != -1) {
-	storeAppendPrintf(sentry, "\n\tIndividual:\n");
-	storeAppendPrintf(sentry, "\t\tMax: %d\n",
-	    Config.Delay.class2.individual.max_bytes);
-	storeAppendPrintf(sentry, "\t\tRate: %d\n",
-	    Config.Delay.class2.individual.restore_bps);
-	storeAppendPrintf(sentry, "\t\tCurrent: ");
-	for (i = 0;; i++) {
-	    if (delay_data.class2_individual_map[i] == 255)
-		break;
-	    storeAppendPrintf(sentry, "%d:%d ",
-		delay_data.class2_individual_map[i],
-		delay_data.class2_individual[i]);
-	}
-    } else {
-	storeAppendPrintf(sentry, "\n\tIndividual:\n\tDisabled.");
-    }
-    storeAppendPrintf(sentry, "\n\nClass 3 Delay Pool Statistics:\n");
-    if (Config.Delay.class3.aggregate.restore_bps != -1) {
-	storeAppendPrintf(sentry, "\n\tAggregate:\n");
-	storeAppendPrintf(sentry, "\t\tMax: %d\n",
-	    Config.Delay.class3.aggregate.max_bytes);
-	storeAppendPrintf(sentry, "\t\tRate: %d\n",
-	    Config.Delay.class3.aggregate.restore_bps);
-	storeAppendPrintf(sentry, "\t\tCurrent: %d\n",
-	    delay_data.class3_aggregate);
-    } else {
-	storeAppendPrintf(sentry, "\n\tAggregate:\n\tDisabled.\n");
-    }
-    if (Config.Delay.class3.network.restore_bps != -1) {
-	storeAppendPrintf(sentry, "\n\tNetwork:\n");
-	storeAppendPrintf(sentry, "\t\tMax: %d\n",
-	    Config.Delay.class3.network.max_bytes);
-	storeAppendPrintf(sentry, "\t\tRate: %d\n",
-	    Config.Delay.class3.network.restore_bps);
-	storeAppendPrintf(sentry, "\t\tCurrent: ");
-	for (i = 0;; i++) {
-	    if (delay_data.class3_network_map[i] == 255)
-		break;
-	    storeAppendPrintf(sentry, "%d:%d ",
-		delay_data.class3_network_map[i],
-		delay_data.class3_network[i]);
-	}
-    } else {
-	storeAppendPrintf(sentry, "\n\tNetwork:\n\tDisabled.");
-    }
-    if (Config.Delay.class3.individual.restore_bps != -1) {
-	storeAppendPrintf(sentry, "\n\n\tIndividual:\n");
-	storeAppendPrintf(sentry, "\t\tMax: %d\n",
-	    Config.Delay.class3.individual.max_bytes);
-	storeAppendPrintf(sentry, "\t\tRate: %d\n",
-	    Config.Delay.class3.individual.restore_bps);
-	for (i = 0;; i++) {
-	    if (delay_data.class3_network_map[i] == 255)
-		break;
-	    storeAppendPrintf(sentry, "\t\tCurrent [Network %d]: ",
-		delay_data.class3_network_map[i]);
-	    for (j = 0;; j++) {
-		if (delay_data.class3_individual_map[i][j] == 255)
+    int individual_restore_bytes, network_restore_bytes;
+    int mpos;
+    unsigned char i, j;
+    /* delaySetSpec may be pointer to partial structure so MUST pass by
+     * reference.
+     */
+    if (rates->aggregate.restore_bps != -1 &&
+	(class3->aggregate += rates->aggregate.restore_bps * incr) >
+	rates->aggregate.max_bytes)
+	class3->aggregate = rates->aggregate.max_bytes;
+    /* the following line deliberately uses &, not &&, in an if statement
+     * to avoid conditional execution
+     */
+    if (((network_restore_bytes = rates->network.restore_bps) == -1) &
+	((individual_restore_bytes = rates->individual.restore_bps) == -1))
+	return;
+    individual_restore_bytes *= incr;
+    network_restore_bytes *= incr;
+    if (class3->network_255_used)
+	i = 255;
+    else
+	i = 0;
+    for (;;) {
+	if (i != 255 && class3->network_map[i] == 255)
+	    return;
+	if (individual_restore_bytes != -incr) {
+	    mpos = i << 8;
+	    if (class3->individual_255_used[i / 8] & (1 << (i % 8)))
+		j = 255;
+	    else
+		j = 0;
+	    for (;;) {
+		if (j != 255 && class3->individual_map[i][j] == 255)
+		    break;
+		if (class3->individual[mpos] != rates->individual.max_bytes &&
+		    (class3->individual[mpos] += individual_restore_bytes) >
+		    rates->individual.max_bytes)
+		    class3->individual[mpos] = rates->individual.max_bytes;
+		mpos++;
+		if (j == 255)
+		    mpos -= 256;
+		if (++j == 255)
 		    break;
-		storeAppendPrintf(sentry, "%d:%d ",
-		    delay_data.class3_individual_map[i][j],
-		    delay_data.class3_individual[(i << 8) + j]);
 	    }
-	    storeAppendPrintf(sentry, "\n");
 	}
-    } else {
-	storeAppendPrintf(sentry, "\n\n\tIndividual:\n\tDisabled.\n");
+	if (network_restore_bytes != -incr &&
+	    class3->network[i] != rates->network.max_bytes &&
+	    (class3->network[i] += network_restore_bytes) >
+	    rates->network.max_bytes)
+	    class3->network[i] = rates->network.max_bytes;
+	if (++i == 255)
+	    return;
     }
-    storeAppendPrintf(sentry, "\n");
 }
 
 void
-delayPoolsInit(void)
+delayPoolsUpdate(void *unused)
 {
-    delay_pools_last_update = getCurrentTime();
-    delay_data.class1_aggregate = Config.Delay.class1.aggregate.restore_bps;
-    delay_data.class2_aggregate = Config.Delay.class2.aggregate.restore_bps;
-    delay_data.class2_individual_map[0] = 255;
-    delay_data.class3_aggregate = Config.Delay.class3.aggregate.restore_bps;
-    delay_data.class3_network_map[0] = 255;
-    cachemgrRegister("delay", "Delay Pool Levels", delayPoolStats, 0, 1);
+    int incr = squid_curtime - delay_pools_last_update;
+    unsigned short i;
+    unsigned char class;
+    if (!Config.Delay.pools)
+	return;
     eventAdd("delayPoolsUpdate", delayPoolsUpdate, NULL, 1.0, 1);
+    if (incr < 1)
+	return;
+    delay_pools_last_update = squid_curtime;
+    for (i = 0; i < Config.Delay.pools; i++) {
+	class = Config.Delay.class[i];
+	if (!class)
+	    continue;
+	switch (class) {
+	case 1:
+	    delayUpdateClass1(delay_data[i].class1, Config.Delay.rates[i], incr);
+	    break;
+	case 2:
+	    delayUpdateClass2(delay_data[i].class2, Config.Delay.rates[i], incr);
+	    break;
+	case 3:
+	    delayUpdateClass3(delay_data[i].class3, Config.Delay.rates[i], incr);
+	    break;
+	default:
+	    assert(0);
+	}
+    }
 }
 
 /*
