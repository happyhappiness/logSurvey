 		av = default_arg - 1; /* ick; we would not address av[0] */
 	}
 
-	while (1 < ac && av[1][0] == '-') {
-		const char *arg = av[1];
-		if (!strcmp(arg, "--")) {
-			ac--; av++;
-			break;
-		}
-		else if (!strcmp(arg, "--all") || !strcmp(arg, "-a"))
-			all_heads = all_remotes = 1;
-		else if (!strcmp(arg, "--remotes") || !strcmp(arg, "-r"))
-			all_remotes = 1;
-		else if (!strcmp(arg, "--more"))
-			extra = 1;
-		else if (!strcmp(arg, "--list"))
-			extra = -1;
-		else if (!strcmp(arg, "--no-name"))
-			no_name = 1;
-		else if (!strcmp(arg, "--current"))
-			with_current_branch = 1;
-		else if (!strcmp(arg, "--sha1-name"))
-			sha1_name = 1;
-		else if (!prefixcmp(arg, "--more="))
-			extra = atoi(arg + 7);
-		else if (!strcmp(arg, "--merge-base"))
-			merge_base = 1;
-		else if (!strcmp(arg, "--independent"))
-			independent = 1;
-		else if (!strcmp(arg, "--topo-order"))
-			lifo = 1;
-		else if (!strcmp(arg, "--topics"))
-			topics = 1;
-		else if (!strcmp(arg, "--sparse"))
-			dense = 0;
-		else if (!strcmp(arg, "--date-order"))
-			lifo = 0;
-		else if (!strcmp(arg, "--reflog") || !strcmp(arg, "-g")) {
-			reflog = DEFAULT_REFLOG;
-		}
-		else if (!prefixcmp(arg, "--reflog="))
-			parse_reflog_param(arg + 9, &reflog, &reflog_base);
-		else if (!prefixcmp(arg, "-g="))
-			parse_reflog_param(arg + 3, &reflog, &reflog_base);
-		else if (!strcmp(arg, "--color"))
-			showbranch_use_color = 1;
-		else if (!strcmp(arg, "--no-color"))
-			showbranch_use_color = 0;
-		else
-			usage(show_branch_usage);
-		ac--; av++;
-	}
-	ac--; av++;
+	ac = parse_options(ac, av, builtin_show_branch_options,
+			   show_branch_usage, PARSE_OPT_STOP_AT_NON_OPTION);
+	if (all_heads)
+		all_remotes = 1;
 
 	if (extra || reflog) {
 		/* "listing" mode is incompatible with
 		 * independent nor merge-base modes.
 		 */
 		if (independent || merge_base)
-			usage(show_branch_usage);
+			usage_with_options(show_branch_usage,
+					   builtin_show_branch_options);
 		if (reflog && ((0 < extra) || all_heads || all_remotes))
 			/*
 			 * Asking for --more in reflog mode does not
 			 * make sense.  --list is Ok.
 			 *
 			 * Also --all and --remotes do not make sense either.
 			 */
-			usage(show_branch_usage_reflog);
+			die("--reflog is incompatible with --all, --remotes, "
+			    "--independent or --merge-base");
 	}
 
 	/* If nothing is specified, show all branches by default */