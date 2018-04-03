 static uint32_t reused, reused_delta;
 
 
-static void *delta_against(void *buf, unsigned long size, struct object_entry *entry)
+static void *get_delta(struct object_entry *entry)
 {
-	unsigned long othersize, delta_size;
+	unsigned long size, base_size, delta_size;
+	void *buf, *base_buf, *delta_buf;
 	enum object_type type;
-	void *otherbuf = read_sha1_file(entry->delta->idx.sha1, &type, &othersize);
-	void *delta_buf;
 
-	if (!otherbuf)
+	buf = read_sha1_file(entry->idx.sha1, &type, &size);
+	if (!buf)
+		die("unable to read %s", sha1_to_hex(entry->idx.sha1));
+	base_buf = read_sha1_file(entry->delta->idx.sha1, &type, &base_size);
+	if (!base_buf)
 		die("unable to read %s", sha1_to_hex(entry->delta->idx.sha1));
-        delta_buf = diff_delta(otherbuf, othersize,
+	delta_buf = diff_delta(base_buf, base_size,
 			       buf, size, &delta_size, 0);
-        if (!delta_buf || delta_size != entry->delta_size)
+	if (!delta_buf || delta_size != entry->delta_size)
 		die("delta size changed");
-        free(buf);
-        free(otherbuf);
+	free(buf);
+	free(base_buf);
 	return delta_buf;
 }
 
