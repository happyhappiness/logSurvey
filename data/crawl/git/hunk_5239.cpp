  */
 char *sha1_file_name(const unsigned char *sha1)
 {
-	static char *name, *base;
+	static char buf[PATH_MAX];
+	const char *objdir;
+	int len;
 
-	if (!base) {
-		const char *sha1_file_directory = get_object_directory();
-		int len = strlen(sha1_file_directory);
-		base = xmalloc(len + 60);
-		memcpy(base, sha1_file_directory, len);
-		memset(base+len, 0, 60);
-		base[len] = '/';
-		base[len+3] = '/';
-		name = base + len + 1;
-	}
-	fill_sha1_path(name, sha1);
-	return base;
+	objdir = get_object_directory();
+	len = strlen(objdir);
+
+	/* '/' + sha1(2) + '/' + sha1(38) + '\0' */
+	if (len + 43 > PATH_MAX)
+		die("insanely long object directory %s", objdir);
+	memcpy(buf, objdir, len);
+	buf[len] = '/';
+	buf[len+3] = '/';
+	buf[len+42] = '\0';
+	fill_sha1_path(buf + len + 1, sha1);
+	return buf;
 }
 
 static char *sha1_get_pack_name(const unsigned char *sha1,