     storeAppendPrintf(sentry, "Memory usage for %s via mallinfo():\n",
                       appname);
 
-    storeAppendPrintf(sentry, "\tTotal space in arena:  %6d KB\n",
-                      mp.arena >> 10);
+    storeAppendPrintf(sentry, "\tTotal space in arena:  %6ld KB\n",
+                      (long)mp.arena >> 10);
 
-    storeAppendPrintf(sentry, "\tOrdinary blocks:       %6d KB %6d blks\n",
-                      mp.uordblks >> 10, mp.ordblks);
+    storeAppendPrintf(sentry, "\tOrdinary blocks:       %6ld KB %6ld blks\n",
+                      (long)mp.uordblks >> 10, (long)mp.ordblks);
 
-    storeAppendPrintf(sentry, "\tSmall blocks:          %6d KB %6d blks\n",
-                      mp.usmblks >> 10, mp.smblks);
+    storeAppendPrintf(sentry, "\tSmall blocks:          %6ld KB %6ld blks\n",
+                      (long)mp.usmblks >> 10, (long)mp.smblks);
 
-    storeAppendPrintf(sentry, "\tHolding blocks:        %6d KB %6d blks\n",
-                      mp.hblkhd >> 10, mp.hblks);
+    storeAppendPrintf(sentry, "\tHolding blocks:        %6ld KB %6ld blks\n",
+                      (long)mp.hblkhd >> 10, (long)mp.hblks);
 
-    storeAppendPrintf(sentry, "\tFree Small blocks:     %6d KB\n",
-                      mp.fsmblks >> 10);
+    storeAppendPrintf(sentry, "\tFree Small blocks:     %6ld KB\n",
+                      (long)mp.fsmblks >> 10);
 
-    storeAppendPrintf(sentry, "\tFree Ordinary blocks:  %6d KB\n",
-                      mp.fordblks >> 10);
+    storeAppendPrintf(sentry, "\tFree Ordinary blocks:  %6ld KB\n",
+                      (long)mp.fordblks >> 10);
 
     t = mp.uordblks + mp.usmblks + mp.hblkhd;
 
