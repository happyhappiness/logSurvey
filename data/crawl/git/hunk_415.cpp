 	struct strbuf msgbuf = STRBUF_INIT;
 
 	filename = git_path_merge_msg();
-	fp = fopen(filename, "a");
-	if (!fp)
-		die_errno(_("Could not open '%s' for writing"), filename);
+	fp = xfopen(filename, "a");
 
 	append_conflicts_hint(&msgbuf);
 	fputs(msgbuf.buf, fp);
