 
     storeAppendPrintf(sentry, "{Internal Data Structures:}\n");
     storeAppendPrintf(sentry, "{\t%6d StoreEntries}\n",
-	meta_data.store_entries);
+	memInUse(MEM_STOREENTRY));
     storeAppendPrintf(sentry, "{\t%6d StoreEntries with MemObjects}\n",
-	meta_data.mem_obj_count);
+	memInUse(MEM_MEMOBJECT));
     storeAppendPrintf(sentry, "{\t%6d StoreEntries with MemObject Data}\n",
-	meta_data.mem_data_count);
+	memInUse(MEM_MEM_HDR));
     storeAppendPrintf(sentry, "{\t%6d Hot Object Cache Items}\n",
 	meta_data.hot_vm);
 
-    storeAppendPrintf(sentry, "{Accounted Memory Usage:}\n");
-    storeAppendPrintf(sentry, "{\t%-25.25s %7d x %4d bytes = %6d KB}\n",
-	"StoreEntry",
-	meta_data.store_entries,
-	(int) sizeof(StoreEntry),
-	(int) (meta_data.store_entries * sizeof(StoreEntry) >> 10));
-
     storeAppendPrintf(sentry, "{\t%-25.25s                      = %6d KB}\n",
 	"StoreEntry Keys",
 	meta_data.store_keys >> 10);
