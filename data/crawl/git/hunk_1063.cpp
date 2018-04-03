 	return result;
 }
 
-static void fill_sha1_path(char *pathbuf, const unsigned char *sha1)
+static void fill_sha1_path(struct strbuf *buf, const unsigned char *sha1)
 {
 	int i;
 	for (i = 0; i < 20; i++) {
 		static char hex[] = "0123456789abcdef";
 		unsigned int val = sha1[i];
-		*pathbuf++ = hex[val >> 4];
-		*pathbuf++ = hex[val & 0xf];
+		strbuf_addch(buf, hex[val >> 4]);
+		strbuf_addch(buf, hex[val & 0xf]);
 		if (!i)
-			*pathbuf++ = '/';
+			strbuf_addch(buf, '/');
 	}
-	*pathbuf = '\0';
 }
 
 const char *sha1_file_name(const unsigned char *sha1)
 {
-	static char buf[PATH_MAX];
-	const char *objdir;
-	int len;
+	static struct strbuf buf = STRBUF_INIT;
 
-	objdir = get_object_directory();
-	len = strlen(objdir);
+	strbuf_reset(&buf);
+	strbuf_addf(&buf, "%s/", get_object_directory());
 
-	/* '/' + sha1(2) + '/' + sha1(38) + '\0' */
-	if (len + 43 > PATH_MAX)
-		die("insanely long object directory %s", objdir);
-	memcpy(buf, objdir, len);
-	buf[len] = '/';
-	fill_sha1_path(buf + len + 1, sha1);
-	return buf;
+	fill_sha1_path(&buf, sha1);
+	return buf.buf;
 }
 
 struct strbuf *alt_scratch_buf(struct alternate_object_database *alt)
