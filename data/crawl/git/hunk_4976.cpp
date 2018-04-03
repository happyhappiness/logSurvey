 			die("cherry-pick --ff cannot be used with --edit");
 	}
 
-	if (read_cache() < 0)
-		die("git %s: failed to read the index", me);
+	read_and_refresh_cache(me);
 
 	prepare_revs(&revs);
 
