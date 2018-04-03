 	argc = setup_revisions(argc, argv, &rev, NULL);
 	if (!rev.diffopt.output_format) {
 		rev.diffopt.output_format = DIFF_FORMAT_PATCH;
-		if (diff_setup_done(&rev.diffopt) < 0)
-			die(_("diff_setup_done failed"));
+		diff_setup_done(&rev.diffopt);
 	}
 
 	DIFF_OPT_SET(&rev.diffopt, RECURSIVE);
