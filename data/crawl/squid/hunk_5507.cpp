     }
     storeAppendPrintf(entry, "%s %d\n", name, cfg.pools);
     for (i = 0; i < cfg.pools; i++) {
-	storeAppendPrintf(entry, "delay_class %d %d\n", i + 1, cfg.class[i]);
+	storeAppendPrintf(entry, "delay_class %d %d\n", i + 1, cfg.delay_class[i]);
 	snprintf(nom, 32, "delay_access %d", i + 1);
 	dump_acl_access(entry, nom, cfg.access[i]);
-	if (cfg.class[i] >= 1)
+	if (cfg.delay_class[i] >= 1)
 	    storeAppendPrintf(entry, "delay_parameters %d %d/%d", i + 1,
 		cfg.rates[i]->aggregate.restore_bps,
 		cfg.rates[i]->aggregate.max_bytes);
-	if (cfg.class[i] >= 3)
+	if (cfg.delay_class[i] >= 3)
 	    storeAppendPrintf(entry, " %d/%d",
 		cfg.rates[i]->network.restore_bps,
 		cfg.rates[i]->network.max_bytes);
-	if (cfg.class[i] >= 2)
+	if (cfg.delay_class[i] >= 2)
 	    storeAppendPrintf(entry, " %d/%d",
 		cfg.rates[i]->individual.restore_bps,
 		cfg.rates[i]->individual.max_bytes);
-	if (cfg.class[i] >= 1)
+	if (cfg.delay_class[i] >= 1)
 	    storeAppendPrintf(entry, "\n");
     }
 }
