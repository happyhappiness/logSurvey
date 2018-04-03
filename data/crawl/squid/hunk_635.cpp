     storeAppendPrintf(e, "%2s\t %-25s\t %5s\t %6s\t %6s\n",
                       "id", "name", "#alive", "%err", "%repeat");
 
+#if 0
     for (ht = (http_hdr_type)0; ht < HDR_ENUM_END; ++ht) {
         HttpHeaderFieldInfo *f = Headers + ht;
         storeAppendPrintf(e, "%2d\t %-25s\t %5d\t %6.3f\t %6.3f\n",
                           f->id, f->name.termedBuf(), f->stat.aliveCount,
                           xpercent(f->stat.errCount, f->stat.parsCount),
                           xpercent(f->stat.repCount, f->stat.seenCount));
     }
+#endif
+    // scan heaaderTable and output
+    for (int j = 0; headerTable[j].name != nullptr; ++j) {
+        auto stats = headerStatsTable[j];
+        storeAppendPrintf(e, "%2d\t %-25s\t %5d\t %6.3f\t %6.3f\n",
+            headerTable[j].id, headerTable[j].name, stats.aliveCount,
+            xpercent(stats.errCount, stats.parsCount),
+            xpercent(stats.repCount, stats.seenCount));
+    }
 
     storeAppendPrintf(e, "Headers Parsed: %d + %d = %d\n",
                       HttpHeaderStats[hoRequest].parsedCount,