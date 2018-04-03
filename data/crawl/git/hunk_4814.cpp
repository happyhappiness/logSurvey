 	sprintf(path, "%s/pack", objdir);
 	len = strlen(path);
 	dir = opendir(path);
-	while (!dir && errno == EMFILE && unuse_one_window(NULL, -1))
-		dir = opendir(path);
 	if (!dir) {
 		if (errno != ENOENT)
 			error("unable to open object pack directory: %s: %s",
