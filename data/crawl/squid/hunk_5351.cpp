     int i;
 
     if (!DelayPools::pools()) {
-	storeAppendPrintf(entry, "%s 0\n", name);
-	return;
+        storeAppendPrintf(entry, "%s 0\n", name);
+        return;
     }
+
     storeAppendPrintf(entry, "%s %d\n", name, DelayPools::pools());
+
     for (i = 0; i < DelayPools::pools(); i++)
-	DelayPools::delay_data[i].dump (entry, i);
+        DelayPools::delay_data[i].dump (entry, i);
 }
+
 #endif
