 		only_include_assumed = "Explicit paths specified without -i nor -o; assuming --only paths...";
 		also = 0;
 	}
+	if (!cleanup_arg || !strcmp(cleanup_arg, "default"))
+		cleanup_mode = use_editor ? CLEANUP_ALL : CLEANUP_SPACE;
+	else if (!strcmp(cleanup_arg, "verbatim"))
+		cleanup_mode = CLEANUP_NONE;
+	else if (!strcmp(cleanup_arg, "whitespace"))
+		cleanup_mode = CLEANUP_SPACE;
+	else if (!strcmp(cleanup_arg, "strip"))
+		cleanup_mode = CLEANUP_ALL;
+	else
+		die("Invalid cleanup mode %s", cleanup_arg);
 
 	if (all && argc > 0)
 		die("Paths with -a does not make sense.");
