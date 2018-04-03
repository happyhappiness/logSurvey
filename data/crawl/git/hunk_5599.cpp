 		free(data->helper);
 		data->helper = NULL;
 	}
+	free(data);
 	return 0;
 }
 
+static const char *unsupported_options[] = {
+	TRANS_OPT_UPLOADPACK,
+	TRANS_OPT_RECEIVEPACK,
+	TRANS_OPT_THIN,
+	TRANS_OPT_KEEP
+	};
+static const char *boolean_options[] = {
+	TRANS_OPT_THIN,
+	TRANS_OPT_KEEP,
+	TRANS_OPT_FOLLOWTAGS
+	};
+
+static int set_helper_option(struct transport *transport,
+			  const char *name, const char *value)
+{
+	struct helper_data *data = transport->data;
+	struct child_process *helper = get_helper(transport);
+	struct strbuf buf = STRBUF_INIT;
+	int i, ret, is_bool = 0;
+
+	if (!data->option)
+		return 1;
+
+	for (i = 0; i < ARRAY_SIZE(unsupported_options); i++) {
+		if (!strcmp(name, unsupported_options[i]))
+			return 1;
+	}
+
+	for (i = 0; i < ARRAY_SIZE(boolean_options); i++) {
+		if (!strcmp(name, boolean_options[i])) {
+			is_bool = 1;
+			break;
+		}
+	}
+
+	strbuf_addf(&buf, "option %s ", name);
+	if (is_bool)
+		strbuf_addstr(&buf, value ? "true" : "false");
+	else
+		quote_c_style(value, &buf, NULL, 0);
+	strbuf_addch(&buf, '\n');
+
+	if (write_in_full(helper->in, buf.buf, buf.len) != buf.len)
+		die_errno("cannot send option to %s", data->name);
+
+	strbuf_reset(&buf);
+	if (strbuf_getline(&buf, data->out, '\n') == EOF)
+		exit(128); /* child died, message supplied already */
+
+	if (!strcmp(buf.buf, "ok"))
+		ret = 0;
+	else if (!prefixcmp(buf.buf, "error")) {
+		ret = -1;
+	} else if (!strcmp(buf.buf, "unsupported"))
+		ret = 1;
+	else {
+		warning("%s unexpectedly said: '%s'", data->name, buf.buf);
+		ret = 1;
+	}
+	strbuf_release(&buf);
+	return ret;
+}
+
+static void standard_options(struct transport *t)
+{
+	char buf[16];
+	int n;
+	int v = t->verbose;
+	int no_progress = v < 0 || (!t->progress && !isatty(1));
+
+	set_helper_option(t, "progress", !no_progress ? "true" : "false");
+
+	n = snprintf(buf, sizeof(buf), "%d", v + 1);
+	if (n >= sizeof(buf))
+		die("impossibly large verbosity value");
+	set_helper_option(t, "verbosity", buf);
+}
+
 static int fetch_with_fetch(struct transport *transport,
 			    int nr_heads, const struct ref **to_fetch)
 {
 	struct helper_data *data = transport->data;
 	int i;
 	struct strbuf buf = STRBUF_INIT;
 
+	standard_options(transport);
+
 	for (i = 0; i < nr_heads; i++) {
 		const struct ref *posn = to_fetch[i];
 		if (posn->status & REF_STATUS_UPTODATE)
