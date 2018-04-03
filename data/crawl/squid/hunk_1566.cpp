         CBDataDumper::operator()(x);
         storeAppendPrintf(where, "\n");
         storeAppendPrintf(where, "Action\tFile\tLine\n");
-        std::for_each (x.calls.begin(), x.calls.end(), callDumper);
+        for_each (x.calls,callDumper);
         storeAppendPrintf(where, "\n");
     }
 
