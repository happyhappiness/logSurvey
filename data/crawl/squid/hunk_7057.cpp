 {
     SwapDir *s;
     int i;
-    for (i = 0; i<swap.n_configured; i++) {
-	s = swap.swapDirs+i;
+    for (i = 0; i < swap.n_configured; i++) {
+	s = swap.swapDirs + i;
 	storeAppendPrintf(entry, "%s %s %d %d %d\n",
 	    name,
 	    s->path,
-	    s->max_size>>10,
+	    s->max_size >> 10,
 	    s->l1,
 	    s->l2);
     }
