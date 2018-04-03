 	argc = parse_options_end(&ctx);
 
 	if (setup_revisions(argc, argv, &rev, NULL) != 1) {
-		error("unrecognized argument: %s", argv[1]);
+		error(_("unrecognized argument: %s"), argv[1]);
 		usage_with_options(shortlog_usage, options);
 	}
 
