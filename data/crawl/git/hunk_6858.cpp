 	return index_name;
 }
 
+/*
+ * Update pack header with object_count and compute new SHA1 for pack data
+ * associated to pack_fd, and write that SHA1 at the end.  That new SHA1
+ * is also returned in new_pack_sha1.
+ *
+ * If partial_pack_sha1 is non null, then the SHA1 of the existing pack
+ * (without the header update) is computed and validated against the
+ * one provided in partial_pack_sha1.  The validation is performed at
+ * partial_pack_offset bytes in the pack file.  The SHA1 of the remaining
+ * data (i.e. from partial_pack_offset to the end) is then computed and
+ * returned in partial_pack_sha1.
+ *
+ * Note that new_pack_sha1 is updated last, so both new_pack_sha1 and
+ * partial_pack_sha1 can refer to the same buffer if the caller is not
+ * interested in the resulting SHA1 of pack data above partial_pack_offset.
+ */
 void fixup_pack_header_footer(int pack_fd,
-			 unsigned char *pack_file_sha1,
+			 unsigned char *new_pack_sha1,
 			 const char *pack_name,
-			 uint32_t object_count)
+			 uint32_t object_count,
+			 unsigned char *partial_pack_sha1,
+			 off_t partial_pack_offset)
 {
 	static const int buf_sz = 128 * 1024;
-	SHA_CTX c;
+	SHA_CTX old_sha1_ctx, new_sha1_ctx;
 	struct pack_header hdr;
 	char *buf;
 
+	SHA1_Init(&old_sha1_ctx);
+	SHA1_Init(&new_sha1_ctx);
+
 	if (lseek(pack_fd, 0, SEEK_SET) != 0)
-		die("Failed seeking to start: %s", strerror(errno));
+		die("Failed seeking to start of %s: %s", pack_name, strerror(errno));
 	if (read_in_full(pack_fd, &hdr, sizeof(hdr)) != sizeof(hdr))
 		die("Unable to reread header of %s: %s", pack_name, strerror(errno));
 	if (lseek(pack_fd, 0, SEEK_SET) != 0)
-		die("Failed seeking to start: %s", strerror(errno));
+		die("Failed seeking to start of %s: %s", pack_name, strerror(errno));
+	SHA1_Update(&old_sha1_ctx, &hdr, sizeof(hdr));
 	hdr.hdr_entries = htonl(object_count);
+	SHA1_Update(&new_sha1_ctx, &hdr, sizeof(hdr));
 	write_or_die(pack_fd, &hdr, sizeof(hdr));
-
-	SHA1_Init(&c);
-	SHA1_Update(&c, &hdr, sizeof(hdr));
+	partial_pack_offset -= sizeof(hdr);
 
 	buf = xmalloc(buf_sz);
 	for (;;) {
-		ssize_t n = xread(pack_fd, buf, buf_sz);
+		ssize_t m, n;
+		m = (partial_pack_sha1 && partial_pack_offset < buf_sz) ?
+			partial_pack_offset : buf_sz;
+		n = xread(pack_fd, buf, m);
 		if (!n)
 			break;
 		if (n < 0)
 			die("Failed to checksum %s: %s", pack_name, strerror(errno));
-		SHA1_Update(&c, buf, n);
+		SHA1_Update(&new_sha1_ctx, buf, n);
+
+		if (!partial_pack_sha1)
+			continue;
+
+		SHA1_Update(&old_sha1_ctx, buf, n);
+		partial_pack_offset -= n;
+		if (partial_pack_offset == 0) {
+			unsigned char sha1[20];
+			SHA1_Final(sha1, &old_sha1_ctx);
+			if (hashcmp(sha1, partial_pack_sha1) != 0)
+				die("Unexpected checksum for %s "
+				    "(disk corruption?)", pack_name);
+			/*
+			 * Now let's compute the SHA1 of the remainder of the
+			 * pack, which also means making partial_pack_offset
+			 * big enough not to matter anymore.
+			 */
+			SHA1_Init(&old_sha1_ctx);
+			partial_pack_offset = ~partial_pack_offset;
+			partial_pack_offset -= MSB(partial_pack_offset, 1);
+		}
 	}
 	free(buf);
 
-	SHA1_Final(pack_file_sha1, &c);
-	write_or_die(pack_fd, pack_file_sha1, 20);
+	if (partial_pack_sha1)
+		SHA1_Final(partial_pack_sha1, &old_sha1_ctx);
+	SHA1_Final(new_pack_sha1, &new_sha1_ctx);
+	write_or_die(pack_fd, new_pack_sha1, 20);
 	fsync_or_die(pack_fd, pack_name);
 }
 
