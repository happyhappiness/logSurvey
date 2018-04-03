     mp_stats.items_idle = mp_total.tot_items_idle;
     mp_stats.overhead = mp_total.tot_overhead;
 
-    PoolReport(&mp_stats, mp_total.TheMeter, e);
+    PoolReport(&mp_stats, mp_total.TheMeter, stream);
 
     /* Cumulative */
-    storeAppendPrintf(e, "Cumulative allocated volume: %s\n", double_to_str(buf, 64, mp_total.TheMeter->gb_saved.bytes));
+    stream << "Cumulative allocated volume: "<< double_to_str(buf, 64, mp_total.TheMeter->gb_saved.bytes) << "\n";
     /* overhead */
-    storeAppendPrintf(e, "Current overhead: %d bytes (%.3f%%)\n",
-                      mp_total.tot_overhead, xpercent(mp_total.tot_overhead, mp_total.TheMeter->inuse.level));
+    stream << "Current overhead: " << mp_total.tot_overhead << " bytes (" <<
+    std::setprecision(3) << xpercent(mp_total.tot_overhead, mp_total.TheMeter->inuse.level) << "%%)\n";
     /* limits */
-    storeAppendPrintf(e, "Idle pool limit: %.2f MB\n", toMB(mp_total.mem_idle_limit));
+    stream << "Idle pool limit: " << std::setprecision(2) << toMB(mp_total.mem_idle_limit) << " MB\n";
     /* limits */
-    storeAppendPrintf(e, "Total Pools created: %d\n", mp_total.tot_pools_alloc);
-    storeAppendPrintf(e, "Pools ever used:     %d (shown above)\n", mp_total.tot_pools_alloc - not_used);
-    storeAppendPrintf(e, "Currently in use:    %d\n", mp_total.tot_pools_inuse);
+    stream << "Total Pools created: " << mp_total.tot_pools_alloc << "\n";
+    stream << "Pools ever used:     " << mp_total.tot_pools_alloc - not_used << " (shown above)\n";
+    stream << "Currently in use:    " << mp_total.tot_pools_inuse << "\n";
 }
