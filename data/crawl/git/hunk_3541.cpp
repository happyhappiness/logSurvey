 		show_diffstat = 0;
 
 	if (squash) {
-		if (!allow_fast_forward)
+		if (fast_forward == FF_NO)
 			die(_("You cannot combine --squash with --no-ff."));
 		option_commit = 0;
 	}
 
-	if (!allow_fast_forward && fast_forward_only)
-		die(_("You cannot combine --no-ff with --ff-only."));
-
 	if (!abort_current_merge) {
 		if (!argc) {
 			if (default_to_upstream)
