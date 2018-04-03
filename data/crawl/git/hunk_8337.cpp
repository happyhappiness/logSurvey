 {
 	unsigned long othersize, delta_size;
 	enum object_type type;
-	void *otherbuf = read_sha1_file(entry->delta->sha1, &type, &othersize);
+	void *otherbuf = read_sha1_file(entry->delta->idx.sha1, &type, &othersize);
 	void *delta_buf;
 
 	if (!otherbuf)
-		die("unable to read %s", sha1_to_hex(entry->delta->sha1));
+		die("unable to read %s", sha1_to_hex(entry->delta->idx.sha1));
         delta_buf = diff_delta(otherbuf, othersize,
 			       buf, size, &delta_size, 0);
         if (!delta_buf || delta_size != entry->delta_size)
