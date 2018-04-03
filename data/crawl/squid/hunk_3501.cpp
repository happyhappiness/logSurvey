     fd_bytes(ll->fd, s, FD_WRITE);
 
     if (s == len)
-	return;
+        return;
 
     if (!lf->flags.fatal)
-	return;
+        return;
 
     fatalf("logfileWrite (stdio): %s: %s\n", lf->path, xstrerror());
 }
