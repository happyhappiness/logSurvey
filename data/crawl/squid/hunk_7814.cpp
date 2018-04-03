 	    (int) entry->refcount,
 	    mem_describe(entry),
 	    stat_describe(entry));
-	storeAppend(sentry, tempbuf, strlen(tempbuf));
     }
-    storeAppend(sentry, close_bracket, strlen(close_bracket));
+    storeAppendPrintf(sentry, "}\n");
 }
 
 
