 		separator++;
 	}
 
+	if (output_format & DIFF_FORMAT_NO_OUTPUT &&
+	    DIFF_OPT_TST(options, EXIT_WITH_STATUS) &&
+	    DIFF_OPT_TST(options, DIFF_FROM_CONTENTS)) {
+		/*
+		 * run diff_flush_patch for the exit status. setting
+		 * options->file to /dev/null should be safe, becaue we
+		 * aren't supposed to produce any output anyway.
+		 */
+		if (options->close_file)
+			fclose(options->file);
+		options->file = fopen("/dev/null", "w");
+		if (!options->file)
+			die_errno("Could not open /dev/null");
+		options->close_file = 1;
+		for (i = 0; i < q->nr; i++) {
+			struct diff_filepair *p = q->queue[i];
+			if (check_pair_status(p))
+				diff_flush_patch(p, options);
+			if (options->found_changes)
+				break;
+		}
+	}
+
 	if (output_format & DIFF_FORMAT_PATCH) {
 		if (separator) {
 			putc(options->line_termination, options->file);