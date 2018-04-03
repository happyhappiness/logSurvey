 void
 httpReplyHeaderStats(StoreEntry * entry)
 {
+    http_server_cc_t i;
     storeAppendPrintf(entry, open_bracket);
-    storeAppendPrintf(entry, "{HTTP Reply Headers}\n");
-    storeAppendPrintf(entry, "{Headers parsed: %d}\n",
+    storeAppendPrintf(entry, "{HTTP Reply Headers:}\n");
+    storeAppendPrintf(entry, "{       Headers parsed: %d}\n",
 	ReplyHeaderStats.parsed);
-    storeAppendPrintf(entry, "{          Date: %d}\n",
+    storeAppendPrintf(entry, "{                 Date: %d}\n",
 	ReplyHeaderStats.date);
-    storeAppendPrintf(entry, "{ Last-Modified: %d}\n",
+    storeAppendPrintf(entry, "{        Last-Modified: %d}\n",
 	ReplyHeaderStats.lm);
-    storeAppendPrintf(entry, "{       Expires: %d}\n",
+    storeAppendPrintf(entry, "{              Expires: %d}\n",
 	ReplyHeaderStats.exp);
-    storeAppendPrintf(entry, "{  Content-Type: %d}\n",
+    storeAppendPrintf(entry, "{         Content-Type: %d}\n",
 	ReplyHeaderStats.ctype);
-    storeAppendPrintf(entry, "{Content-Length: %d}\n",
+    storeAppendPrintf(entry, "{       Content-Length: %d}\n",
 	ReplyHeaderStats.clen);
-    storeAppendPrintf(entry, "{Cache-Control Private: %d}\n",
-	ReplyHeaderStats.cc.private);
-    storeAppendPrintf(entry, "{Cache-Control Cachable: %d}\n",
-	ReplyHeaderStats.cc.cachable);
-    storeAppendPrintf(entry, "{Cache-Control Nocache: %d}\n",
-	ReplyHeaderStats.cc.nocache);
+    for (i = 0; i < SCC_ENUM_END; i++)
+	storeAppendPrintf(entry, "{Cache-Control %7.7s: %d}\n",
+	    HttpServerCCStr[i],
+	    ReplyHeaderStats.cc[i]);
     storeAppendPrintf(entry, close_bracket);
 }
