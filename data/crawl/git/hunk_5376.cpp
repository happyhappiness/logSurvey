 		OPT_INTEGER('m', "mainline", &mainline, "parent number"),
 		OPT_RERERE_AUTOUPDATE(&allow_rerere_auto),
 		OPT_END(),
+		OPT_END(),
+		OPT_END(),
 	};
 
+	if (action == CHERRY_PICK) {
+		struct option cp_extra[] = {
+			OPT_BOOLEAN(0, "ff", &allow_ff, "allow fast-forward"),
+			OPT_END(),
+		};
+		if (parse_options_concat(options, ARRAY_SIZE(options), cp_extra))
+			die("program error");
+	}
+
 	if (parse_options(argc, argv, NULL, options, usage_str, 0) != 1)
 		usage_with_options(usage_str, options);
 
