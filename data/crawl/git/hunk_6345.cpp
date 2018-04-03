 	const char *encoding = "utf-8";
 	struct diff_options opts;
 	int need_8bit_cte = 0;
-	char filename[PATH_MAX];
+	struct commit *commit = NULL;
 
 	if (rev->commit_format != CMIT_FMT_EMAIL)
 		die("Cover letter needs email format");
 
-	if (numbered_files)
-		sprintf(filename, "0");
-	else
-		sprintf(filename, "%04d-cover-letter%s", 0, fmt_patch_suffix);
+	committer = git_committer_info(0);
+	head_sha1 = sha1_to_hex(head->object.sha1);
 
-	if (!use_stdout && reopen_stdout(filename, rev))
+	if (!numbered_files) {
+		/*
+		 * We fake a commit for the cover letter so we get the filename
+		 * desired.
+		 */
+		commit = xcalloc(1, sizeof(*commit));
+		commit->buffer = xmalloc(400);
+		snprintf(commit->buffer, 400,
+			"tree 0000000000000000000000000000000000000000\n"
+			"parent %s\n"
+			"author %s\n"
+			"committer %s\n\n"
+			"cover letter\n",
+			head_sha1, committer, committer);
+	}
+
+	if (!use_stdout && reopen_stdout(commit, rev))
 		return;
 
-	head_sha1 = sha1_to_hex(head->object.sha1);
+	if (commit) {
+
+		free(commit->buffer);
+		free(commit);
+	}
 
 	log_write_email_headers(rev, head_sha1, &subject_start, &extra_headers,
 				&need_8bit_cte);
 
-	committer = git_committer_info(0);
-
 	msg = body;
 	pp_user_info(NULL, CMIT_FMT_EMAIL, &sb, committer, DATE_RFC2822,
 		     encoding);
