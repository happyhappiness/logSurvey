 #endif /* HAVE_EXT_MALLINFO */
 #endif /* HAVE_MALLINFO */
     storeAppendPrintf(sentry, "Memory accounted for:\n");
+#if !(HAVE_MSTATS && HAVE_GNUMALLOC_H) && HAVE_MALLINFO && HAVE_STRUCT_MALLINFO
+    storeAppendPrintf(sentry, "\tTotal accounted:       %6d KB %3d%%\n",
+	statMemoryAccounted() >> 10, percent(statMemoryAccounted(), t));
+#else
     storeAppendPrintf(sentry, "\tTotal accounted:       %6d KB\n",
 	statMemoryAccounted() >> 10);
-    storeAppendPrintf(sentry, "\tmemPoolAlloc calls: %d\n",
-	mem_pool_alloc_calls);
-    storeAppendPrintf(sentry, "\tmemPoolFree calls: %d\n",
-	mem_pool_free_calls);
-
+#endif
+    {
+	MemPoolGlobalStats mp_stats;
+	memPoolGetGlobalStats(&mp_stats);
+	storeAppendPrintf(sentry, "\tmemPool accounted:     %6d KB %3d%%\n",
+	    mp_stats.TheMeter->alloc.level >> 10, percent(mp_stats.TheMeter->alloc.level, t));
+	storeAppendPrintf(sentry, "\tmemPool unaccounted:   %6d KB %3d%%\n",
+	    (t - mp_stats.TheMeter->alloc.level) >> 10, percent((t - mp_stats.TheMeter->alloc.level), t));
+	storeAppendPrintf(sentry, "\tmemPoolAlloc calls: %9.0f\n",
+	    mp_stats.TheMeter->gb_saved.count);
+	storeAppendPrintf(sentry, "\tmemPoolFree calls:  %9.0f\n",
+	    mp_stats.TheMeter->gb_freed.count);
+    }
     storeAppendPrintf(sentry, "File descriptor usage for %s:\n", appname);
     storeAppendPrintf(sentry, "\tMaximum number of file descriptors:   %4d\n",
 	Squid_MaxFD);
