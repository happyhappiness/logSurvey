 		setenv("GIT_COMMITTER_DATE",
 			state->ignore_date ? "" : state->author_date, 1);
 
-	if (commit_tree(state->msg, state->msg_len, tree, parents, commit,
+	if (commit_tree(state->msg, state->msg_len, tree.hash, parents, commit.hash,
 				author, state->sign_commit))
 		die(_("failed to write commit object"));
 
