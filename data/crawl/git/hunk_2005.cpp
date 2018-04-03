 	return 0;
 }
 
+static int collect_expect(const struct option *opt, const char *arg, int unset)
+{
+	struct string_list *expect;
+	struct string_list_item *item;
+	struct strbuf label = STRBUF_INIT;
+	const char *colon;
+
+	if (!arg || unset)
+		die("malformed --expect option");
+
+	expect = (struct string_list *)opt->value;
+	colon = strchr(arg, ':');
+	if (!colon)
+		die("malformed --expect option, lacking a colon");
+	strbuf_add(&label, arg, colon - arg);
+	item = string_list_insert(expect, strbuf_detach(&label, NULL));
+	if (item->util)
+		die("malformed --expect option, duplicate %s", label.buf);
+	item->util = (void *)arg;
+	return 0;
+}
+
+__attribute__((format (printf,3,4)))
+static void show(struct string_list *expect, int *status, const char *fmt, ...)
+{
+	struct string_list_item *item;
+	struct strbuf buf = STRBUF_INIT;
+	va_list args;
+
+	va_start(args, fmt);
+	strbuf_vaddf(&buf, fmt, args);
+	va_end(args);
+
+	if (!expect->nr)
+		printf("%s\n", buf.buf);
+	else {
+		char *colon = strchr(buf.buf, ':');
+		if (!colon)
+			die("malformed output format, output lacking colon: %s", fmt);
+		*colon = '\0';
+		item = string_list_lookup(expect, buf.buf);
+		*colon = ':';
+		if (!item)
+			; /* not among entries being checked */
+		else {
+			if (strcmp((const char *)item->util, buf.buf)) {
+				printf("-%s\n", (char *)item->util);
+				printf("+%s\n", buf.buf);
+				*status = 1;
+			}
+		}
+	}
+	strbuf_release(&buf);
+}
+
 int main(int argc, char **argv)
 {
 	const char *prefix = "prefix/";
 	const char *usage[] = {
 		"test-parse-options <options>",
 		NULL
 	};
+	struct string_list expect = STRING_LIST_INIT_NODUP;
 	struct option options[] = {
 		OPT_BOOL(0, "yes", &boolean, "get a boolean"),
 		OPT_BOOL('D', "no-doubt", &boolean, "begins with 'no-'"),
