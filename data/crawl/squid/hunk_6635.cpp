 	storeAppendPrintf(entry, "%21.21s: %d\n",
 	    HttpHdrMiscStr[j],
 	    ReplyHeaderStats.misc[j]);
-    for (i = SCC_PUBLIC; i < SCC_ENUM_END; i++)
+    for (i = CC_PUBLIC; i < CC_ENUM_END; i++)
 	storeAppendPrintf(entry, "Cache-Control %s: %d\n",
 	    HttpServerCCStr[i],
 	    ReplyHeaderStats.cc[i]);
