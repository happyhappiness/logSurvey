 	}
 
 	if (do_keep) {
-		if (pack_lockfile && pipe(keep_pipe))
-			die("fetch-pack: pipe setup failure: %s", strerror(errno));
+		if (pack_lockfile)
+			cmd.out = -1;
 		*av++ = "index-pack";
 		*av++ = "--stdin";
 		if (!args.quiet && !args.no_progress)
