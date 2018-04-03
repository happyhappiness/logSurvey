 	}
 
 	tree_content_set(&b->branch_tree, p, sha1, S_IFREG | mode, NULL);
-	free(p_uq);
 }
 
 static void file_change_d(struct branch *b)
 {
 	const char *p = command_buf.buf + 2;
-	char *p_uq;
+	static struct strbuf uq = STRBUF_INIT;
 	const char *endp;
 
-	p_uq = unquote_c_style(p, &endp);
-	if (p_uq) {
+	strbuf_reset(&uq);
+	if (!unquote_c_style(&uq, p, &endp)) {
 		if (*endp)
 			die("Garbage after path in: %s", command_buf.buf);
-		p = p_uq;
+		p = uq.buf;
 	}
 	tree_content_remove(&b->branch_tree, p, NULL);
-	free(p_uq);
 }
 
 static void file_change_cr(struct branch *b, int rename)
 {
 	const char *s, *d;
-	char *s_uq, *d_uq;
+	static struct strbuf s_uq = STRBUF_INIT;
+	static struct strbuf d_uq = STRBUF_INIT;
 	const char *endp;
 	struct tree_entry leaf;
 
 	s = command_buf.buf + 2;
-	s_uq = unquote_c_style(s, &endp);
-	if (s_uq) {
+	strbuf_reset(&s_uq);
+	if (!unquote_c_style(&s_uq, s, &endp)) {
 		if (*endp != ' ')
 			die("Missing space after source: %s", command_buf.buf);
-	}
-	else {
+	} else {
 		endp = strchr(s, ' ');
 		if (!endp)
 			die("Missing space after source: %s", command_buf.buf);
-		s_uq = xmemdupz(s, endp - s);
+		strbuf_add(&s_uq, s, endp - s);
 	}
-	s = s_uq;
+	s = s_uq.buf;
 
 	endp++;
 	if (!*endp)
 		die("Missing dest: %s", command_buf.buf);
 
 	d = endp;
-	d_uq = unquote_c_style(d, &endp);
-	if (d_uq) {
+	strbuf_reset(&d_uq);
+	if (!unquote_c_style(&d_uq, d, &endp)) {
 		if (*endp)
 			die("Garbage after dest in: %s", command_buf.buf);
-		d = d_uq;
+		d = d_uq.buf;
 	}
 
 	memset(&leaf, 0, sizeof(leaf));
