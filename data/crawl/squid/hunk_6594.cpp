     const char *name = valid_id ? Headers[id].name : "INVALID";
     if (count || valid_id)
 	storeAppendPrintf(sentry, "%2d\t %-20s\t %5d\t %6.2f\n",
-	    id, name, count, xdiv(count, HeaderParsedCount));
+	    id, name, count, xdiv(count, NonEmptyHeaderDestroyedCount));
 }
 
 static void
 httpHeaderFldsPerHdrDumper(StoreEntry * sentry, int idx, double val, double size, int count)
 {
     if (count)
 	storeAppendPrintf(sentry, "%2d\t %5d\t %5d\t %6.2f\n",
-	    idx, ((int) (val + size)), count, xpercent(count, HeaderParsedCount));
+	    idx, (int)val, count,
+	    xpercent(count, HeaderDestroyedCount));
 }
 
 
