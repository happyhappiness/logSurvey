 	storeAppendPrintf(entry, " %s", args->key);
 	args = args->next;
     }
+    storeAppendPrintf(entry, "\n");
 }
 
 