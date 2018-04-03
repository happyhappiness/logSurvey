 			sha1_to_hex(commit->object.sha1));
 }
 
+static void write_cherry_pick_head(void)
+{
+	int fd;
+	struct strbuf buf = STRBUF_INIT;
+
+	strbuf_addf(&buf, "%s\n", sha1_to_hex(commit->object.sha1));
+
+	fd = open(git_path("CHERRY_PICK_HEAD"), O_WRONLY | O_CREAT, 0666);
+	if (fd < 0)
+		die_errno("Could not open '%s' for writing",
+			  git_path("CHERRY_PICK_HEAD"));
+	if (write_in_full(fd, buf.buf, buf.len) != buf.len || close(fd))
+		die_errno("Could not write to '%s'", git_path("CHERRY_PICK_HEAD"));
+	strbuf_release(&buf);
+}
+
 static void advise(const char *advice, ...)
 {
 	va_list params;
