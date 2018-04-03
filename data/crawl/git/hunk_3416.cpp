 static int read_graft_file(const char *graft_file)
 {
 	FILE *fp = fopen(graft_file, "r");
-	char buf[1024];
+	struct strbuf buf = STRBUF_INIT;
 	if (!fp)
 		return -1;
-	while (fgets(buf, sizeof(buf), fp)) {
+	while (!strbuf_getwholeline(&buf, fp, '\n')) {
 		/* The format is just "Commit Parent1 Parent2 ...\n" */
-		int len = strlen(buf);
-		struct commit_graft *graft = read_graft_line(buf, len);
+		struct commit_graft *graft = read_graft_line(buf.buf, buf.len);
 		if (!graft)
 			continue;
 		if (register_commit_graft(graft, 1))
-			error("duplicate graft data: %s", buf);
+			error("duplicate graft data: %s", buf.buf);
 	}
 	fclose(fp);
+	strbuf_release(&buf);
 	return 0;
 }
 
