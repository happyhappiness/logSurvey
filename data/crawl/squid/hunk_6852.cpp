 }
 
 void
-statAvg5min(StoreEntry *e)
+statAvg5min(StoreEntry * e)
 {
 #if NOT_YET
-	statCountersDump(e);
-	storeAppendPrintf(e, "\n");
+    statCountersDump(e);
+    storeAppendPrintf(e, "\n");
 #endif
-	statAvgDump(e, 5);
+    statAvgDump(e, 5);
 }
 
 void
-statAvg60min(StoreEntry *e)
+statAvg60min(StoreEntry * e)
 {
 #if NOT_YET
-	statCountersDump(e);
-	storeAppendPrintf(e, "\n");
+    statCountersDump(e);
+    storeAppendPrintf(e, "\n");
 #endif
-	statAvgDump(e, 60);
+    statAvgDump(e, 60);
 }
