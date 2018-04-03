      */
     fd = open(buf, r->offset, 0600);
     if (fd < 0) {
-	fprintf(stderr, "%d %s: ", (int) mypid, buf);
-	perror("open");
+	DEBUG(1) {
+	    fprintf(stderr, "%d %s: ", (int) mypid, buf);
+	    perror("open");
+	}
 	return -errno;
     }
     fs = xcalloc(1, sizeof(*fs));
     fs->id = r->id;
     fs->key = &fs->id;		/* gack */
     fs->fd = fd;
     hash_join(hash, (hash_link *) fs);
-#if STDERR_DEBUG
-    fprintf(stderr, "%d OPEN  id %d, FD %d, fs %p\n",
+    DEBUG(2)
+	fprintf(stderr, "%d OPEN  id %d, FD %d, fs %p\n",
 	(int) mypid,
 	fs->id,
 	fs->fd,
 	fs);
-#endif
     return fd;
 }
 
