 	int num_loose = 0;
 	int needed = 0;
 
-	/*
-	 * Setting gc.auto to 0 or negative can disable the
-	 * automatic gc
-	 */
-	if (gc_auto_threshold <= 0)
-		return 0;
-
 	if (sizeof(path) <= snprintf(path, sizeof(path), "%s/17", objdir)) {
 		warning("insanely long object directory %.*s", 50, objdir);
 		return 0;
