     int i;
     for (i = 0; i < swap.n_configured; i++) {
 	s = swap.swapDirs + i;
-	storeAppendPrintf(entry, "%s %s %d %d %d\n",
-	    name,
-	    s->path,
-	    s->max_size >> 10,
-	    s->l1,
-	    s->l2);
+	switch (s->type) {
+	case SWAPDIR_UFS:
+	    storeUfsDirDump(entry, name, s);
+	    break;
+	default:
+	    debug(0, 0) ("dump_cachedir doesn't know about type %d\n",
+		(int) s->type);
+	    break;
+	}
     }
 }
 
