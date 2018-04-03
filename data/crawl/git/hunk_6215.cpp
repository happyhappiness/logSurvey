 	s->cnt_data = NULL;
 }
 
-static void prep_temp_blob(struct diff_tempfile *temp,
+static void prep_temp_blob(const char *path, struct diff_tempfile *temp,
 			   void *blob,
 			   unsigned long size,
 			   const unsigned char *sha1,
 			   int mode)
 {
 	int fd;
+	struct strbuf buf = STRBUF_INIT;
 
 	fd = git_mkstemp(temp->tmp_path, PATH_MAX, ".diff_XXXXXX");
 	if (fd < 0)
 		die("unable to create temp-file: %s", strerror(errno));
+	if (convert_to_working_tree(path,
+			(const char *)blob, (size_t)size, &buf)) {
+		blob = buf.buf;
+		size = buf.len;
+	}
 	if (write_in_full(fd, blob, size) != size)
 		die("unable to write temp-file");
 	close(fd);
 	temp->name = temp->tmp_path;
 	strcpy(temp->hex, sha1_to_hex(sha1));
 	temp->hex[40] = 0;
 	sprintf(temp->mode, "%06o", mode);
+	strbuf_release(&buf);
 }
 
 static struct diff_tempfile *prepare_temp_file(const char *name,
