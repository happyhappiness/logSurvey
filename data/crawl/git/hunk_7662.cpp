 	if (options->output_format & DIFF_FORMAT_NAME_STATUS)
 		count++;
 	if (options->output_format & DIFF_FORMAT_CHECKDIFF)
-	{
 		count++;
-		if (DIFF_OPT_TST(options, QUIET) ||
-		    DIFF_OPT_TST(options, EXIT_WITH_STATUS))
-			die("--check may not be used with --quiet or --exit-code");
-	}
 	if (options->output_format & DIFF_FORMAT_NO_OUTPUT)
 		count++;
 	if (count > 1)
