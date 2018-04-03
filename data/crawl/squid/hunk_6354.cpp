     assert(hs && e);
 
     dump_stat = hs;
-    storeAppendPrintf(e, "\n<h3>Header Stats: %s</h3>\n", hs->label);
-    storeAppendPrintf(e, "<h3>Field type distribution</h3>\n");
+    storeAppendPrintf(e, "\nHeader Stats: %s\n", hs->label);
+    storeAppendPrintf(e, "\nField type distribution\n");
     storeAppendPrintf(e, "%2s\t %-20s\t %5s\t %6s\n",
 	"id", "name", "count", "#/header");
     statHistDump(&hs->fieldTypeDistr, e, httpHeaderFieldStatDumper);
-    storeAppendPrintf(e, "<h3>Cache-control directives distribution</h3>\n");
+    storeAppendPrintf(e, "Cache-control directives distribution\n");
     storeAppendPrintf(e, "%2s\t %-20s\t %5s\t %6s\n",
 	"id", "name", "count", "#/cc_field");
     statHistDump(&hs->ccTypeDistr, e, httpHdrCcStatDumper);
-    storeAppendPrintf(e, "<h3>Number of fields per header distribution</h3>\n");
+    storeAppendPrintf(e, "Number of fields per header distribution\n");
     storeAppendPrintf(e, "%2s\t %-5s\t %5s\t %6s\n",
 	"id", "#flds", "count", "%total");
     statHistDump(&hs->hdrUCountDistr, e, httpHeaderFldsPerHdrDumper);
