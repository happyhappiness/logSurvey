 	int cnt = 0;
 	struct rev_info rev;
 
-	discard_cache();
-	if (read_cache() < 0)
-		die("failed to read the cache");
-
 	/* Check how many files differ. */
 	init_revisions(&rev, "");
 	setup_revisions(0, NULL, &rev, NULL);
