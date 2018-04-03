 		if (diff_setup_done(&rev.diffopt) < 0)
 			die("diff_setup_done failed");
 	}
-	rev.diffopt.allow_external = 1;
-	rev.diffopt.recursive = 1;
+	DIFF_OPT_SET(&rev.diffopt, ALLOW_EXTERNAL);
+	DIFF_OPT_SET(&rev.diffopt, RECURSIVE);
 
 	/* If the user asked for our exit code then don't start a
 	 * pager or we would end up reporting its exit code instead.
 	 */
-	if (!rev.diffopt.exit_with_status)
+	if (!DIFF_OPT_TST(&rev.diffopt, EXIT_WITH_STATUS))
 		setup_pager();
 
 	/* Do we have --cached and not have a pending object, then
