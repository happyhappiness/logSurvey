     fs = (file_state *) hash_lookup(hash, &r->id);
     if (NULL == fs) {
 	errno = EBADF;
-	fprintf(stderr, "%d CLOSE id %d: ", (int) mypid, r->id);
-	perror("do_close");
-	return -EBADF;
+	DEBUG(1) {
+	    fprintf(stderr, "%d CLOSE id %d: ", (int) mypid, r->id);
+	    perror("do_close");
+	}
+	return -errno;
     }
     fd = fs->fd;
     hash_remove_link(hash, (hash_link *) fs);
-#if STDERR_DEBUG
-    fprintf(stderr, "%d CLOSE id %d, FD %d, fs %p\n",
+    DEBUG(2)
+	fprintf(stderr, "%d CLOSE id %d, FD %d, fs %p\n",
 	(int) mypid,
 	r->id,
 	fs->fd,
 	fs);
-#endif
     xfree(fs);
     return close(fd);
 }
