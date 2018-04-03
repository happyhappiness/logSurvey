 }
 
 void
-statAvg5min(StoreEntry * e)
+statCounters(StoreEntry * e)
 {
-#if NOT_YET
     statCountersDump(e);
-    storeAppendPrintf(e, "\n");
-#endif
+}
+
+void
+statAvg5min(StoreEntry * e)
+{
     statAvgDump(e, 5);
 }
 
 void
 statAvg60min(StoreEntry * e)
 {
-#if NOT_YET
-    statCountersDump(e);
-    storeAppendPrintf(e, "\n");
-#endif
     statAvgDump(e, 60);
 }