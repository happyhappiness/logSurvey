 	return 0;
 }
 
+/* Finalize a file on disk, and close it. */
+static void close_sha1_file(int fd)
+{
+	/* For safe-mode, we could fsync_or_die(fd, "sha1 file") here */
+	fchmod(fd, 0444);
+	if (close(fd) != 0)
+		die("unable to write sha1 file");
+}
+
 static int write_loose_object(const unsigned char *sha1, char *hdr, int hdrlen,
 			      void *buf, unsigned long len, time_t mtime)
 {
