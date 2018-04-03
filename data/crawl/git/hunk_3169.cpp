 			return NULL;
 		release_pack_memory(length);
 		ret = mmap(start, length, prot, flags, fd, offset);
-		if (ret == MAP_FAILED)
-			die_errno("Out of memory? mmap failed");
 	}
 	return ret;
 }
 
+void *xmmap(void *start, size_t length,
+	int prot, int flags, int fd, off_t offset)
+{
+	void *ret = xmmap_gently(start, length, prot, flags, fd, offset);
+	if (ret == MAP_FAILED)
+		die_errno("Out of memory? mmap failed");
+	return ret;
+}
+
 void close_pack_windows(struct packed_git *p)
 {
 	while (p->windows) {