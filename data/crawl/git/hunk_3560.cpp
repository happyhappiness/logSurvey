 	return logmsg_reencode(commit, NULL, out_enc);
 }
 
+/*
+ * Enumerate what needs to be propagated when --porcelain
+ * is not in effect here.
+ */
+static struct status_deferred_config {
+	enum status_format status_format;
+	int show_branch;
+} status_deferred_config = {
+	STATUS_FORMAT_UNSPECIFIED,
+	-1 /* unspecified */
+};
+
+static void finalize_deferred_config(struct wt_status *s)
+{
+	int use_deferred_config = (status_format != STATUS_FORMAT_PORCELAIN &&
+				   !s->null_termination);
+
+	if (s->null_termination) {
+		if (status_format == STATUS_FORMAT_NONE ||
+		    status_format == STATUS_FORMAT_UNSPECIFIED)
+			status_format = STATUS_FORMAT_PORCELAIN;
+		else if (status_format == STATUS_FORMAT_LONG)
+			die(_("--long and -z are incompatible"));
+	}
+
+	if (use_deferred_config && status_format == STATUS_FORMAT_UNSPECIFIED)
+		status_format = status_deferred_config.status_format;
+	if (status_format == STATUS_FORMAT_UNSPECIFIED)
+		status_format = STATUS_FORMAT_NONE;
+
+	if (use_deferred_config && s->show_branch < 0)
+		s->show_branch = status_deferred_config.show_branch;
+	if (s->show_branch < 0)
+		s->show_branch = 0;
+}
+
 static int parse_and_validate_options(int argc, const char *argv[],
 				      const struct option *options,
 				      const char * const usage[],
