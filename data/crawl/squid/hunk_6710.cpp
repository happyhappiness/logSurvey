 httpHeaderFldsPerHdrDumper(StoreEntry * sentry, int idx, double val, double size, int count)
 {
     if (count)
-	storeAppendPrintf(sentry, "%2d\t %5d\t %5d\t %6.2f\n",
+	storeAppendPrintf(sentry, "%2d\t %5d\t %5d\t %6.2lf\n",
 	    idx, ((int)(val+size)), count, xpercent(count, HeaderEntryParsedCount));
 }
 
