 	    (secs ? p->transferbyte / secs : 0),
 	    p->refcount,
 	    p->transferbyte);
-	storeAppend(sentry, tempbuf, strlen(tempbuf));
     }
 
-    storeAppend(sentry, close_bracket, strlen(close_bracket));
+    storeAppendPrintf(sentry, "}\n");
 }
 
 
