 	fputc('\'', stream);
 }
 
-char *sq_quote_argv(const char** argv, int count)
+void sq_quote_argv(struct strbuf *dst, const char** argv, int count,
+                   size_t maxlen)
 {
-	char *buf, *to;
 	int i;
-	size_t len = 0;
 
 	/* Count argv if needed. */
 	if (count < 0) {
 		for (count = 0; argv[count]; count++)
 			; /* just counting */
 	}
 
-	/* Special case: no argv. */
-	if (!count)
-		return xcalloc(1,1);
-
-	/* Get destination buffer length. */
-	for (i = 0; i < count; i++)
-		len += sq_quote_buf(NULL, 0, argv[i]) + 1;
-
-	/* Alloc destination buffer. */
-	to = buf = xmalloc(len + 1);
-
 	/* Copy into destination buffer. */
+	strbuf_grow(dst, 32 * count);
 	for (i = 0; i < count; ++i) {
-		*to++ = ' ';
-		to += sq_quote_buf(to, len, argv[i]);
+		strbuf_addch(dst, ' ');
+		sq_quote_buf(dst, argv[i]);
+		if (maxlen && dst->len > maxlen)
+			die("Too many or long arguments");
 	}
-
-	return buf;
-}
-
-/*
- * Append a string to a string buffer, with or without shell quoting.
- * Return true if the buffer overflowed.
- */
-int add_to_string(char **ptrp, int *sizep, const char *str, int quote)
-{
-	char *p = *ptrp;
-	int size = *sizep;
-	int oc;
-	int err = 0;
-
-	if (quote)
-		oc = sq_quote_buf(p, size, str);
-	else {
-		oc = strlen(str);
-		memcpy(p, str, (size <= oc) ? size - 1 : oc);
-	}
-
-	if (size <= oc) {
-		err = 1;
-		oc = size - 1;
-	}
-
-	*ptrp += oc;
-	**ptrp = '\0';
-	*sizep -= oc;
-	return err;
 }
 
 char *sq_dequote(char *arg)
