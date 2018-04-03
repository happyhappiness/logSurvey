     storeAppendPrintf(e,
                       "%s persistent connection counts:\n"
                       "\n"
-                      "\treq/\n"
-                      "\tconn      count\n"
-                      "\t----  ---------\n",
+                      "\t Requests\t Connection Count\n"
+                      "\t --------\t ----------------\n",
                       descr);
 
     for (int i = 0; i < PCONN_HIST_SZ; ++i) {
         if (hist[i] == 0)
             continue;
 
-        storeAppendPrintf(e, "\t%4d  %9d\n", i, hist[i]);
+        storeAppendPrintf(e, "\t%d\t%d\n", i, hist[i]);
     }
 }
 
