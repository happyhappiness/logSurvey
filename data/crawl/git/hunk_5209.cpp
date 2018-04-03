 	char *defmsg = NULL;
 	struct strbuf msgbuf = STRBUF_INIT;
 
-	git_config(git_default_config, NULL);
-	me = action == REVERT ? "revert" : "cherry-pick";
-	setenv(GIT_REFLOG_ACTION, me, 0);
-	parse_args(argc, argv);
-
-	if (allow_ff) {
-		if (signoff)
-			die("cherry-pick --ff cannot be used with --signoff");
-		if (no_commit)
-			die("cherry-pick --ff cannot be used with --no-commit");
-		if (no_replay)
-			die("cherry-pick --ff cannot be used with -x");
-		if (edit)
-			die("cherry-pick --ff cannot be used with --edit");
-	}
-
-	if (read_cache() < 0)
-		die("git %s: failed to read the index", me);
 	if (no_commit) {
 		/*
 		 * We do not intend to commit immediately.  We just want to
