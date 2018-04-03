 	if (read_cache_unmerged())
 		return error_resolve_conflict(_(action_name(opts)));
 
-	error(_("Your local changes would be overwritten by %s."),
+	error(_("your local changes would be overwritten by %s."),
 		_(action_name(opts)));
 
 	if (advice_commit_before_merge)
-		advise(_("Commit your changes or stash them to proceed."));
+		advise(_("commit your changes or stash them to proceed."));
 	return -1;
 }
 
