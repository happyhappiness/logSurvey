 
 #endif
 
-    storeAppendPrintf(sentry, "\tMaximum Resident Size: %d KB\n",
-                      rusage_maxrss(&rusage));
+    storeAppendPrintf(sentry, "\tMaximum Resident Size: %ld KB\n",
+                      (long)rusage_maxrss(&rusage));
 
-    storeAppendPrintf(sentry, "\tPage faults with physical i/o: %d\n",
-                      rusage_pagefaults(&rusage));
+    storeAppendPrintf(sentry, "\tPage faults with physical i/o: %ld\n",
+                      (long)rusage_pagefaults(&rusage));
 
 #if HAVE_MSTATS && HAVE_GNUMALLOC_H
 
     ms = mstats();
 
     storeAppendPrintf(sentry, "Memory usage for %s via mstats():\n",APP_SHORTNAME);
 
-    storeAppendPrintf(sentry, "\tTotal space in arena:  %6d KB\n",
-                      ms.bytes_total >> 10);
+    storeAppendPrintf(sentry, "\tTotal space in arena:  %6ld KB\n",
+                      (long)(ms.bytes_total >> 10));
 
-    storeAppendPrintf(sentry, "\tTotal free:            %6d KB %d%%\n",
-                      ms.bytes_free >> 10, Math::intPercent(ms.bytes_free, ms.bytes_total));
+    storeAppendPrintf(sentry, "\tTotal free:            %6ld KB %d%%\n",
+                     (long)(ms.bytes_free >> 10), Math::intPercent(ms.bytes_free, ms.bytes_total));
 
 #elif HAVE_MALLINFO && HAVE_STRUCT_MALLINFO
 
