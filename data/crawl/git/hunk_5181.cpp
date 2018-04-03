 		DIFF_OPT_CLR(options, ALLOW_TEXTCONV);
 	else if (!strcmp(arg, "--ignore-submodules"))
 		DIFF_OPT_SET(options, IGNORE_SUBMODULES);
-	else if (!strcmp(arg, "--submodule"))
+	else if (!prefixcmp(arg, "--ignore-submodules=")) {
+		if (!strcmp(arg + 20, "all"))
+			DIFF_OPT_SET(options, IGNORE_SUBMODULES);
+		else if (!strcmp(arg + 20, "untracked"))
+			DIFF_OPT_SET(options, IGNORE_UNTRACKED_IN_SUBMODULES);
+		else if (!strcmp(arg + 20, "dirty"))
+			DIFF_OPT_SET(options, IGNORE_DIRTY_SUBMODULES);
+		else
+			die("bad --ignore-submodules argument: %s", arg + 20);
+	} else if (!strcmp(arg, "--submodule"))
 		DIFF_OPT_SET(options, SUBMODULE_LOG);
 	else if (!prefixcmp(arg, "--submodule=")) {
 		if (!strcmp(arg + 12, "log"))
