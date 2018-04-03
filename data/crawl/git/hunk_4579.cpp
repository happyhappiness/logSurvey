 	}
 
 	if (fast_forward_only)
-		die("Not possible to fast-forward, aborting.");
+		die(_("Not possible to fast-forward, aborting."));
 
 	/* We are going to make a new commit. */
 	git_committer_info(IDENT_ERROR_ON_NO_NAME);
