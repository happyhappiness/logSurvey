 	return end - start + 1;
 }
 
-static void print_object_or_die(int fd, const unsigned char *sha1,
-				enum object_type type, unsigned long size)
+static void print_object_or_die(int fd, struct expand_data *data)
 {
-	if (type == OBJ_BLOB) {
+	const unsigned char *sha1 = data->sha1;
+
+	if (data->type == OBJ_BLOB) {
 		if (stream_blob_to_fd(fd, sha1, NULL, 0) < 0)
 			die("unable to stream %s to stdout", sha1_to_hex(sha1));
 	}
 	else {
-		enum object_type rtype;
-		unsigned long rsize;
+		enum object_type type;
+		unsigned long size;
 		void *contents;
 
-		contents = read_sha1_file(sha1, &rtype, &rsize);
+		contents = read_sha1_file(sha1, &type, &size);
 		if (!contents)
 			die("object %s disappeared", sha1_to_hex(sha1));
-		if (rtype != type)
+		if (type != data->type)
 			die("object %s changed type!?", sha1_to_hex(sha1));
-		if (rsize != size)
-			die("object %s change size!?", sha1_to_hex(sha1));
+		if (size != data->size)
+			die("object %s changed size!?", sha1_to_hex(sha1));
 
 		write_or_die(fd, contents, size);
 		free(contents);
