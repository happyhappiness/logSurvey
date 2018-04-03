     MemPools[type] = memPoolCreate(name, size);
 }
 
+static void
+memStringStats(StoreEntry * sentry)
+{
+    const char *pfmt = "%-20s\t %d\t %d\n";
+    int i;
+    int pooled_count = 0;
+    size_t pooled_volume = 0;
+    /* heading */
+    storeAppendPrintf(sentry, 
+	"String Pool\t Impact\t\t\n"
+	" \t (%%strings)\t (%%volume)\n");
+    /* table body */
+    for (i = 0; i < mem_str_pool_count; i++) {
+	const MemPool *pool = StrPools[i].pool;
+	const int plevel = pool->meter.inuse.level;
+  	storeAppendPrintf(sentry, pfmt,
+	    pool->label,
+	    xpercentInt(plevel, StrCountMeter.level),
+	    xpercentInt(plevel*pool->obj_size, StrVolumeMeter.level));
+	pooled_count += plevel;
+	pooled_volume += plevel*pool->obj_size;
+    }
+    /* malloc strings */
+    storeAppendPrintf(sentry, pfmt,
+	"Other Strings",
+	xpercentInt(StrCountMeter.level-pooled_count, StrCountMeter.level),
+	xpercentInt(StrVolumeMeter.level-pooled_volume, StrVolumeMeter.level));
+}
+
 static void
 memStats(StoreEntry * sentry)
 {
     storeBuffer(sentry);
     memReport(sentry);
-    /* memStringStats(sentry); */
+    memStringStats(sentry);
     storeBufferFlush(sentry);
 }
 
 
-
 /*
- * PUBLIC ROUTINES
+ * public routines
  */
 
+
 /* find appropriate pool and use it (pools always init buffer with 0s) */
 void *
 memAllocate(mem_type type)
