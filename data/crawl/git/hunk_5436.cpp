 	return 0;
 }
 
+static void truncate_pack(off_t to)
+{
+	if (ftruncate(pack_data->pack_fd, to)
+	 || lseek(pack_data->pack_fd, to, SEEK_SET) != to)
+		die_errno("cannot truncate pack to skip duplicate");
+	pack_size = to;
+}
+
+static void stream_blob(uintmax_t len, unsigned char *sha1out, uintmax_t mark)
+{
+	size_t in_sz = 64 * 1024, out_sz = 64 * 1024;
+	unsigned char *in_buf = xmalloc(in_sz);
+	unsigned char *out_buf = xmalloc(out_sz);
+	struct object_entry *e;
+	unsigned char sha1[20];
+	unsigned long hdrlen;
+	off_t offset;
+	git_SHA_CTX c;
+	z_stream s;
+	int status = Z_OK;
+
+	/* Determine if we should auto-checkpoint. */
+	if ((pack_size + 60 + len) > max_packsize
+		|| (pack_size + 60 + len) < pack_size)
+		cycle_packfile();
+
+	offset = pack_size;
+
+	hdrlen = snprintf((char *)out_buf, out_sz, "blob %" PRIuMAX, len) + 1;
+	if (out_sz <= hdrlen)
+		die("impossibly large object header");
+
+	git_SHA1_Init(&c);
+	git_SHA1_Update(&c, out_buf, hdrlen);
+
+	memset(&s, 0, sizeof(s));
+	deflateInit(&s, pack_compression_level);
+
+	hdrlen = encode_header(OBJ_BLOB, len, out_buf);
+	if (out_sz <= hdrlen)
+		die("impossibly large object header");
+
+	s.next_out = out_buf + hdrlen;
+	s.avail_out = out_sz - hdrlen;
+
+	while (status != Z_STREAM_END) {
+		if (0 < len && !s.avail_in) {
+			size_t cnt = in_sz < len ? in_sz : (size_t)len;
+			size_t n = fread(in_buf, 1, cnt, stdin);
+			if (!n && feof(stdin))
+				die("EOF in data (%" PRIuMAX " bytes remaining)", len);
+
+			git_SHA1_Update(&c, in_buf, n);
+			s.next_in = in_buf;
+			s.avail_in = n;
+			len -= n;
+		}
+
+		status = deflate(&s, len ? 0 : Z_FINISH);
+
+		if (!s.avail_out || status == Z_STREAM_END) {
+			size_t n = s.next_out - out_buf;
+			write_or_die(pack_data->pack_fd, out_buf, n);
+			pack_size += n;
+			s.next_out = out_buf;
+			s.avail_out = out_sz;
+		}
+
+		switch (status) {
+		case Z_OK:
+		case Z_BUF_ERROR:
+		case Z_STREAM_END:
+			continue;
+		default:
+			die("unexpected deflate failure: %d", status);
+		}
+	}
+	deflateEnd(&s);
+	git_SHA1_Final(sha1, &c);
+
+	if (sha1out)
+		hashcpy(sha1out, sha1);
+
+	e = insert_object(sha1);
+
+	if (mark)
+		insert_mark(mark, e);
+
+	if (e->offset) {
+		duplicate_count_by_type[OBJ_BLOB]++;
+		truncate_pack(offset);
+
+	} else if (find_sha1_pack(sha1, packed_git)) {
+		e->type = OBJ_BLOB;
+		e->pack_id = MAX_PACK_ID;
+		e->offset = 1; /* just not zero! */
+		duplicate_count_by_type[OBJ_BLOB]++;
+		truncate_pack(offset);
+
+	} else {
+		e->depth = 0;
+		e->type = OBJ_BLOB;
+		e->pack_id = pack_id;
+		e->offset = offset;
+		object_count++;
+		object_count_by_type[OBJ_BLOB]++;
+	}
+
+	free(in_buf);
+	free(out_buf);
+}
+
 /* All calls must be guarded by find_object() or find_mark() to
  * ensure the 'struct object_entry' passed was written by this
  * process instance.  We unpack the entry by the offset, avoiding
