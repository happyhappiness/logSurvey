     storeAppendPrintf(sentry, close_bracket);
 }
 
-static int memoryAccounted()
+static int
+memoryAccounted()
 {
     return (int)
 	meta_data.store_entries * sizeof(StoreEntry) +
