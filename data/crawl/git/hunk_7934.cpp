 	return status;
 }
 
+static int count_reflog_ent(unsigned char *osha1, unsigned char *nsha1,
+		const char *email, unsigned long timestamp, int tz,
+		const char *message, void *cb_data)
+{
+	struct cmd_reflog_expire_cb *cb = cb_data;
+	if (!cb->expire_total || timestamp < cb->expire_total)
+		cb->recno++;
+	return 0;
+}
+
+static int cmd_reflog_delete(int argc, const char **argv, const char *prefix)
+{
+	struct cmd_reflog_expire_cb cb;
+	int i, status = 0;
+
+	if (argc < 2)
+		return error("Nothing to delete?");
+
+	memset(&cb, 0, sizeof(cb));
+
+	for (i = 1; i < argc; i++) {
+		const char *spec = strstr(argv[i], "@{");
+		unsigned char sha1[20];
+		char *ep, *ref;
+		int recno;
+
+		if (!spec) {
+			status |= error("Not a reflog: %s", ref);
+			continue;
+		}
+
+		if (!dwim_ref(argv[i], spec - argv[i], sha1, &ref)) {
+			status |= error("%s points nowhere!", argv[i]);
+			continue;
+		}
+
+		recno = strtoul(spec + 2, &ep, 10);
+		if (*ep == '}') {
+			cb.recno = -recno;
+			for_each_reflog_ent(ref, count_reflog_ent, &cb);
+		} else {
+			cb.expire_total = approxidate(spec + 2);
+			for_each_reflog_ent(ref, count_reflog_ent, &cb);
+			cb.expire_total = 0;
+		}
+
+		status |= expire_reflog(ref, sha1, 0, &cb);
+		free(ref);
+	}
+	return status;
+}
+
 /*
  * main "reflog"
  */
