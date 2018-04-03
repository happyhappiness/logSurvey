 	for_each_ref(one_local_ref, NULL);
 }
 
-static int receive_status(int in)
+static struct ref *set_ref_error(struct ref *refs, const char *line)
 {
+	struct ref *ref;
+
+	for (ref = refs; ref; ref = ref->next) {
+		const char *msg;
+		if (prefixcmp(line, ref->name))
+			continue;
+		msg = line + strlen(ref->name);
+		if (*msg++ != ' ')
+			continue;
+		ref->status = REF_STATUS_REMOTE_REJECT;
+		ref->error = xstrdup(msg);
+		ref->error[strlen(ref->error)-1] = '\0';
+		return ref;
+	}
+	return NULL;
+}
+
+/* a return value of -1 indicates that an error occurred,
+ * but we were able to set individual ref errors. A return
+ * value of -2 means we couldn't even get that far. */
+static int receive_status(int in, struct ref *refs)
+{
+	struct ref *hint;
 	char line[1000];
 	int ret = 0;
 	int len = packet_read_line(in, line, sizeof(line));
 	if (len < 10 || memcmp(line, "unpack ", 7)) {
 		fprintf(stderr, "did not receive status back\n");
-		return -1;
+		return -2;
 	}
 	if (memcmp(line, "unpack ok\n", 10)) {
 		fputs(line, stderr);
 		ret = -1;
 	}
+	hint = NULL;
 	while (1) {
 		len = packet_read_line(in, line, sizeof(line));
 		if (!len)
