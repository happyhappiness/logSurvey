     storeAppendPrintf(e, "%2s\t %-5s\t %5s\t %6s\n",
                       "id", "#flds", "count", "%total");
     hs->hdrUCountDistr.dump(e, httpHeaderFldsPerHdrDumper);
+    storeAppendPrintf(e, "\n");
     dump_stat = NULL;
 }
 
