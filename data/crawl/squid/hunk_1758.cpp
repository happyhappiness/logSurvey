 
     for (i = 1; i < HttpHeaderStatCount; ++i) {
         httpHeaderStatDump(HttpHeaderStats + i, e);
-        storeAppendPrintf(e, "%s\n", "<br>");
     }
 
     /* field stats for all messages */