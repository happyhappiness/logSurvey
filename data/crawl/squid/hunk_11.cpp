                       (int) n->last_use_time);
 
         for (x = n->hosts; x; x = x->next)
-            logfilePrintf(lf, " %s", hashKeyStr(&x->hash));
+            logfilePrintf(lf, " %s", hashKeyStr(x));
 
         logfilePrintf(lf, "\n");
 
