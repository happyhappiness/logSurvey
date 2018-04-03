 	ctx.output_encoding = get_log_output_encoding();
 
 	format_commit_message(commit, "%an <%ae>", &author, &ctx);
-	/* we can detect a total failure only by seeing " <>" in the output */
-	if (author.len <= 3) {
-		warning(_("Missing author: %s"),
-		    oid_to_hex(&commit->object.oid));
-		goto out;
-	}
-
 	if (!log->summary) {
 		if (log->user_format)
 			pretty_print_commit(&ctx, commit, &oneline);
