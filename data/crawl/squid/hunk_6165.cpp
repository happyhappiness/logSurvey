     sc->delay_id = delay_id;
 }
 
+static void
+delayPoolStatsAg(StoreEntry * sentry, delaySpecSet * rate, int ag)
+{
+    /* note - always pass delaySpecSet's by reference as may be incomplete */
+    if (rate->aggregate.restore_bps == -1) {
+	storeAppendPrintf(sentry, "\tAggregate:\n\t\tDisabled.\n\n");
+	return;
+    }
+    storeAppendPrintf(sentry, "\tAggregate:\n");
+    storeAppendPrintf(sentry, "\t\tMax: %d\n", rate->aggregate.max_bytes);
+    storeAppendPrintf(sentry, "\t\tRestore: %d\n", rate->aggregate.restore_bps);
+    storeAppendPrintf(sentry, "\t\tCurrent: %d\n\n", ag);
+}
+
+static void
+delayPoolStats1(StoreEntry * sentry, unsigned short pool)
+{
+    /* must be a reference only - partially malloc()d struct */
+    delaySpecSet *rate = Config.Delay.rates[pool];
+
+    storeAppendPrintf(sentry, "Pool: %d\n\tClass: 1\n\n", pool + 1);
+    delayPoolStatsAg(sentry, rate, delay_data[pool].class1->aggregate);
+}
+
+static void
+delayPoolStats2(StoreEntry * sentry, unsigned short pool)
+{
+    /* must be a reference only - partially malloc()d struct */
+    delaySpecSet *rate = Config.Delay.rates[pool];
+    class2DelayPool *class2 = delay_data[pool].class2;
+    unsigned char shown = 0, i;
+
+    storeAppendPrintf(sentry, "Pool: %d\n\tClass: 2\n\n", pool + 1);
+    delayPoolStatsAg(sentry, rate, class2->aggregate);
+    if (rate->individual.restore_bps == -1) {
+	storeAppendPrintf(sentry, "\tIndividual:\n\t\tDisabled.\n\n");
+	return;
+    }
+    storeAppendPrintf(sentry, "\tIndividual:\n");
+    storeAppendPrintf(sentry, "\t\tMax: %d\n", rate->individual.max_bytes);
+    storeAppendPrintf(sentry, "\t\tRate: %d\n", rate->individual.restore_bps);
+    storeAppendPrintf(sentry, "\t\tCurrent: ");
+    for (i = 0;; i++) {
+	if (class2->individual_map[i] == 255)
+	    break;
+	storeAppendPrintf(sentry, "%d:%d ", class2->individual_map[i],
+	    class2->individual[i]);
+	shown = 1;
+    }
+    if (class2->individual_255_used) {
+	storeAppendPrintf(sentry, "%d:%d ", 255, class2->individual[255]);
+	shown = 1;
+    }
+    if (!shown)
+	storeAppendPrintf(sentry, "Not used yet.");
+    storeAppendPrintf(sentry, "\n\n");
+}
+
+static void
+delayPoolStats3(StoreEntry * sentry, unsigned short pool)
+{
+    /* fully malloc()d struct in this case only */
+    delaySpecSet *rate = Config.Delay.rates[pool];
+    class3DelayPool *class3 = delay_data[pool].class3;
+    unsigned char shown = 0, i, j;
+
+    storeAppendPrintf(sentry, "Pool: %d\n\tClass: 3\n\n", pool + 1);
+    delayPoolStatsAg(sentry, rate, class3->aggregate);
+    if (rate->network.restore_bps == -1) {
+	storeAppendPrintf(sentry, "\tNetwork:\n\t\tDisabled.");
+    } else {
+	storeAppendPrintf(sentry, "\tNetwork:\n");
+	storeAppendPrintf(sentry, "\t\tMax: %d\n", rate->network.max_bytes);
+	storeAppendPrintf(sentry, "\t\tRate: %d\n", rate->network.restore_bps);
+	storeAppendPrintf(sentry, "\t\tCurrent: ");
+	for (i = 0;; i++) {
+	    if (class3->network_map[i] == 255)
+		break;
+	    storeAppendPrintf(sentry, "%d:%d ", class3->network_map[i],
+		class3->network[i]);
+	    shown = 1;
+	}
+	if (class3->network_255_used) {
+	    storeAppendPrintf(sentry, "%d:%d ", 255, class3->network[255]);
+	    shown = 1;
+	}
+	if (!shown)
+	    storeAppendPrintf(sentry, "Not used yet.");
+    }
+    storeAppendPrintf(sentry, "\n\n");
+    shown = 0;
+    if (rate->individual.restore_bps == -1) {
+	storeAppendPrintf(sentry, "\tIndividual:\n\t\tDisabled.\n\n");
+	return;
+    }
+    storeAppendPrintf(sentry, "\tIndividual:\n");
+    storeAppendPrintf(sentry, "\t\tMax: %d\n", rate->individual.max_bytes);
+    storeAppendPrintf(sentry, "\t\tRate: %d\n", rate->individual.restore_bps);
+    for (i = 0;; i++) {
+	if (class3->network_map[i] == 255)
+	    break;
+	storeAppendPrintf(sentry, "\t\tCurrent [Network %d]: ", class3->network_map[i]);
+	shown = 1;
+	for (j = 0;; j++) {
+	    if (class3->individual_map[i][j] == 255)
+		break;
+	    storeAppendPrintf(sentry, "%d:%d ", class3->individual_map[i][j],
+		class3->individual[(i << 8) | j]);
+	}
+	if (class3->individual_255_used[i / 8] & (1 << (i % 8))) {
+	    storeAppendPrintf(sentry, "%d:%d ", 255, class3->individual[(i << 8) | 255]);
+	}
+	storeAppendPrintf(sentry, "\n");
+    }
+    if (class3->network_255_used) {
+	storeAppendPrintf(sentry, "\t\tCurrent [Network 255]: ");
+	shown = 1;
+	for (j = 0;; j++) {
+	    if (class3->individual_map[255][j] == 255)
+		break;
+	    storeAppendPrintf(sentry, "%d:%d ", class3->individual_map[255][j],
+		class3->individual[(255 << 8) | j]);
+	}
+	if (class3->individual_255_used[255 / 8] & (1 << (255 % 8))) {
+	    storeAppendPrintf(sentry, "%d:%d ", 255, class3->individual[(255 << 8) | 255]);
+	}
+	storeAppendPrintf(sentry, "\n");
+    }
+    if (!shown)
+	storeAppendPrintf(sentry, "\t\tCurrent [All networks]: Not used yet.\n");
+    storeAppendPrintf(sentry, "\n");
+}
+
+static void
+delayPoolStats(StoreEntry * sentry)
+{
+    unsigned short i;
+
+    storeAppendPrintf(sentry, "Delay pools configured: %d\n\n", Config.Delay.pools);
+    for (i = 0; i < Config.Delay.pools; i++) {
+	switch (Config.Delay.class[i]) {
+	case 0:
+	    storeAppendPrintf(sentry, "Pool: %d\n\tClass: 0\n\n", i + 1);
+	    storeAppendPrintf(sentry, "\tMisconfigured pool.\n\n");
+	    break;
+	case 1:
+	    delayPoolStats1(sentry, i);
+	    break;
+	case 2:
+	    delayPoolStats2(sentry, i);
+	    break;
+	case 3:
+	    delayPoolStats3(sentry, i);
+	    break;
+	default:
+	    assert(0);
+	}
+    }
+}
+
 #endif
