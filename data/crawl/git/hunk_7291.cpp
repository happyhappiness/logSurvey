 static void wt_status_print_verbose(struct wt_status *s)
 {
 	struct rev_info rev;
-	int saved_stdout;
-
-	fflush(s->fp);
-
-	/* Sigh, the entire diff machinery is hardcoded to output to
-	 * stdout.  Do the dup-dance...*/
-	saved_stdout = dup(STDOUT_FILENO);
-	if (saved_stdout < 0 ||dup2(fileno(s->fp), STDOUT_FILENO) < 0)
-		die("couldn't redirect stdout\n");
 
 	init_revisions(&rev, NULL);
 	setup_revisions(0, NULL, &rev, s->reference);
 	rev.diffopt.output_format |= DIFF_FORMAT_PATCH;
 	rev.diffopt.detect_rename = 1;
+	rev.diffopt.file = s->fp;
+	rev.diffopt.close_file = 0;
 	run_diff_index(&rev, 1);
-
-	fflush(stdout);
-
-	if (dup2(saved_stdout, STDOUT_FILENO) < 0)
-		die("couldn't restore stdout\n");
-	close(saved_stdout);
 }
 
 void wt_status_print(struct wt_status *s)