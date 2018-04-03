 static unsigned long expire;
 static int show_progress = -1;
 
-static int prune_tmp_object(const char *path, const char *filename)
+static int prune_tmp_file(const char *fullpath)
 {
-	const char *fullpath = mkpath("%s/%s", path, filename);
 	struct stat st;
 	if (lstat(fullpath, &st))
 		return error("Could not stat '%s'", fullpath);
