 	if (gc_auto_threshold <= 0)
 		return 0;
 
-	if (sizeof(path) <= snprintf(path, sizeof(path), "%s/17", objdir)) {
-		warning(_("insanely long object directory %.*s"), 50, objdir);
-		return 0;
-	}
-	dir = opendir(path);
+	dir = opendir(git_path("objects/17"));
 	if (!dir)
 		return 0;
 