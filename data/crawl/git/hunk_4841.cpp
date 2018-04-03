 		use_message = edit_message;
 	if (amend && !use_message && !fixup_message)
 		use_message = "HEAD";
-	if (!use_message && renew_authorship)
+	if (!use_message && whence != FROM_CHERRY_PICK && renew_authorship)
 		die("--reset-author can be used only with -C, -c or --amend.");
 	if (use_message) {
-		const char *out_enc;
-		struct commit *commit;
-
-		commit = lookup_commit_reference_by_name(use_message);
-		if (!commit)
-			die("could not lookup commit %s", use_message);
-		out_enc = get_commit_output_encoding();
-		use_message_buffer = logmsg_reencode(commit, out_enc);
-
-		/*
-		 * If we failed to reencode the buffer, just copy it
-		 * byte for byte so the user can try to fix it up.
-		 * This also handles the case where input and output
-		 * encodings are identical.
-		 */
-		if (use_message_buffer == NULL)
-			use_message_buffer = xstrdup(commit->buffer);
+		use_message_buffer = read_commit_message(use_message);
+		if (!renew_authorship) {
+			author_message = use_message;
+			author_message_buffer = use_message_buffer;
+		}
+	}
+	if (whence == FROM_CHERRY_PICK && !renew_authorship) {
+		author_message = "CHERRY_PICK_HEAD";
+		author_message_buffer = read_commit_message(author_message);
 	}
 
 	if (!!also + !!only + !!all + !!interactive > 1)
