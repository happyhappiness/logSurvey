     Must(entry != NULL);
 
 #if XMALLOC_STATISTICS
-    if (UsingSmp() && IamWorkerProcess())
+    if (UsingSmp())
         storeAppendPrintf(entry, "by kid%d {\n", KidIdentifier);
     DumpMallocStatistics(entry);
-    if (UsingSmp() && IamWorkerProcess())
+    if (UsingSmp())
         storeAppendPrintf(entry, "} by kid%d\n\n", KidIdentifier);
 #endif
     if (IamPrimaryProcess())
