 	unsigned long size;
 	char *data;
 	enum object_type type;
-	char *to_free = NULL;
 	int hit;
+	struct strbuf pathbuf = STRBUF_INIT;
 
 	data = read_sha1_file(sha1, &type, &size);
 	if (!data) {
 		error("'%s': unable to read %s", name, sha1_to_hex(sha1));
 		return 0;
 	}
 	if (opt->relative && opt->prefix_length) {
-		static char name_buf[PATH_MAX];
-		char *cp;
-		int name_len = strlen(name) - opt->prefix_length + 1;
-
-		if (!tree_name_len)
-			name += opt->prefix_length;
-		else {
-			if (ARRAY_SIZE(name_buf) <= name_len)
-				cp = to_free = xmalloc(name_len);
-			else
-				cp = name_buf;
-			memcpy(cp, name, tree_name_len);
-			strcpy(cp + tree_name_len,
-			       name + tree_name_len + opt->prefix_length);
-			name = cp;
-		}
+		quote_path_relative(name + tree_name_len, -1, &pathbuf, opt->prefix);
+		strbuf_insert(&pathbuf, 0, name, tree_name_len);
+		name = pathbuf.buf;
 	}
 	hit = grep_buffer(opt, name, data, size);
+	strbuf_release(&pathbuf);
 	free(data);
-	free(to_free);
 	return hit;
 }
 
