 
 static void bisect_rev_setup(struct rev_info *revs, const char *prefix)
 {
+	int i;
+
 	init_revisions(revs, prefix);
 	revs->abbrev = 0;
 	revs->commit_format = CMIT_FMT_UNSPECIFIED;
 
+	if (read_bisect_refs())
+		die("reading bisect refs failed");
+
 	/* argv[0] will be ignored by setup_revisions */
 	ALLOC_GROW(rev_argv, rev_argv_nr + 1, rev_argv_alloc);
 	rev_argv[rev_argv_nr++] = xstrdup("bisect_rev_setup");
 
-	if (read_bisect_refs())
-		die("reading bisect refs failed");
+	rev_argv_push(current_bad_sha1, "%s");
+
+	for (i = 0; i < good_revs.sha1_nr; i++)
+		rev_argv_push(good_revs.sha1[i], "^%s");
 
 	ALLOC_GROW(rev_argv, rev_argv_nr + 1, rev_argv_alloc);
 	rev_argv[rev_argv_nr++] = xstrdup("--");