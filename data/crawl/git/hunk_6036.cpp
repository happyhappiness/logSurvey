 	free_commit_list(result);
 }
 
+/*
+ * This function runs the command "git rev-list $_good ^$_bad"
+ * and returns 1 if it produces some output, 0 otherwise.
+ */
+static int check_ancestors(void)
+{
+	struct argv_array rev_argv = { NULL, 0, 0 };
+	struct strbuf str = STRBUF_INIT;
+	int i, result = 0;
+	struct child_process rls;
+	FILE *rls_fout;
+
+	argv_array_push(&rev_argv, xstrdup("rev-list"));
+	argv_array_push_sha1(&rev_argv, current_bad_sha1, "^%s");
+	for (i = 0; i < good_revs.sha1_nr; i++)
+		argv_array_push_sha1(&rev_argv, good_revs.sha1[i], "%s");
+	argv_array_push(&rev_argv, NULL);
+
+	memset(&rls, 0, sizeof(rls));
+	rls.argv = rev_argv.argv;
+	rls.out = -1;
+	rls.git_cmd = 1;
+	if (start_command(&rls))
+		die("Could not launch 'git rev-list' command.");
+	rls_fout = fdopen(rls.out, "r");
+	while (strbuf_getline(&str, rls_fout, '\n') != EOF) {
+		strbuf_trim(&str);
+		if (*str.buf) {
+			result = 1;
+			break;
+		}
+	}
+	fclose(rls_fout);
+	finish_command(&rls);
+
+	return result;
+}
+
+/*
+ * "check_good_are_ancestors_of_bad" checks that all "good" revs are
+ * ancestor of the "bad" rev.
+ *
+ * If that's not the case, we need to check the merge bases.
+ * If a merge base must be tested by the user, its source code will be
+ * checked out to be tested by the user and we will exit.
+ */
+static void check_good_are_ancestors_of_bad(const char *prefix)
+{
+	const char *filename = git_path("BISECT_ANCESTORS_OK");
+	struct stat st;
+	int fd;
+
+	if (!current_bad_sha1)
+		die("a bad revision is needed");
+
+	/* Check if file BISECT_ANCESTORS_OK exists. */
+	if (!stat(filename, &st) && S_ISREG(st.st_mode))
+		return;
+
+	/* Bisecting with no good rev is ok. */
+	if (good_revs.sha1_nr == 0)
+		return;
+
+	if (check_ancestors())
+		check_merge_bases();
+
+	/* Create file BISECT_ANCESTORS_OK. */
+	fd = open(filename, O_CREAT | O_TRUNC | O_WRONLY, 0600);
+	if (fd < 0)
+		warning("could not create file '%s': %s",
+			filename, strerror(errno));
+	else
+		close(fd);
+}
+
 /*
  * We use the convention that exiting with an exit code 10 means that
  * the bisection process finished successfully.