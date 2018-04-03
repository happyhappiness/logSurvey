 	}
 
 	if (subdir && chdir(subdir))
-		die("Cannot change to %s: %s", subdir, strerror(errno));
+		die_errno("Cannot change to '%s'", subdir);
 
 	errno = saved_errno;
 
