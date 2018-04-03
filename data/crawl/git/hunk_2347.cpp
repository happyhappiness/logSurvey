 		ret = 1;
 	}
 
-	if (subdir && chdir(subdir))
-		die_errno("Cannot change to '%s'", subdir);
+	restore_env();
 
 	errno = saved_errno;
 
