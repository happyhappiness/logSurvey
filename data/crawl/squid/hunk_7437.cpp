 	ReplyHeaderStats.ctype);
     storeAppendPrintf(entry, "{Content-Length: %d}\n",
 	ReplyHeaderStats.clen);
+    storeAppendPrintf(entry, "{Cache-Control Private: %d}\n",
+	ReplyHeaderStats.cc.private);
+    storeAppendPrintf(entry, "{Cache-Control Cachable: %d}\n",
+	ReplyHeaderStats.cc.cachable);
+    storeAppendPrintf(entry, "{Cache-Control Nocache: %d}\n",
+	ReplyHeaderStats.cc.nocache);
     storeAppendPrintf(entry, close_bracket);
 }
