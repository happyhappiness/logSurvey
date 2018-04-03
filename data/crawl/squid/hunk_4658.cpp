 SwapDir::optionReadOnlyDump(StoreEntry * e) const
 {
     if (flags.read_only)
-        storeAppendPrintf(e, " read-only");
+        storeAppendPrintf(e, " no-store");
 }
 
 bool
