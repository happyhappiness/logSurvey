 {
 	int msg_type;
 
-	msg_type = msg_id_info[msg_id].msg_type;
-	if (options->strict && msg_type == FSCK_WARN)
-		msg_type = FSCK_ERROR;
+	assert(msg_id >= 0 && msg_id < FSCK_MSG_MAX);
+
+	if (options->msg_type)
+		msg_type = options->msg_type[msg_id];
+	else {
+		msg_type = msg_id_info[msg_id].msg_type;
+		if (options->strict && msg_type == FSCK_WARN)
+			msg_type = FSCK_ERROR;
+	}
 
 	return msg_type;
 }
 
+static int parse_msg_type(const char *str)
+{
+	if (!strcmp(str, "error"))
+		return FSCK_ERROR;
+	else if (!strcmp(str, "warn"))
+		return FSCK_WARN;
+	else
+		die("Unknown fsck message type: '%s'", str);
+}
+
+void fsck_set_msg_type(struct fsck_options *options,
+		const char *msg_id, const char *msg_type)
+{
+	int id = parse_msg_id(msg_id), type;
+
+	if (id < 0)
+		die("Unhandled message id: %s", msg_id);
+	type = parse_msg_type(msg_type);
+
+	if (!options->msg_type) {
+		int i;
+		int *msg_type = xmalloc(sizeof(int) * FSCK_MSG_MAX);
+		for (i = 0; i < FSCK_MSG_MAX; i++)
+			msg_type[i] = fsck_msg_type(i, options);
+		options->msg_type = msg_type;
+	}
+
+	options->msg_type[id] = type;
+}
+
+void fsck_set_msg_types(struct fsck_options *options, const char *values)
+{
+	char *buf = xstrdup(values), *to_free = buf;
+	int done = 0;
+
+	while (!done) {
+		int len = strcspn(buf, " ,|"), equal;
+
+		done = !buf[len];
+		if (!len) {
+			buf++;
+			continue;
+		}
+		buf[len] = '\0';
+
+		for (equal = 0;
+		     equal < len && buf[equal] != '=' && buf[equal] != ':';
+		     equal++)
+			buf[equal] = tolower(buf[equal]);
+		buf[equal] = '\0';
+
+		if (equal == len)
+			die("Missing '=': '%s'", buf);
+
+		fsck_set_msg_type(options, buf, buf + equal + 1);
+		buf += len + 1;
+	}
+	free(to_free);
+}
+
 __attribute__((format (printf, 4, 5)))
 static int report(struct fsck_options *options, struct object *object,
 	enum fsck_msg_id id, const char *fmt, ...)
