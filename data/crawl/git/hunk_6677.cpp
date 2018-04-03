 		git_xmerge_config("merge.conflictstyle", conflict_style, NULL);
 	}
 
-	if (!opts.new_branch && (opts.track != git_branch_track))
-		die("git checkout: --track and --no-track require -b");
-
 	if (opts.force && opts.merge)
 		die("git checkout: -f and -m are incompatible");
 