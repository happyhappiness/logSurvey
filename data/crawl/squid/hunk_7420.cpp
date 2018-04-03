 httpReplyHeaderStats(StoreEntry * entry)
 {
     http_server_cc_t i;
+    http_hdr_misc_t j;
     storeAppendPrintf(entry, open_bracket);
     storeAppendPrintf(entry, "{HTTP Reply Headers:}\n");
     storeAppendPrintf(entry, "{       Headers parsed: %d}\n",
 	ReplyHeaderStats.parsed);
-    storeAppendPrintf(entry, "{                 Date: %d}\n",
-	ReplyHeaderStats.date);
-    storeAppendPrintf(entry, "{        Last-Modified: %d}\n",
-	ReplyHeaderStats.lm);
-    storeAppendPrintf(entry, "{              Expires: %d}\n",
-	ReplyHeaderStats.exp);
-    storeAppendPrintf(entry, "{         Content-Type: %d}\n",
-	ReplyHeaderStats.ctype);
-    storeAppendPrintf(entry, "{       Content-Length: %d}\n",
-	ReplyHeaderStats.clen);
+    for (j = HDR_AGE; j < HDR_MISC_END; j++)
+	storeAppendPrintf(entry, "{%21.21s: %d}\n",
+	    HttpHdrMiscStr[j],
+	    ReplyHeaderStats.misc[j]);
     for (i = SCC_PUBLIC; i < SCC_ENUM_END; i++)
 	storeAppendPrintf(entry, "{Cache-Control %7.7s: %d}\n",
 	    HttpServerCCStr[i],