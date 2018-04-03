 	    xpercent(f->stat.errCount, f->stat.parsCount),
 	    xpercent(f->stat.repCount, f->stat.parsCount));
     }
-    storeAppendPrintf(e, "\nSurvived/Parsed ratio: %d/%d (%.2f%%)\n", 
-	HeaderEntrySurvivedCount, HeaderEntryParsedCount,
-	xpercent(HeaderEntrySurvivedCount, HeaderEntryParsedCount));
+    storeAppendPrintf(e, "Headers Parsed: %d\n", HeaderParsedCount);
+    storeAppendPrintf(e, "Hdr Fields Parsed: %d\n", HeaderEntryParsedCount);
 }
