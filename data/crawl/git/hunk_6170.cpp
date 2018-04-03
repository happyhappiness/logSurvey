 		auto_number = auto_number && numbered;
 		return 0;
 	}
-
-	return git_log_config(var, value, cb);
-}
-
-
-static const char *get_oneline_for_filename(struct commit *commit,
-					    int keep_subject)
-{
-	static char filename[PATH_MAX];
-	char *sol;
-	int len = 0;
-	int suffix_len = strlen(fmt_patch_suffix) + 1;
-
-	sol = strstr(commit->buffer, "\n\n");
-	if (!sol)
-		filename[0] = '\0';
-	else {
-		int j, space = 0;
-
-		sol += 2;
-		/* strip [PATCH] or [PATCH blabla] */
-		if (!keep_subject && !prefixcmp(sol, "[PATCH")) {
-			char *eos = strchr(sol + 6, ']');
-			if (eos) {
-				while (isspace(*eos))
-					eos++;
-				sol = eos;
-			}
+	if (!strcmp(var, "format.attach")) {
+		if (value && *value)
+			default_attach = xstrdup(value);
+		else
+			default_attach = xstrdup(git_version_string);
+		return 0;
+	}
+	if (!strcmp(var, "format.thread")) {
+		if (value && !strcasecmp(value, "deep")) {
+			thread = THREAD_DEEP;
+			return 0;
 		}
-
-		for (j = 0;
-		     j < FORMAT_PATCH_NAME_MAX - suffix_len - 5 &&
-			     len < sizeof(filename) - suffix_len &&
-			     sol[j] && sol[j] != '\n';
-		     j++) {
-			if (istitlechar(sol[j])) {
-				if (space) {
-					filename[len++] = '-';
-					space = 0;
-				}
-				filename[len++] = sol[j];
-				if (sol[j] == '.')
-					while (sol[j + 1] == '.')
-						j++;
-			} else
-				space = 1;
+		if (value && !strcasecmp(value, "shallow")) {
+			thread = THREAD_SHALLOW;
+			return 0;
 		}
-		while (filename[len - 1] == '.'
-		       || filename[len - 1] == '-')
-			len--;
-		filename[len] = '\0';
+		thread = git_config_bool(var, value) && THREAD_SHALLOW;
+		return 0;
+	}
+	if (!strcmp(var, "format.signoff")) {
+		do_signoff = git_config_bool(var, value);
+		return 0;
 	}
-	return filename;
+
+	return git_log_config(var, value, cb);
 }
 
 static FILE *realstdout = NULL;
 static const char *output_directory = NULL;
 static int outdir_offset;
 
-static int reopen_stdout(const char *oneline, int nr, int total)
+static int reopen_stdout(struct commit *commit, struct rev_info *rev)
 {
-	char filename[PATH_MAX];
-	int len = 0;
+	struct strbuf filename = STRBUF_INIT;
 	int suffix_len = strlen(fmt_patch_suffix) + 1;
 
 	if (output_directory) {
-		len = snprintf(filename, sizeof(filename), "%s",
-				output_directory);
-		if (len >=
-		    sizeof(filename) - FORMAT_PATCH_NAME_MAX - suffix_len)
+		strbuf_addstr(&filename, output_directory);
+		if (filename.len >=
+		    PATH_MAX - FORMAT_PATCH_NAME_MAX - suffix_len)
 			return error("name of output directory is too long");
-		if (filename[len - 1] != '/')
-			filename[len++] = '/';
+		if (filename.buf[filename.len - 1] != '/')
+			strbuf_addch(&filename, '/');
 	}
 
-	if (!oneline)
-		len += sprintf(filename + len, "%d", nr);
-	else {
-		len += sprintf(filename + len, "%04d-", nr);
-		len += snprintf(filename + len, sizeof(filename) - len - 1
-				- suffix_len, "%s", oneline);
-		strcpy(filename + len, fmt_patch_suffix);
-	}
+	get_patch_filename(commit, rev->nr, fmt_patch_suffix, &filename);
 
-	fprintf(realstdout, "%s\n", filename + outdir_offset);
-	if (freopen(filename, "w", stdout) == NULL)
-		return error("Cannot open patch file %s",filename);
+	if (!DIFF_OPT_TST(&rev->diffopt, QUIET))
+		fprintf(realstdout, "%s\n", filename.buf + outdir_offset);
 
+	if (freopen(filename.buf, "w", stdout) == NULL)
+		return error("Cannot open patch file %s", filename.buf);
+
+	strbuf_release(&filename);
 	return 0;
 }
 
