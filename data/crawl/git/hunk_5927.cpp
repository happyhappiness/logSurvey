 		die("ambiguous argument '%s': both revision and filename\n"
 		    "Use '--' to separate filenames from revisions", arg);
 	if (errno != ENOENT && errno != ENOTDIR)
-		die("'%s': %s", arg, strerror(errno));
+		die_errno("failed to stat '%s'", arg);
 }
 
 const char **get_pathspec(const char *prefix, const char **pathspec)
