 		else
 			die("bad --word-diff argument: %s", type);
 	}
-	else if (!prefixcmp(arg, "--word-diff-regex=")) {
+	else if ((argcount = parse_long_opt("word-diff-regex", av, &optarg))) {
 		if (options->word_diff == DIFF_WORDS_NONE)
 			options->word_diff = DIFF_WORDS_PLAIN;
-		options->word_regex = arg + 18;
+		options->word_regex = optarg;
+		return argcount;
 	}
 	else if (!strcmp(arg, "--exit-code"))
 		DIFF_OPT_SET(options, EXIT_WITH_STATUS);
