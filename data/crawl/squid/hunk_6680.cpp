 {
     if (count)
 	storeAppendPrintf(sentry, "%2d\t %5d\t %5d\t %6.2lf\n",
-	    idx, ((int)(val+size)), count, xpercent(count, HeaderEntryParsedCount));
+	    idx, ((int) (val + size)), count, xpercent(count, HeaderEntryParsedCount));
 }
 
 
 static void
-httpHeaderStatDump(const HttpHeaderStat *hs, StoreEntry *e)
+httpHeaderStatDump(const HttpHeaderStat * hs, StoreEntry * e)
 {
     assert(hs && e);
 
