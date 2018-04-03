 {
 	struct stat st;
 	if (lstat(path, &st))
-		die("%s: unable to stat (%s)", path, strerror(errno));
+		die_errno("unable to stat '%s'", path);
 	return add_to_index(istate, path, &st, flags);
 }
 
