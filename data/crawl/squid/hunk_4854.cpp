     debug(20, 1) ("ERROR: Be sure to have set cache_replacement_policy\n");
     debug(20, 1) ("ERROR:   and memory_replacement_policy in squid.conf!\n");
     fatalf("ERROR: Unknown policy %s\n", settings->type);
-    return NULL;		/* NOTREACHED */
+    return NULL;                /* NOTREACHED */
 }
 
 #if 0
