 			OPT_BOOL(0, "keep-redundant-commits", &opts->keep_redundant_commits, N_("keep redundant, empty commits")),
 			OPT_END(),
 		};
-		if (parse_options_concat(options, ARRAY_SIZE(options), cp_extra))
-			die(_("program error"));
+		options = parse_options_concat(options, cp_extra);
 	}
 
 	argc = parse_options(argc, argv, NULL, options, usage_str,
