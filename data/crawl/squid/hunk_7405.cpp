 	    HttpHdrMiscStr[j],
 	    ReplyHeaderStats.misc[j]);
     for (i = SCC_PUBLIC; i < SCC_ENUM_END; i++)
-	storeAppendPrintf(entry, "{Cache-Control %7.7s: %d}\n",
+	storeAppendPrintf(entry, "{Cache-Control %s: %d}\n",
 	    HttpServerCCStr[i],
 	    ReplyHeaderStats.cc[i]);
     storeAppendPrintf(entry, close_bracket);