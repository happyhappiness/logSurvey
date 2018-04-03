 	setenv(GIT_REFLOG_ACTION, me, 0);
 	parse_args(argc, argv);
 
-	/* this is copied from the shell script, but it's never triggered... */
-	if (action == REVERT && !no_replay)
-		die("revert is incompatible with replay");
-
 	if (allow_ff) {
 		if (signoff)
 			die("cherry-pick --ff cannot be used with --signoff");
