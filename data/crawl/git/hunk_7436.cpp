 		numbered = 1;
 	if (numbered)
 		rev.total = total + start_number - 1;
-	rev.add_signoff = add_signoff;
 	if (in_reply_to)
 		rev.ref_message_id = clean_message_id(in_reply_to);
+	if (cover_letter) {
+		if (thread)
+			gen_message_id(&rev, "cover");
+		make_cover_letter(&rev, use_stdout, numbered, numbered_files,
+				  origin, head);
+		total++;
+		start_number--;
+	}
+	rev.add_signoff = add_signoff;
 	while (0 <= --nr) {
 		int shown;
 		commit = list[nr];
 		rev.nr = total - nr + (start_number - 1);
 		/* Make the second and subsequent mails replies to the first */
 		if (thread) {
+			/* Have we already had a message ID? */
 			if (rev.message_id) {
+				/*
+				 * If we've got the ID to be a reply
+				 * to, discard the current ID;
+				 * otherwise, make everything a reply
+				 * to that.
+				 */
 				if (rev.ref_message_id)
 					free(rev.message_id);
 				else
 					rev.ref_message_id = rev.message_id;
 			}
 			gen_message_id(&rev, sha1_to_hex(commit->object.sha1));
 		}
-		if (!use_stdout)
-			if (reopen_stdout(commit, rev.nr, keep_subject,
-					  numbered_files))
-				die("Failed to create output files");
+		if (!use_stdout && reopen_stdout(numbered_files ? NULL :
+				get_oneline_for_filename(commit, keep_subject),
+				rev.nr, rev.total))
+			die("Failed to create output files");
 		shown = log_tree_commit(&rev, commit);
 		free(commit->buffer);
 		commit->buffer = NULL;
