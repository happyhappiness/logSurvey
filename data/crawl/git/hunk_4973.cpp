 		; /* nothing */
 }
 
+void *xmmap(void *start, size_t length,
+	int prot, int flags, int fd, off_t offset)
+{
+	void *ret = mmap(start, length, prot, flags, fd, offset);
+	if (ret == MAP_FAILED) {
+		if (!length)
+			return NULL;
+		release_pack_memory(length, fd);
+		ret = mmap(start, length, prot, flags, fd, offset);
+		if (ret == MAP_FAILED)
+			die_errno("Out of memory? mmap failed");
+	}
+	return ret;
+}
+
 void close_pack_windows(struct packed_git *p)
 {
 	while (p->windows) {
