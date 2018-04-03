     storeAppendPrintf(e, "<h3>Cache-control directives distribution</h3>\n");
     storeAppendPrintf(e, "%2s\t %-20s\t %5s\t %6s\n",
 	"id", "name", "count", "#/cc_field");
-    statHistDump(&hs->ccTypeDistr, e, httpHeaderCCStatDumper);
+    statHistDump(&hs->ccTypeDistr, e, httpHdrCcStatDumper);
     storeAppendPrintf(e, "<h3>Number of fields per header distribution (init size: %d)</h3>\n",
 	INIT_FIELDS_PER_HEADER);
     storeAppendPrintf(e, "%2s\t %-5s\t %5s\t %6s\n",
