 parse_done:
 	argc = parse_options_end(&ctx);
 
-	if (cmd_is_annotate)
+	if (revs_file && read_ancestry(revs_file))
+		die("reading graft file %s failed: %s",
+		    revs_file, strerror(errno));
+
+	if (cmd_is_annotate) {
 		output_option |= OUTPUT_ANNOTATE_COMPAT;
+		blame_date_mode = DATE_ISO8601;
+	} else {
+		blame_date_mode = revs.date_mode;
+	}
+
+	/* The maximum width used to show the dates */
+	switch (blame_date_mode) {
+	case DATE_RFC2822:
+		blame_date_width = sizeof("Thu, 19 Oct 2006 16:00:04 -0700");
+		break;
+	case DATE_ISO8601:
+		blame_date_width = sizeof("2006-10-19 16:00:04 -0700");
+		break;
+	case DATE_RAW:
+		blame_date_width = sizeof("1161298804 -0700");
+		break;
+	case DATE_SHORT:
+		blame_date_width = sizeof("2006-10-19");
+		break;
+	case DATE_RELATIVE:
+		/* "normal" is used as the fallback for "relative" */
+	case DATE_LOCAL:
+	case DATE_NORMAL:
+		blame_date_width = sizeof("Thu Oct 19 16:00:04 2006 -0700");
+		break;
+	}
+	blame_date_width -= 1; /* strip the null */
 
 	if (DIFF_OPT_TST(&revs.diffopt, FIND_COPIES_HARDER))
 		opt |= (PICKAXE_BLAME_COPY | PICKAXE_BLAME_MOVE |
