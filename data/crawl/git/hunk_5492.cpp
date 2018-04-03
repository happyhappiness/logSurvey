 
 void read_revisions_from_stdin(struct rev_info *revs)
 {
-	char line[1000];
+	struct strbuf sb;
 
-	while (fgets(line, sizeof(line), stdin) != NULL) {
-		int len = strlen(line);
-		if (len && line[len - 1] == '\n')
-			line[--len] = '\0';
+	strbuf_init(&sb, 1000);
+	while (strbuf_getwholeline(&sb, stdin, '\n') != EOF) {
+		int len = sb.len;
+		if (len && sb.buf[len - 1] == '\n')
+			sb.buf[--len] = '\0';
 		if (!len)
 			break;
-		if (line[0] == '-')
+		if (sb.buf[0] == '-')
 			die("options not supported in --stdin mode");
-		if (handle_revision_arg(line, revs, 0, 1))
-			die("bad revision '%s'", line);
+		if (handle_revision_arg(sb.buf, revs, 0, 1))
+			die("bad revision '%s'", sb.buf);
 	}
+	strbuf_release(&sb);
 }
 
 static void add_grep(struct rev_info *revs, const char *ptn, enum grep_pat_token what)