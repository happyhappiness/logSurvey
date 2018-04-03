 		die("Invalid untracked files mode '%s'", untracked_files_arg);
 }
 
+static const char *read_commit_message(const char *name)
+{
+	const char *out_enc, *out;
+	struct commit *commit;
+
+	commit = lookup_commit_reference_by_name(name);
+	if (!commit)
+		die("could not lookup commit %s", name);
+	out_enc = get_commit_output_encoding();
+	out = logmsg_reencode(commit, out_enc);
+
+	/*
+	 * If we failed to reencode the buffer, just copy it
+	 * byte for byte so the user can try to fix it up.
+	 * This also handles the case where input and output
+	 * encodings are identical.
+	 */
+	if (out == NULL)
+		out = xstrdup(commit->buffer);
+	return out;
+}
+
 static int parse_and_validate_options(int argc, const char *argv[],
 				      const char * const usage[],
 				      const char *prefix,
