 	    mem_describe(entry),
 	    stat_describe(entry));
     }
-    storeAppendPrintf(sentry, "}\n");
+    storeAppendPrintf(sentry, close_bracket);
 }
 
 
