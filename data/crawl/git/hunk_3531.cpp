 	return 0;
 }
 
+static void print_object_or_die(int fd, const unsigned char *sha1,
+				enum object_type type, unsigned long size)
+{
+	if (type == OBJ_BLOB) {
+		if (stream_blob_to_fd(fd, sha1, NULL, 0) < 0)
+			die("unable to stream %s to stdout", sha1_to_hex(sha1));
+	}
+	else {
+		enum object_type rtype;
+		unsigned long rsize;
+		void *contents;
+
+		contents = read_sha1_file(sha1, &rtype, &rsize);
+		if (!contents)
+			die("object %s disappeared", sha1_to_hex(sha1));
+		if (rtype != type)
+			die("object %s changed type!?", sha1_to_hex(sha1));
+		if (rsize != size)
+			die("object %s change size!?", sha1_to_hex(sha1));
+
+		write_or_die(fd, contents, size);
+		free(contents);
+	}
+}
+
 static int batch_one_object(const char *obj_name, int print_contents)
 {
 	unsigned char sha1[20];
 	enum object_type type = 0;
 	unsigned long size;
-	void *contents = NULL;
 
 	if (!obj_name)
 	   return 1;
