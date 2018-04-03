 		free(head_ref);
 	}
 
-	if (opts->new_worktree) {
-		if (!new->commit)
-			die(_("no branch specified"));
-		return prepare_linked_checkout(opts->new_worktree,
-					       opts->saved_argv);
-	}
-
 	if (!new->commit && opts->new_branch) {
 		unsigned char rev[20];
 		int flag;
