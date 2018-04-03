 
 static void show_stats(struct patch *patch)
 {
-	const char *prefix = "";
-	char *name = patch->new_name;
-	char *qname = NULL;
-	int len, max, add, del, total;
-
-	if (!name)
-		name = patch->old_name;
+	struct strbuf qname;
+	char *cp = patch->new_name ? patch->new_name : patch->old_name;
+	int max, add, del;
 
-	if (0 < (len = quote_c_style(name, NULL, NULL, 0))) {
-		qname = xmalloc(len + 1);
-		quote_c_style(name, qname, NULL, 0);
-		name = qname;
-	}
+	strbuf_init(&qname, 0);
+	quote_c_style(cp, &qname, NULL, 0);
 
 	/*
 	 * "scale" the filename
 	 */
-	len = strlen(name);
 	max = max_len;
 	if (max > 50)
 		max = 50;
-	if (len > max) {
-		char *slash;
-		prefix = "...";
-		max -= 3;
-		name += len - max;
-		slash = strchr(name, '/');
-		if (slash)
-			name = slash;
+
+	if (qname.len > max) {
+		cp = strchr(qname.buf + qname.len + 3 - max, '/');
+		if (!cp)
+			cp = qname.buf + qname.len + 3 - max;
+		strbuf_splice(&qname, 0, cp - qname.buf, "...", 3);
+	}
+
+	if (patch->is_binary) {
+		printf(" %-*s |  Bin\n", max, qname.buf);
+		strbuf_release(&qname);
+		return;
 	}
-	len = max;
+
+	printf(" %-*s |", max, qname.buf);
+	strbuf_release(&qname);
 
 	/*
 	 * scale the add/delete
 	 */
-	max = max_change;
-	if (max + len > 70)
-		max = 70 - len;
-
+	max = max + max_change > 70 ? 70 - max : max_change;
 	add = patch->lines_added;
 	del = patch->lines_deleted;
-	total = add + del;
 
 	if (max_change > 0) {
-		total = (total * max + max_change / 2) / max_change;
+		int total = ((add + del) * max + max_change / 2) / max_change;
 		add = (add * max + max_change / 2) / max_change;
 		del = total - add;
 	}
-	if (patch->is_binary)
-		printf(" %s%-*s |  Bin\n", prefix, len, name);
-	else
-		printf(" %s%-*s |%5d %.*s%.*s\n", prefix,
-		       len, name, patch->lines_added + patch->lines_deleted,
-		       add, pluses, del, minuses);
-	free(qname);
+	printf("%5d %.*s%.*s\n", patch->lines_added + patch->lines_deleted,
+		add, pluses, del, minuses);
 }
 
 static int read_old_data(struct stat *st, const char *path, struct strbuf *buf)
