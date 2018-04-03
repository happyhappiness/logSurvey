 static void
 memStats(StoreEntry * sentry)
 {
-    mem_type t;
     storeBuffer(sentry);
-    storeAppendPrintf(sentry, "%-20s\t %s\t %s\t %s\t %s\t %s\t %s\t %s\t %s\t %s\t %s\n",
-	"Pool",	"Obj Size",
-	"Capacity (#)", "Capacity (KB)", "Used (KB)", "HWater (KB)", 
-	"Util (%)", "Grow Count",
-	"Malloc (#)", "Malloc (KB)", "MHWater (KB)");
-    for (t = MEM_NONE + 1; t < MEM_MAX; t++) {
-	const MemPool *pool = MemPools[t];
-	if (!memPoolWasNeverUsed(pool))
-	    memPoolReport(pool, sentry);
-    }
-    storeAppendPrintf(sentry, "\n");
+    memReport(sentry);
     /* memStringStats(sentry); */
-    memReportTotals(sentry);
     storeBufferFlush(sentry);
 }
 
