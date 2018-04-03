     http_hdr_type ht;
     assert(e);
 
-    /* fix this (including summing for totals) for req hdrs @?@ */
-    for (i = 0; i < 1 /*HttpHeaderStatCount */ ; i++) {
+    for (i = 1; i < HttpHeaderStatCount; i++) {
 	httpHeaderStatDump(HttpHeaderStats + i, e);
 	storeAppendPrintf(e, "%s\n", "<br>");
     }
-    storeAppendPrintf(e, "%s\n", "<hr size=1 noshade>");
     /* field stats */
     storeAppendPrintf(e, "<h3>Http Fields Stats (replies and requests)</h3>\n");
     storeAppendPrintf(e, "%2s\t %-20s\t %5s\t %6s\t %6s\n",
