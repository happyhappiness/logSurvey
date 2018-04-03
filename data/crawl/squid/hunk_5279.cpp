 {
     CBDataHistoryDumper(StoreEntry *anEntry):CBDataDumper(anEntry),where(anEntry), callDumper(anEntry){}
 
-    void operator()(_cbdata const &x)
+    void operator()(cbdata const &x)
     {
         CBDataDumper::operator()(x);
         storeAppendPrintf(where, "\n");
