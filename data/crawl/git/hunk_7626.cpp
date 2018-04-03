 	return cmd_log_walk(&rev);
 }
 
-static int show_object(const unsigned char *sha1, int suppress_header)
+static void show_tagger(char *buf, int len, struct rev_info *rev)
+{
+	char *email_end, *p;
+	unsigned long date;
+	int tz;
+
+	email_end = memchr(buf, '>', len);
+	if (!email_end)
+		return;
+	p = ++email_end;
+	while (isspace(*p))
+		p++;
+	date = strtoul(p, &p, 10);
+	while (isspace(*p))
+		p++;
+	tz = (int)strtol(p, NULL, 10);
+	printf("Tagger: %.*s\nDate:   %s\n", (int)(email_end - buf), buf,
+	       show_date(date, tz, rev->date_mode));
+}
+
+static int show_object(const unsigned char *sha1, int show_tag_object,
+	struct rev_info *rev)
 {
 	unsigned long size;
 	enum object_type type;
