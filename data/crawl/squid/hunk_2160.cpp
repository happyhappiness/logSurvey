 
     storeAppendPrintf(entry, "%s %d\n", name, DelayPools::pools());
 
-    for (i = 0; i < DelayPools::pools(); i++)
+    for (i = 0; i < DelayPools::pools(); ++i)
         DelayPools::delay_data[i].dump (entry, i);
 }
 
