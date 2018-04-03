     const int valid_id = id >= 0 && id < HDR_ENUM_END;
     const char *name = valid_id ? Headers[id].name : "INVALID";
     if (count || valid_id)
-	storeAppendPrintf(sentry, "%2d\t %-20s\t %5d\t %6.2lf\n",
+	storeAppendPrintf(sentry, "%2d\t %-20s\t %5d\t %6.2f\n",
 	    id, name, count, xdiv(count, HeaderParsedCount));
 }
 
