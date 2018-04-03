 static int inside_git_dir = -1;
 static int inside_work_tree = -1;
 
-const char *prefix_path(const char *prefix, int len, const char *path)
+static int sanitary_path_copy(char *dst, const char *src)
 {
-	const char *orig = path;
+	char *dst0 = dst;
+
+	if (*src == '/') {
+		*dst++ = '/';
+		while (*src == '/')
+			src++;
+	}
+
 	for (;;) {
-		char c;
-		if (*path != '.')
-			break;
-		c = path[1];
-		/* "." */
-		if (!c) {
-			path++;
-			break;
+		char c = *src;
+
+		/*
+		 * A path component that begins with . could be
+		 * special:
+		 * (1) "." and ends   -- ignore and terminate.
+		 * (2) "./"           -- ignore them, eat slash and continue.
+		 * (3) ".." and ends  -- strip one and terminate.
+		 * (4) "../"          -- strip one, eat slash and continue.
+		 */
+		if (c == '.') {
+			switch (src[1]) {
+			case '\0':
+				/* (1) */
+				src++;
+				break;
+			case '/':
+				/* (2) */
+				src += 2;
+				while (*src == '/')
+					src++;
+				continue;
+			case '.':
+				switch (src[2]) {
+				case '\0':
+					/* (3) */
+					src += 2;
+					goto up_one;
+				case '/':
+					/* (4) */
+					src += 3;
+					while (*src == '/')
+						src++;
+					goto up_one;
+				}
+			}
 		}
-		/* "./" */
+
+		/* copy up to the next '/', and eat all '/' */
+		while ((c = *src++) != '\0' && c != '/')
+			*dst++ = c;
 		if (c == '/') {
-			path += 2;
-			continue;
-		}
-		if (c != '.')
+			*dst++ = c;
+			while (c == '/')
+				c = *src++;
+			src--;
+		} else if (!c)
 			break;
-		c = path[2];
-		if (!c)
-			path += 2;
-		else if (c == '/')
-			path += 3;
-		else
-			break;
-		/* ".." and "../" */
-		/* Remove last component of the prefix */
-		do {
-			if (!len)
-				die("'%s' is outside repository", orig);
-			len--;
-		} while (len && prefix[len-1] != '/');
 		continue;
+
+	up_one:
+		/*
+		 * dst0..dst is prefix portion, and dst[-1] is '/';
+		 * go up one level.
+		 */
+		dst -= 2; /* go past trailing '/' if any */
+		if (dst < dst0)
+			return -1;
+		while (1) {
+			if (dst <= dst0)
+				break;
+			c = *dst--;
+			if (c == '/') {
+				dst += 2;
+				break;
+			}
+		}
 	}
-	if (len) {
-		int speclen = strlen(path);
-		char *n = xmalloc(speclen + len + 1);
+	*dst = '\0';
+	return 0;
+}
 
-		memcpy(n, prefix, len);
-		memcpy(n + len, path, speclen+1);
-		path = n;
+const char *prefix_path(const char *prefix, int len, const char *path)
+{
+	const char *orig = path;
+	char *sanitized = xmalloc(len + strlen(path) + 1);
+	if (*orig == '/')
+		strcpy(sanitized, path);
+	else {
+		if (len)
+			memcpy(sanitized, prefix, len);
+		strcpy(sanitized + len, path);
 	}
-	return path;
+	if (sanitary_path_copy(sanitized, sanitized))
+		goto error_out;
+	if (*orig == '/') {
+		const char *work_tree = get_git_work_tree();
+		size_t len = strlen(work_tree);
+		size_t total = strlen(sanitized) + 1;
+		if (strncmp(sanitized, work_tree, len) ||
+		    (sanitized[len] != '\0' && sanitized[len] != '/')) {
+		error_out:
+			error("'%s' is outside repository", orig);
+			free(sanitized);
+			return NULL;
+		}
+		if (sanitized[len] == '/')
+			len++;
+		memmove(sanitized, sanitized + len, total - len);
+	}
+	return sanitized;
 }
 
 /*
