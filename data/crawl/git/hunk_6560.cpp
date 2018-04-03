 
 static void show_tagger(char *buf, int len, struct rev_info *rev)
 {
-	char *email_end, *p;
-	unsigned long date;
-	int tz;
+	struct strbuf out = STRBUF_INIT;
 
-	email_end = memchr(buf, '>', len);
-	if (!email_end)
-		return;
-	p = ++email_end;
-	while (isspace(*p))
-		p++;
-	date = strtoul(p, &p, 10);
-	while (isspace(*p))
-		p++;
-	tz = (int)strtol(p, NULL, 10);
-	printf("Tagger: %.*s\nDate:   %s\n", (int)(email_end - buf), buf,
-	       show_date(date, tz, rev->date_mode));
+	pp_user_info("Tagger", rev->commit_format, &out, buf, rev->date_mode,
+		git_log_output_encoding ?
+		git_log_output_encoding: git_commit_encoding);
+	printf("%s\n", out.buf);
+	strbuf_release(&out);
 }
 
 static int show_object(const unsigned char *sha1, int show_tag_object,