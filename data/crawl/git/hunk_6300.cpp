 	ALLOC_GROW(rev_argv, rev_argv_nr + 1, rev_argv_alloc);
 	rev_argv[rev_argv_nr++] = xstrdup("--");
 
-	setup_revisions(rev_argv_nr, rev_argv, &revs, NULL);
+	read_bisect_paths();
+
+	ALLOC_GROW(rev_argv, rev_argv_nr + 1, rev_argv_alloc);
+	rev_argv[rev_argv_nr++] = NULL;
+
+	setup_revisions(rev_argv_nr, rev_argv, revs, NULL);
+
+	revs->limited = 1;
+}
+
+int bisect_next_vars(const char *prefix)
+{
+	struct rev_info revs;
+	int reaches = 0, all = 0;
 
-	revs.limited = 1;
+	bisect_rev_setup(&revs, prefix);
 
 	if (prepare_revision_walk(&revs))
 		die("revision walk setup failed");