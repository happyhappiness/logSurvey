 	for (i = 1; i < argc; i++) {
 		const char *arg = argv[i];
 		if (!strcmp(arg, "--decorate")) {
-			load_ref_decorations();
-			rev->show_decorations = 1;
+			decoration_style = DECORATE_SHORT_REFS;
+		} else if (!prefixcmp(arg, "--decorate=")) {
+			const char *v = skip_prefix(arg, "--decorate=");
+			if (!strcmp(v, "full"))
+				decoration_style = DECORATE_FULL_REFS;
+			else if (!strcmp(v, "short"))
+				decoration_style = DECORATE_SHORT_REFS;
+			else
+				die("invalid --decorate option: %s", arg);
 		} else if (!strcmp(arg, "--source")) {
 			rev->show_source = 1;
 		} else if (!strcmp(arg, "-h")) {
 			usage(builtin_log_usage);
 		} else
 			die("unrecognized argument: %s", arg);
 	}
+	if (decoration_style) {
+		rev->show_decorations = 1;
+		load_ref_decorations(decoration_style);
+	}
 }
 
 /*
