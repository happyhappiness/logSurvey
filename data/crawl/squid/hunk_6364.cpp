 	    xpercent(f->stat.errCount, f->stat.parsCount),
 	    xpercent(f->stat.repCount, f->stat.seenCount));
     }
-    storeAppendPrintf(e, "Headers Parsed: %d\n", HeaderParsedCount);
+    storeAppendPrintf(e, "Headers Parsed: %d + %d = %d\n",
+	HttpHeaderStats[hoRequest].parsedCount,
+	HttpHeaderStats[hoReply].parsedCount,
+	HttpHeaderStats[0].parsedCount);
     storeAppendPrintf(e, "Hdr Fields Parsed: %d\n", HeaderEntryParsedCount);
 }
