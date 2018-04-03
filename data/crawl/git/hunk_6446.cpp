 		die("Unable to create temporary file: %s", strerror(errno));
 	return fd;
 }
+
+int odb_mkstemp(char *template, size_t limit, const char *pattern)
+{
+	int fd;
+
+	snprintf(template, limit, "%s/%s",
+		 get_object_directory(), pattern);
+	fd = mkstemp(template);
+	if (0 <= fd)
+		return fd;
+
+	/* slow path */
+	safe_create_leading_directories(template);
+	snprintf(template, limit, "%s/%s",
+		 get_object_directory(), pattern);
+	return xmkstemp(template);
+}
+
+int odb_pack_keep(char *name, size_t namesz, unsigned char *sha1)
+{
+	int fd;
+
+	snprintf(name, namesz, "%s/pack/pack-%s.keep",
+		 get_object_directory(), sha1_to_hex(sha1));
+	fd = open(name, O_RDWR|O_CREAT|O_EXCL, 0600);
+	if (0 <= fd)
+		return fd;
+
+	/* slow path */
+	safe_create_leading_directories(name);
+	return open(name, O_RDWR|O_CREAT|O_EXCL, 0600);
+}