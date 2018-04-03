  */
 static void am_next(struct am_state *state)
 {
+	free(state->author_name);
+	state->author_name = NULL;
+
+	free(state->author_email);
+	state->author_email = NULL;
+
+	free(state->author_date);
+	state->author_date = NULL;
+
+	free(state->msg);
+	state->msg = NULL;
+	state->msg_len = 0;
+
+	unlink(am_path(state, "author-script"));
+	unlink(am_path(state, "final-commit"));
+
 	state->cur++;
 	write_file(am_path(state, "next"), 1, "%d", state->cur);
 }
 
+/**
+ * Returns the filename of the current patch email.
+ */
+static const char *msgnum(const struct am_state *state)
+{
+	static struct strbuf sb = STRBUF_INIT;
+
+	strbuf_reset(&sb);
+	strbuf_addf(&sb, "%0*d", state->prec, state->cur);
+
+	return sb.buf;
+}
+
+/**
+ * Parses `mail` using git-mailinfo, extracting its patch and authorship info.
+ * state->msg will be set to the patch message. state->author_name,
+ * state->author_email and state->author_date will be set to the patch author's
+ * name, email and date respectively. The patch body will be written to the
+ * state directory's "patch" file.
+ *
+ * Returns 1 if the patch should be skipped, 0 otherwise.
+ */
+static int parse_mail(struct am_state *state, const char *mail)
+{
+	FILE *fp;
+	struct child_process cp = CHILD_PROCESS_INIT;
+	struct strbuf sb = STRBUF_INIT;
+	struct strbuf msg = STRBUF_INIT;
+	struct strbuf author_name = STRBUF_INIT;
+	struct strbuf author_date = STRBUF_INIT;
+	struct strbuf author_email = STRBUF_INIT;
+	int ret = 0;
+
+	cp.git_cmd = 1;
+	cp.in = xopen(mail, O_RDONLY, 0);
+	cp.out = xopen(am_path(state, "info"), O_WRONLY | O_CREAT, 0777);
+
+	argv_array_push(&cp.args, "mailinfo");
+	argv_array_push(&cp.args, am_path(state, "msg"));
+	argv_array_push(&cp.args, am_path(state, "patch"));
+
+	if (run_command(&cp) < 0)
+		die("could not parse patch");
+
+	close(cp.in);
+	close(cp.out);
+
+	/* Extract message and author information */
+	fp = xfopen(am_path(state, "info"), "r");
+	while (!strbuf_getline(&sb, fp, '\n')) {
+		const char *x;
+
+		if (skip_prefix(sb.buf, "Subject: ", &x)) {
+			if (msg.len)
+				strbuf_addch(&msg, '\n');
+			strbuf_addstr(&msg, x);
+		} else if (skip_prefix(sb.buf, "Author: ", &x))
+			strbuf_addstr(&author_name, x);
+		else if (skip_prefix(sb.buf, "Email: ", &x))
+			strbuf_addstr(&author_email, x);
+		else if (skip_prefix(sb.buf, "Date: ", &x))
+			strbuf_addstr(&author_date, x);
+	}
+	fclose(fp);
+
+	/* Skip pine's internal folder data */
+	if (!strcmp(author_name.buf, "Mail System Internal Data")) {
+		ret = 1;
+		goto finish;
+	}
+
+	if (is_empty_file(am_path(state, "patch"))) {
+		printf_ln(_("Patch is empty. Was it split wrong?"));
+		exit(128);
+	}
+
+	strbuf_addstr(&msg, "\n\n");
+	if (strbuf_read_file(&msg, am_path(state, "msg"), 0) < 0)
+		die_errno(_("could not read '%s'"), am_path(state, "msg"));
+	stripspace(&msg, 0);
+
+	assert(!state->author_name);
+	state->author_name = strbuf_detach(&author_name, NULL);
+
+	assert(!state->author_email);
+	state->author_email = strbuf_detach(&author_email, NULL);
+
+	assert(!state->author_date);
+	state->author_date = strbuf_detach(&author_date, NULL);
+
+	assert(!state->msg);
+	state->msg = strbuf_detach(&msg, &state->msg_len);
+
+finish:
+	strbuf_release(&msg);
+	strbuf_release(&author_date);
+	strbuf_release(&author_email);
+	strbuf_release(&author_name);
+	strbuf_release(&sb);
+	return ret;
+}
+
 /**
  * Applies all queued mail.
  */
 static void am_run(struct am_state *state)
 {
 	while (state->cur <= state->last) {
+		const char *mail = am_path(state, msgnum(state));
+
+		if (!file_exists(mail))
+			goto next;
+
+		if (parse_mail(state, mail))
+			goto next; /* mail should be skipped */
+
+		write_author_script(state);
+		write_commit_msg(state);
 
 		/* NEEDSWORK: Patch application not implemented yet */
 
+next:
 		am_next(state);
 	}
 