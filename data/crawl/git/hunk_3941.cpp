 		options->xdl_opts = DIFF_WITH_ALG(options, PATIENCE_DIFF);
 	else if (!strcmp(arg, "--histogram"))
 		options->xdl_opts = DIFF_WITH_ALG(options, HISTOGRAM_DIFF);
+	else if (!prefixcmp(arg, "--diff-algorithm=")) {
+		long value = parse_algorithm_value(arg+17);
+		if (value < 0)
+			return error("option diff-algorithm accepts \"myers\", "
+				     "\"minimal\", \"patience\" and \"histogram\"");
+		/* clear out previous settings */
+		DIFF_XDL_CLR(options, NEED_MINIMAL);
+		options->xdl_opts &= ~XDF_DIFF_ALGORITHM_MASK;
+		options->xdl_opts |= value;
+	}
 
 	/* flags options */
 	else if (!strcmp(arg, "--binary")) {
